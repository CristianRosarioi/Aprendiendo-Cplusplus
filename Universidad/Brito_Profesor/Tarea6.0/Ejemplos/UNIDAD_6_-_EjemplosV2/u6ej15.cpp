#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double * redim(double[], int, int);
void print(double *, int);

int main(int argc, char** argv)
{
    double arreglo[] = {23, 45, 98, 78, 69};

    double * arr = redim(arreglo, 5, 5);
    print(arr, 10);


    return 0;
}

double * redim(double arr[], int len, int more)
{
    double * new_array = new double[len + more];

    for (int i = 0; i < len; i++)
        new_array[i] = arr[i];

    for (int i = len + 1; i < more; i++)
        new_array[i] = 0;

    return new_array;
}

void print(double * arr, int len)
{
    /*
    for (int i = 0; i < len; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }*/

    for (int i = 0; i < len; i++)
    {
        //cout << "i: " << *arr++ << endl;
        cout << i << ": " << *(arr + i) << " ==> ";
        cout << (arr + i) << endl;
    }
}
