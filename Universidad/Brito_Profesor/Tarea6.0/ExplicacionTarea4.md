# Tarea Unidad VI — Ejercicio 4: Crear una copia invertida de un arreglo utilizando punteros

INF510 · Introducción a la Programación · UASD · Profesor Brito

¡Vamos con el cuarto y último ejercicio de la Unidad VI!

Este ejercicio combina lo que hemos aprendido sobre punteros, memoria dinámica, arreglos, funciones, ciclos `for` y `return`.

La parte más importante será comprender cómo copiar los elementos de un arreglo en orden inverso, sin modificar el arreglo original.

Como siempre, te dejaré el código completo y después su explicación paso a paso, para que puedas guardarlo en tu archivo `.md`.

## 1. Enunciado del profesor

El mandato establece:

> Escriba una función que acepte un arreglo de enteros y la cantidad de elementos de dicho arreglo. La función debe crear una copia del arreglo, excepto que los valores de los elementos deben estar reversados en dicha copia. La función debe retornar un puntero que apunte al nuevo arreglo, debe demostrar el uso de la función en un programa completo.

### ¿Qué significa esto?

Supongamos que el usuario introduce cinco números:

```cpp
10  20  30  40  50
```

La función debe crear un arreglo nuevo con estos valores:

```cpp
50  40  30  20  10
```

Importante: el arreglo original debe conservar sus valores. No vamos a invertirlo directamente, sino crear una copia.

Así debe funcionar el ejercicio

Arreglo original

## 10

[0]

## 20

[1]

## 30

[2]

## 40

[3]

## 50

[4]

Crear una copia invertida

Nuevo arreglo

## 50

[0]

## 40

[1]

## 30

[2]

## 20

[3]

## 10

[4]

Los dos arreglos tienen el mismo tamaño, pero sus elementos están organizados en orden contrario.

## 2. Código completo — `Ejercicio4.cpp`

Para mantenernos dentro de lo estudiado, utilizaremos tres funciones:

- `leerNumeros()` para registrar los datos.
- `invertirArreglo()` para crear y devolver la copia invertida.
- `mostrarArreglo()` para imprimir los elementos.

```cpp

#include <iostream>
using namespace std;

// Prototipos de las funciones
void leerNumeros(int *arreglo, int cantidad);
int *invertirArreglo(int *arreglo, int cantidad);
void mostrarArreglo(int *arreglo, int cantidad);

int main() {

    int cantidad;

    int *numeros;
    int *invertido;

    // Solicitar la cantidad de numeros
    cout << "Cuantos numeros desea introducir? ";
    cin >> cantidad;

    // Validar la cantidad
    while (cantidad <= 0) {
        cout << "Cantidad invalida. Introduzca otra: ";
        cin >> cantidad;
    }

    // Crear el arreglo original dinamicamente
    numeros = new int[cantidad];

    // Registrar los numeros
    leerNumeros(numeros, cantidad);

    // Crear la copia invertida
    invertido = invertirArreglo(numeros, cantidad);

    // Mostrar el arreglo original
    cout << "\nARREGLO ORIGINAL" << endl;

    mostrarArreglo(numeros, cantidad);

    // Mostrar el arreglo invertido
    cout << "\nARREGLO INVERTIDO" << endl;

    mostrarArreglo(invertido, cantidad);

    // Liberar la memoria dinamica
    delete[] numeros;
    delete[] invertido;

    numeros = nullptr;
    invertido = nullptr;

    return 0;
}


// Funcion para registrar los numeros
void leerNumeros(int *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++) {

        cout << "Introduzca el numero " << i + 1 << ": ";

        cin >> arreglo[i];
    }
}


// Funcion que crea una copia invertida del arreglo
int *invertirArreglo(int *arreglo, int cantidad) {

    // Crear un nuevo arreglo dinamico
    int *nuevo = new int[cantidad];

    // Copiar los elementos en orden inverso
    for (int i = 0; i < cantidad; i++) {

        nuevo[i] = arreglo[cantidad - 1 - i];
    }

    // Devolver el puntero al nuevo arreglo
    return nuevo;
}


// Funcion para mostrar los elementos del arreglo
void mostrarArreglo(int *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++) {

        cout << arreglo[i] << " ";
    }

    cout << endl;
}

```

# 3. ¿Cómo funciona el programa?

Vamos a visualizar su funcionamiento general antes de estudiar cada línea.

`main()`

Solicita cuántos números desea introducir el usuario

`new int[cantidad]`

Crea el arreglo original en memoria dinámica

`leerNumeros()`

Registra los números introducidos por el usuario

`invertirArreglo()`

Crea otro arreglo, copia los valores al revés y devuelve un puntero

`mostrarArreglo()`

Muestra el arreglo original y después la copia invertida

`delete[]`

Libera la memoria dinámica de ambos arreglos

# 4. Bibliotecas y prototipos

### Biblioteca

```cpp
#include <iostream>
using namespace std;
```

`iostream` permite utilizar las instrucciones `cin`, `cout` y `endl`.

`using namespace std;` evita tener que escribir `std::` delante de cada una.

### Prototipos

```cpp
void leerNumeros(int *arreglo, int cantidad);
int *invertirArreglo(int *arreglo, int cantidad);
void mostrarArreglo(int *arreglo, int cantidad);
```

La palabra `void` indica que la función no devuelve un resultado mediante `return`.

Pero fíjate en la segunda:

```cpp
int *invertirArreglo(int *arreglo, int cantidad);
```

Esta devuelve un puntero a entero (`int*`).

¿Por qué? Porque la función crea un nuevo arreglo dinámico y necesita devolver su dirección.

| Función             | Parámetros         | Retorno |
| ------------------- | ------------------ | ------- |
| `leerNumeros()`     | Puntero y cantidad | `void`  |
| `invertirArreglo()` | Puntero y cantidad | `int*`  |
| `mostrarArreglo()`  | Puntero y cantidad | `void`  |

# 5. Explicación de `main()` línea por línea

## A. Declaración de las variables

```
int cantidad;

int *numeros;
int *invertido;
```

`cantidad`: almacena el número de elementos que tendrá el arreglo.

`numeros`: es un puntero que guardará la dirección del arreglo original.

`invertido`: es otro puntero que guardará la dirección del nuevo arreglo.

Observa algo importante:

```cpp
int *numeros;
```

Esta instrucción todavía no reserva memoria para un arreglo. Solamente declara un puntero.

La memoria se reservará después con `new[]`.

## B. Solicitar la cantidad

```cpp
cout << "Cuantos numeros desea introducir? ";
cin >> cantidad;
```

Pedimos al usuario cuántos valores desea registrar.

Por ejemplo:

```cpp
Cuantos numeros desea introducir? 5
```

Después validamos:

```cpp
while (cantidad <= 0) {
    cout << "Cantidad invalida. Introduzca otra: ";
    cin >> cantidad;
}
```

El `while` impide continuar si el usuario introduce cero o un número negativo.

Recuerda que necesitamos una cantidad positiva para crear el arreglo.

## C. Crear el arreglo original

```cpp
numeros = new int[cantidad];
```

Esta instrucción utiliza el operador `new[]` que estudiamos en la Unidad VI.

Si `cantidad` vale 5, reservamos memoria para cinco números enteros.

La dirección del primer elemento queda guardada en el puntero `numeros`.

## D. Registrar los números

```cpp
leerNumeros(numeros, cantidad);
```

Aquí llamamos a nuestra primera función.

Le enviamos dos argumentos:

- `numeros`, que contiene la dirección del arreglo.
- `cantidad`, que indica cuántos elementos debemos registrar.

La función recibe esa información y guarda los números dentro del arreglo original.

## E. Crear la copia invertida

```
invertido = invertirArreglo(numeros, cantidad);
```

Esta es una de las instrucciones más importantes del programa.

Primero, llamamos a `invertirArreglo()`.

La función recibe el arreglo original y su tamaño.

Después crea un nuevo arreglo e invierte el orden de sus elementos.

Finalmente, devuelve un puntero a ese nuevo arreglo.

Esa dirección se guarda en:

```cpp
invertido
```

Ahora tenemos dos punteros diferentes, cada uno apuntando a un arreglo distinto.

## F. Mostrar los arreglos

```cpp
cout << "\nARREGLO ORIGINAL" << endl;

mostrarArreglo(numeros, cantidad);
```

Muestra los valores originales.

Después:

```cpp
cout << "\nARREGLO INVERTIDO" << endl;

mostrarArreglo(invertido, cantidad);
```

Muestra los valores invertidos.

Observa que utilizamos la misma función `mostrarArreglo()` dos veces. No necesitamos crear una función diferente para cada arreglo.

## G. Liberar la memoria

```cpp
delete[] numeros;
delete[] invertido;
```

Esta parte es fundamental.

Como creamos dos arreglos utilizando `new[]`, debemos liberar ambas reservas.

Por eso escribimos dos instrucciones `delete[]`.

Después:

```cpp
numeros = nullptr;
invertido = nullptr;
```

Dejamos los punteros sin apuntar a las zonas de memoria liberadas.

Y finalmente:

```cpp
return 0;
```

Indica que `main()` terminó correctamente.

# 6. Función `leerNumeros()`

```cpp
void leerNumeros(int *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++) {

        cout << "Introduzca el numero " << i + 1 << ": ";

        cin >> arreglo[i];
    }
}
```

Vamos a analizarla.

### Declaración

```cpp
void leerNumeros(int *arreglo, int cantidad)
```

Esta función recibe un puntero a entero y la cantidad de elementos.

No devuelve un resultado, por eso utilizamos `void`.

### Ciclo `for`

```cpp
for (int i = 0; i < cantidad; i++)
```

Recorre las posiciones del arreglo.

Si `cantidad = 5`, los valores de `i` serán:

```cpp
0, 1, 2, 3, 4
```

### Mostrar el número solicitado

```cpp
cout << "Introduzca el numero " << i + 1 << ": ";
```

Utilizamos `i + 1` solamente para mostrar una numeración más natural al usuario.

Internamente el arreglo comienza en cero.

### Guardar el número

```cpp
cin >> arreglo[i];
```

Guarda el dato introducido en la posición correspondiente.

Como `arreglo` es un puntero, también podríamos utilizar:

```cpp
cin >> *(arreglo + i);
```

Ambas formas funcionan.

En el Ejercicio 3 utilizamos obligatoriamente la notación con asteriscos porque el profesor lo solicitaba expresamente.

En este ejercicio no existe esa condición, por lo que usamos `arreglo[i]` para mantener el código sencillo.

# 7. Función `invertirArreglo()` — La parte más importante

Esta función contiene la lógica principal del ejercicio.

```cpp
int *invertirArreglo(int *arreglo, int cantidad) {

    int *nuevo = new int[cantidad];

    for (int i = 0; i < cantidad; i++) {

        nuevo[i] = arreglo[cantidad - 1 - i];
    }

    return nuevo;
}
```

Vamos a entenderla completamente.

## A. Declaración

```cpp
int *invertirArreglo(int *arreglo, int cantidad)
```

La función se llama `invertirArreglo`.

Recibe dos argumentos:

- Un puntero al arreglo original.
- La cantidad de elementos.

Y devuelve un `int*`, es decir, un puntero al nuevo arreglo.

## B. Crear el nuevo arreglo

```cpp
int *nuevo = new int[cantidad];
```

Aquí reservamos memoria para un segundo arreglo.

Si el original tiene cinco elementos, el nuevo también tendrá cinco.

La diferencia es que sus valores estarán en orden inverso.

¿Por qué creamos otro arreglo?

Porque el enunciado exige una copia.

Si modificáramos directamente el arreglo original, no estaríamos cumpliendo exactamente lo solicitado.

## C. Recorrer el nuevo arreglo

```cpp
for (int i = 0; i < cantidad; i++)
```

Utilizamos un ciclo `for` para recorrer todas las posiciones del nuevo arreglo.

El ciclo comienza en 0 y termina en `cantidad - 1`.

## D. La instrucción que invierte los elementos

Esta es la línea más importante:

```cpp
nuevo[i] = arreglo[cantidad - 1 - i];
```

Debes aprender a explicar exactamente qué sucede aquí.

A la izquierda tenemos:

```cpp
nuevo[i]
```

Esta es la posición del nuevo arreglo donde vamos a guardar un valor.

A la derecha tenemos:

```cpp
arreglo[cantidad - 1 - i]
```

Esta expresión obtiene los elementos del arreglo original desde el último hasta el primero.

### ¿Por qué utilizamos `cantidad - 1 - i`?

Porque los índices de los arreglos comienzan en cero.

Si tenemos cinco elementos:

```cpp
10  20  30  40  50
```

Los índices son:

| Índice | Valor |
| ------ | ----- |
| 0      | 10    |
| 1      | 20    |
| 2      | 30    |
| 3      | 40    |
| 4      | 50    |

La última posición es `4`, no `5`.

Por eso utilizamos:

```cpp
cantidad - 1
```

Ahora queremos ir retrocediendo desde esa última posición.

Para lograrlo, restamos `i`:

```cpp
cantidad - 1 - i
```

Así, mientras `i` aumenta, el índice del arreglo original disminuye.

# 8. Simulación del ciclo `for` paso a paso

Este es el concepto que más quiero que domines.

Supongamos que:

```cpp
cantidad = 5;
```

Y el arreglo original tiene:

```cpp
10 20 30 40 50
```

Así trabaja nuestro ciclo:

| Vuelta (`i`) | `cantidad - 1 - i` | Valor copiado |
| ------------ | ------------------ | ------------- |
| 0            | 5 - 1 - 0 = 4      | 50            |
| 1            | 5 - 1 - 1 = 3      | 40            |
| 2            | 5 - 1 - 2 = 2      | 30            |
| 3            | 5 - 1 - 3 = 1      | 20            |
| 4            | 5 - 1 - 4 = 0      | 10            |

### Prueba la inversión paso a paso

Cómo se construye el arreglo invertido

Vuelta 1 de 5

Arreglo original

10

[0]

20

[1]

30

[2]

40

[3]

50

[4]

Nuevo arreglo

50

[0]

—

[1]

—

[2]

—

[3]

—

[4]

Vuelta i = 0

Índice original = 5 - 1 - 0 = 4

`nuevo[{paso}] = arreglo[{4-paso}]`

Copiamos el valor 50.

&#x20;AnteriorSiguiente&#x20;

### Primera vuelta

```cpp
i = 0;
```

La instrucción queda:

```cpp
nuevo[0] = arreglo[4];
```

Guardamos `50` en la primera posición del nuevo arreglo.

### Segunda vuelta

```cpp
i = 1;
```

La instrucción equivale a:

```cpp
nuevo[1] = arreglo[3];
```

Guardamos `40` en la segunda posición.

Y así sucesivamente, hasta copiar todos los valores.

La clave: el índice del arreglo nuevo avanza normalmente, pero el índice del original retrocede.

# 9. ¿Por qué utilizamos `return nuevo`?

Después de invertir todos los elementos tenemos:

```cpp
return nuevo;
```

Recuerda que `nuevo` es un puntero.

La función devuelve la dirección del primer elemento del arreglo creado mediante `new[]`.

En `main()` recibimos esa dirección:

```cpp
invertido = invertirArreglo(numeros, cantidad);
```

Ahora podemos utilizar:

```cpp
invertido[0]
```

Para acceder al primer elemento del arreglo invertido.

Y:

```cpp
invertido[1]
```

Para acceder al segundo.

### ¿Por qué no utilizamos `void`?

Porque el profesor exige que la función retorne un puntero al nuevo arreglo.

Además, el arreglo fue creado dentro de la función mediante `new[]`, y necesitamos conservar su dirección para utilizarlo desde `main()`.

Es importante que recuerdes que una reserva realizada con `new[]` sigue existiendo después de que termina la función, hasta que se libera mediante `delete[]`.

# 10. Función `mostrarArreglo()`

```cpp
void mostrarArreglo(int *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++) {

        cout << arreglo[i] << " ";
    }

    cout << endl;
}
```

Esta función permite mostrar cualquier arreglo de enteros, siempre que le enviemos su puntero y la cantidad de elementos.

### Declaración

```cpp
void mostrarArreglo(int *arreglo, int cantidad)
```

Utilizamos `void` porque la función solo imprime valores y no necesita devolver nada.

### Ciclo `for`

```cpp
for (int i = 0; i < cantidad; i++)
```

Recorre todas las posiciones válidas.

### Imprimir cada elemento

```cpp
cout << arreglo[i] << " ";
```

Muestra los números separados por espacios.

### ¿Qué ventaja tiene esta función?

No necesitamos repetir el ciclo de impresión para cada arreglo.

Podemos escribir:

```cpp
mostrarArreglo(numeros, cantidad);
```

Y después:

```cpp
mostrarArreglo(invertido, cantidad);
```

La función trabaja con el arreglo que reciba.

Esto es precisamente una de las ventajas de organizar el programa mediante funciones.

# 11. Ejemplos de ejecución

## Ejemplo A — Cinco números

```cpp
Cuantos numeros desea introducir? 5

Introduzca el numero 1: 10
Introduzca el numero 2: 20
Introduzca el numero 3: 30
Introduzca el numero 4: 40
Introduzca el numero 5: 50

ARREGLO ORIGINAL
10 20 30 40 50

ARREGLO INVERTIDO
50 40 30 20 10
```

## Ejemplo B — Tres números

```cpp
Cuantos numeros desea introducir? 3

Introduzca el numero 1: 8
Introduzca el numero 2: 15
Introduzca el numero 3: 22

ARREGLO ORIGINAL
8 15 22

ARREGLO INVERTIDO
22 15 8
```

## Ejemplo C — Un solo número

```cpp
Cuantos numeros desea introducir? 1

Introduzca el numero 1: 75

ARREGLO ORIGINAL
75

ARREGLO INVERTIDO
75
```

En este caso funciona correctamente porque invertir un arreglo de un solo elemento no produce ningún cambio.

# 12. Conceptos de C++ utilizados

| Concepto           | Aplicación                                      |
| ------------------ | ----------------------------------------------- |
| `int *`            | Declarar punteros a enteros                     |
| `new[]`            | Crear los arreglos dinámicamente                |
| `delete[]`         | Liberar ambas reservas de memoria               |
| `nullptr`          | Reiniciar los punteros después de liberar       |
| Funciones          | Separar el registro, inversión e impresión      |
| Parámetros         | Enviar el arreglo y su tamaño                   |
| `return`           | Devolver la dirección del nuevo arreglo         |
| `for`              | Recorrer y copiar los elementos                 |
| `while`            | Validar la cantidad                             |
| `arreglo[i]`       | Acceder a los elementos                         |
| `cantidad - 1 - i` | Recorrer el arreglo original en sentido inverso |

# 13. Preguntas que debes saber responder

1\. ¿Qué hace la función `invertirArreglo()`?

Crea un nuevo arreglo dinámico y copia los elementos del arreglo original en orden inverso.

2\. ¿Por qué devuelve un `int*`?

Porque necesita devolver la dirección de memoria del nuevo arreglo.

3\. ¿Por qué utilizamos `new[]`?

Porque estamos creando un arreglo dinámico cuyo tamaño se determina durante la ejecución.

4\. ¿Para qué sirve `cantidad - 1 - i`?

Para obtener los elementos del arreglo original desde la última posición hasta la primera.

5\. ¿Por qué restamos 1 a `cantidad`?

Porque los índices comienzan en cero. Si tenemos cinco elementos, el último índice válido es 4.

6\. ¿La función modifica el arreglo original?

No. Crea otro arreglo y copia sus valores en orden contrario.

7\. ¿Por qué tenemos dos punteros en `main()`?

Porque manejamos dos reservas diferentes: el arreglo original y su copia invertida.

8\. ¿Por qué usamos dos instrucciones `delete[]`?

Porque necesitamos liberar la memoria de los dos arreglos dinámicos.

9\. ¿Por qué `mostrarArreglo()` recibe la cantidad de elementos?

Porque un puntero por sí solo no contiene información sobre cuántos elementos tiene el arreglo.

10\. ¿Qué sucede si el arreglo tiene un único elemento?

La función crea una copia con ese mismo valor. El programa funciona correctamente.

# 14. Cómo compilarlo en tu Mac

Guarda el código como `Ejercicio4.cpp`.

Compila con:

```cpp
clang++ -std=c++17 Ejercicio4.cpp -o Ejercicio4
```

Después ejecútalo:

```cpp
./Ejercicio4
```

Prueba con cinco números diferentes y comprueba que los dos arreglos se muestran correctamente.

Esta solución, al igual que las anteriores, supone entradas numéricas válidas. Se mantiene sencilla y dentro de los conceptos que hemos estudiado.

# 15. Repaso final de los cuatro ejercicios de la Unidad VI

Con este ejercicio terminamos los cuatro mandatos que compartiste.

| Ejercicio | Tema principal                   | Lo más importante                                       |
| --------- | -------------------------------- | ------------------------------------------------------- |
| 1         | Arreglo dinámico de puntuaciones | `new[]`, ordenar por burbuja, promedio                  |
| 2         | Redimensionar un arreglo         | Crear otro arreglo y copiar los elementos que quepan    |
| 3         | Calcular la moda                 | Punteros con `*`, ciclos anidados y frecuencias         |
| 4         | Invertir un arreglo              | Copia dinámica, recorrido inverso y retorno de punteros |

## 16. Lo que más debes aprender del Ejercicio 4

Quiero que te concentres especialmente en estas instrucciones:

```cpp
int *invertirArreglo(int *arreglo, int cantidad) {

    int *nuevo = new int[cantidad];

    for (int i = 0; i < cantidad; i++) {

        nuevo[i] = arreglo[cantidad - 1 - i];
    }

    return nuevo;
}
```

Aquí se encuentran prácticamente todos los conceptos principales del ejercicio.

La función recibe un puntero, crea un nuevo arreglo mediante `new[]`, utiliza un ciclo para invertir los elementos y devuelve la dirección del nuevo arreglo.

No memorices solamente el código. Intenta explicar por qué utilizamos `cantidad - 1 - i`, por qué necesitamos `return nuevo` y por qué debemos liberar la memoria después.

### Archivos recomendados para guardar

- Código fuente: `Ejercicio4.cpp`
- Documentación: `Ejercicio4_Invertir_Arreglo.md`

Con esto completamos la Tarea de la Unidad VI. Lo siguiente será compilar los cuatro programas, probarlos con diferentes entradas y preparar las capturas que pide el profesor para la entrega.