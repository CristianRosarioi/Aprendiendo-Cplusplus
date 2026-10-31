#include <iostream>

using namespace std;
long factorial(int);
void f2(void){

   int x;
   cout << "\n\nEntre un numero entero positivo [0, 16]: "; 
   cin >> x;
   cout << "\n\nEl factorial de x = " << x
           << "  es " << factorial(x) << endl;
}
