/* Escriba un programa que lea dos números: double base y int
 exponente. El programa debe calcular la potencia de base elevado a
 exponente, considere además que el exponente puede ser negativo.
 Si exponente < 0; entonces potencia = 1 / base elevado al exponente positivo.
 La idea es no usar la función pow de la librería <cmath>, el objetivo es
 escribir un algoritmo que calcule la potencia. */

#include <iostream>
using namespace std;

int main () {
    double base;
    int exponente;

    cout << "Ingrese la base: ";
    cin >> base;
    cout << "Ingrese el exponente: ";
    cin >> exponente;

    if (base == 0 && exponente < 0) {
        cout << "No se puede dividir entre cero." << endl;
        return 0;
    }

    double potencia = 1;
    long long repeticiones = exponente;

    if (repeticiones < 0) {
        repeticiones = -repeticiones;
    }

    for (long long i = 0; i < repeticiones; i++) {
        potencia *= base;
    }

    if (exponente < 0) {
        potencia = 1 / potencia;
    }

    cout << "Resultado: " << potencia << endl;
    return 0;
}
