#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    const int TAMANO = 20;
    char nombre[TAMANO];
    char pausa;

    cout << "INICIO DE CAPTURA DE DATOS"
         << endl << endl
         << "Pulse enter para comenzar";
    cin.get(pausa);

    cout << "\n\nNombre  : ";
    cin.getline(nombre, TAMANO);

    cout << "\n\nSu nombre: " << nombre << endl;

    return 0;
}
