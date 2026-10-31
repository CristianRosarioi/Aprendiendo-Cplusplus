#include <iostream>
using namespace std;

// Prototipos
void cambiarPorValor(int numero);
void cambiarPorReferencia(int &numero);

int main() {
    int edad = 20;

    cout << "Edad inicial: " << edad << endl;

    cambiarPorValor(edad);

    cout << "Despues de pasar por valor: "
         << edad << endl;

    cambiarPorReferencia(edad);

    cout << "Despues de pasar por referencia: "
         << edad << endl;

    return 0;
}

// Paso por valor
void cambiarPorValor(int numero) {
    numero = 30;
}

// Paso por referencia
void cambiarPorReferencia(int &numero) {
    numero = 40;
}