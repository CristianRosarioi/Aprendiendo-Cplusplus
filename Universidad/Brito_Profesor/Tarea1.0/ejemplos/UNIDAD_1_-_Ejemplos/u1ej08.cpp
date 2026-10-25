#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    const int TAMANO = 20;
    char nombre[TAMANO];

    cout << "INTRODUZCA LOS SIGUIENTES DATOS"
         << endl << endl;
    cout << "Nombre  : ";
    cin.getline(nombre, TAMANO);

    cout << "\n\nSu nombre: " << nombre << endl;

    return 0;
}
