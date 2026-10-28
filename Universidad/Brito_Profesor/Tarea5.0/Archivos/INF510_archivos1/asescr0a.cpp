/*
  asescr0a.cpp
  Compilador: bcc32 5.5

   C++ / Ferreiras/ Archivos/ Archivos ASCII-8 std

   - Escritura con el operador de insercion << 
   - Uso de ios::app y ios::noreplace

*/

#include <fstream>
using namespace std;

int main(void){

    fstream escribir("arch1.dat",  ios::app | ios::noreplace );
    escribir << "\nEscritura de archivo de texto\n"; 
    escribir.close();    
   return 0;
} 

/*
    NOTA: Cada vez que corro asescr0a se agrega un registro
          al archivo arch1.dat

C:\Borland\BCC55\Bin>asescr0a

C:\Borland\BCC55\Bin>asescr0a

C:\Borland\BCC55\Bin>asescr0a

C:\Borland\BCC55\Bin>asescr0a

C:\Borland\BCC55\Bin>asescr0a

C:\Borland\BCC55\Bin>asescr0a

*/