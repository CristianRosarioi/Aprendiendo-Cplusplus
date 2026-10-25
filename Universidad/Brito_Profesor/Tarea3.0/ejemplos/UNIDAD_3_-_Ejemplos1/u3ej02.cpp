#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string msj = "Vive como si fueras a morir manana, ";
    msj += "aprende como si fueras a vivir para siempre.";
    char chr;
    int posicion;
    int cnt = 0;

    cout << "Entre un caracter a buscar: ";
    cin >> chr;

    posicion = msj.find(chr);

    while (posicion != string::npos && posicion + 1 < msj.length())
    {
        cnt++;
        posicion = msj.find(chr, posicion + 1);
    }

    cout << "Hay " << cnt << " " << chr << " en la cadena.\n";

    return 0;
}
