/*
Enunciado: Comparar dos enteros y decir si el primero es mayor, menor o igual.
Conceptos: if, else if, else; relaciones >, <, ==.
Algoritmo: 1) Leer dos números. 2) Probar si el primero es mayor.
3) Si no lo es, probar si es menor. 4) Si no, son iguales.
Ejemplo: entrada 4 y 9 -> El primero es menor que el segundo.
Se supone entrada entera correcta.
*/
#include <iostream>
using namespace std;

int main() {
    int primero; // Número situado a la izquierda de las comparaciones.
    int segundo; // Número contra el que se compara el primero.
    cout << "Primer entero: ";
    cin >> primero;
    cout << "Segundo entero: ";
    cin >> segundo;

    // Solo se ejecuta una rama: al cumplirse una, se omiten las demás.
    if (primero > segundo) {
        cout << "El primero es mayor que el segundo." << endl;
    } else if (primero < segundo) {
        cout << "El primero es menor que el segundo." << endl;
    } else {
        // Si no es mayor ni menor, necesariamente primero == segundo.
        cout << "Son iguales." << endl;
    }
    // == compara valores; = guarda un nuevo valor en una variable.
    return 0;
}
