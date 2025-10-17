#include <iostream>
#include <iomanip>
#include <cstring>
#define R 12
#define S 8
using namespace std;

void recorreHorizontal(char pupiletras[R][S]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            if (pupiletras[i][j] == 'C')
                if (pupiletras[i][j+1] == 'E')
                    if (pupiletras[i][j+2] == 'N') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i<<","<<j+2<<")"<<endl;
                    }
            if (pupiletras[i][j] == 'E')
                if (pupiletras[i][j+1] == 'C')
                    if (pupiletras[i][j+2] == 'N') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i<<","<<j+2<<")"<<endl;
                    }
            if (pupiletras[i][j] == 'N')
                if (pupiletras[i][j+1] == 'E')
                    if (pupiletras[i][j+2] == 'C') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i<<","<<j+2<<")"<<endl;
                    }
            if (pupiletras[i][j] == 'N')
                if (pupiletras[i][j+1] == 'C')
                    if (pupiletras[i][j+2] == 'E') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i<<","<<j+2<<")"<<endl;
                    }
        }
    }
}

void recorreVertical(char pupiletras[R][S]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            if (pupiletras[i][j] == 'C')
                if (pupiletras[i+1][j] == 'E')
                    if (pupiletras[i+2][j] == 'N') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i+2<<","<<j<<")"<<endl;
                    }
            if (pupiletras[i][j] == 'E')
                if (pupiletras[i+1][j] == 'C')
                    if (pupiletras[i+2][j] == 'N') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i+2<<","<<j<<")"<<endl;
                    }
            if (pupiletras[i][j] == 'N')
                if (pupiletras[i+1][j] == 'E')
                    if (pupiletras[i+2][j] == 'C') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i+2<<","<<j<<")"<<endl;
                    }
            if (pupiletras[i][j] == 'N')
                if (pupiletras[i+1][j] == 'C')
                    if (pupiletras[i+2][j] == 'E') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i+2<<","<<j<<")"<<endl;
                    }
        }
    }
}

void recorreDiagonalDercho(char pupiletras[R][S]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            if (pupiletras[i][j] == 'C')
                if (pupiletras[i+1][j+1] == 'E')
                    if (pupiletras[i+2][j+2] == 'N') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i+2<<","<<j+2<<")"<<endl;
                    }
            if (pupiletras[i][j] == 'E')
                if (pupiletras[i+1][j+1] == 'C')
                    if (pupiletras[i+2][j+2] == 'N') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i+2<<","<<j+2<<")"<<endl;
                    }
            if (pupiletras[i][j] == 'N')
                if (pupiletras[i+1][j+1] == 'E')
                    if (pupiletras[i+2][j+2] == 'C') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i+2<<","<<j+2<<")"<<endl;
                    }
            if (pupiletras[i][j] == 'N')
                if (pupiletras[i+1][j+1] == 'C')
                    if (pupiletras[i+2][j+2] == 'E') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i+2<<","<<j+2<<")"<<endl;
                    }
        }
    }
}

void recorreDiagonalIzquierdo(char pupiletras[R][S]) {
    for (int i = R - 1; i >= 0; i--) {
        for (int j = 0; j < S; j++) {
            if (pupiletras[i][j] == 'C')
                if (pupiletras[i-1][j+1] == 'E')
                    if (pupiletras[i-2][j+2] == 'N') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i-2<<","<<j+2<<")"<<endl;
                    }
            if (pupiletras[i][j] == 'E')
                if (pupiletras[i-1][j+1] == 'C')
                    if (pupiletras[i-2][j+2] == 'N') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i-2<<","<<j+2<<")"<<endl;
                    }
            if (pupiletras[i][j] == 'N')
                if (pupiletras[i-1][j+1] == 'E')
                    if (pupiletras[i-2][j+2] == 'C') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i-2<<","<<j+2<<")"<<endl;
                    }
            if (pupiletras[i][j] == 'N')
                if (pupiletras[i-1][j+1] == 'C')
                    if (pupiletras[i-2][j+2] == 'E') {
                        cout << "("<<i<<","<<j<<")"<<endl;
                        cout << "("<<i-2<<","<<j+2<<")"<<endl;
                    }
        }
    }
}

int main() {
    char pupiletras[R][S] = {
        {'C','E','N','Z','Y','X','A','U'},
        {'D','Y','X','A','B','A','Y','U'},
        {'A','Z','Y','A','X','B','C','U'},
        {'B','Z','Z','A','E','E','Y','A'},
        {'Y','Y','B','X','N','C','Z','Y'},
        {'U','U','Y','Y','B','N','C','Z'},
        {'Z','Y','A','A','U','Y','Y','E'},
        {'Y','U','E','D','Z','B','B','N'},
        {'Z','C','B','X','U','B','A','Z'},
        {'N','Z','B','C','Y','Y','A','Y'},
        {'X','A','E','Z','Z','A','U','Z'},
        {'A','C','Z','X','X','Y','Y','Z'}
    };
    recorreHorizontal(pupiletras);
    recorreVertical(pupiletras);
    recorreDiagonalDercho(pupiletras);
    recorreDiagonalIzquierdo(pupiletras);
    return 0;
}