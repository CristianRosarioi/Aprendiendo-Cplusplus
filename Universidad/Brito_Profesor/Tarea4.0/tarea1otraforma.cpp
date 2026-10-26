#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Bebida {
    string nombreBebida;
    double precioBebida;
    int cantidadEnMaquina;
};

int main() {
    vector<Bebida> bebidas;
    Bebida bebida;

    bebida.nombreBebida = "Botella de Agua";
    bebida.precioBebida = 20.00;
    bebida.cantidadEnMaquina = 20;
    bebidas.push_back(bebida);

    bebida.nombreBebida = "Coca Cola";
    bebida.precioBebida = 25.00;
    bebida.cantidadEnMaquina = 20;
    bebidas.push_back(bebida);

    bebida.nombreBebida = "Seven Up";
    bebida.precioBebida = 25.00;
    bebida.cantidadEnMaquina = 20;
    bebidas.push_back(bebida);

    bebida.nombreBebida = "Mountain Dew";
    bebida.precioBebida = 30.00;
    bebida.cantidadEnMaquina = 20;
    bebidas.push_back(bebida);

    bebida.nombreBebida = "Jugo V8";
    bebida.precioBebida = 50.00;
    bebida.cantidadEnMaquina = 20;
    bebidas.push_back(bebida);

    int opcion;
    double dinero;
    double cambio;
    double ganancias = 0.00;

    do {
        cout << "\nMAQUINA DE BEBIDAS" << endl;

        for (int i = 0; i < bebidas.size(); i++) {
            cout << i + 1 << ". "
                 << bebidas[i].nombreBebida
                 << " Precio: $" << bebidas[i].precioBebida
                 << " Existencia: "
                 << bebidas[i].cantidadEnMaquina << endl;
        }

        cout << "0. Salir" << endl;
        cout << "Seleccione una bebida: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= bebidas.size()) {
            int indice = opcion - 1;

            if (bebidas[indice].cantidadEnMaquina > 0) {
                do {
                    cout << "Introduzca el dinero (minimo $20.00): ";
                    cin >> dinero;

                    if (dinero < 20.00) {
                        cout << "El dinero no puede ser menor de $20.00."
                             << endl;
                    } else if (dinero < bebidas[indice].precioBebida) {
                        cout << "El dinero no es suficiente para la bebida."
                             << endl;
                    }
                } while (dinero < 20.00 ||
                         dinero < bebidas[indice].precioBebida);

                cambio = dinero - bebidas[indice].precioBebida;

                cout << "Bebida seleccionada: "
                     << bebidas[indice].nombreBebida << endl;
                cout << "Cambio: $" << cambio << endl;

                bebidas[indice].cantidadEnMaquina--;
                ganancias = ganancias + bebidas[indice].precioBebida;
            } else {
                cout << "Esta bebida esta agotada." << endl;
            }
        } else if (opcion != 0) {
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 0);

    cout << "Ganancias totales: $" << ganancias << endl;

    return 0;
}
