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

#include <SDL/SDL.h>
#include <stdio.h>

#include "fps.h"
#include "pelota.h"
#include "util.h"

#ifdef WIN32
#include <windows.h>
int WINAPI WinMain(HINSTANCE x1, HINSTANCE x2, LPSTR x3, int x4)
#else
int main (void)
#endif
{
	struct fps fps;
	struct pelota pelota;
	SDL_Surface *screen;
	SDL_Surface *fondo;
	int salir = 0;
	int rep;
	int i;
	
	if (iniciar(&screen, &fondo))
		return 1;

	if (pelota_iniciar(&pelota))
		return 1;

	fps_iniciar(&fps, 70);
	
	while (! salir)
	{
		SDL_BlitSurface(fondo, NULL, screen, NULL);

		rep = fps_actualizar (&fps);
		
		for (i = 0; i < rep; i++)
			pelota_actualizar(&pelota);

		pelota_imprimir(&pelota, screen);

		SDL_Flip(screen);
		procesar_eventos(&salir);
	}

	SDL_FreeSurface(fondo);
	pelota_terminar(&pelota);
	
	SDL_Quit();
	return 0;
}
