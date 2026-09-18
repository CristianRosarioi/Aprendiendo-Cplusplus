// Ejemplo: clase Estudiante con constructor y metodos
#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;

public:
    Estudiante(string n, int e) {
        nombre = n;
        edad = e;
    }

    void mostrar() {
        cout << nombre << " (" << edad << " anos)" << endl;
    }

    void setNombre(string n) { nombre = n; }
    string getNombre() { return nombre; }
};

int main() {
    Estudiante e1("Cristian", 20);
    e1.mostrar();

    e1.setNombre("Chris");
    cout << "Nuevo nombre: " << e1.getNombre() << endl;
    return 0;
}