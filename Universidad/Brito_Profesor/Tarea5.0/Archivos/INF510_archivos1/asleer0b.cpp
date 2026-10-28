/*
  asleer0b.cpp
  Compilador: bcc32 5.5

   C++ / Ferreiras/ Archivos/ Binarios / Archivos ASCII-8 std

   Lectura get()

*/


#include <fstream>
using namespace std;

int main(void){
    fstream leer("arch1.dat", ios::in);
    char car;
    while( !leer.eof() ){
        leer.get(car);
        cout << car;
    }
    leer.close();    
   return 0;
} 

/*

  ==> En este momento arch1.dat solo tiene un registro a leer

C:\Borland\BCC55\Bin>asleer0b

Escritura de archivo de texto

  ==> Agregamos mas registros

C:\Borland\BCC55\Bin>asescr0a
C:\Borland\BCC55\Bin>asescr0a
C:\Borland\BCC55\Bin>asescr0a
C:\Borland\BCC55\Bin>asescr0a

==> En este momento arch1.dat solo tiene mas de un registro a leer

C:\Borland\BCC55\Bin>asleer0b

Escritura de archivo de texto

Escritura de archivo de texto

Escritura de archivo de texto

Escritura de archivo de texto

Escritura de archivo de texto

*/