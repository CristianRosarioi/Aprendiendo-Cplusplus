#include <iostream>

using namespace std;

struct Hotel
{
    string nombre;
    int estrellas;
};

int main(int argc, char** argv)
{
    void *puntero;

    Hotel hotel = {"Royalton", 5};
    string pelicula = "Interstellar";
    long valor = 1991;

    puntero = &pelicula;
    //puntero = &valor;
    //puntero = &hotel;

    string *str = (string *) puntero;
    cout << *str << endl;

    return 0;
}
