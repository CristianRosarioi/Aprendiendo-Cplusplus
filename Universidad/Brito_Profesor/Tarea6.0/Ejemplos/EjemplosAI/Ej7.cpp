#include <iostream>
using namespace std;

// Prototipo
void intercambiar(int *a, int *b);

int main() {

    int numero1 = 10;
    int numero2 = 20;

    cout << "ANTES DEL INTERCAMBIO" << endl;

    cout << "Numero 1: " << numero1 << endl;
    cout << "Numero 2: " << numero2 << endl;

    intercambiar(&numero1, &numero2);

    cout << "\nDESPUES DEL INTERCAMBIO" << endl;

    cout << "Numero 1: " << numero1 << endl;
    cout << "Numero 2: " << numero2 << endl;

    return 0;
}

// Funcion que intercambia los valores
void intercambiar(int *a, int *b) {

    int temporal;

    temporal = *a;

    *a = *b;

    *b = temporal;
}