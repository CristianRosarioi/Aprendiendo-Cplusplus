// Ejemplo: promedio de notas con funcion
#include <iostream>
using namespace std;

double promedio(double a, double b, double c) {
    return (a + b + c) / 3.0;
}

int main() {
    double n1, n2, n3;
    cout << "Ingresa 3 notas: ";
    cin >> n1 >> n2 >> n3;

    cout << "Promedio: " << promedio(n1, n2, n3) << endl;
    return 0;
}