#include <iostream>
#include <cstdlib>

using namespace std;

const unsigned int SUMA = 1;
const unsigned int RESTA = 2;
const unsigned int MULTIPLICA = 3;
const unsigned int DIVIDE = 4;
const unsigned int ERROR = 99;

int validaOperador(string operador);
double opera(double a, double b, int operador);

int main(int argc, char** argv)
{
    const unsigned int CANT_ARGUMENTOS = 4;

    double numA;
    double numB;
    string operadorStr;
    int operador;

    if (argc == CANT_ARGUMENTOS)
    {
        operadorStr = argv[2];
        operador = validaOperador(operadorStr);

        if (operador != ERROR)
        {
            numA = atof(argv[1]); // convierte a numero de punto flotante, atoi a entero
            numB = atof(argv[3]); // convierte a numero de punto flotante, atoi a entero
            cout << opera(numA, numB, operador) << endl;
        }
        else
        {
            cout << "Operador incorrecto!" << endl << endl
                 << "Uso: u5ej02 <numero> + <numero>" << endl;
        }
    }
    else
    {
        cout << "Numero incorrecto de argumentos!" << endl << endl
             << "Uso: u5ej02 <numero> + <numero>" << endl;
    }

    return 0;
}

int validaOperador(string operador)
{
    char op = operador.at(0);
    int resultado = 99;

    switch (op)
    {
        case '+':
            resultado = SUMA;
            break;
        case '-':
            resultado = RESTA;
            break;
        case 'x':
        case 'X':
            resultado = MULTIPLICA;
            break;
        case '/':
            resultado = DIVIDE;
            break;
        default:
            resultado = ERROR;
    }

    return resultado;
}

double opera(double a, double b, int operador)
{
    double resultado = 0;

    switch (operador)
    {
        case SUMA:
            resultado = a + b;
            break;
        case RESTA:
            resultado = a - b;
            break;
        case MULTIPLICA:
            resultado = a * b;
            break;
        case DIVIDE:
            resultado = a / b;
            break;
    }

    return resultado;
}
