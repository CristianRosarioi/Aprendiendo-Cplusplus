// Ejemplo: memoria dinamica (new / delete)
#include <iostream>
using namespace std;

int main() {
    int* num = new int(42);
    cout << "Valor dinamico: " << *num << endl;
    delete num;

    int* arr = new int[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    cout << "Elementos del arreglo dinamico: ";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;

    return 0;
}