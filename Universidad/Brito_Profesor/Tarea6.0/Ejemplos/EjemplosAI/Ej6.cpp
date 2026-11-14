#include <iostream>
using namespace std;

// Prototipo
void duplicarNumero(int *numero);

int main() {

    int valor;

    cout << "Introduzca un numero: ";
    cin >> valor;

    cout << "Antes: " << valor << endl;

    duplicarNumero(&valor);

    cout << "Despues: " << valor << endl;

    return 0;
}

// Funcion que duplica el numero
void duplicarNumero(int *numero) {

    *numero = *numero * 2;
}