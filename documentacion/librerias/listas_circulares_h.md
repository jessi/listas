listas_circulares.h
====

# (1)<->(5)<->(3)<-
#  ^--------------'

### int lista\_cir\_insertar(LISTA *l, int v);

> - **inserta el valor v en la lista**
> - devuelve 1 si se inserto con exito y 0 en caso contrario

	int lista_cir_insertar(&l, 7);
	# (1)<->(5)<->(3)<->(7)<--
	#  ^---------------------'

### int lista\_cir\_valor\_pos(LISTA *l, int pos);

> - Regresa el valor del elemento en la posición pos

	lista_cir_valor_pos(&l, 0)//Regresa 1
	lista_cir_valor(&l, 2)//Regresa 3

###int lista\_cir\_borrar\_posicion(LISTA *l,int pos);

 - Borra al elemento en la posicion pos
 - devuelve el valor del elemento que elimino
 - en caso que no lo pueda borrar devuelve -1
 
>*lista\_cir\_borrar\_posicion(&l,1)*

	# (1)<->(3)<--
	#  ^---------'
       
**Devuelve:** 5 

**Lista actual:** (1)->(3)

###int lista\_cir\_dimension(LISTA *l)

	lista_cir_dimension(&l)	
	
**Devuelve:** 3

	
###int lista\_cir\_existe(LISTA *l, int valor);

**Regresa la posicion donde encuentre la primera incurrencia de "valor" en l,  de no encontrar ninguno devuelve -1**

	lista_cir_buscar_existe(&l, 1);

**Devuelve:** 0

	lista_cir_buscar_existe(&l, 8);

**Devuelve:** -1
	
    
