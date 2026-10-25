/* Los números primos son aquellos números divisibles solamente entre 1
 y ellos mismos, por ejemplo: 23, 17, 19, 7. Diseñar un programa que
 imprima todos los números primos que existen entre 30 y 300. */

#include <iostream>
using namespace std;

int main () {
    for (int numero = 30; numero <= 300; numero++) {
        bool esPrimo = true;

        for (int divisor = 2; divisor <= numero / divisor; divisor++) {
            if (numero % divisor == 0) {
                esPrimo = false;
                break;
            }
        }

        if (esPrimo) {
            cout << numero << " ";
        }
    }

    cout << endl;
    return 0;
}
