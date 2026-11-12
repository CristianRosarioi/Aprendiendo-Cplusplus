#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int numero = 19;
    int *puntero = &numero;

    cout << "La direccion de numero es  : " << &numero << endl
         << "El contenido de puntero es : " << puntero << endl
         << "Lo que apunta el puntero es: " << *puntero << endl;

    // cambiar valor de numero a traves del puntero
    *puntero += 3;

    cout << "El valor de numero es: " << numero << endl;
    return 0;
}
