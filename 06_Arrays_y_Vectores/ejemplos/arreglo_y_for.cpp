// Ejemplo: llenar, mostrar y promediar un arreglo con for
#include <iostream>
using namespace std;

int main() {
    const int TOTAL = 4;
    float notas[TOTAL];
    float suma = 0;

    for (int i = 0; i < TOTAL; i++) {
        cout << "Nota " << i + 1 << ": ";
        cin >> notas[i];
        suma += notas[i];
    }

    cout << "\n--- Notas ---" << endl;
    for (int i = 0; i < TOTAL; i++) {
        cout << "Nota " << i + 1 << ": " << notas[i] << endl;
    }

    cout << "Promedio: " << suma / TOTAL << endl;
    return 0;
}