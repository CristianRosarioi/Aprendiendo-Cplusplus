#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Estudiante
{
	string matricula;
	string nombre;
	int carrera;
};

int main()
{
	char continuar;
	Estudiante e;

	fstream dataFile;
	dataFile.open("estud1.txt", ios::out | ios::app);

	do
    {
		cout << "Matricula: ";
		getline(cin, e.matricula);
		cout << "Nombre   : ";
		getline(cin, e.nombre);
		cout << "Carrera  : ";
		cin >> e.carrera;
		cin.ignore();

		dataFile << setw(15) << left << e.matricula
				 << setw(35) << left << e.nombre
				 << setw(10) << left << e.carrera
				 << "\n";

		cout << "Desea continuar (S/N)? ";
		cin >> continuar;
		cin.ignore();
	} while (continuar == 'S' || continuar == 's');

	dataFile.close();
	return 0;
}
