#include<stdio.h>
#include<stdlib.h>
#include"lista_circulares.h"

int main()
{
	LISTA l;
	int e=5,t;
	list_cir_insertar(&l, e);
	list_cir_insertar(&l,3);
	list_cir_insertar(&l,5);
	list_cir_insertar(&l,10);
	list_cir_insertar(&l,2);
	t=list_cir_eliminar(&l,10);
	//t=list_cir_eliminar(&l,10);
	printf("dato eliminado; 10 fué %d\n",t);
	//tamaño de la lista 
	printf("tamaño de la lista %d\n",lis_cir_tam(&l)); //<-- revisar
	return 0;
}
