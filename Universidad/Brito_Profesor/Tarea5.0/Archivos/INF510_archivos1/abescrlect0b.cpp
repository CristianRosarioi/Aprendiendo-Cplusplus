/*
  abescrlect0b.cpp
  Compilador: bcc32 5.5

   C++ / Ferreiras/ Archivos/ Binarios / write, read 

   Observese que, en este caso, NO ES POSIBLE LEER EL ARCHIVO
   CREADO COMO ARCHIVO DE TEXTO ASCII porque los numeros tienen
   su propia representacion que no es ASCII.

*/

#include <fstream>
   using namespace std;

int main(void){
    system("cls");  
    double num(123.456), x; // 
    fstream escr_leer("arch4.bin", ios::out | ios::in | ios::binary);
    if( escr_leer ){
      escr_leer.write((char*)(&num), sizeof(num));    
      escr_leer.seekg(ios::beg);
      escr_leer.read( (char*)(&x), sizeof(x)); 
      cout << x << endl;
    }
   else{
        cout << "\nERROR ABRIENDO EL ARCHIVO DE TEXTO\n";
        exit(1);
   }
   escr_leer.close();    
   return 0;
} 

/*

C:\Borland\BCC55\Bin>abescrlect0b

123.456

C:\Borland\BCC55\Bin>type arch4.bin

w¥ƒ  <= Este es el resultado de intentar leerlo como texto

C:\Borland\BCC55\Bin>

*/
