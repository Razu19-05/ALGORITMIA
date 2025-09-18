//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

void construir(struct Lista & listaTAD) {
    listaTAD.inicio = nullptr;
}

bool esListaVacia(const struct Lista & listaTAD) {
    return listaTAD.inicio == nullptr;
}

/*Inserta los elementos al inicio de la lista*/
void insertarAlInicio(struct Lista & listaTAD, const struct ElementoLista & elemento) {

    struct NodoLista * nuevo;
    nuevo = new struct NodoLista;
    nuevo->elemento = elemento;
    nuevo->siguiente = listaTAD.inicio;
    listaTAD.inicio = nuevo;
}

/*Inserta un elemento siempre al final de la lista*/
void insertarAlFinal(struct Lista & listaTAD, const struct ElementoLista & elemento) {

    struct NodoLista * ultimoNodoLista = obtenerUltimoNodo(listaTAD);
    struct NodoLista * nuevo;
    nuevo = new struct NodoLista;
    nuevo->elemento = elemento;
    nuevo->siguiente = nullptr;

    if (ultimoNodoLista == nullptr) /*Si la lista está vacía*/
        listaTAD.inicio = nuevo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene NodoListas
        ultimoNodoLista->siguiente = nuevo;
}

/*Obtiene el último NodoLista de la lista*/
struct NodoLista * obtenerUltimoNodo(const struct Lista & listaTAD) {
    struct NodoLista * ultimo = nullptr;
    struct NodoLista* recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

void insertarEnOrden(struct Lista & listaTAD, const struct ElementoLista & elemento) {

    struct NodoLista *nuevo, *recorrido = listaTAD.inicio, * anterior = nullptr;
    nuevo = new struct NodoLista;
    nuevo->elemento = elemento;
    while(recorrido){
        if(recorrido->elemento.codigo > elemento.codigo) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    nuevo->siguiente = recorrido;
    if(anterior == nullptr) listaTAD.inicio = nuevo;
    else anterior->siguiente = nuevo;
}

void eliminaNodo(struct Lista & listaTAD, const struct ElementoLista & elemento) {
    struct NodoLista * ultimo = nullptr;
    struct NodoLista * recorrido = listaTAD.inicio;
    /*Avanzo hasta encontrar el elemento*/
    /*Si no lo encuentra no elimina nada*/
    while ((recorrido != nullptr) and (recorrido->elemento.codigo != elemento.codigo)) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr) /*Estoy al inicio de la lista*/
            listaTAD.inicio = recorrido->siguiente;
        else
            ultimo->siguiente = recorrido->siguiente;
        delete recorrido; /*libera la memoria*/
    }
}

void destruir(struct Lista & listaTAD) {
    /*recorrido apunta al inicio del tad*/
    struct NodoLista * recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        /*NodoLista auxiliar que va servir para eliminar los NodoListas*/
        struct NodoLista * NodoListaAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete NodoListaAEliminar;
    }
    /*la lista queda vacia*/
    listaTAD.inicio = nullptr;

}

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprimir(const struct Lista & listaTAD) {

    if (esListaVacia(listaTAD)) {
        cout << "La lista esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoLista * recorrido = listaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despuÃ©s de la cabeza*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.codigo;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

void imprimeRecursivo(const struct Lista & lista) {
    cout << "Imprime recursivo... " << endl;
    if (not esListaVacia(lista)) {
        recorreRecursivo(lista.inicio);
    }
    cout << endl;
}

void recorreRecursivo(struct NodoLista * recorrido) {

    if (recorrido != nullptr) {
        cout << recorrido->elemento.codigo << " ";
        cout << recorrido->elemento.nombre << " ";
        cout << recorrido->elemento.equipo << endl;
        recorreRecursivo(recorrido->siguiente);
    }
}

void busquedaRecursivo(const struct Lista & lista, int elemento) {
    cout << "Busqqueda recursivo... " << endl;
    if (not esListaVacia(lista)) {
        seEncuentraRecursivo(lista.inicio, elemento);
    }
    cout << endl;
}

void seEncuentraRecursivo(struct NodoLista * recorrido, int elemento) {

    if (recorrido != nullptr) {
        if (recorrido->elemento.codigo == elemento)
            cout << "El elemento " << elemento << " pertenece a la lista" << endl;
        else
            seEncuentraRecursivo(recorrido->siguiente, elemento);
    } else
        cout << "El elemento " << elemento << " NO pertenece a la lista" << endl;

}


void invierteLista(struct Lista & lista) {
    struct NodoLista * anterior = nullptr;
    struct NodoLista * actual = lista.inicio;
    struct NodoLista * posterior = nullptr;

    while (actual != nullptr) {
        posterior = actual->siguiente; //almacena el siguiente nodo
        actual->siguiente = anterior; //invierte el enlace
        anterior = actual; //avanza el puntero anterior
        actual = posterior; // avanza el puntero actual
    }
    lista.inicio = anterior;
}

void invierteListaRecursivo(struct Lista & lista) {
    cout << "Invierte lista recursivo... " << endl;
    invierteLaListaRecursivo(lista.inicio);
}

void invierteLaListaRecursivo(struct NodoLista *& inicio) {
    if ((inicio == nullptr) or (inicio->siguiente == nullptr)) {
        return;
    }

    struct NodoLista * recorrido = inicio->siguiente;
    invierteLaListaRecursivo(recorrido); // Invierte el resto de la lista

    inicio->siguiente->siguiente = inicio; // Coloca el nodo actual al final del resto
    inicio->siguiente = nullptr; // El nuevo Ãºltimo nodo debe apuntar a nullptr

    inicio = recorrido; // Actualiza la nueva cabeza
}

/*Elimina repetidos cuando son consecutivos*/
void eliminaRepetidos(struct Lista & lista) {

    struct NodoLista * anterior = nullptr;
    struct NodoLista * recorrido = lista.inicio;

    anterior = lista.inicio;
    recorrido = lista.inicio->siguiente;

    while (recorrido != nullptr) {
        while (anterior->elemento.codigo != recorrido->elemento.codigo) { /*son diferentes*/
            anterior = anterior->siguiente;
            recorrido = recorrido->siguiente;
            if (recorrido == nullptr) break;
        }

        if (recorrido != nullptr) {
            anterior->siguiente = recorrido->siguiente; /*enlazo*/
            delete recorrido; /*borro*/
            recorrido = anterior->siguiente;
        }
    }
}

void completarLista(struct Lista & lista) {

    struct NodoLista * anterior = nullptr;
    struct NodoLista * recorrido;
    struct NodoLista * nuevoNodo;

    anterior = lista.inicio;
    recorrido = lista.inicio->siguiente;

    while (recorrido != nullptr) {
        while (anterior->elemento.codigo + 1 == recorrido->elemento.codigo) {
            anterior = anterior->siguiente;
            recorrido = recorrido->siguiente;
            if (recorrido == nullptr) return;
        }

        for (int i = anterior->elemento.codigo + 1; i < recorrido->elemento.codigo; i++) {
            struct NodoLista * nuevoNodo = new struct NodoLista;
            nuevoNodo->elemento.codigo = i;
            nuevoNodo->siguiente = anterior->siguiente;

            anterior->siguiente = nuevoNodo;
            nuevoNodo->siguiente = recorrido;
            anterior = nuevoNodo;
            recorrido = nuevoNodo->siguiente;
        }
    }
}

/*mÃ©todo que ordena intercambiando elementos, para datos simples funciona
 para estructuras lo mejor es usar los punteros*/
void bubbleSort(struct Lista & lista) {

    cout << "Ordeno la lista" << endl;
    if (esListaVacia(lista)) return;

    bool intercambio;
    struct NodoLista * recorrido;
    struct NodoLista * ultimo = nullptr;

    do {
        intercambio = false;
        recorrido = lista.inicio;

        /*Ojo que compara con recorrido siguiente para dejar el Ãºltimo ordenado*/
        while (recorrido->siguiente != ultimo) {
            if (recorrido->elemento.codigo > recorrido->siguiente->elemento.codigo) {
                // Intercambiamos los valores de los nodos
                int temp = recorrido->elemento.codigo;
                recorrido->elemento.codigo = recorrido->siguiente->elemento.codigo;
                recorrido->siguiente->elemento.codigo = temp;
                intercambio = true;
            }
            recorrido = recorrido->siguiente;
        }
        ultimo = recorrido;
    } while (intercambio);
}