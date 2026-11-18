#include <iostream>
#include <fstream>

using namespace std;

struct Track
{
    int trackId;
    char titulo[40];
    int duracion;
};

int main()
{
    Track track;
    char continuar;
    fstream musicFile;
    int contador = 0;

    musicFile.open("musica.dat", ios::out | ios::binary);

    do
    {
        track.trackId = contador++;
        cout << "Titulo         : ";
        cin.getline(track.titulo, 40);
        cout << "Duracion (segs): ";
        cin >> track.duracion;

        musicFile.write(reinterpret_cast<char *>(&track), sizeof(track));

        cout << "\nDesea agregar otra cancion (s/n)? ";
        cin.get(continuar);
   } while (toupper(continuar) == 'S');

   musicFile.close();

   return 0;
}
