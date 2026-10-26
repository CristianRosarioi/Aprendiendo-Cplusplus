#include <iostream>
using namespace std;

int main() {
    double comida[3][7];
    double total = 0;
    double menor, mayor;

    for (int mono = 0; mono < 3; mono++) {
        cout << "\nMONO " << mono + 1 << endl;

        for (int dia = 0; dia < 7; dia++) {
            do {
                cout << "Cantidad de comida del dia "
                     << dia + 1 << ": ";
                cin >> comida[mono][dia];

                if (comida[mono][dia] < 0) {
                    cout << "La cantidad no puede ser negativa."
                         << endl;
                }
            } while (comida[mono][dia] < 0);

            total = total + comida[mono][dia];

            if (mono == 0 && dia == 0) {
                menor = comida[mono][dia];
                mayor = comida[mono][dia];
            } else {
                if (comida[mono][dia] < menor) {
                    menor = comida[mono][dia];
                }

                if (comida[mono][dia] > mayor) {
                    mayor = comida[mono][dia];
                }
            }
        }
    }

    cout << "\nREPORTE SEMANAL" << endl;
    cout << "Promedio diario de los tres monos: "
         << total / 7 << " libras" << endl;
    cout << "Menor cantidad de comida: "
         << menor << " libras" << endl;
    cout << "Mayor cantidad de comida: "
         << mayor << " libras" << endl;

    return 0;
}