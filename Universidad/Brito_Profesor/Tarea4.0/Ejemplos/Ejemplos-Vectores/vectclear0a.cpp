/*
   vectclear0a.cpp
   Compilador: bcc32 5.5

   C++/ Ferreiras/  Arreglos inteligentes con C++: <vector>
      / recurso clear()

   El recurso clear() de <vector> remueve todos los elementos en
   un <vector> dado, dejandolo con un size de 0 y liberando la
   memoria asignada. 

   Otros recursos asociados son:

   erase()        Borra elementos
   resize()       Cambia el size
   empty()        Verifica si esta vacio

*/

#include <iostream>
#include <vector>
#include <string>
 using namespace std;

int main(void){

  system("cls"); 
 
  vector<string> v;
  cout << "\n=> La capacidad del <vector> actual es: "
       << v.capacity() << endl;

  v.push_back("Estamos en <vector>, ! que bien !");
  v.push_back("Y tenemos 6 puntos");
  v.push_back("Para el next lab");
  
  cout << "\n=> La capacidad del <vector> actual es: "
       << v.capacity() << endl;

  cout << "\n=> El contenido actual en el <vector> es:\n\n";
  for ( unsigned int i(0); i < v.size(); i++)
     cout << "  " << v[i] << endl; 
  
  v.clear();
  if( v.empty()){
    cout << "\n=> Estoy vacio, mi size es: " 
         << v.size() << "  elementos" << endl;
  }
  else{
    cout << "\n=> Estoy lleno con " << v.size() << " elementos\n"
         << endl << " Los cuales son: " << endl;   
    for( unsigned int k(0); k < v.size(); k++)
       cout << "   " << v[k] << endl;    
  }
  cout << "\n=> La capacidad del <vector> actual es: "
       << v.capacity() << endl;

  v.push_back("Ahora le cargo un elemento");
  v.push_back("Otro elemento");

  cout << "\n=> La capacidad del <vector> actual es: "
       << v.capacity() << endl;

  if( v.empty()){
    cout << "\n=> Estoy vacio, mi size es: " 
         << v.size() << "  elementos" << endl;
  }
  else{
    cout << "\n=> Me han empujado elementos y ahora tengo " 
         << v.size() << ", los cuales son: " << endl << endl;   
    for( unsigned int k(0); k < v.size(); k++)
       cout << "   " << v[k] << endl;    
  }
  return 0;
}
