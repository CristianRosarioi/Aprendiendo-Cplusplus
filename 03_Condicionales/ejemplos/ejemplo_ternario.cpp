// Ejemplo: operador ternario (if en una linea)
#include <iostream>
using namespace std;

int main() {
    double nota;
    cout << "Nota: ";
    cin >> nota;

    // condicion ? valor_si_true : valor_si_false
    string estado = (nota >= 60) ? "Aprobado" : "Reprobado";
    cout << "Estado: " << estado << endl;
    return 0;
}