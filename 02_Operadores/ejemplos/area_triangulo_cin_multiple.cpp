#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    double base;
    double altura;
    double areaTriangulo;

    cout << "INTRODUZCA LOS SIGUIENTES DATOS (base, altura)"
         << endl << endl;

    cin >> base >> altura;

    areaTriangulo = (base * altura) / 2;

    cout << "\n\nEl area del triangulo es: "
         << areaTriangulo
         << endl;

    return 0;
}
