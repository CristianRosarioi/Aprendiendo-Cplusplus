/*
Universidad Autónoma de Santo Domingo UASD
Centro UASD San Pedro, Escuela de informatica 5100-29
Introduccion a la Programacion
Cristian Rosario
Matricula: 100806653
*/

// Calculadora con argumentos de linea de comandos


#include <iostream>
#include <cstdlib>
using namespace std;

// Prototipos de las funciones
double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);

int main(int argc, char* argv[]) {

    double numero1, numero2;
    double resultado;
    char operacion;

    // Verificar cantidad de argumentos
    if (argc != 4) {
        cout << "Uso: calculadora numero1 operacion numero2"
             << endl;
        return 1;
    }

    // Convertir los argumentos a numeros
    numero1 = atof(argv[1]);
    operacion = argv[2][0];
    numero2 = atof(argv[3]);

    // Seleccionar la operacion
    switch (operacion) {

        case '+':
            resultado = sumar(numero1, numero2);
            break;

        case '-':
            resultado = restar(numero1, numero2);
            break;

        case '*':
            resultado = multiplicar(numero1, numero2);
            break;

        case '/':
            if (numero2 == 0) {
                cout << "Error: division entre cero." << endl;
                return 1;
            }

            resultado = dividir(numero1, numero2);
            break;

        default:
            cout << "Operacion no valida." << endl;
            return 1;
    }

    cout << "Resultado: " << resultado << endl;

    return 0;
}

// Funcion para sumar
double sumar(double a, double b) {
    return a + b;
}

// Funcion para restar
double restar(double a, double b) {
    return a - b;
}

// Funcion para multiplicar
double multiplicar(double a, double b) {
    return a * b;
}

// Funcion para dividir
double dividir(double a, double b) {
    return a / b;
}
