/* hacer una modificacion del otro programa, si es mayor y es mujer poner: sabias que tu nombre tiene tantas i, si es menor la oracion seria:tu nombre tiene tantas a. si es hombre y es mayor: sabias que tu nombre tiene tantas e y si es hombre y es menor sabias que nombre tine tantas o. */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int edad;
string nombre;
char sexo;
char vocal;
unsigned char letra;
unsigned int i;
int cantidad = 0;

int main () {
    cout << "Cuantos anos tienes? ";
    cin >> edad;
    cin.ignore();

    cout << "Cual es tu nombre completo? ";
    getline(cin, nombre);

    cout << "Cual es tu sexo? [F o M] ";
    cin >> sexo;

    if (sexo == 'F' || sexo == 'f') {
        if (edad >= 18) {
            vocal = 'i';
        } else {
            vocal = 'a';
        }
    } else if (sexo == 'M' || sexo == 'm') {
        if (edad >= 18) {
            vocal = 'e';
        } else {
            vocal = 'o';
        }
    } else {
        cout << "Sexo no valido. Escriba F o M." << endl;
        return 0;
    }

    for (i = 0; i < nombre.size(); i++) {
        letra = nombre.at(i);
        if (tolower(letra) == vocal) {
            cantidad++;
        }
    }

    cout << "Sabias que tu nombre tiene " << cantidad
         << " letras '" << vocal << "'?" << endl;

    return 0;
}
