#include <iostream>
using namespace std;

int sumar(int a, int b) {
    int resultado;

    resultado = a + b;

    return resultado;
}

int main() {
    int numero1, numero2;
    int total;

    cout << "Primer numero: ";
    cin >> numero1;

    cout << "Segundo numero: ";
    cin >> numero2;

    total = sumar(numero1, numero2);

    cout << "La suma es: " << total << endl;

    return 0;
}
