
#include <iostream>
#include <cstring>
#include "Lista/funcionesLista.h"
#include "Lista/Lista.h"

using namespace std;

void llenarElemetos(ElementoLista &a1,ElementoLista &a2,ElementoLista &a3,ElementoLista &a4, ElementoLista &a5, ElementoLista &a6) {
    a1.codigo = 17;
    strcpy(a1.nombre,"Messala");
    strcpy(a1.equipo,"Rojo");
    a2.codigo = 4;
    strcpy(a2.nombre,"Ben-Hur");
    strcpy(a2.equipo,"Azul");
    a3.codigo = 12;
    strcpy(a3.nombre,"Artax");
    strcpy(a3.equipo,"Verde");
    a4.codigo = 7;
    strcpy(a4.nombre,"Drusus");
    strcpy(a4.equipo,"Negro");
    a5.codigo = 32;
    strcpy(a5.nombre,"Drusus");
    strcpy(a5.equipo,"Negro");
    a6.codigo = 11;
    strcpy(a6.nombre,"Drusus");
    strcpy(a6.equipo,"Negro");
}

bool esImpar(int numero) {
    if (numero % 2 != 0)  return true;
    else return false;
}

void moverLista(Lista &lista) {
    NodoLista* recorrido = lista.inicio;
    NodoLista* par = nullptr;
    NodoLista* colaPar = nullptr;
    NodoLista* impar = nullptr;
    NodoLista* colaImpar = nullptr;
    bool primeraVezPar = true, primeraVezImpar = true;
    while (recorrido != nullptr) {
        NodoLista* siguiente = recorrido->siguiente;
        recorrido->siguiente = nullptr;

        if (esImpar(recorrido->elemento.codigo)) {
            if (primeraVezImpar) {
                impar = recorrido;
                colaImpar = recorrido;
                primeraVezImpar = false;
            } else {
                colaImpar->siguiente = recorrido;
                colaImpar = recorrido;
            }
        } else {
            if (primeraVezPar) {
                par = recorrido;
                colaPar = recorrido;
                primeraVezPar = false;
            } else {
                colaPar->siguiente = recorrido;
                colaPar = recorrido;
            }
        }

        recorrido = siguiente;
    }


    if (colaPar != nullptr) {
        colaPar->siguiente = impar;
        lista.inicio = par;
    } else {
        lista.inicio = impar;
    }
}


int main() {
    Lista lista;
    ElementoLista a1,a2,a3,a4,a5,a6;
    construir(lista);
    llenarElemetos(a1,a2,a3,a4,a5,a6);
    insertarAlFinal(lista,a1);
    insertarAlFinal(lista,a2);
    insertarAlFinal(lista,a3);
    insertarAlFinal(lista,a4);
    insertarAlFinal(lista,a5);
    insertarAlFinal(lista,a6);
    imprimeRecursivo(lista);
    moverLista(lista);
    imprimeRecursivo(lista);
    return 0;
}
