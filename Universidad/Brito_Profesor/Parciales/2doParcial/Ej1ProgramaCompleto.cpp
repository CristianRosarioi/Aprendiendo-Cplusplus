
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Estructura para los datos del estudiante
struct Estudiante {
    long matricula;
    string nombre;
    string apellido;
    int edad;
    double notaFinal;
};

// Prototipos de las funciones
void mostrarMenu();
void registrar(vector<Estudiante> &estudiantes);
void mostrarEstudiantes(vector<Estudiante> &estudiantes);
void calcularEstadisticas(vector<Estudiante> &estudiantes);
void buscarEstudiante(vector<Estudiante> &estudiantes);

int main() {

    vector<Estudiante> estudiantes;

    int opcion;

    cout << fixed << setprecision(2);

    do {
        mostrarMenu();

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        while (opcion < 0 || opcion > 4) {
            cout << "Opcion invalida. Intente otra vez: ";
            cin >> opcion;
        }

        switch (opcion) {

            case 1:
                registrar(estudiantes);
                break;

            case 2:
                mostrarEstudiantes(estudiantes);
                break;

            case 3:
                calcularEstadisticas(estudiantes);
                break;

            case 4:
                buscarEstudiante(estudiantes);
                break;

            case 0:
                cout << "Programa finalizado." << endl;
                break;
        }

    } while (opcion != 0);

    return 0;
}

// Funcion para mostrar el menu
void mostrarMenu() {

    cout << "\n===== CONTROL DE ESTUDIANTES =====" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Mostrar estudiantes" << endl;
    cout << "3. Calcular estadisticas" << endl;
    cout << "4. Buscar por matricula" << endl;
    cout << "0. Salir" << endl;
}

// Funcion para registrar estudiantes
void registrar(vector<Estudiante> &estudiantes) {

    Estudiante nuevo;
    bool repetida = false;

    // Limitar la cantidad de estudiantes
    if (estudiantes.size() >= 5) {
        cout << "No puede registrar mas estudiantes." << endl;
        return;
    }

    cout << "\nREGISTRO DE ESTUDIANTE" << endl;

    cout << "Matricula: ";
    cin >> nuevo.matricula;

    // Comprobar si la matricula ya existe
    for (unsigned int i = 0; i < estudiantes.size(); i++) {

        if (estudiantes.at(i).matricula == nuevo.matricula) {
            repetida = true;
        }
    }

    if (repetida == true) {
        cout << "Esta matricula ya esta registrada." << endl;
        return;
    }

    cout << "Nombre: ";
    cin >> nuevo.nombre;

    cout << "Apellido: ";
    cin >> nuevo.apellido;

    cout << "Edad: ";
    cin >> nuevo.edad;

    while (nuevo.edad <= 0) {
        cout << "Edad invalida. Introduzca otra edad: ";
        cin >> nuevo.edad;
    }

    cout << "Nota final: ";
    cin >> nuevo.notaFinal;

    while (nuevo.notaFinal < 0 || nuevo.notaFinal > 100) {
        cout << "Nota invalida. Introduzca otra nota: ";
        cin >> nuevo.notaFinal;
    }

    // Agregar el estudiante al vector
    estudiantes.push_back(nuevo);

    cout << "Estudiante registrado correctamente." << endl;
}

// Funcion para mostrar los registros
void mostrarEstudiantes(vector<Estudiante> &estudiantes) {

    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    cout << "\nLISTA DE ESTUDIANTES" << endl;

    cout << left
         << setw(12) << "Matricula"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << setw(8) << "Edad"
         << setw(10) << "Nota" << endl;

    for (unsigned int i = 0; i < estudiantes.size(); i++) {

        cout << left
             << setw(12) << estudiantes.at(i).matricula
             << setw(15) << estudiantes.at(i).nombre
             << setw(15) << estudiantes.at(i).apellido
             << setw(8) << estudiantes.at(i).edad
             << setw(10) << estudiantes.at(i).notaFinal
             << endl;
    }
}

// Funcion para calcular estadisticas
void calcularEstadisticas(vector<Estudiante> &estudiantes) {

    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    double suma = 0;
    double promedio;
    double mayor = estudiantes.at(0).notaFinal;
    double menor = estudiantes.at(0).notaFinal;

    int aprobados = 0;
    int reprobados = 0;

    for (unsigned int i = 0; i < estudiantes.size(); i++) {

        // Acumular todas las notas
        suma += estudiantes.at(i).notaFinal;

        // Determinar la nota mayor
        if (estudiantes.at(i).notaFinal > mayor) {
            mayor = estudiantes.at(i).notaFinal;
        }

        // Determinar la nota menor
        if (estudiantes.at(i).notaFinal < menor) {
            menor = estudiantes.at(i).notaFinal;
        }

        // Contar aprobados y reprobados
        if (estudiantes.at(i).notaFinal >= 70) {
            aprobados++;
        } else {
            reprobados++;
        }
    }

    promedio = suma / estudiantes.size();

    cout << "\nESTADISTICAS DEL GRUPO" << endl;
    cout << "Cantidad: " << estudiantes.size() << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Nota mayor: " << mayor << endl;
    cout << "Nota menor: " << menor << endl;
    cout << "Aprobados: " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;
}

// Funcion para buscar un estudiante
void buscarEstudiante(vector<Estudiante> &estudiantes) {

    long matriculaBuscada;
    bool encontrado = false;

    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    cout << "Introduzca la matricula a buscar: ";
    cin >> matriculaBuscada;

    for (unsigned int i = 0; i < estudiantes.size(); i++) {

        if (estudiantes.at(i).matricula == matriculaBuscada) {

            cout << "\nESTUDIANTE ENCONTRADO" << endl;

            cout << "Matricula: "
                 << estudiantes.at(i).matricula << endl;

            cout << "Nombre: "
                 << estudiantes.at(i).nombre << endl;

            cout << "Apellido: "
                 << estudiantes.at(i).apellido << endl;

            cout << "Edad: "
                 << estudiantes.at(i).edad << endl;

            cout << "Nota: "
                 << estudiantes.at(i).notaFinal << endl;

            encontrado = true;
            break;
        }
    }

    if (encontrado == false) {
        cout << "No se encontro esa matricula." << endl;
    }
}
