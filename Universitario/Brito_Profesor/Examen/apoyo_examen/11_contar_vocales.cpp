/*
Enunciado: Contar por separado a, e, i, o, u sin distinguir mayúsculas.
Conceptos: string, recorrido por posición, contadores, tolower de <cctype>.
Algoritmo: 1) Leer línea. 2) Convertir cada byte a minúscula.
3) Sumar uno al contador de la vocal correspondiente, si lo es.
Ejemplo: entrada Aula -> a 2, e 0, i 0, o 0, u 1.
Solo vocales ASCII sin tilde: á y otras letras Unicode requieren otro método.
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string texto; // Incluye también espacios, que no son vocales.
    int aes = 0, ees = 0, ies = 0, oes = 0, ues = 0;
    // Los contadores comienzan en cero porque aún no se han visto vocales.
    cout << "Texto: ";
    getline(cin, texto);

    int longitud = static_cast<int>(texto.size()); // Texto de tamaño habitual.
    for (int i = 0; i < longitud; i++) {
        // Se lee desde índice 0 hasta longitud-1, sin salir de la cadena.
        // tolower requiere byte no negativo: la conversión evita un char negativo.
        int letra = tolower(static_cast<unsigned char>(texto.at(i)));
        if (letra == 'a') { aes++; }
        else if (letra == 'e') { ees++; }
        else if (letra == 'i') { ies++; }
        else if (letra == 'o') { oes++; }
        else if (letra == 'u') { ues++; }
        // == compara; = asignaría. ++ añade un caso al contador elegido.
    }
    cout << "a: " << aes << ", e: " << ees << ", i: " << ies
         << ", o: " << oes << ", u: " << ues << endl;
    return 0;
}
