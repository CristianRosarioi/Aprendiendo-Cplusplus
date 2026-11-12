#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getSize();
int * create(int);
void print(int *, int);

int main(int argc, char** argv)
{
    int cantidad = getSize();

    if (cantidad > 0)
    {
        int *numeros = create(cantidad);
        print(numeros, cantidad);
    }

    return 0;
}

int getSize()
{
    int cantidad;

    do
    {
        cout << "Cuantos numeros? ";
        cin >> cantidad;
        if (cantidad == 0) break;
    } while (cantidad < 0);

    return cantidad;
}

int * create(int qty)
{
    int *numeros;

    numeros = new int[qty];

    srand(time(0));
    for (int i = 0; i < qty; i++)
    {
        *(numeros + i) = rand() % 100 + 1;
    }

    return numeros;
}

void print(int *nums, int qty)
{
    cout << endl;
    for (int i = 0; i < qty; i++)
    {
        cout << nums[i] << endl;
    }
}

