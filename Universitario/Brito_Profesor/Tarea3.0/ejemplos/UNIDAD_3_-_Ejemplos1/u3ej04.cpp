#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string asignatura = "INF-510 Lenguaje C++";
    int contador = 0;

    for (int i = 0; i < asignatura.size(); i++)
    {
        if (isdigit(asignatura.at(i)))
            contador++;
    }

    cout << "Cantidad de digitos: " << contador << endl;

    return 0;
}
