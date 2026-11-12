# Unidad VI — Punteros y memoria dinámica en C++

Introducción a la Programación · UASD · Profesor Brito

Esta unidad es especialmente importante porque cambia la manera en que entendemos las variables, los arreglos y las funciones.

Hasta ahora hemos trabajado principalmente con valores: declaramos variables, guardamos números, utilizamos ciclos y enviamos argumentos a funciones.

En la Unidad VI aprenderemos a trabajar también con direcciones de memoria.

He revisado los dos materiales que compartiste:

- Unidad 6 — Punteros, de Félix Ferreiras y Zobiesky Ovalle (66 páginas).
- Punteros y memoria dinámica, de Gabriel Navarro (119 páginas).

El primero desarrolla los conceptos fundamentales que debemos priorizar para estudiar: variables puntero, relación con arreglos, aritmética de punteros, asignación dinámica de memoria y punteros con funciones. El segundo profundiza con matrices, cadenas de caracteres, estructuras y listas enlazadas.

Vamos a preparar estos apuntes para que puedas copiarlos a tu archivo `.md` y utilizarlos como referencia para tareas, prácticas y el examen final.

## 1. ¿Qué debes aprender en esta unidad?

| Tema                                  | Qué debes dominar                  | Prioridad   |
| ------------------------------------- | ---------------------------------- | ----------- |
| Direcciones de memoria                | Entender el operador `&`           | Fundamental |
| Punteros                              | Declarar y utilizar `*`            | Fundamental |
| Modificar variables mediante punteros | Diferenciar valor y dirección      | Fundamental |
| Punteros y arreglos                   | Utilizar índices y direcciones     | Fundamental |
| Aritmética de punteros                | Utilizar `p + 1`, `p++`            | Alta        |
| Punteros con funciones                | Enviar direcciones como argumentos | Alta        |
| Memoria dinámica                      | Utilizar `new` y `delete`          | Alta        |
| Arreglos dinámicos                    | Utilizar `new[]` y `delete[]`      | Alta        |
| Punteros constantes y `void*`         | Entender sus diferencias           | Media       |
| Matrices y estructuras con punteros   | Trabajar con datos más complejos   | Ampliación  |
| Listas enlazadas                      | Entender nodos y enlaces           | Ampliación  |

Las prioridades son mi propuesta de estudio, no una distribución oficial de puntos del profesor.

## 2. ¿Qué es la memoria y dónde se guardan las variables?

Cuando ejecutas un programa en C++, las variables ocupan espacio en la memoria.

Por ejemplo:

```
int edad = 25;
```

El computador necesita almacenar el valor `25` en algún lugar.

Imagina que esa variable se guarda en la dirección `0x1000`.

Representación simplificada de memoria

Las direcciones son ilustrativas. En una ejecución real pueden ser diferentes.

Una variable tiene dos cosas que debemos distinguir:

- Valor: el contenido que almacena, como `25`.
- Dirección: el lugar de memoria donde se encuentra ese contenido.

Esto es justamente lo que nos permite estudiar los punteros.

## 3. El operador `&`: obtener una dirección de memoria

Hasta ahora probablemente utilizabas:

```
cout << edad;
```

Esto muestra el valor.

Pero si escribes:

```
cout << &edad;
```

C++ muestra la dirección de memoria de la variable.

### Ejemplo 1 — Valor y dirección

```
#include <iostream>
using namespace std;

int main() {

    int numero = 50;

    cout << "Valor: " << numero << endl;
    cout << "Direccion: " << &numero << endl;

    return 0;
}
```

Resultado aproximado:

```
Valor: 50
Direccion: 0x16fdff3a8
```

La dirección cambia según la ejecución y el equipo.

Debes recordar:

```
numero   // Valor de la variable
&numero  // Direccion de la variable
```

El símbolo `&` tiene otros usos en C++, como el paso por referencia que viste en la Unidad V. Aquí estamos estudiando específicamente su uso para obtener direcciones.

## 4. ¿Qué es un puntero?

Un puntero es una variable cuyo contenido es una dirección de memoria.

Por ejemplo:

```
int numero = 50;
int *ptr = &numero;
```

Esto significa:

- `numero` almacena el número `50`.
- `&numero` obtiene su dirección.
- `ptr` guarda esa dirección.
- `*ptr` permite acceder al valor almacenado en esa dirección.

Cómo se relacionan una variable y un puntero

### Ejemplo 2 — Nuestro primer puntero

```
#include <iostream>
using namespace std;

int main() {

    int numero = 50;

    int *ptr = &numero;

    cout << "Valor de numero: " << numero << endl;
    cout << "Direccion de numero: " << &numero << endl;

    cout << "Contenido de ptr: " << ptr << endl;
    cout << "Valor al que apunta ptr: " << *ptr << endl;

    return 0;
}
```

Observa especialmente la diferencia entre:

```
cout << ptr;   // Muestra la direccion
cout << *ptr;  // Muestra el valor
```

### Los símbolos más importantes

| Expresión        | Significado                        |
| ---------------- | ---------------------------------- |
| `int *ptr;`      | Declara un puntero a `int`         |
| `&numero`        | Dirección de `numero`              |
| `ptr = &numero;` | Hace que `ptr` apunte a `numero`   |
| `ptr`            | Dirección almacenada en el puntero |
| `*ptr`           | Valor al que apunta el puntero     |

La operación de utilizar `*ptr` para acceder al objeto apuntado se llama desreferenciación o indirección.

## 5. Modificar una variable utilizando un puntero

Esta es una de las partes más importantes.

Un puntero no solamente puede leer el valor de una variable: también puede modificarlo.

### Ejemplo 3 — Cambiar un valor indirectamente

```
#include <iostream>
using namespace std;

int main() {

    int numero = 100;
    int *ptr = &numero;

    cout << "Antes: " << numero << endl;

    *ptr = 250;

    cout << "Despues: " << numero << endl;

    return 0;
}
```

Salida:

```
Antes: 100
Despues: 250
```

¿Por qué cambió `numero` si nunca escribimos `numero = 250`?

Porque `ptr` apunta a la misma variable.

La instrucción:

```
*ptr = 250;
```

Significa: guarda 250 en la variable que se encuentra en la dirección almacenada en `ptr`.

No estamos creando otra variable independiente. Estamos modificando `numero` indirectamente.

### Ejemplo 4 — Incrementar mediante punteros

```
#include <iostream>
using namespace std;

int main() {

    int numero = 10;
    int *ptr = &numero;

    *ptr += 5;

    cout << numero << endl;

    return 0;
}
```

Resultado:

```
15
```

Esta operación equivale a incrementar directamente `numero` en cinco unidades.

## 6. Diferencia entre `*` y `&`

Estos dos símbolos aparecen muchísimo en la Unidad VI. Es importante entenderlos antes de continuar.

| Símbolo | Uso                       | Ejemplo                |
| ------- | ------------------------- | ---------------------- |
| `&`     | Obtener una dirección     | `&edad`                |
| `*`     | Declarar un puntero       | `int *ptr;`            |
| `*`     | Acceder al valor apuntado | `*ptr`                 |
| `*`     | Multiplicar números       | `5 * 3`                |
| `&`     | Declarar una referencia   | `void funcion(int &n)` |
| `&&`    | AND lógico                | `a > 0 && b > 0`       |

### Comprueba si lo entendiste

1\. Si numero vale 20 y ptr apunta a numero, ¿qué muestra cout << \*ptr?

La dirección de memoria

20

El tamaño del puntero

2\. ¿Cuál instrucción cambia numero a 80?

ptr = 80;

&numero = 80;

\*ptr = 80;

3\. ¿Qué almacena ptr después de ptr = &numero?

La dirección de numero

Una copia del valor de numero

El nombre de la variable

Aciertos: 0 de 3

Reiniciar

## 7. Punteros y arreglos

El material del profesor dedica una sección completa a la relación entre punteros y arreglos.

Recuerda cómo declaramos un arreglo:

```
int numeros[5] = {10, 20, 30, 40, 50};
```

Hasta ahora accedíamos a los elementos con índices:

```
numeros[0]
numeros[1]
numeros[2]
```

Pero también podemos acceder utilizando punteros.

### Ejemplo 5 — Recorrer un arreglo con un puntero

```
#include <iostream>
using namespace std;

int main() {

    int numeros[5] = {10, 20, 30, 40, 50};

    int *ptr = numeros;

    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << endl;
    }

    return 0;
}
```

Resultado:

```
10
20
30
40
50
```

### ¿Por qué funciona?

Cuando utilizamos el nombre `numeros` en esta asignación:

```
int *ptr = numeros;
```

Obtenemos la dirección de su primer elemento.

Por eso:

```
ptr = &numeros[0];
```

También sería válido.

Las siguientes expresiones permiten acceder a los mismos elementos:

| Notación de arreglo | Notación de puntero |
| ------------------- | ------------------- |
| `numeros[0]`        | `*(ptr + 0)`        |
| `numeros[1]`        | `*(ptr + 1)`        |
| `numeros[2]`        | `*(ptr + 2)`        |
| `numeros[3]`        | `*(ptr + 3)`        |
| `numeros[4]`        | `*(ptr + 4)`        |

Una precisión técnica: el nombre de un arreglo no es exactamente una variable puntero modificable, aunque en muchas expresiones se convierte en un puntero a su primer elemento.

## 8. Aritmética de punteros

En un puntero podemos realizar operaciones como:

```
ptr + 1
ptr + 2
ptr++
ptr--
```

Pero aquí sucede algo diferente a las operaciones aritméticas normales.

Si `ptr` apunta a un `int`, avanzar una posición significa desplazarse hasta el siguiente entero, no necesariamente avanzar un solo byte.

Avanzar mediante un puntero

10[0]

20[1]

30[2]

40[3]

50[4]

ptr + 0 apunta al valor 10

Si cada `int` ocupa 4 bytes, el desplazamiento desde `ptr` es de 0 bytes.

Dirección ilustrativa: 0x1000

&#x20;RetrocederAvanzar&#x20;

### Ejemplo 6 — Incrementar el puntero

```
#include <iostream>
using namespace std;

int main() {

    int numeros[4] = {5, 10, 15, 20};

    int *ptr = numeros;

    cout << *ptr << endl;

    ptr++;

    cout << *ptr << endl;

    ptr++;

    cout << *ptr << endl;

    return 0;
}
```

Salida:

```
5
10
15
```

Cada `ptr++` mueve el puntero al siguiente elemento del arreglo.

### ¿Qué ocurre con los paréntesis?

Estas expresiones no significan lo mismo:

```
*(ptr + 1)
```

Accede al elemento siguiente.

```
*ptr + 1
```

Suma uno al valor al que apunta `ptr`, sin cambiar ese valor.

```
(*ptr)++;
```

Incrementa en uno el valor apuntado.

```
ptr++;
```

Mueve el propio puntero a la siguiente posición.

Estas diferencias pueden aparecer perfectamente en una práctica de la unidad.

### Comparar punteros

El material también enseña:

```
ptr1 == ptr2
ptr1 != ptr2
ptr1 < ptr2
ptr1 > ptr2
```

`==` compara si dos punteros almacenan la misma dirección.

Las comparaciones de orden (`<`, `>`, `<=`, `>=`) deben utilizarse en contextos apropiados, como posiciones dentro de un mismo arreglo. No debemos interpretar arbitrariamente direcciones de objetos independientes como si formaran una secuencia.

## 9. Punteros y funciones

Aquí se relaciona directamente la Unidad VI con la Unidad V, donde aprendimos parámetros, argumentos y `return`.

Antes trabajábamos con una función como:

```
void mostrarEdad(int edad);
```

Ahora veremos funciones que reciben direcciones.

### Ejemplo 7 — Modificar una variable desde una función

```
#include <iostream>
using namespace std;

// Prototipo
void duplicar(int *numero);

int main() {

    int edad = 20;

    cout << "Antes: " << edad << endl;

    duplicar(&edad);

    cout << "Despues: " << edad << endl;

    return 0;
}

// Funcion que recibe un puntero
void duplicar(int *numero) {

    *numero = *numero * 2;
}
```

Resultado:

```
Antes: 20
Despues: 40
```

Vamos a entender las tres instrucciones fundamentales.

Primero:

```
void duplicar(int *numero);
```

La función recibe un puntero a un entero.

Segundo:

```
duplicar(&edad);
```

Enviamos la dirección de la variable `edad`, no solamente su valor.

Tercero:

```
*numero = *numero * 2;
```

La función accede al valor de `edad` mediante el puntero y lo multiplica por dos.

Por eso `edad` cambia directamente dentro de `main()`.

## 10. Paso por valor, por referencia y mediante punteros

Ya habías visto estas formas de trabajar con funciones. Ahora podemos entenderlas mejor.

| Forma            | Parámetro | Llamada          | ¿Puede modificar el original? |
| ---------------- | --------- | ---------------- | ----------------------------- |
| Por valor        | `int n`   | `funcion(edad)`  | No, modifica una copia        |
| Por referencia   | `int &n`  | `funcion(edad)`  | Sí                            |
| Mediante puntero | `int *n`  | `funcion(&edad)` | Sí, usando `*n`               |

### Ejemplo 8 — Comparar las tres formas

```
#include <iostream>
using namespace std;

void porValor(int n) {
    n = 100;
}

void porReferencia(int &n) {
    n = 200;
}

void porPuntero(int *n) {
    *n = 300;
}

int main() {

    int numero = 10;

    porValor(numero);
    cout << numero << endl;

    porReferencia(numero);
    cout << numero << endl;

    porPuntero(&numero);
    cout << numero << endl;

    return 0;
}
```

Resultado:

```
10
200
300
```

Esto es muy importante para el examen.

En `porValor()`, se modifica una copia.

En `porReferencia()`, el parámetro representa la variable original.

En `porPuntero()`, se pasa una dirección por valor y se utiliza esa dirección para modificar la variable original.

## 11. Punteros y estructuras

El segundo PDF profundiza en el uso de punteros para acceder a estructuras.

Recuerda que anteriormente utilizábamos:

```
struct Estudiante {
    string nombre;
    int edad;
};
```

Y accedíamos a los campos así:

```
estudiante.edad
```

Ahora, si tenemos un puntero a una estructura, utilizaremos `->`.

### Ejemplo 9 — El operador `->`

```
#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
};

int main() {

    Estudiante alumno = {"Juan", 20};

    Estudiante *ptr = &alumno;

    cout << ptr->nombre << endl;
    cout << ptr->edad << endl;

    return 0;
}
```

Resultado:

```
Juan
20
```

Estas dos expresiones son equivalentes:

```
ptr->edad
```

```
(*ptr).edad
```

El operador `->` es una manera más cómoda de acceder a los miembros de una estructura mediante un puntero.

Regla para memorizar:

- Estructura normal: `alumno.edad`
- Puntero a estructura: `ptr->edad`

# Parte II — Memoria dinámica

## 12. ¿Qué es la memoria dinámica?

En el material de la Unidad VI aparece una de las aplicaciones principales de los punteros: solicitar memoria durante la ejecución del programa.

Hasta ahora trabajábamos con arreglos como este:

```
int numeros[5];
```

El tamaño es conocido al compilar.

Pero imagina que quieres que el usuario decida cuántos números va a almacenar:

```
¿Cuantos numeros desea registrar? 12
```

Necesitamos reservar espacio para doce números cuando el programa ya está ejecutándose.

Ahí entra la asignación dinámica de memoria.

El material distingue diferentes áreas de memoria, entre ellas la pila (stack) y la memoria dinámica (heap).

Modelo simplificado de la memoria de un programa

Pila (stack)

Variables locales y contexto de llamadas a funciones

Memoria dinámica (heap)

Espacio solicitado mediante `new`

Datos

Variables globales y estáticas, según su clase y duración

Código

Instrucciones ejecutables del programa

Diagrama conceptual para estudiar. La distribución real depende del sistema operativo y del compilador.

El material explica que la memoria dinámica se solicita cuando hace falta y que el programador debe liberarla cuando deja de necesitarla.

## 13. El operador `new`

`new` permite solicitar memoria dinámicamente.

### Ejemplo 10 — Crear un entero dinámicamente

```
#include <iostream>
using namespace std;

int main() {

    int *ptr = new int;

    *ptr = 100;

    cout << "Valor: " << *ptr << endl;

    delete ptr;

    ptr = nullptr;

    return 0;
}
```

### ¿Qué sucede paso a paso?

1\. Declaramos el puntero y reservamos memoria:

```
int *ptr = new int;
```

`new int` solicita espacio para almacenar un entero y devuelve su dirección.

2\. Guardamos un valor:

```
*ptr = 100;
```

3\. Mostramos el contenido:

```
cout << *ptr;
```

4\. Liberamos la memoria:

```
delete ptr;
```

5\. Evitamos conservar una dirección que ya no debe utilizarse:

```
ptr = nullptr;
```

`nullptr` representa un puntero nulo, que no apunta a un objeto.

El primer material utiliza también `NULL` o `0` en algunos ejemplos. Para los programas que compilamos con C++17, prefiero enseñarte `nullptr` por ser más claro.

## 14. Crear arreglos dinámicos con `new[]`

Este es uno de los puntos principales de la unidad.

### Ejemplo 11 — El usuario decide el tamaño

```
#include <iostream>
using namespace std;

int main() {

    int cantidad;

    cout << "Cuantos numeros desea guardar? ";
    cin >> cantidad;

    while (cantidad <= 0) {
        cout << "Introduzca una cantidad positiva: ";
        cin >> cantidad;
    }

    // Crear el arreglo dinamico
    int *numeros = new int[cantidad];

    // Llenar el arreglo
    for (int i = 0; i < cantidad; i++) {

        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // Mostrar los datos
    cout << "\nNUMEROS REGISTRADOS" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << numeros[i] << endl;
    }

    // Liberar la memoria
    delete[] numeros;

    numeros = nullptr;

    return 0;
}
```

### ¿Qué cambia respecto a un arreglo normal?

Antes:

```
int numeros[5];
```

Ahora:

```
int *numeros = new int[cantidad];
```

La cantidad se conoce durante la ejecución, cuando el usuario la introduce.

Sin embargo, una vez creado, ese arreglo dinámico conserva el tamaño solicitado. No crece automáticamente como un `vector`.

### ¿Por qué `delete[]` y no `delete`?

Porque se reservó memoria para varios elementos.

| Reserva                | Liberación correcta |
| ---------------------- | ------------------- |
| `new int`              | `delete ptr`        |
| `new double`           | `delete ptr`        |
| `new int[10]`          | `delete[] ptr`      |
| `new double[cantidad]` | `delete[] ptr`      |

Esta diferencia debes aprenderla muy bien. Utilizar una forma de liberación incompatible provoca comportamiento indefinido.

## 15. Ejemplo completo: calcular promedio usando memoria dinámica

Este ejercicio combina conocimientos de varias unidades: funciones, ciclos, punteros y arreglos dinámicos.

### Ejemplo 12 — Promedio de calificaciones

```
#include <iostream>
#include <iomanip>
using namespace std;

// Prototipo
double calcularPromedio(double *notas, int cantidad);

int main() {

    int cantidad;

    cout << "Cantidad de estudiantes: ";
    cin >> cantidad;

    while (cantidad <= 0) {
        cout << "Cantidad invalida. Introduzca otra: ";
        cin >> cantidad;
    }

    // Reservar memoria dinamica
    double *notas = new double[cantidad];

    // Registrar calificaciones
    for (int i = 0; i < cantidad; i++) {

        cout << "Nota del estudiante " << i + 1 << ": ";
        cin >> notas[i];

        while (notas[i] < 0 || notas[i] > 100) {
            cout << "Nota invalida. Intente otra vez: ";
            cin >> notas[i];
        }
    }

    // Llamar a la funcion
    double promedio = calcularPromedio(notas, cantidad);

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

### ¿Qué conceptos reúne?

- `new[]` solicita un arreglo de tamaño decidido en ejecución.
- `notas[i]` permite acceder a sus elementos.
- `for` recorre el arreglo.
- `while` valida las calificaciones.
- `calcularPromedio()` recibe un puntero y el tamaño.
- `return` devuelve el promedio.
- `delete[]` libera la memoria.

Observa:

```
double calcularPromedio(double *notas, int cantidad);
```

¿Por qué necesitamos enviar `cantidad`?

Porque un puntero por sí solo no indica cuántos elementos tiene el arreglo al que apunta. Si la función va a recorrerlo, necesita conocer sus límites por otro medio.

Este es uno de los aspectos que el material de la unidad destaca expresamente.

## 16. Errores peligrosos con punteros

Aquí hay que prestar especial atención. Algunos errores de punteros pueden compilar perfectamente, pero producir resultados inesperados o fallos durante la ejecución.

El material habla de corrupción de memoria.

### Error A — Utilizar un puntero sin inicializar

Código incorrecto:

```
int *ptr;

*ptr = 50;
```

`ptr` no tiene asignada una dirección válida conocida.

No podemos utilizar `*ptr` en esas condiciones.

### Error B — Utilizar memoria después de liberarla

Código incorrecto:

```
int *ptr = new int(100);

delete ptr;

cout << *ptr;
```

Después de `delete`, ya no debemos acceder al objeto mediante ese puntero.

### Error C — Liberar dos veces

Código incorrecto:

```
int *ptr = new int(20);

delete ptr;
delete ptr;
```

La misma memoria se intenta liberar dos veces.

### Error D — Acceder fuera del arreglo

Código incorrecto:

```
int *numeros = new int[5];

numeros[8] = 100;

delete[] numeros;
```

El arreglo solo tiene índices del 0 al 4.

El índice 8 está fuera de sus límites.

### Error E — No liberar la memoria

```
int *ptr = new int(100);

// Nunca se llama delete
```

Si no existe otro mecanismo que administre esa reserva, podemos provocar una fuga de memoria.

### Cómo prevenir estos errores

- Inicializar los punteros antes de utilizarlos.
- No desreferenciar punteros nulos.
- Respetar los límites de los arreglos.
- Utilizar `delete` o `delete[]` según la reserva.
- No volver a utilizar memoria liberada.
- No liberar dos veces la misma reserva.
- Preferir contenedores como `vector` cuando no sea necesario administrar memoria manualmente.

Los programas básicos de esta guía suponen entradas numéricas válidas y que las reservas de memoria tienen éxito. Más adelante podemos estudiar el manejo de fallos de entrada y de asignación de memoria.

## 17. Punteros constantes

El primer PDF presenta tres formas distintas.

### A. Puntero constante

```
int numero = 10;

int *const ptr = &numero;
```

Podemos modificar el valor:

```
*ptr = 20;
```

Pero no podemos hacer que `ptr` apunte a otra dirección.

### B. Puntero a constante

```
int numero = 10;

const int *ptr = &numero;
```

No podemos modificar el valor utilizando ese puntero:

```
// *ptr = 20;  // No permitido
```

Pero sí podemos hacer que apunte a otra variable compatible.

### C. Puntero constante a constante

```
int numero = 10;

const int *const ptr = &numero;
```

No podemos cambiar el destino del puntero ni modificar el valor mediante ese puntero.

| Declaración          | ¿Puede cambiar a dónde apunta? | ¿Puede modificar el valor apuntado? |
| -------------------- | ------------------------------ | ----------------------------------- |
| `int *p`             | Sí                             | Sí                                  |
| `int *const p`       | No                             | Sí                                  |
| `const int *p`       | Sí                             | No                                  |
| `const int *const p` | No                             | No                                  |

La tabla asume que las variables apuntadas no son constantes por sí mismas.

## 18. Punteros `void`

El material también presenta los punteros genéricos.

```
void *ptr;
```

Un `void*` puede almacenar direcciones de distintos tipos de objetos.

Por ejemplo:

```
int numero = 50;

void *ptr = &numero;
```

Pero no podemos hacer directamente:

```
// cout << *ptr;  // Incorrecto
```

Porque el compilador no sabe qué tipo de dato debe leer.

Para acceder al valor debemos convertir el puntero a un tipo adecuado.

### Ejemplo 13 — Puntero genérico

```
#include <iostream>
using namespace std;

int main() {

    int numero = 50;

    void *ptr = &numero;

    int *punteroEntero = static_cast<int*>(ptr);

    cout << *punteroEntero << endl;

    return 0;
}
```

Resultado:

```
50
```

Este es un tema complementario. Primero debes dominar bien los punteros normales a `int`, `double` y estructuras.

# Parte III — Temas de ampliación del segundo PDF

Estos temas están incluidos en Punteros y memoria dinámica, de Gabriel Navarro. Son importantes para conocer hacia dónde continúa el aprendizaje, aunque algunos son más complejos que los fundamentos iniciales de la unidad.

## 19. Punteros y cadenas de caracteres

Antes de trabajar con `string`, también podemos representar texto mediante arreglos de caracteres.

```
char nombre[] = "Juan";
```

Un puntero de tipo `char*` puede apuntar al primer carácter del arreglo.

### Ejemplo 14 — Recorrer una cadena

```
#include <iostream>
using namespace std;

int main() {

    char nombre[] = "Juan";

    char *ptr = nombre;

    while (*ptr != '\0') {

        cout << *ptr << endl;

        ptr++;
    }

    return 0;
}
```

Salida:

```
J
u
a
n
```

El carácter `'\0'` marca el final de la cadena de caracteres.

Es importante distinguir estos arreglos de caracteres de la clase `string` que ya hemos utilizado en otras unidades.

## 20. Punteros y matrices dinámicas

El segundo material también estudia cómo reservar matrices durante la ejecución.

En los ejercicios anteriores usábamos matrices como:

```
int numeros[3][4];
```

Con memoria dinámica podemos decidir las dimensiones durante la ejecución.

Una forma es utilizar un puntero a puntero, `int **`, para almacenar las direcciones de las filas.

### Ejemplo 15 — Matriz dinámica

```
#include <iostream>
using namespace std;

int main() {

    int filas = 2;
    int columnas = 3;

    // Reservar espacio para las filas
    int **matriz = new int*[filas];

    // Reservar las columnas de cada fila
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }

    // Registrar valores
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            cout << "Numero [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Mostrar matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }

        cout << endl;
    }

    // Liberar cada fila
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }

    // Liberar el arreglo de punteros
    delete[] matriz;

    return 0;
}
```

Observa que utilizamos dos ciclos anidados, algo que ya hemos practicado.

La diferencia es que ahora también necesitamos liberar la memoria que reservamos para cada fila y luego la memoria del arreglo que guarda sus direcciones.

## 21. Listas enlazadas

El segundo PDF dedica sus últimas secciones a las listas enlazadas.

Una lista enlazada es una estructura en la que cada elemento, llamado nodo, guarda información y una dirección hacia otro nodo.

Ejemplo de lista enlazada

Podemos definir un nodo así:

```
struct Nodo {
    int numero;
    Nodo *siguiente;
};
```

Y crear uno mediante memoria dinámica:

```
Nodo *primero = new Nodo;

primero->numero = 10;
primero->siguiente = nullptr;
```

En este caso:

- `numero` almacena el dato.
- `siguiente` almacena la dirección de otro nodo.
- `nullptr` indica que todavía no hay un nodo siguiente.

Las listas enlazadas permiten agregar y quitar elementos sin necesitar que todos estén almacenados en posiciones consecutivas como en un arreglo.

El material incluye operaciones para insertar, recorrer, contar y liberar nodos. También presenta un ejemplo más avanzado de diccionario. Son aplicaciones de los punteros que podemos estudiar después de dominar los ejercicios básicos.

# Parte IV — Repaso y preparación para prácticas

## 22. Los errores conceptuales que debes evitar

Estos son errores frecuentes cuando se empieza a estudiar la Unidad VI.

| Confusión                                                      | Explicación correcta                                 |
| -------------------------------------------------------------- | ---------------------------------------------------- |
| Creer que `ptr` siempre muestra el valor                       | Normalmente `ptr` representa una dirección           |
| Confundir `ptr` con `*ptr`                                     | Uno es el puntero; el otro accede al objeto apuntado |
| Creer que `ptr++` suma 1 al valor                              | Mueve el puntero al siguiente elemento               |
| Creer que `*ptr++` modifica el valor                           | Se interpreta como `*(ptr++)`                        |
| Creer que un arreglo puede crecer con `new[]`                  | Su tamaño queda fijado después de reservarlo         |
| Usar `delete` para un arreglo dinámico                         | Debe utilizarse `delete[]`                           |
| Acceder a memoria liberada                                     | Produce comportamiento indefinido                    |
| Creer que `nullptr` contiene una dirección válida de un objeto | Representa un puntero nulo                           |
| Creer que un puntero conoce el tamaño de un arreglo            | Hay que conservar o pasar el tamaño por separado     |

Hay una precisión adicional en el primer PDF que conviene tener presente: al escribir `*(ptr + 2)`, C++ ya considera el tamaño del tipo apuntado. No debemos multiplicar manualmente el índice por `sizeof(tipo)` para movernos dos elementos.

## 23. Ejercicios para practicar

Te recomiendo resolverlos en este orden, sin comenzar directamente por matrices dinámicas.

Lista de prácticas — Unidad VI

Marca las que completes

0 de 12 completados

01_direccion.cpp

Crear una variable y mostrar su valor y dirección.

02_primer_puntero.cpp

Crear un puntero y mostrar ptr y \*ptr.

03_modificar_valor.cpp

Cambiar un entero utilizando un puntero.

04_punteros_arreglos.cpp

Recorrer cinco números utilizando \*(ptr + i).

05_incrementar_puntero.cpp

Recorrer un arreglo utilizando ptr++.

06_funcion_puntero.cpp

Crear una función que triplique una variable mediante su dirección.

07_intercambiar.cpp

Crear una función que intercambie dos números mediante punteros.

08_new_delete.cpp

Crear un entero con new y liberarlo con delete.

09_arreglo_dinamico.cpp

Solicitar N notas, calcular el promedio y liberar memoria.

10_estructura_puntero.cpp

Acceder a una estructura utilizando ->.

11_matriz_dinamica.cpp

Crear una matriz dinámica de dos filas y tres columnas.

12_lista_enlazada.cpp

Crear dos nodos enlazados y liberarlos correctamente.

Los primeros diez ejercicios son los que priorizaría antes de pasar a las estructuras dinámicas más complejas.

## 24. Preguntas teóricas que debes poder responder

Si te hacen un cuestionario o examen de selección múltiple, estas son preguntas que conviene dominar:

1. ¿Qué es una variable puntero?
2. ¿Cuál es la diferencia entre `&` y `*`?
3. ¿Qué significa desreferenciar un puntero?
4. ¿Qué ocurre cuando modificamos `*ptr`?
5. ¿Cómo se relacionan los punteros con los arreglos?
6. ¿Qué significa `ptr + 1`?
7. ¿Qué diferencia existe entre `ptr++` y `(*ptr)++`?
8. ¿Cómo se envía la dirección de una variable a una función?
9. ¿Para qué se utiliza `new`?
10. ¿Cuál es la diferencia entre `delete` y `delete[]`?
11. ¿Qué es una fuga de memoria?
12. ¿Qué ocurre si utilizamos un puntero sin inicializar?
13. ¿Qué es un puntero constante?
14. ¿Para qué sirve el operador `->`?
15. ¿Por qué una función que recibe un arreglo dinámico también suele recibir su tamaño?

## 25. Hoja rápida de referencia

Esta parte te servirá especialmente cuando estés programando y olvides alguna instrucción.

| Quiero hacer esto                                   | Escribo                  |
| --------------------------------------------------- | ------------------------ |
| Declarar un entero                                  | `int numero = 10;`       |
| Obtener su dirección                                | `&numero`                |
| Declarar un puntero                                 | `int *ptr;`              |
| Apuntar a una variable                              | `ptr = &numero;`         |
| Leer el valor apuntado                              | `*ptr`                   |
| Modificar el valor apuntado                         | `*ptr = 50;`             |
| Apuntar al primer elemento de un arreglo            | `ptr = numeros;`         |
| Acceder al tercer elemento                          | `*(ptr + 2)`             |
| Avanzar al siguiente elemento                       | `ptr++;`                 |
| Declarar un puntero nulo                            | `int *ptr = nullptr;`    |
| Reservar un entero                                  | `new int`                |
| Reservar un arreglo                                 | `new int[cantidad]`      |
| Liberar un entero dinámico                          | `delete ptr;`            |
| Liberar un arreglo dinámico                         | `delete[] ptr;`          |
| Acceder al campo de una estructura mediante puntero | `ptr->edad`              |
| Recibir un puntero en una función                   | `void funcion(int *ptr)` |
| Enviar la dirección de una variable                 | `funcion(&numero);`      |

## 26. ¿Qué debemos dominar antes de dar por terminada la Unidad VI?

Yo dividiría nuestro estudio en cuatro etapas.

1. Fundamentos de punteros

   Comprender `&`, `*`, dirección de memoria, desreferenciación y modificación indirecta.
2. Punteros con arreglos y funciones

   Dominar `*(ptr + i)`, `ptr++`, funciones que reciben punteros y su relación con el paso por referencia.
3. Memoria dinámica

   Crear datos y arreglos con `new`, liberar con `delete` y `delete[]`, y evitar errores de memoria.
4. Aplicaciones avanzadas

   Repasar punteros con estructuras, matrices dinámicas y los fundamentos de listas enlazadas.

## 27. Relación con nuestro proyecto de Accesorios Mashiaj

Te aclaro algo que será importante cuando continuemos el proyecto final.

No necesitamos introducir punteros ni `new` en el sistema de facturación solo porque ahora estamos estudiando esta unidad.

Actualmente ya podemos almacenar cantidades, realizar compras, calcular el ITBIS e imprimir facturas utilizando arreglos normales y funciones.

Si el profesor pide utilizar memoria dinámica o punteros en el proyecto final, estudiaremos dónde tienen sentido y cómo incorporarlos correctamente.

Eso sigue la misma idea que aprendiste en el primer parcial: primero analizamos el problema y después elegimos las herramientas necesarias.

### Mi recomendación para estudiar esta unidad

Si hay algo que deberías saber explicar sin mirar tus apuntes, es este pequeño programa:

```
#include <iostream>
using namespace std;

void aumentar(int *numero) {
    *numero += 10;
}

int main() {

    int valor = 20;

    int *ptr = &valor;

    cout << *ptr << endl;

    aumentar(ptr);

    cout << valor << endl;

    return 0;
}
```

Salida:

```
20
30
```

Cuando entiendas por qué `valor` termina siendo `30`, habrás comprendido una de las ideas centrales de los punteros.

Después continuamos con los arreglos y la memoria dinámica, que es donde estos conceptos se vuelven más interesantes.

Conserva estos apuntes como `UNIDAD_6_PUNTEROS.md` en tu repositorio de aprendizaje. Los ejemplos están separados por tema y podemos ampliarlos con el material, las prácticas y las tareas que vaya asignando el profesor.