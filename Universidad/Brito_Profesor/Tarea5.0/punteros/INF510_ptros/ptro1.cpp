/*
   ptro1.cpp  
   Compilador: bcc32 5.5

   C++ / FERREIRAS/ Punteros
 
   
*/

# include <iostream>

using namespace std;
     
int main(void){

  float x(34.56);
  
 // Operador *

  float *py = &x; // Declara un puntero y lo inicializa

  cout << "\nLa direccion almacenada en el puntero es py = " << py << endl;
  cout << "\nEl valor almacenado en la direccion en el py es *py = " << *py << endl;
  cout << "\nEl puntero tiene su propia direccion, que es &py = " << &py << endl;  

  // Operador **

  float **ppy = &py; // Declara un puntero a un puntero y lo inicializa  

  cout << "\nEl ppy contiene la direccion &py = " << ppy << endl;
  cout << "\n*ppy accesa a la direccion almacenada por py, *ppy = " << *ppy << endl;
  cout << " **ppy accesa al contenido almacenado en la direccion por py, **ppy= " << **ppy << endl;
 
  // Operaciones basica con punteros

  float w(123.45);
  float z(*py + w);
  cout << "\n z(*py + w) Esta inicializada con: " << z << endl;
 
  return 0;
}

/*          
                 CORRIDA

C:\Borland\BCC55\Bin>ptro1

La direccion almacenada en el puntero es py = 0012FF88

El valor almacenado en la direccion en el py es *py = 34.56

El puntero tiene su propia direccion, que es &py = 0012FF84

El ppy contiene la direccion &py = 0012FF84

*ppy accesa a la direccion almacenada por py, *ppy = 0012FF88
 **ppy accesa al contenido almacenado en la direccion por py, **ppy= 34.56

 z(*py + w) Esta inicializada con: 158.01

*/	
