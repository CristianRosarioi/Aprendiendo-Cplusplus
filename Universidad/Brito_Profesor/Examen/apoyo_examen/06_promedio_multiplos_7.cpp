/*
Enunciado: Promediar los múltiplos de 7 de [inicio, final], con inicio < final.
Conceptos: validación, while, %, contador, acumulador, promedio decimal.
Algoritmo: 1) Pedir extremos hasta que sean válidos. 2) Recorrer
inclusive desde inicio hasta final; acumular los divisibles por 7.
3) Si hubo alguno, dividir suma entre cantidad; si no, informar.
Ejemplo: entrada 7 16 -> (7 + 14) / 2 = 10.5.
Se suponen enteros en rangos habituales y suma representable en int.
*/
#include <iostream>
using namespace std;

int main() {
    int inicio; // Primer número que será examinado.
    int final;  // Último número que también será examinado.
    int actual; // Avanza de uno en uno sin pasar del final.
    int cantidad = 0; // Cuenta SOLO los múltiplos encontrados.
    int suma = 0;     // Acumula sus valores, no todos los del intervalo.
    cout << "Inicio y final (inicio < final): ";
    cin >> inicio >> final;
    while (inicio >= final) {
        cout << "Intervalo invalido. Escriba ambos otra vez: ";
        cin >> inicio >> final;
    }

    actual = inicio; // = asigna el punto de partida; == compara igualdad.
    while (actual <= final) { // <= incluye el límite final.
        if (actual % 7 == 0) { // % da el residuo; cero indica múltiplo.
            suma += actual; // Agrega el valor al total anterior.
            cantidad++;     // Agrega uno a la cantidad de hallazgos.
        }
        // Evita incrementar int si final es su mayor valor representable.
        if (actual == final) {
            break;
        }
        actual++; // El progreso garantiza que el ciclo termina.
    }
    if (cantidad == 0) {
        cout << "No hay multiplos de 7; no existe promedio." << endl;
    } else {
        // Convertir antes de dividir evita que int / int pierda decimales.
        double promedio = static_cast<double>(suma) / cantidad;
        cout << "Cantidad: " << cantidad << ", suma: " << suma
             << ", promedio: " << promedio << endl;
    }
    return 0;
}
