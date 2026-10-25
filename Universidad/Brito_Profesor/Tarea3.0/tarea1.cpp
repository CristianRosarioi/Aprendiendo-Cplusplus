/*
Universidad Autónoma de Santo Domingo UASD
Centro UASD San Pedro, Escuela de informatica 5100-29
Introduccion a la Programacion
Cristian Rosario
Matricula: 100806653
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string texto;
int mayusculas = 0;
int minusculas = 0;
int digitos = 0;
int puntuacion = 0;
int alfanumericos = 0;
unsigned int i;
unsigned char caracter;

int main () {
    cout << "Ingrese un texto: ";
    getline(cin, texto);

    for (i = 0; i < texto.size(); i++) {
        caracter = texto.at(i);

        if (isupper(caracter)) {
            mayusculas++;
        }
        if (islower(caracter)) {
            minusculas++;
        }
        if (isdigit(caracter)) {
            digitos++;
        }
        if (ispunct(caracter)) {
            puntuacion++;
        }
        if (isalnum(caracter)) {
            alfanumericos++;
        }
    }

    cout << "Mayusculas: " << mayusculas << endl;
    cout << "Minusculas: " << minusculas << endl;
    cout << "Digitos: " << digitos << endl;
    cout << "Signos de puntuacion: " << puntuacion << endl;
    cout << "Alfanumericos (letras y digitos): " << alfanumericos << endl;

    return 0;
}
