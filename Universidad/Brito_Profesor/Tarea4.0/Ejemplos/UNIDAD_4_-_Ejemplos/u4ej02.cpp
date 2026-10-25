#include <iostream>

using namespace std;

int mayor(int[], int);

int main(int argc, char** argv)
{
    /*************************************************************
     * Tres tipos de arreglos para ser vistos en esta asignatura *
     *
     * Arreglos definidos en tiempo de compilacion
     * Arreglos definidos en tiempo de ejecucion
     * Vectores
     *************************************************************/

    const int SIZE = 5;
    int numeros[SIZE] = {34, 23, 33, 66, 45};


    cout << "El mayor es " << mayor(numeros, SIZE) << endl;

    return 0;
}

int mayor(int x[], int s)
{
    int m = x[0];

    for (int i = 0; i < s; i++)
    {
        if (x[i] > m)
            m = x[i];
    }

    return m;
}
