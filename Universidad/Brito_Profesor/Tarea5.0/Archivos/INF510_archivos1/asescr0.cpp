
/*
  asescr0.cpp
  Compilador: bcc32 5.5

  C++ / Ferreiras / Procesamiento de archivos en C++ /
  
   Archivos secuenciales o archivos de texto ASCII /
  
   Escritura usando el operador de insercion << 

   Ejemplo simple, muy simple.

*/

#include <fstream>
using namespace std;

int main(void){
    fstream escribir("fff.dat", ios::out);
    escribir << endl << "Escritura de archivo de texto" << endl; 
    escribir << endl << "Usando los recursos de fstream" << endl;
    escribir.close();    
   return 0;
} 


/*

C:\Borland\BCC55\Bin>asescr0

C:\Borland\BCC55\Bin>type fff.dat

Escritura de archivo de texto

Usando los recursos de fstream

 => TAREA: Quite los endl y verifique el resultado. 

*/