#include <iostream>
using namespace std;

int main() {

    int numero = 10;

    int *ptr = &numero;

    cout << "Valor original: " << numero << endl;

    *ptr = 50;

    cout << "Nuevo valor: " << numero << endl;

    *ptr += 10;

    cout << "Valor final: " << numero << endl;

    return 0;
}