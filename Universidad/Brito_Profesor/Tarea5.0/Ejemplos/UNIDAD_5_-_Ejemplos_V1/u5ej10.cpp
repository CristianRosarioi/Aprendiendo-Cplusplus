#include <iostream>

using namespace std;

void imprimePostre(string = "Brownie", string = "Tres leche", string = "Frape de Macadamia");

int main(int argc, char** argv)
{
    imprimePostre("Chocolate");

    return 0;
}

void imprimePostre(string a, string b, string c)
{
    cout << "Postre 1: " << a << endl;
    cout << "Postre 2: " << b << endl;
    cout << "Postre 3: " << c << endl;
}
