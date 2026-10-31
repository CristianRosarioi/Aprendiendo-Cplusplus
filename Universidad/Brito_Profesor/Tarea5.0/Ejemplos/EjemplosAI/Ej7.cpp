#include <iostream>
#include <vector>
using namespace std;

// Prototipo
double calcularPromedio(vector<double> notas);

int main() {
    vector<double> notas(5);

    double promedio;

    for (unsigned int i = 0; i < notas.size(); i++) {
        cout << "Introduzca la nota " << i + 1 << ": ";
        cin >> notas.at(i);
    }

    promedio = calcularPromedio(notas);

    cout << "El promedio es: " << promedio << endl;

    return 0;
}

// Definicion de la funcion
double calcularPromedio(vector<double> notas) {
    double suma = 0;

    for (unsigned int i = 0; i < notas.size(); i++) {
        suma += notas.at(i);
    }

    return suma / notas.size();
}