
#include <iostream>
#include <cmath>
using namespace std;

#define N 6   // Número de tablas
#define M 3   // Número de discos

// Convierte numero en base M y lo guarda en arreglo asignacion
void paseBase(int numero, int base, int cromosoma[N], int size) {
    for (int i = 0; i < size; i++) cromosoma[i] = 0;
    int i = 0;
    while (numero != 0) {
        cromosoma[i++] = numero % base;
        numero /= base;
    }
}

int main() {
    // Velocidades de tablas (IOPs)
    int tablas[N] = {150, 100, 80, 50, 120, 10};
    // Velocidades de discos (IOPs)
    int discosBase[M] = {250, 200, 200};

    int cromosoma[N];
    int totalCombinaciones = pow(M, N);

    int mejorMinimo = -1;
    int mejorIndice;

    for (int num = 0; num < totalCombinaciones; num++) {
        // Copiamos velocidades originales
        int discos[M];
        for (int d = 0; d < M; d++) discos[d] = discosBase[d];

        paseBase(num, M, cromosoma, N);

        // Asignamos tablas a discos
        for (int t = 0; t < N; t++) {
            int d = cromosoma[t];
            discos[d] -= tablas[t];//restamos lo del disco menos las tablas que entran
        }

        // Calculamos el mínimo performance de los discos
        int minimo = discos[0];
        for (int d = 1; d < M; d++)
            if (discos[d] < minimo) minimo = discos[d];


        // Guardamos mejor solución
        if (minimo > mejorMinimo) {
            mejorMinimo = minimo;
            mejorIndice = num;
        }
    }

    // Mostrar solución óptima
    cout << "La mejor velocidad minima de grupo es: " << mejorMinimo << " IOPs\n";
    cout << "Distribución de tablas en discos:\n";

    paseBase(mejorIndice, M, cromosoma, N);
    for (int d = 0; d < M; d++) {
        cout << "Disco " << d+1 << ": ";
        for (int t = 0; t < N; t++) {
            if (cromosoma[t] == d) cout << (t+1) << " ";
        }
        cout << endl;
    }

    return 0;
}
