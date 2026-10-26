/*
Universidad Autónoma de Santo Domingo UASD
Centro UASD San Pedro, Escuela de informatica 5100-29
Introduccion a la Programacion
Cristian Rosario
Matricula: 100806653
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Bebida {
    string nombreBebida;
    double precioBebida;
    int cantidadEnMaquina;
};

int main() {
    vector<Bebida> bebidas(5);

    int opcion;
    int posicion;
    unsigned int i;

    double dinero;
    double cambio;
    double totalVentas = 0;

    // Datos iniciales de las cinco bebidas.
    bebidas.at(0).nombreBebida = "Botella de Agua";
    bebidas.at(0).precioBebida = 20.00;
    bebidas.at(0).cantidadEnMaquina = 20;

    bebidas.at(1).nombreBebida = "Coca Cola";
    bebidas.at(1).precioBebida = 25.00;
    bebidas.at(1).cantidadEnMaquina = 20;

    bebidas.at(2).nombreBebida = "Seven Up";
    bebidas.at(2).precioBebida = 25.00;
    bebidas.at(2).cantidadEnMaquina = 20;

    bebidas.at(3).nombreBebida = "Montain Dew";
    bebidas.at(3).precioBebida = 30.00;
    bebidas.at(3).cantidadEnMaquina = 20;

    bebidas.at(4).nombreBebida = "Jugo V8";
    bebidas.at(4).precioBebida = 50.00;
    bebidas.at(4).cantidadEnMaquina = 20;

    cout << fixed << setprecision(2);

    do {
        cout << "\nMAQUINA DE BEBIDAS" << endl;
        cout << fixed << setprecision(2) << left;

        cout << "+--------+----------------------+----------+------------+" << endl;

        cout << "| " << setw(6) << "Opcion"
             << " | " << setw(20) << "Bebida"
             << " | " << setw(8) << "Precio"
             << " | " << setw(10) << "Existencia"
             << " |" << endl;

        cout << "+--------+----------------------+----------+------------+" << endl;

        for (i = 0; i < bebidas.size(); i++) {
            cout << "| " << setw(6) << i + 1
                 << " | " << setw(20) << bebidas.at(i).nombreBebida
                 << " | " << setw(8) << bebidas.at(i).precioBebida
                 << " | " << setw(10) << bebidas.at(i).cantidadEnMaquina
                 << " |" << endl;
        }

        cout << "+--------+----------------------+----------+------------+" << endl;
        cout << "0. Salir" << endl;

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        while (opcion < 0 || opcion > 5) {
            cout << "Opcion invalida. Escriba de 0 a 5: ";
            cin >> opcion;
        }

        if (opcion != 0) {
            posicion = opcion - 1;

            if (bebidas.at(posicion).cantidadEnMaquina == 0) {
                cout << "Esta bebida esta agotada." << endl;
            } else {
                cout << "Bebida seleccionada: "
                     << bebidas.at(posicion).nombreBebida
                     << endl;

                cout << "Introduzca el monto de dinero: ";
                cin >> dinero;

                while (dinero < 20.00 ||
                       dinero < bebidas.at(posicion).precioBebida) {

                    if (dinero < 20.00) {
                        cout << "El monto debe ser de al menos 20.00."
                             << endl;
                    } else {
                        cout << "El monto no alcanza para esta bebida."
                             << endl;
                    }

                    cout << "Introduzca nuevamente el monto: ";
                    cin >> dinero;
                }

                cambio = dinero - bebidas.at(posicion).precioBebida;

                bebidas.at(posicion).cantidadEnMaquina--;

                totalVentas += bebidas.at(posicion).precioBebida;

                cout << "Retire su bebida: "
                     << bebidas.at(posicion).nombreBebida
                     << endl;

                cout << "Su cambio es: " << cambio << endl;
            }
        }

    } while (opcion != 0);

    cout << "\nTotal de dinero recaudado: "
         << totalVentas << endl;

    return 0;
}

