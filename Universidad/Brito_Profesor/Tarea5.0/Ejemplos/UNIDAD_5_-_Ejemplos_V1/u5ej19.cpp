#include <iostream>

using namespace std;

struct Triangulo
{
    // miembros dato
    double base;
    double altura;
    // miembros funcion
    double area();
};

void imprimeTriangulo(Triangulo);

int main(int argc, char** argv)
{
    Triangulo tri1 = {2.5, 4.8};
    Triangulo tri2 = {6.3, 9.2};
    imprimeTriangulo(tri1);
    imprimeTriangulo(tri2);
    return 0;
}

double Triangulo::area()
{
    return base * altura / 2;
}

void imprimeTriangulo(Triangulo t)
{
    cout << "\nBase  : " << t.base;
    cout << "\nAltura: " << t.altura;
    cout << "\nArea  : " << t.area() << endl;
}
