#include <iostream>
using namespace std;

bool notaValida(double nota) {
    if (nota >= 0 && nota <= 100) {
        return true;
    }

    return false;
}

int main() {
    double nota;

    cout << "Introduzca una nota de 0 a 100: ";
    cin >> nota;

    while (!notaValida(nota)) {
        cout << "Nota invalida. Intente otra vez: ";
        cin >> nota;
    }

    cout << "La nota introducida es valida." << endl;

    return 0;
}