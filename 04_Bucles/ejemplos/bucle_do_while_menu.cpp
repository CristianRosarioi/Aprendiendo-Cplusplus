// Ejemplo: do-while para validar un dato (post-test)
#include <iostream>
using namespace std;

int main() {
    int opcion;

    do {
        cout << "Menu:" << endl;
        cout << "1. Notas" << endl;
        cout << "2. Horario" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion < 1 || opcion > 3) {
            cout << "Opcion invalida, intente de nuevo." << endl;
        }
    } while (opcion != 3);   // <-- punto y coma obligatorio

    cout << "Hasta luego" << endl;
    return 0;
}