#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
using namespace std;

struct Contacto
{
    char nombre[30];
    unsigned int edad;
};

int main(int argc, char** argv)
{
    Contacto contc;
    fstream datos("contacto.dat", ios::in
                                | ios::binary);

    cout << "Presione cualquier tecla para listar los contactos:";
    getch();
    cout << endl << endl;
    datos.read(reinterpret_cast<char *>(&contc), sizeof(contc));
	while (!datos.eof())
	{
        cout << setw(30) << left << contc.nombre << "\t"
             << setw(5) << right << contc.edad << endl;
        datos.read(reinterpret_cast<char *>(&contc), sizeof(contc));
	}

	datos.close();
	return 0;
}
