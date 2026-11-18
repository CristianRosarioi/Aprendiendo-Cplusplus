// Este programa lee un archivo y escribe su contenido en otro
// archivo en formato HTML
#include <iostream>
#include <fstream>
using namespace std;

const int NOMBRE_SIZE = 51, DIRECCION_SIZE = 51, TELEFONO_SIZE = 14;

struct Info
{
   char nombre[NOMBRE_SIZE];
   int edad;
   char direccion1[DIRECCION_SIZE];
   char direccion2[DIRECCION_SIZE];
   char telefono[TELEFONO_SIZE];
};

int main()
{
   Info personas;
   char continuar;
   fstream archivoPersonas;
   fstream htmlFile;

   // Abrir el archivo para lectura en modo binario
   archivoPersonas.open("curso.dat", ios::in | ios::binary);
   htmlFile.open("curso.html", ios::out);

   if (!archivoPersonas)
   {
      cout << "Error opening file. Program aborting.\n";
      return 0;
   }


   cout << "Aqui estan los registros en el archivo:\n\n";
   archivoPersonas.read(reinterpret_cast<char *>(&personas), sizeof(personas));

   htmlFile << "<table border=\"1\" cellpadding=\"1\">\n";
   htmlFile << "<tr>\n";
   htmlFile << "<th>Nombre</th><th>Edad</th><th>Direccion</th><th>Sector</th><th>Telefono</th>\n";
   htmlFile << "</tr>\n";

   while (!archivoPersonas.eof())
   {
      htmlFile << "<tr>\n";
	  htmlFile << "<td>" << personas.nombre << "</td>"
	           << "<td>" << personas.edad << "</td>"
			   << "<td>" << personas.direccion1 << "</td>"
			   << "<td>" << personas.direccion2 << "</td>"
			   << "<td>" << personas.telefono << "</td>\n";
	  htmlFile << "</tr>\n";

      archivoPersonas.read(reinterpret_cast<char *>(&personas), sizeof(personas));
   }

   htmlFile << "</table>";
   archivoPersonas.close();
   return 0;
}
