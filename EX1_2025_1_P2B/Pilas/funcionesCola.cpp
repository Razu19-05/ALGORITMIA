//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;

void construir(struct Cola & colaTAD){
    colaTAD.inicio = nullptr;
    colaTAD.fin = nullptr;
    colaTAD.longit = 0;
}

/*devuelve la longitud de la cola*/
int longitud(const struct Cola & colaTAD) {
    return colaTAD.longit;
}

void encolar(struct Cola &colaTAD, const struct ElementoCola & elemento){
    struct NodoCola *nuevo;
    nuevo = new NodoCola{};
    nuevo->elemento = elemento;
    if(esColaVacia(colaTAD)){
        colaTAD.inicio = nuevo;
        colaTAD.fin = nuevo;
    }
    else {
        colaTAD.fin->siguiente = nuevo;
        colaTAD.fin = nuevo;
    }
    colaTAD.longit++;
}

struct ElementoCola desencolar(struct Cola &colaTAD) {
    struct ElementoCola elemento;

    // Si la cola está vacía
    if (colaTAD.inicio == nullptr) {
        cout << "Cola vacía\n";
        return elemento; // retorna vacío
    }

    // Si solo hay un elemento
    if (colaTAD.inicio->siguiente == nullptr) {
        elemento = colaTAD.inicio->elemento;
        delete colaTAD.inicio;
        colaTAD.inicio = nullptr;
        colaTAD.fin = nullptr;
        colaTAD.longit--;
        return elemento;
    }

    // Recorremos hasta el penúltimo nodo
    struct NodoCola *actual = colaTAD.inicio;
    while (actual->siguiente->siguiente != nullptr) {
        actual = actual->siguiente;
    }

    // actual apunta al penúltimo
    struct NodoCola *pSale = actual->siguiente;
    elemento = pSale->elemento;
    delete pSale;
    actual->siguiente = nullptr;
    colaTAD.fin = actual;
    colaTAD.longit--;

    return elemento;
}
bool esColaVacia(const struct Cola & colaTAD){
    return colaTAD.inicio == nullptr;
}

void imprimir(const struct Cola & colaTAD) {
    if (esColaVacia(colaTAD)) {
        cout << "La cola esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoCola * recorrido = colaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despues del inicio*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.codigo;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

struct ElementoCola desencolarDefecto(struct Cola & colaTAD){
    struct NodoCola * pSale;
    struct ElementoCola elemento;
    pSale = colaTAD.inicio;
    colaTAD.inicio = colaTAD.inicio->siguiente;
    elemento = pSale->elemento;
    colaTAD.longit--;
    delete pSale;
    return elemento;
}
