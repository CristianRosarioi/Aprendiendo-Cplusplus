#include <iostream>
#include <iomanip>

using namespace std;

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
    int sum = 0;

    for (int i = 0; i < SIZE; i++)
    {
        sum += numeros[i];
    }

    cout << "Sumatoria = " << setw(6) << sum << endl;
    cout << setprecision(2) << fixed;
    cout << "Promedio  = " << setw(6) << left << (double)sum / SIZE << endl;

    return 0;
}
