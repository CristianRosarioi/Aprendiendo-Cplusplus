/*1. Arreglo fijo: leer cuatro notas y calcular el promedio
Practica declaración de arreglos, índices, lectura y acumulación.

La lógica: notas[i] identifica una posición. El primer ciclo guarda los datos; el segundo los muestra y suma. Las posiciones válidas son 0, 1, 2 y 3.

Empieza ejecutando el primero y cambia sus cuatro notas. Después intenta añadir el cálculo de la nota mayor antes de pasar al segundo. Así practicas una idea nueva cada vez.*/


#include <iostream>
using namespace std;

int main() {
    const int TAMANO = 4;
    double notas[TAMANO];
    double suma = 0;
    int i;

    for (i = 0; i < TAMANO; i++) {
        cout << "Ingrese la nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    cout << "\nNotas ingresadas:" << endl;

    for (i = 0; i < TAMANO; i++) {
        cout << notas[i] << endl;
        suma += notas[i];
    }

    cout << "Promedio: " << suma / TAMANO << endl;

    return 0;
}