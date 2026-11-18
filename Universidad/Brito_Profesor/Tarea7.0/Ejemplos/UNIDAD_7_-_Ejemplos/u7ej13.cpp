// Este programa muestra el contenido del archivo de inventario
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
   InventoryItem record; // Define la estructura para almacenar el registro

   // Abre el archivo de solo lectura y modo binario
   fstream inventory("invent.dat", ios::in | ios::binary);

   // Leemos y mostramos los registros
   // Leemos el 1er record
   inventory.read(reinterpret_cast<char *>(&record), sizeof(record));

   // Mientras no encontremos el fin del archivo
   // iteramos con un ciclo while desplegando y leyendo
   // el contenido del archivo
   while (!inventory.eof())
   {
      cout << "Descripcion: ";
      cout << record.desc << endl;
      cout << "Cantidad   : ";
      cout << record.qty << endl;
      cout << "Precio     : ";
      cout << record.price << endl << endl;
      inventory.read(reinterpret_cast<char *>(&record), sizeof(record));
   }

   // Cerrar el archivo
   inventory.close();
   return 0;
}
