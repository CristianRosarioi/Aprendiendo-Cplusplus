// Ejemplo: while con contador (suma de numeros ingresados)
#include <iostream>
using namespace std;

int main() {
    int cantidad;
    cout << "Cuantos numeros quiere sumar? ";
    cin >> cantidad;

    int suma = 0;
    int i = 0;

    while (i < cantidad) {
        int num;
        cout << "Numero " << i + 1 << ": ";
        cin >> num;
        suma += num;
        i++;  // no olvidar: evita bucle infinito
    }

    cout << "Suma total: " << suma << endl;
    return 0;
}