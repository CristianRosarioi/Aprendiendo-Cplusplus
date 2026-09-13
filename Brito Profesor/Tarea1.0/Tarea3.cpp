// Tarea 2

/*Escribir un programa que le solicite al usuario introducir su nombre
(utilice una variable tipo char -arreglo de char [30]- para almacenar el
valor) y la edad (puede almacenarla en una variable tipo int) e imprima
“Hola nombre, usted tiene XX años”, donde nombre representa el dato
leído por teclado y XX la edad. Considere que la persona puede tener
dos nombres (ver cin.getline() y cin.ignore()).*/

#include <iostream>
using namespace std;

int main() {
    char nombre[30];
    int edad;

    cout << "Ingrese su nombre: ";
    cin.getline(nombre, 30); // Leer el nombre completo, incluyendo espacios

    cout << "Ingrese su edad: ";
    cin >> edad;

    cout << "Hola " << nombre << ", usted tiene " << edad << " años." << endl;

    return 0;
}


       