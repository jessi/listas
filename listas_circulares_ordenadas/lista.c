//LISTA ORDENADA
#include<stdio.h>
#include<stdlib.h>
#include"listas_ordenadas.h"

int main()
{
	LISTA l;
	int e=5,t=0;
	lista_insertar(&l, e);
	lista_insertar(&l, 6);//<¿'--el valor 6 me parece que nunca se acaba de insertar marga violación de proceso
	t=lista_eliminar_elemento(&l,8);
	printf("dato eliminado fué %d dato %d\n",t, l->dato);
	lista_insertar(&l, 7);//<--esta nunca es ejecutada
	lista_insertar(&l, 8);
	lista_insertar(&l, 9);
	return 0;
}

