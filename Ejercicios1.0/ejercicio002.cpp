
// Condicionales simples (if / else) y operadores de comparación

/*Siguiente reto: Toma de decisiones (if / else) Modifiquemos este mismo programa para que analice los datos.
Añade las siguientes condiciones antes del return 0;:
Si la persona tiene 18 años o más, imprime: Estado: Mayor de edad. Si no, imprime: Estado: Menor de edad.
Si su promedio es mayor o igual a 70.0, imprime: Condición académica: Aprobado. Si es menor, imprime: Condición académica: Reprobado..*/

#include <iostream>
using namespace std;

int main() {
    string nombre;
    int edad;
    float promedio;

    cout << "Ingrese su nombre: ";
    cin >> nombre;

    cout << "Ingrese su edad: ";
    cin >> edad;

    // Condición para la edad
    if (edad >= 18) {
        cout << "Estado: Mayor de edad." << endl;
    } else {
        cout << "Eres menor de edad." << endl;
    }

    cout << "Ingrese su promedio acumulado: ";
    cin >> promedio;

    // Condición para el promedio
    if (promedio >= 70.0) {
        cout << "Aprobado." << endl;
    } else {
        cout << "Reprobado." << endl;
    }

    cout << "\nFicha Universitaria Interactiva" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio acumulado: " << promedio << endl; 
    cout << "Edad en 5 anios: " << edad + 5 << endl;

    return 0;
}


/*cuatro reglas estrictas de sintaxis en C++:
Sensibilidad a mayúsculas (case-sensitive): Las palabras reservadas en C++ van siempre en minúsculas: if, else, cout. Escribir If, Else o Cout genera un error de compilación.
Condición entre paréntesis ( ): La condición a evaluar debe ir obligatoriamente entre paréntesis: if (edad >= 18).
Operador mayor o igual (>=): El símbolo de mayor o menor siempre va primero y el igual después (>= o <=). Si pones =>, el compilador se confunde.
Comillas rectas ("): A veces el teclado o editor inserta comillas tipográficas curvadas (“ o ”). C++ solo acepta comillas rectas dobles estándar (").*/