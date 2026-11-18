#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Ubicacion
{
   char nombre[40];
   double latitud;
   double longitud;
};

int main(int argc, char** argv)
{
    Ubicacion lugar;
    fstream ubicaciones;

    ubicaciones.open("lugar.dat", ios::out | ios::binary);

    cout << "Ubicaciones [0 - para salir]\n\n";
    do
    {
        cout << "Lugar   : ";
        cin.getline(lugar.nombre, 40);

        if (strcmp(lugar.nombre, "0") == 0)
            break;

        cout << "Latitud : ";
        cin >> lugar.latitud;
        cout << "Longitud: ";
        cin >> lugar.longitud;
        cin.ignore();

        ubicaciones.write(reinterpret_cast<char *>(&lugar), sizeof(lugar));
    } while (true);

    ubicaciones.close();

    return 0;
}
