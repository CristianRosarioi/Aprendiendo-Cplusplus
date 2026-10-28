#include <iostream>

using namespace std;

int menor(int arreglo[], int cantidad)
{
    int menor = arreglo[0];
    for (int i = 0; i < cantidad; i++)
    {
        if (arreglo[i] < menor)
            menor = arreglo[i];
    }

    return menor;
}
