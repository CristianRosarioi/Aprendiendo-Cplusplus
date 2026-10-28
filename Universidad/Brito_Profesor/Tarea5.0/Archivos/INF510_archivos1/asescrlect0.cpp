/*
  asescrlect.cpp
  Compilador: bcc32 5.5

  C++/ FERREIRAS/ Archivos / <fstream> 

  Archivos de texto/ Creacion y lectura

*/

#include <fstream>

using namespace std;

char linea[100];

int main(void){

  // VARIABLES PARA CAPTURAR LOS CAMPOS DE LOS REGISTROS

  string nombre("Hotel Estudiantes");
  unsigned int hab(103);
  float precio(265.09);

 // APERTURA DEL ARCHIVO PARA ESCRITURA

  fstream escritor("Hoteles.txt", ios::app);
  if(!escritor){
    cout << endl << "Error !! " << endl;
    exit(EXIT_SUCCESS);
  }

  escritor << nombre << " "  
           << hab << " "
           << precio << endl;

  escritor.close();
  
 // APERTURA DEL ARCHIVO PARA LECTURA

  fstream lector("Hoteles.txt", ios::in);
  if(!lector){
    cout << endl << "Error !! " << endl;
    exit(EXIT_SUCCESS);
  }

 // LECTURA Y VISUALIZACIÓN DE REGISTROS
 
  while( !lector.eof()){
     lector.getline(linea, 100);
     cout << endl << linea;
  }
  lector.close();  

  cout << endl << endl;
  system("pause");
  return 0;

}

