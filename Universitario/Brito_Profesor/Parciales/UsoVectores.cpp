#include <iostream>
#include <string>
#include <vector>
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
    vector<Estudiantes> estudiantes;
    Estudiantes estudiante;
    unsigned int i;

    // Primer estudiante.
    estudiante.matricula = "121128";
    estudiante.primernombre = "Cristian";
    estudiante.primerapellido = "Rosario";
    estudiante.edad = 29;
    estudiante.sexo = 'M';
    estudiante.notafinal = 84;
    estudiantes.push_back(estudiante);

    // Segundo estudiante.
    estudiante.matricula = "212321";
    estudiante.primernombre = "Manuel";
    estudiante.primerapellido = "martinez";
    estudiante.edad = 36;
    estudiante.sexo = 'M';
    estudiante.notafinal = 93;
    estudiantes.push_back(estudiante);

    // Tercer estudiante.
    estudiante.matricula = "323651";
    estudiante.primernombre = "Madelin";
    estudiante.primerapellido = "Baez";
    estudiante.edad = 19;
    estudiante.sexo = 'F';
    estudiante.notafinal = 78;
    estudiantes.push_back(estudiante);

    // Cuarto estudiante.
    estudiante.matricula = "214659";
    estudiante.primernombre = "Esther";
    estudiante.primerapellido = "Beltre";
    estudiante.edad = 18;
    estudiante.sexo = 'F';
    estudiante.notafinal = 71;
    estudiantes.push_back(estudiante);

    cout << "\nLista de los estudiantes:" << endl;
    cout << "Matricula | Nombre | Apellido | Edad | Sexo | Nota" << endl;
    cout << "------------------------------------------------" << endl;

    for (i = 0; i < estudiantes.size(); i++) {
        cout << estudiantes.at(i).matricula << " | "
             << estudiantes.at(i).primernombre << " | "
             << estudiantes.at(i).primerapellido << " | "
             << estudiantes.at(i).edad << " | "
             << estudiantes.at(i).sexo << " | "
             << estudiantes.at(i).notafinal << endl;
    }

    double notamayor = estudiantes.at(0).notafinal;

    for (i = 1; i < estudiantes.size(); i++) {
        if (estudiantes.at(i).notafinal > notamayor) {
            notamayor = estudiantes.at(i).notafinal;
        }
    }

    cout << "\nLA NOTA MAYOR ES: " << notamayor << endl;

    return 0;
}