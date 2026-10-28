#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

struct Rectangulo
{
    int ancho;
    int altura;
};

vector<Rectangulo> creaRectangulos(int);
void imprimeRectangulos(vector<Rectangulo>);
void dibujaRectangulo(Rectangulo, char);

int main(int argc, char** argv)
{
    vector<Rectangulo> rectangulos = creaRectangulos(5);
    imprimeRectangulos(rectangulos);
    return 0;
}

vector<Rectangulo> creaRectangulos(int cantidad)
{
    vector<Rectangulo> temp;
    Rectangulo r;
    srand(time(0));

    const int ANCHO = 40;
    const int ALTURA = 15;

    for (int i = 0; i < cantidad; i++)
    {
        r.ancho = rand() % ANCHO + 1;
        r.altura = rand() % ALTURA + 1;
        temp.push_back(r);
    }

    return temp;
}

void imprimeRectangulos(vector<Rectangulo> rects)
{
    char caracteres[6] = {'#','$','@','*','&','~'};
    srand(time(0));

    for (int i = 0; i < rects.size(); i++)
    {
        dibujaRectangulo(rects.at(i), caracteres[rand() % 6]);
    }
}

void dibujaRectangulo(Rectangulo r, char chr)
{
    for (int fila = 0; fila < r.altura; fila++)
    {
        for (int columna = 0; columna < r.ancho; columna++)
        {
            cout << chr;
        }

        cout << endl;
    }

    cout << endl << endl;
}
