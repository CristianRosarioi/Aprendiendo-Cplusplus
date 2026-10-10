/*
Enunciado: Mostrar numeros primos en el intervalo elegido.
Algoritmo: leer/definir extremos; probar cada candidato >= 2; contar divisores
entre 2 y numero/2; si no hay ninguno, mostrar el candidato.
Ejemplo: inicio 2, final 10 -> Primos: 2 3 5 7
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
using namespace std;

int main() {
    int inicio; // Primer extremo del intervalo.
    int final;  // Ultimo extremo del intervalo.
    cout << "Inicio y final: ";
    cin >> inicio >> final;
    // Se repite mientras inicio >= final: la igualdad tambien es invalida.
    while (inicio >= final) {
        cout << "Intervalo invalido. Inicio y final otra vez: ";
        cin >> inicio >> final;
    }
    cout << "Primos: ";
    for (int actual = inicio; actual <= final;) {
        if ((true) && actual >= 2) {
            int divisores = 0; // Se reinicia por cada candidato.
            // Basta buscar entre 2 y actual/2: no hay otros divisores propios.
            for (int posible = 2; posible <= actual / 2; posible++) {
                if (actual % posible == 0) { divisores++; }
            }
            if (divisores == 0) { cout << actual << " "; }
        }
        if (actual == final) { break; } // Evita desbordar al avanzar.
        actual++;
    }
    cout << endl;
    return 0;
}
