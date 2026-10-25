/*
Enunciado: Leer N enteros y contar positivos, negativos y ceros.
Algoritmo: validar N positivo; leer N valores; sumar sus valores y contar
cada signo con condiciones excluyentes.
Ejemplo: entrada 4 y luego 2 -3 0 5 -> positivos 2, negativos 1, ceros 1, suma 4
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
using namespace std;

int main() {
    int cantidad; // Numero de lecturas que se realizaran.
    int positivos = 0, negativos = 0, ceros = 0; // Contadores en cero.
    int suma = 0; // Acumulador en cero: elemento neutro de la suma.
    cout << "Cantidad positiva: "; cin >> cantidad;
    while (cantidad <= 0) {
        cout << "Debe ser positiva. Otra cantidad: "; cin >> cantidad;
    }
    for (int i = 0; i < cantidad; i++) { // N lecturas, desde 0 hasta N-1.
        int numero; // Valor actual; se lee antes de usarlo.
        cout << "Numero: "; cin >> numero;
        suma += numero; // Acumula el valor, no solamente uno.
        if (numero > 0) { positivos++; }
        else if (numero < 0) { negativos++; }
        else { ceros++; } // Cada dato pertenece a una sola categoria.
    }
    cout << "Positivos: " << positivos << ", negativos: " << negativos
         << ", ceros: " << ceros << ", suma: " << suma << endl;
    return 0;
}
