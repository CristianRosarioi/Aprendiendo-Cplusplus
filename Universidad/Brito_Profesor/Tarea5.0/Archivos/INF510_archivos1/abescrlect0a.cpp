/*
  abescrlect0a.cpp
  Compilador: bcc32 5.5

   C++ / Ferreiras/ Archivos/ Binarios / write, read 

   En un archivo binario podemos escribir solo texto
   y procesarlo como un archivo de texto. 

*/

#include <fstream>
#include <string>

using namespace std;

int main(void){

    char texto[35] = "Archivos binarios solo como texto.";
    char cad[35];
    fstream escr_leer("arch4.bin", ios::out | ios::in | ios::binary);
    if( escr_leer ){
      escr_leer.write( texto, 35 );     
      escr_leer.seekg(ios::beg);
      escr_leer.read( cad, 35 ); 
      cout << cad << endl;
    }
   else{
        cout << "\nERROR ABRIENDO EL ARCHIVO DE TEXTO\n";
        exit(1);
   }
   escr_leer.close();    
   return 0;
} 

/*

C:\Borland\BCC55\Bin> abescrlect0a

Archivos binarios leidos con type.

C:\Borland\BCC55\Bin>type arch4.bin  <= usando type
  Archivos binarios leidos con type.

C:\Borland\BCC55\Bin>asleer1 <= leyendolo como archivo de texto

Entre el nombre del archivo de texto a leer: arch4.bin
  Archivos binarios leidos con type.

*/