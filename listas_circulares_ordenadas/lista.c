//LISTA ORDENADA

#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

int main()
{
	LISTA l;
	int e=5,t;
	lista_insertar(&l, e);
	
	t=lista_eliminar_elemento(&l,e);
	printf("dato eliminado; %d fué %d\n",e,t);
	return 0;
}

