// Ejemplo: bucle for (tabla de multiplicar de 7)
#include <iostream>
using namespace std;

int main() {
    const int NUMERO = 7;

    for (int i = 1; i <= 10; i++) {
        cout << NUMERO << " x " << i << " = " << NUMERO * i << endl;
    }
    return 0;
}