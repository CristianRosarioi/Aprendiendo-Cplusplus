/*
Enunciado: Contar mayúsculas, minúsculas, dígitos, puntuación y alfanuméricos.
Conceptos: string, getline, at, size, for y funciones de <cctype>.
Algoritmo: 1) Leer línea con espacios. 2) Visitar cada posición.
3) Probar cada categoría por separado y sumar sus contadores.
Ejemplo: entrada Hola 2! -> mayúsculas 1, minúsculas 3,
dígitos 1, puntuación 1, alfanuméricos 5.
Se usa para texto ASCII básico; no cuenta letras acentuadas como Unicode.
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string texto; // Guarda toda la línea, sin perder sus espacios.
    int mayusculas = 0; // Cada contador comienza en cero: ningún hallazgo.
    int minusculas = 0;
    int digitos = 0;
    int puntuacion = 0;
    int alfanumericos = 0;
    cout << "Texto: ";
    getline(cin, texto);

    // Se trabajan líneas habituales cuyo número de bytes cabe en int.
    int longitud = static_cast<int>(texto.size());
    for (int i = 0; i < longitud; i++) {
        // at(i) lee la posición i; la primera es 0 y la última longitud-1.
        // cctype exige EOF o un valor representable como unsigned char.
        // Convertir el byte evita pasar un char negativo (comportamiento indefinido).
        int caracter = static_cast<unsigned char>(texto.at(i));
        if (isupper(caracter)) { mayusculas++; } // Letra mayúscula.
        if (islower(caracter)) { minusculas++; } // Letra minúscula.
        if (isdigit(caracter)) { digitos++; } // Dígito 0 a 9.
        if (ispunct(caracter)) { puntuacion++; } // Por ejemplo ! , .
        if (isalnum(caracter)) { alfanumericos++; } // Letra O dígito.
        // Son if independientes: 'H' es mayúscula Y alfanumérica.
        // ++ agrega uno; == compararía, mientras = asignaría un valor.
    }
    cout << "Mayusculas: " << mayusculas << endl;
    cout << "Minusculas: " << minusculas << endl;
    cout << "Digitos: " << digitos << endl;
    cout << "Puntuacion: " << puntuacion << endl;
    cout << "Alfanumericos: " << alfanumericos << endl;
    return 0;
}
