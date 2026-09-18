// Ejemplo: funcion void (no retorna nada)
#include <iostream>
#include <string>
using namespace std;

void saludar(string nombre) {
    cout << "Bienvenido, " << nombre << "!" << endl;
}

int main() {
    string nombre;
    cout << "Tu nombre: ";
    getline(cin, nombre);

    saludar(nombre);
    return 0;
}