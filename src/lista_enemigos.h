//lista de enemigos
/*lista_enemigo.h*/
typedef struct nodo_enemigo
{
	struct Tanque *tanque;
	struct nodo_enemigo *siguiente;
}Nodo_enemigo;

int lista_enemigo_vacia(Nodo_enemigo * lista_enemigos)
{
      if(*lista_enemigos==NULL)
	return 1;
   return 0;
}
/*
 * 1=se pudo;
 * 0=otro caso
 * */
int lista_enemigos_insertar(Tanque * tanque,Nodo_enemigo *l)
{
      Nodo_enemigo nuevo,act=*l,ant=NULL;
	nuevo=(Nodo_enemigo)malloc(sizeof(nodo_enemigo));
	if(nuevo==NULL)
	{ 
		printf("Memoria insuficiente\n");
		return 0;
	}
	nuevo->tanque=*tanque;
	nuevo->sig=NUll;
	if(lista_enemigo_vacia(*l))
	*l=nuevo;
	else
	 {
	 nuevo->sig=*l;
	 *l=nuevo;
	 }
  return 1;

}

/*
 * 1=se pudo
 * 0=otro caso
* */
int lista_enemigos_eliminar(Tanque * tanque)
{

	NODOP act =*l;
	if(lista_enemigo_vacia(*l))
	  return 0;
	else
	*l=act->sig;
	 free(act);
	 return 1;
}
