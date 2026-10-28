
/*
  asleer0a.cpp
  Compilador: bcc32 5.5

  C++ / Ferreiras / Procesamiento de archivos en C++ /
  
   Archivos secuenciales o archivos de texto ASCII /
   Lectura con el operador de extraccion >>

   Ejemplo simple, muy simple.

*/

#include <fstream>
using namespace std;

int main(void){
    
    string palabra; 
    fstream leer("fff.dat", ios::in);
    while(!leer.eof()){
      leer >> palabra; // lee palabra por palabra
      cout << palabra << endl; // muestra palabra 
    }
    leer.close();    
    return 0;
} 


/*

C:\Borland\BCC55\Bin>asleer0a

Escritura
de
archivo
de
texto
Usando
los
recursos
de
fstream
fstream

==> 

*/