// Tarea 1

/*Hacer un programa que solicite al usuario que introduzca dos números
enteros tipo int por teclado y calcule e imprima la suma, resta,
multiplicación, división y residuo de dichos números.*/

#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    cout << "ingrese el prime numero: ";
    cin >> num1;
    cout << "ingrese el sefundo numero: ";
    cin >> num2;
    cout << "la suma es: " << num1 + num2 << endl;
    cout << "la resta es:" << num1 - num2 << endl;
    cout << "la multiplicacion es:" << num1 * num2 << endl;
    cout << "la division es:" << num1 / num2 << endl;
    cout << "el residuo es:" << num1 % num2 << endl;
    return 0;
}

