#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> edades; // Contenedor vacío: edades = []
    int numero;         // Variable temporal donde guardo un valor a la vez

    // 1. Asigno un valor a la variable
    numero = 25;
    // 2. Le paso la variable a push_back para que la agregue al vector
    edades.push_back(numero); // Ahora edades = [25]

    // Reutilizo la misma variable con otro dato
    numero = 30;
    edades.push_back(numero); // Ahora edades = [25, 30]

    // También puedes pasar el valor directo sin usar la variable:
    edades.push_back(18);     // Ahora edades = [25, 30, 18]

    return 0;
}

