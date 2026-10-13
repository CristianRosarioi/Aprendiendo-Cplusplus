/* RETO r02 - "Tu edad en el futuro"
Escribe un programa que:
1. Pida tu anio de nacimiento (int).
2. Pida un anio futuro (int).
3. Calcule y muestre cuantos anos tendras en ese anio futuro.
Pistas:
- la edad = anio_futuro - anio_nacimiento (sin considerar el mes).
- Declara: int anioNac, anioFuturo; */

#include <iostream>
using namespace std;

int anodenacimiento;
int anofuturo;
int edad;

int main() {
    cout << "caul es tu ano de nacimiento ?";
    cin >> anodenacimiento;

    cout << "dime un ano futuro";
    cin >> anofuturo;

    edad = anodenacimiento - anofuturo;

    cout << " en el futuro tu edad sera: " << edad << "anos" << endl;


    return 0;
}
