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

#ifndef PELOTA_H
#define PELOTA_H

#include <SDL/SDL.h>

struct pelota
{
	int x;
	int y;
	int dx;
	float vel_y;
	int cuadro;
	SDL_Surface *ima0;
	SDL_Surface *ima1;
};


void pelota_imprimir (struct pelota *pelota, SDL_Surface *screen);
int pelota_iniciar (struct pelota *pelota);
void pelota_actualizar(struct pelota *pelota);
void pelota_terminar(struct pelota *pelota);

#endif
