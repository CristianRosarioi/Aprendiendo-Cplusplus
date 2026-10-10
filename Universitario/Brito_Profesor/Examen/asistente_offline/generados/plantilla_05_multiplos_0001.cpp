/*
Enunciado: Calcular promedio de multiplos de 7 en un intervalo.
Algoritmo: leer/definir extremos; recorrer con while; filtrar, contar y sumar; si se promedia, comprobar cantidad antes de dividir.
Ejemplo: inicio 1, final 20 -> Promedio: 10.5
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
using namespace std;

int main() {
    int inicio; // Primer extremo del intervalo.
    int final;  // Ultimo extremo del intervalo.
    cout << "Inicio y final: ";
    cin >> inicio >> final;
    // Se repite mientras inicio >= final: la igualdad tambien es invalida.
    while (inicio >= final) {
        cout << "Intervalo invalido. Inicio y final otra vez: ";
        cin >> inicio >> final;
    }
    int divisor = 7; // Divisor no nulo elegido al generar.
    int suma = 0; // Acumulador: inicia en cero.
    int cantidad = 0; // Contador: inicia en cero.
    // Se prueba cada entero; las comparaciones de bordes deciden inclusion.
    int actual = inicio; // Valor en examen; avanzara uno a uno.
    while (actual <= final) {
        // % devuelve el residuo; == comprueba igualdad, = asigna.
        if ((true) && actual % divisor == 0) {
            suma += actual; // Suma el valor seleccionado.
            cantidad++; // Suma una coincidencia al contador.
        }
        // Sin este corte, incrementar final cuando vale INT_MAX desbordaria.
        if (actual == final) { break; }
        actual++; // Garantiza progreso hacia el final.
    }
    if (cantidad == 0) {
        cout << "No hay elementos; no existe promedio." << endl;
    } else {
        // Convertir ANTES de dividir conserva la parte decimal.
        double promedio = static_cast<double>(suma) / cantidad;
        cout << "Promedio: " << promedio << endl;
    }
    return 0;
}
