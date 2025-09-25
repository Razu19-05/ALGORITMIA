#include "src/funcionesLista.h"
#include "src/Lista.h"
using namespace std;

void contruirListas(Lista &lunes,Lista &martes,Lista &miercoles,Lista &jueves,Lista &viernes){
    construir(lunes);
    construir(martes);
    construir(miercoles);
    construir(jueves);
    construir(viernes);
}

void fusionarLista(Lista& lista1,Lista &lista2) {
    NodoLista *inicio1 = lista1.inicio;
    NodoLista *fin1 = obtenerUltimoNodo(lista1);
    NodoLista *inicio2 = lista2.inicio;
    NodoLista *fin2 = obtenerUltimoNodo(lista2);
    if (fin1->elemento.codigo < inicio2->elemento.codigo) {
        fin1->siguiente = inicio2;
    } else if (inicio1->elemento.codigo > fin2->elemento.codigo) {
        fin2->siguiente = inicio1;
        lista1.inicio= inicio2;
    }
    else {
        NodoLista *ptrInicio = nullptr;
        NodoLista *ptrFin = nullptr;
        while (!esListaVacia(lista1) && !esListaVacia(lista2)){
            if (lista1.inicio->elemento.codigo <= lista2.inicio->elemento.codigo){
                if (ptrInicio == nullptr){
                    ptrInicio = lista1.inicio;
                    ptrFin = lista1.inicio;
                }
                else{
                    ptrFin->siguiente = lista1.inicio;
                    ptrFin = lista1.inicio;
                }
                lista1.inicio = lista1.inicio->siguiente;
            }
            else{
                if (ptrInicio == nullptr){
                    ptrInicio = lista2.inicio;
                    ptrFin = lista2.inicio;
                }
                else{
                    ptrFin->siguiente = lista2.inicio;
                    ptrFin = lista2.inicio;
                }
                lista2.inicio = lista2.inicio->siguiente;
            }
        }

        while (!esListaVacia(lista1)){
            ptrFin->siguiente = lista1.inicio;
            ptrFin = lista1.inicio;
            lista1.inicio = lista1.inicio->siguiente;
        }
        while (!esListaVacia(lista2)){
            ptrFin->siguiente = lista2.inicio;
            ptrFin = lista2.inicio;
            lista2.inicio = lista2.inicio->siguiente;
        }
        lista1.inicio = ptrInicio;
    }
}

int main() {
    Lista lunes, martes, miercoles, jueves, viernes;
    ElementoLista e1, e2, e3;
    contruirListas(lunes,martes,miercoles,jueves,viernes);
    e1.codigo = 8;
    e1.dia = 1;
    e2.codigo = 10;
    e2.dia = 1;
    e3.codigo = 12;
    e3.dia = 1;
    insertarAlFinal(lunes,e1);
    insertarAlFinal(lunes,e2);
    insertarAlFinal(lunes,e3);
    imprimir(lunes);
    e1.codigo = 9;
    e1.dia = 2;
    e2.codigo = 11;
    e2.dia = 2;
    insertarAlFinal(martes,e1);
    insertarAlFinal(martes,e2);
    imprimir(martes);
    e1.codigo = 8;
    e1.dia = 3;
    e2.codigo = 9;
    e2.dia = 3;
    e3.codigo = 10;
    e3.dia = 3;
    insertarAlFinal(miercoles,e1);
    insertarAlFinal(miercoles,e2);
    insertarAlFinal(miercoles,e3);
    imprimir(miercoles);
    e1.codigo = 14;
    e1.dia = 4;
    e2.codigo = 15;
    e2.dia = 4;
    e3.codigo = 16;
    e3.dia = 4;
    insertarAlFinal(jueves,e1);
    insertarAlFinal(jueves,e2);
    insertarAlFinal(jueves,e3);
    imprimir(jueves);
    e1.codigo = 17;
    e1.dia = 5;
    e2.codigo = 18;
    e2.dia = 5;
    e3.codigo = 19;
    e3.dia = 5;
    insertarAlFinal(viernes,e1);
    insertarAlFinal(viernes,e2);
    insertarAlFinal(viernes,e3);
    imprimir(viernes);
    fusionarLista(lunes,martes);
    imprimir(lunes);
    fusionarLista(lunes,miercoles);
    imprimir(lunes);
    fusionarLista(lunes,jueves);
    imprimir(lunes);
    fusionarLista(lunes,viernes);
    imprimir(lunes);

    return 0;
}
