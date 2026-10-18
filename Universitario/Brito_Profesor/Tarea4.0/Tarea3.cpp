/*
Universidad Autónoma de Santo Domingo UASD
Centro UASD San Pedro, Escuela de informatica 5100-29
Introduccion a la Programacion
Cristian Rosario
Matricula: 100806653
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int MONOS = 3;
    const int DIAS = 7;

    double comida[MONOS][DIAS];

    double totalComida = 0;
    double promedioDiario;
    double menor;
    double mayor;

    int mono;
    int dia;

    // Capturar los datos de los tres monos.
    for (mono = 0; mono < MONOS; mono++) {
        cout << "\nDATOS DEL MONO " << mono + 1 << endl;

        for (dia = 0; dia < DIAS; dia++) {
            cout << "Libras de comida del dia "
                 << dia + 1 << ": ";

            cin >> comida[mono][dia];

            while (comida[mono][dia] < 0) {
                cout << "La cantidad no puede ser negativa."
                     << endl;

                cout << "Ingrese nuevamente las libras: ";
                cin >> comida[mono][dia];
            }
        }
    }

    // Tomar el primer dato como referencia.
    menor = comida[0][0];
    mayor = comida[0][0];

    // Procesar las 21 cantidades almacenadas.
    for (mono = 0; mono < MONOS; mono++) {
        for (dia = 0; dia < DIAS; dia++) {
            totalComida += comida[mono][dia];

            if (comida[mono][dia] < menor) {
                menor = comida[mono][dia];
            }

            if (comida[mono][dia] > mayor) {
                mayor = comida[mono][dia];
            }
        }
    }

    // Promedio por dia de los tres monos juntos.
    promedioDiario = totalComida / DIAS;

    cout << fixed << setprecision(2);

    cout << "\nREPORTE DE ALIMENTACION" << endl;

    cout << "Promedio diario de los tres monos juntos: "
         << promedioDiario << " libras" << endl;

    cout << "Menor cantidad ingerida por un mono en un dia: "
         << menor << " libras" << endl;

    cout << "Mayor cantidad ingerida por un mono en un dia: "
         << mayor << " libras" << endl;

    return 0;
}