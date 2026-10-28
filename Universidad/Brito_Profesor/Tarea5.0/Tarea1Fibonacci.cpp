/*
Universidad Autónoma de Santo Domingo UASD
Centro UASD San Pedro, Escuela de informatica 5100-29
Introduccion a la Programacion
Cristian Rosario
Matricula: 100806653
*/

// Sucesion de Fibonacci


#include <iostream>
using namespace std;

// Prototipo de la funcion
long fibonacci(long);

int main() {
    long terminoBuscado;
    long cantidad;

    cout << "Ingrese el termino de Fibonacci: ";
    cin >> terminoBuscado;

    // Validar que el termino sea positivo
    while (terminoBuscado <= 0) {
        cout << "El termino debe ser mayor que cero: ";
        cin >> terminoBuscado;
    }

    // Llamar la funcion y guardar el resultado
    cantidad = fibonacci(terminoBuscado);

    cout << "Cantidad: " << cantidad << endl;

    return 0;
}

// Definicion de la funcion fibonacci
long fibonacci(long n) {
    long anterior = 0;
    long actual = 1;
    long siguiente;

    if (n == 1) {
        return anterior;
    }

    if (n == 2) {
        return actual;
    }

    for (long i = 3; i <= n; i++) {
        siguiente = anterior + actual;
        anterior = actual;
        actual = siguiente;
    }

    return actual;
}
