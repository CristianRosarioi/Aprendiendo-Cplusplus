/*  vect0.cpp
    Compilador: bcc32 5.5

    C++ / FERREIRAS/ Arreglos inteligentes: <vector>

  <vector>,  Declaracion de vectores, carga de elementos con push_back, 
  size() del arreglo y  acceso a sus elementos con at(indice).

 <vector> provee una forma de arreglo dinamico que se expande tanto como sea
necesario para acomodar elementos adicionales al final. Los arreglos <vector> son mas 
robustos que los arreglos ordinarios.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){

   // Declaracion de vectores

   vector<float> v1; // Crea un vector vacio
   vector<float> v2(10); // Crea un vector con 10 elementos con valor por defecto 0.0
   vector<float> v3(5, 3.33);// Crea un vector con 5 elementos, cada uno con valor 3.33
   vector<string> v4; // Crea un vector vacio de cadenas  

 // push_back para agregar elementos al final del vector

   v1.push_back(1.23);
   v2.push_back(2.34);
   v3.push_back(103.44);
   v4.push_back("Ferreiras");

 // at(), size()

 //  at(indice)  para accesar  elementos de los vectores
 //  indice en el rango [ 0, size() - 1) ] 

   cout << v1.at(0) << endl;
   cout << v2.at(1) << endl;
   cout << v3.at( v3.size()  - 1) << endl;
   cout << v4.at(0) << endl;
   cout << v2.at(10) << endl;
   return 0;
}
