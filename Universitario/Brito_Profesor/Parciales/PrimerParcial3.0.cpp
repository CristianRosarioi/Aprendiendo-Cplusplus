#include <iostream>
#include <string>
#include <iomanip>
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
    Estudiantes estudiante1 = {"121128", "Cristian", "Rosario", 29, 'M', 84};
    Estudiantes estudiante2 = {"212321", "Manuel", "Martinez", 36, 'M', 93};
    Estudiantes estudiante3 = {"323651", "Madelin", "Baez", 19, 'F', 78};
    Estudiantes estudiante4 = {"214659", "Esther", "Beltre", 18, 'F', 71};

    double notamayor;

    cout << "\nLista de los estudiantes:\n" << endl;

    cout << left << fixed << setprecision(2);

    cout << "+------------+---------------+---------------+--------+--------+----------+"
         << endl;

    cout << "| " << setw(10) << "Matricula"
         << " | " << setw(13) << "Nombre"
         << " | " << setw(13) << "Apellido"
         << " | " << setw(6) << "Edad"
         << " | " << setw(6) << "Sexo"
         << " | " << setw(8) << "Nota"
         << " |" << endl;

    cout << "+------------+---------------+---------------+--------+--------+----------+"
         << endl;

    cout << "| " << setw(10) << estudiante1.matricula
         << " | " << setw(13) << estudiante1.primernombre
         << " | " << setw(13) << estudiante1.primerapellido
         << " | " << setw(6) << estudiante1.edad
         << " | " << setw(6) << estudiante1.sexo
         << " | " << setw(8) << estudiante1.notafinal
         << " |" << endl;

    cout << "| " << setw(10) << estudiante2.matricula
         << " | " << setw(13) << estudiante2.primernombre
         << " | " << setw(13) << estudiante2.primerapellido
         << " | " << setw(6) << estudiante2.edad
         << " | " << setw(6) << estudiante2.sexo
         << " | " << setw(8) << estudiante2.notafinal
         << " |" << endl;

    cout << "| " << setw(10) << estudiante3.matricula
         << " | " << setw(13) << estudiante3.primernombre
         << " | " << setw(13) << estudiante3.primerapellido
         << " | " << setw(6) << estudiante3.edad
         << " | " << setw(6) << estudiante3.sexo
         << " | " << setw(8) << estudiante3.notafinal
         << " |" << endl;

    cout << "| " << setw(10) << estudiante4.matricula
         << " | " << setw(13) << estudiante4.primernombre
         << " | " << setw(13) << estudiante4.primerapellido
         << " | " << setw(6) << estudiante4.edad
         << " | " << setw(6) << estudiante4.sexo
         << " | " << setw(8) << estudiante4.notafinal
         << " |" << endl;

    cout << "+------------+---------------+---------------+--------+--------+----------+"
         << endl;

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
