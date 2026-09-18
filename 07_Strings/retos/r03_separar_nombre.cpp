/* RETO r03 - "Separar nombre y apellido"
Escribe un programa que:
1. Pida el nombre completo con getline (ej: "Cristian Rosario").
2. Encuentre la posicion del espacio con .find(' ').
3. Separe el nombre con .substr(0, pos) y el apellido con .substr(pos + 1).
4. Muestre ambos por separado.
Pistas:
size_t pos = nombre.find(' ');
string nom = nombre.substr(0, pos);
string ape = nombre.substr(pos + 1);
Si no hay espacio, find devuelve string::npos. */

#include <iostream>
#include <string>
using namespace std;

int main() {
    // TODO: escribe tu solucion aqui

    return 0;
}