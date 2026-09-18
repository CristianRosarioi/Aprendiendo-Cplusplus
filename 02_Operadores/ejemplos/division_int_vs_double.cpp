// Ejemplo: por que 7 / 2 == 3 ? (division de enteros)
#include <iostream>
using namespace std;

int main() {
    int a = 7;
    int b = 2;

    cout << "7 / 2 (int)   = " << a / b << endl;      // 3 (trunca el decimal)
    cout << "7 % 2 (int)   = " << a % b << endl;      // 1 (residuo)
    cout << "7.0 / 2.0     = " << 7.0 / 2.0 << endl;  // 3.5

    // Solucion clasica: convertir a double antes de dividir
    double resultado = a / (double)b;
    cout << "7 / (double)2 = " << resultado << endl;  // 3.5
    return 0;
}