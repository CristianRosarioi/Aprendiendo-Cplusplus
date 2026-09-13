// Rangos y condiciones compuestas (else if, &&)

/* Siguiente Reto: Rangos y condiciones compuestas (else if, &&)

En la vida real las notas universitarias no son solo aprobado/reprobado, tienen rangos y validaciones.
Mejora el bloque del promedio usando else if y operadores lógicos:
Si el promedio es mayor a 100 o menor a 0, imprime: Error: Promedio invalido.
Si está entre 90 y 100, imprime: Excelente - Calificacion A. (Usa el operador AND: &&).
Si está entre 80 y 89.9, imprime: Muy Bueno - Calificacion B.
Si está entre 70 y 79.9, imprime: Bueno - Calificacion C.
Si es menor a 70, imprime: Reprobado - Calificacion F.
Prueba escribir esa estructura if / else if / else cuidando los paréntesis y las minúsculas. */


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

    // Condición para el promedio con rangos y validaciones
    if (promedio > 100 || promedio < 0) {
        cout << "Error: Promedio invalido." << endl;
    } else if (promedio >= 90 && promedio <= 100) {
        cout << "Excelente - Calificacion A." << endl;
    } else if (promedio >= 80 && promedio < 90) {
        cout << "Muy Bueno - Calificacion B." << endl;
    } else if (promedio >= 70 && promedio < 80) {
        cout << "Bueno - Calificacion C." << endl;
    } else {
        cout << "Reprobado - Calificacion F." << endl;
    }

    cout << "\nFicha Universitaria Interactiva" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio acumulado: " << promedio << endl; 
    cout << "Edad en 5 anios: " << edad + 5 << endl;

    return 0;
}

/* Desglosemos paso a paso cada símbolo, operador y estructura nueva que apareció en este bloque de evaluación.
1. El operador OR lógico: ||
C++
if (promedio > 100 || promedio < 0)
Símbolo || (pleca doble o pipes): Representa la disyunción lógica O.
Comportamiento: La condición completa evalúa a verdadero (true) si al menos una de las expresiones a los lados se cumple.
Por qué se usa aquí: Una nota no puede ser mayor que 100 y menor que 0 al mismo tiempo; son casos excluyentes. Basta con que ocurra uno de los dos para clasificar el dato como un valor inválido.
Evaluación en cortocircuito (Short-circuit evaluation): Si la primera parte (promedio > 100) resulta verdadera, C++ ni siquiera evalúa la segunda parte (promedio < 0), porque el resultado final ya está garantizado como verdadero.
2. El operador AND lógico: &&
C++
else if (promedio >= 90 && promedio <= 100)
Símbolo && (doble ampersand): Representa la conjunción lógica Y.
Comportamiento: La condición completa evalúa a verdadero únicamente si ambas expresiones son verdaderas de forma simultánea.
Error común de sintaxis evitado: En matemáticas solemos escribir 90≤promedio≤100, pero en C++ eso no funciona. El compilador exige separar los límites en dos evaluaciones independientes unidas por &&: (promedio >= 90 && promedio <= 100).
3. La estructura encadenada: else if
C++
if (...) {
    // 1. Caso inválido
} else if (...) {
    // 2. Rango A
} else if (...) {
    // 3. Rango B
} else if (...) {
    // 4. Rango C
} else {
    // 5. Todo lo demás
}
Evaluación secuencial (en cascada): C++ revisa las condiciones de arriba hacia abajo, una por una. En el momento en que una sola resulta verdadera, ejecuta su bloque de código y se salta automáticamente todo el resto de la estructura.
Optimización implícita: Como el primer if ya filtró cualquier valor superior a 100 o inferior a 0, en los siguientes else if puedes asumir con total certeza que el número está en el rango seguro de 0 a 100.
El else final: Es la cláusula de descarte. Si ninguna de las comprobaciones anteriores fue verdadera (es decir, la nota no fue inválida ni fue ≥70), el flujo cae obligatoriamente aquí, garantizando que el estudiante reprobó con calificación F.
4. Tabla de operadores relacionales y lógicos
Operador	Significado	Ejemplo	Resultado si promedio = 85
>	Mayor que	promedio > 100	false
<	Menor que	promedio < 0	false
>=	Mayor o igual	promedio >= 80	true
<=	Menor o igual	promedio <= 90	true
==	Igual a (comparación)	promedio == 85	true
!=	Distinto de / No igual	promedio != 0	true
&&	AND lógico (ambos)	promedio >= 80 && promedio < 90	true
||	OR lógico (al menos uno)	promedio > 100 || promedio < 0	false
!	NOT lógico (negación)	!(promedio >= 70)	false
Nota sobre el doble igual (== vs =): En C++, un solo signo = es para asignación (int x = 10;), mientras que el doble signo == es para comparación lógica (if (x == 10)). Confundirlos dentro de un if es uno de los errores más comunes en la universidad. */


