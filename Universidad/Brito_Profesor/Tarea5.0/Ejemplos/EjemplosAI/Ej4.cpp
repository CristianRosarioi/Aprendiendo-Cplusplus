#include <iostream>
#include <iomanip>
using namespace std;

double calcularPromedio(double n1, double n2, double n3) {
    double promedio;

    promedio = (n1 + n2 + n3) / 3.0;

    return promedio;
}

int main() {
    double nota1, nota2, nota3;
    double promedioFinal;

    cout << "Introduzca la primera nota: ";
    cin >> nota1;

    cout << "Introduzca la segunda nota: ";
    cin >> nota2;

    cout << "Introduzca la tercera nota: ";
    cin >> nota3;

    promedioFinal = calcularPromedio(nota1, nota2, nota3);

    cout << fixed << setprecision(2);
    cout << "Promedio final: " << promedioFinal << endl;

    return 0;
}