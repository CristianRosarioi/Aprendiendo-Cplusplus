/*    vect2.cpp
      Compilador: bcc32 5.5

  C++ / FERREIRAS/ <vector>

  Uso de:  iterator, begin(), end()
   
  iterator permiten accesar a todos los elemenntos del vector.
  Una de las formas mas usada es:  vector<T>::iterator ID_Iterador;   

  Para ello, dinamicamente se capturar� en un objeto vector valores reales
 (La captura terminara con <Ctrl>+Z+<ENTER>) y se manipular� dicho vector 
  usando  los recursos indicados.  

*/

/* #include <vector>
#include <iostream>
#include <conio>

using namespace std;

int main(void){

  vector<float> v1; 
  vector<float>::iterator iter1, iter2, iter3; // declaracion de varios iterator
  float real;
  
  clrscr();
  cout << endl << "ENTRE VALORES REALES. PARA TERMINAR, CTRL+Z DOS VECES:" 
       << endl << endl;
  while( cin >> real) {
     v1.push_back(real); //
  }
  
  // Accesando el vector usando el iterator

  iter1 = v1.begin();
  iter2 = v1.end();
  int desplazamiento = iter2 - iter1;
  cout << endl << endl << "desplazamiento = iter2 - iter1: " << desplazamiento ;
  cout << endl << "El contenido actual del vector es: " << endl << endl;
  iter1 = v1.begin(); // begin() retorna un puntero al primer elemento
  while( iter1 != v1.end() ){// end() retorna puntero a la posici�n (ultimo_elemento + 1) 
     cout << *iter1 << "  "; // el iterator puede ser "desreferenciado"
     iter1++; // el iterator puede ser incrementado
  }

  return 0;
}
  */ 

  // Este codigo de arriba es el que dio el profesor pero no compila en C++14, por lo que se ha modificado para que compile y funcione correctamente.


  #include <vector>
#include <iostream>

using namespace std;

int main(void){

  vector<float> v1; 
  vector<float>::iterator iter1, iter2; // Eliminado iter3 que no se usaba
  float real;
  
  // LIMPIAR PANTALLA DE FORMA ESTÁNDAR:
  // Envía una secuencia de escape ANSI para limpiar la terminal. Funciona en Windows, Linux y macOS.
  cout << "\033[2J\033[1;1H"; 
  
  cout << endl << "ENTRE VALORES REALES. PARA TERMINAR, CTRL+Z DOS VECES (o CTRL+D en Linux/Mac):" 
       << endl << endl;
  while( cin >> real) {
     v1.push_back(real); 
  }
  
  // Accediendo al vector usando el iterator

  iter1 = v1.begin();
  iter2 = v1.end();
  int desplazamiento = iter2 - iter1;
  cout << endl << endl << "desplazamiento = iter2 - iter1: " << desplazamiento ;
  cout << endl << "El contenido actual del vector es: " << endl << endl;
  
  iter1 = v1.begin(); // begin() retorna un puntero al primer elemento
  while( iter1 != v1.end() ){ // end() retorna puntero a la posición (ultimo_elemento + 1) 
     cout << *iter1 << "  "; // el iterator puede ser "desreferenciado"
     iter1++; // el iterator puede ser incrementado
  }

  cout << endl; // Salto de línea final para limpiar la salida
  return 0;
}



