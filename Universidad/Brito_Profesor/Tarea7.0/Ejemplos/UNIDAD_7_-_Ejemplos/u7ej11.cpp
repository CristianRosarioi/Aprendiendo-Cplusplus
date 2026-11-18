// Este programa demuestra el uso de la funcion tellg
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
   long offset;    // Almacena la posicion a la que nos moveremos
   long numBytes;  // Almacena el tamanao del archivo
   char ch;        // Almacena un caracter
   char again;     // Almacena S o N

   // Abrir el archivo de solo lectura
   fstream file("letters.txt", ios::in);

   // Determinar el numero de bytes en el archivo
   file.seekg(0L, ios::end);
   numBytes = file.tellg();
   cout << "El archivo tiene " << numBytes << " bytes.\n";

   // Volvemos al inicio del archivo
   file.seekg(0L, ios::beg);

   // Permitir al usuario que se mueva libremente en el archivo
   do
   {
      // Muestra la posicion actual
      cout << "Posicion actual: " << file.tellg() << endl;

      // Pide el numero de byte al usuario
      cout << "Entre la posicion (offset) a la que quiere moverse desde el inicio: ";
      cin >> offset;

      // Nos movemos a la posicion especificada por el usuario
      // y desplegamos el caracter que hay en ella
      if (offset >= numBytes)    // Validamos que el usuario no intente pasar al final del archivo
         cout << "No puede leer una posicion luego del fin del archivo.\n";
      else
      {
         file.seekg(offset, ios::beg);
         file.get(ch);
         cout << "Caracter leido: " << ch << endl;
      }

      cout << "Leer otro caracter (S/N)? ";
      cin >> again;
    } while (again == 'S' || again == 's'); // (toupper(again) == 'S')

   // Cerrar el archivo
    file.close();
   return 0;
}
