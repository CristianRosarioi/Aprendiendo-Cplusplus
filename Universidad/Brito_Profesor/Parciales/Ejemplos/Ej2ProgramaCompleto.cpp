#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Estructura
struct Producto {
    string nombre;
    double precio;
    int cantidad;
};

// Prototipos
void mostrarMenu();
double calcularVenta(double precio, int cantidad);

int main() {

    Producto productos[3];

    int opcion;
    double totalGeneral;

    cout << fixed << setprecision(2);

    // Registrar los productos
    for (int i = 0; i < 3; i++) {

        cout << "\nPRODUCTO " << i + 1 << endl;

        cout << "Nombre: ";
        cin >> productos[i].nombre;

        cout << "Precio: ";
        cin >> productos[i].precio;

        while (productos[i].precio <= 0) {
            cout << "Precio invalido. Intente otra vez: ";
            cin >> productos[i].precio;
        }

        cout << "Cantidad vendida: ";
        cin >> productos[i].cantidad;

        while (productos[i].cantidad < 0) {
            cout << "Cantidad invalida. Intente otra vez: ";
            cin >> productos[i].cantidad;
        }
    }

    do {
        mostrarMenu();

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:
                cout << "\nLISTA DE PRODUCTOS" << endl;

                for (int i = 0; i < 3; i++) {

                    cout << "\nProducto: " << productos[i].nombre
                         << endl;

                    cout << "Precio: " << productos[i].precio
                         << endl;

                    cout << "Cantidad: " << productos[i].cantidad
                         << endl;

                    cout << "Total: "
                         << calcularVenta(productos[i].precio,
                                         productos[i].cantidad)
                         << endl;
                }
                break;

            case 2:
                totalGeneral = 0;

                for (int i = 0; i < 3; i++) {

                    totalGeneral += calcularVenta(
                        productos[i].precio,
                        productos[i].cantidad
                    );
                }

                cout << "\nTotal general de ventas: "
                     << totalGeneral << endl;
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

    cout << "\n===== SISTEMA DE VENTAS =====" << endl;
    cout << "1. Mostrar productos" << endl;
    cout << "2. Calcular total de ventas" << endl;
    cout << "0. Salir" << endl;
}

// Funcion que calcula el total de una venta
double calcularVenta(double precio, int cantidad) {

    double total;

    total = precio * cantidad;

    return total;
}