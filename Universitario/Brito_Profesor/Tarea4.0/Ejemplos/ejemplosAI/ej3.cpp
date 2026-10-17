/*3. Vector: insertar, eliminar y cambiar su tamaño
Practica las operaciones sobre un vector. Los comentarios indican el contenido después de cada cambio.

La lógica: los índices se actualizan cuando insertas o eliminas. Después de borrar, una misma posición puede contener otro valor.*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros;
    unsigned int i;

    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_back(30);
    // Contenido: 10, 20, 30

    numeros.insert(numeros.begin() + 1, 15);
    // Inserta antes del indice 1.
    // Contenido: 10, 15, 20, 30

    numeros.erase(numeros.begin() + 2);
    // Elimina el elemento del indice 2.
    // Contenido: 10, 15, 30

    numeros.pop_back();
    // Elimina el ultimo.
    // Contenido: 10, 15

    numeros.resize(4, 99);
    // Amplia hasta cuatro elementos; los nuevos valen 99.
    // Contenido: 10, 15, 99, 99

    cout << "Contenido final:" << endl;

    for (i = 0; i < numeros.size(); i++) {
        cout << numeros.at(i) << " ";
    }

    cout << "\nPrimero: " << numeros.front() << endl;
    cout << "Ultimo: " << numeros.back() << endl;
    cout << "Cantidad: " << numeros.size() << endl;

    numeros.clear();

    cout << "Cantidad despues de clear: "
         << numeros.size() << endl;

    return 0;
}