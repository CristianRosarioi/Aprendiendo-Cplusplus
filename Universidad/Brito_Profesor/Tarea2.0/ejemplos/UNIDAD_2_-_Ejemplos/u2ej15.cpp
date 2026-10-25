#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int numero;
    long unsigned long factorial = 1;

    /***************************************
     *  Ciclo para garantizar que el valor *
     *  de la variable numero sea >= cero  *
     ***************************************/
    do
    {
        cout << "Entre un numero >= cero: ";
        cin >> numero;
    } while (numero < 0);

    /***************************************
     * Ciclo for para calcular el factorial*
     ***************************************/
    for (int cnt = 1; cnt <= numero; cnt++)
    {
        factorial *= cnt;
    }

    cout << "El factorial de " << numero
         << " es: " << factorial << endl;

    return 0;
}
