#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Prototipo de la funcion
void mostrarArchivo(string nombreArchivo);

int main() {

    string nombreArchivo;

    // Solicitar el nombre del archivo
    cout << "Introduzca el nombre del archivo: ";
    getline(cin, nombreArchivo);

    // Llamar a la funcion que muestra el archivo
    mostrarArchivo(nombreArchivo);

    return 0;
}

// Funcion que lee y muestra el contenido del archivo
void mostrarArchivo(string nombreArchivo) {

    // Abrir el archivo en modo lectura
    fstream archivo(nombreArchivo.c_str(), ios::in);

    // Verificar que el archivo se haya abierto
    if (!archivo.is_open()) {

        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;

    int numeroLinea = 1;
    int lineasPantalla = 0;

    // Leer todas las lineas del archivo
    while (getline(archivo, linea)) {

        // Hacer una pausa cada 24 lineas
        if (lineasPantalla == 24) {

            cout << "\nPresione Enter para continuar...";
            cin.get();

            lineasPantalla = 0;
        }

        // Mostrar el numero y contenido de la linea
        cout << numeroLinea << ": " << linea << endl;

        // Aumentar los contadores
        numeroLinea++;
        lineasPantalla++;
    }

    // Cerrar el archivo
    archivo.close();
}
