
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Prototipos de las funciones
void mostrarNegocio();
void mostrarMenu();
string obtenerPerfume(int opcion);
double obtenerPrecio(int opcion);
void mostrarFactura(int cantidades[]);

int main() {

    int opcion;
    int cantidad;

    // Arreglo que guarda las cantidades compradas
    int cantidades[5] = {0, 0, 0, 0, 0};

    mostrarNegocio();

    do {
        mostrarMenu();

        cout << "\nSeleccione una opcion (0-5): ";
        cin >> opcion;

        // Validar la opcion seleccionada
        while (opcion < 0 || opcion > 5) {
            cout << "Opcion invalida. Seleccione del 0 al 5: ";
            cin >> opcion;
        }

        if (opcion != 0) {

            cout << "\nPerfume seleccionado: "
                 << obtenerPerfume(opcion) << endl;

            cout << "Precio: RD$ "
                 << obtenerPrecio(opcion) << endl;

            cout << "Cantidad que desea comprar: ";
            cin >> cantidad;

            // Validar la cantidad
            while (cantidad <= 0) {
                cout << "Cantidad invalida. Introduzca una cantidad mayor que 0: ";
                cin >> cantidad;
            }

            // Acumular la cantidad del producto seleccionado
            cantidades[opcion - 1] += cantidad;

            cout << "\nProducto agregado a su pedido." << endl;
            cout << "Puede seguir comprando o elegir 0 para finalizar."
                 << endl;
        }

    } while (opcion != 0);

    // Mostrar la factura final
    mostrarFactura(cantidades);

    return 0;
}

// Funcion que muestra los datos del negocio
void mostrarNegocio() {

    cout << "===============================================================" << endl;
    cout << "                       ACCESORIOS MASHIAJ" << endl;
    cout << "                     Tu perfumeria preferida" << endl;
    cout << "===============================================================" << endl;
}

// Funcion que muestra el menu de perfumes
void mostrarMenu() {

    cout << fixed << setprecision(2);

    cout << "\n                      MENU DE PERFUMES\n" << endl;

    cout << "+--------+------------------------------------------+------------+" << endl;

    cout << "| " << left << setw(6) << "Opcion"
         << " | " << setw(40) << "Perfume"
         << " | " << right << setw(10) << "Precio RD$"
         << " |" << endl;

    cout << "+--------+------------------------------------------+------------+" << endl;

    for (int i = 1; i <= 5; i++) {

        cout << "| " << left << setw(6) << i
             << " | " << setw(40) << obtenerPerfume(i)
             << " | " << right << setw(10) << obtenerPrecio(i)
             << " |" << endl;
    }

    cout << "+--------+------------------------------------------+------------+" << endl;
    cout << "0. Finalizar compra" << endl;
}

// Funcion que devuelve el nombre del perfume
string obtenerPerfume(int opcion) {

    switch (opcion) {

        case 1:
            return "One Million 3.4 oz";

        case 2:
            return "Armani Acqua di Gio 3.4 oz";

        case 3:
            return "Dolce Gabbana Light Blue 4.2 oz";

        case 4:
            return "Nautica Voyage 3.4 oz";

        case 5:
            return "Valentino Born in Roma 3.4 oz";

        default:
            return "Perfume no encontrado";
    }
}

// Funcion que devuelve el precio del perfume
double obtenerPrecio(int opcion) {

    switch (opcion) {

        case 1:
            return 5000.00;

        case 2:
            return 7500.00;

        case 3:
            return 4200.00;

        case 4:
            return 2500.00;

        case 5:
            return 6500.00;

        default:
            return 0;
    }
}

// Funcion que genera la factura
void mostrarFactura(int cantidades[]) {

    double subtotal = 0;
    double itbis;
    double totalGeneral;
    double importe;

    int totalUnidades = 0;

    cout << "\n\n===============================================================" << endl;
    cout << "                       ACCESORIOS MASHIAJ" << endl;
    cout << "                         FACTURA DE COMPRA" << endl;
    cout << "===============================================================" << endl;

    cout << fixed << setprecision(2);

    cout << left
         << setw(36) << "Perfume"
         << right << setw(10) << "Cantidad"
         << setw(12) << "Precio"
         << setw(14) << "Importe" << endl;

    cout << "------------------------------------------------------------------------" << endl;

    // Recorrer los cinco perfumes
    for (int i = 0; i < 5; i++) {

        // Mostrar solamente los perfumes comprados
        if (cantidades[i] > 0) {

            importe = cantidades[i] * obtenerPrecio(i + 1);

            cout << left << setw(36) << obtenerPerfume(i + 1)
                 << right << setw(10) << cantidades[i]
                 << setw(12) << obtenerPrecio(i + 1)
                 << setw(14) << importe << endl;

            subtotal += importe;

            totalUnidades += cantidades[i];
        }
    }

    // Calcular el ITBIS y el total general
    itbis = subtotal * 0.18;

    totalGeneral = subtotal + itbis;

    cout << "------------------------------------------------------------------------" << endl;

    cout << "Total de unidades: " << totalUnidades << endl;
    cout << "Subtotal: RD$ " << subtotal << endl;
    cout << "ITBIS (18%): RD$ " << itbis << endl;

    cout << "------------------------------------------------------------------------" << endl;

    cout << "TOTAL GENERAL: RD$ " << totalGeneral << endl;

    cout << "===============================================================" << endl;

    cout << "Gracias por comprar en Accesorios Mashiaj." << endl;
}
