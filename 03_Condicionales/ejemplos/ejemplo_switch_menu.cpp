// Ejemplo: menu con switch
#include <iostream>
using namespace std;

int main() {
    int opcion;

    cout << "1. Ver notas" << endl;
    cout << "2. Ver horario" << endl;
    cout << "3. Salir" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Mostrando notas..." << endl;
            break;
        case 2:
            cout << "Mostrando horario..." << endl;
            break;
        case 3:
            cout << "Hasta luego" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
    }
    return 0;
}