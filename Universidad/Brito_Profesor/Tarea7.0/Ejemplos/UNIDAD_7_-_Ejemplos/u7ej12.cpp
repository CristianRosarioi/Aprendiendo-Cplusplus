// Programa que agrega registros a un archivo (los registros no tendran datos)
#include <iostream>
#include <fstream>
using namespace std;

// Constantes
const int DESC_SIZE = 31;   // Tamano de la descripcion
const int NUM_RECORDS = 5;  // Numero de registros

// Declaracion de la estructura InventoryItem
struct InventoryItem
{
   char desc[DESC_SIZE];
   int qty;
   double price;
};

int main(int argc, char** argv)
{
   // Crea una estructura vacia
   InventoryItem record = { "", 0, 0.0 };

   // Abrimos el archivo en modo binario y solo escritura
   fstream inventory("invent.dat", ios::out | ios::binary);

   // Escribimos los registros en blanco
   for (int count = 0; count < NUM_RECORDS; count++)
   {
      cout << "Escribiendo el record " << count << endl;
      inventory.write(reinterpret_cast<char *>(&record),
                     sizeof(record));
   }

   // Cerrar el archivo
   inventory.close();
   return 0;
}

