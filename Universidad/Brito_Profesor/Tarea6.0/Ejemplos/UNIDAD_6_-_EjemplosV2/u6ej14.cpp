#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char** argv)
{
    srand(time(0));

    int tamano = rand() % 21 + 10; // de 0 a 20
    cout << "Tamano del arreglo: " << tamano << endl << endl;

    int * arreglo = new int[tamano];

    cout << "Imprimiendo el arreglo\n";
    for (int i = 0; i < tamano; i++)
    {
        cout << i << ": " << arreglo[i] << endl;
    }

    return 0;
}
