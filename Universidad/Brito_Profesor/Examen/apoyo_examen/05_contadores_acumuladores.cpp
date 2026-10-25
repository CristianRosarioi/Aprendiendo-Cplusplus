/*
Enunciado: Leer una cantidad de enteros, clasificarlos y sumar sus valores.
Conceptos: for, contadores, acumulador, if / else if / else.
Algoritmo: 1) Pedir cantidad positiva. 2) Por cada entero leído,
sumarlo y contar si es positivo, negativo o cero. 3) Mostrar totales.
Ejemplo: entrada cantidad 4 y valores 2 -3 0 5 -> positivos 2,
negativos 1, ceros 1, suma 4.
Se supone entrada entera y suma representable en int.
*/
#include <iostream>
using namespace std;

int main() {
    int cantidad; // Indica cuántas lecturas harán falta.
    int numero;   // Guarda el valor de la lectura actual.
    int positivos = 0; // Contadores comienzan en 0: aún no hay casos.
    int negativos = 0;
    int ceros = 0;
    int suma = 0; // Acumulador comienza en 0: elemento neutro de la suma.
    cout << "Cantidad positiva de numeros: ";
    cin >> cantidad;
    while (cantidad <= 0) {
        cout << "Debe ser positiva. Cantidad: ";
        cin >> cantidad;
    }

    // La lectura se repite exactamente cantidad veces.
    for (int posicion = 1; posicion <= cantidad; posicion++) {
        cout << "Numero " << posicion << ": ";
        cin >> numero;
        suma += numero; // Equivale a suma = suma + numero (valor variable).
        if (numero > 0) {
            positivos++; // ++ añade exactamente 1 a un contador.
        } else if (numero < 0) {
            negativos++;
        } else {
            ceros++; // Si no es positivo ni negativo, vale cero.
        }
    }
    cout << "Positivos: " << positivos << ", negativos: " << negativos
         << ", ceros: " << ceros << ", suma: " << suma << endl;
    return 0;
}
