
listas_ordenadas.h
====

# (1)->(5)->(3)->NULL


### int lista\_org\_insertar(LISTA *l, int v);

> - **inserta el valor v en la lista**
> - devuelve 1 si se inserto con exito y 0 en caso contrario

	int lista_org_insertar(&l, 7);
	//lista resultante (1)->(5)->(3)->(7)->NULL
	
### int lista\_ord\_valor\_pos(LISTA *l, int pos);

> - Regresa el valor del elemento en la posición pos

	lista_org_valor_pos(&l, 0)//Regresa 1
	lista_ord_valor(&l, 2)//Regresa 3

###int lista\_ord\_borrar\_posicion(LISTA *l,int pos);
       lista_ord_borrar_posicion(&l,1)
       
**Devuelve:** 5 

**Lista actual:** (1)->(3)

###int lista\_ord\_dimension(LISTA *l)

	lista_ord_dimension(&l)	
	
**Devuelve:** 3

	
###int lista\_ord\_existe(LISTA *l, int valor);

**Regresa la posicion donde encuentre la primera incurrencia de "valor" en l,  de no encontrar ninguno devuelve -1**

	lista_ord_buscar_existe(&l, 1);

**Devuelve:** 0

	lista_ord_buscar_existe(&l, 8);

**Devuelve:** -1
	
    
