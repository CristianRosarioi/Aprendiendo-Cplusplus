#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string msj = "Programando con C++ en INF-510";
    const char CHR = msj.at(8);

    cout << "Caracter de prueba: " << CHR
         << endl << endl;

    cout << "Es alfabetico? "
         << ((isalpha(CHR)) ? "Si" : "No") << endl;
    cout << "Es alfanumerico? "
         << ((isalnum(CHR)) ? "Si" : "No") << endl;
    cout << "Es un digito? "
         << ((isdigit(CHR)) ? "Si" : "No") << endl;
    cout << "Esta en minuscula? "
         << ((islower(CHR)) ? "Si" : "No") << endl;
    cout << "Esta en mayuscula? "
         << ((isupper(CHR)) ? "Si" : "No") << endl;
    cout << "Es un espacio en blanco? "
         << ((isspace(CHR)) ? "Si" : "No") << endl;
    cout << "Es un caracter imprimible? "
         << ((isprint(CHR)) ? "Si" : "No") << endl;

    return 0;
}
