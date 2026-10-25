/*
Enunciado: Elegir vocal por edad y sexo F/M; contarla en nombre completo.
Algoritmo: leer edad, nombre con espacios y sexo; elegir i/a/e/o con if
anidados; contar esa vocal ignorando mayusculas.
Ejemplo: entrada 20, Maria Isabel, F -> Vocal i: 2
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int edad; // La mayoria de edad comienza a los 18.
    string nombre; // Puede incluir espacios.
    char sexo, vocal = ' '; // La vocal se elige tras validar F/M.
    int cantidad = 0; // Contador sin coincidencias inicialmente.
    cout << "Edad: "; cin >> edad;
    cin.ignore(); // Descarta ENTER si la edad se escribio sola en su linea.
    cout << "Nombre completo: "; getline(cin, nombre);
    cout << "Sexo F/M: "; cin >> sexo;
    if (sexo == 'F' || sexo == 'f') {
        if (edad >= 18) { vocal = 'i'; }
        else { vocal = 'a'; }
    } else if (sexo == 'M' || sexo == 'm') {
        if (edad >= 18) { vocal = 'e'; }
        else { vocal = 'o'; }
    } else {
        cout << "Sexo invalido." << endl;
        return 0;
    }
    // Indices 0..size()-1; en UTF-8 esto recorre bytes, no letras completas.
    int longitud = static_cast<int>(nombre.size());
    for (int i = 0; i < longitud; i++) {
        // cctype requiere byte valido: convertir ANTES de tolower.
        int letra = tolower(static_cast<unsigned char>(nombre.at(i)));
        if (letra == vocal) { cantidad++; } // == compara; = asigna.
    }
    cout << "Vocal " << vocal << ": " << cantidad << endl;
    return 0;
}
