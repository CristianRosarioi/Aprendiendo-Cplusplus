# Unidad 5 — Tarea 1: Sucesión de Fibonacci en C++

Ya revisé el mandato. Vamos a trabajar solamente la primera tarea, y no pasaremos a la segunda hasta que me lo indiques.

Esta tarea es ideal para practicar lo nuevo de la unidad 5: crear una función, enviarle un argumento, calcular un resultado y devolverlo con `return`.

## 1. ¿Qué pide exactamente el profesor?

El mandato exige escribir una función con este prototipo:

```
long fibonacci(long);
```

La función debe recibir el número del término que queremos buscar y devolver su valor en la sucesión de Fibonacci.

La sucesión comienza así:

Sucesión de Fibonacci

\#1

## 0

\#2

## 1

\#3

## 1

\#4

## 2

\#5

## 3

\#6

## 5

\#7

## 8

El quinto término es 3, tal como indica el ejemplo del profesor. Contamos las posiciones desde 1.

Cada nuevo término es la suma de los dos anteriores:

\\[ F(n)=F(n-1)+F(n-2) \\]

Por ejemplo, para obtener el quinto término, sumamos el tercero y el cuarto:

\\[ 1+2=3 \\]

## 2. Código completo — `tarea1.cpp`

Este programa utiliza únicamente conceptos que ya hemos estudiado: variables, `cin`, `cout`, `if`, `while`, `for`, funciones, parámetros y `return`.

```cpp

/*
Universidad Autonoma de Santo Domingo
Introduccion a la Programacion
Unidad V - Tarea 1

Sucesion de Fibonacci
*/

#include <iostream>
using namespace std;

// Prototipo de la funcion
long fibonacci(long);

int main() {
    long terminoBuscado;
    long cantidad;

    cout << "Ingrese el termino de Fibonacci: ";
    cin >> terminoBuscado;

    // Validar que el termino sea positivo
    while (terminoBuscado <= 0) {
        cout << "El termino debe ser mayor que cero: ";
        cin >> terminoBuscado;
    }

    // Llamar la funcion y guardar el resultado
    cantidad = fibonacci(terminoBuscado);

    cout << "Cantidad: " << cantidad << endl;

    return 0;
}

// Definicion de la funcion fibonacci
long fibonacci(long n) {
    long anterior = 0;
    long actual = 1;
    long siguiente;

    if (n == 1) {
        return anterior;
    }

    if (n == 2) {
        return actual;
    }

    for (long i = 3; i <= n; i++) {
        siguiente = anterior + actual;
        anterior = actual;
        actual = siguiente;
    }

    return actual;
}

```

El código respeta el prototipo solicitado. Además, utiliza un ciclo `for` en vez de recursividad, porque los ciclos ya forman parte de las unidades anteriores y todavía no necesitamos introducir una técnica más compleja.

## 3. Explicación del código paso a paso

### A. La biblioteca y el prototipo

```cpp
#include <iostream>
using namespace std;

long fibonacci(long);
```

Ya conoces `<iostream>`, pero la tercera línea es nueva.

```cpp
long fibonacci(long);
```

Se llama prototipo de función y anuncia tres cosas:

| Parte          | Significado                                          |
| -------------- | ---------------------------------------------------- |
| Primer `long`  | La función devolverá un número entero de tipo `long` |
| `fibonacci`    | Nombre de la función                                 |
| Segundo `long` | Recibirá un argumento entero de tipo `long`          |

El punto y coma `;` termina el prototipo.

¿Por qué lo colocamos antes de `main()`? Porque la definición completa de `fibonacci` está después de `main`. Así, el compilador ya conoce la función cuando encuentra la llamada.

### B. La función `main()`

```cpp
long terminoBuscado;
long cantidad;
```

Declaramos dos variables:

- `terminoBuscado`: número de posición que introduce el usuario.
- `cantidad`: valor que devuelve nuestra función.

Por ejemplo, el usuario introduce `5`, pero el resultado es `3`. Son dos valores diferentes.

```cpp
while (terminoBuscado <= 0) {
    cout << "El termino debe ser mayor que cero: ";
    cin >> terminoBuscado;
}
```

Este `while` valida que la posición sea positiva. Como el mandato cuenta el primer término desde la posición 1, rechazamos posiciones como 0 o −3. Suponemos que el usuario introduce números enteros válidos.

```cpp
cantidad = fibonacci(terminoBuscado);
```

Esta es la línea más importante de `main`.

Se lee:

> Llama a la función `fibonacci`, envíale el valor de `terminoBuscado` y guarda el resultado devuelto en `cantidad`.

Si `terminoBuscado` es 5, equivale a llamar:

```cpp
cantidad = fibonacci(5);
```

Después de ejecutar la función, `cantidad` recibe 3.

### C. Definición de `fibonacci`

```cpp
long fibonacci(long n) {
```

Aquí empieza la definición real.

`n` es el parámetro que recibe el valor enviado desde `main`.

Si llamamos `fibonacci(5)`, entonces dentro de la función `n` vale 5.

```cpp
long anterior = 0;
long actual = 1;
long siguiente;
```

Estas variables sirven para construir la sucesión:

| Variable    | Función                                   |
| ----------- | ----------------------------------------- |
| `anterior`  | Guarda uno de los dos términos anteriores |
| `actual`    | Guarda el término más reciente            |
| `siguiente` | Guarda la suma de los anteriores          |

Al principio:

```cpp
anterior = 0
actual   = 1
```

Son los dos primeros términos de Fibonacci.

### D. ¿Por qué usamos dos `if`?

```cpp
if (n == 1) {
    return anterior;
}

if (n == 2) {
    return actual;
}
```

Porque ya conocemos las respuestas para las posiciones 1 y 2.

- Si pide el primer término, devolvemos 0.
- Si pide el segundo, devolvemos 1.

`return` termina la función inmediatamente. No ejecuta las instrucciones que quedan después dentro de esa función.

### E. La lógica del ciclo `for`

Esta es la parte que quiero que comprendas especialmente.

```cpp
for (long i = 3; i <= n; i++) {
    siguiente = anterior + actual;
    anterior = actual;
    actual = siguiente;
}
```

Primero analicemos el encabezado:

```cpp
for (long i = 3; i <= n; i++)
```

- `long i = 3`: empezamos en la posición 3 porque ya tenemos los términos 1 y 2.
- `i <= n`: repetimos hasta llegar a la posición solicitada.
- `i++`: avanzamos una posición después de cada vuelta.

Ahora vamos a simularlo con `n = 5`.

Simulación de `fibonacci(5)`

Vuelta 1 de 4

Posición Inicio

anterior

# 0

actual

# 1

siguiente

# —

Tenemos los dos primeros términos.

&#x20;AnteriorSiguiente&#x20;

Las tres instrucciones del ciclo deben ejecutarse en ese orden:

```cpp
siguiente = anterior + actual;
anterior = actual;
actual = siguiente;
```

La primera calcula el nuevo término. Las otras dos desplazan los valores para preparar la siguiente vuelta.

Cuando `i` llega a 6, la condición `6 <= 5` es falsa y termina el ciclo.

Finalmente:

```cpp
return actual;
```

Devuelve el resultado a `main()`.

En nuestro ejemplo, devuelve 3.

## 4. Comprueba diferentes resultados

| Entrada | Resultado esperado |
| ------- | ------------------ |
| 1       | 0                  |
| 2       | 1                  |
| 3       | 1                  |
| 4       | 2                  |
| 5       | 3                  |
| 6       | 5                  |
| 7       | 8                  |
| 8       | 13                 |
| 12      | 89                 |
| 13      | 144                |

El tipo `long` tiene una capacidad limitada. Si solicitas una posición extremadamente grande, el cálculo puede desbordarse y dejar de producir resultados válidos. El programa está pensado para los valores de práctica de la tarea.

## 5. Cómo probarlo

En tu Mac, guarda el archivo como `tarea1.cpp`, abre la terminal en esa carpeta y escribe:

```cpp
clang++ -std=c++17 tarea1.cpp -o tarea1
./tarea1
```

Para el laboratorio con Borland, usa el procedimiento de compilación que ya vienes utilizando y verifica el resultado con el quinto término.

Para entregar la tarea, el mandato exige el archivo fuente `.cpp` y una captura de pantalla del programa ejecutándose, ambos dentro de un archivo ZIP o RAR. No basta con subir únicamente el ejecutable.

## 6. Lo que debes poder explicar al profesor

Lo fundamental de esta tarea no es memorizar los números de Fibonacci. Es que puedas explicar estos conceptos:

- Prototipo: anuncia la función.
- Definición: contiene las instrucciones que ejecuta.
- Parámetro: `n` recibe el dato dentro de la función.
- Argumento: `terminoBuscado` es el dato que enviamos.
- `return`: devuelve el valor y termina la función.
- `for`: genera los términos que todavía faltan.
- Variables auxiliares: conservan los dos términos necesarios para calcular el siguiente.

En particular, recuerda la diferencia entre estas instrucciones:

```cpp
long fibonacci(long);              // Prototipo
cantidad = fibonacci(5);           // Llamada
long fibonacci(long n) { ... }     // Definicion
```

Con esto completamos la tarea 1 de la unidad 5. Cuando me digas «Dame la 2», trabajaremos Piedra, Papel o Tijera con el mismo nivel de detalle y usando las funciones que exige su enunciado.

