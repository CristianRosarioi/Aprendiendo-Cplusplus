#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    const int TAMANO = 20;
    char nombre[TAMANO];
    int edad;

    cout << "INICIO DE CAPTURA DE DATOS"
         << endl << endl;

    cout << "Edad  : ";
    cin >> edad;
    cin.ignore(); // ver aqui uso de cin.ignore
    cout << "Nombre: ";
    cin.getline(nombre, TAMANO);

    cout << "\n\nSu nombre : " << nombre << endl
         << "\nSu edad es: " << edad << endl;

    return 0;
}
