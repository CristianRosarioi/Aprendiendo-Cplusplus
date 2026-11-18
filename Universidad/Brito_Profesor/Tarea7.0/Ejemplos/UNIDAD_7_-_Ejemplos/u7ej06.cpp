// Este programa usa una estructura para almacenar un registro en un archivo
#include <iostream>
#include <fstream>
using namespace std;

// Tamano de los arreglos
const int NOMBRE_SIZE = 51, DIRECCION_SIZE = 51, TELEFONO_SIZE = 14;

// Declarar la estructura para el registro
struct Info
{
    char nombre[NOMBRE_SIZE];
    int  edad;
    char direccion1[DIRECCION_SIZE];
    char direccion2[DIRECCION_SIZE];
    char telefono[TELEFONO_SIZE];
};

int main()
{
    Info personas;     // Variable para almacenar la informacion sobre personas
    char continuar;

    // Definir un archivo para almacenar las personas
    fstream archivoPersonas("curso.dat", ios::out | ios::binary | ios::app);

	do
	{
		// Leer la data por teclado
		cout << "Entre la siguiente informacion sobre una persona:\n";
		cout << "Nombre             : ";
		cin.getline(personas.nombre, NOMBRE_SIZE);
		cout << "Edad               : ";
		cin >> personas.edad;
		cin.ignore();
		cout << "Direccion (linea 1): ";
		cin.getline(personas.direccion1, DIRECCION_SIZE);
		cout << "Direccion (linea 2): ";
		cin.getline(personas.direccion2, DIRECCION_SIZE);
		cout << "Telefono           : ";
		cin.getline(personas.telefono, TELEFONO_SIZE);

		// Escribir el contenido de la estructura persona en el archivo
		// reinterpret_cast es utilizado para convertir el parametro a
		// la derecha en un puntero char
		archivoPersonas.write(reinterpret_cast<char *>(&personas), sizeof(personas));

		cout << "Desea continuar? ";
		cin >> continuar;
		cin.ignore();
	} while (continuar == 'S' || continuar == 's');

	// Cerrar el archivo
	archivoPersonas.close();
	return 0;
}
