// Ejemplo: intercambio por referencia (&)
#include <iostream>
using namespace std;

void intercambiar(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main() {
    int a = 10, b = 20;

    cout << "Antes: a=" << a << " b=" << b << endl;
    intercambiar(a, b);
    cout << "Despues: a=" << a << " b=" << b << endl;
    return 0;
}