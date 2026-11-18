// Este programa demuestra el uso de la funcion seekg().
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
   char ch;

   // Abre un archivo de solo lectura
   fstream file("letters.txt", ios::in);

   // Nos movemos 5 bytes desde el inicio del archivo
   // (al 6to byte) y leemos el caracter que hay ahi
   file.seekg(5L, ios::beg);
   file.get(ch);
   cout << "5 bytes desde el inicio: " << ch << endl; // F

   // Nos movemos al 10mo byte desde el fin del archivo
   // y leemos el caracter que hay ahi
   file.seekg(-10L, ios::end);
   file.get(ch);
   cout << "10mo byte desde el fin: " << ch << endl;  // Q

   // Movemos 3 bytes desde la posicion actual
   // (al 4to byte) y leemos el caracter que hay ahi
   file.seekg(3L, ios::cur);
   file.get(ch);
   cout << "3 bytes desde la poscion actual: " << ch << endl; // U

   file.close();
   return 0;
}
