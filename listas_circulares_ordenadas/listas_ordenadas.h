/*
 Libreria de Listas ordenas
*/
#ifndef LISTAS_ORDENADAS_H
#define LISTAS_ORDENADAS_H

struct nodo
{
	int dato;
	struct nodo * siguiente;
};


/*
 * Devuelve el tamaño de la lista ordenada
 */

int tam(struct nodo * actual)
 {
	int len = 0;
	while(actual)
	{
		len++;
		actual = actual->siguiente;
	}
	return len;
}

/*
 * Imprime el contenido de la lista
 */
void list_ord_imprimir(struct nodo * lista_ord)
{
	while(lista_ord){
		printf("[%d]->",lista_ord->dato);
		lista_ord = lista_ord->siguiente;
	}
	printf("NULL\n");
}

/*
 * Inserta el valor numerico dato en la lista ordenada
 */
struct nodo* list_ord_insertar(struct nodo* list_ord, int dato)
{
    struct nodo * actual = list_ord;
    struct nodo * nuevoNodo = (nodo*)(malloc(sizeof(nodo*)));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    //Caso base para el 1er elemento
    if(list_ord == NULL)
		return nuevoNodo;
	//ahora el sigiente es buscar la posicion de dato
	while(actual!=NULL){
		
        if(actual->siguiente==NULL){
            actual->siguiente = nuevoNodo;
            break;
		}if(actual->siguiente->dato < nuevoNodo->dato){
			nuevoNodo->siguiente = actual->siguiente;
			actual->siguiente = nuevoNodo;
			break;
		}
		else
			actual = actual->siguiente;
	}
	list_ord_imprimir(list_ord);
    return list_ord;
}

/*
 * Devuelve true si la lista esta vacia y false en caso contrario
 */
bool list_ord_es_vacio(struct nodo * list_ord){
    if(list_ord == NULL)
    {
		printf("La lista ordenada esta vacia");
		return true;
    }
    else{
        return false;
    }
}

/*
 * Borra un elemento en la lista apartir de su valor
 */
struct nodo * list_ord_borrar(struct nodo * list_ord, int dato){
    struct nodo * actual = list_ord;
	while(actual!=NULL){
        if(actual->siguiente != NULL && actual->siguiente->dato == dato){
			actual->siguiente = actual->siguiente->siguiente;
			break;
		}
		else
			actual = actual->siguiente;
	}
	list_ord_imprimir(list_ord);
    return list_ord;
}

#endif
