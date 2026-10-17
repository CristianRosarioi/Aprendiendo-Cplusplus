/*4. Iteradores: mostrar y modificar los elementos
Practica vector<int>::iterator, begin(), end() y *iter.

La lógica: iter señala una posición; *iter permite leer o modificar el valor señalado. Antes del segundo recorrido, volvemos a colocar el iterador al principio.*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros;
    vector<int>::iterator iter;

    numeros.push_back(5);
    numeros.push_back(10);
    numeros.push_back(15);

    iter = numeros.begin();

    while (iter != numeros.end()) {
        *iter = *iter * 2;
        iter++;
    }

    cout << "Numeros multiplicados por dos:" << endl;

    iter = numeros.begin();

    while (iter != numeros.end()) {
        cout << *iter << endl;
        iter++;
    }

    return 0;
}