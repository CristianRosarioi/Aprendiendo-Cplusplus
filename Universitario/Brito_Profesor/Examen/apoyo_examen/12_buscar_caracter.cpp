/*
Enunciado: Leer un texto y un carácter; contar cuántas veces aparece.
Conceptos: char frente a string, getline, for, at, comparación ==.
Algoritmo: 1) Leer línea entera. 2) Leer un carácter (no blanco).
3) Recorrer las posiciones y contar las coincidencias exactas.
Ejemplo: entrada banana, luego a -> apariciones 3.
La comparación distingue A de a; se busca un solo byte ASCII.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string texto; // Secuencia completa de caracteres a recorrer.
    char buscado; // Un solo carácter leído con cin >>; omite espacios.
    int apariciones = 0; // Ninguna coincidencia antes de recorrer.
    cout << "Texto: ";
    getline(cin, texto);
    cout << "Caracter a buscar (sin espacios): ";
    cin >> buscado;

    int longitud = static_cast<int>(texto.size()); // Textos de tamaño habitual.
    for (int i = 0; i < longitud; i++) {
        // Índices desde cero: el ciclo termina antes de i == longitud.
        if (texto.at(i) == buscado) { // == pregunta; = cambiaría el dato.
            apariciones++; // ++ suma una aparición al contador.
        }
    }
    cout << "Apariciones de '" << buscado << "': " << apariciones << endl;
    return 0;
}
