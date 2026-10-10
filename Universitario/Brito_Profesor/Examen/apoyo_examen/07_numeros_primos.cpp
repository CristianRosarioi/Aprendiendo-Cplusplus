/*
Enunciado: Mostrar todos los números primos desde 30 hasta 300.
Conceptos: ciclos for anidados, %, divisibilidad, contador de divisores.
Algoritmo: 1) Probar cada número del intervalo. 2) Contar divisores
desde 1 hasta ese número. 3) Mostrarlo si tiene exactamente dos.
Ejemplo: el comienzo de la salida es 31 37 41 43 47 ...
Se usa el método elemental, fácil de comprobar a mano.
*/
#include <iostream>
using namespace std;

int main() {
    for (int numero = 30; numero <= 300; numero++) {
        int divisores = 0; // Se reinicia para cada nuevo candidato.
        for (int posible = 1; posible <= numero; posible++) {
            // % devuelve el residuo; == 0 comprueba división exacta.
            if (numero % posible == 0) {
                divisores++; // Cada divisor exacto aumenta el conteo.
            }
        } // Después de examinar el propio número, ya están todos.
        if (divisores == 2) { // 1 y el propio número: definición de primo.
            cout << numero << " ";
        }
    } // El último candidato es 300; después termina el for.
    cout << endl;
    return 0;
}
