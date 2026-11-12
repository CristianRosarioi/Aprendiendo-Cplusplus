
#include <iostream>
using namespace std;

// Prototipos de las funciones
int *redimensionarArreglo(int *arreglo, int tamanoActual, int nuevoTamano);
void mostrarArreglo(int *arreglo, int tamano);

int main() {

    int tamanoActual;
    int nuevoTamano;

    int *numeros;
    int *nuevoArreglo;

    // Solicitar el tamaño del arreglo original
    cout << "Introduzca el tamano del arreglo: ";
    cin >> tamanoActual;

    // Validar el tamaño
    while (tamanoActual <= 0) {
        cout << "Tamano invalido. Introduzca otro: ";
        cin >> tamanoActual;
    }

    // Crear el arreglo original
    numeros = new int[tamanoActual];

    // Registrar los valores
    for (int i = 0; i < tamanoActual; i++) {

        cout << "Introduzca el numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // Mostrar el arreglo original
    cout << "\nARREGLO ORIGINAL" << endl;

    mostrarArreglo(numeros, tamanoActual);

    // Solicitar el nuevo tamaño
    cout << "\nIntroduzca el nuevo tamano del arreglo: ";
    cin >> nuevoTamano;

    // Validar el nuevo tamaño
    while (nuevoTamano <= 0) {
        cout << "Tamano invalido. Introduzca otro: ";
        cin >> nuevoTamano;
    }

    // Llamar a la funcion para redimensionar
    nuevoArreglo = redimensionarArreglo(
        numeros, tamanoActual, nuevoTamano
    );

    // Mostrar el nuevo arreglo
    cout << "\nARREGLO REDIMENSIONADO" << endl;

    mostrarArreglo(nuevoArreglo, nuevoTamano);

    // Liberar la memoria de los dos arreglos
    delete[] numeros;
    delete[] nuevoArreglo;

    numeros = nullptr;
    nuevoArreglo = nullptr;

    return 0;
}


// Funcion que redimensiona el arreglo
int *redimensionarArreglo(int *arreglo, int tamanoActual, int nuevoTamano) {

    // Crear un nuevo arreglo dinamico
    int *nuevo = new int[nuevoTamano];

    // Inicializar todas las posiciones en cero
    for (int i = 0; i < nuevoTamano; i++) {

        nuevo[i] = 0;
    }

    // Determinar cuantos elementos podemos copiar
    int cantidadCopiar;

    if (nuevoTamano < tamanoActual) {
        cantidadCopiar = nuevoTamano;
    } else {
        cantidadCopiar = tamanoActual;
    }

    // Copiar los elementos del arreglo original
    for (int i = 0; i < cantidadCopiar; i++) {

        nuevo[i] = arreglo[i];
    }

    // Devolver el puntero al nuevo arreglo
    return nuevo;
}


// Funcion para mostrar los elementos de un arreglo
void mostrarArreglo(int *arreglo, int tamano) {

    for (int i = 0; i < tamano; i++) {

        cout << arreglo[i] << " ";
    }

    cout << endl;
}
