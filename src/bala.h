typedef struct bala
{
	int x;
	int y;
	int cuadro;
	int velocidad,score,gasolina,estado,nvidas,alcanzeproyectil;
	SDL_Surface * ima;
} Bala;

void iniciar_bala (Bala * bala)
{
	bala->x = 250;
	bala->y = 150;
	bala->cuadro = 0;
	bala->velocidad = 1;
	bala->gasolina=100;
	bala->nvidas=3;
	bala->score=0;
	bala->alcanzeproyectil=2;
	bala->estado=100;
}

int bala_modificarVelocidad(Bala * bala, int velocidad){
	/*if(velocidad>0 
	bala->velocidad = */
	return 0;
}

int incrementar_velocidad_bala(Bala * bala)
{
	printf("velocidad del bala es %d\n",bala->velocidad);
	if(bala->velocidad<5)
		bala->velocidad++;
	else
		return -1;
	return 0;
}

int desincrementar_velocidad_bala(Bala * bala)
{
	printf("velocidad del bala es %d\n",bala->velocidad);
	if(bala->velocidad>1)
		bala->velocidad--;
	else
		return -1;
	return 0;
}
