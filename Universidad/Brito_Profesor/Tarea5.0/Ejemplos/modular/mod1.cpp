#include <iostream>
#include <math>


using namespace std;

// Definición de la función

long factorial (int n){ // [ -2147483648, 2147483647 ]
  
    long prod(1);
    for (int i(1) ; i <= n; i++)
       prod = prod *i;
    return prod;
}                                  
