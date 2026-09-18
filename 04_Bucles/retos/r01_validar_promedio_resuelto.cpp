/* Siguiente Reto: Bucles (while o for)

El programa actual tiene un límite: pide la información una sola vez y termina. Si cometes un error al ingresar la nota, tienes que volver a correr el binario.
Para pasar al siguiente nivel de programación imperativa, implementaremos un bucle:
El objetivo: Que el programa pida el promedio repetidamente dentro de un bucle while hasta que el usuario ingrese una nota válida (entre 0 y 100). Si ingresa un número negativo o mayor a 100, le avisa del error y se lo vuelve a pedir sin cerrar la aplicación. */

#include <iostream>
using namespace std;

int main () {
    string nombre;
    int edad;
    float promedio;

    cout << "\n--------------------------" << endl;
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

    // Bucle para validar el promedio
    do {
        cout << "Ingrese su promedio acumulado (0-100): ";
        cin >> promedio;

        if (promedio < 0 || promedio > 100) {
            cout << "Error: Promedio invalido. Por favor, ingrese un valor entre 0 y 100." << endl;
        }
    } while (promedio < 0 || promedio > 100);

    // Condición para el promedio con rangos y validaciones
    if (promedio >= 90 && promedio <= 100) {
        cout << "Excelente - Calificacion A." << endl;
    } else if (promedio >= 80 && promedio < 90) {
        cout << "Muy Bueno - Calificacion B." << endl;
    } else if (promedio >= 70 && promedio < 80) {
        cout << "Bueno - Calificacion C." << endl;
    } else {
        cout << "Reprobado - Calificacion F." << endl;
    }

    cout << "\n--------------------------------" << endl;
    cout << "\nFicha Universitaria Interactiva" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio acumulado: " << promedio << endl; 
    cout << "Edad en 5 anios: " << edad + 5 << endl;
    cout << "\n--------------------------------" << endl;

    return 0;
}

/* Conceptos clave para guardar en tus notas

1. La estructura do-while frente al while tradicional
while (condición) (Pre-test): Evalúa primero. Si la condición es falsa desde el inicio, el bloque nunca se ejecuta. Requiere pedir el dato una vez fuera del bucle y volver a pedirlo dentro.
do { ... } while (condición); (Post-test): Ejecuta el bloque al menos una vez obligatoriamente y luego evalúa la condición al final.
Detalle de sintaxis: El while que cierra el do lleva obligatoriamente un punto y coma al final (;), a diferencia de los otros bucles:
C++
do {
    // Bloque de instrucciones
} while (condición); // <--- Punto y coma obligatorio
2. Limpieza de ramas muertas (Dead Code Removal)
En tu versión anterior con if-else tenías esta línea:
C++
if (promedio > 100 || promedio < 0) { ... }
En este nuevo código la eliminaste correctamente. Como el bucle do-while retiene al usuario hasta que introduce un número entre 0 y 100, para cuando el flujo de ejecución llega a la evaluación de letras (A, B, C, F), es matemáticamente imposible que la nota sea negativa o mayor a 100.
Siguiente paso: El bucle contador for y arreglos (arrays)
Hasta ahora el programa solo procesa un único estudiante con una sola materia. En la vida universitaria real se cursan varias asignaturas y se promedian.
Para dar el siguiente salto conceptual necesitamos dos herramientas:
Arreglos de tamaño fijo (arrays): Permiten guardar varios datos del mismo tipo en una sola variable:
C++
float calificaciones[4]; // Reserva espacio en memoria para 4 notas
calificaciones[0] = 85.5; // El índice siempre inicia en 0
El bucle for: Ideal para repetir una tarea un número exacto y conocido de veces:
C++
for (int i = 0; i < 4; i++) {
    // i toma los valores 0, 1, 2, 3
}
int i = 0: Inicializa la variable de control (el iterador).
i < 4: Condición de parada (se ejecuta mientras sea menor a 4).
i++: Incremento (i = i + 1) tras finalizar cada vuelta. */