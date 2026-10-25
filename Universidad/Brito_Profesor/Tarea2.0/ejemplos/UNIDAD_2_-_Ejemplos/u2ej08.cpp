#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int estacion = 3;

    switch (estacion)
    {
        case 1:
            cout << "Primavera" << endl;
            break;
        case 2:
            cout << "Verano" << endl;
            break;
        case 3:
            cout << "Otono" << endl;
            break;
        case 4:
            cout << "Invierno" << endl;
            break;
        default:
            cout << "Parametro invalido." << endl;
    }

    return 0;
}

