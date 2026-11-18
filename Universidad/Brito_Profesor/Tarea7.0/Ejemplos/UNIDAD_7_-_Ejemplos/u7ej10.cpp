// Este programa lee de forma aleatoria un registro en un archivo
#include <iostream>
#include <fstream>
using namespace std;

const int NAME_SIZE = 51, ADDR_SIZE = 51, PHONE_SIZE = 14;

// Declaramos la estructura para el registro del archivo
struct Info
{
   char name[NAME_SIZE];
   int age;
   char address1[ADDR_SIZE];
   char address2[ADDR_SIZE];
   char phone[PHONE_SIZE];
};

// Prototipo de las funciones
long byteNum(int);
void showRec(Info);

int main(int argc, char** argv)
{
   Info person;
   fstream people;

   // Abrimos el archivo en modo binario y solo lectura
   people.open("curso.dat", ios::in | ios::binary);

   // Validamos si hay un error al abrir el archivo
   if (!people)
   {
      cout << "Error abriendo el archivo.  Fin del programa.\n";
      return 0;
   }

   // Lee y muestra el record 1 (el 2do registro)
   cout << "Record 1:\n";
   people.seekg(byteNum(1), ios::beg);
   people.read(reinterpret_cast<char *>(&person), sizeof(person));
   showRec(person);

   // Lee y muestra el record 0 (el 1er registro)
   cout << "\nRecord 0:\n";
   people.seekg(byteNum(0), ios::beg);
   people.read(reinterpret_cast<char *>(&person), sizeof(person));
   showRec(person);

   // Cerrar el archivo
   people.close();
   return 0;
}

//************************************************************
// La funcion byteNum acepta un entero como argumento.       *
// Retorna el numero de byte en el archivo del record cuyo   *
// numero es pasado como argumento.                          *
//************************************************************

long byteNum(int recNum)
{
   return sizeof(Info) * recNum;
}

//************************************************************
// La funcion showRec acepta una estructura tipo Info como   *
// argumento y despliega muestra por pantalla su contenido.  *
//************************************************************

void showRec(Info record)
{
   cout << "Nombre             : ";
   cout << record.name << endl;
   cout << "Edad               : ";
   cout << record.age << endl;
   cout << "Direccion (linea 1): ";
   cout << record.address1 << endl;
   cout << "Direccion (linea 2): ";
   cout << record.address2 << endl;
   cout << "Telefono           : ";
   cout << record.phone << endl;
}
