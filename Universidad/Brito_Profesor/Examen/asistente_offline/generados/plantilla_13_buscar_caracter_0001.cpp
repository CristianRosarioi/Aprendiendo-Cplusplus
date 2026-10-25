/*
Enunciado: Contar apariciones de un caracter en una cadena.
Algoritmo: leer texto y caracter; recorrer posiciones; comparar cada
caracter segun la opcion de mayusculas.
Ejemplo: entrada banana y caracter a -> Apariciones: 3
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string texto; // Texto completo que se examina.
    cout << "Texto (puede incluir espacios): ";
    getline(cin, texto);
    char buscado; // Se lee al ejecutar; cin >> omite blancos.
    cout << "Caracter a buscar (sin espacios): "; cin >> buscado;
    int apariciones = 0; // Empieza sin coincidencias.
    // Textos habituales: size() devuelve bytes y cabe en int.
    int longitud = static_cast<int>(texto.size());
    for (int i = 0; i < longitud; i++) { // Indices: 0..longitud-1.
        if (texto.at(i) == buscado) { apariciones++; } // == compara.
    }
    cout << "Apariciones: " << apariciones << endl;
    return 0;
}
