/*
Enunciado: Demostrar insert, erase, push_back, substr, empty y comparar.
Algoritmo: partir de un string; insertar, borrar, anexar un caracter;
mostrar cada cambio y examinar una subcadena y el orden.
Ejemplo: texto inicial Sol -> tras insertar ' de': Sol de; tras borrar: Sol; final: Sol!
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string texto = "Sol"; // Texto fijo validado al generar.
    cout << "Inicial: " << texto << endl;
    // size() apunta justo despues del ultimo caracter: agregamos ' de'.
    texto.insert(texto.size(), " de");
    cout << "Tras insert: " << texto << endl;
    // erase elimina los tres caracteres que acabamos de insertar.
    texto.erase(texto.size() - 3, 3);
    cout << "Tras erase: " << texto << endl;
    texto.push_back('!'); // Un char al final del estado ACTUAL.
    cout << "Tras push_back: " << texto << endl;
    // substr(0, 2) toma como maximo dos caracteres desde indice 0.
    cout << "Primeros dos: " << texto.substr(0, 2) << endl;
    if (texto.empty()) { cout << "Vacia" << endl; }
    else { cout << "No vacia" << endl; }
    if (texto < "sol") { cout << "Antes de sol (orden lexicografico)" << endl; }
    else { cout << "Igual o despues de sol (orden lexicografico)" << endl; }
    return 0;
}
