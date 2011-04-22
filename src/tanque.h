typedef struct tanque
{
	int x;
	int y;
	int cuadro;
	int velocidad,score,gasolina,estado,nvidas,alcanzeproyectil;
	SDL_Surface * ima;
} Tanque;

void iniciar_tanque (Tanque * tanque)
{
	tanque->x = 250;
	tanque->y = 150;
	tanque->cuadro = 0;
	tanque->velocidad = 1;
	tanque->gasolina=100;
	tanque->nvidas=3;
	tanque->score=0;
	tanque->alcanzeproyectil=2;
	tanque->estado=100;
}

int tanque_modificarVelocidad(Tanque * tanque, int velocidad){
	/*if(velocidad>0 
	tanque->velocidad = */
	return 0;
}

int incrementar_velocidad_tanque(Tanque * tanque)
{
	printf("velocidad del tanque es %d\n",tanque->velocidad);
	if(tanque->velocidad<5)
		tanque->velocidad++;
	else
		return -1;
	return 0;
}

int desincrementar_velocidad_tanque(Tanque * tanque)
{
	printf("velocidad del tanque es %d\n",tanque->velocidad);
	if(tanque->velocidad>1)
		tanque->velocidad--;
	else
		return -1;
	return 0;
}
