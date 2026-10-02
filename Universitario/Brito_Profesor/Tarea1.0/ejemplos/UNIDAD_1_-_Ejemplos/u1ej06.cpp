#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    char nombre[20];
    char apellido[20];

    cout << "INTRODUZCA LOS SIGUIENTES DATOS"
         << endl << endl;
    cout << "Nombre  : ";
    cin >> nombre;
    cout << "Apellido: ";
    cin >> apellido;

    cout << "\n\nSu nombre completo es: "
         << nombre << " " << apellido
         << endl;

    return 0;
}
