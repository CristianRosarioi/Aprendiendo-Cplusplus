/*
Enunciado: Demostrar insert, erase y push_back en una misma cadena.
Conceptos: string, índices desde cero, modificación acumulativa.
Algoritmo: 1) Empezar con "Sol". 2) Insertar " de" en índice 3.
3) Borrar esos 3 caracteres. 4) Agregar '!' al final. Mostrar cada paso.
Ejemplo: Sol -> Sol de -> Sol -> Sol!
Estas operaciones figuran en el ejemplo u3ej01.cpp distribuido con unidad 3.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string texto = "Sol"; // Valor inicial sobre el que actúan los tres pasos.
    cout << "Inicial: " << texto << endl;

    // Índice 3 está justo después de 'l'; se añaden tres caracteres.
    texto.insert(3, " de");
    cout << "Tras insert(3, \" de\"): " << texto << endl;

    // erase(3,3) quita desde índice 3 exactamente tres caracteres.
    // Trabaja sobre el texto ya modificado, no sobre una copia original.
    texto.erase(3, 3);
    cout << "Tras erase(3, 3): " << texto << endl;

    texto.push_back('!'); // Un char (comillas simples) al final.
    cout << "Tras push_back('!'): " << texto << endl;
    return 0;
}
