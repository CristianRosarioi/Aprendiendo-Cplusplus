#include <iostream>
#include <iomanip>
using namespace std;

// Prototipo
double calcularPromedio(double *notas, int cantidad);

int main() {

    int cantidad;
    double promedio;

    double *notas;

    cout << "Cuantos estudiantes desea registrar? ";
    cin >> cantidad;

    while (cantidad <= 0) {
        cout << "Cantidad invalida: ";
        cin >> cantidad;
    }

    // Crear arreglo dinamico
    notas = new double[cantidad];

    // Registrar las notas
    for (int i = 0; i < cantidad; i++) {

        cout << "Introduzca la nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    // Calcular el promedio con una funcion
    promedio = calcularPromedio(notas, cantidad);

    cout << fixed << setprecision(2);

    cout << "\nPromedio general: " << promedio << endl;

    // Liberar memoria
    delete[] notas;

    notas = nullptr;

    return 0;
}

// Funcion que calcula el promedio
double calcularPromedio(double *notas, int cantidad) {

    double suma = 0;

    for (int i = 0; i < cantidad; i++) {

        suma += notas[i];
    }

    return suma / cantidad;
}