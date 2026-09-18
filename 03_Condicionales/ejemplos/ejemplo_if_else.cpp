// Ejemplo: if / else if / else con notas universitarias
#include <iostream>
using namespace std;

int main() {
    double nota;

    cout << "Ingresa tu nota (0-100): ";
    cin >> nota;

    if (nota < 0 || nota > 100) {
        cout << "Error: nota invalida" << endl;
    } else if (nota >= 90) {
        cout << "Excelente (A)" << endl;
    } else if (nota >= 70) {
        cout << "Aprobado (C)" << endl;
    } else {
        cout << "Reprobado (F)" << endl;
    }
    return 0;
}