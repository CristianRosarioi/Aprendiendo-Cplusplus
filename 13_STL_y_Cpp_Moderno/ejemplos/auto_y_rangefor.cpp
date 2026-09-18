// Ejemplo: auto y range-based for
#include <iostream>
#include <vector>
using namespace std;

int main() {
    auto x = 42;          // el compilador deduce int
    auto nota = 8.5;      // double

    cout << "x = " << x << ", nota = " << nota << endl;

    vector<int> notas = {8, 9, 7, 6};

    cout << "Mis notas: ";
    for (auto n : notas) {   // range-based for, sin indices
        cout << n << " ";
    }
    cout << endl;
    return 0;
}