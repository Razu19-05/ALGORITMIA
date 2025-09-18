#include  <iostream>
#include  <cmath>
#define N 6
#define M 6


using namespace std;

int buscarUnos(int posX,int posY,int limiteX,int limiteY,int maxFila,int maxColumna, int nivel, int tablero[N][M]) {
    if (posX < 0 or posY < 0 or limiteX >= maxFila or limiteY >= maxColumna) return 0;

    int contador = 0;
    if (tablero[posX][posY] == 1) contador++;
    for (int i = posY + 1 ; i <= limiteY; i++) if (tablero[posX][i]==1) contador++;
    for (int i = posX + 1; i <= limiteX; i++) if (tablero[i][limiteY] == 1) contador++;
    for (int i = limiteY - 1; i >= posY; i--) if (tablero[limiteX][i] == 1) contador++;
    for (int i = limiteX - 1; i > posX; i--) if (tablero[i][posY] == 1) contador++;

    return contador + buscarUnos(posX-1,posY-1,limiteX+1,limiteY+1,maxFila,maxColumna,nivel + 1,tablero);
}

int main () {
    int tablero[N][M] {
        {0,0,0,1,0,1},
        {0,0,1,0,0,0},
        {0,1,0,0,0,0},
        {1,0,0,0,0,0},
        {0,1,0,0,1,0},
        {0,0,0,0,1,0}
    };
    int posX = 4, posY = 4, limiteX = posX, limiteY = posY;
    int nivel = 1;
    int contador = buscarUnos(posX,posY,limiteX,limiteY,N,M,nivel,tablero);
    cout<<contador<<endl;
    return 0;

}