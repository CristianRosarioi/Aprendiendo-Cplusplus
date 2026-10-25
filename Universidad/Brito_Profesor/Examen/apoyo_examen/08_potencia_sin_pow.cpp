/*
Enunciado: Calcular base^exponente por multiplicaciones, sin pow.
Conceptos: double, int, while, *=, exponentes positivos, cero y negativos.
Algoritmo: 1) Leer base y exponente. 2) Rechazar 0 con exponente
negativo. 3) Para exponente positivo multiplicar tantas veces como indique;
para negativo multiplicar el recíproco esa cantidad de veces.
Ejemplo: entrada 2 -3 -> resultado 0.125; entrada 5 0 -> resultado 1.
Se suponen entradas numéricas y potencias dentro del rango de double.
*/
#include <iostream>
using namespace std;

int main() {
    double base; // Número que se repite como factor.
    int exponente; // Indica cuántas veces, y el signo indica si invertir.
    double potencia = 1.0; // Multiplicar por 1 no cambia nada; base^0 = 1.
    cout << "Base: ";
    cin >> base;
    cout << "Exponente entero: ";
    cin >> exponente;

    if (base == 0.0 && exponente < 0) {
        cout << "No existe: requeriria dividir entre cero." << endl;
        return 0;
    }
    if (exponente >= 0) {
        int pendientes = exponente; // Copia para conservar el dato original.
        while (pendientes > 0) {
            potencia *= base; // Equivale a potencia = potencia * base.
            pendientes--; // Restamos una multiplicación pendiente.
        } // Con exponente cero no entra: permanece en 1.
    } else {
        int pendientes = exponente; // Evitamos negar el mínimo valor de int.
        double inversa = 1.0 / base; // base no puede ser cero en esta rama.
        while (pendientes < 0) {
            potencia *= inversa; // Para -3, multiplica 1/base tres veces.
            pendientes++; // Se acerca a cero incluso para el mínimo int.
        }
    }
    cout << "Resultado: " << potencia << endl;
    return 0;
}
