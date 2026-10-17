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
    const int CANTIDAD = 4;
    int numero;
    unsigned int i;

    for (numero = 0; numero < CANTIDAD; numero++) {
        cout << "\nDATOS DEL ESTUDIANTE "
             << numero + 1 << endl;

        cout << "Matricula: ";
        getline(cin, estudiante.matricula);

        cout << "Primer nombre: ";
        getline(cin, estudiante.primernombre);

        cout << "Primer apellido: ";
        getline(cin, estudiante.primerapellido);

        cout << "Edad: ";
        cin >> estudiante.edad;

        cout << "Sexo (F o M): ";
        cin >> estudiante.sexo;

        cout << "Nota final: ";
        cin >> estudiante.notafinal;
        cin.ignore();

        estudiantes.push_back(estudiante);
    }

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
