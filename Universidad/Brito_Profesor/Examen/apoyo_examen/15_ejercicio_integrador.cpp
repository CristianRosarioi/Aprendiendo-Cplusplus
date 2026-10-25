/*
Enunciado: Leer edad, nombre completo y sexo F/M; elegir y contar vocal.
Mujer adulta: i; mujer menor: a; hombre adulto: e; hombre menor: o.
Conceptos: cin.ignore, getline, if anidados, for, tolower y contador.
Algoritmo: 1) Leer edad y línea del nombre. 2) Leer F/M, comprobar
valor y edad, elegir vocal. 3) Recorrer el nombre y contar esa vocal.
Ejemplo: entrada 20, Maria Isabel, F -> vocal i, cantidad 2.
Se suponen edad entera y cada dato en su línea. Solo vocales ASCII sin tilde.
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int edad; // Decide si se utiliza la vocal para mayor o menor de edad.
    string nombre; // Guarda nombre y apellido, incluidos los espacios.
    char sexo; // F o M; se permiten también f y m.
    char vocal = ' '; // Se reemplaza al determinar sexo y edad.
    int cantidad = 0; // Ninguna coincidencia antes del recorrido.
    cout << "Edad: ";
    cin >> edad;
    cin.ignore(); // Descarta ENTER antes de leer la línea completa.
    cout << "Nombre completo: ";
    getline(cin, nombre);
    cout << "Sexo (F/M): ";
    cin >> sexo;

    // Condiciones anidadas: primero sexo, luego edad dentro de cada caso.
    if (sexo == 'F' || sexo == 'f') {
        if (edad >= 18) { vocal = 'i'; }
        else { vocal = 'a'; }
    } else if (sexo == 'M' || sexo == 'm') {
        if (edad >= 18) { vocal = 'e'; }
        else { vocal = 'o'; }
    } else {
        cout << "Sexo invalido: escriba F o M." << endl;
        return 0; // Sin vocal elegida no se debe contar.
    }

    int longitud = static_cast<int>(nombre.size()); // Nombre de tamaño habitual.
    for (int i = 0; i < longitud; i++) {
        // at(i) recorre desde 0 hasta longitud-1; incluye los espacios.
        // Convertir cada byte antes de tolower evita un argumento negativo.
        int letra = tolower(static_cast<unsigned char>(nombre.at(i)));
        if (letra == vocal) { // == compara; = asigna un nuevo valor.
            cantidad++; // ++ agrega una coincidencia.
        }
    }
    cout << "La vocal '" << vocal << "' aparece " << cantidad
         << " veces en el nombre." << endl;
    return 0;
}
