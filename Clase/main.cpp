#include <iostream>
#include <cmath>

using namespace std;
void buscaOro(int matriz[6][7],int x,int y,int n,int m,int c,char dir) {
    if (x>n-1 or y>m-1) {
        return;
    }
    if (c<0) {
        return;
    }

    if (matriz[x][y]==2) {
        if (dir=='D') {
            dir='I';
            y--;
            c--;
        }
    }

        if (dir=='D'){
            //izquierda
            for (int i=y;i>=0;i--) {
                if (matriz[x][i]==1) {
                    cout<<"("<<x<<","<<i<<")"<<endl;
                    matriz[x][i]=0;
                    break;
                }
            }

            //arriba
            for (int i=x;i>=0;i--) {
                if (matriz[i][y]==1) {
                    cout<<"("<<i<<","<<y<<")"<<endl;
                    break;
                }
            }

            //abajo
            for (int i=x;i<n;i++) {
                if (matriz[i][y]==1) {
                    cout<<"("<<i<<","<<y<<")"<<endl;
                    break;
                }
            }
            buscaOro(matriz,x,y+1,n,m,c-1,dir);
        }
        else if (dir=='I') {
            //derecha
            for (int i=y;i<m;i++) {
                if (matriz[x][i]==1) {
                    cout<<"("<<x<<","<<i<<")"<<endl;
                    matriz[x][i]=0;
                    break;
                }
            }

            //arriba
            for (int i=x;i>=0;i--) {
                if (matriz[i][y]==1) {
                    cout<<"("<<i<<","<<y<<")"<<endl;
                    break;
                }
            }

            //abajo
            for (int i=x;i<n;i++) {
                if (matriz[i][y]==1) {
                    cout<<"("<<i<<","<<y<<")"<<endl;
                    break;
                }
            }
            buscaOro(matriz,x,y-1,n,m,c-1,dir);
        }

}
int main() {
    int matriz[6][7]={
        {0,1,1,1,1,1,1},
        {0,1,1,0,0,0,0},
        {0,1,0,0,0,0,0},
        {1,0,0,0,2,0,0},
        {1,1,0,0,0,0,0},
        {1,1,0,1,1,0,0}
    };
    int n,m,c,x,y;
    n=6;
    m=7;
    x=3;
    y=2;
    c=6;
    char dir;
    dir='D';
    buscaOro(matriz,x,y,n,m,c,dir);


    return 0;
}