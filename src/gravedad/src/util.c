/*
 Gravedad - mini-ejemplo
 Copyright (C) 2005 - Hugo Ruscitti
 
 Este programa es software libre. Puede redistribuirlo y/o modificarlo bajo 
 los t�rminos de la Licencia P�blica General de GNU seg�n es publicada por la 
 Free Software Foundation, bien de la versi�n 2 de dicha Licencia o bien 
 (seg�n su elecci�n) de cualquier versi�n posterior.
 
 Este programa se distribuye con la esperanza de que sea �til, pero SIN 
 NINGUNA GARANT�A, incluso sin la garant�a MERCANTIL impl�cita o sin 
 garantizar la CONVENIENCIA PARA UN PROP�SITO PARTICULAR. V�ase la Licencia 
 P�blica General de GNU para m�s detalles.

 Deber�a haber recibido una copia de la Licencia P�blica General junto con 
 este programa. Si no ha sido as�, escriba a la Free Software Foundation, 
 Inc., en 675 Mass Ave, Cambridge, MA 02139, EEUU. 
*/

#include "util.h"

int iniciar (SDL_Surface **screen, SDL_Surface **fondo)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1) 
	{
		printf("Error: %s\n", SDL_GetError());
		return 1;
	}

	*screen = SDL_SetVideoMode(320, 240, 16, SDL_DOUBLEBUF | SDL_HWSURFACE);
	
	if (*screen == NULL) 
	{
		printf("Error: %s\n", SDL_GetError());
		return 1;
	}

	*fondo = SDL_LoadBMP("../ima/fondo.bmp");

	if (*fondo == NULL) 
	{
		printf("Error: %s\n", SDL_GetError());
		return 1;
	}

	SDL_WM_SetCaption("Gravedad", NULL);
	
	return 0;
}


void procesar_eventos (int *salir)
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) 
	{
		if (event.type == SDL_QUIT)
			*salir = 1;

		if (event.type == SDL_KEYDOWN)
			*salir = 1;
	}
}
