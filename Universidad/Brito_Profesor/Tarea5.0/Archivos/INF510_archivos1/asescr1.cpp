

  /* 
     asescr1.cpp
     Compilador: bcc32 5.50

     C++ /Ferreiras / Archivos / <fstream> /
         Archivos de texto/Creación

     Creacion de un archivo de texto, verificando su no existencia en
     el directorio suplido. 
 
 */

  # include <fstream>
  # include <string>
 
  using namespace std;

  // DECLARACION DE LAS VARIABLES PARA MANEJAR LOS CAMPOS 
  // DE CADA REGISTRO
   
   string matricula; 
   string nombre;
   string apellido;
   string indice;  
  
 int main(void){
    
      char NombreDeArchivo[30]; // Para capturar el nombre del archivo 
     
      cout <<"\n CREACION DE ARCHIVO DE TEXTO" << endl;
      cout <<"\n  Entre el nombre del archivo:  ";
      cin >> NombreDeArchivo;
    
      fstream Escritura(NombreDeArchivo, ios::app |ios::noreplace ); // 1:
        
      if(Escritura.fail()){
    
         Escritura.clear(ios::failbit);
         cout << "\n ERROR! NO SE PUDO ABRIR EL ARCHIVO, SE ABORTA EL PROCESO\n"
	    << "\nPulse ENTER para continuar ";
         system("pause");
         exit(0);
      }
    
     else{
        cout << endl << "EL ARCHIVO SE ABRIO EXITOSAMENTE"
               << endl << "SE PROCEDE A CAPTURAR LA INFORMACION PARA SU ESCRITURA"
               << endl;
     }  

    char resp;
    do{
        cin.ignore();
        cout << endl << "MATRICULA: ";
        getline(cin, matricula);
        cout << endl << "NOMBRE: ";
        getline(cin,  nombre);
        cout << endl << "APELLIDO: ";
        getline(cin, apellido);
        cout << endl << "INDICE [1.0-10.0]):  ";
        getline(cin, indice); // si se requiere hacer operaciones
                            // aritmeticas con indice
                            //  convertir con strtd en <stdlib>
     
        Escritura << matricula << " " << nombre << " " << apellido 
                  << " " << indice << "\n";

        cout << "\n\n ¿ OTRO REGISTRO A PROCESAR ? S/N:  ";
        cin >> resp;     
    }while( resp == 'S'|| resp == 's'  ); //  1 || -> 1; 0 || 0 -> 0
	   
    Escritura.close(); // 2:
    cout << "\n\nREGISTROS ESCRITOS EXITOSAMENTE, VERIFIQUE CON"
         << "\ntype " << NombreDeArchivo << endl << endl;
    system("pause"); 
    return 0;
 }

/*
                DOCUMENTACION DEL CODIGO
  
  Comentario # 1

  Crea un objeto de la clase fstream y lo asocia con un archivo real 
  en disco; ios::app lo abre para escritura no destructiva; Si el archivo
  suplido existe noreplace generaria  un error si no es usado el modo
  ios::app  o  ios::ate

Comentario # 2

  close() es funcion miembro de la clase fstreambase de la cual hereda  

                    EJECUCION


C:\Borland\BCC55\Bin>asescr1

 CREACION DE ARCHIVO DE TEXTO

  Entre el nombre del archivo:  agapito.dat

EL ARCHIVO SE ABRIO EXITOSAMENTE
SE PROCEDE A CAPTURAR LA INFORMACION PARA SU ESCRITURA

MATRICULA: 12345

NOMBRE: Angelina Maria

APELLIDO: Ortiz Sanchez

INDICE [1.0-10.0]):  4.5

 + OTRO REGISTRO A PROCESAR ? S/N:  s

MATRICULA: 23456

NOMBRE: belnarda rosamaria

APELLIDO: monteodeoca de los santos y cespedes

INDICE [1.0-10.0]):  5.6

 + OTRO REGISTRO A PROCESAR ? S/N:  n


REGISTROS ESCRITOS EXITOSAMENTE, VERIFIQUE
CON type agapito.dat

Press any key to continue . . .

C:\Borland\BCC55\Bin>type agapito.dat
12345  Angelina Maria  Ortiz Sanchez  4.5
23456  belnarda rosamaria  monteodeoca de los santos y cespedes  5.6

C:\Borland\BCC55\Bin>

*/