/*
 Libreria de Listas ordenas
*/
#ifndef LISTAS_ORDENADAS_H
#define LISTAS_ORDENADAS_H
struct nodo
{
	//Uint16 dato;
	int dato;
	struct nodo *sig;
};

typedef struct nodo NODO;
typedef NODO *NODOP;
typedef NODO *LISTA;

int lista_ord_dimension(LISTA *l)
 {
	NODOP actual = *l;
	int len = 0;
	while(actual)
	{
		len++;
		actual = actual->sig;
	}
	return len;
}


int list_insertar(LISTA *l, int dato)
{
    NODOP actual = *l;
    NODOP nuevo = (NODOP)malloc(sizeof(NODO));
    	if(nuevo==NULL)
	{ 
		printf("Memoria insuficiente\n");
		return 0;
	}
    nuevo->dato = dato;
    nuevo->sig = NULL;
    
    if(*l == NULL)
    { *l=nuevo;
	return 1;
	}
	
    while( (actual != NULL) && (dato > actual->dato) )
    {
		
        if(actual->sig == NULL)
          {
            actual->sig= nuevo;
            break;
	  }
	 if(actual->sig->dato > nuevo->dato)
	 {
			nuevo->sig = actual->sig;
			actual->sig = nuevo;
			break;
	}
	else
		actual = actual->sig;
	}
  return 1;
}

int lista_ord_borrar_posicion(LISTA *l,int pos){
	NODOP ant=NULL,act =*l,aux=*l;
	int c=0,t;
	while(act!=NULL && c!=pos)
    { ant=act;
      act=act->sig;
      c++;
      }
	if(c==0)
	    { 
	    *l=(*l)->sig;
	      t=act->dato;
	      free(act);
	    return t;
	    }
	else if(c==pos)
	{
	 t=act->dato;
	 ant->sig=act->sig;
	 free(act);
	 return t;
	 }
	else if(act==NULL&& c!=pos)
	 { printf("pocicion incorrecta\n");
	exit(0);
	}
}      
       
int lista_ord_buscar_existe(LISTA *l,int valor)
{
	NODOP act=*l;
	while(act!=NULL)
	{
	if(act->dato==valor)
		return 0;
	else
		act=act->sig;
	}
	return -1;
}   
#endif
