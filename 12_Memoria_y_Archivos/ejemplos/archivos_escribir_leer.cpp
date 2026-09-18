// Ejemplo: escribir y leer archivos con fstream
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // ESCRIBIR en el archivo
    ofstream salida("notas.txt");
    if (!salida) {
        cout << "No se pudo crear el archivo" << endl;
        return 1;
    }
    salida << "Cristian 8.5" << endl;
    salida << "Ana 9.0" << endl;
    salida.close();

    // LEER el archivo linea por linea
    ifstream entrada("notas.txt");
    if (!entrada) {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }

    string linea;
    cout << "Contenido de notas.txt:" << endl;
    while (getline(entrada, linea)) {
        cout << linea << endl;
    }
    entrada.close();

    return 0;
}