#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    double nota;
};

// Prototipo
void mostrarEstudiante(Estudiante alumno);

int main() {
    Estudiante estudiante1;

    cout << "Nombre: ";
    getline(cin, estudiante1.nombre);

    cout << "Edad: ";
    cin >> estudiante1.edad;

    cout << "Nota: ";
    cin >> estudiante1.nota;

    mostrarEstudiante(estudiante1);

    return 0;
}

// Definicion
void mostrarEstudiante(Estudiante alumno) {
    cout << "\nDATOS DEL ESTUDIANTE" << endl;

    cout << "Nombre: " << alumno.nombre << endl;
    cout << "Edad: " << alumno.edad << endl;
    cout << "Nota: " << alumno.nota << endl;
}