#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    double ventas = 325350.00;
    double incentivo = 0;
    const int TASA_INCENTIVO = 4;

    if (ventas >= 500000.0)
    {
        incentivo = ventas * (TASA_INCENTIVO / 100.0);
        cout << "Usted ha ganado un incentivo especial."
             << "\nEl monto de su incentivo es: "
             << incentivo << endl;
    }

    cout << "Las ventas fueron: " << ventas << endl;

    return 0;
}
