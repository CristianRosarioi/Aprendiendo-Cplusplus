
/*  
     abescrdir1.cpp
     Compilador: bcc32 5.5

     C++ / Ferreiras / Archivos con <fstream> / Binarios
         / Escritura aleatoria

   Escritura directa de datos en un registro ya existente con 
   la estructura indicada. Se captura el numero de
   registro, se verifica su existencia, se procede a capturar 
   los demas datos pertinentes y luego se escribe dicho registro
   en la posicion correspondiente. OJO: Este codigo asegura que
   el numero de registro suplido ya exista en el archivo. 

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
 
  }; // El tamano de este registro es de 65 bytes

int main(void){

 system("cls");
 
 cout << "\n\n=> Escritura directa sobre registros en el archivo ced.bin \n" 
      << "\n\n=> El Tamano del registro es " << sizeof(Cedulado) 
      << " bytes" << "\n\n";

 fstream flujo("ced.bin", ios::in | ios::out);

 if(flujo.fail()){
    cout << "\n=> El archivo no se pudo abrir, termina ejecucion\n\n ";
    exit(1);
 }
 
 int longarchivo;

 // OBTENEMOS LA LONGITUD ACTUAL DEL ARCHIVO

 flujo.seekp(0, ios::end); // Posiciona el puntero al final

 // Otener la posicion actual del puntero de archivo
 // La cual es la longitud del archivo hasta ese momento

 longarchivo = flujo.tellp(); 
 cout <<"\n\n=> El  tamano ACTUAL del archivo ES DE : " << longarchivo
      << " bytes" << endl;

 Cedulado c;
 char respuesta; 
 unsigned numreg;

 do{
    
  // Captura de la cedula del registro a escribir
  
    cout  << "\n\n=> El total actual de registros es de: " 
          << longarchivo/sizeof(Cedulado) << endl
          << "\n=> Entre el numero del registro a escribir: ";
    cin >> numreg;

  // VERIFICACION DEL NUMERO DE REGISTRO

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

    else {
        cout << "\n\n=> El registro existe y se procede a capturar"
             << "\n   los datos para su reescritura o modificacion "
             << "=>\n\n";
    }

    // Captura de los otros datos del registro

     cout << " \n=> Entre la cedula del registro a escribir: "; 
     cin >> c.cedula;
     cin.ignore();
     cout << "    Nombre : "; 
     cin.getline(c.nombre, 30);
     cout << "  Apellido : ";
     cin.getline(c.apellido, 30);
     cout << "    Sexo, M/F:  ";
     cin >> c.sexo;
     if(cin.fail()){ 
         clrscr();
         cout << "ERROR!!, pulse ENTER: ";
         getch(); 
         exit(1);
     }
    
     // Posicionamiento del puntero de escritura

     flujo.seekp( ((numreg - 1) * sizeof(Cedulado)), ios::beg);
     // Escritura del registro
     flujo.write((char*)(&c), sizeof(Cedulado)); 
     
     cout << "\n\n=> OTRO REGISTRO A ESCRIBIR ?, S/N:  ";
     cin >> respuesta;
  } while(respuesta == 'S' || respuesta == 's');
  

  flujo.close();
  cout << "\n\n"; 
  return 0;
}


