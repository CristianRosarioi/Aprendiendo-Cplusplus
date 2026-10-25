#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int numero;

    do
    {
        cout << "Entre un numero positivo: ";
        cin >> numero;

        if (numero <= 0)
            cout << "\nNumero invalido.  Intentelo de nuevo.\n\n";

    } while (numero <= 0);

    cout << "Numero introducido: " << numero << endl;

    return 0;
}
