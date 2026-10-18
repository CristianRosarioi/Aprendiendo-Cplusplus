/*
Universidad Autónoma de Santo Domingo UASD
Centro UASD San Pedro, Escuela de informatica 5100-29
Introduccion a la Programacion
Cristian Rosario
Matricula: 100806653
*/

#include <iostream>
#include <string>
using namespace std;

struct Estudiantes {
    string matricula;
    string primernombre;
    string primerapellido;
    int edad;
    char sexo;
    double notafinal;
};

Estudiantes estudiantes[4];

int main() {
    cout << "DATOS DEL ESTUDIANTE 1" << endl;

    cout << "Matricula: ";
    getline(cin, estudiantes[0].matricula);

    cout << "Primer nombre: ";
    getline(cin, estudiantes[0].primernombre);

    cout << "Primer apellido: ";
    getline(cin, estudiantes[0].primerapellido);

    cout << "Edad: ";
    cin >> estudiantes[0].edad;

    cout << "Sexo (F o M): ";
    cin >> estudiantes[0].sexo;

    cout << "Nota final: ";
    cin >> estudiantes[0].notafinal;
    cin.ignore();

    cout << "\nDATOS DEL ESTUDIANTE 2" << endl;

    cout << "Matricula: ";
    getline(cin, estudiantes[1].matricula);

    cout << "Primer nombre: ";
    getline(cin, estudiantes[1].primernombre);

    cout << "Primer apellido: ";
    getline(cin, estudiantes[1].primerapellido);

    cout << "Edad: ";
    cin >> estudiantes[1].edad;

    cout << "Sexo (F o M): ";
    cin >> estudiantes[1].sexo;

    cout << "Nota final: ";
    cin >> estudiantes[1].notafinal;
    cin.ignore();

    cout << "\nDATOS DEL ESTUDIANTE 3" << endl;

    cout << "Matricula: ";
    getline(cin, estudiantes[2].matricula);

    cout << "Primer nombre: ";
    getline(cin, estudiantes[2].primernombre);

    cout << "Primer apellido: ";
    getline(cin, estudiantes[2].primerapellido);

    cout << "Edad: ";
    cin >> estudiantes[2].edad;

    cout << "Sexo (F o M): ";
    cin >> estudiantes[2].sexo;

    cout << "Nota final: ";
    cin >> estudiantes[2].notafinal;
    cin.ignore();

    cout << "\nDATOS DEL ESTUDIANTE 4" << endl;

    cout << "Matricula: ";
    getline(cin, estudiantes[3].matricula);

    cout << "Primer nombre: ";
    getline(cin, estudiantes[3].primernombre);

    cout << "Primer apellido: ";
    getline(cin, estudiantes[3].primerapellido);

    cout << "Edad: ";
    cin >> estudiantes[3].edad;

    cout << "Sexo (F o M): ";
    cin >> estudiantes[3].sexo;

    cout << "Nota final: ";
    cin >> estudiantes[3].notafinal;

    cout << "\nLista de los estudiantes:" << endl;
    cout << "Matricula | Nombre | Apellido | Edad | Sexo | Nota" << endl;
    cout << "------------------------------------------------" << endl;

    for (int i = 0; i < 4; i++) {
        cout << estudiantes[i].matricula << " | "
             << estudiantes[i].primernombre << " | "
             << estudiantes[i].primerapellido << " | "
             << estudiantes[i].edad << " | "
             << estudiantes[i].sexo << " | "
             << estudiantes[i].notafinal << endl;
    }

    double notamayor = estudiantes[0].notafinal;

    for (int i = 1; i < 4; i++) {
        if (estudiantes[i].notafinal > notamayor) {
            notamayor = estudiantes[i].notafinal;
        }
    }

    cout << "\nLA NOTA MAYOR ES: " << notamayor << endl;

    return 0;
}
