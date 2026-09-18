// Ejemplo: funcion que suma dos numeros
#include <iostream>
using namespace std;

int sumar(int a, int b) {
    return a + b;
}

int main() {
    int x, y;
    cout << "Ingresa dos numeros: ";
    cin >> x >> y;

    cout << x << " + " << y << " = " << sumar(x, y) << endl;
    return 0;
}