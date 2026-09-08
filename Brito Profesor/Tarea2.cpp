
// Tarea 3

/*Hacer un programa que lea tres números reales tipo double y calcule el
promedio o media aritmética (la sumatoria de los números entre la
cantidad de números sumados).*/

#include <iostream>
using namespace std;

int main() {
    double num1, num2, num3, promedio;

    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    cout << "Ingrese el tercer numero: ";
    cin >> num3;

    promedio = (num1 + num2 + num3) / 3;

    cout << "El promedio es: " << promedio << endl;

    return 0;
}   
