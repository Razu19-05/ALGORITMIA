#include <iostream>
#include <cmath>
#include <cstring>
#define M 8

using namespace std;

void pasaBase(int num,int size,int cromosoma[M],int base) {
    for(int i=0;i<size;i++) cromosoma[i]=0;
    int i = 0;
    while (num!=0) {
        cromosoma[i++] = num%base;
        num = num/base;
    }
}


bool verify(char aux[M], int cant, char palabra1[],int longitud) {
    if (aux[0] == '\0')return false;
    if (cant != longitud) return false;

    char palabraAuxiliar[longitud];
    for (int i=0;i<longitud;i++) palabraAuxiliar[i] = palabra1[i];

    for(int i=0;i<longitud;i++) {
        char letra = aux[i];
        bool encontrada = false;
        //recorre el arreglo palabraAuxiliar y si una de las letras es igual a letra de aux ent lo pone espacio en esa pos
        for (int j=0;j<longitud;j++) {
            if (palabraAuxiliar[j] == letra) {
                palabraAuxiliar[j] = ' ';
                //pone la variable encontrada en true y rompe
                //si no lo encuentra ent se mantiene en false
                encontrada = true;
                break;
            }
        }
        if (!encontrada) return false;
    }
}

int main() {
    char matriz[M]={'G','A','L','A','O','G','L','M'};
    int cantPlabras=0, contador=0;
    cout<<"Ingrese la cant de palabras que desea buscar (max 8): ";
    cin>>cantPlabras;
    cout<<endl;
    if (cantPlabras==0)return 0;
    do {
        int cant;
        int combinaciones = pow(2,M);
        int cromosoma[M];
        char aux[M]{};
        cout<<"Cuantas letras desea ingresar para la palabra "<<contador+1<<"(max 10):";
        cin>>cant;
        cout<<endl;
        char palabra1[cant];
        for (int i=0;i<cant;i++) {
            cout<<"Ingrese la letra "<<i+1<<": ";
            cin>>palabra1[i];
        }
        for(int i=0;i<combinaciones;i++) {
            int t=0;
            pasaBase(i,M,cromosoma,2);
            for(int j=0;j<M;j++) {
                if (cromosoma[j]==1) {
                    aux[t] = matriz[j];
                    t++;
                }
            }
            if (!verify(aux,t,palabra1,cant))continue;
            for (int j=0;j<t;j++) cout<<aux[j]<<" ";
            cout<<endl;
        }
        contador++;
    }while (contador<cantPlabras);
}