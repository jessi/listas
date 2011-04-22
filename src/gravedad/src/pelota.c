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

#include "pelota.h"

int pelota_iniciar (struct pelota *pelota)
{
	Uint32 color_transparente;
	
	pelota->x = 150;
	pelota->y = 50;
	pelota->dx = 2;
	pelota->vel_y = 0;
	pelota->cuadro = 0;

	pelota->ima0 = SDL_LoadBMP("../ima/pelota0.bmp");

	if (pelota->ima0 == NULL) 
	{
		printf("Error al cargar imagen: %s\n", SDL_GetError());
		return 1;
	}

	pelota->ima1 = SDL_LoadBMP("../ima/pelota1.bmp");

	if (pelota->ima1 == NULL) 
	{
		printf("Error al cargar imagen: %s\n", SDL_GetError());
		return 1;
	}

	color_transparente = SDL_MapRGB(pelota->ima0->format, 255, 0, 255);
	
	SDL_SetColorKey(pelota->ima0, SDL_SRCCOLORKEY, color_transparente);
	SDL_SetColorKey(pelota->ima1, SDL_SRCCOLORKEY, color_transparente);
	
	return 0;
}


void pelota_imprimir (struct pelota *pelota, SDL_Surface *screen)
{
	SDL_Rect dst;
	
	dst.x = pelota->x;
	dst.y = pelota->y;

	if (pelota->cuadro == 1)
	{
		SDL_BlitSurface(pelota->ima1, NULL, screen, &dst);
		pelota->cuadro = 0;
	}
	else
	{
		pelota->cuadro = 1;
		SDL_BlitSurface(pelota->ima0, NULL, screen, &dst);
	}
}


void pelota_actualizar(struct pelota *pelota)
{
	pelota->x += pelota->dx;

	pelota->vel_y += 0.1;
	
	if (pelota->y + pelota->vel_y >= 176)
	{
		pelota->vel_y -= 0.1; // pierde fuerza al tocar el suelo
		pelota->vel_y *= -1;
		pelota->y = 176;
	}
	else
	{
		pelota->y += (int) pelota->vel_y;
	}
	
	if (pelota->x >= 302) 
		pelota->dx = -2;

	if (pelota->x < 0)
		pelota->dx = 2;
}


void pelota_terminar (struct pelota *obj)
{
	SDL_FreeSurface (obj->ima0);
	SDL_FreeSurface (obj->ima1);
}
