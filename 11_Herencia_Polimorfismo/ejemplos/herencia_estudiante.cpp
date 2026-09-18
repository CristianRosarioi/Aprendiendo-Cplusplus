// Ejemplo: herencia Persona -> Estudiante
#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string nombre;

public:
    Persona(string n) : nombre(n) {}

    void saludar() {
        cout << "Hola, soy " << nombre << endl;
    }
};

class Estudiante : public Persona {
private:
    int matricula;

public:
    Estudiante(string n, int m) : Persona(n), matricula(m) {}

    void mostrarMatricula() {
        cout << nombre << " tiene matricula " << matricula << endl;
    }
};

int main() {
    Estudiante e("Cristian", 100806653);
    e.saludar();
    e.mostrarMatricula();
    return 0;
}