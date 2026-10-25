#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string comida = "Guineito con Spaguetti";
    string::iterator vIte = comida.begin();

    while (vIte != comida.end())
        cout << *vIte++ << endl;

    return 0;
}
