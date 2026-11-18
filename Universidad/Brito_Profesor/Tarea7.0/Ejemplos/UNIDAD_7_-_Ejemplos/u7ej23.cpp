#include <iostream>
#include <fstream>
using namespace std;

struct Ubicacion
{
   char nombre[40];
   double latitud;
   double longitud;
};

long byteNumero(int);
void muestraUbicacion(Ubicacion);

int main(int argc, char** argv)
{
    Ubicacion lugar;
    fstream ubicaciones;
    long bytes;
    int pos;

    ubicaciones.open("lugar.dat", ios::in | ios::binary);

    if (ubicaciones)
    {
        ubicaciones.seekg(0L, ios::end);
        bytes = ubicaciones.tellg();

        cout << "Existen " << bytes / sizeof(lugar)
             << " ubicaciones, cual desea visualizar (1 - "
             << bytes / sizeof(lugar) << ")? [0 - Salir]\n\n";

        do
        {
            cout << "Ubicacion No.: ";
            cin >> pos;

            if (pos == 0)
                break;
            else if (pos > bytes / sizeof(lugar) || pos < 0)
            {
                cout << "Numero de ubicacion incorrecto.\n\n";
                continue;
            }

            ubicaciones.seekg(byteNumero(pos), ios::beg);
            ubicaciones.read(reinterpret_cast<char *>(&lugar),
                             sizeof(lugar));
            muestraUbicacion(lugar);
        } while (true);
    }

    ubicaciones.close();

    return 0;
}

long byteNumero(int recNumero)
{
    return sizeof(Ubicacion) * (recNumero - 1);
}

void muestraUbicacion(Ubicacion record)
{
    cout << record.nombre << " -> "
         << "Latitud: " << record.latitud
         << " Longitud: " << record.longitud
         << endl << endl;
}
