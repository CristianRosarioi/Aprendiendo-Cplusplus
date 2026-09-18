/* RETO r02 - "Contador de vocales"
Escribe un programa que:
1. Pida un nombre con getline.
2. Recorra el nombre con un for y cuente cuantas vocales tiene
   (a, e, i, o, u, en minuscula y mayuscula).
3. Muestre el total de vocales.
Pistas:
int vocales = 0;
for (int i = 0; i < nombre.length(); i++) {
    char c = tolower(nombre[i]);
    if (c == 'a' || c == 'e' || ...) vocales++;
}
tolower viene en <cctype>. */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    // TODO: escribe tu solucion aqui

    return 0;
}