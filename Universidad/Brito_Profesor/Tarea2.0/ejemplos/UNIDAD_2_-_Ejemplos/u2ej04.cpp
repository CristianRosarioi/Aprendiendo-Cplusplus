#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    unsigned int velocidad = 3700;
    string mensaje;

    if (velocidad >= 0 && velocidad < 300)
        mensaje = "Es un Automovil";
    else if (velocidad >= 300 && velocidad < 500)
        mensaje = "Es un Helicoptero";
    else if (velocidad >= 500 && velocidad < 1200)
        mensaje = "Es un Barco";
    else if (velocidad >= 1200 && velocidad < 2000)
        mensaje = "Es un Avion";
    else
        mensaje = "Waooo! es Superman!!";

    cout << mensaje << endl;

    return 0;
}
