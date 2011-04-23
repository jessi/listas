/*
aqui va a estar la estructura de los bonos
*/

//tipos de bonos
#define BONO_NO 0
#define BONO_GASOLINA 1
#define BONO_PROYECTIL 2
#define BONO_CRUZ_ROJO 3
#define BONO_RAPIDEZ 4
#define BONO_NUEVA_VIDA 5
struct bono
{
 int x,y,w,h;
 int bono;
 SDL_Surface *ima;
};
typedef struct Bono;
void iniciar_bono (Bono *bono, int x, int y, int bono)
{
	bono->x = x;
	bono->y = y;
	bono->w = 50;
	bono->h = 50;
	bono->bono=0;
	if(bono->bono==0)
	  bono->ima=NULL;
	else
	  bono->ima=bonos[(bono->bono)-1];
	  
}
