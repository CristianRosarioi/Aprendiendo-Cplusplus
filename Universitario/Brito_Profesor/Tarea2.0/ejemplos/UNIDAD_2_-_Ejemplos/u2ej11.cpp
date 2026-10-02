#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    char seguir;

    do
    {
        cout << "Desea continuar: ";
        cin >> seguir;
    } while (seguir == 's' || seguir == 'S');

    cout << "Fin del programa." << endl;

    return 0;
}
