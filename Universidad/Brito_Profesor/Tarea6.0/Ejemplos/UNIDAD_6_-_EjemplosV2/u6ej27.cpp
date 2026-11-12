#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    const unsigned int SIZE = 5;
    short numeros[SIZE] = {31, 19, 14, 74, 9};
    short * numerosPtr = numeros;

    cout << "Imprimiendo arreglo del primero al ultimo\n";
    int indice = 0;
    while (indice < SIZE)
    {
        cout << "[" << indice << "] (" << numerosPtr
             << "): " << *numerosPtr << endl;
        indice++;
        numerosPtr++;
    }

    cout << "\nImprimiendo arreglo del ultimo al primero\n";
    indice = SIZE - 1;
    numerosPtr--;
    while (indice >= 0)
    {
        cout << "[" << indice << "] (" << numerosPtr
             << "): " << *numerosPtr << endl;
        indice--;
        numerosPtr--;
    }

    return 0;
}
