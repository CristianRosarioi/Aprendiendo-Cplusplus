/*
Enunciado: Contar cada vocal a/e/i/o/u sin distinguir mayusculas.
Algoritmo: recorrer texto con at(i); normalizar cada byte con tolower;
contar las vocales elegidas.
Ejemplo: entrada Aula -> a 2, e 0, i 0, o 0, u 1 (si se eligen todas).
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string texto; // Incluye espacios si se eligio getline.
    cout << "Texto (puede incluir espacios): ";
    getline(cin, texto);
    int aes = 0, ees = 0, ies = 0, oes = 0, ues = 0; // Contadores.
    // Textos habituales: size() devuelve bytes y cabe en int.
    int longitud = static_cast<int>(texto.size());
    for (int i = 0; i < longitud; i++) { // Indices: 0..longitud-1.
        // Convertir a unsigned char ANTES de cctype evita bytes negativos.
        int letra = tolower(static_cast<unsigned char>(texto.at(i)));
        if (letra == 'a') { aes++; }
        else if (letra == 'e') { ees++; }
        else if (letra == 'i') { ies++; }
        else if (letra == 'o') { oes++; }
        else if (letra == 'u') { ues++; }
    }
    cout << "a: " << aes << ", e: " << ees << ", i: " << ies
         << ", o: " << oes << ", u: " << ues << endl;
    return 0;
}
