
#include <iostream>
using namespace std;

// Prototipos de las funciones
void leerNumeros(int *arreglo, int cantidad);
int calcularModa(int *arreglo, int cantidad);

int main() {

    int cantidad;
    int moda;

    int *numeros;

    // Solicitar la cantidad de numeros
    cout << "Cuantos numeros desea introducir? ";
    cin >> cantidad;

    // Validar la cantidad
    while (cantidad <= 0) {
        cout << "Cantidad invalida. Introduzca otra: ";
        cin >> cantidad;
    }

    // Crear el arreglo dinamico
    numeros = new int[cantidad];

    // Llamar a la funcion para registrar los numeros
    leerNumeros(numeros, cantidad);

    // Calcular la moda
    moda = calcularModa(numeros, cantidad);

    // Mostrar los numeros introducidos
    cout << "\nNUMEROS INTRODUCIDOS" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << *(numeros + i) << " ";
    }

    cout << endl;

    // Mostrar el resultado
    if (moda == -1) {

        cout << "\nEl arreglo no tiene moda." << endl;

    } else {

        cout << "\nLa moda del arreglo es: "
             << moda << endl;
    }

    // Liberar la memoria dinamica
    delete[] numeros;

    numeros = nullptr;

    return 0;
}


// Funcion para leer los numeros
void leerNumeros(int *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++) {

        cout << "Introduzca el numero " << i + 1 << ": ";

        cin >> *(arreglo + i);

        // Validar que el numero sea positivo
        while (*(arreglo + i) <= 0) {

            cout << "Numero invalido. Introduzca uno positivo: ";

            cin >> *(arreglo + i);
        }
    }
}


// Funcion para calcular la moda
int calcularModa(int *arreglo, int cantidad) {

    int moda = -1;
    int mayorFrecuencia = 1;
    int frecuencia;

    // Recorrer cada numero del arreglo
    for (int i = 0; i < cantidad; i++) {

        frecuencia = 0;

        // Comparar el numero actual con todos los demas
        for (int j = 0; j < cantidad; j++) {

            if (*(arreglo + i) == *(arreglo + j)) {

                frecuencia++;
            }
        }

        // Actualizar la moda si encontramos
        // un numero con mayor frecuencia
        if (frecuencia > mayorFrecuencia) {

            mayorFrecuencia = frecuencia;

            moda = *(arreglo + i);
        }
    }

    return moda;
}
