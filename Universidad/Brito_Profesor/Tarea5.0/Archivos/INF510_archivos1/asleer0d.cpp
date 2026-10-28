
/*
  asleer0d.cpp
  Compilador: bcc32 5.5

  C++ / Ferreiras / Procesamiento de archivos en C++ /
  
   Archivos secuenciales o archivos de texto ASCII / 
  
   Lectura usando getline y verificacion de apertura

   Ejemplo simple, muy simple.

*/


#include <fstream>
using namespace std;
int main(void){                                   
   string line;
    fstream leer("fff.dat", ios::in);
   if( leer ){
       while( !leer.eof() ){ // Verifica la apertura
            getline( leer, line);
            cout << line << endl;
       }
   }
    else{
        cout << "\nERROR ABRIENDO EL ARCHIVO DE TEXTO\n";
        exit(1);
    }

    leer.close();    
    return 0;
} 

/*

SIN EL endl

C:\Borland\BCC55\Bin>asleer0d

12345  Pedro El Grande  Constitucion y Articulo  6.78  23456  Luis Felipe  Gerun
dio  4.5  12345678  El Torito  Los Cuernos  6.0


CON endl

C:\Borland\BCC55\Bin>asleer0d

12345  Pedro El Grande  Constitucion y Articulo  6.78
23456  Luis Felipe  Gerundio  4.5
12345678  El Torito  Los Cuernos  6.0

*/