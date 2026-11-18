#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

struct Estudiante
{
	string matricula;
	string nombre;
	int carrera;
};

int main()
{
	string linea;
	Estudiante e;

	fstream dataFile;
	dataFile.open("estud1.txt", ios::in);

	while (!dataFile.eof())
	{
		getline(dataFile, linea);
		cout << linea << endl;
	}

	dataFile.close();
	return 0;
}
