#include <iostream>
using namespace std;

void mostrarEdad(int edad) {
    cout << "Su edad es: " << edad << endl;
}

int main() {
    int edadUsuario;

    cout << "Introduzca su edad: ";
    cin >> edadUsuario;

    mostrarEdad(edadUsuario);

    return 0;
}
