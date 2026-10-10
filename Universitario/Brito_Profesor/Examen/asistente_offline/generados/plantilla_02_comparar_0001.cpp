/*
Enunciado: Comparar dos numeros enteros.
Algoritmo: leer ambos y elegir una sola rama: mayor, menor o igual.
Ejemplo: entrada 4 9 -> Primero menor
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
using namespace std;

int main() {
    int primero, segundo; // Valores que vamos a comparar.
    cout << "Dos enteros: "; cin >> primero >> segundo;
    if (primero > segundo) { cout << "Primero mayor" << endl; }
    else if (primero < segundo) { cout << "Primero menor" << endl; }
    else { cout << "Iguales" << endl; } // No es mayor ni menor.
    // == seria comparar igualdad; = cambiaria un valor.
    return 0;
}
