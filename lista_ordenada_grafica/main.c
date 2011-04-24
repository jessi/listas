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
			switch (event.type)
			{
			case SDL_QUIT:
				puts("Detección salir del juego");
				done = 1;
				break;
			case SDL_KEYDOWN:
				done = 1;
				break;
			case SDL_MOUSEMOTION:
				printf("Mouse en movimiento posición x=%d, y=%d\n", event.motion.x, event.motion.y);
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (event.button.button)
				{
					case SDL_BUTTON_LEFT:
						puts("se preciono el bonton izquierdo");
						break;

					case SDL_BUTTON_RIGHT:
						puts("se preciono el bonton derecho");
						break;
					case SDL_BUTTON_MIDDLE:
						puts("se preciono el bonton del centro");
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
		}
	}
	return 0;
}
