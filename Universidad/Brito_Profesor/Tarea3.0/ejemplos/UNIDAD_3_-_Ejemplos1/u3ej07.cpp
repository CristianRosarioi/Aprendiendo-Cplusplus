#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string asignatura = "Introduccion a la Programacion";

    cout << "Cantidad de caracteres: " << asignatura.size() << endl;
    cout << "Esta vacia la variable? " << asignatura.empty() << endl;
    cout << "Dos caracteres a partir del indice 15: "
         << asignatura.substr(15, 2) << endl;
    asignatura.append(" con C++");
    cout << "Cadena modificada: " << asignatura << endl << endl;

    // Imprimiendo la cadena en mayusculas
    char chr;
    for (int i = 0; i < asignatura.size(); i++)
    {
        chr = toupper(asignatura.at(i));
        cout << chr;
    }

    cout << endl;

    return 0;
}
