/*
  cstr0.cpp
  Compilador: bcc3 5.5

  C++ / Ferreiras / Arreglos inteligentes con C++: <vector>

  Introduccion al concepto de arreglos en C++ / 
  Arreglos de tama�os fijos/ 
 /Arreglos de cadenas de caracteres (cadenas estilo-C)
  
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(void){

  char cad1[]="Esto es una cadena al estilo C";
  char cad2[40];
  char cad3[40];
  
 // USO DE LA FUNCION strcpy( c2, c1)
 
  strcpy(cad2, cad1);
  strcpy(cad3, "Copiando a cad3");
 
  cout << endl << cad1 << endl
          << endl << cad2 << endl
          << endl << cad3 << endl;
  return 0;
}
