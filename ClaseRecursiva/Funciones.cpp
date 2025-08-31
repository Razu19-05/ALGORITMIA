
#include "Funciones.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int suma(int n) {
    int resultado;
    if (n==1)
        return 1;
    else
        resultado = suma(n-1) + n;//recursiva ejem: suma(4) + 5
    return resultado;
}
int multiplica(int m,int n) {
    int resultado;
    if (n == 1)
        return m;
    else
        resultado = multiplica(m,n-1) + m;// recursiva ejem: multiplica (7,3) + 7
    return resultado;
}

int max (int a, int b) {
    return a > b ? a : b;
}

int encontrarMayor(int *arreglo, int cant) {
    if (cant == 1)
        return arreglo[cant-1];//el arreglo en 0
    else
        return max(encontrarMayor(arreglo, cant-1),arreglo[cant-1]);
    //agarra el max entre encontrarMayor(arreglo,cant-1) y arreglo[cant-1]
}

int buscarNumero(int *arreglo, int cant, int numero) {
    if (cant == 0) return -1;
    if (arreglo[cant-1]==numero)
        return cant-1;//de vuelve la posicion donde se encunetra
    else return buscarNumero(arreglo, cant-1, numero);
}

void hanoi(int num,char desde, char aux,char hacia) {
    //posiciones de inicio A, B, C
    //se interpreta, mueve A a C usando B como auxiliar
    //caso base
    if (num == 1) moverUnDisco (num,desde,hacia);
    else {
        hanoi(num-1,desde,hacia,aux);
        moverUnDisco(num,desde,hacia);
        hanoi(num-1,aux,desde,hacia);
    }
}
void moverUnDisco(int n, char desde, char hacia){
    //mueve un disco desde -> hacia
    cout << "Mover disco: " << n <<" desde la torre " <<desde
         << " hacia la torre " << hacia << endl;
}
