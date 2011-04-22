//lista de enemigos
/*lista_enemigo.h*/
typedef struct nodo_enemigo
{
	struct Tanque *tanque;
	struct nodo_enemigo *siguiente;
}Nodo_enemigo;

int lista_enemigo_vacia(Nodo_enemigo * lista_enemigos)
{
	return 1; //vacia
	return 0; //:otro caso
}
/*
 * 1=se pudo;
 * 0=otro caso
 * */
int lista_enemigos_insertar(Tanque * tanque){
	return 0;
}

/*
 * 1=se pudo
 * 0=otro caso
* */
int lista_enemigos_eliminar(Tanque * tanque){
	return 0;
}
