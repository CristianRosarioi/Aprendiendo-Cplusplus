/*
Enunciado: Calcular potencia con multiplicaciones, sin pow.
Algoritmo: iniciar en 1; multiplicar base para exponente positivo o
1/base para negativo; cero negativo no se puede calcular.
Ejemplo: entrada base 2, exponente -3 -> Resultado: 0.125
Limites: suponer entradas del tipo solicitado, cantidades que caben en int
y operaciones representables. Las cadenas UTF-8 se recorren por bytes;
acentos, enie y otros caracteres Unicode necesitan otro tratamiento.
*/
#include <iostream>
using namespace std;

int main() {
    double base; // Factor que se multiplica varias veces.
    int exponente; // Signo negativo indica multiplicar su inversa.
    double potencia = 1.0; // El producto vacio (exponente 0) vale 1.
    cout << "Base y exponente entero: "; cin >> base >> exponente;
    if (base == 0.0 && exponente < 0) {
        cout << "No se puede dividir entre cero." << endl;
        return 0;
    }
    int pendientes = exponente;
    if (exponente >= 0) {
        while (pendientes > 0) {
            potencia *= base; // Equivale a potencia = potencia * base.
            pendientes--; // Queda una multiplicacion menos.
        }
    } else {
        double inversa = 1.0 / base; // Base no nula, comprobada arriba.
        while (pendientes < 0) {
            potencia *= inversa;
            pendientes++; // Evita negar el minimo int.
        }
    }
    cout << "Resultado: " << potencia << endl;
    return 0;
}
