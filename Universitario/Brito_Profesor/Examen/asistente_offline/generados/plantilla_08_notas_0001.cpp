/*
Enunciado: Promediar solo notas aprobadas.
Algoritmo: leer cantidad positiva; leer notas, filtrar si procede;
sumar y contar; dividir solo si la cantidad seleccionada es positiva.
Ejemplo: umbral 70, entrada 2 notas: 70 70 -> promedio 70
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
using namespace std;

int main() {
    int cantidad; // Numero de notas que se leeran.
    int suma = 0, seleccionadas = 0; // Acumulador y contador empiezan en 0.
    cout << "Cantidad positiva de notas: "; cin >> cantidad;
    while (cantidad <= 0) {
        cout << "Debe ser positiva. Otra cantidad: "; cin >> cantidad;
    }
    for (int i = 0; i < cantidad; i++) {
        int nota; // Nota de esta iteracion (se supone entre 0 y 100).
        cout << "Nota: "; cin >> nota;
        if (nota >= 70) { // Solo las aprobadas.
            suma += nota; seleccionadas++;
        }
    }
    if (seleccionadas == 0) {
        cout << "No hay notas seleccionadas; no existe promedio." << endl;
    } else {
        // Convertir antes de / evita perder decimales por division entera.
        double promedio = static_cast<double>(suma) / seleccionadas;
        cout << "Promedio: " << promedio << endl;
    }
    return 0;
}
