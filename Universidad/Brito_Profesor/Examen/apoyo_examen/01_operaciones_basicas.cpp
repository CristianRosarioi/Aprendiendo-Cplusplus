/*
Enunciado: Leer dos enteros y mostrar suma, resta, producto, cocientes y residuo.
Conceptos: int, double, operadores + - * / %, cin, cout, if y división.
Algoritmo: 1) Leer dos números. 2) Mostrar tres operaciones sin división.
3) Si el divisor no es cero, mostrar cociente y residuo; si lo es, avisar.
Ejemplo: entrada 10 y 3 -> suma 13, resta 7, producto 30,
división entera 3, división decimal 3.33333 aprox., residuo 1.
Se supone que la entrada tiene el tipo solicitado y las operaciones caben en int.
*/
#include <iostream>
using namespace std;

int main() {
    int primero; // Primer operando, leído antes de hacer las cuentas.
    int segundo; // Segundo operando; también será el divisor.
    cout << "Primer entero: ";
    cin >> primero;
    cout << "Segundo entero: ";
    cin >> segundo;

    cout << "Suma: " << primero + segundo << endl;
    cout << "Resta: " << primero - segundo << endl;
    cout << "Producto: " << primero * segundo << endl;
    // == pregunta igualdad; = asignaría un valor. El cero no puede dividir.
    if (segundo != 0) {
        cout << "Division entera: " << primero / segundo << endl;
        // Convertir ANTES de / produce un cociente double con decimales.
        double cocienteDecimal = static_cast<double>(primero) / segundo;
        cout << "Division decimal: " << cocienteDecimal << endl;
        // % calcula lo que sobra al dividir enteros: 10 % 3 vale 1.
        cout << "Residuo: " << primero % segundo << endl;
    } else {
        cout << "No se puede dividir ni obtener residuo entre cero." << endl;
    }
    // / con dos int trunca la parte decimal: 10 / 3 da 3.
    return 0;
}
