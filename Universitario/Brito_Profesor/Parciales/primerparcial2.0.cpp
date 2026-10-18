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

Estudiantes estudiante1, estudiante2, estudiante3, estudiante4;
double notamayor;

int main() {
    cout << "DATOS DEL ESTUDIANTE 1" << endl;

    cout << "Matricula: ";
    getline(cin, estudiante1.matricula);

    cout << "Primer nombre: ";
    getline(cin, estudiante1.primernombre);

    cout << "Primer apellido: ";
    getline(cin, estudiante1.primerapellido);

    cout << "Edad: ";
    cin >> estudiante1.edad;

    cout << "Sexo (F o M): ";
    cin >> estudiante1.sexo;

    cout << "Nota final: ";
    cin >> estudiante1.notafinal;
    cin.ignore();

    cout << "\nDATOS DEL ESTUDIANTE 2" << endl;

    cout << "Matricula: ";
    getline(cin, estudiante2.matricula);

    cout << "Primer nombre: ";
    getline(cin, estudiante2.primernombre);

    cout << "Primer apellido: ";
    getline(cin, estudiante2.primerapellido);

    cout << "Edad: ";
    cin >> estudiante2.edad;

    cout << "Sexo (F o M): ";
    cin >> estudiante2.sexo;

    cout << "Nota final: ";
    cin >> estudiante2.notafinal;
    cin.ignore();

    cout << "\nDATOS DEL ESTUDIANTE 3" << endl;

    cout << "Matricula: ";
    getline(cin, estudiante3.matricula);

    cout << "Primer nombre: ";
    getline(cin, estudiante3.primernombre);

    cout << "Primer apellido: ";
    getline(cin, estudiante3.primerapellido);

    cout << "Edad: ";
    cin >> estudiante3.edad;

    cout << "Sexo (F o M): ";
    cin >> estudiante3.sexo;

    cout << "Nota final: ";
    cin >> estudiante3.notafinal;
    cin.ignore();

    cout << "\nDATOS DEL ESTUDIANTE 4" << endl;

    cout << "Matricula: ";
    getline(cin, estudiante4.matricula);

    cout << "Primer nombre: ";
    getline(cin, estudiante4.primernombre);

    cout << "Primer apellido: ";
    getline(cin, estudiante4.primerapellido);

    cout << "Edad: ";
    cin >> estudiante4.edad;

    cout << "Sexo (F o M): ";
    cin >> estudiante4.sexo;

    cout << "Nota final: ";
    cin >> estudiante4.notafinal;

    cout << "\nLista de los estudiantes:" << endl;
    cout << "Matricula | Nombre | Apellido | Edad | Sexo | Nota" << endl;
    cout << "------------------------------------------------" << endl;

    cout << estudiante1.matricula << " | "
         << estudiante1.primernombre << " | "
         << estudiante1.primerapellido << " | "
         << estudiante1.edad << " | "
         << estudiante1.sexo << " | "
         << estudiante1.notafinal << endl;

    cout << estudiante2.matricula << " | "
         << estudiante2.primernombre << " | "
         << estudiante2.primerapellido << " | "
         << estudiante2.edad << " | "
         << estudiante2.sexo << " | "
         << estudiante2.notafinal << endl;

    cout << estudiante3.matricula << " | "
         << estudiante3.primernombre << " | "
         << estudiante3.primerapellido << " | "
         << estudiante3.edad << " | "
         << estudiante3.sexo << " | "
         << estudiante3.notafinal << endl;

    cout << estudiante4.matricula << " | "
         << estudiante4.primernombre << " | "
         << estudiante4.primerapellido << " | "
         << estudiante4.edad << " | "
         << estudiante4.sexo << " | "
         << estudiante4.notafinal << endl;

    if (estudiante1.notafinal >= estudiante2.notafinal &&
        estudiante1.notafinal >= estudiante3.notafinal &&
        estudiante1.notafinal >= estudiante4.notafinal) {

        notamayor = estudiante1.notafinal;

    } else if (estudiante2.notafinal >= estudiante1.notafinal &&
               estudiante2.notafinal >= estudiante3.notafinal &&
               estudiante2.notafinal >= estudiante4.notafinal) {

        notamayor = estudiante2.notafinal;

    } else if (estudiante3.notafinal >= estudiante1.notafinal &&
               estudiante3.notafinal >= estudiante2.notafinal &&
               estudiante3.notafinal >= estudiante4.notafinal) {

        notamayor = estudiante3.notafinal;

    } else {
        notamayor = estudiante4.notafinal;
    }

    cout << "\nLA NOTA MAYOR ES: " << notamayor << endl;

    return 0;
}
// prueba de avatar 3.0


