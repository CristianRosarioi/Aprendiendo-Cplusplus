#include <iostream>
using namespace std;

int main() {

    int edad = 20;

    int *ptr = &edad;

    cout << "Edad: " << edad << endl;

    cout << "Direccion de edad: " << &edad << endl;

    cout << "Contenido de ptr: " << ptr << endl;

    cout << "Valor apuntado por ptr: " << *ptr << endl;

    return 0;
}