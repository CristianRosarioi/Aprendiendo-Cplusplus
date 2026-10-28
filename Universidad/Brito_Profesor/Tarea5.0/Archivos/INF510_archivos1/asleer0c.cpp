
/*
  asleer0c.cpp
  Compilador: bcc32 5.5

  C++ / Ferreiras / Procesamiento de archivos en C++ /
  
   Archivos secuenciales o archivos de texto ASCII / 
  
   Lectura usando getline

   Ejemplo simple, muy simple.

*/

#include <fstream>
using namespace std;

int main(void){
    
    string linea; 
    fstream leer("fff.dat", ios::in);
    while(!leer.eof()){
      getline(leer, linea);
      cout << linea << endl; // quitar endl y probar
    }
    leer.close();    
    return 0;
} 


/*

C:\Borland\BCC55\Bin>asleer0c

Escritura de archivo de texto

Usando los recursos de fstream

==> TAREA: Quitar endl y probar

*/