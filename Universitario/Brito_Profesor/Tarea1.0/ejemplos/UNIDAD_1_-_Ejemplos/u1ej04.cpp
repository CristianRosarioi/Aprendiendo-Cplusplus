#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string nombre;

    cout << "Introduzca su nombre completo: ";

    getline(cin, nombre);

    cout << "\n\nSu nombre completo es: "
         << nombre << endl;

    return 0;
}
