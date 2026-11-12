
#include <iostream>
using namespace std;

// Prototipos de las funciones
void leerNumeros(int *arreglo, int cantidad);
int *invertirArreglo(int *arreglo, int cantidad);
void mostrarArreglo(int *arreglo, int cantidad);

int main() {

    int cantidad;

    int *numeros;
    int *invertido;

    // Solicitar la cantidad de numeros
    cout << "Cuantos numeros desea introducir? ";
    cin >> cantidad;

    // Validar la cantidad
    while (cantidad <= 0) {
        cout << "Cantidad invalida. Introduzca otra: ";
        cin >> cantidad;
    }

    // Crear el arreglo original dinamicamente
    numeros = new int[cantidad];

    // Registrar los numeros
    leerNumeros(numeros, cantidad);

    // Crear la copia invertida
    invertido = invertirArreglo(numeros, cantidad);

    // Mostrar el arreglo original
    cout << "\nARREGLO ORIGINAL" << endl;

    mostrarArreglo(numeros, cantidad);

    // Mostrar el arreglo invertido
    cout << "\nARREGLO INVERTIDO" << endl;

    mostrarArreglo(invertido, cantidad);

    // Liberar la memoria dinamica
    delete[] numeros;
    delete[] invertido;

    numeros = nullptr;
    invertido = nullptr;

    return 0;
}


// Funcion para registrar los numeros
void leerNumeros(int *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++) {

        cout << "Introduzca el numero " << i + 1 << ": ";

        cin >> arreglo[i];
    }
}


// Funcion que crea una copia invertida del arreglo
int *invertirArreglo(int *arreglo, int cantidad) {

    // Crear un nuevo arreglo dinamico
    int *nuevo = new int[cantidad];

    // Copiar los elementos en orden inverso
    for (int i = 0; i < cantidad; i++) {

        nuevo[i] = arreglo[cantidad - 1 - i];
    }

    // Devolver el puntero al nuevo arreglo
    return nuevo;
}


// Funcion para mostrar los elementos del arreglo
void mostrarArreglo(int *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++) {

        cout << arreglo[i] << " ";
    }

    cout << endl;
}

