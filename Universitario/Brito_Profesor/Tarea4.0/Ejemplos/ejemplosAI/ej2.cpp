/*2. Vector: añadir números y encontrar el mayor
Practica push_back(), empty(), size() y at()

La lógica: el primer número se toma como referencia y se compara con los demás. No iniciamos mayor en cero: si todos fueran negativos, eso daría un resultado incorrecto.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros;
    int cantidad;
    int numero;
    int mayor;
    int contador;
    unsigned int i;

    cout << "Cantidad de numeros: ";
    cin >> cantidad;

    while (cantidad < 0) {
        cout << "La cantidad no puede ser negativa: ";
        cin >> cantidad;
    }

    for (contador = 0; contador < cantidad; contador++) {
        cout << "Numero " << contador + 1 << ": ";
        cin >> numero;

        numeros.push_back(numero);
    }

    if (numeros.empty()) {
        cout << "No se ingresaron numeros." << endl;
    } else {
        mayor = numeros.at(0);

        for (i = 1; i < numeros.size(); i++) {
            if (numeros.at(i) > mayor) {
                mayor = numeros.at(i);
            }
        }

        cout << "El numero mayor es: " << mayor << endl;
    }

    return 0;
}