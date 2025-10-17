//Gabriel Huarote 20231846

#include "Lista/Lista.h"
#include "Lista/funcionesLista.h"
#include "Lista/ElementoLista.h"
#include <cstring>
using namespace std;


void llenarElementos(ElementoLista &e1,ElementoLista &e2,ElementoLista &e3,ElementoLista &e4,
    ElementoLista &e5,ElementoLista &e6) {
    e1.codigo = 7;
    strcpy(e1.nombre,"Martínez");
    strcpy(e1.posicion,"Delantero");
    e2.codigo = 1;
    strcpy(e2.nombre,"Ramírez");
    strcpy(e2.posicion,"Portero");
    e3.codigo = 5;
    strcpy(e3.nombre,"Pérez");
    strcpy(e3.posicion,"Defensa");
    e4.codigo = 8;
    strcpy(e4.nombre,"Torres");
    strcpy(e4.posicion,"Mediocampo");
    e5.codigo = 9;
    strcpy(e5.nombre,"López");
    strcpy(e5.posicion,"Delantero");
    e6.codigo = 3;
    strcpy(e6.nombre,"Gómez");
    strcpy(e6.posicion,"Defensa");

}
void reOrdenarFormacion(Lista &lista) {
    NodoLista *recorrido = lista.inicio;
    NodoLista *portero = nullptr;
    NodoLista *defensa = nullptr;
    NodoLista *colaDefensa = nullptr;
    NodoLista *mediocampo = nullptr;
    NodoLista *colaMediocampo = nullptr;
    NodoLista *delantero = nullptr;
    NodoLista *colaDelantero = nullptr;
    while (recorrido != nullptr) {
        ElementoLista elem = recorrido->elemento;
        if (strcmp(elem.posicion,"Portero") == 0) {
            portero = recorrido;
        }
        if (strcmp(elem.posicion,"Defensa")==0) {
            if (defensa == nullptr and colaDefensa == nullptr) {
                defensa = recorrido;
                colaDefensa = recorrido;
            }else {
                colaDefensa = recorrido;
                defensa->siguiente = colaDefensa;
            }
        }
        if (strcmp(elem.posicion,"Mediocampo") == 0) {
            if (mediocampo == nullptr and colaMediocampo == nullptr) {
                mediocampo = recorrido;
                colaMediocampo = recorrido;
            }else {
                colaMediocampo = recorrido;
                mediocampo->siguiente = colaMediocampo;
            }
        }

        if (strcmp(elem.posicion,"Delantero")==0) {
            if (delantero == nullptr and colaDelantero == nullptr) {
                delantero = recorrido;
                colaDelantero = recorrido;
            }else {
                colaDelantero = recorrido;
                delantero->siguiente = colaDelantero;
            }
        }
        recorrido = recorrido->siguiente;
    }

    colaDelantero->siguiente = nullptr;
    mediocampo->siguiente = delantero;
    colaDefensa->siguiente = mediocampo;
    portero->siguiente = defensa;
    lista.inicio = portero;
}

int main() {
    Lista lista;
    ElementoLista e1,e2,e3,e4,e5,e6;
    llenarElementos(e1,e2,e3,e4,e5,e6);
    construir(lista);
    insertarAlFinal(lista,e1);
    insertarAlFinal(lista,e2);
    insertarAlFinal(lista,e3);
    insertarAlFinal(lista,e4);
    insertarAlFinal(lista,e5);
    insertarAlFinal(lista,e6);

    imprimir(lista);
    reOrdenarFormacion(lista);
    imprimir(lista);


    return 0;
}