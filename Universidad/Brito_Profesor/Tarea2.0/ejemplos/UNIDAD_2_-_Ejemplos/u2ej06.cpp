#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int numero;

    cout << "Entre un numero: ";
    cin >> numero;

    (numero > 0) ? cout << "Positivo" : cout << "Negativo o Cero";

    return 0;
}
