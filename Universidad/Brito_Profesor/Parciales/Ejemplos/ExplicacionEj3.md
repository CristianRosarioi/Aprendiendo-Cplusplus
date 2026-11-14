# Simulacro de parcial 3 — Control de calificaciones en C++

Vamos con otro ejercicio al estilo del profesor Brito, pero esta vez cambiaremos un poco la lógica para practicar algo muy importante: arreglos, ciclos, funciones, búsqueda del mayor y menor, acumuladores y condicionales.

Será un programa sencillo, sin paso por referencia ni instrucciones avanzadas. Además, utilizaremos funciones con `return`, para que sigas practicando cómo se comunican con `main()`.

## 1. Enunciado del ejercicio

Desarrolle un programa en C++ que permita registrar las calificaciones de cinco estudiantes.

El programa debe cumplir los siguientes requisitos:

1. Crear una estructura `Estudiante` con nombre, edad y nota final.
2. Utilizar un arreglo para almacenar cinco estudiantes.
3. Solicitar los datos mediante un ciclo `for`.
4. Validar que las edades sean mayores que cero y las notas estén entre 0 y 100.
5. Crear una función que reciba una nota y devuelva si el estudiante está aprobado.
6. Crear una función que reciba dos notas y devuelva la mayor.
7. Mostrar los estudiantes con sus respectivas calificaciones.
8. Calcular el promedio general, la nota mayor y la cantidad de aprobados.
9. Utilizar `do-while` y `switch` para mostrar un menú.

Nota: utilizaremos 70 como nota mínima de aprobación para este ejercicio de práctica.

## 2. Código completo — `simulacro_3.cpp`

```cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Estructura de estudiantes
struct Estudiante {
    string nombre;
    int edad;
    double nota;
};

// Prototipos de las funciones
void mostrarMenu();
bool estaAprobado(double nota);
double obtenerMayor(double nota1, double nota2);

int main() {

    Estudiante estudiantes[5];

    int opcion;
    int aprobados;
    double suma;
    double promedio;
    double mayor;

    cout << fixed << setprecision(2);

    // Registrar los cinco estudiantes
    for (int i = 0; i < 5; i++) {

        cout << "\nESTUDIANTE " << i + 1 << endl;

        cout << "Nombre: ";
        cin >> estudiantes[i].nombre;

        cout << "Edad: ";
        cin >> estudiantes[i].edad;

        while (estudiantes[i].edad <= 0) {
            cout << "Edad invalida. Introduzca otra: ";
            cin >> estudiantes[i].edad;
        }

        cout << "Nota final: ";
        cin >> estudiantes[i].nota;

        while (estudiantes[i].nota < 0 ||
               estudiantes[i].nota > 100) {

            cout << "Nota invalida. Introduzca otra: ";
            cin >> estudiantes[i].nota;
        }
    }

    do {
        mostrarMenu();

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:
                cout << "\nLISTA DE ESTUDIANTES" << endl;

                for (int i = 0; i < 5; i++) {

                    cout << "\nNombre: "
                         << estudiantes[i].nombre << endl;

                    cout << "Edad: "
                         << estudiantes[i].edad << endl;

                    cout << "Nota: "
                         << estudiantes[i].nota << endl;

                    if (estaAprobado(estudiantes[i].nota)) {
                        cout << "Estado: Aprobado" << endl;
                    } else {
                        cout << "Estado: Reprobado" << endl;
                    }
                }
                break;

            case 2:
                suma = 0;
                aprobados = 0;
                mayor = estudiantes[0].nota;

                for (int i = 0; i < 5; i++) {

                    suma += estudiantes[i].nota;

                    mayor = obtenerMayor(
                        mayor, estudiantes[i].nota
                    );

                    if (estaAprobado(estudiantes[i].nota)) {
                        aprobados++;
                    }
                }

                promedio = suma / 5;

                cout << "\nESTADISTICAS" << endl;
                cout << "Promedio: " << promedio << endl;
                cout << "Nota mayor: " << mayor << endl;
                cout << "Aprobados: " << aprobados << endl;
                cout << "Reprobados: " << 5 - aprobados << endl;
                break;

            case 0:
                cout << "Programa finalizado." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 0);

    return 0;
}

// Funcion que muestra el menu
void mostrarMenu() {

    cout << "\n===== CONTROL DE CALIFICACIONES =====" << endl;
    cout << "1. Mostrar estudiantes" << endl;
    cout << "2. Calcular estadisticas" << endl;
    cout << "0. Salir" << endl;
}

// Funcion que verifica si aprobo
bool estaAprobado(double nota) {

    if (nota >= 70) {
        return true;
    }

    return false;
}

// Funcion que devuelve la nota mayor
double obtenerMayor(double nota1, double nota2) {

    if (nota1 > nota2) {
        return nota1;
    } else {
        return nota2;
    }
}
```

## 3. Explicación de las partes importantes

### A. La estructura y el arreglo

```cpp
struct Estudiante {
    string nombre;
    int edad;
    double nota;
};
```

Creamos una estructura que agrupa los datos de cada estudiante.

Después:

```cpp
Estudiante estudiantes[5];
```

Declaramos un arreglo que almacena cinco estructuras del tipo `Estudiante`.

Cada posición tiene sus propios datos:

| Posición         | Información        |
| ---------------- | ------------------ |
| `estudiantes[0]` | Primer estudiante  |
| `estudiantes[1]` | Segundo estudiante |
| `estudiantes[2]` | Tercer estudiante  |
| `estudiantes[3]` | Cuarto estudiante  |
| `estudiantes[4]` | Quinto estudiante  |

No estamos utilizando un vector en este simulacro; estamos practicando los arreglos de tamaño fijo.

### B. Registro mediante `for`

```cpp
for (int i = 0; i < 5; i++) {
    cout << "Nombre: ";
    cin >> estudiantes[i].nombre;

    cout << "Edad: ";
    cin >> estudiantes[i].edad;

    cout << "Nota: ";
    cin >> estudiantes[i].nota;
}
```

Este fragmento simplificado muestra la idea del registro; en el código completo también están las validaciones.

El ciclo se ejecuta cinco veces.

En cada vuelta, `i` cambia y permite acceder a una posición diferente del arreglo.

### C. Validación de los datos

```cpp
while (estudiantes[i].nota < 0 ||
       estudiantes[i].nota > 100) {

    cout << "Nota invalida. Introduzca otra: ";
    cin >> estudiantes[i].nota;
}
```

Esta condición rechaza notas menores que cero o mayores que cien.

El operador `||` significa OR (O).

El `while` continúa hasta que el usuario introduce una nota válida.

### D. Función `estaAprobado()`

```cpp
bool estaAprobado(double nota) {

    if (nota >= 70) {
        return true;
    }

    return false;
}
```

Esta función recibe una nota y devuelve un valor booleano.

- Si la nota es mayor o igual a 70, devuelve `true`.
- Si es menor que 70, devuelve `false`.

En `main()` podemos utilizarla directamente dentro de una condición:

```cpp
if (estaAprobado(estudiantes[i].nota)) {
    cout << "Aprobado" << endl;
} else {
    cout << "Reprobado" << endl;
}
```

Esto funciona porque `if` necesita una condición que pueda evaluarse como verdadera o falsa.

### E. Función `obtenerMayor()`

```cpp
double obtenerMayor(double nota1, double nota2) {

    if (nota1 > nota2) {
        return nota1;
    } else {
        return nota2;
    }
}
```

Esta función recibe dos notas y devuelve la mayor.

Por ejemplo:

```cpp
obtenerMayor(85, 93);
```

Devuelve `93`.

Ahora observa cómo se utiliza dentro del ciclo:

```cpp
mayor = obtenerMayor(mayor, estudiantes[i].nota);
```

Aquí está una de las partes que más debes practicar.

La variable `mayor` guarda la nota más alta encontrada hasta ese momento.

En cada vuelta enviamos dos valores a la función:

- La nota mayor que ya conocemos.
- La nota del estudiante actual.

La función compara ambos y devuelve el mayor.

Así vamos actualizando `mayor` a medida que recorremos el arreglo.

### F. Acumuladores y contadores

```cpp
suma = 0;
aprobados = 0;
mayor = estudiantes[0].nota;
```

Inicializamos los valores antes del ciclo.

Después:

```cpp
suma += estudiantes[i].nota;
```

Acumula las notas.

```cpp
aprobados++;
```

Cuenta los estudiantes aprobados.

Finalmente:

```cpp
promedio = suma / 5;
```

Calcula el promedio.

Y:

```cpp
cout << "Reprobados: " << 5 - aprobados << endl;
```

Calcula cuántos reprobaron restando los aprobados del total de estudiantes.

## 4. Simulación del cálculo de la nota mayor

Supongamos que las cinco notas son:

Cómo cambia la variable `mayor`

i = 075

i = 190

i = 265

i = 385

i = 495

Vuelta 1

Nota actual

# 75

Mayor acumulada

# 75

Inicializamos mayor con la primera nota.

&#x20;AnteriorSiguiente&#x20;

## 5. Ejemplo de ejecución

Si registramos estas notas:

| Estudiante | Nota | Estado    |
| ---------- | ---- | --------- |
| Juan       | 75   | Aprobado  |
| María      | 90   | Aprobado  |
| Pedro      | 65   | Reprobado |
| Ana        | 85   | Aprobado  |
| Luis       | 95   | Aprobado  |

Al seleccionar la opción 2:

```cpp
ESTADISTICAS
Promedio: 82.00
Nota mayor: 95.00
Aprobados: 4
Reprobados: 1
```

## 6. Qué debes practicar para el parcial

En este simulacro utilizamos:

| Concepto           | Aplicación                       |
| ------------------ | -------------------------------- |
| `struct`           | Guardar datos de cada estudiante |
| Arreglo fijo       | Guardar cinco estudiantes        |
| `for`              | Registrar y recorrer             |
| `while`            | Validar edades y notas           |
| `do-while`         | Repetir el menú                  |
| `switch`           | Seleccionar opciones             |
| `if-else`          | Tomar decisiones                 |
| Funciones `void`   | Mostrar menú                     |
| Funciones `bool`   | Validar aprobación               |
| Funciones `double` | Devolver nota mayor              |
| `return`           | Devolver resultados              |
| `+=`               | Acumular notas                   |
| `++`               | Contar aprobados                 |

Para practicar por tu cuenta, intenta agregar una función `obtenerMenor(double nota1, double nota2)` y utilizarla para encontrar la nota más baja. Luego cambia el programa para registrar cuatro estudiantes y calcular el promedio de sus edades.

Consejo para el parcial: fíjate en cómo una función puede recibir dos valores, compararlos y devolver uno, sin utilizar referencias. Si comprendes esa lógica, podrás aplicarla para encontrar precios mayores, salarios menores, notas máximas y muchos otros resultados.

Guarda este como `simulacro_3.cpp` en tu USB.