/*
Enunciado: Calcular cantidad de multiplos de 5 en un intervalo.
Algoritmo: leer/definir extremos; recorrer con while; filtrar, contar y sumar; si se promedia, comprobar cantidad antes de dividir.
Ejemplo: inicio 22, final 234 -> Cantidad: 42
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables.
*/
#include <iostream>
using namespace std;

int main() {
    int inicio; // Primer extremo del intervalo.
    int final;  // Ultimo extremo del intervalo.
    inicio = 22; // Extremo fijo elegido al generar.
    final = 234;
    // Al ser fijos se verifico al generar que inicio < final.
    int divisor = 5; // Divisor no nulo elegido al generar.
    int cantidad = 0; // Contador: inicia en cero.
    // Se prueba cada entero; las comparaciones de bordes deciden inclusion.
    int actual = inicio; // Valor en examen; avanzara uno a uno.
    while (actual <= final) {
        // % devuelve el residuo; == comprueba igualdad, = asigna.
        if (actual % divisor == 0) {
            cantidad++; // Suma una coincidencia al contador.
        }
        // Sin este corte, incrementar final cuando vale INT_MAX desbordaria.
        if (actual == final) { break; }
        actual++; // Garantiza progreso hacia el final.
    }
    cout << "Cantidad: " << cantidad << endl;
    return 0;
}
