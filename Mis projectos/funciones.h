#ifndef MATIREX33_FUNCIONES_H
#define MATIREX33_FUNCIONES_H
#include <iostream>
using namespace std;

/**
 * @brief función que lleva la partida y llama a las demas funciones
 * @param tablero
 * @param jugador1
 * @param jugador2
 * @param tam
 * @param ganar1
 * @param ganar2
 */
void partida(char tablero[][3],int jugador1[],int jugador2[], int const tam,bool ganar1,bool ganar2);

/**
 * @brief posiciones del jugador 1 en el tablero
 * @param jugador1
 * @param tam
 * @param tablero
 */
void posiciones1(char tablero[][3],int jugador1[], int const tam);


/**
 * @brief posiciones del jugador 2 en el tablero
 * @param jugador2
 * @param tam
 * @param tablero
 */
void posiciones2(char tablero[][3],int jugador2[],int const tam);


/**
 * @brief  esta funcion muestra el contenido del tablero
 * @param tablero
 * @param tam
 */
void mostrar(char const tablero[][3],int const tam);

/**
 * @brief comprueba si la partida ha acabado
 * @param v
 * @param tam
 * @return si uno de los dos jugadores ha ganado returnea true si no returnea false
 */
bool comprobar(int const v[],int const tam);


/**
 * @brief vacia la matriz del tablero
 * @param tablero
 * @param tam
 */
void reiniciar(char tablero[][3],int const tam);

#endif //MATIREX33_FUNCIONES_H