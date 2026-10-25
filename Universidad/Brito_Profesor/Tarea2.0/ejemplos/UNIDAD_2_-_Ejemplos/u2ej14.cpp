#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int numero;
    long factorial = 1;

    cout << "Entre un numero: ";
    cin >> numero;

    for (int cnt = 1; cnt <= numero; cnt++)
    {
        factorial *= cnt;
    }

    cout << "El factorial de " << numero
         << " es: " << factorial << endl;

    return 0;
}
