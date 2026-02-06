#include "funciones.h"
//operaciones calculadora

int suma(int n, int n1) {
    int resultado;
    resultado=n+n1;
    return resultado;
}

int resta(int n, int n1) {
    int resultado;
    resultado=n-n1;
    return resultado;
}

int multiplicacion(int n,int n1) {
    int resultado;
    resultado=n*n1;
    return resultado;
}

int division(int n, int n1) {
    int resultado;
    resultado=n/n1;
    return resultado;
}

int potencia(int n, int n1) {
    int resultado=1;
    for (int i=0;i<n1;i++) {
        resultado*=n;
    }
    return resultado;
}