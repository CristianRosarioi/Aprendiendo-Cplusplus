/*
Enunciado: Mostrar la tabla de multiplicar del 1 al 10.
Algoritmo: obtener el numero y recorrer factores desde 1 hasta 10 con for.
Ejemplo: entrada 3 -> primera fila 3 x 1 = 3
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
using namespace std;

int main() {
    int numero; // Numero elegido al ejecutar.
    cout << "Numero: "; cin >> numero;
    // Inicio 1; <= incluye 10; ++ aumenta el factor en uno.
    for (int factor = 1; factor <= 10; factor++) {
        cout << numero << " x " << factor << " = " << numero * factor << endl;
    }
    return 0;
}
