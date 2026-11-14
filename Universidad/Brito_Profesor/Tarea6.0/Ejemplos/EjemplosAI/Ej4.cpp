#include <iostream>
using namespace std;

int main() {

    int numeros[5] = {10, 20, 30, 40, 50};

    int *ptr = numeros;

    cout << "NUMEROS DEL ARREGLO" << endl;

    for (int i = 0; i < 5; i++) {

        cout << *(ptr + i) << endl;
    }

    return 0;
}