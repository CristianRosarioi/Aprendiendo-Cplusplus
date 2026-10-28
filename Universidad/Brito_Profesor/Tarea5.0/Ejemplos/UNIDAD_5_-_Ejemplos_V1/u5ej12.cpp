#include <iostream>

using namespace std;

struct Rectangulo
{
    double ancho;
    double altura;
};

struct Triangulo
{
    double base;
    double altura;
};

double calcAreaFigura(Triangulo);
double calcAreaFigura(Rectangulo);

int main(int argc, char** argv)
{
    Triangulo tri = {10.0, 15.0};
    Rectangulo rec = {15.5, 21.3};

    cout << calcAreaFigura(tri) << endl;
    cout << calcAreaFigura(rec) << endl;

    return 0;
}

double calcAreaFigura(Triangulo t)
{
    return t.base * t.altura / 2;
}

double calcAreaFigura(Rectangulo r)
{
    return r.ancho * r.altura;
}
