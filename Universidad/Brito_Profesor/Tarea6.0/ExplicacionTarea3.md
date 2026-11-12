# Tarea Unidad VI — Ejercicio 3: Calcular la moda de un arreglo utilizando punteros

INF510 · Introducción a la Programación · UASD · Profesor Brito

Continuamos con el Ejercicio 3 de la Unidad VI. Este ejercicio es muy importante porque el profesor quiere comprobar que sabemos utilizar los punteros para recorrer un arreglo sin utilizar corchetes `[]` para acceder a sus elementos.

Como siempre, te dejaré el código completo y después una explicación detallada de cada parte, para que puedas copiarlo a tu archivo Markdown.

## 1. Enunciado del profesor

En estadística, la moda de un conjunto de valores es el valor que aparece con mayor frecuencia.

El profesor solicita escribir una función que reciba:

1. Un arreglo de enteros.
2. Un entero que indique la cantidad de elementos.

La función debe encontrar el número que más se repite y devolverlo mediante `return`.

Condiciones del mandato:

- Si ningún número se repite, la función debe devolver `-1`.
- Todos los valores del arreglo serán positivos.
- Debemos utilizar notación de punteros con asteriscos, en lugar de la notación de arreglos con corchetes.

### ¿Qué es la moda?

Supongamos que tenemos:

```cpp
5  8  3  8  2  8  5
```

El número `8` aparece tres veces, mientras que `5` aparece dos veces y los demás solamente una.

Por tanto:

\\[ \text{Moda}=8 \\]

Otro ejemplo:

```cpp
4  7  9  2  6
```

Ningún número se repite. La función debe devolver `-1`.

## 2. Código completo — `Ejercicio3.cpp`

Utilizaremos dos funciones propias: `leerNumeros()` y `calcularModa()`.

También usaremos memoria dinámica con `new[]` y `delete[]`, como hemos estudiado en esta unidad.

```cpp

#include <iostream>
using namespace std;

// Prototipos de las funciones
void leerNumeros(int *arreglo, int cantidad);
int calcularModa(int *arreglo, int cantidad);

int main() {

    int cantidad;
    int moda;

    int *numeros;

    // Solicitar la cantidad de numeros
    cout << "Cuantos numeros desea introducir? ";
    cin >> cantidad;

    // Validar la cantidad
    while (cantidad <= 0) {
        cout << "Cantidad invalida. Introduzca otra: ";
        cin >> cantidad;
    }

    // Crear el arreglo dinamico
    numeros = new int[cantidad];

    // Llamar a la funcion para registrar los numeros
    leerNumeros(numeros, cantidad);

    // Calcular la moda
    moda = calcularModa(numeros, cantidad);

    // Mostrar los numeros introducidos
    cout << "\nNUMEROS INTRODUCIDOS" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << *(numeros + i) << " ";
    }

    cout << endl;

    // Mostrar el resultado
    if (moda == -1) {

        cout << "\nEl arreglo no tiene moda." << endl;

    } else {

        cout << "\nLa moda del arreglo es: "
             << moda << endl;
    }

    // Liberar la memoria dinamica
    delete[] numeros;

    numeros = nullptr;

    return 0;
}


// Funcion para leer los numeros
void leerNumeros(int *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++) {

        cout << "Introduzca el numero " << i + 1 << ": ";

        cin >> *(arreglo + i);

        // Validar que el numero sea positivo
        while (*(arreglo + i) <= 0) {

            cout << "Numero invalido. Introduzca uno positivo: ";

            cin >> *(arreglo + i);
        }
    }
}


// Funcion para calcular la moda
int calcularModa(int *arreglo, int cantidad) {

    int moda = -1;
    int mayorFrecuencia = 1;
    int frecuencia;

    // Recorrer cada numero del arreglo
    for (int i = 0; i < cantidad; i++) {

        frecuencia = 0;

        // Comparar el numero actual con todos los demas
        for (int j = 0; j < cantidad; j++) {

            if (*(arreglo + i) == *(arreglo + j)) {

                frecuencia++;
            }
        }

        // Actualizar la moda si encontramos
        // un numero con mayor frecuencia
        if (frecuencia > mayorFrecuencia) {

            mayorFrecuencia = frecuencia;

            moda = *(arreglo + i);
        }
    }

    return moda;
}

```

# 3. ¿Cómo funciona el programa?

Vamos a entender primero el proceso completo.

`main()`

Solicita la cantidad de números

`new int[cantidad]`

Reserva la memoria para el arreglo dinámico

`leerNumeros(numeros, cantidad)`

Registra los números positivos

`calcularModa(numeros, cantidad)`

Cuenta cuántas veces aparece cada número

Mostrar resultados y liberar memoria

Presenta la moda y utiliza delete[]

## 4. Bibliotecas y prototipos

```cpp
#include <iostream>
using namespace std;
```

`iostream` permite utilizar `cout`, `cin` y `endl`.

`using namespace std;` evita escribir `std::` antes de esas instrucciones.

Ahora nuestros prototipos:

```cpp
void leerNumeros(int *arreglo, int cantidad);

int calcularModa(int *arreglo, int cantidad);
```

### ¿Qué significa cada uno?

| Función          | Parámetros                          | Retorno |
| ---------------- | ----------------------------------- | ------- |
| `leerNumeros()`  | Un puntero y la cantidad de números | `void`  |
| `calcularModa()` | Un puntero y la cantidad de números | `int`   |

La primera función guarda datos dentro del arreglo.

La segunda calcula la moda y devuelve el número encontrado.

Observa que ambas reciben un puntero de tipo `int *`, porque trabajan con el arreglo original.

# 5. Explicación de `main()` línea por línea

## A. Declaración de las variables

```cpp
int cantidad;
int moda;

int *numeros;
```

`cantidad`: almacena el número de elementos que introducirá el usuario.

`moda`: almacenará el valor que devuelva la función `calcularModa()`.

`numeros`: es un puntero a entero. Guardará la dirección del arreglo dinámico.

Recuerda que:

```cpp
int *numeros;
```

No crea todavía un arreglo. Solo declara un puntero.

## B. Solicitar la cantidad

```cpp
cout << "Cuantos numeros desea introducir? ";
cin >> cantidad;
```

Solicitamos el número de elementos.

Por ejemplo:

```cpp
Cuantos numeros desea introducir? 7
```

Después validamos:

```cpp
while (cantidad <= 0) {
    cout << "Cantidad invalida. Introduzca otra: ";
    cin >> cantidad;
}
```

Esto impide que el usuario introduzca una cantidad negativa o cero.

## C. Crear el arreglo dinámico

```cpp
numeros = new int[cantidad];
```

Aquí utilizamos `new[]`, que estudiamos en la Unidad VI.

Si `cantidad` vale 7, se reserva espacio para siete enteros.

La dirección del primer elemento se guarda en `numeros`.

## D. Llamar a la función de registro

```cpp
leerNumeros(numeros, cantidad);
```

Enviamos el puntero y la cantidad a la función `leerNumeros()`.

Esta función se encarga de solicitar todos los números.

## E. Calcular la moda

```cpp
moda = calcularModa(numeros, cantidad);
```

Esta instrucción hace tres cosas:

1. Llama a la función `calcularModa()`.
2. Le envía el arreglo y su tamaño.
3. Guarda el resultado devuelto en `moda`.

Si el valor que más se repite es `8`, entonces `moda` recibe `8`.

Si ninguno se repite, recibe `-1`.

## F. Mostrar los elementos

```cpp
for (int i = 0; i < cantidad; i++) {
    cout << *(numeros + i) << " ";
}
```

Observa algo muy importante.

No utilizamos:

```cpp
numeros[i]
```

Utilizamos:

```cpp
*(numeros + i)
```

Esto es exactamente lo que solicita el profesor: utilizar notación de punteros para acceder al arreglo.

## G. Mostrar el resultado

```cpp
if (moda == -1) {

    cout << "\nEl arreglo no tiene moda." << endl;

} else {

    cout << "\nLa moda del arreglo es: "
         << moda << endl;
}
```

La condición pregunta si la función devolvió `-1`.

Si es así, mostramos que el arreglo no tiene moda.

En caso contrario, mostramos el número encontrado.

## H. Liberar la memoria

```cpp
delete[] numeros;

numeros = nullptr;
```

`delete[]` libera el espacio reservado por `new[]`.

Después asignamos `nullptr` al puntero para evitar conservar una dirección de memoria liberada.

# 6. Función `leerNumeros()`

```cpp
void leerNumeros(int *arreglo, int cantidad) {

    for (int i = 0; i < cantidad; i++) {

        cout << "Introduzca el numero " << i + 1 << ": ";

        cin >> *(arreglo + i);

        while (*(arreglo + i) <= 0) {

            cout << "Numero invalido. Introduzca uno positivo: ";

            cin >> *(arreglo + i);
        }
    }
}
```

Vamos por partes.

### Declaración

```cpp
void leerNumeros(int *arreglo, int cantidad)
```

`void` significa que no devuelve un resultado mediante `return`.

Recibe la dirección del arreglo y la cantidad de elementos.

### Ciclo `for`

```cpp
for (int i = 0; i < cantidad; i++)
```

Recorre todas las posiciones del arreglo.

Si el usuario solicitó siete números, el ciclo se ejecutará siete veces.

### Guardar los números

```cpp
cin >> *(arreglo + i);
```

Esta es una de las instrucciones fundamentales del ejercicio.

Significa: guarda el número introducido en la posición a la que apunta `arreglo + i`.

Para entenderlo:

| Valor de `i` | Expresión        | Posición |
| ------------ | ---------------- | -------- |
| 0            | `*(arreglo + 0)` | Primera  |
| 1            | `*(arreglo + 1)` | Segunda  |
| 2            | `*(arreglo + 2)` | Tercera  |
| 3            | `*(arreglo + 3)` | Cuarta   |

La expresión es equivalente a `arreglo[i]`, pero utiliza la notación de punteros exigida.

### Validación

```cpp
while (*(arreglo + i) <= 0) {

    cout << "Numero invalido. Introduzca uno positivo: ";

    cin >> *(arreglo + i);
}
```

El profesor indica que los números del arreglo deben ser positivos.

Por eso, si el usuario introduce cero o un número negativo, el programa vuelve a solicitarlo.

# 7. Función `calcularModa()` — La lógica más importante

Esta es la parte que debes estudiar con mayor atención.

```cpp
int calcularModa(int *arreglo, int cantidad) {

    int moda = -1;
    int mayorFrecuencia = 1;
    int frecuencia;

    for (int i = 0; i < cantidad; i++) {

        frecuencia = 0;

        for (int j = 0; j < cantidad; j++) {

            if (*(arreglo + i) == *(arreglo + j)) {

                frecuencia++;
            }
        }

        if (frecuencia > mayorFrecuencia) {

            mayorFrecuencia = frecuencia;

            moda = *(arreglo + i);
        }
    }

    return moda;
}
```

Vamos a dividirla en cinco partes.

## A. Declarar las variables

```cpp
int moda = -1;
int mayorFrecuencia = 1;
int frecuencia;
```

### `moda = -1`

Inicialmente suponemos que no existe moda.

¿Por qué `-1`?

Porque es el valor que el profesor exige devolver cuando ningún número se repite.

Además, el mandato establece que los elementos del arreglo serán positivos, por lo que `-1` no puede confundirse con un valor introducido.

### `mayorFrecuencia = 1`

Inicializamos la mayor frecuencia en 1.

Esto significa que un número debe aparecer más de una vez para convertirse en la moda del programa.

### `frecuencia`

Esta variable contará cuántas veces aparece el número que estamos analizando en cada vuelta.

## B. Primer ciclo `for`

```cpp
for (int i = 0; i < cantidad; i++) {
```

Este ciclo selecciona un número del arreglo para analizarlo.

Por ejemplo:

```cpp
5  8  3  8  2  8  5
```

Cuando `i = 0`, analizamos el número 5.

Cuando `i = 1`, analizamos el número 8.

Cuando `i = 2`, analizamos el número 3.

Y así sucesivamente.

## C. Reiniciar el contador

```cpp
frecuencia = 0;
```

¿Por qué necesitamos colocar `frecuencia` en cero dentro del primer ciclo?

Porque cada vez que analizamos un número diferente debemos comenzar a contar desde cero.

Si no reiniciamos esta variable, estaríamos acumulando las apariciones de todos los números, produciendo un resultado incorrecto.

## D. Segundo ciclo `for`

```cpp
for (int j = 0; j < cantidad; j++) {
```

Aquí tenemos un ciclo anidado, uno de los temas que has estado practicando.

El ciclo exterior, controlado por `i`, selecciona el número que queremos analizar.

El ciclo interior, controlado por `j`, recorre todos los elementos para contar cuántas veces aparece ese número.

### La comparación

```cpp
if (*(arreglo + i) == *(arreglo + j)) {
```

Esta condición compara dos valores.

- `*(arreglo + i)` es el número que estamos analizando.
- `*(arreglo + j)` es el número con el que lo estamos comparando.

Si son iguales:

```cpp
frecuencia++;
```

Incrementamos el contador.

Observa que cuando `i` y `j` tienen el mismo valor, también se cuenta una coincidencia. Esto es correcto, porque cada número aparece al menos una vez: en su propia posición.

## 8. Simulación interactiva: cómo encuentra la moda

Utilicemos este arreglo:

```cpp
5  8  3  8  2  8  5
```

Selecciona un número para ver cómo el ciclo interior cuenta sus apariciones.

Simulación de los ciclos `for` anidados

[0]5

[1]8

[2]3

[3]8

[4]2

[5]8

[6]5

Número analizado

# 5

Frecuencia

# 2

5 aparece 2 veces en el arreglo.

Es un candidato a moda porque aparece más de una vez.

Selecciona distintas posiciones para simular las vueltas del ciclo exterior.

Ahora observa lo que calcula el programa:

| Número | Frecuencia |
| ------ | ---------- |
| 5      | 2          |
| 8      | 3          |
| 3      | 1          |
| 2      | 1          |

El número 8 es el que tiene la mayor frecuencia.

Por tanto:

```cpp
La moda del arreglo es: 8
```

## 9. ¿Cómo actualizamos la moda?

Después de contar las apariciones, ejecutamos:

```cpp
if (frecuencia > mayorFrecuencia) {

    mayorFrecuencia = frecuencia;

    moda = *(arreglo + i);
}
```

Esta condición comprueba si la frecuencia recién calculada supera a la mayor frecuencia encontrada anteriormente.

Por ejemplo:

Primera vuelta: analizamos el 5.

- Frecuencia del 5: 2.
- Mayor frecuencia inicial: 1.
- Como 2 es mayor que 1, guardamos 5 como moda.

Segunda vuelta: analizamos el 8.

- Frecuencia del 8: 3.
- Mayor frecuencia guardada: 2.
- Como 3 es mayor que 2, actualizamos la moda a 8.

Tercera vuelta: analizamos el 3.

- Frecuencia del 3: 1.
- Mayor frecuencia guardada: 3.
- Como 1 no es mayor que 3, no cambiamos nada.

Y así continuamos hasta terminar.

Al finalizar:

```cpp
return moda;
```

Devuelve el número que más se repitió.

### ¿Qué ocurre si hay dos números con la misma frecuencia máxima?

Por ejemplo:

```cpp
4  4  7  7  9
```

El 4 y el 7 aparecen dos veces.

Con nuestra solución se devuelve 4, porque fue el primero en alcanzar la frecuencia máxima. La condición utiliza `>` y no `>=`.

El mandato no especifica cómo resolver los empates entre varias modas. Esta implementación devuelve una de ellas, concretamente la primera que alcanza la máxima frecuencia. Si el profesor exige detectar todas las modas, tendríamos que ampliar la lógica.

# 10. Ejemplos de ejecución

### Ejemplo A — Existe una moda

```cpp
Cuantos numeros desea introducir? 7

Introduzca el numero 1: 5
Introduzca el numero 2: 8
Introduzca el numero 3: 3
Introduzca el numero 4: 8
Introduzca el numero 5: 2
Introduzca el numero 6: 8
Introduzca el numero 7: 5

NUMEROS INTRODUCIDOS
5 8 3 8 2 8 5

La moda del arreglo es: 8
```

### Ejemplo B — No existe moda

```cpp
Cuantos numeros desea introducir? 5

Introduzca el numero 1: 4
Introduzca el numero 2: 7
Introduzca el numero 3: 9
Introduzca el numero 4: 2
Introduzca el numero 5: 6

NUMEROS INTRODUCIDOS
4 7 9 2 6

El arreglo no tiene moda.
```

### Ejemplo C — Todos los números son iguales

```cpp
Cuantos numeros desea introducir? 4

Introduzca el numero 1: 10
Introduzca el numero 2: 10
Introduzca el numero 3: 10
Introduzca el numero 4: 10

NUMEROS INTRODUCIDOS
10 10 10 10

La moda del arreglo es: 10
```

## 11. Conceptos de C++ utilizados

| Concepto         | Aplicación                                   |
| ---------------- | -------------------------------------------- |
| `int *`          | Declaración de punteros                      |
| `new[]`          | Creación del arreglo dinámico                |
| `delete[]`       | Liberación de memoria                        |
| `nullptr`        | Reiniciar el puntero                         |
| `*(arreglo + i)` | Acceder a elementos con notación de punteros |
| `for`            | Recorrer los elementos                       |
| Ciclos anidados  | Comparar cada número con todos los demás     |
| `while`          | Validar entradas                             |
| `if-else`        | Mostrar el resultado correcto                |
| `frecuencia++`   | Contar las apariciones                       |
| `return moda`    | Devolver el número más frecuente             |
| `void`           | Función que no devuelve resultado            |

## 12. Preguntas que debes saber responder

1\. ¿Qué es la moda?

Es el valor que aparece con mayor frecuencia en un conjunto de datos.

2\. ¿Para qué sirve `mayorFrecuencia`?

Para recordar cuántas veces aparece el número más frecuente encontrado hasta ese momento.

3\. ¿Por qué inicializamos `moda` en `-1`?

Porque el profesor exige devolver ese valor cuando ningún número aparece más de una vez.

4\. ¿Por qué utilizamos dos ciclos `for`?

Porque necesitamos seleccionar cada número y compararlo con todos los elementos del arreglo.

5\. ¿Para qué sirve `frecuencia++`?

Para contar cuántas veces encontramos el número que estamos analizando.

6\. ¿Por qué colocamos `frecuencia = 0` dentro del primer ciclo?

Porque debemos comenzar un conteo nuevo para cada número.

7\. ¿Qué significa `*(arreglo + i)`?

Acceder al valor que se encuentra en la posición `i` con notación de punteros.

8\. ¿Por qué utilizamos `new[]` y `delete[]`?

Porque creamos un arreglo de tamaño decidido durante la ejecución y debemos liberar su memoria cuando terminamos.

9\. ¿Por qué `calcularModa()` devuelve `int`?

Porque la moda es uno de los valores enteros del arreglo, o `-1` si no existe.

10\. ¿Se modifica el arreglo original?

No. La función solamente cuenta las apariciones y devuelve un resultado.

## 13. Cómo compilarlo en tu Mac

Guarda el código como `Ejercicio3.cpp`.

Compila con:

```
clang++ -std=c++17 Ejercicio3.cpp -o Ejercicio3
```

Ejecuta:

```
./Ejercicio3
```

Para la entrega, te recomiendo tomar una captura donde se vea una moda y otra donde no exista.

Nota: el programa supone entradas numéricas válidas cuando se utiliza `cin`. Hemos validado los valores positivos, pero todavía no implementamos manejo de entradas no numéricas, para conservar una solución sencilla y acorde con los conceptos vistos.

## 14. Lo más importante que debes aprender de este ejercicio

Aquí hay tres conceptos que quiero que domines especialmente.

Primero: la notación de punteros.

```cpp
*(arreglo + i)
```

Es equivalente a:

```cpp
arreglo[i]
```

Pero el profesor exige que utilicemos la primera forma en este ejercicio.

Segundo: los ciclos anidados.

```cpp
for (int i = 0; i < cantidad; i++) {

    for (int j = 0; j < cantidad; j++) {

        if (*(arreglo + i) == *(arreglo + j)) {
            frecuencia++;
        }
    }
}
```

El primer ciclo selecciona un número y el segundo cuenta sus apariciones.

Tercero: identificar el mayor.

```cpp
if (frecuencia > mayorFrecuencia) {

    mayorFrecuencia = frecuencia;

    moda = *(arreglo + i);
}
```

Esta lógica es muy parecida a la que ya hemos trabajado para encontrar la nota mayor, el salario más alto o el producto más vendido.

La diferencia es que ahora buscamos la frecuencia más alta, no necesariamente el número más grande.

Archivos recomendados para guardar:

- Código fuente: `Ejercicio3.cpp`
- Documentación: `Ejercicio3_Calcular_Moda.md`

Con esto completamos el tercer ejercicio de la Unidad VI, utilizando punteros, memoria dinámica, funciones y ciclos anidados.

Cuando me digas «siguiente», trabajaremos el Ejercicio 4: crear una copia invertida de un arreglo y devolver un puntero al nuevo arreglo, con el mismo formato de código y explicación detallada.