#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

#define NODO_POS_NODO 0

SDL_Surface *image_nodos, *screen;
SDL_Rect nodo_rectBlitOrg, nodo_rectBlitDest;


void cargar_img_nodos(){
	// Cargamos gráfico
	image_nodos = IMG_Load("img/nodos.png");
	if ( image_nodos == NULL ) {
		printf("No pude cargar gráfico: %s\n", SDL_GetError());
		exit(1);
	}
	//iniciamos 2 rectangulos los cuales usaremos en los flits
	//el rect para el bit blitting del origen
	nodo_rectBlitOrg.w = 100;
	nodo_rectBlitOrg.h = 100;
	nodo_rectBlitOrg.y = 0;
	//el rect para el bit blitting del destino
	nodo_rectBlitDest.w = 100;
	nodo_rectBlitDest.h = 100;
	nodo_rectBlitDest.y = 100;
}

void show_nodo_element(){
	SDL_BlitSurface(image_nodos, &nodo_rectBlitOrg, screen, &nodo_rectBlitDest);
}

void mostrar_nodo(int valor, int pos_x){
	//desplazamos el rect del origen(img a pegar)
	nodo_rectBlitOrg.x = 0;
	//desplazamos el rect destino en la pos_x(fondo donde se pondra)
	nodo_rectBlitDest.x = pos_x;
	show_nodo_element();
}


void mostrar_apuntador(int pos_x){
	//desplazamos el rect del origen(img a pegar)
	nodo_rectBlitOrg.x = 100;
	//desplazamos el rect destino en la pos_x(fondo donde se pondra)
	nodo_rectBlitDest.x = pos_x;
	show_nodo_element();
}

void mostrar_null(int pos_x){
	//desplazamos el rect del origen(img a pegar)
	nodo_rectBlitOrg.x = 200;
	//desplazamos el rect destino en la pos_x(fondo donde se pondra)
	nodo_rectBlitDest.x = pos_x;
	show_nodo_element();
}


