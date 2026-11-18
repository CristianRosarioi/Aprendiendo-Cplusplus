#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	fstream dataFile;

    cout << "Abriendo archivo...\n";
    dataFile.open("libros.txt", ios::out);

    cout << "Escribiendo en el archivo...\n";
    dataFile << "Expert Oracle PL/SQL\n";
    dataFile << "Ruby On Rails\n";
    dataFile << "Database Design Solutions\n";
    dataFile << "Starting Out C++\n";
	dataFile << "Oracle PL/SQL Best Practices\n";

	cout << "Cerrando archivo...\n";
    dataFile.close();

    cout << "Fin del programa.\n";
    return 0;
}
