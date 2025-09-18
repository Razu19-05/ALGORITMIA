#include <cmath>
#include <iostream>
#include <iomanip>
#include <math.h>
#define MAX_TABLA 6
#define MAX_DISCO 3
using namespace std;

void paseBase(int numero, int base, int cromosoma[MAX_TABLA], int size) {
    for (int i = 0; i < size; i++) cromosoma[i] = 0;//cromosomas en 0
    int i = 0;
    while (numero != 0) {
        cromosoma[i++] = numero % base;
        numero /= base;
    }
}

int main() {
    int tablas[MAX_TABLA]{150,100,80,50,120,10};
    int disco[MAX_DISCO]{250,200,200};
    int cromosoma[MAX_TABLA];
    int combinaciones = pow(MAX_DISCO, MAX_TABLA);
    int mejorMinimo = -1, mejorIndice;

    for (int i = 0; i < combinaciones; i++) {
        int auxDisco[MAX_DISCO];
        for (int j = 0; j < MAX_DISCO; j++) auxDisco[j] = disco[j];
        paseBase(i,MAX_DISCO,cromosoma,MAX_TABLA);
        for (int j = 0; j < MAX_TABLA; j++) {
            int pos = cromosoma[j];//me dira a que disco va
            auxDisco[pos] -= tablas[j];
        }
        int minimo = auxDisco[0];
        for (int i = 1; i < MAX_DISCO; i++)
            if (auxDisco[i] < minimo) minimo = auxDisco[i];
        if (minimo > mejorMinimo) {
            mejorMinimo = minimo;
            mejorIndice = i;
        }
    }
    cout << "La mejor velocidad minima de grupo es: " << mejorMinimo << " IOPs"<<endl;
    cout << "Distribución de tablas en discos:"<<endl;
    paseBase(mejorIndice,MAX_DISCO,cromosoma,MAX_TABLA);
    for (int i = 0; i < MAX_DISCO; i++) {
        cout << "DISCO "<<i+1<<": ";
        for (int j = 0; j < MAX_TABLA; j++)
            if (cromosoma[j] == i) cout << j+1 << " ";
        cout << endl;
    };
    return 0;
}