/*6. Matriz: leer una tabla y sumar cada fila
Practica dos dimensiones y ciclos anidados.

Si introduces 10, 20, 30, 40, 50, 60, mostrará:
10 20 30 | Suma: 60
40 50 60 | Suma: 150

La lógica: el ciclo exterior selecciona la fila y el interior recorre sus columnas. sumaFila = 0 se ejecuta al comenzar cada fila para no mezclar sus totales.*/

#include <iostream>
using namespace std;

int main() {
    const int FILAS = 2;
    const int COLUMNAS = 3;

    double tabla[FILAS][COLUMNAS];
    double sumaFila;
    int fila;
    int columna;

    for (fila = 0; fila < FILAS; fila++) {
        for (columna = 0; columna < COLUMNAS; columna++) {
            cout << "Valor de fila " << fila + 1
                 << ", columna " << columna + 1 << ": ";

            cin >> tabla[fila][columna];
        }
    }

    cout << "\nTabla y suma de cada fila:" << endl;

    for (fila = 0; fila < FILAS; fila++) {
        sumaFila = 0;

        for (columna = 0; columna < COLUMNAS; columna++) {
            cout << tabla[fila][columna] << " ";
            sumaFila += tabla[fila][columna];
        }

        cout << "| Suma: " << sumaFila << endl;
    }

    return 0;
}
