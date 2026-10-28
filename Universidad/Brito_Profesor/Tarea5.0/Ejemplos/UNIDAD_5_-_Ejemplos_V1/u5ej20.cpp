#include <iostream>

using namespace std;

int mayor(int[], int);

int main(int argc, char** argv)
{
    const int CANTIDAD = 6;
    int numeros[CANTIDAD]
          = {25, 9, 93, 33, 28, 55};

    cout << "El mayor es: "
         << mayor(numeros, CANTIDAD)
         << endl;
    return 0;
}

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
