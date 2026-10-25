/*
Enunciado: Leer dos enteros y hacer operaciones basicas.
Algoritmo: leer ambos; calcular suma, resta y producto; si el segundo no
es cero, calcular cocientes y residuo.
Ejemplo: entrada 10 3 -> suma 13, division entera 3, residuo 1
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
using namespace std;

int main() {
    int primero, segundo; // Operandos leidos por teclado.
    cout << "Dos enteros: "; cin >> primero >> segundo;
    cout << "Suma: " << primero + segundo << endl;
    cout << "Resta: " << primero - segundo << endl;
    cout << "Producto: " << primero * segundo << endl;
    // == compara; = asigna. Evitamos / y % cuando el divisor es cero.
    if (segundo == 0) {
        cout << "No se puede dividir entre cero." << endl;
    } else {
        cout << "Division entera: " << primero / segundo << endl;
        cout << "Division decimal: " << static_cast<double>(primero) / segundo << endl;
        cout << "Residuo: " << primero % segundo << endl;
    }
    return 0;
}
