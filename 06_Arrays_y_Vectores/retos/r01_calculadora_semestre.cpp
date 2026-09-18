/* Reto: "Calculadora de Semestre Universitario"
Escribe un programa que:
1. Declare un arreglo de 4 posiciones para guardar las calificaciones de 4 materias: float notas[4];.
2. Use un bucle for para pedirle al usuario cada una de las 4 notas:
   Por ejemplo: Ingrese la calificacion de la materia 1: , ...materia 2: , etc.
3. Dentro de ese bucle, acumule la suma de todas las notas en una variable: float suma = 0;.
4. Calcule el promedio general dividiendo la suma entre 4: promedio = suma / 4.0;.
5. Muestre:
   - La lista de las 4 notas ingresadas.
   - El promedio final del semestre.
   - La letra correspondiente (A, B, C o F) segun ese promedio. */

#include <iostream>
using namespace std;

int main() {
    const int TOTAL = 4;
    float notas[TOTAL];
    float suma = 0.0;
    float promedio;

    for (int i = 0; i < TOTAL; i++) {
        cout << "Ingrese la calificacion de la materia " << i + 1 << ": ";
        cin >> notas[i];
        suma += notas[i];
    }

    promedio = suma / TOTAL;

    cout << "\n--- Notas del semestre ---" << endl;
    for (int i = 0; i < TOTAL; i++) {
        cout << "Materia " << i + 1 << ": " << notas[i] << endl;
    }

    cout << "Promedio final: " << promedio << endl;

    char letra;
    if (promedio >= 90) {
        letra = 'A';
    } else if (promedio >= 80) {
        letra = 'B';
    } else if (promedio >= 70) {
        letra = 'C';
    } else {
        letra = 'F';
    }

    cout << "Calificacion: " << letra << endl;

    return 0;
}