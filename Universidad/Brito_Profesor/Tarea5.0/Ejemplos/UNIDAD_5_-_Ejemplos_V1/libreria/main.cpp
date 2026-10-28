#include <iostream>
#include "utils.h"

using namespace std;

int main(int argc, char** argv)
{
    const int SIZE = 5;
    int arr[SIZE] = {25, 36, 8, 99, 45};

    cout << "El mayor es: "
         << mayor(arr, SIZE) << endl;
    cout << "El menor es: "
         << menor(arr, SIZE) << endl;

    return 0;
}
