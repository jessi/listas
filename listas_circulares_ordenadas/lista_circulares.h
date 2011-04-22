#ifndef LISTAS_ORDENADAS_H
#define LISTAS_ORDENADAS_H

struct nodo
{
int dato;
struct nodo *sig;
};
typedef struct nodo NODO;
typedef NODO *NODOP;
typedef NODO *LISTA;

int lis_cir_tam(LISTA * actual)
 {
	int len = 0;
	while(actual)
	{
		len++;
		actual = actual->siguiente;
	}
	return len;
}



void list_cir_insertar(LISTA *l,int d)
{
	NODOP nuevo,act=*l,ant=NULL;
	nuevo=(NODOP)malloc(sizeof(NODO));
	if(nuevo==NULL)
	{ 
	printf("Memoria insuficiente\n");
	exit (0);
	}
	nuevo->dato=d;
	nuevo->sig=NULL;
	if(vacia(*l))
	{
	nuevo->sig=nuevo;
	*l=nuevo;
	return ;
	}
	
	
	while(act->sig!=*l && d>=act->dato)
	{ ant=act;
	  act=act->sig;
	  i++;
	  }
	 if(d<(*l)->dato)
	 {
	 while(act->sig!=*l)
	   act=act->sig;
	  act->sig=nuevo;
	  nuevo->sig=*l;
	  *l=nuevo;
	 }
	 else if(act!=*l && d<=act->dato)
	 {
	 ant->sig=nuevo;
	 nuevo->sig=act;
	 }
	 else
	 {
	 act->sig=nuevo;
	 nuevo->sig=*l;
	 }
return ;	 
 }

int list_cir_eliminar(LISTA *l,int e)
{
	NODOP ant=NULL,act =*l;
	if(vacia(*l))
	return 0;
	while(act->sig!=*l && e>act->dato)
		{ 
		 ant=act;
		 act=act->sig;
		}
	if(act->dato!=e)
	       return 0;
	if(ant==NULL)
		{
		 ant=*l;
		 while(act->sig!=*l)
    		   act=act->sig;
    		   *l=(*l)->sig;
    		   act->sig=*l;
    		   free(ant);
    		}
    	else
    	 {
    	 ant->sig=act->sig;
    	 free(act);
    	 }
    	 return 1;
 }
		 }
	 else
		 {
		   ant->sig=act-sig;
		 }
	 free(act);
	 return 1;
 }

int list_cir_vacia(LISTA *l)
{
if(*l==NULL)
  return 0;
return 1;
}
