#include "Colas/funcionesCola.h"
#include "Colas/Cola.h"
#include "Colas/ElementoCola.h"
#include <iostream>
#define MAX_DATOS 6

using namespace std;

void ordenarColaIterativo(Cola &cola,int longitud) {
    ElementoCola aux, menor;
    int k = 0;
    for (int i = 1; i <= longitud; i++) {
        menor = desencolar(cola);//menor de inicio
        for (int j = 1; j < longitud - i + 1; j++) {
            aux = desencolar(cola);
            if (aux.codigo<menor.codigo) {
                encolar(cola,menor);//encolo el mayor
                menor = aux;//actualizo el menor
            }else
                encolar(cola,aux);
        }
        for (int m = 0; m < k; m++) {
            aux = desencolar(cola);
            encolar(cola,aux);
        }
        k++;//esto debe aumentar
        //Encolo el menor encontrado
        encolar(cola, menor);
    }
}

void ordenarColaRecursivo(Cola &cola, int longitud) {
    ElementoCola aux, mayor;
    if (esColaVacia(cola)) return;
    mayor = desencolar(cola);
    int m = longitud;
    while (m > 0 and !(esColaVacia(cola))) {
        aux = desencolar(cola);
        if (mayor.codigo > aux.codigo)
            encolar(cola, aux); //encolo el menor
        else {
            encolar(cola, mayor); // encolo el mayor anterior
            mayor = aux;  // actualizo el nuevo mayor
        }
        m--;
    }
    ordenarColaRecursivo(cola, longitud - 1);
    encolar(cola, mayor);
}

void encolarConPrioridad(struct Cola & cola, const struct ElementoCola & paciente) {
    NodoCola * nuevo;
    nuevo = new NodoCola{};
    nuevo->elemento = paciente;
    if(esColaVacia(cola)) { //cola está vacía
        cola.inicio = nuevo;
        cola.fin = nuevo;
        if (paciente.codigo == 1) //criterio de pregunta; alta prioridad
            cola.colaVIP = nuevo;
    }
    else { // ya tenemos un paciente o más de uno en cola
        if (paciente.codigo == 1) { // el que llega
            if (cola.colaVIP != nullptr) { //Tengo clientes VIP en cola
                nuevo->siguiente = cola.colaVIP->siguiente;
                cola.colaVIP->siguiente = nuevo;
                cola.colaVIP = nuevo;
                if (cola.colaVIP->siguiente == nullptr)
                    cola.fin = nuevo; //actualiza el fin de la cola
            }
            else { //No tengo clientes VIP en cola
                nuevo->siguiente = cola.inicio;
                cola.inicio = nuevo;
                cola.colaVIP = nuevo;
            }
        }
        else { //tengo uno de prioridad 2 en cola
            cola.fin->siguiente = nuevo;
            cola.fin = nuevo;
        }
    }
    cola.longit++;
}

int main() {
    Cola cola;
    ElementoCola elemento;
    construir(cola);
    cout << "La cola esta vacia: " << esColaVacia(cola) << endl;
    /*Encolamos elementos en la Cola*/
    for (int i = 4; i < 20; i+= 3) {
        elemento.codigo = i;
        encolar(cola, elemento);
    }

    imprimir(cola);

    while(!esColaVacia(cola)){
        elemento = desencolar(cola);
        cout<<"Desencolando: "<<elemento.codigo <<endl;
    }
    imprimir(cola);
    construir(cola);

    cout << "La cola esta vacia: " << esColaVacia(cola) << endl;
    /*Encolamos elementos en la Cola*/
    for (int i = 20; i > 3; i-= 3) {
        elemento.codigo = i;
        encolar(cola, elemento);
    }

    imprimir(cola);

    int n  = longitud(cola);

    // ordenarColaIterativo(cola, n);
    // cout << "ordena iterativo" << endl;
    // imprimir(cola);

    // cout<< endl;
    ordenarColaRecursivo(cola, n);
    cout << "ordena recursivo" << endl;
    imprimir(cola);
    construir(cola);
    ElementoCola pacientes [MAX_DATOS] = {
        {30,05,1943, 2,"BXQ778"},
        {20,04,2014, 2,"HRP112"},
        {26,06,1975, 2,"PRL625"},
        {22,10,1949, 1,"MKP157"},
        {13,05,2020, 1,"ARH749"},
        {14,02,1930, 1,"HRQ931"},
    };
    // Salida esperada
    // [1 MKP157, 1 ARH749, 1 HRQ9312, 2 BXQ778, 2 HRP112, 2 PRL625]
    for (int i = 0; i < MAX_DATOS; i++) {
        encolarConPrioridad(cola, pacientes[i]);
    }

    imprimir(cola);

    return 0;
}