// Ejemplo: polimorfismo con virtual
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sonar() {
        cout << "... silencio" << endl;
    }
    virtual ~Animal() {}
};

class Perro : public Animal {
public:
    void sonar() override {
        cout << "Guau guau" << endl;
    }
};

class Gato : public Animal {
public:
    void sonar() override {
        cout << "Miau" << endl;
    }
};

void presentar(Animal& a) {
    a.sonar();   // llama al sonar de la clase real del objeto
}

int main() {
    Perro p;
    Gato g;

    presentar(p);   // Guau guau
    presentar(g);   // Miau
    return 0;
}