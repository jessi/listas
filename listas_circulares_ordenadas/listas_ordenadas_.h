
listas_ordenadas.h
====

# (1)->(5)->(3)

### int lista\_ord\_valor\_pos(lista*l, int pos);

	lista_org_valor_pos(&l,0)
**Regresa 1**

	lista_ord_valor(&l,2)
**Regresa 3**

###int lista\_ord\_borrar\_posicion(lista *l,int pos);
       lista_ord_borrar_posicion(&l,1)
       
**Devuelve:** 5 

**Lista actual:** (1)->(3)

###int lista\_ord\_dimension(lista *l)

	lista\_ord\_dimension(&l)	
	
**Devuelve:** 3

	
### lista\_ord\_buscar\_existe(lista *l,int valor);

	lista\_ord\_buscar\_existe(&l,1);

**Devuelve:** 0

	lista\_ord\_buscar\_existe(&l,8);

**Devuelve:** -1
	
    
