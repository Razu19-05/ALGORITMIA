//Gabriel Huarote Serrano 20231846
#include <iostream>
#include "Pila/Pila.h"
#include "Pila/funcionesPila.h"
#include "Pila/ElementoPila.h"
using namespace std;


void hanoi(Pila &desde, Pila &aux, Pila &hacia, int n) {
    if (n==1) {
        apilar(hacia, desapilar(desde));
        return;
    }
    hanoi(desde,hacia,aux,n-1);
    apilar(hacia, desapilar(desde));
    hanoi(aux,desde,hacia,n-1);
}

void fusionarPilas(Pila &pilaA, Pila &pilaB, Pila &pilaC) {
    Pila pilaAux;
    bool primeraVez = true;
    int n ;
    construir(pilaAux);

    while (!esPilaVacia(pilaA) || !esPilaVacia(pilaB)) {
        ElementoPila numA, numB;
        bool aVacia = esPilaVacia(pilaA);
        bool bVacia = esPilaVacia(pilaB);
        if (!aVacia) numA = cima(pilaA);
        if (!bVacia) numB = cima(pilaB);
        // Determinar de qué pila tomar el elemento
        if (aVacia) {
            // Solo queda pilaB
            n = longitud(pilaAux);
            hanoi(pilaAux,pilaC,pilaA,n);
            apilar(pilaAux, desapilar(pilaB));
            hanoi(pilaA,pilaC,pilaAux,n);
        } else if (bVacia) {
            // Solo queda pilaA
            n = longitud(pilaAux);
            hanoi(pilaAux,pilaC,pilaB,n);
            apilar(pilaAux, desapilar(pilaA));
            hanoi(pilaB,pilaC,pilaAux,n);
        } else {
            // Ambas pilas tienen elementos, tomar el menor
            if (numA.numero <= numB.numero) {
                if (primeraVez) {
                    apilar(pilaAux, desapilar(pilaB));
                    apilar(pilaAux, desapilar(pilaA));
                    primeraVez = false;
                }
                else {
                    n = longitud(pilaAux);
                    hanoi(pilaAux,pilaC,pilaB,n);
                    apilar(pilaAux, desapilar(pilaA));
                    hanoi(pilaB,pilaC,pilaAux,n);
                }
            } else {// numA.numero > numB. numero
                if (primeraVez) {
                    apilar(pilaAux, desapilar(pilaA));
                    apilar(pilaAux, desapilar(pilaB));
                    primeraVez = false;
                }
                else {
                    n = longitud(pilaAux);
                    hanoi(pilaAux,pilaC,pilaA,n);
                    apilar(pilaAux, desapilar(pilaB));
                    hanoi(pilaA,pilaC,pilaAux,n);
                }
            }
        }
    }
    pilaC = pilaAux;
}

using namespace std;
int main() {
    Pila pilaA, pilaB,pilaC;
    ElementoPila e1, e2, e3, e4, e5, e6, e7;
    e1.numero = 5;
    e2.numero = 15;
    e3.numero = 20;
    e4.numero = 2;
    e5.numero = 10;
    e6.numero = 12;
    e7.numero = 18;
    construir(pilaA);
    construir(pilaB);
    construir(pilaC);

    apilar(pilaA,e3);
    apilar(pilaA,e2);
    apilar(pilaA,e1);
    // imprimir(pilaA);

    apilar(pilaB,e7);
    apilar(pilaB,e6);
    apilar(pilaB,e5);
    apilar(pilaB,e4);
    // imprimir(pilaB);

    fusionarPilas(pilaA,pilaB,pilaC);
    imprimir(pilaC);


    return 0;
}