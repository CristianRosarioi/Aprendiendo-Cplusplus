#include <iostream>

using namespace std;

string mayuscula(string x);

int main(int argc, char** argv)
{
    string nombre;

    do
    {
        cout << "Entre su nombre: ";
        getline(cin, nombre);

        if (nombre == "*") break;

        cout << "Nombre leido: "
             << mayuscula(nombre) << endl << endl;
    } while (true);

    return 0;
}

string mayuscula(string x)
{
    string temp;

    for (int i = 0; i < x.size(); i++)
        temp.push_back(toupper(x.at(i)));

    return temp;
}

