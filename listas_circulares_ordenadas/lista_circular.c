#include<stdio.h>
#include<stdlib.h>
#include"lista_circulares.h"

int main()
{
	LISTA l;
	int e=5,t;
	list_cir_insertar(&l, e);
	list_cir_insertar(&l,10);
	t=list_cir_eliminar(&l,10);
	printf("dato eliminado; 10 fué %d\n",t);
	return 0;
}

