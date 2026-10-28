#include <iostream>
#include <iomanip>

using namespace std;

// variables globales
const int FILAS = 2;
const int COLS = 2;

void imprimeArreglo(int filas, int cols, int num[FILAS][COLS])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(10) << num[i][j];
        }
        cout << endl;
    }
}

int main(int argc, char** argv)
{
    int numeros[FILAS][COLS] = {{1, 5},
                                {2, 3}};

    imprimeArreglo(FILAS, COLS, numeros);

    return 0;
}

