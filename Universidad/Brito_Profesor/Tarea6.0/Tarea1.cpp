#include <iostream>
#include <iomanip>
using namespace std;

// Prototipos de las funciones
double *creaArreglo(int cantidad);
void leePuntuaciones(double *arreglo, int cantidad);
void ordena(double *arreglo, int cantidad);
double calculaPromedio(double *arreglo, int cantidad);

int main() {

    int cantidad;
    double *puntuaciones;
    double promedio;

    // Solicitar la cantidad de puntuaciones
    cout << "Cuantas puntuaciones desea introducir? ";
    cin >> cantidad;

    // Validar la cantidad
    while (cantidad <= 0) {
        cout << "Cantidad invalida. Introduzca otra: ";
        cin >> cantidad;
    }

    // Crear el arreglo dinamicamente
    puntuaciones = creaArreglo(cantidad);

    // Leer las puntuaciones
    leePuntuaciones(puntuaciones, cantidad);

    // Ordenar las puntuaciones
    ordena(puntuaciones, cantidad);

    // Calcular el promedio
    promedio = calculaPromedio(puntuaciones, cantidad);

    // Mostrar las puntuaciones ordenadas
    cout << "\nPUNTUACIONES ORDENADAS" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << puntuaciones[i] << endl;
    }

    // Mostrar el promedio
    cout << fixed << setprecision(2);

    cout << "\nPromedio de las puntuaciones: "
         << promedio << endl;

    // Liberar la memoria dinamica
    delete[] puntuaciones;

    puntuaciones = nullptr;

    return 0;
}


// Funcion que crea un arreglo dinamico
double *creaArreglo(int cantidad) {

    double *arreglo;

    arreglo = new double[cantidad];

    return arreglo;
}


// Funcion que lee las puntuaciones
void leePuntuaciones(double *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++) {

        cout << "Introduzca la puntuacion "
             << i + 1 << ": ";

        cin >> arreglo[i];
    }
}


// Funcion que ordena de forma ascendente
// Utiliza el metodo de la burbuja
void ordena(double *arreglo, int cantidad) {

    bool swap;
    double temp;

    do {

        swap = false;

        for (int i = 0; i < cantidad - 1; i++) {

            if (arreglo[i] > arreglo[i + 1]) {

                temp = arreglo[i];

                arreglo[i] = arreglo[i + 1];

                arreglo[i + 1] = temp;

                swap = true;
            }
        }

    } while (swap);
}


// Funcion que calcula el promedio
double calculaPromedio(double *arreglo, int cantidad) {

    double suma = 0;
    double promedio;

    for (int i = 0; i < cantidad; i++) {

        suma += arreglo[i];
    }

    promedio = suma / cantidad;

    return promedio;
}