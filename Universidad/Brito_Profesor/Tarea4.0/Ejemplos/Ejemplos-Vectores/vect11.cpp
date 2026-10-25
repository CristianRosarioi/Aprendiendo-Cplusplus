/* vect11.cpp

   C++/ FERREIRAS / <vector>

     capacity(), size(); max_size()

*/

#include <iostream>
#include <vector>

using namespace std;

int main(void){

  vector<string> vect1(33, "Fresdebindo Perez");
  vector<string> vect2(67,"Guebon idiota");

  system("cls");
  cout << "\n\nDEL VECTOR vect1:"   
       << "\ncapacity() es: " << vect1.capacity() 
       << "\n    size() es: " << vect1.size()
       << "\nmax_size() es: " << vect1.max_size() << endl;
       
  cout << "\n\nDEL VECTOR vect2:"   
       << "\ncapacity() es: " << vect2.capacity() 
       << "\n    size() es: " << vect2.size()
       << "\nmax_size() es: " << vect2.max_size() << endl << endl;
       
  
  system("pause");
  return 0;
}

