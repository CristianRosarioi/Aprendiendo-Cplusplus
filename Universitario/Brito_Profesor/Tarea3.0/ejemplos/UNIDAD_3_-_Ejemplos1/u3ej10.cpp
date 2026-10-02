#include <iostream>

using namespace std;

struct Perro
{
    string nombre;
    unsigned short edad;
    string raza;
};

int main(int argc, char** argv)
{
    Perro miPerro;

    cout << "Nombre : ";
    getline(cin, miPerro.nombre);
    cout << "Edad   : ";
    cin >> miPerro.edad;
    cin.ignore();
    cout << "Raza   : ";
    getline(cin, miPerro.raza);

    return 0;
}
