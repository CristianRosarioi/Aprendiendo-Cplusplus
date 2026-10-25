/*
  vecterase0.cpp
  Compilador: bcc32 5.5

  C++ / Ferreiras / Arreglos inteligentes con C++: <vector>
      / recurso erase()
 
*/

#include <iostream>
#include <vector>
 using namespace std;

int main(void){

  system("cls");
  vector<double> v;

  // CARGAMOS ALGUNOS ELEMENTOS EN v

  v.push_back(1.23);
  v.push_back(12.33);
  v.push_back(13.44);
  v.push_back(14.55);
  v.push_back(15.66);
  v.push_back(16.77);
  v.push_back(17.88);

  // VEMOS EL CONTENIDO DEL VECTOR

  cout << endl << "=> El contenido del <vector> es:\n\n";
  for( unsigned int k(0); k < v.size(); k++ )
    cout << "  " << v[k];

  // BORRAMOS EL 6to. ELEMENTO

  v.erase (v.begin() + 5); // begin() apunta a la posicion 1

  // VEMOS EL CONTENIDO DEL VECTOR

  cout << endl << "\n=> El contenido ahora es: " << endl << endl;
  for( unsigned int k(0); k < v.size(); k++ )
    cout << "  " << v[k];

  // BORRAMOS LOS ELEMENTOS EN EL RANGO [3,4] 
 
  v.erase(v.begin() + 2, v.begin() + 4);

// VEMOS EL CONTENIDO DEL VECTOR

  cout << endl << "\n=> El contenido ahora es: " << endl << endl;
  for( unsigned int k(0); k < v.size(); k++ )
    cout << "  " << v[k];
  cout << endl;
  return 0;
}
