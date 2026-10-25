/*
Enunciado: Leer dos enteros hasta que el primero sea menor que el segundo.
Conceptos: while, comparación >= y validación antes de continuar.
Algoritmo: 1) Leer extremos. 2) Mientras inicio >= final, avisar
y volver a leer AMBOS. 3) Mostrar el intervalo válido.
Ejemplo: entrada 8 8, luego 2 5 -> Intervalo valido: [2, 5].
Se supone entrada entera correcta en cada intento.
*/
#include <iostream>
using namespace std;

int main() {
    int inicio; // Primer extremo que debe resultar estrictamente menor.
    int final;  // Segundo extremo del intervalo.
    cout << "Inicio y final: ";
    cin >> inicio >> final;

    // >= incluye los extremos iguales, que tampoco forman intervalo válido.
    while (inicio >= final) {
        cout << "Intervalo invalido; escriba inicio < final: ";
        cin >> inicio >> final; // Cambiar ambos permite corregir cualquiera.
    } // Al salir del while sabemos que inicio < final.
    cout << "Intervalo valido: [" << inicio << ", " << final << "]" << endl;
    return 0;
}
