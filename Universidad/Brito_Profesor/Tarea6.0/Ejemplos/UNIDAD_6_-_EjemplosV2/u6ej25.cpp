#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    const unsigned int SIZE = 5;
    short numeros[SIZE] = {31, 19, 14, 74, 9};
    short *numerosPtr = numeros;

    short *punteroA = numerosPtr + 1;
    short *punteroB = numerosPtr + 4;

    cout << "Direccion punteroA: " << punteroA << endl;
    cout << "Direccion punteroB: " << punteroB << endl;
    cout << endl;

    if (punteroA > punteroB)
        cout << "punteroA es MAYOR que punteroB";
    else if (punteroA == punteroB)
        cout << "puntero es IGUAL que punteroB";
    else
        cout << "punteroA es MENOR que punteroB";

    cout << endl;

    return 0;
}
