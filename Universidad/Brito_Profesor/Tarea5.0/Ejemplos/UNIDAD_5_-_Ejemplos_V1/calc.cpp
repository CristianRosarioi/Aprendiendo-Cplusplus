#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
    const int CANT_ARGS_PERMITIDOS = 4;
    const string SUMA = "+";
    double num1 = 0;
    double num2 = 0;

    if (argc == CANT_ARGS_PERMITIDOS
        && argv[2] == SUMA)
    {
        num1 = atof(argv[1]);
        num2 = atof(argv[3]);

        cout << num1 + num2 << endl;
    }
    else
    {
        cout << "Uso: <numero> + <numero>"
             << endl;
    }

    return 0;
}
