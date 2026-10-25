/*
Enunciado: Contar categorias seleccionadas en un texto.
Algoritmo: leer texto; recorrer bytes con at(i); usar condiciones
independientes por categoria, pues se pueden superponer.
Ejemplo: entrada Hola 2! -> mayusculas 1, minusculas 3, digitos 1,
puntuacion 1, alfanumericos 5 (si se seleccionan todas).
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string texto; // Texto que se recorrera posicion por posicion.
    cout << "Texto (puede incluir espacios): ";
    getline(cin, texto);
    int mayusculas = 0; // Contador inicial.
    int minusculas = 0; // Contador inicial.
    int digitos = 0; // Contador inicial.
    int puntuacion = 0; // Contador inicial.
    int alfanumericos = 0; // Contador inicial.
    // Textos habituales: size() devuelve bytes y cabe en int.
    int longitud = static_cast<int>(texto.size());
    for (int i = 0; i < longitud; i++) { // Indices: 0..longitud-1.
        // cctype acepta EOF o un byte convertible a unsigned char.
        // Convertir ANTES impide pasar un char negativo.
        int caracter = static_cast<unsigned char>(texto.at(i));
        if (isupper(caracter)) { mayusculas++; }
        if (islower(caracter)) { minusculas++; }
        if (isdigit(caracter)) { digitos++; }
        if (ispunct(caracter)) { puntuacion++; }
        if (isalnum(caracter)) { alfanumericos++; }
        // if independientes: 'A' es mayuscula Y alfanumerica.
    }
    cout << "Mayusculas: " << mayusculas << endl;
    cout << "Minusculas: " << minusculas << endl;
    cout << "Digitos: " << digitos << endl;
    cout << "Puntuacion: " << puntuacion << endl;
    cout << "Alfanumericos: " << alfanumericos << endl;
    return 0;
}
