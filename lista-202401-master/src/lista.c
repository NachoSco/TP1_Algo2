#include "lista.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct nodo {
	void *elemento;
	struct nodo *siguiente;
} nodo_t;

struct lista {
	nodo_t *nodo_inicio;
	size_t longitud;
};

struct lista_iterador {
	//y acá?
	int sarasa;
};

nodo_t *crear_nodo(void *elemento){

	nodo_t* Nodo_nuevo = malloc(sizeof(nodo_t));
	if (Nodo_nuevo == NULL){
		return NULL;
	}
	Nodo_nuevo->elemento = elemento;
	Nodo_nuevo->siguiente = NULL;

	return Nodo_nuevo;
}

lista_t *lista_crear(){

	lista_t *lista = malloc(sizeof(lista_t));
	if (lista == NULL){
		return NULL;
	}
	lista->nodo_inicio = NULL;
	lista->longitud = 0;

	return lista;
}


lista_t *lista_insertar(lista_t *lista, void *elemento)
{
    if (lista == NULL) {
        return NULL; // La lista no existe, devuelve NULL
    }

    nodo_t *nodo_nuevo = crear_nodo(elemento);
    if (nodo_nuevo == NULL) {
        return NULL; // Error al crear el nuevo nodo, devuelve NULL
    }

    if (lista->longitud == 0) {
        // La lista está vacía, el nuevo nodo será el primer nodo
        lista->nodo_inicio = nodo_nuevo;
    } else {
        // La lista ya contiene elementos, hay que encontrar el último nodo
        nodo_t *actual = lista->nodo_inicio;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        // Enlaza el nuevo nodo al final de la lista
        actual->siguiente = nodo_nuevo;
    }

    lista->longitud++;
    return lista;
}

lista_t *lista_insertar_en_posicion(lista_t *lista, void *elemento, size_t posicion) {
    if (lista == NULL) {
        return NULL; // La lista no existe, devuelve NULL
    }

    nodo_t *nodo_nuevo = crear_nodo(elemento);
    if (nodo_nuevo == NULL) {
        return NULL; // Error al crear el nuevo nodo, devuelve NULL
    }

    if (posicion == 0 || lista->nodo_inicio == NULL) {
        // Insertar al principio de la lista o lista vacía
        nodo_nuevo->siguiente = lista->nodo_inicio;
        lista->nodo_inicio = nodo_nuevo;
    } else {
        nodo_t *anterior = lista->nodo_inicio;
        size_t i = 0;
        // Buscar el nodo en la posición anterior a la posición deseada
        while (i < posicion - 1 && anterior->siguiente != NULL) {
            anterior = anterior->siguiente;
            i++;
        }
        // Insertar en la posición deseada
        nodo_nuevo->siguiente = anterior->siguiente;
        anterior->siguiente = nodo_nuevo;
    }

    lista->longitud++;
    return lista;
}

void *lista_quitar(lista_t *lista) {
    if (lista == NULL || lista->nodo_inicio == NULL) {
        return NULL; // La lista está vacía o no existe, devuelve NULL
    }

    nodo_t* actual = lista->nodo_inicio;
    nodo_t* anteultimo = NULL;

    while (actual->siguiente != NULL) {
        anteultimo = actual;
        actual = actual->siguiente;
    }

    void* elemento_eliminado = actual->elemento;
    free(actual);
    
    if (anteultimo != NULL) {
        // Actualizamos el puntero al último nodo
        anteultimo->siguiente = NULL;
    } else {
        // La lista solo tenía un elemento
        lista->nodo_inicio = NULL;
    }

    lista->longitud--;

    return elemento_eliminado;
}

void *lista_quitar_de_posicion(lista_t *lista, size_t posicion)
{
	return NULL;
}

void *lista_elemento_en_posicion(lista_t *lista, size_t posicion)
{
	return NULL;
}

void *lista_buscar_elemento(lista_t *lista, int (*comparador)(void *, void *),
			    void *contexto)
{
	return NULL;
}

void *lista_primero(lista_t *lista)
{
	return NULL;
}

void *lista_ultimo(lista_t *lista)
{
	return NULL;
}

bool lista_vacia(lista_t *lista)
{
	return true;
}

size_t lista_tamanio(lista_t *lista)
{
	return 0;
}

void lista_destruir(lista_t *lista)
{
}

void lista_destruir_todo(lista_t *lista, void (*funcion)(void *))
{
}

lista_iterador_t *lista_iterador_crear(lista_t *lista)
{
	return NULL;
}

bool lista_iterador_tiene_siguiente(lista_iterador_t *iterador)
{
	return false;
}

bool lista_iterador_avanzar(lista_iterador_t *iterador)
{
	return false;
}

void *lista_iterador_elemento_actual(lista_iterador_t *iterador)
{
	return NULL;
}

void lista_iterador_destruir(lista_iterador_t *iterador)
{
}

size_t lista_con_cada_elemento(lista_t *lista, bool (*funcion)(void *, void *),
			       void *contexto)
{
	return 0;
}
