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

int main() {
    Estudiantes estudiantes[4];

    // Estudiante 0
    estudiantes[0].matricula = "121128";
    estudiantes[0].primernombre = "Cristian";
    estudiantes[0].primerapellido = "Rosario";
    estudiantes[0].edad = 29;
    estudiantes[0].sexo = 'M';
    estudiantes[0].notafinal = 84;

    // Estudiante 1
    estudiantes[1].matricula = "212321";
    estudiantes[1].primernombre = "Manuel";
    estudiantes[1].primerapellido = "martinez";
    estudiantes[1].edad = 36;
    estudiantes[1].sexo = 'M';
    estudiantes[1].notafinal = 93;

    // Estudiante 2
    estudiantes[2].matricula = "323651";
    estudiantes[2].primernombre = "Madelin";
    estudiantes[2].primerapellido = "Baez";
    estudiantes[2].edad = 19;
    estudiantes[2].sexo = 'F';
    estudiantes[2].notafinal = 78;

    // Estudiante 3
    estudiantes[3].matricula = "214659";
    estudiantes[3].primernombre = "Esther";
    estudiantes[3].primerapellido = "Beltre";
    estudiantes[3].edad = 18;
    estudiantes[3].sexo = 'F';
    estudiantes[3].notafinal = 71;

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

