/*
aqui va a estar la estructura de los bonos
*/
typedef struct caja
{
	int x;
	int y;
	int w,h;
	int bono;
	SDL_Surface * ima;
} Caja;


void iniciar_caja (Caja * caja, int x, int y, int bono)
{
	caja->x = x;
	caja->y = y;
	caja->w = 50;
	caja->h = 50;
	/* bono puede tomar los sig. valores definidos en bonos.h
	BONO_NO 0
	BONO_GASOLINA 1
	BONO_PROYECTIL 2
	BONO_CRUZ_ROJO 3
	BONO_RAPIDEZ 4
	BONO_NUEVA_VIDA 5
	**/
	caja->bono = 0;
	if(bono>0 && bono<6)
		caja->bono = bono;
}
