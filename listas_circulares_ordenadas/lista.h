# include<stdio.h>
# include<stdlib.h>

struct nodo
{
int dato;
struct nodo *sig;
};
typedef struct nodo NODO;
typedef NODO *NODOP;
typeder NODO *LISTA;

int insertar(LISTA *l,int d)
{
	NODOP nuevo,act=*l,ant=NULL;
	int i=0;
	nuevo=(NODOP)malloc(sizeof(NODO));
	if(nuevo==NULL)
	{ 
	printf("Memoria insuficiente\n");
	exit (0);
	}
	nuevo->dato=d;
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

int eliminar(LISTA *l,int e)
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
		   ant->sig=act-sig;
		 }
	 free(act);
	 return 1;
 }

int vacia(LISTA *l)
{
if(*l==NULL)
  return 0;
return 1;
}

int main()
{
LISTA l;
int e;
