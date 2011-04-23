#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#define SCREEN_W 800
#define SCREEN_H 480
#include "libs/nodos_grafico.h"


void iniciar_SDL(){
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("No se pudo iniciar SDL: %s\n",SDL_GetError());
		exit(1);
	}
	// Activamos modo de video
	screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H,24,SDL_HWSURFACE | SDL_DOUBLEBUF );
	if (screen == NULL) {
		printf("No se puede inicializar el modo gráfico: %s\n",SDL_GetError());
		exit(1);
	}
	cargar_img_nodos();
	paintBackground();
}

int main(int argc, char *argv[]) {
	SDL_Event event;
	int done = 0;
	atexit(SDL_Quit);
	iniciar_SDL();
	//
	mostrar_nodo(5,50);
	mostrar_apuntador(95);
	mostrar_nodo(6,140);
	mostrar_apuntador(185);
	mostrar_null(230);
	// Mostramos la pantalla
	SDL_Flip(screen);
	// liberar superficie
	SDL_FreeSurface(image_nodos);
	// Esperamos la pulsación de una tecla para salir
	while(done == 0) {
		while ( SDL_PollEvent(&event) ) {
			if ( event.type == SDL_KEYDOWN )
				done = 1;
                       else if (event.type == SDL_MOUSEMOTION)
                                      printf("posicion del mouse x=%d, y=%d", event.x, event.y);
		}
	}
	return 0;
}
