


/*  
     ablectdir1.cpp
     Compilador: bcc32 5.5     

     C++ / Ferreiras/ Archivos con <fstream> / BINARIOS/ LECTURA

     Lectura aleatoria de un archivo binario 

     (-_-) Los registros estan numerados desde 1; 
*/

#include <fstream.h>
#include <conio>
 using namespace std;

 // Definicion de los campos del registro y su tamaño
 // mediante una struct 

    struct  Cedulado {    
      unsigned long cedula; //  4 bytes, rango  0 to 4294967295
      char nombre[30];  
      char apellido[30];
      char sexo; // 1 byte
 
  }; // El tamano de este registro es de 68 bytes

  //...

int posicion;

int main(void){

 system("cls");
 
 cout << "\n LECTURA DIRECTA DE ced.dat" << endl;
 // Apertura del archivo para lectura
 fstream Lectura("ced.bin", ios::in | ios::binary);
 if(Lectura.fail()){
   cerr << "ERROR!, Archivo no existe, termina proceso, Pulse ENTER" << endl;
   system("pause");
   exit(1);
 }

 //...

 unsigned long longarchivo;
 Lectura.seekg(0, ios::end); // Posiciona el puntero al final
 longarchivo = Lectura.tellg(); /* Obtiene la posicion actual, que no es
                      mas que la longitud de archivo hasta ese momento.  :)  */
    
 Lectura.seekg(0, ios::beg); // Reposiciona el puntero al principio
 cout <<"\n\n=> El Tamano del archivo a leer es de: " 
      << longarchivo << " bytes" << endl
      << "\n\n=> El total actual de registros es de: " 
      << longarchivo/sizeof(Cedulado) << endl;

 // Procesamiento de  lecturas

 char respuesta;
 unsigned numreg;
 
 do{ 
    
    // Captura del numero del registro a leer

    cout << " \n\n=> Entre el numero del registro a leer: ";
    cin >> numreg;

    // VERIFICACION DEL NUMERO DE REGISTRO O CEDULA

    if( numreg <= 0 || cin.fail()) { 
        cout << "\n\n=> Error en el dato, Termina ejecucion!!\n\n"
             << "\n=> Pulse una tecla... ";
        getch();
        cout << endl;
        exit(1);
    }
      
    else if( numreg > longarchivo/sizeof(Cedulado) ){ 
        cout << "\n\n=> Error en el dato, Termina ejecucion!!\n\n"
             << "\n=> Pulse una tecla... ";
        getch();
        cout << endl;
        exit(1);
    }

    else ; // No hace nada (-_-)

     // Posicionamiento del puntero de lectura

     Lectura.seekg((numreg - 1)* sizeof(Cedulado));
     
    // Verificacion, lectura y visualizacion  
    
     Cedulado c;
     if ( (unsigned long)Lectura.tellg() < longarchivo) {
          // Lectura del registro
             Lectura.read( (char*)(&c), sizeof(Cedulado));
         // Visualizacion del registro
       system("cls");
       cout << "\n  Cedula: " <<  c.cedula
            << "\n  Nombre: " <<  c.nombre
            << "\nApellido: " <<  c.apellido
            << "\n    Sexo: " <<  c.sexo
            <<  endl;
     }
     else { 
       cout << "\nNo mas registro, voy a terminar";
       system("pause");
       exit(1); 
     }
     cout << "\n\n=> OTRO REGISTRO A PROCESAR ?, S/N:  ";
     cin >> respuesta;

 }while( !Lectura.eof() && respuesta == 'S' || respuesta == 's' ); 

 Lectura.close();
 system("cls");
 return 0;
}





