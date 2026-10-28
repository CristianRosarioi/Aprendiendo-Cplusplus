# Unidad 5 — Tarea 2: Piedra, Papel o Tijera en C++

Vamos con la segunda tarea del profesor Brito. Esta vez combinaremos conceptos que ya conoces (`if`, `else`, `do-while`, `char`, `string`) con lo nuevo de la unidad 5: funciones, parámetros, argumentos y valores de retorno.

El objetivo es que puedas guardar el programa en GitHub, estudiarlo y explicar cada parte sin dificultad.

## 1. ¿Qué pide exactamente el mandato?

El profesor solicita crear un juego de Piedra, Papel o Tijera entre el usuario y la computadora.

El programa debe:

1. Mostrar un menú mediante una función.
2. Permitir introducir `P`, `A`, `T` o `S`, en mayúsculas o minúsculas.
3. Validar las opciones mediante una función que devuelva `bool`.
4. Generar la elección de la computadora utilizando `rand()` y `srand()`.
5. Comparar las opciones con una función que devuelva `string`.
6. Repetir el juego mediante `do-while` hasta seleccionar salir.

Además, el mandato sugiere estos cuatro prototipos, que respetaremos:

```cpp
void displayMenu();
char getComputerOption();
string checkOptions(char, char);
bool inputOK(char);
```

## 2. Código completo — `tarea2.cpp`
```cpp

/*
Universidad Autonoma de Santo Domingo
Introduccion a la Programacion
Unidad V - Tarea 2

Juego: Piedra, Papel o Tijera
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Constantes para las opciones
const char PIEDRA = 'P';
const char PAPEL = 'A';
const char TIJERA = 'T';
const char SALIR = 'S';

// Prototipos de las funciones
void displayMenu();
char getComputerOption();
string checkOptions(char, char);
bool inputOK(char);

int main() {
    char opcionUsuario;
    char opcionComputadora;
    string resultado;

    // Inicializar los numeros aleatorios
    srand(time(0));

    do {
        displayMenu();

        cin >> opcionUsuario;

        // Convertir a mayuscula
        opcionUsuario = toupper(opcionUsuario);

        // Validar la opcion
        while (!inputOK(opcionUsuario)) {
            cout << "Opcion no valida. Intente de nuevo: ";
            cin >> opcionUsuario;
            opcionUsuario = toupper(opcionUsuario);
        }

        if (opcionUsuario != SALIR) {

            // Generar la opcion de la computadora
            opcionComputadora = getComputerOption();

            // Mostrar las selecciones
            cout << "Usted eligio: ";

            if (opcionUsuario == PIEDRA) {
                cout << "Piedra" << endl;
            } else if (opcionUsuario == PAPEL) {
                cout << "Papel" << endl;
            } else {
                cout << "Tijera" << endl;
            }

            cout << "La computadora eligio: ";

            if (opcionComputadora == PIEDRA) {
                cout << "Piedra" << endl;
            } else if (opcionComputadora == PAPEL) {
                cout << "Papel" << endl;
            } else {
                cout << "Tijera" << endl;
            }

            // Comparar las opciones
            resultado = checkOptions(opcionUsuario,
                                     opcionComputadora);

            cout << "Resultado: " << resultado << endl;
            cout << endl;
        }

    } while (opcionUsuario != SALIR);

    cout << "Gracias por jugar." << endl;

    return 0;
}

// Funcion que muestra el menu
void displayMenu() {
    cout << "===== PIEDRA, PAPEL O TIJERA =====" << endl;
    cout << "P - Piedra" << endl;
    cout << "A - Papel" << endl;
    cout << "T - Tijera" << endl;
    cout << "S - Salir" << endl;
    cout << "Opcion: ";
}

// Funcion que genera la opcion de la computadora
char getComputerOption() {
    int numero = rand() % 3;

    if (numero == 0) {
        return PIEDRA;
    } else if (numero == 1) {
        return PAPEL;
    } else {
        return TIJERA;
    }
}

// Funcion que compara las opciones
string checkOptions(char usuario, char computadora) {

    if (usuario == computadora) {
        return "Empate :|";
    }

    if ((usuario == PIEDRA && computadora == TIJERA) ||
        (usuario == TIJERA && computadora == PAPEL) ||
        (usuario == PAPEL && computadora == PIEDRA)) {

        return "Gano! :)";
    }

    return "Perdio :(";
}

// Funcion que valida las opciones
bool inputOK(char opcion) {

    if (opcion == PIEDRA || opcion == PAPEL ||
        opcion == TIJERA || opcion == SALIR) {
        return true;
    }

    return false;
}

```

Esta solución mantiene toda la lógica en un único archivo `.cpp`, tal como hemos trabajado en las tareas anteriores.

## 3. Comprendamos primero cómo funciona el juego

Antes de analizar el código, debes conocer las reglas:

| Usuario elige    | Computadora elige | Resultado |
| ---------------- | ----------------- | --------- |
| Piedra           | Tijera            | Gana      |
| Tijera           | Papel             | Gana      |
| Papel            | Piedra            | Gana      |
| Piedra           | Papel             | Pierde    |
| Tijera           | Piedra            | Pierde    |
| Papel            | Tijera            | Pierde    |
| Cualquier opción | La misma opción   | Empate    |

Estas reglas son las que implementamos en la función `checkOptions()`.

## 4. Explicación detallada del código

### A. Bibliotecas utilizadas

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
```

| Biblioteca   | Para qué la utilizamos                                      |
| ------------ | ----------------------------------------------------------- |
| `<iostream>` | Mostrar información con `cout` y recibir datos con `cin`.   |
| `<string>`   | Utilizar `string` para devolver el resultado.               |
| `<cstdlib>`  | Utilizar `rand()` y `srand()`.                              |
| `<ctime>`    | Utilizar `time(0)` para inicializar los números aleatorios. |
| `<cctype>`   | Convertir letras a mayúsculas mediante `toupper()`.         |

Ya utilizaste `<cctype>` en la unidad 3, cuando trabajamos con caracteres y funciones como `isupper()`, `islower()` e `isdigit()`.

### B. Constantes globales

```cpp
const char PIEDRA = 'P';
const char PAPEL = 'A';
const char TIJERA = 'T';
const char SALIR = 'S';
```

La palabra `const` indica que el valor no puede modificarse después de inicializarse.

En vez de escribir `'P'` muchas veces, utilizamos `PIEDRA`. Esto facilita leer el código.

Además, el propio profesor recomienda estas constantes en el mandato.

### C. Los cuatro prototipos

```cpp
void displayMenu();
char getComputerOption();
string checkOptions(char, char);
bool inputOK(char);
```

Aquí tenemos cuatro funciones diferentes, cada una con su responsabilidad.

Funciones del programa

displayMenu()

Muestra el menú. No recibe argumentos ni devuelve valores.

void

getComputerOption()

Genera y devuelve P, A o T. No recibe argumentos.

char

checkOptions(char, char)

Recibe dos opciones y devuelve el resultado del juego.

string

inputOK(char)

Recibe una opción y devuelve true o false según sea válida.

bool

Esta es una de las ideas principales de la unidad 5: una función debe encargarse de una tarea concreta.

### D. ¿Por qué utilizamos `do-while`?

```cpp
do {
    displayMenu();

    cin >> opcionUsuario;

    // Resto del juego...

} while (opcionUsuario != SALIR);
```

El profesor exige un `do-while` porque necesitamos mostrar el menú al menos una vez y repetirlo mientras el usuario no decida salir.

Recuerda la diferencia:

- `while`: comprueba la condición antes de ejecutar.
- `do-while`: ejecuta primero y comprueba después.

Cuando el usuario introduce `S`, la condición deja de cumplirse y el ciclo termina.

### E. ¿Qué hace `toupper()`?

```cpp
opcionUsuario = toupper(opcionUsuario);
```

Convierte una letra minúscula en mayúscula.

Por ejemplo:

| Entrada | Después de `toupper()` |
| ------- | ---------------------- |
| `p`     | `P`                    |
| `a`     | `A`                    |
| `t`     | `T`                    |
| `s`     | `S`                    |

Esto permite comparar siempre con las constantes en mayúsculas.

### F. La validación con `inputOK()`

```cpp
bool inputOK(char opcion) {

    if (opcion == PIEDRA || opcion == PAPEL ||
        opcion == TIJERA || opcion == SALIR) {
        return true;
    }

    return false;
}
```

Esta función recibe un carácter y comprueba si pertenece a las cuatro opciones permitidas.

Si recibe `'P'`, devuelve `true`.

Si recibe `'X'`, devuelve `false`.

Ahora observa cómo la utilizamos:

```cpp
while (!inputOK(opcionUsuario)) {
    cout << "Opcion no valida. Intente de nuevo: ";
    cin >> opcionUsuario;
    opcionUsuario = toupper(opcionUsuario);
}
```

Aquí aparece el operador `!`, que significa negación lógica.

Si `inputOK()` devuelve `false`, entonces `!false` es `true`, y el `while` vuelve a pedir una opción.

El ciclo termina cuando el usuario introduce una opción válida.

### G. ¿Cómo elige la computadora?

```cpp
srand(time(0));
```

Esta instrucción se ejecuta una vez, al iniciar el programa.

`time(0)` obtiene el tiempo actual expresado en segundos y `srand()` utiliza ese número como semilla para generar una secuencia pseudoaleatoria.

Después tenemos:

```cpp
char getComputerOption() {
    int numero = rand() % 3;

    if (numero == 0) {
        return PIEDRA;
    } else if (numero == 1) {
        return PAPEL;
    } else {
        return TIJERA;
    }
}
```

La expresión:

```cpp
rand() % 3
```

produce un resto de 0, 1 o 2.

Utilizamos esos tres posibles resultados para seleccionar una opción.

Simulador de la elección de la computadora

✊Piedranumero = 0

✋Papelnumero = 1

✌️Tijeranumero = 2

Si `rand() % 3` devuelve 0:

## return PIEDRA;

Selecciona cualquier valor para observar qué camino sigue la función. Esta demostración no utiliza el generador de C++.

Importante: `rand()` genera números pseudoaleatorios, no verdaderamente aleatorios. Para este ejercicio, utilizamos exactamente las funciones que pidió el profesor.

### H. La función más importante: `checkOptions()`

```cpp
string checkOptions(char usuario, char computadora) {

    if (usuario == computadora) {
        return "Empate :|";
    }

    if ((usuario == PIEDRA && computadora == TIJERA) ||
        (usuario == TIJERA && computadora == PAPEL) ||
        (usuario == PAPEL && computadora == PIEDRA)) {

        return "Gano! :)";
    }

    return "Perdio :(";
}
```

Aquí combinamos dos operadores que ya has estudiado:

- `&&` significa Y. Las dos condiciones deben cumplirse.
- `||` significa O. Basta con que se cumpla una de las condiciones.

Por ejemplo:

```cpp
usuario == PIEDRA && computadora == TIJERA
```

Significa que el usuario eligió Piedra y la computadora eligió Tijera. Por lo tanto, el usuario gana.

Las otras dos condiciones contemplan las demás formas de ganar.

Si ninguno de los casos de victoria o empate se cumple, la función devuelve `"Perdio :("`.

Observa que cada `return` termina la función y devuelve un `string` a `main()`.

## 5. Cómo se conectan las funciones

`main()`

`displayMenu()` — muestra opciones

`inputOK()` — valida entrada

¿El usuario eligió salir?

Sí

Termina

No

`getComputerOption()`

`checkOptions()`

Muestra resultado y repite

Aquí está la lógica que debemos dominar: `main()` coordina todo el programa y llama a las funciones cuando necesita realizar cada tarea.

## 6. Ejemplo de ejecución

Como la computadora elige aleatoriamente, el resultado puede cambiar en cada partida.

```
===== PIEDRA, PAPEL O TIJERA =====
P - Piedra
A - Papel
T - Tijera
S - Salir
Opcion: p

Usted eligio: Piedra
La computadora eligio: Tijera
Resultado: Gano! :)

===== PIEDRA, PAPEL O TIJERA =====
P - Piedra
A - Papel
T - Tijera
S - Salir
Opcion: x

Opcion no valida. Intente de nuevo: t

Usted eligio: Tijera
La computadora eligio: Piedra
Resultado: Perdio :(

===== PIEDRA, PAPEL O TIJERA =====
P - Piedra
A - Papel
T - Tijera
S - Salir
Opcion: s

Gracias por jugar.
```

## 7. Cómo compilar y guardar en GitHub

En tu Mac:

```cpp
clang++ -std=c++17 tarea2.cpp -o tarea2
./tarea2
```

Como el ejecutable de Mac no tiene necesariamente una extensión, recuerda nuestra conversación sobre `.gitignore`: sube a GitHub el archivo `tarea2.cpp`, no el programa compilado.

Para entregar al profesor, el mandato solicita el código fuente `.cpp` y una captura de pantalla de la ejecución dentro de un ZIP o RAR.

## 8. Qué debes estudiar de esta tarea

Esta segunda tarea refuerza casi todo lo que hemos visto hasta ahora:

\| Concepto | Dónde aparece | |---|---| | Variables | `opcionUsuario`, `resultado`, etc. | | Constantes | `PIEDRA`, `PAPEL`, `TIJERA`, `SALIR` | | Condicionales | `if`, `else if`, `else` | | Operadores lógicos | `&&`, `||`, `!` | | Ciclo `do-while` | Mantener activo el juego | | Ciclo `while` | Validar la entrada | | Funciones `void` | Mostrar el menú | | Funciones `char` | Devolver una jugada | | Funciones `string` | Devolver el resultado | | Funciones `bool` | Comprobar una entrada | | Números pseudoaleatorios | `rand()`, `srand()` |

Hay una mejora posible que no forma parte de esta versión: controlar que el usuario introduzca exactamente un carácter y manejar errores de `cin`. Por ahora, como el ejercicio está centrado en funciones y el profesor pide validar caracteres permitidos, mantenemos la solución sencilla.

Con esto tenemos la tarea 2 desarrollada y explicada. Cuando me digas «Dame la 3», seguiremos con la calculadora mediante argumentos de línea de comandos. Esa tarea introduce una forma diferente de pasar información al programa y será útil para entender programas que se ejecutan desde la terminal.