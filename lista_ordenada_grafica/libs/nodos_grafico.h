#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

#define NODO_POS_NODO 0

typedef struct inputs{
	SDL_Rect insertar, borrar, buscar;
	int edo_insertar, edo_borrar, edo_buscar;
	int w,h,y;
}Inputs;

SDL_Surface *image_nodos, *screen, *img_bg;
SDL_Rect nodo_rectBlitOrg, nodo_rectBlitDest, rect_screen;
Inputs inputs;
/* prototipo de funciones */
void die(char *s);
void show_nodo_element();
void paintBackground();
void mostrar_nodo(int valor, int pos_x);
void mostrar_apuntador(int pos_x);
void mostrar_null(int pos_x);

/*
 *	Carga los graficos a utilizar durante el trascurso de la ejecución
 * */
void cargar_img_nodos(){
	// Cargamos gráfico
	image_nodos = IMG_Load("img/nodos.png");
	if ( image_nodos == NULL )
		die("No pude cargar gráfico: img/nodos.png\n");
	//imag de fondo
	img_bg  = IMG_Load("img/fondo.png");
	if ( img_bg == NULL )
		die("No pude cargar gráfico: img/fondo.png\n");
	//rectangulo que describe el fondo
	rect_screen.w = SCREEN_W;
	rect_screen.h = SCREEN_H;
	rect_screen.x = 0; rect_screen.y = 0;
	//iniciamos 2 rectangulos los cuales usaremos en los flits
	//el rect para el bit blitting del origen
	nodo_rectBlitOrg.w = 50;
	nodo_rectBlitOrg.h = 50;
	nodo_rectBlitOrg.y = 0;
	//el rect para el bit blitting del destino
	nodo_rectBlitDest.w = 50;
	nodo_rectBlitDest.h = 50;
	nodo_rectBlitDest.y = 200;
	//posiciones y estados iniciales de los inputs
}


void die(char *s){
	printf("%s\n",s);
	exit(1);
}


/*
SDL_Rect rect_setear(int w, int h, int x,int y){
	SDL_Rect rect;
	rect.x = w;
	rect.y = h;
	rect.y = y;
	rect.y = y;
	return rect;
}
* */

void show_nodo_element(){
	SDL_BlitSurface(image_nodos, &nodo_rectBlitOrg, screen, &nodo_rectBlitDest);
}

void paintBackground(){
	SDL_Rect rect_aux;
	SDL_BlitSurface(img_bg, &rect_screen, screen, &rect_screen);
	rect_aux.x = 100;
	rect_aux.y = 445;
	rect_aux.h = 20;
	rect_aux.w = 80;
	
	SDL_FillRect(screen, &rect_aux, SDL_MapRGB(screen->format,200,200,200));
	rect_aux.x += 200;
	SDL_FillRect(screen, &rect_aux, SDL_MapRGB(screen->format,200,200,200));
	rect_aux.x += 200;
	SDL_FillRect(screen, &rect_aux, SDL_MapRGB(screen->format,200,200,200));
}

void mostrar_nodo(int valor, int pos_x){
	nodo_rectBlitOrg.x = 0;
	nodo_rectBlitDest.x = pos_x;
	show_nodo_element();
}

void mostrar_apuntador(int pos_x){
	nodo_rectBlitOrg.x = 50;
	nodo_rectBlitDest.x = pos_x;
	show_nodo_element();
}

void mostrar_null(int pos_x){
	nodo_rectBlitOrg.x = 200;
	nodo_rectBlitDest.x = pos_x;
	show_nodo_element();
}
