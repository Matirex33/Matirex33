#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    char tablero[3][3]={{'V','V','V'},{'V','V','V'},{'V','V','V'}};
    int jugador1[3]={0,0,0};
    int jugador2[3]={0,0,0};
    int tam=3;
    bool ganar1=false;
    bool ganar2=false;
    partida(tablero,jugador1,jugador2,tam,ganar1,ganar2);
}