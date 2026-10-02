#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    double base;
    double altura;
    double areaTriangulo;

    cout << "INTRODUZCA LOS SIGUIENTES DATOS"
         << endl << endl;
    cout << "Base  : ";
    cin >> base;
    cout << "Altura: ";
    cin >> altura;

    areaTriangulo = (base * altura) / 2;

    cout << "\n\nEl area del triangulo es: "
         << areaTriangulo
         << endl;

    return 0;
}
