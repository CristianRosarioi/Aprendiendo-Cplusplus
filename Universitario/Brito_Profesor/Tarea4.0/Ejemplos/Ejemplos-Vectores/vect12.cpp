/* vect12.cpp

   C++ / FERREIRAS / <vector>

     push_back,  pop_back

*/

#include <iostream>
#include <vector>

using namespace std;

int main(void){

  vector<float> vect1;
  float num(0.0);
  system("cls");

  cout << "\n\nEntre numeros, <CTRL>+Z dos veces termina\n" << endl;
  while( cin >> num) {
     vect1.push_back(num);
  }


  cout << "\n\nDEL VECTOR vect1:\n"   
       << "\ncapacity() es: " << vect1.capacity() 
       << "\n    size() es: " << vect1.size()
       << "\nmax_size() es: " << vect1.max_size() 
       << "\n    back() es: " << vect1.back() << endl;
   
  vect1.pop_back();
     
  cout << "\n\nDESPUES DE pop_back:\n"   
       << "\ncapacity() es: " << vect1.capacity() 
       << "\n    size() es: " << vect1.size()
       << "\nmax_size() es: " << vect1.max_size() 
       << "\n    back() es: " << vect1.back() <<  endl << endl;
       
  
  system("pause");
  return 0;
}
