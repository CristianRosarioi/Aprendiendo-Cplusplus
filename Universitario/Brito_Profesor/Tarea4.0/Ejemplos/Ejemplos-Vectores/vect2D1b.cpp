/*
  vect2D1b.cpp
  Compilador: bcc32 5.5

  C++/ Ferreiras/ <vector> / 2D

  Para trabajar con matrices:

  (1)    vector<int, allocator<int> >

  (2)   usar la librer�a Matrix en www.boost.org 

  (3)  Usar un vector de vectores
 
       vector< vector<T> > id_matr; // deje los espacios indicados

  (4) Usar

      typedef vector <T> columnas;
      vector <columnas> filas;

  (5) Tanto en 3 como en 4, despues se deber�n crear las filas
      inyectandole vectores con push_back, previamente cargados.
      Cada vez que inyectamos un vector es una fila nueva en la 
      matriz. Por ejemplo:

      vector < vector<int> > matr;  
      matr.push_back(vector <int>()); 

      Creara la fila matr[0]
     
      Podemos asignarle valores, por ejemplo, a matr[0][0]:
    
      matr[0].push_back(50); 
   
      En el siguiente codigo ilustramos esto mas ampliamente.

      !! Cada fila de la matriz podra tener la cantidad de elementos
      que el usuario quiera !!

*/

#include <vector>
#include <iostream>

using namespace std;

int main(void){

    vector< vector<int> > matr;
 // CARGA DE LA MATRIZ
 // CADA VEZ QUE INYECTEMOS UN VECTOR A LA MATRIZ, ES UNA FILA NUEVA

    vector<int> x;
    int y;
    char resp;

    do{
       cout << "\nEntre los elementos de las filas" << endl;
       x.clear(); // borra los elementos en el vector, si los hay.
        // Si el vector no es clear(), simplemente se van agregando
        // dinamicamente y los elementos de las filas anterior
        // estar�n en la fila siguiente. (\_~)
       
       while(cin >> y)
         x.push_back(y); // carga los elementos de la fila
       matr.push_back(x); //inyectamos el vector o fila nueva
       cin.clear(); // limpia el buffer 
       cout << "\nOTRA FILA ? s/n: ";
       cin >> resp;
    }while(resp == 's' || resp == 'S');

 // PROCESAMOS LOS ELEMENTOS DE LA MATRIZ, POR EJEMPLO, MOSTRARLOS
               
   cout << "\n\nCantidad de filas = " << matr.size() << endl;
   for(unsigned f(0); f < matr.size(); f++) {
     cout << "\nCantidad de columnas en la fila " << f 
          << " es " << matr.at(f).size() << endl
          << "Estos elementos son: " << endl;
     for (unsigned j(0); j < matr[f].size(); j++) {
        cout << matr[f][j] << " ";
     }
        cout << endl;
   }

  return 0;
}

