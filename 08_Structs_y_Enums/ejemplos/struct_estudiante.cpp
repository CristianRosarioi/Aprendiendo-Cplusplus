// Ejemplo: struct Estudiante
#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
};

int main() {
    Estudiante e1;
    e1.nombre = "Cristian";
    e1.edad = 20;
    e1.promedio = 8.5;

    Estudiante e2 = {"Ana", 19, 9.2};

    cout << "Estudiante 1: " << e1.nombre << " (" << e1.edad << " anos, promedio " << e1.promedio << ")" << endl;
    cout << "Estudiante 2: " << e2.nombre << " (" << e2.edad << " anos, promedio " << e2.promedio << ")" << endl;
    return 0;
}