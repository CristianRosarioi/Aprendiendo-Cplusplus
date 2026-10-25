/*
Enunciado: Mostrar la tabla del número leído desde 1 hasta 10.
Conceptos: for, variable de control, multiplicación.
Algoritmo: 1) Leer número. 2) Iniciar factor en 1. 3) Mientras
factor <= 10, mostrar producto y aumentar factor en una unidad.
Ejemplo: entrada 3 -> 3 x 1 = 3 ... 3 x 10 = 30.
Se supone entrada entera y productos representables en int.
*/
#include <iostream>
using namespace std;

int main() {
    int numero; // Es el número cuya tabla queremos estudiar.
    cout << "Numero para la tabla: ";
    cin >> numero;

    // 1 inicia la tabla; <= 10 incluye el último factor; ++ suma 1.
    for (int factor = 1; factor <= 10; factor++) {
        cout << numero << " x " << factor << " = " << numero * factor << endl;
    } // Cuando factor llega a 11, termina el recorrido.
    return 0;
}
