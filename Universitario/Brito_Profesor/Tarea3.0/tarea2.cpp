/*
Universidad Autónoma de Santo Domingo UASD
Centro UASD San Pedro, Escuela de informatica 5100-29
Introduccion a la Programacion
Cristian Rosario
 Matricula: 100806653
*/

#include <iostream>
#include <string>
using namespace std;

string nombreCompleto;
string::iterator letra;

int main () {
    cout << "Ingrese su nombre y apellido: ";
    getline(cin, nombreCompleto);

    letra = nombreCompleto.begin();
    while (letra != nombreCompleto.end()) {
        cout << *letra << endl;
        letra++;
    }

    return 0;
}
