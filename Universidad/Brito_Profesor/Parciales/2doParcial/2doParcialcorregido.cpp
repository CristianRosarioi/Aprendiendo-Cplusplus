/*
Universidad Autónoma de Santo Domingo UASD
Centro UASD San Pedro, Escuela de informatica 5100-29
Introduccion a la Programacion
Cristian Rosario
Matricula: 100806653
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Prototipos de las funciones
void mostrarNegocio();
void mostrarMenu();
void entregarPedido(int opcion);

int main() {

    int opcion;

    mostrarNegocio();
    mostrarMenu();

    cout << "\nSeleccione una opcion (1-5): ";
    cin >> opcion;

    entregarPedido(opcion);

    return 0;
}

// Funcion que muestra los datos del negocio
void mostrarNegocio() {

    cout << "===============================================================" << endl;
    cout << "                       ACCESORIOS MASHIAJ" << endl;
    cout << "                     Tu perfumeria preferida" << endl;
    cout << "===============================================================" << endl;
}

// Funcion que muestra el menu
void mostrarMenu() {

    cout << fixed << setprecision(2);

    cout << "\n                      MENU DE PERFUMES\n" << endl;

    cout << "+--------+------------------------------------------+------------+" << endl;

    cout << "| " << left << setw(6) << "Opcion"
         << " | " << setw(40) << "Perfume"
         << " | " << right << setw(10) << "Precio RD$"
         << " |" << endl;

    cout << "+--------+------------------------------------------+------------+" << endl;

    cout << "| " << left << setw(6) << "1"
         << " | " << setw(40) << "One Million 3.4 oz"
         << " | " << right << setw(10) << 5000.00
         << " |" << endl;

    cout << "| " << left << setw(6) << "2"
         << " | " << setw(40) << "Armani Acqua di Gio 3.4 oz"
         << " | " << right << setw(10) << 7500.00
         << " |" << endl;

    cout << "| " << left << setw(6) << "3"
         << " | " << setw(40) << "Dolce Gabbana Light Blue 4.2 oz"
         << " | " << right << setw(10) << 4200.00
         << " |" << endl;

    cout << "| " << left << setw(6) << "4"
         << " | " << setw(40) << "Nautica Voyage 3.4 oz"
         << " | " << right << setw(10) << 2500.00
         << " |" << endl;

    cout << "| " << left << setw(6) << "5"
         << " | " << setw(40) << "Valentino Born in Roma 3.4 oz"
         << " | " << right << setw(10) << 6500.00
         << " |" << endl;

    cout << "+--------+------------------------------------------+------------+" << endl;
}

// Funcion que entrega el pedido del cliente
void entregarPedido(int opcion) {

    switch (opcion) {

        case 1:
            cout << "\nAqui esta su pedido: One Million 3.4 oz"
                 << endl;
            break;

        case 2:
            cout << "\nAqui esta su pedido: Armani Acqua di Gio 3.4 oz"
                 << endl;
            break;

        case 3:
            cout << "\nAqui esta su pedido: Dolce Gabbana Light Blue 4.2 oz"
                 << endl;
            break;

        case 4:
            cout << "\nAqui esta su pedido: Nautica Voyage 3.4 oz"
                 << endl;
            break;

        case 5:
            cout << "\nAqui esta su pedido: Valentino Born in Roma 3.4 oz"
                 << endl;
            break;

        default:
            cout << "\nOpcion invalida. Seleccione del 1 al 5."
                 << endl;
            break;
    }
}
