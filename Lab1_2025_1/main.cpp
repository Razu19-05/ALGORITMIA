
#include <iostream>
#include <cmath>
using namespace std;

#define N 6   // Número de tablas
#define M 3   // Número de discos

#define A 10 // Número de filas
#define B 2  // Número de columnas
#define C 4  // Número de ya

bool verify(int recurso[]) ;
int sumaDependientes(int dependecia[],int costoSeguridad[A][B]) ;
bool verifySales(int cromosoma2[A],double montoMax,double montoMin,double &sumaTotal,int costoSeguridad[A][B]) ;
bool verify(int cromosoma2[A],int dependencia[A][C],double &sumaTotal,int costoSeguridad[A][B]);

// Convierte numero en base M y lo guarda en arreglo asignacion
void paseBase(int numero, int base, int cromosoma[N], int size) {
    for (int i = 0; i < size; i++) cromosoma[i] = 0;//cromosomas en 0
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
    int totalCombinaciones = pow(M+1, N);

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

        // Calculamos el mínimo disco
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


    //PREGUNTA N°2
    int costoSeguridad[A][B] = {
        {50, 120},
        {40, 110},
        {80, 140},
        {70, 130},
        {85, 160},
        {140, 250},
        {55, 100},
        {130, 240},
        {30, 90},
        {150, 300}
    };
    int dependencia[A][C] = {
        // Recurso, Impl1, Impl2, Impl3
        {0, 0, 0, 0},      // Firewall
        {0, 0, 0, 0},      // IDS
        {0, 0, 0, 0},      // Monitoreo de Red
        {1, 0, 0, 0},      // Sistema de Autenticación -> Firewall
        {1, 0, 0, 0},      // IPS -> Firewall
        {1, 2, 0, 0},      // IDS Avanzado -> Firewall, IDS
        {2, 0, 0, 0},      // Honeypot -> IDS
        {2, 3, 0, 0},      // Detección de Intrusos -> IDS, Monitoreo
        {0, 0, 0, 0},      // Seguridad de Correo
        {1, 2, 5, 0}       // Gestión Centralizada -> Firewall, IDS, IPS
    };
    int combinaciones = pow(2,A);
    double montoMax = 80;
    double montoMin = montoMax * 0.8;
    double sumaTotalPrecio;
    double sumaTotalDependicia;
    int cromosoma2[A];
    for (int i = 0; i < combinaciones; i++) {
        paseBase(i, 2, cromosoma2, A);
        if (!verifySales(cromosoma2,montoMax,montoMin,sumaTotalPrecio,costoSeguridad)) continue;
        if (!verify(cromosoma2,dependencia,sumaTotalDependicia,costoSeguridad))continue;
        cout<<i<<"  ";
        for (int t = 0; t < N; t++) {
            cout<<cromosoma2[t]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
bool verifySales(int cromosoma2[A],double montoMax,double montoMin,double &sumaTotal,int costoSeguridad[A][B]) {
    sumaTotal = 0;
    for (int i = 0; i < A; i++) {
        if (cromosoma2[i] == 1) {
            sumaTotal += costoSeguridad[i][0];
        }
    }
    if (sumaTotal >= montoMin && sumaTotal <= montoMax) return true;
    return false;
}

bool verify(int cromosoma2[A],int dependencia[A][C],double &sumaTotal,int costoSeguridad[A][B]){
    sumaTotal = 0;
    for (int i = 0; i < A; i++) {
        if (cromosoma2[i] == 1) {
            for (int t= 0; t < C; t++) {
                if (dependencia[i][t] == 0) break;
                if (cromosoma2[dependencia[i][t]-1] == 1) continue;
                else return false;
            }
            sumaTotal += costoSeguridad[i][1];
        }
    }
    return true;
}

int sumaDependientes(int dependecia[],int costoSeguridad[A][B]) {
    int sumaParcial= 0;
    for (int i = 1; i < C; i++) {
        if (dependecia[i] != 0) {
            int num = dependecia[i];
            sumaParcial += costoSeguridad[num-1][0];
        }
    }
    return sumaParcial;
}