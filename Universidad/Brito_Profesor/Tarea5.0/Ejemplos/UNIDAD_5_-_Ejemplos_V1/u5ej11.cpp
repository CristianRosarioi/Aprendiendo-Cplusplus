#include <iostream>

using namespace std;

void cambiaNumero(int &);

int main(int argc, char** argv)
{
    int numero = 5;
    cout << "El valor de numero es: " << numero << endl;
    cout << "Numero esta en la siguiente direccion de RAM: " << &numero << endl;

    cambiaNumero(numero);

    cout << "Dentro de main: " << numero << endl;

    return 0;
}

void cambiaNumero(int &valor)
{
    valor += 2;
    cout << "Estoy dentro de la funcion: " << valor << endl;
}
