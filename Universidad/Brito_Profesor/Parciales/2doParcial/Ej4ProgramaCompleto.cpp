#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Estructura de empleados
struct Empleado {
    string nombre;
    double tarifa;
    int horas[7];
};

// Prototipos
void mostrarMenu();
int calcularHoras(Empleado empleado);
double calcularSalario(Empleado empleado);
bool horasValidas(int cantidad);

int main() {

    vector<Empleado> empleados(3);

    int opcion;
    int totalHoras;
    int contador;

    double salario;
    double totalGeneral;
    double salarioMayor;

    string nombreMayor;

    cout << fixed << setprecision(2);

    // Registrar los tres empleados
    for (unsigned int i = 0; i < empleados.size(); i++) {

        cout << "\nEMPLEADO " << i + 1 << endl;

        cout << "Nombre: ";
        cin >> empleados.at(i).nombre;

        cout << "Tarifa por hora: ";
        cin >> empleados.at(i).tarifa;

        while (empleados.at(i).tarifa <= 0) {
            cout << "Tarifa invalida. Intente otra vez: ";
            cin >> empleados.at(i).tarifa;
        }

        // Registrar las horas de los siete dias
        for (int j = 0; j < 7; j++) {

            cout << "Horas del dia " << j + 1 << ": ";
            cin >> empleados.at(i).horas[j];

            while (!horasValidas(empleados.at(i).horas[j])) {
                cout << "Horas invalidas (0 a 12): ";
                cin >> empleados.at(i).horas[j];
            }
        }
    }

    do {
        mostrarMenu();

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        while (opcion < 0 || opcion > 3) {
            cout << "Opcion invalida: ";
            cin >> opcion;
        }

        switch (opcion) {

            case 1:
                cout << "\nREPORTE DE EMPLEADOS" << endl;

                for (unsigned int i = 0; i < empleados.size(); i++) {

                    totalHoras = calcularHoras(empleados.at(i));
                    salario = calcularSalario(empleados.at(i));

                    cout << "\nEmpleado: "
                         << empleados.at(i).nombre << endl;

                    cout << "Horas por dia: ";

                    for (int j = 0; j < 7; j++) {
                        cout << empleados.at(i).horas[j] << " ";
                    }

                    cout << endl;

                    cout << "Total de horas: "
                         << totalHoras << endl;

                    cout << "Tarifa: "
                         << empleados.at(i).tarifa << endl;

                    cout << "Salario semanal: "
                         << salario << endl;
                }
                break;

            case 2:
                totalGeneral = 0;
                contador = 0;

                for (unsigned int i = 0; i < empleados.size(); i++) {

                    salario = calcularSalario(empleados.at(i));

                    totalGeneral += salario;

                    if (salario > 3000) {
                        contador++;
                    }
                }

                cout << "\nTOTAL DE NOMINA" << endl;
                cout << "Total a pagar: "
                     << totalGeneral << endl;

                cout << "Empleados con salario mayor a 3000: "
                     << contador << endl;
                break;

            case 3:
                salarioMayor = calcularSalario(empleados.at(0));
                nombreMayor = empleados.at(0).nombre;

                for (unsigned int i = 1; i < empleados.size(); i++) {

                    salario = calcularSalario(empleados.at(i));

                    if (salario > salarioMayor) {
                        salarioMayor = salario;
                        nombreMayor = empleados.at(i).nombre;
                    }
                }

                cout << "\nEMPLEADO CON MAYOR SALARIO" << endl;
                cout << "Nombre: " << nombreMayor << endl;
                cout << "Salario: " << salarioMayor << endl;
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

    cout << "\n===== CONTROL DE EMPLEADOS =====" << endl;
    cout << "1. Mostrar empleados y salarios" << endl;
    cout << "2. Calcular nomina total" << endl;
    cout << "3. Mostrar empleado con mayor salario" << endl;
    cout << "0. Salir" << endl;
}

// Funcion que calcula el total de horas
int calcularHoras(Empleado empleado) {

    int suma = 0;

    for (int i = 0; i < 7; i++) {
        suma += empleado.horas[i];
    }

    return suma;
}

// Funcion que calcula el salario
double calcularSalario(Empleado empleado) {

    int horasTotales;
    double salario;

    horasTotales = calcularHoras(empleado);

    salario = horasTotales * empleado.tarifa;

    return salario;
}

// Funcion que valida las horas
bool horasValidas(int cantidad) {

    if (cantidad >= 0 && cantidad <= 12) {
        return true;
    }

    return false;
}