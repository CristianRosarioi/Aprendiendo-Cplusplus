/*

  ptro0.cpp
  Compilador: bcc32 5.5


  C++ /  Ferreiras/  Punteros

  Inicializacion de punteros 

*/


#include <iostream>

using namespace std;

int main(void){

     float x(1.234);
     float *py = &x; // La direccion de una variable del mismo tipo

     float *pz;

     pz = py; // Otro puntero valido del mismo tipo

     // pz y py apuntan a la misma variable

     cout << endl << " *pz = " << *pz << endl 
          << endl << " *py = " << *py << endl;

     return 0;

}

/*

C:\Borland\BCC55\Bin>ptro0

 *pz = 1.234

 *py = 1.234

*/