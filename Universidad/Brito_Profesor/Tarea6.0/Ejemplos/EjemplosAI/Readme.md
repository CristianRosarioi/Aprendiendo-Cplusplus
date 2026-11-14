# Unidad VI — 10 ejemplos básicos de punteros en C++

Introducción a la Programación · UASD · Profesor Brito

Vamos a preparar 10 programas independientes, desde lo más básico hasta algunos usos prácticos de los punteros y la memoria dinámica.

La idea es que puedas copiarlos a VS Code, compilarlos, modificarlos y guardar cada uno con su explicación en tu archivo `.md`.

Los ejemplos utilizarán solamente lo que hemos estudiado: variables, `cin`, `cout`, `if`, ciclos `for`, funciones, arreglos, estructuras, punteros y memoria dinámica.

## Los 10 ejemplos que practicaremos

| #  | Programa                      | Concepto principal                      |
| -- | ----------------------------- | --------------------------------------- |
| 1  | `01_direccion_memoria.cpp`    | Operador `&`                            |
| 2  | `02_primer_puntero.cpp`       | Punteros y `*`                          |
| 3  | `03_modificar_valor.cpp`      | Modificar variables mediante punteros   |
| 4  | `04_punteros_arreglos.cpp`    | Recorrer arreglos con punteros          |
| 5  | `05_avanzar_puntero.cpp`      | `ptr++` y `(*ptr)++`                    |
| 6  | `06_funcion_puntero.cpp`      | Punteros como parámetros                |
| 7  | `07_intercambiar_valores.cpp` | Modificar dos variables con una función |
| 8  | `08_memoria_dinamica.cpp`     | `new` y `delete`                        |
| 9  | `09_arreglo_dinamico.cpp`     | `new[]`, `delete[]` y promedios         |
| 10 | `10_puntero_estructura.cpp`   | Punteros con `struct` y `->`            |

## Ejemplo 1 — Mostrar el valor y la dirección de una variable

Objetivo: entender que una variable tiene un valor y una dirección de memoria.

```cpp
#include <iostream>
using namespace std;

int main() {

    int numero = 25;

    cout << "Valor de numero: " << numero << endl;

    cout << "Direccion de numero: " << &numero << endl;

    return 0;
}
```

### Explicación

```cpp
int numero = 25;
```

Creamos una variable entera y almacenamos `25`.

```cpp
cout << numero;
```

Muestra el contenido de la variable.

```cpp
cout << &numero;
```

Muestra su dirección de memoria.

El símbolo `&` se utiliza aquí para obtener la dirección de una variable.

### Resultado

```cpp
Valor de numero: 25
Direccion de numero: 0x16fdff308
```

La dirección es solamente un ejemplo. Puede ser diferente cada vez que ejecutes el programa.

Lo que debes aprender: `numero` y `&numero` no significan lo mismo.

## Ejemplo 2 — Crear nuestro primer puntero

Objetivo: aprender a declarar un puntero y acceder al valor al que apunta.

```cpp
#include <iostream>
using namespace std;

int main() {

    int edad = 20;

    int *ptr = &edad;

    cout << "Edad: " << edad << endl;

    cout << "Direccion de edad: " << &edad << endl;

    cout << "Contenido de ptr: " << ptr << endl;

    cout << "Valor apuntado por ptr: " << *ptr << endl;

    return 0;
}
```

### Explicación

La primera instrucción:

```cpp
int edad = 20;
```

Crea una variable que almacena `20`.

Después:

```cpp
int *ptr = &edad;
```

Aquí suceden dos cosas:

- `int *ptr` declara un puntero a entero.
- `&edad` obtiene la dirección de la variable `edad`.

Por tanto, `ptr` guarda la dirección de `edad`.

Ahora observa:

```cpp
cout << ptr;
```

Muestra la dirección almacenada en el puntero.

Mientras que:

```cpp
cout << *ptr;
```

Muestra el valor al que apunta, es decir, `20`.

### Resultado aproximado

```cpp
Edad: 20
Direccion de edad: 0x1000
Contenido de ptr: 0x1000
Valor apuntado por ptr: 20
```

### Visualización

Lo que debes aprender: `ptr` contiene una dirección; `*ptr` permite acceder al valor de esa dirección.

## Ejemplo 3 — Modificar el valor de una variable con un puntero

Objetivo: comprender que un puntero puede modificar la variable a la que apunta.

```cpp
#include <iostream>
using namespace std;

int main() {

    int numero = 10;

    int *ptr = &numero;

    cout << "Valor original: " << numero << endl;

    *ptr = 50;

    cout << "Nuevo valor: " << numero << endl;

    *ptr += 10;

    cout << "Valor final: " << numero << endl;

    return 0;
}
```

### Explicación

Primero:

```cpp
int numero = 10;
int *ptr = &numero;
```

Creamos una variable y un puntero que apunta a ella.

Después:

```cpp
*ptr = 50;
```

Esta instrucción modifica el contenido de la variable `numero`.

¿Por qué?

Porque `ptr` apunta a la dirección donde está almacenado `numero`.

Por tanto, esta instrucción es equivalente a escribir:

```cpp
numero = 50;
```

Luego:

```cpp
*ptr += 10;
```

Aumenta el valor apuntado en diez unidades.

### Resultado

```cpp
Valor original: 10
Nuevo valor: 50
Valor final: 60
```

Lo que debes aprender: al modificar `*ptr`, estamos modificando la variable original.

## Ejemplo 4 — Recorrer un arreglo utilizando punteros

Objetivo: aprender cómo utilizar un puntero con un arreglo y un ciclo `for`.

```cpp
#include <iostream>
using namespace std;

int main() {

    int numeros[5] = {10, 20, 30, 40, 50};

    int *ptr = numeros;

    cout << "NUMEROS DEL ARREGLO" << endl;

    for (int i = 0; i < 5; i++) {

        cout << *(ptr + i) << endl;
    }

    return 0;
}
```

### Explicación

Creamos un arreglo:

```cpp
int numeros[5] = {10, 20, 30, 40, 50};
```

Contiene cinco números.

Después:

```cpp
int *ptr = numeros;
```

El puntero recibe la dirección del primer elemento del arreglo.

Ahora observa:

```cpp
for (int i = 0; i < 5; i++)
```

El ciclo recorre las cinco posiciones.

Y dentro:

```cpp
cout << *(ptr + i);
```

Utilizamos notación de punteros para leer cada elemento.

| Valor de `i` | Expresión    | Resultado |
| ------------ | ------------ | --------- |
| 0            | `*(ptr + 0)` | 10        |
| 1            | `*(ptr + 1)` | 20        |
| 2            | `*(ptr + 2)` | 30        |
| 3            | `*(ptr + 3)` | 40        |
| 4            | `*(ptr + 4)` | 50        |

Esta expresión:

```cpp
*(ptr + i)
```

Es equivalente a:

```cpp
numeros[i]
```

### Resultado

```cpp
NUMEROS DEL ARREGLO
10
20
30
40
50
```

Lo que debes aprender: podemos acceder a los elementos de un arreglo mediante índices o aritmética de punteros.

## Ejemplo 5 — Diferencia entre `ptr++` y `(*ptr)++`

Objetivo: entender la diferencia entre mover un puntero y modificar el valor apuntado.

```cpp
#include <iostream>
using namespace std;

int main() {

    int numeros[3] = {10, 20, 30};

    int *ptr = numeros;

    cout << "Primer valor: " << *ptr << endl;

    // Avanzar a la siguiente posicion
    ptr++;

    cout << "Segundo valor: " << *ptr << endl;

    // Aumentar el valor apuntado
    (*ptr)++;

    cout << "Segundo valor aumentado: " << *ptr << endl;

    cout << "Arreglo completo: " << endl;

    for (int i = 0; i < 3; i++) {
        cout << numeros[i] << " ";
    }

    cout << endl;

    return 0;
}
```

### Explicación

Inicialmente:

```cpp
int *ptr = numeros;
```

El puntero apunta al primer elemento, que vale `10`.

Luego:

```cpp
ptr++;
```

Hace que el puntero avance al siguiente elemento, que vale `20`.

No aumenta el número 10 ni el número 20. Solamente cambia hacia dónde apunta.

Después:

```cpp
(*ptr)++;
```

Esto aumenta el valor apuntado.

Como ahora el puntero apunta al segundo elemento, ese número cambia de `20` a `21`.

### Resultado

```cpp
Primer valor: 10
Segundo valor: 20
Segundo valor aumentado: 21
Arreglo completo:
10 21 30
```

### Diferencia fundamental

| Instrucción  | Qué hace                                     |
| ------------ | -------------------------------------------- |
| `ptr++`      | Avanza al siguiente elemento                 |
| `(*ptr)++`   | Incrementa el valor apuntado                 |
| `*ptr = 50`  | Reemplaza el valor apuntado                  |
| `*(ptr + 1)` | Accede al elemento siguiente sin mover `ptr` |

Este es uno de los conceptos que más te recomiendo practicar.

## Ejemplo 6 — Utilizar un puntero como parámetro de una función

Objetivo: aprender cómo una función puede modificar una variable de `main()` mediante un puntero.

```cpp
#include <iostream>
using namespace std;

// Prototipo
void duplicarNumero(int *numero);

int main() {

    int valor;

    cout << "Introduzca un numero: ";
    cin >> valor;

    cout << "Antes: " << valor << endl;

    duplicarNumero(&valor);

    cout << "Despues: " << valor << endl;

    return 0;
}

// Funcion que duplica el numero
void duplicarNumero(int *numero) {

    *numero = *numero * 2;
}
```

### Explicación

Primero declaramos el prototipo:

```cpp
void duplicarNumero(int *numero);
```

Esta función:

- Se llama `duplicarNumero`.
- Recibe un puntero a entero.
- No devuelve un resultado mediante `return`.

Desde `main()` llamamos:

```cpp
duplicarNumero(&valor);
```

¿Por qué utilizamos `&valor`?

Porque la función necesita recibir una dirección de memoria.

Dentro de la función:

```cpp
*numero = *numero * 2;
```

El puntero permite acceder a `valor` y multiplicarlo por dos.

### Ejemplo de ejecución

```cpp
Introduzca un numero: 15
Antes: 15
Despues: 30
```

### Lo más importante

La función no devuelve un número porque modifica directamente la variable original mediante su dirección.

Recuerda que esto es diferente del paso por valor tradicional:

```cpp
void duplicarNumero(int numero);
```

En ese caso, el parámetro sería una copia y modificarlo no cambiaría la variable original.

## Ejemplo 7 — Intercambiar dos números mediante punteros

Objetivo: utilizar una función que recibe dos direcciones y modifica dos variables.

Este ejemplo es especialmente útil para comprender el intercambio de valores que vimos en el método de burbuja del Ejercicio 1.

```cpp
#include <iostream>
using namespace std;

// Prototipo
void intercambiar(int *a, int *b);

int main() {

    int numero1 = 10;
    int numero2 = 20;

    cout << "ANTES DEL INTERCAMBIO" << endl;

    cout << "Numero 1: " << numero1 << endl;
    cout << "Numero 2: " << numero2 << endl;

    intercambiar(&numero1, &numero2);

    cout << "\nDESPUES DEL INTERCAMBIO" << endl;

    cout << "Numero 1: " << numero1 << endl;
    cout << "Numero 2: " << numero2 << endl;

    return 0;
}

// Funcion que intercambia los valores
void intercambiar(int *a, int *b) {

    int temporal;

    temporal = *a;

    *a = *b;

    *b = temporal;
}
```

### Explicación

Declaramos dos variables:

```cpp
int numero1 = 10;
int numero2 = 20;
```

Después llamamos:

```cpp
intercambiar(&numero1, &numero2);
```

Enviamos las direcciones de ambas variables.

Dentro de la función:

```cpp
int temporal;
```

Creamos una variable temporal.

Luego:

```cpp
temporal = *a;
```

Guardamos el primer valor en `temporal`.

Después:

```cpp
*a = *b;
```

Copiamos el segundo valor en la primera variable.

Finalmente:

```cpp
*b = temporal;
```

Colocamos el valor que habíamos guardado en la segunda variable.

### Resultado

```cpp
ANTES DEL INTERCAMBIO
Numero 1: 10
Numero 2: 20

DESPUES DEL INTERCAMBIO
Numero 1: 20
Numero 2: 10
```

Lo que debes aprender: utilizando punteros podemos modificar varias variables desde una función sin necesidad de devolverlas individualmente.

# Ejemplos de memoria dinámica

Los primeros siete ejemplos utilizan punteros que apuntan a variables o arreglos ya existentes.

Ahora aprenderemos a solicitar y liberar memoria durante la ejecución.

## Ejemplo 8 — Crear una variable dinámicamente con `new`

Objetivo: comprender los operadores `new` y `delete`.

```cpp
#include <iostream>
using namespace std;

int main() {

    int *numero;

    // Reservar memoria dinamicamente
    numero = new int;

    // Guardar un valor en esa memoria
    *numero = 100;

    cout << "Valor almacenado: " << *numero << endl;

    // Modificar el valor
    *numero = 250;

    cout << "Nuevo valor: " << *numero << endl;

    // Liberar la memoria
    delete numero;

    numero = nullptr;

    return 0;
}
```

### Explicación

Declaramos:

```cpp
int *numero;
```

Esto crea un puntero, pero todavía no hemos reservado memoria para el entero al que apuntará.

Después:

```cpp
numero = new int;
```

`new` solicita espacio en la memoria dinámica para almacenar un entero.

El puntero recibe la dirección de ese espacio.

Ahora podemos escribir:

```cpp
*numero = 100;
```

Para guardar el valor `100`.

También podemos modificarlo:

```cpp
*numero = 250;
```

Cuando terminamos:

```cpp
delete numero;
```

Liberamos la memoria reservada.

Y:

```cpp
numero = nullptr;
```

Dejamos el puntero sin apuntar a un objeto.

### Resultado

```cpp
Valor almacenado: 100
Nuevo valor: 250
```

### Regla que debes memorizar

```cpp
new int
```

Se libera con:

```cpp
delete puntero;
```

No utilices `delete[]` para liberar un objeto individual creado con `new int`.

## Ejemplo 9 — Crear un arreglo dinámico y calcular un promedio

Objetivo: combinar memoria dinámica, funciones, arreglos y ciclos.

Este ejemplo es parecido a la Tarea 1, pero más sencillo porque no necesita ordenar los números.

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

// Prototipo
double calcularPromedio(double *notas, int cantidad);

int main() {

    int cantidad;
    double promedio;

    double *notas;

    cout << "Cuantos estudiantes desea registrar? ";
    cin >> cantidad;

    while (cantidad <= 0) {
        cout << "Cantidad invalida: ";
        cin >> cantidad;
    }

    // Crear arreglo dinamico
    notas = new double[cantidad];

    // Registrar las notas
    for (int i = 0; i < cantidad; i++) {

        cout << "Introduzca la nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    // Calcular el promedio con una funcion
    promedio = calcularPromedio(notas, cantidad);

    cout << fixed << setprecision(2);

    cout << "\nPromedio general: " << promedio << endl;

    // Liberar memoria
    delete[] notas;

    notas = nullptr;

    return 0;
}

// Funcion que calcula el promedio
double calcularPromedio(double *notas, int cantidad) {

    double suma = 0;

    for (int i = 0; i < cantidad; i++) {

        suma += notas[i];
    }

    return suma / cantidad;
}
```

### Explicación

Primero declaramos un puntero:

```cpp
double *notas;
```

Después solicitamos la cantidad de estudiantes.

Imagina que el usuario introduce:

```cpp
3
```

Entonces:

```cpp
notas = new double[cantidad];
```

Reserva memoria para tres valores `double`.

Luego:

```cpp
for (int i = 0; i < cantidad; i++)
```

Recorre las posiciones del arreglo.

En cada posición guardamos una nota:

```cpp
cin >> notas[i];
```

Después llamamos a:

```cpp
promedio = calcularPromedio(notas, cantidad);
```

La función recibe el puntero al arreglo y la cantidad de elementos.

Dentro de la función:

```cpp
double suma = 0;
```

Inicializamos un acumulador.

Después:

```cpp
suma += notas[i];
```

Acumulamos las calificaciones.

Finalmente:

```cpp
return suma / cantidad;
```

Devolvemos el promedio.

### Ejemplo de ejecución

```cpp
Cuantos estudiantes desea registrar? 3

Introduzca la nota 1: 80
Introduzca la nota 2: 90
Introduzca la nota 3: 70

Promedio general: 80.00
```

### ¿Por qué `delete[]` y no `delete`?

Porque creamos un arreglo:

```cpp
new double[cantidad]
```

Por tanto, necesitamos liberar la reserva completa:

```cpp
delete[] notas;
```

Lo que debes aprender: cuando utilizamos memoria dinámica, el tamaño del arreglo puede decidirse durante la ejecución del programa.

## Ejemplo 10 — Utilizar punteros con estructuras (`struct`)

Objetivo: aprender a utilizar el operador `->` para acceder a los miembros de una estructura mediante un puntero.

Este ejemplo es útil porque ya hemos utilizado estructuras en muchos ejercicios universitarios.

```cpp
#include <iostream>
#include <string>
using namespace std;

// Estructura
struct Estudiante {
    string nombre;
    int edad;
    double nota;
};

int main() {

    Estudiante alumno;

    // Puntero a la estructura
    Estudiante *ptr = &alumno;

    // Registrar los datos
    cout << "Nombre: ";
    cin >> ptr->nombre;

    cout << "Edad: ";
    cin >> ptr->edad;

    cout << "Nota: ";
    cin >> ptr->nota;

    // Mostrar los datos
    cout << "\nDATOS DEL ESTUDIANTE" << endl;

    cout << "Nombre: " << ptr->nombre << endl;
    cout << "Edad: " << ptr->edad << endl;
    cout << "Nota: " << ptr->nota << endl;

    // Verificar si aprobo
    if (ptr->nota >= 70) {

        cout << "Estado: Aprobado" << endl;

    } else {

        cout << "Estado: Reprobado" << endl;
    }

    return 0;
}
```

### Explicación

Primero creamos una estructura:

```cpp
struct Estudiante {
    string nombre;
    int edad;
    double nota;
};
```

Después declaramos una variable de ese tipo:

```cpp
Estudiante alumno;
```

Y creamos un puntero:

```cpp
Estudiante *ptr = &alumno;
```

Ahora `ptr` apunta a la estructura `alumno`.

Antes accedíamos a los miembros así:

```cpp
alumno.nombre
alumno.edad
alumno.nota
```

Pero utilizando un puntero escribimos:

```cpp
ptr->nombre
ptr->edad
ptr->nota
```

El operador `->` permite acceder a los miembros de una estructura mediante un puntero.

Por eso:

```cpp
cin >> ptr->edad;
```

Guarda la edad directamente en la estructura `alumno`.

### Ejemplo de ejecución

```cpp
Nombre: Juan
Edad: 20
Nota: 85

DATOS DEL ESTUDIANTE
Nombre: Juan
Edad: 20
Nota: 85
Estado: Aprobado
```

### Diferencia entre `.` y `->`

| Tenemos                     | Utilizamos    |
| --------------------------- | ------------- |
| Una estructura normal       | `alumno.edad` |
| Un puntero a una estructura | `ptr->edad`   |

Estas expresiones acceden al mismo miembro en nuestro ejemplo:

```cpp
alumno.edad
```

```cpp
ptr->edad
```

```cpp
(*ptr).edad
```

Lo que debes aprender: cuando trabajamos con un puntero a una estructura, el operador `->` nos permite acceder fácilmente a sus datos.

# Repaso final de los 10 ejemplos

## Las instrucciones que debes dominar

| Instrucción        | Significado                          |
| ------------------ | ------------------------------------ |
| `&numero`          | Obtener la dirección de una variable |
| `int *ptr`         | Declarar un puntero a entero         |
| `ptr = &numero`    | Apuntar hacia una variable           |
| `*ptr`             | Acceder al valor apuntado            |
| `*ptr = 50`        | Modificar el valor apuntado          |
| `ptr++`            | Avanzar el puntero                   |
| `(*ptr)++`         | Incrementar el valor apuntado        |
| `*(ptr + i)`       | Acceder a una posición del arreglo   |
| `funcion(&numero)` | Enviar una dirección a una función   |
| `new int`          | Reservar memoria para un entero      |
| `delete ptr`       | Liberar un objeto creado con `new`   |
| `new int[5]`       | Reservar un arreglo dinámico         |
| `delete[] ptr`     | Liberar un arreglo dinámico          |
| `nullptr`          | Representar un puntero nulo          |
| `ptr->edad`        | Acceder al campo de una estructura   |

## Prueba tus conocimientos

1\. ¿Qué imprime \*ptr cuando ptr apunta a una variable cuyo valor es 30?

Una dirección de memoria

30

El tamaño de la variable

2\. ¿Qué diferencia hay entre ptr++ y (\*ptr)++?

Son exactamente iguales

ptr++ avanza el puntero y (\*ptr)++ aumenta el valor

Ambos liberan memoria

3\. Si utilizas new int[10], ¿cómo liberas esa memoria?

delete[] ptr;

delete ptr;

ptr = nullptr;

4\. ¿Cómo accedes al campo edad mediante un puntero a una estructura?

ptr.edad

\*ptr.edad

ptr->edad

Aciertos: 0 de 4

Reiniciar

## Cómo guardarlos y compilarlos

Te recomiendo crear esta estructura dentro de tu repositorio:

```cpp
Universidad/
└── Brito_Profesor/
    └── Tarea6.0/
        └── Practicas_Punteros/
            ├── 01_direccion_memoria.cpp
            ├── 02_primer_puntero.cpp
            ├── 03_modificar_valor.cpp
            ├── 04_punteros_arreglos.cpp
            ├── 05_avanzar_puntero.cpp
            ├── 06_funcion_puntero.cpp
            ├── 07_intercambiar_valores.cpp
            ├── 08_memoria_dinamica.cpp
            ├── 09_arreglo_dinamico.cpp
            ├── 10_puntero_estructura.cpp
            └── README.md
```

Cada archivo `.cpp` tiene su propio `main()`, por lo que debes compilarlos individualmente.

Por ejemplo, en Mac:

```cpp
clang++ -std=c++17 01_direccion_memoria.cpp -o ejemplo1
./ejemplo1
```

Para los otros programas solamente cambia el nombre del archivo y del ejecutable.

Nota: estos ejemplos se centran en la lógica de punteros y memoria dinámica. Suponemos que las entradas introducidas mediante `cin` son del tipo correcto y que las reservas de memoria tienen éxito.

## Lo que te recomiendo practicar primero

Aunque ya resolvimos los cuatro ejercicios del profesor, quiero que prestes especial atención a los ejemplos 2, 3, 5, 6, 7 y 9. Son los que mejor te ayudarán a comprender qué hace realmente un puntero y por qué necesitamos utilizarlo.

Por ejemplo, una prueba excelente sería tomar el Ejemplo 6 y modificarlo para crear estas tres funciones:

```cpp
void sumarDiez(int *numero);
void triplicar(int *numero);
void convertirACero(int *numero);
```

Intenta implementarlas tú mismo utilizando `*numero`.

Si puedes explicar cuándo utilizamos `&`, cuándo utilizamos `*` y por qué una función puede modificar una variable a través de un puntero, ya tendrás una base bastante sólida para seguir avanzando en la Unidad VI.

Puedes guardar esta respuesta como `README.md` dentro de `Practicas_Punteros/`, junto con los diez archivos `.cpp`. Así tendrás tanto los programas como sus explicaciones disponibles para estudiar sin conexión.