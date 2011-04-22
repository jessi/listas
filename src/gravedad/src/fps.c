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

#include <SDL/SDL.h>
#include "fps.h"


void fps_iniciar (struct fps *obj, int cuadros_por_segundo)
{
	obj->tl = obj->t = SDL_GetTicks();
	obj->tpl = 1000 / cuadros_por_segundo;
}


int fps_actualizar (struct fps *obj)
{
	int rep;
	obj->t = SDL_GetTicks();

	if ( (obj->t - obj->tl) > obj->tpl)
	{
		rep = (obj->t - obj->tl) / obj->tpl;
		
		obj->tl += rep *obj->tpl;
		
		return rep;
	}
	else
	{
		SDL_Delay(obj->tpl - (obj->t - obj->tl));
		return 0;
	}
}
