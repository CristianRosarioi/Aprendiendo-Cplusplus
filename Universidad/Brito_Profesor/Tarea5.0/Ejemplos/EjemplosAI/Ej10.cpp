#include <iostream>
using namespace std;

// Prototipos
void mostrarMenu();

double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);

int main() {
    int opcion;

    double numero1;
    double numero2;
    double resultado;

    do {
        mostrarMenu();

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        while (opcion < 0 || opcion > 4) {
            cout << "Opcion invalida: ";
            cin >> opcion;
        }

        if (opcion != 0) {

            cout << "Introduzca el primer numero: ";
            cin >> numero1;

            cout << "Introduzca el segundo numero: ";
            cin >> numero2;

            switch (opcion) {

                case 1:
                    resultado = sumar(numero1, numero2);
                    break;

                case 2:
                    resultado = restar(numero1, numero2);
                    break;

                case 3:
                    resultado = multiplicar(numero1, numero2);
                    break;

                case 4:
                    while (numero2 == 0) {
                        cout << "No se puede dividir entre cero."
                             << endl;

                        cout << "Introduzca otro divisor: ";
                        cin >> numero2;
                    }

                    resultado = dividir(numero1, numero2);
                    break;
            }

            cout << "Resultado: " << resultado << endl;
        }

    } while (opcion != 0);

    cout << "Programa finalizado." << endl;

    return 0;
}

// Funcion que muestra el menu
void mostrarMenu() {
    cout << "\nCALCULADORA" << endl;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "4. Dividir" << endl;
    cout << "0. Salir" << endl;
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