/*
  asescr0b.cpp
  Compilador: bcc32 5.5

  C++ / Ferreiras / Archivos de texto ascii-std

  Escritura con el operador de insercion << 

  Ejemplo desde un <vector>

*/


#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int main(void){

    fstream Escritura("salida.dat");
    vector<float> num(10, 5.5);
    
    Escritura.precision(2);
    for( unsigned int k(0); k < num.size(); k++ ){
       Escritura << setw(5) << (num.at(k) + 1.5*k);
    }
    
    Escritura.close();
    cout << "\nEL ARCHIVO salida.dat YA ESTA CREADO..."
         << "\n\nPUEDES VER SU CONTENIDO CON type salida.dat"
         << endl << endl;
  
    return 0;

    
}

/*

C:\Borland\BCC55\Bin>asescr0b

==> Para ver el contenido grabado en el archivo salida.dat

    usando type:

C:\Borland\BCC55\Bin>type salida.dat

  5.5    7  8.5   10   12   13   14   16   18   19

*/