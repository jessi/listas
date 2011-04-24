listas_circulares.h
====

Lo siguiente es la documentacion de la libreria listas circulares ubicada en: _listas_circulares_ordenadas/listas_circulares.h_ para la siguiente documentación:

##Lista circular de ejemplo

	(1)<->(3)<->(5)<-
	^--------------'
##lista de funciones

### int lista\_cir\_insertar(LISTA *l, int v);

> - **inserta el valor v en la lista**
> - devuelve 1 si se inserto con exito y 0 en caso contrario

	int lista_cir_insertar(&l, 7);
	# (1)<->(3)<->(5)<->(7)<--
	#  ^---------------------'

### int lista\_cir\_valor\_pos(LISTA *l, int pos);

> - Regresa el valor del elemento en la posición pos

	lista_cir_valor_pos(&l, 0)//Regresa 1
	lista_cir_valor(&l, 2)//Regresa 5

###int lista\_cir\_borrar\_posicion(LISTA *l,int pos);

 - Borra al elemento ubicado en la posición _pos_
 - Devuelve el valor del elemento que elimino
 - En caso que no lo pueda borrar devuelve -1
 
>*lista\_cir\_borrar\_posicion(&l,1)*

	# (1)<->(5)<--
	#  ^---------'
       
**Devuelve:** 3

###int lista\_cir\_dimension(LISTA *l)

 - Devuelve el tamaño de la lista circular

	lista_cir_dimension(&l)	

**Devuelve:** 3

	
###int lista\_cir\_existe(LISTA *l, int val);

 - Busca el primero elemento en la lista con el valor val en la lista
 - Devuelve el valor de la posicion en donde se encuentre dicho elemento
 - En caso de no encontrar ninguno devuelve -1
 
**Regresa la posicion donde encuentre la primera incurrencia de "valor" en l,  de no encontrar ninguno devuelve -1**

	lista_cir_buscar_existe(&l, 1);

**Devuelve:** 0

	lista_cir_buscar_existe(&l, 8);

**Devuelve:** -1
	
    
