
 /* 
     abescrsec1.cpp
     Compilador: bcc32 5.5

    C++/ Ferreiras / Archivos con <fstream> / BINARIOS/ CREACION

    - Creacion de un archivo de registros de cedulados en la JCE de la RD.
    - El nombre del archivo es ced.bin
    - El programa debe permitir agregar registro cada vez que se corra. 

*/

#include <fstream.h>
#include <conio>

using namespace std;

// Definicion de los campos del registro y su tamano
// mediante una struct 

   struct  Cedulado { 
     
      unsigned long cedula; //  4 bytes, rango  0 to 4294967295
      char nombre[30];  
      char apellido[30];
      char sexo; // 1 byte
 
  }; // El tamano de este registro es de 65 bytes
  
  //...

  int main(void) {

     char respuesta;

     system("cls");
     cout << "\n\n=> ESCRITURA DE REGISTROS EN EL ARCHIVO BINARIO ced.bin "
          << "\n\n=> El Tamano del registro es " << sizeof(Cedulado) 
          << " bytes " << endl;
     

     fstream Escritura("ced.bin", ios::out | ios::binary | ios::ate);
  
     // Se crea el archivo vacio y abierto para escritura  
  
     if (Escritura.fail()) {
            cerr << "\n=> ERROR !, Archivo no exite, termina el proceso"
            << "\n\n=> Pulse una tecla para continuar... ";
       getch();
       cout << "\n\n";
       exit(1);
     }
     else { // Procedemos a capturar los datos y a escribirlos
     
        Cedulado c1;
  
        do{

            // CAPTURA POR TECLADO DE LOS DATOS DE CADA REGISTRO
          
            cout << endl << "CEDULA: ";
            cin >> c1.cedula;
            cout << endl << "NOMBRE: ";
            cin.ignore();
            cin.getline(c1.nombre, 30 );
            cout << endl << "APELLIDO: ";
            cin.getline(c1.apellido, 30);
            cout << endl << "SEXO [M/F]:  ";
            cin >> c1.sexo;
           
            // ESCRIBIMOS EN EL ARCHIVO EL REGISTRO CAPTURADO 

            Escritura.write((char*)(&c1), sizeof(Cedulado));
        
            cout << "\n\n ¿ OTRO REGISTRO A PROCESAR ? S/N:  ";
            cin >> respuesta;
           
      }while( respuesta == 'S'  ||  respuesta == 's'  ); 

    } // Fin del bloque de captura/escritura
  
    Escritura.close(); // cierra el flujo de escritura.    
    return 0;
 }
