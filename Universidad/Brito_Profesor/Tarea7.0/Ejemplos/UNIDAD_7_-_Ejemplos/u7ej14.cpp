// Este programa permite al usuario editar un registro en especifico
#include <iostream>
#include <fstream>
using namespace std;

const int DESC_SIZE = 31;

// Declaracion de la estructura InventoryItem
struct InventoryItem
{
   char desc[DESC_SIZE];
   int qty;
   double price;
};

int main(int argc, char** argv)
{
   InventoryItem record;  // Almacena un registro
   long recNum;           // Almacena el numero del registro

   // Abre el archivo en modo binario y de lectura y escritura
   fstream inventory("invent.dat",
                     ios::in | ios::out | ios::binary);

   // Solicita el numero de record a editar
   cout << "Que record desea editar? ";
   cin >> recNum;

   // Nos movemos a ese numero de record y lo leemos
   inventory.seekg(recNum * sizeof(record), ios::beg);
   inventory.read(reinterpret_cast<char *>(&record), sizeof(record));

   // Desplegamos su contenido
   cout << "Descripcion: ";
   cout << record.desc << endl;
   cout << "Cantidad   : ";
   cout << record.qty << endl;
   cout << "Precio     : ";
   cout << record.price << endl << endl;

   // Solicitamos la nueva data
   cout << "Introduzca los nuevos datos:\n";
   cout << "Descripcion: ";
   cin.ignore();
   cin.getline(record.desc, DESC_SIZE);
   cout << "Cantidad   : ";
   cin >> record.qty;
   cout << "Precio     : ";
   cin >> record.price;

   // Nos movemos al inicio de la posicion de ese registro
   inventory.seekp(recNum * sizeof(record), ios::beg);

   // Escribimos el registro nuevo sobre la data existente
   inventory.write(reinterpret_cast<char *>(&record), sizeof(record));

   // Cerramos el archivo
   inventory.close();
   return 0;
}
