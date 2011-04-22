/*
 Gravedad - mini-ejemplo
 Copyright (C) 2005 - Hugo Ruscitti
 
 Este programa es software libre. Puede redistribuirlo y/o modificarlo bajo 
 los términos de la Licencia Pública General de GNU según es publicada por la 
 Free Software Foundation, bien de la versión 2 de dicha Licencia o bien 
 (según su elección) de cualquier versión posterior.
 
 Este programa se distribuye con la esperanza de que sea útil, pero SIN 
 NINGUNA GARANTÍA, incluso sin la garantía MERCANTIL implícita o sin 
 garantizar la CONVENIENCIA PARA UN PROPÓSITO PARTICULAR. Véase la Licencia 
 Pública General de GNU para más detalles.

 Debería haber recibido una copia de la Licencia Pública General junto con 
 este programa. Si no ha sido así, escriba a la Free Software Foundation, 
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
