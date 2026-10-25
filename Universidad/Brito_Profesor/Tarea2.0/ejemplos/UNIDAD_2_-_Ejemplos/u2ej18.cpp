#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int contador = 0;
    const unsigned int LIMITE = 20;

    /********************************************
     * Imprime todos los numeros del 1 al 20    *
     * excepto aquellos que son multiplos de 3  *
     ********************************************/

    while (++contador <= LIMITE)
    {
        if (contador % 3 == 0)
            continue;

        cout << "Contador: " << contador << endl;
    }

    cout << "Fin del programa." << endl;

    return 0;
}

