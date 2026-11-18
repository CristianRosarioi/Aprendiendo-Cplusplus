#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Contacto
{
    char nombre[30];
    unsigned int edad;
};

int main(int argc, char** argv)
{
    Contacto contc;

    fstream datos("contacto.dat", ios::out
                                | ios::binary
                                | ios::app);

    cout << "Entre datos de contacto (0 - Salir):\n";
	do
	{
		cout << "\nNombre: ";
		cin.getline(contc.nombre, 30);
		if (strcmp(contc.nombre, "0") == 0)
            break;
		cout << "Edad  : ";
		cin >> contc.edad;
		cin.ignore();
		datos.write(reinterpret_cast<char *>(&contc), sizeof(contc));
	} while (true);

	datos.close();
	return 0;
}
