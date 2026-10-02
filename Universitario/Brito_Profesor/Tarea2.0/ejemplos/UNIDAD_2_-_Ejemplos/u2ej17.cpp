#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string palabra;
    const string PALABRA_MAGICA = "SESAMO";
    int intentos = 0;

    while (true)
    {
        cout << "Entre la palabra magica (en mayusculas): ";
        getline(cin, palabra);

        intentos++;

        if (palabra == PALABRA_MAGICA)
            break;
    }

    cout << endl << "Necesitaste " << intentos
         << " para acertar la palabra magica." << endl;

    return 0;
}
