/*
 * Mini ejemplo : Scroll y cámara suave
 * 
 * Copyright (C) 2006 Hugo Ruscitti
 *
 * Este programa es software libre. Puede redistribuirlo y/o 
 * modificarlo bajo los términos de la Licencia Pública General	de 
 * GNU según es publicada por la Free Software Foundation, bien de 
 * la versión 2 de dicha Licencia o bien (según su elección) de 
 * cualquier versión posterior.
 * 
 * Este programa se distribuye con la esperanza de que sea útil, pero
 * SIN NINGUNA GARANTÍA, incluso sin la garantía MERCANTIL implícita 
 * o sin garantizar la CONVENIENCIA PARA UN PROPÓSITO PARTICULAR. 
 * Véase la Licencia Pública General de GNU para más detalles.
 * 
 * Debería haber recibido una copia de la Licencia Pública General 
 * junto con este programa. Si no ha sido así, escriba a la Free 
 * Software Foundation, Inc., en 675 Mass Ave, Cambridge, 
 * MA 02139, EEUU.
 */

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <stdlib.h>
#include "tanque.h"
#include "lista_enemigos.h"

#include "bonos.h"
#include "cajas.h"


#define COLUMNAS_TILES 7
#define FILAS_MAPA 10
#define COLUMNAS_MAPA 20
#define ALTO_TILE 50
#define ANCHO_TILE 50
#define FRECUENCIA 10

typedef struct camara
{
	float x;
	float y;
} Camara;

SDL_Surface * iniciar_sdl (const char * titulo);
void iniciar_tanque (Tanque * tanque);
void iniciar_camara (Camara * camara);
void mover_camara (Camara * camara, Tanque * tanque);
void mover_tanque (Tanque * tanque);
int cargar_imagenes (SDL_Surface ** tiles, SDL_Surface ** tanques);
int fps_sincronizar (void);
void imprimir_escenario (SDL_Surface * screen, SDL_Surface * ima, int x, int y);
void imprimir_tanque (SDL_Surface * screen, Tanque * tanque, Camara * camara);
void imprimir_grilla (SDL_Surface * screen, SDL_Surface * src, int cuadro, 
		int cols, int x, int y);





int main (int argc, char * argv [])
{
	SDL_Event event;
	SDL_Surface * screen;
	int salir = 0;
	int repeticiones;
	int i;
	SDL_Surface * tiles;
	Tanque tanque;
	Camara camara;
	
	screen = iniciar_sdl ("Desplazamiento suave");

	if (screen == NULL)
		return 1;

	iniciar_camara (& camara);
	iniciar_tanque (& tanque);
	
	if (cargar_imagenes (& tiles, & tanque.ima))
		return 1;
	
	while (! salir)
	{
		while (SDL_PollEvent (& event))
		{
			if (event.type == SDL_QUIT)
				salir = 1;

			if (event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_ESCAPE)
					salir = 1;
				if(event.key.keysym.sym == SDLK_PLUS)
					incrementar_velocidad_tanque( &tanque);
					
					else if(event.key.keysym.sym == SDLK_MINUS)
					desincrementar_velocidad_tanque( &tanque);
			
			
			}
		}

		repeticiones = fps_sincronizar ();

		for (i = 0; i < repeticiones; i ++)
		{
			mover_tanque (& tanque);
			mover_camara (& camara, & tanque);
			
		}
		
		imprimir_escenario (screen, tiles, camara.x, camara.y);
		imprimir_tanque (screen, & tanque, & camara);
		
		SDL_Flip (screen);
	}

	SDL_FreeSurface (tanque.ima);
	SDL_FreeSurface (tiles);

	SDL_Quit ();
	return 0;
}


void mover_camara (Camara * camara, Tanque * tanque)
{
	int limite_derecho = (COLUMNAS_MAPA - 1) * ANCHO_TILE - 320;
	int limite_inferior = (FILAS_MAPA - 1) * ANCHO_TILE - 240;
	
	/* se acerca a la posición del tanque de manera gradual */
	
	camara->x += (tanque->x - camara->x) / 20;
	camara->y += (tanque->y - camara->y) / 20;
	
	
	/* detiene el desplazamiento en los límites */
	
	if (camara->x < 0)
		camara->x = 0;
	
	if (camara->y < 0)
		camara->y = 0;
	
	if (camara->x > limite_derecho)
		camara->x = limite_derecho;
	
	if (camara->y > limite_inferior)
		camara->y = limite_inferior;
}


void mover_tanque (Tanque * tanque)
{
	Uint8 * teclas = SDL_GetKeyState (NULL);
	
	if (teclas [SDLK_LEFT] && tanque->x > 0)
	{
		tanque->x -= tanque->velocidad;
		tanque->cuadro = 6;
	}
	
	if (teclas [SDLK_RIGHT])
	{
		tanque->x += tanque->velocidad;
		tanque->cuadro = 2;
	}
	
	if (teclas [SDLK_DOWN])
	{
		tanque->y += tanque->velocidad;
		tanque->cuadro = 4;
	}

	if (teclas [SDLK_UP] && tanque->y > 0)
	{
		tanque->y -= tanque->velocidad;
		tanque->cuadro = 0;
	}


	if (teclas [SDLK_UP] && teclas [SDLK_LEFT])
		tanque->cuadro = 7;

	if (teclas [SDLK_UP] && teclas [SDLK_RIGHT])
		tanque->cuadro = 1;

	if (teclas [SDLK_DOWN] && teclas [SDLK_LEFT])
		tanque->cuadro = 5;

	if (teclas [SDLK_DOWN] && teclas [SDLK_RIGHT])
		tanque->cuadro = 3;
    
}


void imprimir_escenario (SDL_Surface * screen, SDL_Surface * ima, int x, int y)
{
	
	FILE * pFile;
	pFile = fopen ("/escenario/mapa1.txt","r");
	char c;
	if (pFile==NULL)
		die('no se pudo abrir el mapa del escenario');
	do {
		c = fgetc (pFile);
		//if(c != '\n')
		printf("%c",c);
    } while (c != EOF);
	
	static char mapa [FILAS_MAPA] [COLUMNAS_MAPA + 1] = {
		"00000002112000000211",
		"00000002112000000211",
		"00000002112000000211",
		"00000002112000000211",
		"11111111110111111111",
		"11111111111111111111",
		"11111111111111111111",
		"11111111111111111111",
		"11111111111111111111",
		"11111111111111111111"
	};
	int i;
	int j;
	int fila = y / ALTO_TILE;
	int columna = x / ANCHO_TILE;
	int desplazamiento_x = x % ANCHO_TILE;
	int desplazamiento_y = y % ALTO_TILE;
	
	for (i = 0; i < 6; i ++)
	{
		for (j = 0; j < 8; j ++)
		{
			imprimir_grilla (screen, ima, 
					mapa [fila + i] [columna + j] - '0',
					COLUMNAS_TILES,
					j * ANCHO_TILE - desplazamiento_x,
					i * ALTO_TILE - desplazamiento_y);
		}
	}
	
}


void imprimir_tanque (SDL_Surface * screen, Tanque * tanque, Camara * camara)
{
	int x = tanque->x - camara->x + 160;
	int y = tanque->y - camara->y + 120;

	imprimir_grilla (screen, tanque->ima, tanque->cuadro, 8, x, y);
}


SDL_Surface * iniciar_sdl (const char * titulo)
{
	SDL_Surface * screen;

	if (SDL_Init (SDL_INIT_VIDEO))
	{
		printf ("error: %s\n", SDL_GetError ());
		return NULL;
	}

	screen = SDL_SetVideoMode (850, 480, 16, SDL_HWSURFACE);
	
	if (screen == NULL)
	{
		printf ("error: %s\n", SDL_GetError ());
		return NULL;
	}

	SDL_WM_SetCaption (titulo, NULL);
	SDL_ShowCursor (SDL_DISABLE);

	return screen;
}


void imprimir_grilla (SDL_Surface * screen, SDL_Surface * src, int cuadro, 
		int cols, int x, int y)
{
	int w = src->w / cols;
	SDL_Rect fuente = {cuadro * w, 0, w, src->h};
	SDL_Rect rect = {x, y, 0, 0};
	
	if (cuadro < 0 || cuadro > cols)
	{
		printf ("No se puede imprimir el cuadro %d\n", cuadro);
		return;
	}
	
	SDL_BlitSurface (src, & fuente,	screen, &rect);
}


int cargar_imagenes (SDL_Surface ** tiles, SDL_Surface ** tanques)
{
	SDL_Surface * tmp;

	tmp = IMG_Load ("../ima/fondos.png");
	
	if (tmp == NULL)
	{
		printf ("%s\n", SDL_GetError ());
		return 1;
	}

	/* intenta optimizar los gráficos del terreno */
	
	* tiles = SDL_DisplayFormat (tmp);

	if (* tiles)
		free (tmp);
	else
		* tiles = tmp;

	
	* tanques = IMG_Load ("../ima/tanque1.png");

	if (* tanques == NULL)
	{
		printf ("%s\n", SDL_GetError ());
		return 1;
	}

	return 0;
}


int fps_sincronizar (void)
{
	static int t;
	static int tmp;
	static int tl = 0;

	t = SDL_GetTicks ();

	if (t - tl >= FRECUENCIA)
	{
		tmp = (t - tl) / FRECUENCIA;
		tl += tmp * FRECUENCIA;
		return tmp;
	}
	else
	{
		SDL_Delay (FRECUENCIA - (t - tl));
		tl += FRECUENCIA;
		return 1;
	}
}


void iniciar_camara (Camara * camara)
{
	camara->x = 0;
	camara->y = 0;
}
