#include <iostream>

using namespace std;

int suma(int, int);
int suma(int [], int);

int main(int argc, char** argv)
{
    int arreglo[5] = {23, 4, 56, 1, -9};

    cout << suma(4, 5) << endl;
    cout << suma(arreglo, 5) << endl;

    return 0;
}

int suma(int a, int b)
{
    return a + b;
}

int suma(int arr[], int cantidad)
{
    int total = 0;
    for (int i = 0; i < cantidad; i++)
        total += arr[i];
    return total;
}
