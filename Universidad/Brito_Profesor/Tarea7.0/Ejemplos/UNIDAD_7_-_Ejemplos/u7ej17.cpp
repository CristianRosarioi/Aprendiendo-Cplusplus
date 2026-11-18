#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	fstream dataFile;
	string linea;

    cout << "Abriendo archivo...\n\n";
    dataFile.open("libros.txt", ios::in);

    if (dataFile.fail())
    {
        cout << "Error al abrir el archivo.\n";
        cout << "Puede que el archivo no exista.\n";
    }
    else
    {
        cout << "Leyendo el archivo...\n";
        while (!dataFile.eof())
        {
            getline(dataFile, linea);
            cout << linea << endl;
        }

        cout << "Cerrando archivo...\n";
        dataFile.close();
    }

    cout << "Fin del programa.\n";
    return 0;
}
