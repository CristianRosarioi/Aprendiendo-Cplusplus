#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int numero;
    string mensaje;

    cout << "Entre un numero: ";
    cin >> numero;

    mensaje = (numero > 0) ? "Positivo" : "Negativo o Cero";

    cout << "El numero es " << mensaje << endl;

    return 0;
}
