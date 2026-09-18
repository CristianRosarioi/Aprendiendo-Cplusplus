// Ejemplo: enum con dias de la semana
#include <iostream>
using namespace std;

enum Dia { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };

int main() {
    Dia hoy = MIERCOLES;

    cout << "Valor interno de MIERCOLES: " << hoy << endl;

    if (hoy == LUNES) {
        cout << "Uf, lunes" << endl;
    } else if (hoy >= SABADO) {
        cout << "Es fin de semana" << endl;
    } else {
        cout << "Entre semana" << endl;
    }
    return 0;
}