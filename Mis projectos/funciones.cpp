#include "funciones.h"


void posiciones1(char tablero[][3],int jugador1[],int tam) {
    int h,k;
    for (int i=0;i<tam;i++) {
        h=(jugador1[i]/10);
        k=(jugador1[i]-h*10)-1;
        h--;
        if (jugador1[i]!=0) {
            tablero[h][k]='X';
        }
    }
}

void posiciones2(char tablero[][3],int jugador2[],int tam) {
    int h,k;
    for (int i=0;i<tam;i++) {
        h=(jugador2[i]/10);
        k=(jugador2[i]-h*10)-1;
        h--;
        if (jugador2[i]!=0) {
            tablero[h][k]='O';
        }
    }
}

bool comprobar(int const v[],int const tam) {
    int sumai=0;
    int sumaj=0;
    int sumad=0;
    bool cierto=false;
    int tablero[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    int h,k;
    for (int i=0;i<tam;i++) {
        h=(v[i]/10);
        k=(v[i]-h*10)-1;
        h--;
        tablero[h][k]=1;
    }
    for (int i=0;i<tam;i++) {
        sumai=0;
        sumaj=0;
        for (int j=0;j<tam;j++) {
            sumai+=tablero[i][j];
            sumaj+=tablero[j][i];
            if (sumai==3||sumaj==3) {
                cierto=true;
            }
        }
    }
    return cierto;
}

void partida(char tablero[][3],int jugador1[],int jugador2[], int const tam,bool ganar1,bool ganar2) {
    int h=0,k=0;
    cout<<"Jugador 1 empieza: ";
    cin>>jugador1[h];
    h++;
    posiciones1(tablero,jugador1,tam);
    mostrar(tablero,tam);
    while (!ganar1&&!ganar2) {
        if (h==3) {
            h=0;
            posiciones1(tablero,jugador1,tam);
            mostrar(tablero,tam);
        }
        if (k==3) {
            k=0;
            posiciones2(tablero,jugador2,tam);
            mostrar(tablero,tam);
        }
        cout<<"Jugador 2 sigue: ";
        cin>>jugador2[k];
        k++;
        posiciones2(tablero,jugador2,tam);
        mostrar(tablero,tam);
        cout<<"Jugador 1 sigue; ";
        cin>>jugador1[h];
        h++;
        posiciones1(tablero,jugador1,tam);
        mostrar(tablero,tam);
        ganar1=comprobar(jugador1,tam);
        ganar2=comprobar(jugador2,tam);
    }
    if (ganar1) {
        cout<<"El jugador 1 ha ganado"<<endl;
    }
    if (ganar2) {
        cout<<"El jugador 2 ha ganado"<<endl;
    }
}


void mostrar(char const tablero[][3],int const tam) {
    cout<<endl;
    for (int i=0;i<tam;i++) {
        for (int j=0;j<tam;j++) {
            cout<<tablero[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}