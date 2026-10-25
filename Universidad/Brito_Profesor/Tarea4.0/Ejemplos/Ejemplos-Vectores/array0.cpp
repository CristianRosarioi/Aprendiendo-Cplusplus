/*
  array0.cpp
  Compilador: bcc32 5.5

  C++/ Ferreiras / Arreglos inteligentes con C++: <vector>

  /Introduccion a los arreglos /  arreglos de size fijo

*/

#include <iostream>
using namespace std;

int main(void){

   system("cls");
   double a[10000];// Declara un array de size fijo de 10000 doubles
   int indice(0); // 
   cout << "\n\n => Entre numeros reales, CTRL+Z termina\n" << endl; 
   while (cin >> a[indice]){
        indice++;
   }

    double suma(0);  
    for (int i(0); i < indice; i++) {
        suma = suma + a[i]; // Acumula los valores a[i]
    }
    cout << "La suma de los reales suplidos es: " << suma << endl;
    return 0;
}
