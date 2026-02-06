#include "funciones.h"

using namespace std;

void posiciones1(char tablero[][3], int jugador1[], int tam) {
    int h, k;
    for (int i = 0; i < tam; i++) {
        if (jugador1[i] != 0) {
            h = (jugador1[i] / 10);
            k = (jugador1[i] - h * 10) - 1;
            h--;
            tablero[h][k] = 'X';
        }
    }
}

void posiciones2(char tablero[][3], int jugador2[], int tam) {
    int h, k;
    for (int i = 0; i < tam; i++) {
        if (jugador2[i] != 0) {
            h = (jugador2[i] / 10);
            k = (jugador2[i] - h * 10) - 1;
            h--;
            tablero[h][k] = 'O';
        }
    }
}

void reiniciar(char tablero[][3], int const tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            tablero[i][j] = ' ';
        }
    }
}

bool comprobar(int const v[], int const tam) {
    int tablero[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int h, k;
    for (int i = 0; i < tam; i++) {
        if (v[i] != 0) {
            h = (v[i] / 10);
            k = (v[i] - h * 10) - 1;
            h--;
            tablero[h][k] = 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] + tablero[i][1] + tablero[i][2] == 3) return true;
        if (tablero[0][i] + tablero[1][i] + tablero[2][i] == 3) return true;
    }
    if (tablero[0][0] + tablero[1][1] + tablero[2][2] == 3) return true;
    if (tablero[0][2] + tablero[1][1] + tablero[2][0] == 3) return true;

    return false;
}