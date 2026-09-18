// Ejemplo: lambdas (funciones anonimas) y sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    auto alCuadrado = [](int x) { return x * x; };
    cout << "5 al cuadrado = " << alCuadrado(5) << endl;

    vector<int> notas = {7, 9, 8, 6};
    sort(notas.begin(), notas.end());   // ordena de menor a mayor

    cout << "Notas ordenadas: ";
    for (auto n : notas) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}