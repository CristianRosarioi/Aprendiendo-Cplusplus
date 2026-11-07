#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Estructura de estudiantes
struct Estudiante {
    string nombre;
    int edad;
    double nota;
};

// Prototipos de las funciones
void mostrarMenu();
bool estaAprobado(double nota);
double obtenerMayor(double nota1, double nota2);

int main() {

    Estudiante estudiantes[5];

    int opcion;
    int aprobados;
    double suma;
    double promedio;
    double mayor;

    cout << fixed << setprecision(2);

    // Registrar los cinco estudiantes
    for (int i = 0; i < 5; i++) {

        cout << "\nESTUDIANTE " << i + 1 << endl;

        cout << "Nombre: ";
        cin >> estudiantes[i].nombre;

        cout << "Edad: ";
        cin >> estudiantes[i].edad;

        while (estudiantes[i].edad <= 0) {
            cout << "Edad invalida. Introduzca otra: ";
            cin >> estudiantes[i].edad;
        }

        cout << "Nota final: ";
        cin >> estudiantes[i].nota;

        while (estudiantes[i].nota < 0 ||
               estudiantes[i].nota > 100) {

            cout << "Nota invalida. Introduzca otra: ";
            cin >> estudiantes[i].nota;
        }
    }

    do {
        mostrarMenu();

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:
                cout << "\nLISTA DE ESTUDIANTES" << endl;

                for (int i = 0; i < 5; i++) {

                    cout << "\nNombre: "
                         << estudiantes[i].nombre << endl;

                    cout << "Edad: "
                         << estudiantes[i].edad << endl;

                    cout << "Nota: "
                         << estudiantes[i].nota << endl;

                    if (estaAprobado(estudiantes[i].nota)) {
                        cout << "Estado: Aprobado" << endl;
                    } else {
                        cout << "Estado: Reprobado" << endl;
                    }
                }
                break;

            case 2:
                suma = 0;
                aprobados = 0;
                mayor = estudiantes[0].nota;

                for (int i = 0; i < 5; i++) {

                    suma += estudiantes[i].nota;

                    mayor = obtenerMayor(
                        mayor, estudiantes[i].nota
                    );

                    if (estaAprobado(estudiantes[i].nota)) {
                        aprobados++;
                    }
                }

                promedio = suma / 5;

                cout << "\nESTADISTICAS" << endl;
                cout << "Promedio: " << promedio << endl;
                cout << "Nota mayor: " << mayor << endl;
                cout << "Aprobados: " << aprobados << endl;
                cout << "Reprobados: " << 5 - aprobados << endl;
                break;

            case 0:
                cout << "Programa finalizado." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 0);

    return 0;
}

// Funcion que muestra el menu
void mostrarMenu() {

    cout << "\n===== CONTROL DE CALIFICACIONES =====" << endl;
    cout << "1. Mostrar estudiantes" << endl;
    cout << "2. Calcular estadisticas" << endl;
    cout << "0. Salir" << endl;
}

// Funcion que verifica si aprobo
bool estaAprobado(double nota) {

    if (nota >= 70) {
        return true;
    }

    return false;
}

// Funcion que devuelve la nota mayor
double obtenerMayor(double nota1, double nota2) {

    if (nota1 > nota2) {
        return nota1;
    } else {
        return nota2;
    }
}