#include <iostream>
using namespace std;

int main() {

    int *numero;

    // Reservar memoria dinamicamente
    numero = new int;

    // Guardar un valor en esa memoria
    *numero = 100;

    cout << "Valor almacenado: " << *numero << endl;

    // Modificar el valor
    *numero = 250;

    cout << "Nuevo valor: " << *numero << endl;

    // Liberar la memoria
    delete numero;

    numero = nullptr;

    return 0;
}