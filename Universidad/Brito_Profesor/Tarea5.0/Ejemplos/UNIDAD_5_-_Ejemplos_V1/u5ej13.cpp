#include <iostream>

using namespace std;

/** Pase por valor **/
void cambia(int);

int main(int argc, char** argv)
{
    int numero = 5;
    cambia(numero);
    cout << "En main() = "
         << numero << endl;
    return 0;
}

void cambia(int valor)
{
    valor += 8;
    cout << "En cambia() = "
         << valor << endl;
}
