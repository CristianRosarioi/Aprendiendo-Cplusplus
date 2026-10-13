#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    const int SIZE = 5;
    // Declarando e inicializando el arreglo con valores
    int edades[SIZE] = {23, 34, 55, 25, 58};
    double sumatoria = 0;

    /*
     * Asignando los valores de cada elemento de forma manual
    edades[0] = 23;
    edades[1] = 34;
    edades[2] = 55;
    edades[3] = 25;
    edades[4] = 58;
    */

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Elemento " << i << ": " << edades[i] << endl;
        sumatoria += edades[i];
    }

    cout << "Edad Promedio es " << sumatoria / SIZE << endl;

    return 0;
}
