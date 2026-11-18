// ********************************************************************************
// -----------------------------------------------------------------------------------------------------------------------
// File Access Flag  Significado
// -----------------------------------------------------------------------------------------------------------------------
// ios::app        Append Mode.  Si archivo ya existe, su contenido es preservado y toda la
//                 data es escrita al final del archivo.  Esta opcion causa que el archivo sea
//                 creado si el archivo no existe.
//
// ios::ate        Si el archivo ya existe, el programa va directamente al final de el.  La data
//                 puede ser escrita en cualquier parte del archivo.
//
// ios::binary     Binary Mode.   Cuando un archivo es abierto en modo binario, la data es
//                 escrita y leida en formato binario puro.  (El modo por defecto es Texto).
//
// ios::in         Input Mode.  La data sera leida del archivo.  Si el archivo no existe, no
//                 creado y la funcion open fallara.
//
// ios::out        Output Mode.  La data podra ser escrita al archivo.  Por defecto, el
//                 contenido del archivo sera borrado si el archivo ya existe.
//
// ios::trunc      Si el archivo ya existe, su contenido sera borrado (truncado).  Este es el
//                 el modo por defecto usado por ios::out.
// -----------------------------------------------------------------------------------------------------------------------
// ********************************************************************************

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream dataFile;

    cout << "Abriendo archivo...\n";
    // Abre el archivo en modo APPEND (agregar)
    dataFile.open("texto.txt", ios::out | ios::app);
    cout << "Escribiendo mas data en el archivo.\n";
    dataFile << "Canario" << endl;
    dataFile << "Pico Cruzado\n";
	dataFile << "Lechuza Cara Ceniza\n";
	dataFile << "Cigua Palmera\n";
    cout << "Cerrando el archivo.\n";
    // Cierra el archivo
    dataFile.close();

    cout << "Fin.\n";
    return 0;
}
