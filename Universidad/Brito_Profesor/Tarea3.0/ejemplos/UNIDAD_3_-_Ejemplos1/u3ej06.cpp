#include <iostream>

using namespace std;

struct Precio
{
    double precio1;
    double precio2;
    double precio3;
};

struct Articulo
{
    int codigo;
    string descripcion;
    Precio precios;
};

int main(int argc, char** argv)
{
    Articulo x;

    cout << "Codigo    : ";
    cin >> x.codigo;
    cout << "Descipcion: ";
    cin.ignore();
    getline(cin, x.descripcion);
    cout << "Precio 1  : ";
    cin >> x.precios.precio1;
    cout << "Precio 2  : ";
    cin >> x.precios.precio2;
    cout << "Precio 3  : ";
    cin >> x.precios.precio3;

    return 0;
}
