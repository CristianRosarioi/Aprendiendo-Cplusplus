 /*  
     ablectsec1.cpp
     Compilador: bcc32 5.5

     C++/ Ferreiras / Archivos con <fstream> / BINARIOS/ 
         /lectura secuencial

    Lectura secuencial de archivo binario conocido, llamado
    ced.bin,  hasta el final
   
 */

#include <fstream.h>
#include <string>
#include <conio>

using namespace std;

// Definicion de los campos del registro y su tamaño
// mediante una struct 

   struct  Cedulado { 
     
      unsigned long cedula; //  4 bytes, rango  0 to 4294967295
      char nombre[30];
      char apellido[30];
      char sexo; // 1 byte
 
  }; // El tamaño de este registro es de 68 bytes
  
 int main(void) {

     system("cls");
     cout << "\n LECTURA SECUENCIAL DE ARCHIVO BINARIO\n\n" ;
     
     fstream Lectura("ced.bin", ios::in | ios::binary);
     if (Lectura.fail()) {
       cerr << "\n=> ERROR !, Archivo no exite, termina el proceso"
            << "\n\n=> Pulse una tecla para continuar... ";
       getch();
       cout << "\n\n";
       exit(1);
     }
     else { // Procedemos a leer los datos y a visualizarlos
   
       Cedulado c1;
  
       Lectura.read(reinterpret_cast <char *> (&c1), sizeof(Cedulado));
       // Lectura.read((char*)(&c1), sizeof(Cedulado));
  
       while(!Lectura.eof() ) {

         // ESCRIBE A PANTALLA EL REGISTRO LEIDO

          cout << " Cedula No.: " << c1.cedula << endl;
          cout << "     Nombre: " << c1.nombre << endl;
          cout << "   Apellido: " << c1.apellido  << endl;
          cout << "       Sexo: " << c1.sexo   << endl;
          cout << "-------------------------------------" << endl;
       
        // LEE OTRO REGISTRO

          Lectura.read(reinterpret_cast <char *> (&c1), sizeof(Cedulado));
          // Lectura.read((char*)(&c1), sizeof(Cedulado));
      }
    } // Fin del bloque de lectura/visualizacion
   
    Lectura.close();
    return 0; 
}

