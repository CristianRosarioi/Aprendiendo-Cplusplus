/* Hacer un programa que calcule el promedio de los números múltiplos de
7 desde un entero numDesde leído por teclado hasta un entero
numHasta también leído por teclado. Debe validar que el primer entero
sea menor que el segundo. (use un ciclo while).*/

#include <iostream>
using namespace std;

int main () {
    int numDesde, numHasta;

    cout << "Ingrese el numero desde: ";
    cin >> numDesde;
    cout << "Ingrese el numero hasta: ";
    cin >> numHasta;

    while (numDesde >= numHasta) {
        cout << "El primer numero debe ser menor que el segundo." << endl;
        cout << "Ingrese el numero desde: ";
        cin >> numDesde;
        cout << "Ingrese el numero hasta: ";
        cin >> numHasta;
    }

    double suma = 0;
    long long cantidad = 0;
    long long numero = numDesde;

    while (numero <= numHasta) {
        if (numero % 7 == 0) {
            suma += numero;
            cantidad++;
        }
        numero++;
    }

    if (cantidad > 0) {
        cout << "Promedio: " << suma / cantidad << endl;
    } else {
        cout << "No hay multiplos de 7 en ese intervalo." << endl;
    }

    return 0;
}
