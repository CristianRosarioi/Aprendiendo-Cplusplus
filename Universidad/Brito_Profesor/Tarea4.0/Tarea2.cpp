/*
Universidad Autónoma de Santo Domingo UASD
Centro UASD San Pedro, Escuela de informatica 5100-29
Introduccion a la Programacion
Cristian Rosario
Matricula: 100806653
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    const int CANTIDAD = 7;

    vector<long> empId(CANTIDAD);
    vector<int> horas(CANTIDAD);
    vector<double> tarifaPorHora(CANTIDAD);
    vector<double> salarioBruto(CANTIDAD);

    int i;

    // Identificaciones iniciales.
    empId.at(0) = 5658845;
    empId.at(1) = 4520125;
    empId.at(2) = 7895122;
    empId.at(3) = 8777541;
    empId.at(4) = 8451277;
    empId.at(5) = 1302850;
    empId.at(6) = 7580489;

    cout << fixed << setprecision(2);

    // Captura y calculo de los datos.
    for (i = 0; i < CANTIDAD; i++) {
        cout << "\nEmpleado: " << empId.at(i) << endl;

        cout << "Horas trabajadas: ";
        cin >> horas.at(i);

        while (horas.at(i) < 0) {
            cout << "Las horas no pueden ser negativas." << endl;
            cout << "Ingrese las horas nuevamente: ";
            cin >> horas.at(i);
        }

        cout << "Tarifa por hora: ";
        cin >> tarifaPorHora.at(i);

        while (tarifaPorHora.at(i) < 50.00) {
            cout << "La tarifa debe ser de al menos 50.00." << endl;
            cout << "Ingrese la tarifa nuevamente: ";
            cin >> tarifaPorHora.at(i);
        }

        salarioBruto.at(i) = horas.at(i) * tarifaPorHora.at(i);
    }

    // Mostrar resultados despues de capturar todos los empleados.
    cout << "\nSALARIOS DE LOS EMPLEADOS" << endl;
    cout << "Identificacion | Salario bruto" << endl;
    cout << "-----------------------------" << endl;

    for (i = 0; i < CANTIDAD; i++) {
        cout << empId.at(i) << "        | "
             << salarioBruto.at(i) << endl;
    }

    return 0;
}
