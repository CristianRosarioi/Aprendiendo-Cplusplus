#include <iostream>

using namespace std;

int mayor(int arreglo[], int cantidad)
{
    int mayor = arreglo[0];
    for (int i = 0; i < cantidad; i++)
    {
        if (arreglo[i] > mayor)
            mayor = arreglo[i];
    }

    return mayor;
}
