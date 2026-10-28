/*
  asleer1.cpp
  Compilador: bcc32 5.5

  C++ / FERREIRAS/ <fstream> 

  Archivos de texto/ Lectura

*/

#include <fstream>

using namespace std;

int main(void){

  string linea;
  char NombreArchivo[30];
  
  system("cls");
  cout << endl << endl << "Entre el nombre del archivo de texto a leer: ";
  cin >> NombreArchivo;
  
  fstream lee(NombreArchivo, ios::in);// Crea un objeto para lectura
  if(!lee){  
    cout << endl << "Error !! " << endl;
    exit(EXIT_SUCCESS);
  }
  
  while( !lee.eof()){
    
     if( lee.bad() || lee.fail() ){
       cout << endl << "Error durante lectura de archivo"; break;
     }
     else{
       // lee >> linea; // tambien, y es mas corto, pero no me gusta, (^_~)
       getline( lee, linea ); // Prefiero este, me es mas explicito 
       cout << endl << linea;
    }  
  }
    
  lee.close();
  return 0;
}

/*

Entre el nombre del archivo de texto a leer: agapito.dat

12345  Angelina Maria  Ortiz Sanchez  4.5
23456  belnarda rosamaria  monteodeoca de los santos y cespedes  5.6

C:\Borland\BCC55\Bin>


*/