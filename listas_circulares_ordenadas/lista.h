/*
 Libreria de Listas ordenas
*/
#ifndef LISTA_H
#define LISTA_H


struct nodo
{
	int dato;
	struct nodo *sig;
};

typedef struct nodo NODO;
typedef NODO *NODOP;
typedef NODO *LISTA;
int lista_insertar(LISTA *l, int d)
{
	NODOP nuevo,act=*l,ant=NULL;
	int i=0;
	printf("entro ala funcion insertar, valor de d=%d\n",d);
	nuevo=(NODOP)malloc(sizeof(NODO));
	if(nuevo==NULL)
	{ 
		printf("Memoria insuficiente\n");
		exit (0);
	}
	nuevo->dato=d;
	if(lista_vacia(*l))
	{*l=nuevo;
	return i;
	}
	while(act!=NULL && d>act->dato)
	{ ant=act;
	  act=act->sig;
	  i++;
	  }
	 if(ant=NULL)
	 {
	 *l=nuevo;
	 nuevo->sig=act;
	 }
	 else
	 {
	 ant->sig=nuevo;
	 nuevo->sig=act;
	 }
  return i;
}

int lista_eliminar_elemento(LISTA *l, int e)
{
	NODOP ant=NULL,act =*l;
	while(act!=NULL && e>act->dato)
		{ 
		 ant=act;
		 act=act->sig;
		}
	if((act!=NULL&& e!=act->dato)|| act==NULL)
	       return -1;
	if(ant==NULL)
		{
		 *l=act->sig;
		 }
	 else
		 {
		   ant->sig=act->sig;
		 }
	 free(act);
	 return 1;
}

int lista_vacia(LISTA *l)
{
if(*l==NULL)
  return 0;
return 1;
}

#endif
