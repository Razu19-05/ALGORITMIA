#include "Pilas/funcionesCola.h"
#include "Pilas/Cola.h"
#include "Pilas/ElementoCola.h"
#include <iostream>
using namespace std;

void agregarTemperatura(Cola &cola, int temp, int cant, int k) {
    ElementoCola elemento;
    elemento.codigo = temp;
    if (cant <= k)
        encolar(cola, elemento);
    else {
        desencolarDefecto(cola);
        encolar(cola, elemento);
    }
}

void copiar(Cola &origen, Cola &destino, int cant) {
    if (cant == 0 || esColaVacia(origen)) return; // Caso base
    // Desencolar el primer elemento
    ElementoCola elem = desencolar(origen);
    // Llamada recursiva con el resto
    copiar(origen, destino, cant - 1);
    // Después de volver de la recursión, encolamos en ambos
    encolar(destino, elem);
    encolar(origen, elem);
}

double promedioRec(Cola &cola, int &n, double &suma) {
    if (esColaVacia(cola))
        return 0;

    ElementoCola elem = desencolar(cola);
    suma += elem.codigo;
    n++;

    promedioRec(cola, n, suma);

    encolar(cola, elem); // restaurar orden
    return suma / n;
}

double promedio(Cola &cola) {
    int n = 0;
    double suma = 0;
    return promedioRec(cola, n, suma);
}

int main() {
    Cola cola, aux;
    construir(cola);
    int k, temp, cant = 1;
    double prom;
    bool agregar = true;
    cout << "Ingrese K: ";
    cin >> k;
    while (true) {
        if (agregar) {
            cout << "Ingrese Temperatura (-1 para salir): ";
            cin >> temp;
            if (temp == -1) break;
            agregarTemperatura(cola, temp, cant, k);
            agregar = false;
            cant++;
        }
        else {
            construir(aux);
            copiar(cola,aux,cant-1);
            imprimir(aux);
            agregar = true;
            prom = promedio(aux);
            cout << "Promedio: " << prom << endl;
        }
    }
    return 0;
}