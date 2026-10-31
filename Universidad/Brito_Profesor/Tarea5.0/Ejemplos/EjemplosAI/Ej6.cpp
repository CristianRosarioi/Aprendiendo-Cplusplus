#include <iostream>
using namespace std;

void mostrarTabla(int numero) {
    for (int i = 1; i <= 12; i++) {
        cout << numero << " x " << i
             << " = " << numero * i << endl;
    }
}

int main() {
    int numero;

    cout << "Introduzca un numero: ";
    cin >> numero;

    mostrarTabla(numero);

    return 0;
}