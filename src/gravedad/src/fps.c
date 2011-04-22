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
