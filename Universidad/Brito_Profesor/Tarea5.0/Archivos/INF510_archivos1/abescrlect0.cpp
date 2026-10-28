/*
  abescrlect0.cpp
  Compilador: bcc32 5.5

   C++ / Ferreiras/ Archivos/ Binarios

   Uso de put, seekg, get

   En un archivo binario podemos escribir solo texto
   y procesarlo como un archivo de texto. 

*/

#include <fstream>
using namespace std;

int main(void){

    char car('F');
    fstream escr_leer("arch3.dat", ios::out | ios::in | ios::binary);
    if( escr_leer ){
      escr_leer.put(car);// escribe el contenido de car en el archivo
      escr_leer.seekg(ios::beg);// va al principio del archivo         
      escr_leer.get(car);// lee el caracter apuntado
      cout << endl << car << endl;// muestra el caracter leido 
    }
   else{
        cout << "\nERROR ABRIENDO EL ARCHIVO DE TEXTO\n";
        exit(1);
   }
   escr_leer.close();    
   return 0;
} 
