#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    double velocidad = 130.0;
    const double VELOCIDAD_PERMITIDA = 100.0;

    if (velocidad <= VELOCIDAD_PERMITIDA)
    {
        cout << "Velocidad dentro del limite permitido."
             << endl;
    }
    else
    {
        cout << "ALTO!" << endl
             << "Debe corregir su velocidad!\n";
    }

    return 0;
}
