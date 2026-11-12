#include <iostream>
#include <vector>

using namespace std;

// Accediendo a los elementos de un vector a traves
// de punteros

int main (int argc, char** argv)
{
    vector<string> entradas(5);

    string *p = entradas.data();

    *p = "Alitas Picantes Deshuesadas";
    p++; // nos movemos a la segunda posicion
    *p = "Palitos Mozarella";
    p[2] = "Bastoncitos de Camarones"; // P ya esta movido, cae en la 4ta posicion

    cout << "Contenido del vector:\n\n";

    for (unsigned int i = 0; i < entradas.size(); i++)
        cout << "[" << i << "]: " << entradas.at(i) << endl;

    cout << endl;

    return 0;
}
