#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int cantidad;
    int * arreglo;

    cout << "Cantidad de elementos: ";
    cin >> cantidad;
    arreglo = new int[cantidad];

    // inicializar cada elemento
    for (int i = 0; i < cantidad; i++)
        *(arreglo + i) = 0; // arreglo[i] = 0;

    // imprimir el arreglo
    for (int i = 0; i < cantidad; i++)
        cout << "[" << i << "]: "
             << *(arreglo + i) << endl;

    delete [] arreglo;
    arreglo = 0; // arreglo = NULL;

    return 0;
}
