#include <iostream>

using namespace std;

void printMessage();

int main(int argc, char** argv)
{
    for (int i = 0; i < 10; i++)
    {
        printMessage();
    }

    return 0;
}

void printMessage()
{
    static int cantidadDeLlamadas;
    cantidadDeLlamadas++;
    cout << "Cantidad de veces que me han llamado: "
         << cantidadDeLlamadas << endl;
}
