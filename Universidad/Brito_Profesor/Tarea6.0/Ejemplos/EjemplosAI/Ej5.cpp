#include <iostream>
using namespace std;

int main() {

    int numeros[3] = {10, 20, 30};

    int *ptr = numeros;

    cout << "Primer valor: " << *ptr << endl;

    // Avanzar a la siguiente posicion
    ptr++;

    cout << "Segundo valor: " << *ptr << endl;

    // Aumentar el valor apuntado
    (*ptr)++;

    cout << "Segundo valor aumentado: " << *ptr << endl;

    cout << "Arreglo completo: " << endl;

    for (int i = 0; i < 3; i++) {
        cout << numeros[i] << " ";
    }

    cout << endl;

    return 0;
}