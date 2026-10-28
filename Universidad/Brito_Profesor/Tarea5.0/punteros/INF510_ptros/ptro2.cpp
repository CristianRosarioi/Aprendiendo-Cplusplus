/*

  ptro2.cpp
  Compilador: bcc32 5.5


  C++ / FERREIRAS/ C++ / Punteros y Funciones

  Uso de punteros para pasar direcciones como argumentos
  en llamadas a funciones.

*/


#include <iostream>

using namespace std;

void suma( float *psuma, float num1, float num2){

   *psuma = num1 + num2;
}


int main(void){

   float  x, y(1.23), z(2.34);
   suma(&x, y, z);
   cout << endl << "LA SUMA ES: " << x << endl;
   return 0;
}

/*

C:\Borland\BCC55\Bin>ptro2

LA SUMA ES: 3.57

*/