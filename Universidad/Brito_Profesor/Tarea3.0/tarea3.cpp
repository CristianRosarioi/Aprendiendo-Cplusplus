/*
Universidad Autónoma de Santo Domingo UASD
Centro UASD San Pedro, Escuela de informatica 5100-29
Introduccion a la Programacion
Cristian Rosario
 Matricula: 100806653
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Factura {
    long factNumero;
    string factCliente;
    string factFecha;
    double factMonto;
    double factDescuento;
    double factNeto;
};

Factura factura;

int main () {
    cout << "Numero de factura: ";
    cin >> factura.factNumero;
    cin.ignore();
    cout << "Cliente: ";
    getline(cin, factura.factCliente);
    cout << "Fecha: ";
    getline(cin, factura.factFecha);
    cout << "Monto bruto: ";
    cin >> factura.factMonto;

    if (factura.factMonto >= 50000) {
        factura.factDescuento = factura.factMonto * 0.14;
    } else if (factura.factMonto >= 30000) {
        factura.factDescuento = factura.factMonto * 0.10;
    } else if (factura.factMonto >= 20000) {
        factura.factDescuento = factura.factMonto * 0.07;
    } else {
        factura.factDescuento = 0;
    }

    factura.factNeto = factura.factMonto - factura.factDescuento;

    cout << fixed << setprecision(2);
    cout << "\nDatos de la factura:" << endl;
    cout << "Numero: " << factura.factNumero << endl;
    cout << "Cliente: " << factura.factCliente << endl;
    cout << "Fecha: " << factura.factFecha << endl;
    cout << "Monto bruto: " << factura.factMonto << endl;
    cout << "Descuento: " << factura.factDescuento << endl;
    cout << "Monto neto: " << factura.factNeto << endl;

    return 0;
}
