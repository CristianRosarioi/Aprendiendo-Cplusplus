/* vect10.cpp

   C++ / FERREIRAS / <vector>

     operador de asignacion = entre <vector>s

*/

#include <iostream>
#include <vector>

using namespace std;

int main(void){

  vector<string> vect1(7, "Fresdebindo Perez");
  vector<string> vect2(15,"Gran Dominicano");

  system("cls");
  cout << "\n\nANTES DE LA ASIGNACION: "
       << "\nsize de vect1 es: " << vect1.size()
       << "\nsize de vect2 es: " << vect2.size()
       << "\nprimer elemento en vect1 es: " << vect1.front() 
       << "\nprimer elemento en vect2 es: " << vect2.front() << endl;
  
  vect2 = vect1;

  cout << "\n\nDESPUES DE LA ASIGNACION: "
       << "\nsize de vect1 es: " << vect1.size()
       << "\nsize de vect2 es: " << vect2.size() << endl
       << "\nprimer elemento en vect1 es: " << vect1.front() 
       << "\nprimer elemento en vect2 es: " << vect2.front() << endl << endl;
  
  system("pause");
  return 0;
}
