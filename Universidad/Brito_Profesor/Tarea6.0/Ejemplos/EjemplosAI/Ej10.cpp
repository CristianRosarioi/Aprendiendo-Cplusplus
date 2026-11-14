#include <iostream>
#include <string>
using namespace std;

// Estructura
struct Estudiante {
    string nombre;
    int edad;
    double nota;
};

int main() {

    Estudiante alumno;

    // Puntero a la estructura
    Estudiante *ptr = &alumno;

    // Registrar los datos
    cout << "Nombre: ";
    cin >> ptr->nombre;

    cout << "Edad: ";
    cin >> ptr->edad;

    cout << "Nota: ";
    cin >> ptr->nota;

    // Mostrar los datos
    cout << "\nDATOS DEL ESTUDIANTE" << endl;

    cout << "Nombre: " << ptr->nombre << endl;
    cout << "Edad: " << ptr->edad << endl;
    cout << "Nota: " << ptr->nota << endl;

    // Verificar si aprobo
    if (ptr->nota >= 70) {

        cout << "Estado: Aprobado" << endl;

    } else {

        cout << "Estado: Reprobado" << endl;
    }

    return 0;
}