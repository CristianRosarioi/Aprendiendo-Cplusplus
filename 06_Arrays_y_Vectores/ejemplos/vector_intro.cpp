// Ejemplo: std::vector (crece solo)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<float> notas;

    notas.push_back(8.5);
    notas.push_back(9.0);
    notas.push_back(7.5);

    cout << "Cantidad de notas: " << notas.size() << endl;

    for (int i = 0; i < notas.size(); i++) {
        cout << "Nota " << i + 1 << ": " << notas[i] << endl;
    }

    if (notas.empty()) {
        cout << "No hay notas" << endl;
    }
    return 0;
}