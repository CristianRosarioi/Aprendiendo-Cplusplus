// Ejemplo: punteros basicos (& direccion, * desreferencia)
#include <iostream>
using namespace std;

int main() {
    int edad = 20;
    int* ptr = &edad;   // ptr guarda la direccion de memoria de edad

    cout << "Valor de edad:        " << edad << endl;
    cout << "Direccion (&edad):    " << &edad << endl;
    cout << "Valor de ptr:         " << ptr << endl;   // misma direccion
    cout << "Desreferencia (*ptr): " << *ptr << endl;  // 20

    *ptr = 99;   // modifica edad a traves del puntero
    cout << "edad ahora es:        " << edad << endl;  // 99
    return 0;
}