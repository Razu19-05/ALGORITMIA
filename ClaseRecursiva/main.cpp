#include <iostream>
#include <iomanip>
#include <cmath>
#include "Funciones.hpp"
#define N 8
using namespace std;
int main() {
    int m, n, sumatoria,producto;
    /*sumatoria de numeros naturales de 1 a n*/
    n=5;
    sumatoria = suma(n);
    cout<<sumatoria<<endl;
    /*multiplicar de numeros naturales de 1 a n*/
    m=7;
    n=4;
    producto = multiplica(m,n);
    cout<<producto<<endl;
    /*Buscar numero mayor*/
    int arreglo[N]={9, 8, 7, 6, 10, 1, 14, 3};
    int mayor = encontrarMayor(arreglo,N);
    cout<<mayor<<endl;
    /*Buscar el numero deseado*/
    int numero=12;
    int indice = buscarNumero(arreglo,N,numero);
    if (indice == -1) cout<<"NO SE ENCONTRO EL NUMERO"<<endl;
    else cout<<"SE ENCONTRO EL NUEMERO EN: "<<indice+1<<endl;

    // ------------------------------------------------------------------------
    //HANOI FUCKKKKKKKKK
    int numDiscos;
    cout<<"Ingrese el numero de discos:";
    cin>>numDiscos;
    /*Condiciones para el juego
     A: es la torre de inicio
     B: es la torre auxiliar
     C: es la torre final*/
    cout << "RESULTADO DE HANOI CON " << numDiscos << endl << endl;
    hanoi(numDiscos,'A','B','C');
    return 0;
}