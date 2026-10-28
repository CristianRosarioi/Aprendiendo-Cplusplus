/*
  asput0.cpp
  Compilador: bcc32 5.5

  C++ / Ferreiras / Manejo de archivos en C++ con <fstream>

  Archivos secuenciales/ Escitura con put

*/

#include <fstream>
 using namespace std;

int main(void){

   fstream escribir("ggg.dat", ios::out);
   char c;
   system("cls");
   cout << "\n=> Entre un caracter, para terminar CTRL+Z:\n\n";
   while(cin >> c){
      escribir.put(c);
   }

   escribir.close();
   return 0;
 
}

/*

C:\Borland\BCC55\Bin>asput0

=> Entre un caracter, para terminar CTRL+Z:

#
&
(
)
F
E
^Z
^Z

C:\Borland\BCC55\Bin>type ggg.dat

#&()FE

C:\Borland\BCC55\Bin>

*/