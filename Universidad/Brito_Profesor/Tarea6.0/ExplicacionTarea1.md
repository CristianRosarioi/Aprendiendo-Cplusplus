# Tarea Unidad VI — Ejercicio 1: Arreglo dinámico de puntuaciones

INF510 · Introducción a la Programación · UASD · Profesor Brito

Vamos a trabajar los ejercicios uno por uno, como acordamos. Cada ejercicio tendrá su enunciado, código completo, explicación de las instrucciones, ejemplos de ejecución y conceptos utilizados, para que puedas guardar todo en tu archivo `.md` de GitHub.

El mandato contiene cuatro ejercicios. Comenzamos únicamente con el Ejercicio 1 y no pasaremos al segundo hasta que me digas «siguiente».

## 1. Enunciado del profesor

Escriba un programa que asigne dinámicamente un arreglo lo suficientemente grande para almacenar un número de puntuaciones definido por el usuario.

Una vez introducidas todas las puntuaciones:

1. El arreglo debe enviarse a una función que lo ordene de forma ascendente.
2. Otra función debe calcular el promedio.
3. El programa debe mostrar las puntuaciones ordenadas.
4. Finalmente, debe mostrar la puntuación promedio.

El profesor sugiere estos prototipos:

```cpp
double *creaArreglo(int);
void leePuntuaciones(double *, int);
void ordena(double *, int);
double calculaPromedio(double *, int);
```

También proporciona el algoritmo de ordenamiento burbuja, que debemos utilizar.

### ¿Qué conceptos vamos a practicar?

- Punteros (`*`).
- Memoria dinámica (`new` y `delete[]`).
- Arreglos dinámicos.
- Funciones con parámetros.
- Funciones que devuelven punteros.
- Ciclos `for`, `while` y `do-while`.
- Condicionales `if`.
- Acumuladores.
- Ordenamiento por burbuja.
- Cálculo de promedios.

## 2. Código completo — `Ejercicio1.cpp`

Este código utiliza los cuatro prototipos sugeridos por el profesor y su algoritmo de burbuja. Solo ajustamos la variable temporal a `double` para no perder los decimales de las puntuaciones.

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

// Prototipos de las funciones
double *creaArreglo(int cantidad);
void leePuntuaciones(double *arreglo, int cantidad);
void ordena(double *arreglo, int cantidad);
double calculaPromedio(double *arreglo, int cantidad);

int main() {

    int cantidad;
    double *puntuaciones;
    double promedio;

    // Solicitar la cantidad de puntuaciones
    cout << "Cuantas puntuaciones desea introducir? ";
    cin >> cantidad;

    // Validar la cantidad
    while (cantidad <= 0) {
        cout << "Cantidad invalida. Introduzca otra: ";
        cin >> cantidad;
    }

    // Crear el arreglo dinamicamente
    puntuaciones = creaArreglo(cantidad);

    // Leer las puntuaciones
    leePuntuaciones(puntuaciones, cantidad);

    // Ordenar las puntuaciones
    ordena(puntuaciones, cantidad);

    // Calcular el promedio
    promedio = calculaPromedio(puntuaciones, cantidad);

    // Mostrar las puntuaciones ordenadas
    cout << "\nPUNTUACIONES ORDENADAS" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << puntuaciones[i] << endl;
    }

    // Mostrar el promedio
    cout << fixed << setprecision(2);

    cout << "\nPromedio de las puntuaciones: "
         << promedio << endl;

    // Liberar la memoria dinamica
    delete[] puntuaciones;

    puntuaciones = nullptr;

    return 0;
}


// Funcion que crea un arreglo dinamico
double *creaArreglo(int cantidad) {

    double *arreglo;

    arreglo = new double[cantidad];

    return arreglo;
}


// Funcion que lee las puntuaciones
void leePuntuaciones(double *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++) {

        cout << "Introduzca la puntuacion "
             << i + 1 << ": ";

        cin >> arreglo[i];
    }
}


// Funcion que ordena de forma ascendente
// Utiliza el metodo de la burbuja
void ordena(double *arreglo, int cantidad) {

    bool swap;
    double temp;

    do {

        swap = false;

        for (int i = 0; i < cantidad - 1; i++) {

            if (arreglo[i] > arreglo[i + 1]) {

                temp = arreglo[i];

                arreglo[i] = arreglo[i + 1];

                arreglo[i + 1] = temp;

                swap = true;
            }
        }

    } while (swap);
}


// Funcion que calcula el promedio
double calculaPromedio(double *arreglo, int cantidad) {

    double suma = 0;
    double promedio;

    for (int i = 0; i < cantidad; i++) {

        suma += arreglo[i];
    }

    promedio = suma / cantidad;

    return promedio;
}
```

## 3. ¿Cómo funciona nuestro programa?

Primero entendamos la secuencia general.

`main()`

Solicita cuántas puntuaciones registraremos

`creaArreglo(cantidad)`

Reserva la memoria necesaria con new

`leePuntuaciones(puntuaciones, cantidad)`

Registra los valores utilizando un for

`ordena(puntuaciones, cantidad)`

Organiza las puntuaciones de menor a mayor

`calculaPromedio(puntuaciones, cantidad)`

Suma las puntuaciones y devuelve el promedio

Mostrar resultados y liberar memoria

Imprime el arreglo, el promedio y utiliza delete[]

Ahora vamos a estudiar cada parte.

## 4. Explicación de las bibliotecas y prototipos

### Bibliotecas

```cpp
#include <iostream>
#include <iomanip>
using namespace std;
```

`iostream` permite utilizar `cin`, `cout` y `endl`.

`iomanip` permite utilizar `fixed` y `setprecision(2)` para mostrar el promedio con dos decimales.

`using namespace std;` evita escribir `std::cout`, `std::cin` y otros nombres con el prefijo `std::`.

### Los cuatro prototipos

```cpp
double *creaArreglo(int cantidad);
void leePuntuaciones(double *arreglo, int cantidad);
void ordena(double *arreglo, int cantidad);
double calculaPromedio(double *arreglo, int cantidad);
```

Veamos qué significa cada uno:

| Función             | Qué recibe                | Qué devuelve         |
| ------------------- | ------------------------- | -------------------- |
| `creaArreglo()`     | Un entero con la cantidad | Un puntero `double*` |
| `leePuntuaciones()` | Un puntero y la cantidad  | Nada (`void`)        |
| `ordena()`          | Un puntero y la cantidad  | Nada (`void`)        |
| `calculaPromedio()` | Un puntero y la cantidad  | Un número `double`   |

¿Por qué tres funciones reciben un puntero?

Porque necesitan trabajar con el arreglo creado dinámicamente. El puntero les permite acceder a sus elementos.

## 5. Explicación de `main()` línea por línea

### Declaración de variables

```cpp
int cantidad;
double *puntuaciones;
double promedio;
```

- `cantidad`: almacena cuántos números va a introducir el usuario.
- `puntuaciones`: es un puntero de tipo `double`. Más adelante guardará la dirección del arreglo dinámico.
- `promedio`: almacena el promedio calculado.

Observa que todavía no hemos creado el arreglo. Solamente declaramos el puntero.

### Solicitar la cantidad

```cpp
cout << "Cuantas puntuaciones desea introducir? ";
cin >> cantidad;
```

El usuario determina cuántas puntuaciones desea registrar.

Por ejemplo:

```cpp
Cuantas puntuaciones desea introducir? 4
```

Después validamos:

```cpp
while (cantidad <= 0) {
    cout << "Cantidad invalida. Introduzca otra: ";
    cin >> cantidad;
}
```

Esto impide que se utilice cero o una cantidad negativa.

El ejemplo supone que el usuario introduce números válidos por teclado.

### Crear el arreglo

```cpp
puntuaciones = creaArreglo(cantidad);
```

Aquí llamamos a nuestra primera función.

Le enviamos `cantidad` y recibimos una dirección de memoria.

Esa dirección se guarda en `puntuaciones`.

Si el usuario escribió `4`, la función reservará espacio para cuatro valores `double`.

### Leer las puntuaciones

```cpp
leePuntuaciones(puntuaciones, cantidad);
```

Enviamos el puntero y la cantidad de elementos.

La función utiliza esa información para solicitar y almacenar todos los números.

### Ordenar el arreglo

```cpp
ordena(puntuaciones, cantidad);
```

Enviamos el mismo arreglo a la función que lo ordenará.

Aquí es importante entender que no estamos creando otro arreglo: la función modifica las posiciones del arreglo existente.

### Calcular el promedio

```cpp
promedio = calculaPromedio(puntuaciones, cantidad);
```

La función recibe el arreglo y la cantidad, calcula el promedio y devuelve el resultado.

Ese resultado se guarda en `promedio`.

### Mostrar las puntuaciones

```cpp
for (int i = 0; i < cantidad; i++) {
    cout << puntuaciones[i] << endl;
}
```

Este ciclo muestra todos los elementos.

Si tenemos cuatro puntuaciones, recorre las posiciones `0`, `1`, `2` y `3`.

### Mostrar el promedio

```cpp
cout << fixed << setprecision(2);
```

Indica que los siguientes números decimales se mostrarán con dos cifras después del punto.

```cpp
cout << "\nPromedio de las puntuaciones: "
     << promedio << endl;
```

Imprime el resultado que nos devolvió la función.

### Liberar la memoria

```cpp
delete[] puntuaciones;
puntuaciones = nullptr;
```

`delete[]` libera el arreglo dinámico.

Después colocamos el puntero en `nullptr` para no conservar una dirección que ya no debemos utilizar.

Esto es fundamental en la Unidad VI: cuando reservamos un arreglo con `new[]`, debemos liberarlo con `delete[]`.

## 6. Función `creaArreglo()` — Memoria dinámica

Esta es la función que más nos interesa en la Unidad VI.

```cpp
double *creaArreglo(int cantidad) {

    double *arreglo;

    arreglo = new double[cantidad];

    return arreglo;
}
```

Vamos línea por línea.

### Primera línea

```cpp
double *creaArreglo(int cantidad)
```

La función se llama `creaArreglo`.

Recibe un entero llamado `cantidad`.

Su tipo de retorno es `double*`, es decir, devuelve un puntero a `double`.

### Segunda línea

```cpp
double *arreglo;
```

Declaramos un puntero local.

### Tercera línea

```cpp
arreglo = new double[cantidad];
```

Aquí ocurre la reserva dinámica de memoria.

Si `cantidad` vale 4, esta instrucción solicita espacio para almacenar cuatro números `double`.

### Cuarta línea

```cpp
return arreglo;
```

Devuelve la dirección de memoria que recibió de `new[]`.

Esa dirección llega a `main()`.

Ejemplo: cantidad = 4

[0]

## —

[1]

## —

[2]

## —

[3]

## —

Se reservan cuatro espacios. Sus valores todavía no han sido asignados por el programa.

`puntuaciones` apunta al primer elemento de este arreglo.

Pregunta importante: ¿por qué no utilizamos simplemente `double puntuaciones[4]`?

Porque el mandato exige que el usuario defina la cantidad y que la memoria se asigne dinámicamente.

## 7. Función `leePuntuaciones()`

```cpp
void leePuntuaciones(double *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++) {

        cout << "Introduzca la puntuacion "
             << i + 1 << ": ";

        cin >> arreglo[i];
    }
}
```

### Primera línea

```cpp
void leePuntuaciones(double *arreglo, int cantidad)
```

`void` significa que la función no devuelve un resultado.

Recibe dos parámetros:

- `double *arreglo`: acceso al arreglo dinámico.
- `int cantidad`: número de elementos que debemos registrar.

### El ciclo `for`

```cpp
for (int i = 0; i < cantidad; i++)
```

Comienza en `i = 0` y continúa hasta llegar al último elemento válido.

Si la cantidad es 4, se ejecuta cuatro veces.

### Mostrar el número de puntuación

```cpp
cout << "Introduzca la puntuacion "
     << i + 1 << ": ";
```

Utilizamos `i + 1` porque queremos mostrar:

```cpp
Introduzca la puntuacion 1:
Introduzca la puntuacion 2:
Introduzca la puntuacion 3:
Introduzca la puntuacion 4:
```

Pero internamente los índices empiezan en cero.

### Guardar el dato

```cpp
cin >> arreglo[i];
```

Guarda el valor introducido en la posición correspondiente.

Recuerda que:

```cpp
arreglo[i]
```

Es equivalente a:

```cpp
*(arreglo + i)
```

En este ejercicio utilizamos la notación de corchetes porque es más sencilla de leer y el primer mandato no exige exclusivamente la notación con asteriscos.

## 8. Función `ordena()` — Algoritmo de burbuja

Esta es probablemente la parte de lógica más compleja del ejercicio.

El profesor nos proporcionó el algoritmo, por lo que lo conservamos casi exactamente igual.

```cpp
void ordena(double *arreglo, int cantidad) {

    bool swap;
    double temp;

    do {

        swap = false;

        for (int i = 0; i < cantidad - 1; i++) {

            if (arreglo[i] > arreglo[i + 1]) {

                temp = arreglo[i];

                arreglo[i] = arreglo[i + 1];

                arreglo[i + 1] = temp;

                swap = true;
            }
        }

    } while (swap);
}
```

### ¿Qué es ordenar de forma ascendente?

Significa organizar los valores de menor a mayor.

Por ejemplo:

```cpp
Antes:    85.5   70   92   60
Despues:  60     70   85.5 92
```

### ¿Qué hace el algoritmo de burbuja?

Compara dos números vecinos.

Si el primero es mayor que el segundo, los intercambia.

Luego continúa con la siguiente pareja, hasta completar una pasada. Repite las pasadas mientras se hayan realizado intercambios.

### Explicación de cada instrucción

```cpp
bool swap;
```

Es una variable booleana. Nos ayudará a saber si se produjo algún intercambio durante una pasada.

```cpp
double temp;
```

Es una variable temporal que utilizamos para intercambiar dos puntuaciones.

La declaramos `double` porque las puntuaciones pueden tener decimales.

```cpp
do {
```

Inicia un ciclo que se ejecuta al menos una vez.

```cpp
swap = false;
```

Al comenzar cada pasada, suponemos que todavía no ha ocurrido ningún intercambio.

```cpp
for (int i = 0; i < cantidad - 1; i++)
```

Recorre las parejas de números consecutivos.

¿Por qué `cantidad - 1`?

Porque comparamos:

```cpp
arreglo[i]
```

con:

```cpp
arreglo[i + 1]
```

Si `cantidad` es 4, el último índice válido es 3. Por tanto, el último valor permitido de `i` es 2, para poder comparar las posiciones 2 y 3.

```cpp
if (arreglo[i] > arreglo[i + 1])
```

Comprueba si el número de la izquierda es mayor que el de la derecha.

Si es así, están en el orden equivocado y debemos intercambiarlos.

### El intercambio

Estas tres líneas son fundamentales:

```cpp
temp = arreglo[i];

arreglo[i] = arreglo[i + 1];

arreglo[i + 1] = temp;
```

Ejemplo: tenemos `85.5` y `70`.

Primero guardamos `85.5` en `temp`.

Después colocamos `70` en la posición donde estaba `85.5`.

Finalmente, colocamos el valor de `temp` en la posición siguiente.

Resultado:

```cpp
Antes:     85.5   70
Despues:   70     85.5
```

```cpp
swap = true;
```

Indica que ocurrió un intercambio y que debemos realizar otra pasada para comprobar si ya está completamente ordenado.

```cpp
} while (swap);
```

Repite el proceso mientras `swap` sea `true`.

Cuando una pasada completa no necesita hacer ningún intercambio, `swap` permanece en `false` y el algoritmo termina.

### Simulación interactiva del método burbuja

Ordenamiento por burbuja

Paso 1 de 8

Índice 0

## 85.5

Índice 1

## 70

Índice 2

## 92

Índice 3

## 60

Arreglo inicial, todavía sin ordenar.

&#x20;AnteriorSiguiente&#x20;

Lo principal que debes memorizar: el algoritmo de burbuja compara valores vecinos, los intercambia cuando están desordenados y repite hasta que no hace falta realizar más intercambios.

## 9. Función `calculaPromedio()`

Esta es más sencilla que la anterior.

```cpp
double calculaPromedio(double *arreglo, int cantidad) {

    double suma = 0;
    double promedio;

    for (int i = 0; i < cantidad; i++) {

        suma += arreglo[i];
    }

    promedio = suma / cantidad;

    return promedio;
}
```

### Explicación línea por línea

```cpp
double calculaPromedio(double *arreglo, int cantidad)
```

La función devuelve un `double` y recibe el puntero al arreglo y la cantidad de puntuaciones.

```cpp
double suma = 0;
```

Creamos un acumulador e inicializamos su valor en cero.

```cpp
double promedio;
```

Declaramos la variable que almacenará el resultado.

```cpp
for (int i = 0; i < cantidad; i++)
```

Recorre todas las puntuaciones.

```cpp
suma += arreglo[i];
```

Va acumulando cada valor.

Recuerda que:

```cpp
suma += arreglo[i];
```

Es equivalente a:

```cpp
suma = suma + arreglo[i];
```

Después:

```cpp
promedio = suma / cantidad;
```

Divide la suma entre el número de puntuaciones.

Finalmente:

```cpp
return promedio;
```

Devuelve el promedio calculado a `main()`.

### Ejemplo matemático

Si las puntuaciones son `85.5`, `70`, `92` y `60`:

\\[ \text{Suma} = 85.5+70+92+60=307.5 \\]

\\[ \text{Promedio} = \frac{307.5}{4}=76.875 \\]

Con dos decimales se muestra `76.88`.

## 10. Ejemplo de ejecución del programa

```cpp
Cuantas puntuaciones desea introducir? 4

Introduzca la puntuacion 1: 85.5
Introduzca la puntuacion 2: 70
Introduzca la puntuacion 3: 92
Introduzca la puntuacion 4: 60

PUNTUACIONES ORDENADAS
60
70
85.5
92

Promedio de las puntuaciones: 76.88
```

## 11. ¿Qué sucede con los punteros durante el programa?

Este punto es especialmente importante porque estamos trabajando la Unidad VI.

Observa:

```cpp
puntuaciones = creaArreglo(cantidad);
```

La función reserva memoria y devuelve un puntero.

Después utilizamos:

```cpp
leePuntuaciones(puntuaciones, cantidad);
```

La función recibe ese puntero y llena el arreglo.

Luego:

```cpp
ordena(puntuaciones, cantidad);
```

La función recibe un puntero que permite acceder al mismo arreglo y modificar sus posiciones.

Finalmente:

```cpp
promedio = calculaPromedio(puntuaciones, cantidad);
```

La función lee los datos y devuelve un resultado numérico.

No tenemos cuatro arreglos distintos. Las funciones están trabajando con el mismo arreglo dinámico, al que acceden mediante la dirección que reciben.

Esto también explica por qué `ordena()` es `void`: no necesita devolver otro arreglo, porque modifica directamente el existente.

## 12. Preguntas que debes saber responder

| Pregunta                            | Respuesta                                                       |
| ----------------------------------- | --------------------------------------------------------------- |
| ¿Por qué utilizamos `double *`?     | Porque trabajamos con direcciones de datos `double`             |
| ¿Qué hace `new double[cantidad]`?   | Reserva dinámicamente espacio para esa cantidad de números      |
| ¿Qué devuelve `creaArreglo()`?      | Un puntero al arreglo creado                                    |
| ¿Qué hace `leePuntuaciones()`?      | Solicita y almacena las puntuaciones                            |
| ¿Por qué `ordena()` utiliza `void`? | Porque modifica directamente los elementos del arreglo recibido |
| ¿Qué hace el algoritmo de burbuja?  | Compara e intercambia elementos vecinos hasta ordenar           |
| ¿Para qué sirve `temp`?             | Para guardar temporalmente un valor durante un intercambio      |
| ¿Por qué utilizamos `cantidad - 1`? | Para no acceder a una posición inexistente con `i + 1`          |
| ¿Qué hace `swap`?                   | Indica si ocurrió un intercambio durante una pasada             |
| ¿Qué devuelve `calculaPromedio()`?  | El promedio como número `double`                                |
| ¿Para qué sirve `delete[]`?         | Para liberar la memoria del arreglo dinámico                    |

## 13. Cómo compilarlo en tu Mac

Guarda el programa como `Ejercicio1.cpp`.

Desde la terminal, ejecuta:

```cpp
clang++ -std=c++17 Ejercicio1.cpp -o Ejercicio1
```

Después:

```cpp
./Ejercicio1
```

El mandato también exige entregar los archivos fuente `.cpp` y una captura de la ejecución, todo dentro de un archivo comprimido `.zip` o `.rar`.

Por eso, al terminar las cuatro tareas, necesitaremos los cuatro programas `.cpp` y sus respectivas capturas para preparar la entrega.

## 14. ¿Qué aprendimos con este primer ejercicio?

El objetivo no es solamente ordenar puntuaciones.

Lo más importante es comprender cómo se relacionan estos conceptos:

- `new[]` crea el arreglo dinámicamente.
- El puntero conserva la dirección del arreglo.
- Las funciones trabajan sobre ese arreglo recibiendo el puntero.
- `for` permite recorrer sus elementos.
- `do-while` y `if` permiten implementar el ordenamiento burbuja.
- `return` devuelve la dirección del arreglo o el promedio, según la función.
- `delete[]` libera la memoria cuando terminamos de utilizarla.

Un detalle importante del mandato: en el algoritmo que proporcionó el profesor, `temp` aparece como `int`. Nosotros utilizamos `double` porque el arreglo almacena puntuaciones `double` y un `int` perdería los decimales al realizar intercambios.

Nombre recomendado para guardar los apuntes: `Ejercicio1_Arreglo_Dinamico.md`.

Y el código fuente: `Ejercicio1.cpp`.

Cuando me digas «siguiente», pasamos al Ejercicio 2: redimensionar un arreglo dinámico, conservando este mismo formato de código y explicación detallada.