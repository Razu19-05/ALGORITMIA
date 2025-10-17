#include <iostream>
#include <iomanip>
#include <cstring>
#define N 9
#define M 9
using namespace std;

int buscarLetras(char matriz[N][M],int x,int y,char letra,int limiteX,int limiteY,char dirc, bool borrar) {
    int contador = 0;
    if (x>=limiteX || y>=limiteY || x < 0 || y < 0) return 0;
    //derecha
    if (dirc == 'D') {
        if (matriz[x][y] == letra and !borrar) contador++;
        if (matriz[x][y] == letra and borrar) matriz[x][y] = '.';
        return contador + buscarLetras(matriz,x,y+1,letra,limiteX,limiteY,dirc,borrar);
    }
    //izquierda
    if (dirc == 'A') {
        if (matriz[x][y] == letra and !borrar) contador++;
        if (matriz[x][y] == letra and borrar) matriz[x][y] = '.';
        return contador + buscarLetras(matriz,x,y-1,letra,limiteX,limiteY,dirc,borrar);
    }
    //arriba
    if (dirc == 'W') {
        if (matriz[x][y] == letra and !borrar) contador++;
        if (matriz[x][y] == letra and borrar) matriz[x][y] = '.';
        return contador + buscarLetras(matriz,x-1,y,letra,limiteX,limiteY,dirc,borrar);
    }
    //abajo
    if (dirc == 'S') {
        if (matriz[x][y] == letra and !borrar) contador++;
        if (matriz[x][y] == letra and borrar) matriz[x][y] = '.';
        return contador + buscarLetras(matriz,x+1,y,letra,limiteX,limiteY,dirc,borrar);
    }
    //diagonal dercho arriba
    if (dirc == 'E') {
        if (matriz[x][y] == letra and !borrar) contador++;
        if (matriz[x][y] == letra and borrar) matriz[x][y] = '.';
        return contador + buscarLetras(matriz,x-1,y+1,letra,limiteX,limiteY,dirc, borrar);
    }
    //diagonal izquierda arriba
    if (dirc == 'Q') {
        if (matriz[x][y] == letra and !borrar) contador++;
        if (matriz[x][y] == letra and borrar) matriz[x][y] = '.';
        return contador + buscarLetras(matriz,x-1,y-1,letra,limiteX,limiteY,dirc, borrar);
    }
    //diagonal dercho abajo
    if (dirc == 'X') {
        if (matriz[x][y] == letra and !borrar) contador++;
        if (matriz[x][y] == letra and borrar) matriz[x][y] = '.';
        return contador + buscarLetras(matriz,x+1,y+1,letra,limiteX,limiteY,dirc, borrar);
    }
    //diagonal izquierda abajo
    if (dirc == 'Z') {
        if (matriz[x][y] == letra and !borrar) contador++;
        if (matriz[x][y] == letra and borrar) matriz[x][y] = '.';
        return contador + buscarLetras(matriz,x+1,y-1,letra,limiteX,limiteY,dirc, borrar);
    }
    return contador;
}

int main() {
    char matriz[N][M] = {
        {'.','.','.','.','.','.','.','.','.'},
        {'.','A','.','.','.','B','.','.','.'},
        {'.','.','V','A','.','.','.','.','.'},
        {'.','B','.','D','.','V','B','A','.'},
        {'.','.','B','B','.','.','.','.','.'},
        {'.','A','.','B','.','.','.','.','.'},
        {'.','.','.','.','.','B','A','.','.'},
        {'.','.','.','V','.','.','.','.','.'},
        {'.','.','.','B','.','.','.','.','A'}
    };
    int posX = 3, posY = 3;
    char letraBuscar = 'B',movimientos[8]{'W','S','A','D','E','Q','X','Z'};
    int esMayor = -1, pos;
    int cantidades[8]{};
    bool borrar = false;
    cantidades[0] = buscarLetras(matriz,posX,posY,letraBuscar,N,M,movimientos[0],borrar);
    cantidades[1] = buscarLetras(matriz,posX,posY,letraBuscar,N,M,movimientos[1],borrar);
    cantidades[2] = buscarLetras(matriz,posX,posY,letraBuscar,N,M,movimientos[2],borrar);
    cantidades[3] = buscarLetras(matriz,posX,posY,letraBuscar,N,M,movimientos[3],borrar);
    cantidades[4] = buscarLetras(matriz,posX,posY,letraBuscar,N,M,movimientos[4],borrar);
    cantidades[5] = buscarLetras(matriz,posX,posY,letraBuscar,N,M,movimientos[5],borrar);
    cantidades[6] = buscarLetras(matriz,posX,posY,letraBuscar,N,M,movimientos[6],borrar);
    cantidades[7] = buscarLetras(matriz,posX,posY,letraBuscar,N,M,movimientos[7],borrar);
    for (int i = 0; i < 8; i++) {
        if (cantidades[i] > esMayor) {
            esMayor = cantidades[i];
            pos = i;
        }
    }
    borrar = true;
    buscarLetras(matriz,posX,posY,letraBuscar,N,M,movimientos[pos],borrar);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}