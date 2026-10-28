#include <iostream>

using namespace std;

// Definicion de la estructura
struct Triangulo
{
    double base;
    double altura;
};

// Prototipos de las funciones
double calculaArea(Triangulo);
Triangulo creaTriangulo(double, double);

int main(int argc, char** argv)
{
    // Declaramos una variable tipo Triangulo llamada "tri"
    Triangulo tri;

    // Ejecutamos la funcion "creaTriangulo" la cual recibe dos
    // valores tipo double (uno para la base, otro para la altura)
    // retornando un valor tipo Triangulo el cual es asignado a la
    // variable "tri"
    tri = creaTriangulo(3.5, 8);

    // Desplegamos por pantalla el area del triangulo colocando
    // la invocacion o llamado de la funcion "calculaArea" como
    // uno de los valores pasados al cout
    cout << "El area del triangulo es: "
         << calculaArea(tri) << endl;

    return 0;
}

/**
 * Funcion    : calculaArea
 * Descripcion: Esta funcion recibe un valor tipo Triangulo (estructura)
 *              como argumento, en este caso le llamamos "b" al valor
 *              recibido, este valor es local a la funcion, solo tiene
 *              visibilidad dentro de ella.
 * Objetivo   : La funcion hace uso de la formula del calculo de la base
 *              de un triangulo (base x altura / 2).  Como la funcion
 *              recibe un argumento tipo Triangulo (estructura) entonces
 *              solamente debemos acceder a los miembros de la estructura
 *              recibida (base y altura) para poder aplicar la formula,
 *              esto es, si nuestro argumento tipo Triangulo es llamado b
 *              entonces la formula seria: b.base * b.altura / 2
 */
double calculaArea(Triangulo b)
{
    return b.base * b.altura / 2;
}

/**
 * Funcion    : creaTriangulo
 * Descripcion: Esta funcion recibe dos valores tipo "double" los cuales
 *              son necesarios para la creacion de un elemento tipo Triangulo,
 *              es decir, necesitamos un double que sera asignado como la base
 *              del triangulo y otro double que sera asignado como la altura
 *              del triangulo.
 * Objetivo   : La funcion declara una variable tipo Triangulo llamada "t", esta
 *              es una variable local cuyo objetivo es servir dentro de la funcion
 *              para luego ser retornado cuando ella ya este completa, es decir,
 *              con los valores correspondientes para sus miembros, esto es, que los
 *              dos argumentos que recibe la funcion (x, y) sean usados para aplicarlos
 *              a los miembros de una estructura tipo Triangulo respectivamente de esta
 *              forma: t.base = x; t.altura = y
 *              Finalmente la funcion luego de completar esta tarea, retorna el valor
 *              de "t", o sea, retorna el triangulo.
 */
Triangulo creaTriangulo(double x, double y)
{
    Triangulo t;
    t.base = x;
    t.altura = y;
    return t;
}
