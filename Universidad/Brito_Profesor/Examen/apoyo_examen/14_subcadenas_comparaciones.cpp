/*
Enunciado: Mostrar substr, empty y comparaciones lexicográficas de string.
Conceptos: índices desde cero, subcadena (inicio, cantidad), < y ==.
Algoritmo: 1) Partir de "casa". 2) Extraer dos caracteres desde
índice 1. 3) Examinar si una cadena está vacía. 4) Comparar palabras.
Ejemplo: substr(1,2) = as; "casa" < "caso" es verdadero.
La comparación depende del orden de caracteres, no de la longitud.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string palabra = "casa"; // Sus índices son 0:c, 1:a, 2:s, 3:a.
    string otra = "caso";   // Difiere de palabra solo en la última letra.
    string vacia = "";     // Sin caracteres: empty() será verdadero.
    cout << "Subcadena: " << palabra.substr(1, 2) << endl;
    // substr(1,2) empieza en 1 y toma DOS caracteres; no termina en 2.
    if (vacia.empty()) {
        cout << "La tercera cadena esta vacia." << endl;
    }
    if (palabra < otra) {
        // 'a' va antes de 'o'; los tres primeros caracteres coinciden.
        cout << "casa va antes que caso." << endl;
    }
    if (palabra == otra) {
        cout << "Las palabras son iguales." << endl;
    } else {
        cout << "Las palabras son distintas." << endl;
    }
    // == compara; = asignaría otra cadena. La longitud no decide el orden.
    return 0;
}
