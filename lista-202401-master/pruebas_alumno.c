#include "pa2m.h"
#include "src/lista.h"
#include "src/pila.h"
#include "src/cola.h"
#include <stdio.h>
#include <string.h>

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

void probar_creacion_lista(){
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista != NULL, "La lista se crea correctamente.");
    pa2m_afirmar(lista->nodo_inicio == NULL && lista->longitud == 0, "La lista está vacía al crearla.");

    // Liberar memoria
    free(lista);
}

void probar_lista_vacia(){
    lista_t* lista = lista_crear();
    pa2m_afirmar(lista_vacia(lista), "La lista creada está vacía.");

    lista_insertar(lista, "Elemento 1");
    lista_insertar(lista, "Elemento 2");

    pa2m_afirmar(!lista_vacia(lista), "La lista con elementos no está vacía.");

    // Liberar memoria
    nodo_t* actual = lista->nodo_inicio;
    while (actual != NULL) {
        nodo_t* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(lista);
}

void probar_insercion_elementos(){
    lista_t* lista = lista_crear();

    char* elemento_1 = "Elemento 1";
    char* elemento_2 = "Elemento 2";

    lista_insertar(lista, elemento_1);
    lista_insertar(lista, elemento_2);

    pa2m_afirmar(lista->nodo_inicio->elemento == elemento_1 && lista->longitud == 2, "Se insertan elementos correctamente en la lista.");

    // Liberar memoria
    nodo_t* actual = lista->nodo_inicio;
    while (actual != NULL) {
        nodo_t* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(lista);
}

void probar_insercion_en_posicion(){
    lista_t* lista = lista_crear();

    char* elemento_1 = "Elemento 1";
    char* elemento_2 = "Elemento 2";
    char* elemento_3 = "Elemento 3";

    lista_insertar(lista, elemento_1);
    lista_insertar(lista, elemento_2);

    lista_insertar_en_posicion(lista, elemento_3, 1);

    pa2m_afirmar(lista->nodo_inicio->siguiente->elemento == elemento_3 && lista->longitud == 3, "Se inserta un elemento en la posición indicada correctamente.");

    // Liberar memoria
    nodo_t* actual = lista->nodo_inicio;
    while (actual != NULL) {
        nodo_t* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(lista);
}

void probar_eliminar_ultimo_nodo() {
    lista_t* lista = lista_crear();

    // Insertar algunos elementos en la lista
    lista_insertar(lista, "Elemento 1");
    lista_insertar(lista, "Elemento 2");
    lista_insertar(lista, "Elemento 3");

    // Eliminar el último nodo y obtener el elemento eliminado
    void* elemento_eliminado = lista_quitar(lista);

    // Verificar si el elemento eliminado es el correcto
    pa2m_afirmar(elemento_eliminado != NULL, "Se elimina el último nodo correctamente.");

    // Verificar si el elemento eliminado es el esperado
    pa2m_afirmar(strcmp(elemento_eliminado, "Elemento 3") == 0, "El elemento eliminado es el esperado.");

    // Liberar la memoria de la lista (esto debe hacerse después de la prueba)
    nodo_t* actual = lista->nodo_inicio;
    while (actual != NULL) {
        nodo_t* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(lista);
}

int main(){
    pa2m_nuevo_grupo("Pruebas de Lista");

    probar_creacion_lista();
    probar_lista_vacia();
    probar_insercion_elementos();
    probar_insercion_en_posicion();
    probar_eliminar_ultimo_nodo();

    pa2m_mostrar_reporte();

    return 0;
}
