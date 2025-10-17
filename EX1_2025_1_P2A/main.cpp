#include "Lista/funcionesLista.h"
#include "Lista/Lista.h"
#include "Lista/ElementoLista.h"
#include <iostream>
using namespace std;

void llenarLista(Lista &lista) {
    ElementoLista e1;
    e1.codigo = 1; e1.cantidad = 10; e1.prioridad = 'B'; insertarAlFinal(lista, e1);
    e1.codigo = 2; e1.cantidad = 20; e1.prioridad = 'A'; insertarAlFinal(lista, e1);
    e1.codigo = 3; e1.cantidad = 15; e1.prioridad = 'B'; insertarAlFinal(lista, e1);
    e1.codigo = 4; e1.cantidad = 12; e1.prioridad = 'B'; insertarAlFinal(lista, e1);
    e1.codigo = 5; e1.cantidad = 5;  e1.prioridad = 'C'; insertarAlFinal(lista, e1);
    e1.codigo = 6; e1.cantidad = 6;  e1.prioridad = 'A'; insertarAlFinal(lista, e1);
    e1.codigo = 7; e1.cantidad = 8;  e1.prioridad = 'C'; insertarAlFinal(lista, e1);
    e1.codigo = 8; e1.cantidad = 4;  e1.prioridad = 'C'; insertarAlFinal(lista, e1);
    e1.codigo = 9; e1.cantidad = 2;  e1.prioridad = 'B'; insertarAlFinal(lista, e1);
}


void unirListas(NodoLista *&inicio1, NodoLista *&fin1, NodoLista *inicio2, NodoLista *fin2) {
    if (inicio2 == nullptr) return; // nada que unir
    if (inicio1 == nullptr) {
        inicio1 = inicio2;
        fin1 = fin2;
    } else {
        fin1->siguiente = inicio2;
        fin1 = fin2;
    }
    // asegurar terminación
    if (fin1) fin1->siguiente = nullptr;
}

void ordenarLista(Lista &lista) {
    if (esListaVacia(lista)) return;

    NodoLista *Aini = nullptr, *Afin = nullptr;
    NodoLista *Gini = nullptr, *Gfin = nullptr;
    NodoLista *Oini = nullptr, *Ofin = nullptr;

    NodoLista *actual = lista.inicio;

    while (actual != nullptr) {
        NodoLista *siguiente = actual->siguiente; // guardar siguiente antes de cortar
        // NO cortar actual->siguiente todavía; primero decidir qué hacemos con actual
        if (actual->elemento.prioridad == 'A') {
            // Es 'A' => desconectar y unir a A
            actual->siguiente = nullptr;
            unirListas(Aini, Afin, actual, actual);
        } else {
            // Contar cuántos consecutivos comparten la misma prioridad (incluye 'actual')
            int contador = 1;
            NodoLista *temp = siguiente;
            while (temp != nullptr && temp->elemento.prioridad == actual->elemento.prioridad) {
                contador++;
                temp = temp->siguiente;
            }

            if (contador >= 2) {
                // Es un grupo: determinar inicio y fin del grupo (referencias de la lista original)
                NodoLista *grupoInicio = actual;
                NodoLista *grupoFin = actual;
                for (int i = 1; i < contador; ++i) {
                    // avanzar hasta el fin del grupo; como no hemos cortado enlaces esto es seguro
                    grupoFin = grupoFin->siguiente;
                }
                // guardar el siguiente después del grupo
                siguiente = grupoFin->siguiente;
                // desconectar el grupo
                grupoFin->siguiente = nullptr;

                // unir grupo a la lista de grupos
                unirListas(Gini, Gfin, grupoInicio, grupoFin);

                // actual debe saltar al final del grupo (en el while luego se asigna actual = siguiente)
                // no hacemos actual = grupoFin aquí porque al final del bucle haremos actual = siguiente
            } else {
                // Nodo aislado: desconectar y añadir a "otros"
                actual->siguiente = nullptr;
                unirListas(Oini, Ofin, actual, actual);
            }
        }

        // avanzar al siguiente bloque / nodo guardado
        actual = siguiente;
    }

    // Reconstruir la lista en el orden: A -> grupos -> otros
    NodoLista *nuevoInicio = nullptr;
    NodoLista *nuevoFin = nullptr;

    unirListas(nuevoInicio, nuevoFin, Aini, Afin);
    unirListas(nuevoInicio, nuevoFin, Gini, Gfin);
    unirListas(nuevoInicio, nuevoFin, Oini, Ofin);

    lista.inicio = nuevoInicio;
}

int main() {
    Lista lista;
    construir(lista);
    llenarLista(lista);

    cout << "=== Lista original ==="<<endl;
    imprimir(lista);

    ordenarLista(lista);

    cout << "=== Lista reordenada ==="<<endl;
    imprimir(lista);

    return 0;
}
