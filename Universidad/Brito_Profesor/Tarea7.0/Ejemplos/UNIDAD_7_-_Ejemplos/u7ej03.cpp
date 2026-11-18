#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream dataFile;
	dataFile.open("existe.txt", ios::in);
	if (dataFile.fail())
	{
		cout << "Crea archivo ya que no existe.\n";
		dataFile.open("existe.txt", ios::out);
		dataFile << "Esta es una nueva linea.\n"; // Agrega una linea nueva
	}
	else
	{
		cout << "Archivo ya existe :)\n";
	}
	dataFile.close();
	return 0;
}
