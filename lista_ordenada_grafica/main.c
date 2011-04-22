#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "libs/nodos_grafico.h"

int main(int argc, char *argv[]) {
	SDL_Event event;
	int done = 0;
	atexit(SDL_Quit);
	// Iniciar SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("No se pudo iniciar SDL: %s\n",SDL_GetError());
		exit(1);
	}
	// Activamos modo de video
	screen = SDL_SetVideoMode(850,480,24,SDL_HWSURFACE | SDL_DOUBLEBUF );
	if (screen == NULL) {
		printf("No se puede inicializar el modo gráfico: %s\n",SDL_GetError());
	exit(1);
	}
	cargar_img_nodos();
	//
	mostrar_nodo(5,300);
	mostrar_apuntador(380);
	mostrar_nodo(6,470);
	mostrar_apuntador(550);
	mostrar_null(630);
	// Mostramos la pantalla
	SDL_Flip(screen);
	// liberar superficie
	SDL_FreeSurface(image_nodos);
	// Esperamos la pulsación de una tecla para salir
	while(done == 0) {
		while ( SDL_PollEvent(&event) ) {
			if ( event.type == SDL_KEYDOWN )
				done = 1;
		}
	}
	return 0;
}
