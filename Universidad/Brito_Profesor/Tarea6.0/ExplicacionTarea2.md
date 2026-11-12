# Tarea Unidad VI — Ejercicio 2: Redimensionar un arreglo dinámico en C++

INF510 · Introducción a la Programación · UASD · Profesor Brito

Continuamos con el Ejercicio 2 de la Unidad VI. Esta vez vamos a trabajar con punteros, memoria dinámica y una función que permita cambiar el tamaño de un arreglo, conservando sus elementos.

Te dejaré el código completo y después su explicación detallada, para que puedas copiarlo y guardarlo en `Ejercicio2_Redimensionar_Arreglo.md`.

## 1. Enunciado del profesor

Crear una función que pueda redimensionar un arreglo. La función debe aceptar como argumentos:

1. Un arreglo de enteros `int` (nombre del arreglo y tamaño).
2. Un entero que será el nuevo tamaño del arreglo.

El objetivo es crear un nuevo arreglo, copiar los elementos del arreglo recibido y retornar un puntero con la dirección del nuevo arreglo.

Debemos tener en cuenta dos situaciones:

- Si el arreglo aumenta de tamaño: conservar todos los valores anteriores y rellenar con ceros las posiciones nuevas.
- Si disminuye de tamaño: copiar únicamente los valores que quepan en el nuevo arreglo.

### Ejemplo de lo que debe hacer

ExpandirReducir

Arreglo original — 5 elementos

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

Nuevo tamaño = 8

Nuevo arreglo — 8 elementos

10

0

20

1

30

2

40

3

50

4

0

5

0

6

0

7

Los tres espacios adicionales se inicializan en cero.

## 2. Código completo — `Ejercicio2.cpp`

Utilizaremos una función principal llamada `redimensionarArreglo()`.

Como todavía estamos aprendiendo punteros, vamos a mantener la solución sencilla, sin vectores, clases ni instrucciones avanzadas.

```cpp

#include <iostream>
using namespace std;

// Prototipos de las funciones
int *redimensionarArreglo(int *arreglo, int tamanoActual, int nuevoTamano);
void mostrarArreglo(int *arreglo, int tamano);

int main() {

    int tamanoActual;
    int nuevoTamano;

    int *numeros;
    int *nuevoArreglo;

    // Solicitar el tamaño del arreglo original
    cout << "Introduzca el tamano del arreglo: ";
    cin >> tamanoActual;

    // Validar el tamaño
    while (tamanoActual <= 0) {
        cout << "Tamano invalido. Introduzca otro: ";
        cin >> tamanoActual;
    }

    // Crear el arreglo original
    numeros = new int[tamanoActual];

    // Registrar los valores
    for (int i = 0; i < tamanoActual; i++) {

        cout << "Introduzca el numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // Mostrar el arreglo original
    cout << "\nARREGLO ORIGINAL" << endl;

    mostrarArreglo(numeros, tamanoActual);

    // Solicitar el nuevo tamaño
    cout << "\nIntroduzca el nuevo tamano del arreglo: ";
    cin >> nuevoTamano;

    // Validar el nuevo tamaño
    while (nuevoTamano <= 0) {
        cout << "Tamano invalido. Introduzca otro: ";
        cin >> nuevoTamano;
    }

    // Llamar a la funcion para redimensionar
    nuevoArreglo = redimensionarArreglo(
        numeros, tamanoActual, nuevoTamano
    );

    // Mostrar el nuevo arreglo
    cout << "\nARREGLO REDIMENSIONADO" << endl;

    mostrarArreglo(nuevoArreglo, nuevoTamano);

    // Liberar la memoria de los dos arreglos
    delete[] numeros;
    delete[] nuevoArreglo;

    numeros = nullptr;
    nuevoArreglo = nullptr;

    return 0;
}


// Funcion que redimensiona el arreglo
int *redimensionarArreglo(int *arreglo, int tamanoActual, int nuevoTamano) {

    // Crear un nuevo arreglo dinamico
    int *nuevo = new int[nuevoTamano];

    // Inicializar todas las posiciones en cero
    for (int i = 0; i < nuevoTamano; i++) {

        nuevo[i] = 0;
    }

    // Determinar cuantos elementos podemos copiar
    int cantidadCopiar;

    if (nuevoTamano < tamanoActual) {
        cantidadCopiar = nuevoTamano;
    } else {
        cantidadCopiar = tamanoActual;
    }

    // Copiar los elementos del arreglo original
    for (int i = 0; i < cantidadCopiar; i++) {

        nuevo[i] = arreglo[i];
    }

    // Devolver el puntero al nuevo arreglo
    return nuevo;
}


// Funcion para mostrar los elementos de un arreglo
void mostrarArreglo(int *arreglo, int tamano) {

    for (int i = 0; i < tamano; i++) {

        cout << arreglo[i] << " ";
    }

    cout << endl;
}

```

# 3. Explicación del programa línea por línea

Vamos a estudiarlo por partes, especialmente la función `redimensionarArreglo()`, que es la que cumple el requisito principal del profesor.

## A. Bibliotecas y prototipos

```cpp
#include <iostream>
using namespace std;
```

`iostream` nos permite trabajar con `cin` y `cout`.

`using namespace std;` evita que tengamos que escribir `std::` delante de esas instrucciones.

Ahora los prototipos:

```cpp
int *redimensionarArreglo(int *arreglo, int tamanoActual, int nuevoTamano);
void mostrarArreglo(int *arreglo, int tamano);
```

Observa que tenemos dos funciones:

| Función                  | Recibe                                | Devuelve      |
| ------------------------ | ------------------------------------- | ------------- |
| `redimensionarArreglo()` | Puntero, tamaño actual y nuevo tamaño | `int*`        |
| `mostrarArreglo()`       | Puntero y tamaño                      | Nada (`void`) |

¿Por qué `redimensionarArreglo()` devuelve `int*`?

Porque va a crear un nuevo arreglo dinámico y necesita devolver su dirección de memoria.

Es el mismo concepto que utilizamos en el ejercicio anterior con `creaArreglo()`.

## B. Las variables de `main()`

```cpp
int tamanoActual;
int nuevoTamano;

int *numeros;
int *nuevoArreglo;
```

Vamos una por una.

`tamanoActual`: almacena la cantidad de elementos que tendrá el arreglo original.

`nuevoTamano`: almacena el tamaño que desea utilizar el usuario después de redimensionar.

`numeros`: es un puntero que guardará la dirección del arreglo original.

`nuevoArreglo`: es otro puntero que guardará la dirección del arreglo redimensionado.

Aquí hay algo que debes entender:

No vamos a cambiar directamente el tamaño de `numeros`. Vamos a crear otro arreglo con el tamaño solicitado.

Eso es precisamente lo que pide el mandato.

## C. Crear el arreglo original

```cpp
numeros = new int[tamanoActual];
```

Esta instrucción reserva memoria para un arreglo de enteros.

Por ejemplo, si:

```cpp
tamanoActual = 5;
```

Se reserva espacio para cinco enteros.

La dirección del primer elemento queda almacenada en `numeros`.

Después utilizamos:

```cpp
for (int i = 0; i < tamanoActual; i++) {

    cout << "Introduzca el numero " << i + 1 << ": ";
    cin >> numeros[i];
}
```

Este ciclo permite introducir los valores.

Si el usuario escribe cinco números:

```cpp
10 20 30 40 50
```

El arreglo tendrá estos elementos:

| Índice       | Valor |
| ------------ | ----- |
| `numeros[0]` | 10    |
| `numeros[1]` | 20    |
| `numeros[2]` | 30    |
| `numeros[3]` | 40    |
| `numeros[4]` | 50    |

# 4. La función más importante: `redimensionarArreglo()`

Vamos a analizarla con especial atención.

```cpp
int *redimensionarArreglo(int *arreglo, int tamanoActual, int nuevoTamano) {

    int *nuevo = new int[nuevoTamano];

    for (int i = 0; i < nuevoTamano; i++) {
        nuevo[i] = 0;
    }

    int cantidadCopiar;

    if (nuevoTamano < tamanoActual) {
        cantidadCopiar = nuevoTamano;
    } else {
        cantidadCopiar = tamanoActual;
    }

    for (int i = 0; i < cantidadCopiar; i++) {
        nuevo[i] = arreglo[i];
    }

    return nuevo;
}
```

Esta función realiza cuatro tareas:

1. Reservar memoria para el nuevo arreglo.
2. Inicializar sus posiciones en cero.
3. Copiar los elementos que quepan.
4. Devolver la dirección del nuevo arreglo.

## A. Declaración de la función

```cpp
int *redimensionarArreglo(int *arreglo, int tamanoActual, int nuevoTamano)
```

Veamos cada parte.

`int *` al principio indica que la función devolverá un puntero a entero.

`redimensionarArreglo` es el nombre de la función.

Recibe tres parámetros:

| Parámetro          | Significado                                     |
| ------------------ | ----------------------------------------------- |
| `int *arreglo`     | Dirección del arreglo original                  |
| `int tamanoActual` | Número de elementos del arreglo original        |
| `int nuevoTamano`  | Número de elementos que tendrá el nuevo arreglo |

Por ejemplo, en `main()` llamamos:

```cpp
nuevoArreglo = redimensionarArreglo(numeros, 5, 8);
```

Esto le indica a la función que debe crear un arreglo de ocho elementos, tomando como referencia un arreglo original de cinco elementos.

## B. Crear el nuevo arreglo dinámico

```cpp
int *nuevo = new int[nuevoTamano];
```

Esta línea hace dos cosas.

Primero, declara el puntero `nuevo`.

Después, mediante `new`, solicita memoria para un arreglo con el tamaño indicado.

Si `nuevoTamano` vale `8`, reserva espacio para ocho enteros.

¿Por qué no utilizamos un arreglo normal?

Porque el usuario decide el tamaño durante la ejecución.

Ese es uno de los objetivos fundamentales de la Unidad VI.

## C. Inicializar las posiciones en cero

```cpp
for (int i = 0; i < nuevoTamano; i++) {

    nuevo[i] = 0;
}
```

Este ciclo recorre todas las posiciones del nuevo arreglo.

En cada posición guarda un cero.

Si `nuevoTamano` es 8, tendremos inicialmente:

```cpp
0 0 0 0 0 0 0 0
```

¿Por qué hacemos esto?

Porque el profesor indica que, si el arreglo aumenta de tamaño, las posiciones adicionales deben contener cero.

Después copiaremos los elementos originales. Las posiciones que no reciban ningún elemento conservarán el cero.

Además, recuerda que un arreglo creado mediante:

```cpp
new int[nuevoTamano]
```

no inicializa automáticamente sus elementos a cero de la forma en que lo utilizamos aquí.

Por eso realizamos la inicialización explícitamente.

## D. Determinar cuántos elementos podemos copiar

Esta parte es muy importante:

```cpp
int cantidadCopiar;

if (nuevoTamano < tamanoActual) {

    cantidadCopiar = nuevoTamano;

} else {

    cantidadCopiar = tamanoActual;
}
```

Aquí tenemos una condición `if-else`.

Necesitamos decidir cuántos valores podemos copiar sin salir de los límites de ninguno de los dos arreglos.

### Caso 1: el nuevo arreglo es más grande

Supongamos:

```cpp
tamanoActual = 5;
nuevoTamano = 8;
```

Evaluamos:

```cpp
if (8 < 5)
```

Es falso.

Entonces ejecutamos:

```cpp
cantidadCopiar = tamanoActual;
```

Es decir:

```
cantidadCopiar = 5;
```

Copiaremos los cinco elementos originales y las tres posiciones adicionales permanecerán en cero.

### Caso 2: el nuevo arreglo es más pequeño

Supongamos:

```cpp
tamanoActual = 5;
nuevoTamano = 3;
```

Evaluamos:

```cpp
if (3 < 5)
```

Es verdadero.

Entonces:

```cpp
cantidadCopiar = nuevoTamano;
```

Por tanto:

```cpp
cantidadCopiar = 3;
```

Solamente copiaremos los primeros tres elementos.

No podemos copiar los cinco porque el nuevo arreglo solo tiene tres posiciones.

Esta condición evita intentar escribir fuera del nuevo arreglo.

## E. Copiar los elementos

```cpp
for (int i = 0; i < cantidadCopiar; i++) {

    nuevo[i] = arreglo[i];
}
```

Este es el ciclo que realiza la copia.

Observa:

```cpp
nuevo[i] = arreglo[i];
```

A la derecha tenemos:

```cpp
arreglo[i]
```

Es el valor del arreglo original.

A la izquierda:

```cpp
nuevo[i]
```

Es la posición donde guardaremos ese valor en el nuevo arreglo.

Por tanto, estamos copiando un dato desde el arreglo original al nuevo.

Por ejemplo:

```cpp
nuevo[0] = arreglo[0];
nuevo[1] = arreglo[1];
nuevo[2] = arreglo[2];
```

Si los valores originales son `10`, `20` y `30`, esos mismos valores se copian al nuevo arreglo.

La cantidad de veces que se ejecuta el ciclo depende de `cantidadCopiar`.

## F. Devolver el nuevo arreglo

```cpp
return nuevo;
```

Esta línea devuelve la dirección de memoria del nuevo arreglo.

Recuerda que `nuevo` es un puntero.

Por tanto, no estamos devolviendo todos los elementos uno por uno, sino la dirección que nos permitirá acceder al nuevo arreglo.

En `main()` recibimos ese resultado:

```cpp
nuevoArreglo = redimensionarArreglo(
    numeros, tamanoActual, nuevoTamano
);
```

Ahora `nuevoArreglo` apunta al arreglo recién creado.

El arreglo original sigue existiendo, porque todavía no lo hemos liberado.

# 5. Función `mostrarArreglo()`

Esta función es mucho más sencilla.

```cpp
void mostrarArreglo(int *arreglo, int tamano) {

    for (int i = 0; i < tamano; i++) {

        cout << arreglo[i] << " ";
    }

    cout << endl;
}
```

La creamos para evitar repetir el mismo ciclo de impresión varias veces dentro de `main()`.

### Primera línea

```cpp
void mostrarArreglo(int *arreglo, int tamano)
```

La función recibe:

- Un puntero al arreglo.
- La cantidad de elementos que contiene.

Utilizamos `void` porque solamente mostramos información. No necesitamos devolver ningún resultado.

### El ciclo

```cpp
for (int i = 0; i < tamano; i++)
```

Recorre las posiciones desde cero hasta `tamano - 1`.

### Mostrar los elementos

```cpp
cout << arreglo[i] << " ";
```

Muestra cada número seguido de un espacio.

Así obtenemos:

```cpp
10 20 30 40 50
```

Esta función sirve tanto para mostrar el arreglo original como el nuevo, porque recibe su dirección y el tamaño correspondiente.

# 6. ¿Por qué tenemos dos punteros en `main()`?

Observa:

```cpp
int *numeros;
int *nuevoArreglo;
```

Es importante no confundirlos.

Dos arreglos diferentes en memoria

`numeros` — arreglo original

10

20

30

40

50

`nuevoArreglo` — arreglo redimensionado

10

20

30

40

50

0

0

0

Cada puntero conserva la dirección de una reserva diferente de memoria dinámica. El nuevo arreglo contiene una copia de los valores originales.

Por eso, al finalizar, liberamos ambas reservas:

```cpp
delete[] numeros;
delete[] nuevoArreglo;
```

Y después:

```cpp
numeros = nullptr;
nuevoArreglo = nullptr;
```

Dejamos ambos punteros sin apuntar a memoria liberada.

Importante: `delete[]` libera la memoria; asignar `nullptr` por sí solo no la libera.

# 7. Ejemplos de ejecución

## Ejemplo A — Expandir el arreglo

El usuario comienza con cinco números y desea un arreglo de ocho elementos.

```cpp
Introduzca el tamano del arreglo: 5

Introduzca el numero 1: 10
Introduzca el numero 2: 20
Introduzca el numero 3: 30
Introduzca el numero 4: 40
Introduzca el numero 5: 50

ARREGLO ORIGINAL
10 20 30 40 50

Introduzca el nuevo tamano del arreglo: 8

ARREGLO REDIMENSIONADO
10 20 30 40 50 0 0 0
```

Los cinco valores se conservaron y las tres posiciones nuevas contienen cero.

## Ejemplo B — Reducir el arreglo

Ahora el usuario desea reducirlo a tres posiciones.

```cpp
Introduzca el tamano del arreglo: 5

Introduzca el numero 1: 10
Introduzca el numero 2: 20
Introduzca el numero 3: 30
Introduzca el numero 4: 40
Introduzca el numero 5: 50

ARREGLO ORIGINAL
10 20 30 40 50

Introduzca el nuevo tamano del arreglo: 3

ARREGLO REDIMENSIONADO
10 20 30
```

Solamente se copiaron los tres primeros elementos, exactamente como solicita el profesor.

## Ejemplo C — Mantener el mismo tamaño

Si el usuario introduce el mismo tamaño:

```cpp
ARREGLO ORIGINAL
10 20 30 40 50

Introduzca el nuevo tamano del arreglo: 5

ARREGLO REDIMENSIONADO
10 20 30 40 50
```

El programa también funciona. Crea una copia con el mismo número de elementos.

# 8. Conceptos de C++ utilizados

| Concepto         | Dónde aparece                 | Para qué sirve                         |
| ---------------- | ----------------------------- | -------------------------------------- |
| Punteros `int *` | `numeros`, `nuevoArreglo`     | Guardar direcciones de memoria         |
| `new[]`          | Creación de los arreglos      | Reservar memoria dinámica              |
| `delete[]`       | Final de `main()`             | Liberar memoria                        |
| `nullptr`        | Final de `main()`             | Evitar conservar direcciones liberadas |
| Funciones        | `redimensionarArreglo()`      | Separar responsabilidades              |
| Parámetros       | `tamanoActual`, `nuevoTamano` | Enviar información                     |
| `return`         | `return nuevo;`               | Devolver un puntero                    |
| `for`            | Registro, copia e impresión   | Recorrer arreglos                      |
| `while`          | Validación de tamaños         | Impedir tamaños no positivos           |
| `if-else`        | Determinar `cantidadCopiar`   | Decidir cuántos elementos copiar       |
| `arreglo[i]`     | Acceso a los elementos        | Leer y escribir datos                  |

# 9. Preguntas que debes saber responder

Estas preguntas te ayudarán a comprobar si realmente entendiste el ejercicio.

1\. ¿Por qué `redimensionarArreglo()` devuelve un puntero?

Porque crea un nuevo arreglo dinámico y necesita devolver su dirección de memoria.

2\. ¿Por qué no modificamos directamente el tamaño del arreglo original?

Porque un arreglo creado mediante `new[]` no puede cambiar de tamaño automáticamente. Necesitamos reservar otro arreglo y copiar los elementos.

3\. ¿Por qué inicializamos las posiciones nuevas en cero?

Porque es un requisito del enunciado cuando el arreglo aumenta de tamaño.

4\. ¿Para qué sirve `cantidadCopiar`?

Para determinar cuántos elementos podemos copiar sin exceder los límites del nuevo arreglo ni leer fuera del original.

5\. ¿Qué ocurre cuando reducimos un arreglo de cinco a tres elementos?

Se copian solamente los primeros tres valores.

6\. ¿Por qué utilizamos `delete[]` dos veces?

Porque realizamos dos reservas independientes mediante `new[]`.

7\. ¿Qué significa `nuevo[i] = arreglo[i]`?

Que copiamos el valor de la posición `i` del arreglo original a la misma posición del arreglo nuevo.

8\. ¿Se modifica el arreglo original?

No. La función crea otro arreglo y copia los datos. El original conserva sus valores mientras exista.

# 10. Cómo compilarlo en tu Mac

Guarda el código como `Ejercicio2.cpp`.

Para compilar:

```
clang++ -std=c++17 Ejercicio2.cpp -o Ejercicio2
```

Para ejecutar:

```cpp
./Ejercicio2
```

Te recomiendo realizar dos ejecuciones para la entrega: una aumentando el tamaño y otra reduciéndolo. Así puedes tomar capturas que demuestren ambos comportamientos.

El código está pensado para entradas numéricas válidas y tamaños razonables. En esta etapa no incorporamos manejo avanzado de errores de `cin` ni de agotamiento de memoria, porque queremos mantenernos dentro de los conceptos estudiados.

## 11. Lo más importante que aprendimos

En el ejercicio anterior aprendimos a crear un arreglo dinámico.

En este segundo ejercicio aprendemos algo nuevo: crear un segundo arreglo de tamaño diferente y copiar los elementos del primero.

La parte más importante que debes comprender es:

```cpp
int *nuevo = new int[nuevoTamano];

for (int i = 0; i < nuevoTamano; i++) {
    nuevo[i] = 0;
}

int cantidadCopiar;

if (nuevoTamano < tamanoActual) {
    cantidadCopiar = nuevoTamano;
} else {
    cantidadCopiar = tamanoActual;
}

for (int i = 0; i < cantidadCopiar; i++) {
    nuevo[i] = arreglo[i];
}

return nuevo;
```

Si sabes explicar esas instrucciones sin mirar los apuntes, habrás comprendido la lógica principal del ejercicio.

Archivos recomendados para guardar:

- Código fuente: `Ejercicio2.cpp`
- Documentación: `Ejercicio2_Redimensionar_Arreglo.md`

Con esto completamos el segundo mandato de la Unidad VI. Cuando me digas «siguiente», trabajaremos el Ejercicio 3: encontrar la moda de un arreglo utilizando notación de punteros con asteriscos en lugar de corchetes, tal como exige el profesor.