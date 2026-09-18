// Ejemplo: encapsulacion (cuenta bancaria)
#include <iostream>
using namespace std;

class Cuenta {
private:
    double saldo;

public:
    Cuenta(double inicial) {
        saldo = (inicial >= 0) ? inicial : 0;
    }

    void depositar(double monto) {
        if (monto > 0) saldo += monto;
    }

    bool retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            return true;
        }
        return false;
    }

    double getSaldo() { return saldo; }
};

int main() {
    Cuenta c(100);
    c.depositar(50);

    if (c.retirar(30)) {
        cout << "Retiro exitoso" << endl;
    } else {
        cout << "Saldo insuficiente" << endl;
    }

    cout << "Saldo: " << c.getSaldo() << endl;
    return 0;
}