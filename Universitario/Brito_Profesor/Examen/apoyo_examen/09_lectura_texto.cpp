/*
Enunciado: Leer edad y nombre completo, mostrar longitud y primer carácter.
Conceptos: string, getline, cin.ignore, size, at e índices desde cero.
Algoritmo: 1) Leer edad. 2) Descartar el ENTER pendiente. 3) Leer
nombre con espacios. 4) Mostrar longitud y, si existe, primer carácter.
Ejemplo: entrada 20, luego Ana Maria -> longitud 9, primer carácter A.
Se supone edad entera y escrita sola en su línea.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int edad; // Lectura previa para estudiar cómo se combina cin con getline.
    string nombre; // Almacena la línea completa, incluidos los espacios.
    cout << "Edad: ";
    cin >> edad;
    // cin >> deja el ENTER en la entrada; ignore() consume un carácter.
    // Se supone que después de la edad viene directamente ENTER.
    cin.ignore();
    cout << "Nombre completo: ";
    getline(cin, nombre); // cin >> nombre solo leería hasta el primer espacio.

    cout << "Edad: " << edad << ", longitud: " << nombre.size() << endl;
    // at(0) obtiene el primer carácter; una cadena vacía no tiene índice 0.
    if (!nombre.empty()) {
        cout << "Primer caracter: " << nombre.at(0) << endl;
    } else {
        cout << "El nombre esta vacio; no tiene primer caracter." << endl;
    }
    // size() mide unidades de almacenamiento (bytes en UTF-8), no letras Unicode.
    return 0;
}
