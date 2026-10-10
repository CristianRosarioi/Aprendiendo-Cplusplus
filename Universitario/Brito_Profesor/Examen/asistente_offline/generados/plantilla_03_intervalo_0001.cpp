/*
Enunciado: Solicitar un intervalo con inicio estrictamente menor al final.
Algoritmo: leer extremos; mientras inicio >= final, volver a leer ambos.
Ejemplo: entrada 8 8, luego 2 5 -> Intervalo valido: 2 5
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
using namespace std;

int main() {
    int inicio, final; // Dos extremos leidos por teclado.
    cout << "Inicio y final: "; cin >> inicio >> final;
    while (inicio >= final) { // Igualdad e inversion son invalidas.
        cout << "Intervalo invalido. Escriba ambos otra vez: ";
        cin >> inicio >> final; // El ciclo termina cuando inicio < final.
    }
    cout << "Intervalo valido: " << inicio << " " << final << endl;
    return 0;
}
