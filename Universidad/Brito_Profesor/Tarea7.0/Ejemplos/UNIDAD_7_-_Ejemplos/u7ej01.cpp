// ********************************************************************************
// -----------------------------------------------------------------------------------------------------------------------
// Data Type  Descripcion
// -----------------------------------------------------------------------------------------------------------------------
// ifstream    Input File Stream.  Este tipo de data puede ser usada solamente para leer datos
//                    desde archivos hacia la memoria.
// ofstream    Output File Stream.  Este tipo de data puede ser usada solamente para crear y
//                    escribir datos a los archivos.
// fstream     File Stream.  Este tipo de data puede ser usada para crear archivos, escribir y leer
//                    datos de ellos.
// -----------------------------------------------------------------------------------------------------------------------
// ********************************************************************************

// Este programa usa el objeto fstream para escribir data en un archivo.
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	fstream dataFile;
	string archivoTXT;

	cout << "Nombre del archivo: ";
	getline(cin, archivoTXT);

    cout << "Abriendo archivo...\n";
    dataFile.open(archivoTXT.c_str(), ios::out); // Abierto para escritura
    //dataFile.open(argv[1], ios::out); // Abierto para escritura
    cout << "Ahora escribiremos data en el archivo.\n";
    dataFile << "Diany Martinez\n";
    dataFile << "Jeyson Ortega\n";
    dataFile << "Yeimy Jimenez\n";
    dataFile << "Maria Duran\n";
	dataFile << "Angel Grullon\n";
    dataFile.close(); // Cerrar archivo
    cout << "Fin.\n";
    return 0;
}
