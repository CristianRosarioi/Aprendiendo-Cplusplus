#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char** argv)
{
    int *numeros;
    int cantidad;

    do
    {
        cout << "Cuantos numeros? ";
        cin >> cantidad;
        if (cantidad == 0) break;
    } while (cantidad < 0);

    numeros = new int[cantidad];

    srand(time(0));
    for (int i = 0; i < cantidad; i++)
    {
        *(numeros + i) = rand() % 100 + 1;
    }

    cout << endl;
    for (int i = 0; i < cantidad; i++)
    {
        cout << numeros[i] << endl;
    }


    delete [] numeros;
    numeros = NULL;

    return 0;
}
