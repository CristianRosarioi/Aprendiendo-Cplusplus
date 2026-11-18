// Este programa utiliza una estructura para leer un archivo binario
#include <iostream>
#include <fstream>
using namespace std;

const int NOMBRE_SIZE = 51, DIRECCION_SIZE = 51, TELEFONO_SIZE = 14;

// Declarar la estructura para el registro
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

   archivoPersonas.open("curso.dat", ios::in | ios::binary);

   // Verifica que no haya errores
   if (!archivoPersonas)
   {
      cout << "Error abriendo el archivo.\n";
      return 0;
   }


   cout << "Aqui estan los registros en el archivo:\n\n";
   // Lee el primer registro del archivo
   archivoPersonas.read(reinterpret_cast<char *>(&personas), sizeof(personas));

   // Leer el archivo mientras mientras no llegues al fin del archivo
   while (!archivoPersonas.eof())
   {
      // Despliega la informacion del registro
      cout << "Nombre             : ";
      cout << personas.nombre << endl;
      cout << "Edad               : ";
      cout << personas.edad << endl;
      cout << "Direccion (linea 1): ";
      cout << personas.direccion1 << endl;
      cout << "Direccion (linea 2): ";
      cout << personas.direccion2 << endl;
      cout << "Telefono           : ";
      cout << personas.telefono << endl;

      // Realiza una pausa (espera que el usuario pulse enter)
      cout << "\nPresione Enter para ver el proximo record.\n";
      cin.get(continuar);

      // Lee el proximo registro del archivo
      archivoPersonas.read(reinterpret_cast<char *>(&personas), sizeof(personas));
   }

   cout << "Esa es toda la data en el archivo!\n";
   archivoPersonas.close();
   return 0;
}
