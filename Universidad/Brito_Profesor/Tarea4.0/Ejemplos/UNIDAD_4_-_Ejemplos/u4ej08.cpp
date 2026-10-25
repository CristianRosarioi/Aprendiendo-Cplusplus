#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Contacto
{
    int codigo;
    string nombre;
    string email;
    int edad;
    double sueldoDeseado;

};

void print(vector<Contacto>);

int main(int argc, char** argv)
{
    Contacto c;
    vector<Contacto> contactos;

    cout << "Introduzca los siguientes datos (0 para finalizar)";

    do
    {
        cout << "\n\nCodigo        : ";
        cin >> c.codigo;

        if (c.codigo == 0) break;

        cin.ignore();
        cout << "Nombre        : ";
        getline(cin, c.nombre);
        cout << "Email         : ";
        getline(cin, c.email);
        cout << "Edad          : ";
        cin >> c.edad;
        cout << "Sueldo deseado: ";
        cin >> c.sueldoDeseado;

        contactos.push_back(c);
    } while(true);

    print(contactos);

    return 0;
}

void print(vector<Contacto> x)
{
    cout << endl;

    for (int i = 0; i < x.size(); i++)
    {
        cout << setw(5) << left << x.at(i).codigo;
        cout << setw(20) << left << x.at(i).nombre;
        cout << setw(35) << left << x.at(i).email;
        cout << setw(5) << right << x.at(i).edad;
        cout << setw(10) << right << setprecision(2) << fixed << x.at(i).sueldoDeseado;
        cout << endl;
    }

    cout << endl << endl;
}
