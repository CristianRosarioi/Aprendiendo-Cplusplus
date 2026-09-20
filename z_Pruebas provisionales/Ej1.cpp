#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    cout << "Total de argumentos: " << argc << endl;
    cout << "Nombre del programa: " << argv[0] << endl;

    if (argc > 1) {
        cout << "Primer argumento pasado: " << argv[1] << endl;
    }

    return 0;
}

