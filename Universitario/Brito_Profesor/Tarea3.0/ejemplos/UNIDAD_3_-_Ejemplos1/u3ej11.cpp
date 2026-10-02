#include <iostream>

using namespace std;

struct Triangulo
{
    double base;
    double altura;
};

int main(int argc, char** argv)
{
    Triangulo triangulo = {7.0, 7.5};
    double area = 0.0;

    /** Determinar el area del triangulo **/
    area = (triangulo.base * triangulo.altura) / 2;

    cout << "El area del triangulo es: "
         << area << endl;

    return 0;
}
