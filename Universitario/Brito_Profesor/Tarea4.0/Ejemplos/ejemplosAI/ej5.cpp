/*5. Vector de estructuras: estudiantes y nota mayor
Este es el siguiente paso de tu ejercicio anterior. Ahora puedes manejar varios estudiantes sin repetir cuatro bloques de instrucciones.

La lógica:
- estudiante guarda temporalmente los datos leídos.
- push_back(estudiante) añade una copia completa al vector.
- estudiantes.at(i).nota obtiene la nota del estudiante situado en i.
- posicionMayor conserva el índice, permitiéndonos consultar también su nombre.
- En caso de empate, conserva al primero.
El ejemplo supone entradas numéricas correctas y que pulses Enter después de cada dato.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Estudiante {
    string matricula;
    string nombre;
    double nota;
};

int main() {
    vector<Estudiante> estudiantes;
    Estudiante estudiante;

    const int CANTIDAD = 3;
    unsigned int i;
    unsigned int posicionMayor = 0;

    for (i = 0; i < CANTIDAD; i++) {
        cout << "\nEstudiante " << i + 1 << endl;

        cout << "Matricula: ";
        getline(cin, estudiante.matricula);

        cout << "Nombre: ";
        getline(cin, estudiante.nombre);

        cout << "Nota: ";
        cin >> estudiante.nota;
        cin.ignore();

        estudiantes.push_back(estudiante);
    }

    cout << "\nMatricula | Nombre | Nota" << endl;

    for (i = 0; i < estudiantes.size(); i++) {
        cout << estudiantes.at(i).matricula << " | "
             << estudiantes.at(i).nombre << " | "
             << estudiantes.at(i).nota << endl;

        if (estudiantes.at(i).nota >
            estudiantes.at(posicionMayor).nota) {

            posicionMayor = i;
        }
    }

    cout << "\nEstudiante con la nota mayor:" << endl;
    cout << estudiantes.at(posicionMayor).nombre << endl;
    cout << "Nota: "
         << estudiantes.at(posicionMayor).nota << endl;

    return 0;
}
