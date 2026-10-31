# Guía de estudio — Funciones en C++ (Unidad V)

Vamos a trabajar con 10 programas independientes, organizados desde lo más sencillo hasta ejemplos que combinan funciones con ciclos, validaciones, vectores y estructuras.

Todos utilizan conceptos que hemos estudiado en la UASD. No vamos a introducir clases, programación orientada a objetos, lambdas ni técnicas avanzadas.

Te recomiendo guardar la explicación como `README.md` y cada programa en un archivo `.cpp` separado.

## 1. ¿Qué es una función?

Una función es un bloque de instrucciones que realiza una tarea específica. Podemos ejecutarlo desde otra parte del programa llamándolo por su nombre.

Por ejemplo, si necesitamos sumar dos números varias veces, podemos crear una función `sumar()` en vez de escribir la misma operación repetidamente.

### Estructura de una función

```cpp
tipoDeRetorno nombreFuncion(parametros) {
    // Instrucciones de la funcion

    return resultado;
}
```

Cada parte tiene un significado:

| Elemento        | Significado                                                        |
| --------------- | ------------------------------------------------------------------ |
| `tipoDeRetorno` | Tipo de dato que devuelve: `int`, `double`, `string`, `bool`, etc. |
| `nombreFuncion` | Nombre que utilizaremos para llamarla.                             |
| `parametros`    | Variables que reciben información.                                 |
| `{ }`           | Delimitan el cuerpo de la función.                                 |
| `return`        | Devuelve un valor y termina la ejecución de esa función.           |

Si la función no devuelve ningún valor, utilizamos `void`.

## 2. Parámetros y argumentos

Observa:

```cpp
int sumar(int a, int b) {
    return a + b;
}
```

Aquí, `a` y `b` son parámetros.

Cuando llamamos:

```cpp
int resultado = sumar(10, 5);
```

Los valores `10` y `5` son argumentos.

El programa envía esos valores a la función, que realiza el cálculo y devuelve `15`.

## 3. Diferencia entre `void`, `cout` y `return`

Este concepto es especialmente importante porque acabamos de estudiarlo con el ejercicio de la edad.

Una función que muestra información:

```cpp
void saludar() {
    cout << "Hola estudiante" << endl;
}
```

La ejecutamos así:

```cpp
saludar();
```

Una función que devuelve un resultado:

```cpp
int duplicar(int numero) {
    return numero * 2;
}
```

La utilizamos así:

```cpp
cout << duplicar(5) << endl;
```

La primera imprime directamente. La segunda devuelve `10`, y es `cout` quien muestra ese valor.

Regla fundamental: `cout` muestra información; `return` devuelve información a quien llamó la función.

## 4. Prototipos, definiciones y llamadas

Una función tiene tres elementos que debes distinguir:

```cpp
// Prototipo
int sumar(int, int);

int main() {
    // Llamada
    cout << sumar(5, 3);
    return 0;
}

// Definicion
int sumar(int a, int b) {
    return a + b;
}
```

El prototipo anuncia que existe la función. La definición contiene lo que hará y la llamada ejecuta esa función.

Podemos colocar la definición antes de `main()` y evitar el prototipo separado, pero quiero que practiques ambas formas porque aparecen en el material de la unidad.

# 10 ejemplos prácticos de funciones

Cada ejemplo tiene su propio `main()`. No debes pegar los diez programas en un único archivo `.cpp`, porque un programa no puede tener diez funciones principales `main()`.

## Ejemplo 1 — Función sin parámetros y sin retorno

Archivo: `01_saludar.cpp`

```cpp
#include <iostream>
using namespace std;

// Definicion de la funcion
void saludar() {
    cout << "Bienvenido al programa de C++" << endl;
}

int main() {
    saludar();

    return 0;
}
```

Explicación:

- `void` significa que la función no devuelve ningún valor.
- `saludar()` no recibe parámetros porque sus paréntesis están vacíos.
- Dentro de la función utilizamos `cout` para mostrar un mensaje.
- `main()` ejecuta `saludar()` mediante una llamada.

Resultado:

```cpp
Bienvenido al programa de C++
```

Es el ejemplo más sencillo de reutilización de código. Si llamamos `saludar()` tres veces, el mensaje aparecerá tres veces.

## Ejemplo 2 — Función con parámetros y sin retorno

Archivo: `02_mostrar_edad.cpp`

```cpp
#include <iostream>
using namespace std;

void mostrarEdad(int edad) {
    cout << "Su edad es: " << edad << endl;
}

int main() {
    int edadUsuario;

    cout << "Introduzca su edad: ";
    cin >> edadUsuario;

    mostrarEdad(edadUsuario);

    return 0;
}
```

Explicación:

Ahora la función recibe información.

```cpp
void mostrarEdad(int edad)
```

- `void`: no devuelve un valor.
- `int edad`: es el parámetro que recibe un número entero.
- `mostrarEdad(edadUsuario)`: es la llamada que envía la edad introducida.

Si el usuario introduce 22, el valor 22 se copia al parámetro `edad` y la función lo muestra.

Resultado:

```cpp
Introduzca su edad: 22
Su edad es: 22
```

Lo que debes aprender: una función puede recibir datos sin necesidad de devolverlos.

## Ejemplo 3 — Función con parámetros y retorno `int`

Archivo: `03_sumar.cpp`

```cpp
#include <iostream>
using namespace std;

int sumar(int a, int b) {
    int resultado;

    resultado = a + b;

    return resultado;
}

int main() {
    int numero1, numero2;
    int total;

    cout << "Primer numero: ";
    cin >> numero1;

    cout << "Segundo numero: ";
    cin >> numero2;

    total = sumar(numero1, numero2);

    cout << "La suma es: " << total << endl;

    return 0;
}
```

Explicación:

Esta función recibe dos números enteros, los suma y devuelve el resultado.

```cpp
int sumar(int a, int b)
```

El primer `int` indica que la función devuelve un entero. Los otros dos `int` declaran los parámetros.

```cpp
return resultado;
```

Envía el valor calculado a quien llamó la función.

```cpp
total = sumar(numero1, numero2);
```

Aquí sucede lo siguiente:

1. `main()` envía los dos números.
2. `sumar()` realiza la operación.
3. `return` devuelve el resultado.
4. `total` recibe ese valor.
5. `cout` lo muestra.

Lo que debes aprender: la función calcula y `main()` decide cómo utilizar el resultado.

## Ejemplo 4 — Función con retorno `double`

Archivo: `04_calcular_promedio.cpp`

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

double calcularPromedio(double n1, double n2, double n3) {
    double promedio;

    promedio = (n1 + n2 + n3) / 3.0;

    return promedio;
}

int main() {
    double nota1, nota2, nota3;
    double promedioFinal;

    cout << "Introduzca la primera nota: ";
    cin >> nota1;

    cout << "Introduzca la segunda nota: ";
    cin >> nota2;

    cout << "Introduzca la tercera nota: ";
    cin >> nota3;

    promedioFinal = calcularPromedio(nota1, nota2, nota3);

    cout << fixed << setprecision(2);
    cout << "Promedio final: " << promedioFinal << endl;

    return 0;
}
```

Explicación:

Este ejemplo es parecido al anterior, pero ahora trabajamos con números decimales.

La función:

```cpp
double calcularPromedio(double n1, double n2, double n3)
```

recibe tres notas y devuelve un `double`.

La fórmula es:

\\[ \text{Promedio}=\frac{n1+n2+n3}{3} \\]

Utilizamos `3.0` para expresar el divisor como un número decimal.

`fixed` y `setprecision(2)` permiten mostrar el resultado con dos cifras decimales.

Lo que debes aprender: el tipo de retorno debe ser apropiado para el dato que queremos devolver.

## Ejemplo 5 — Función con retorno `bool` y condicionales

Archivo: `05_validar_nota.cpp`

```cpp
#include <iostream>
using namespace std;

bool notaValida(double nota) {
    if (nota >= 0 && nota <= 100) {
        return true;
    }

    return false;
}

int main() {
    double nota;

    cout << "Introduzca una nota de 0 a 100: ";
    cin >> nota;

    while (!notaValida(nota)) {
        cout << "Nota invalida. Intente otra vez: ";
        cin >> nota;
    }

    cout << "La nota introducida es valida." << endl;

    return 0;
}
```

Explicación:

`bool` es un tipo de dato que puede contener `true` o `false`.

La función:

```cpp
bool notaValida(double nota)
```

recibe una nota y comprueba si se encuentra entre 0 y 100.

El operador `&&` significa Y: ambas condiciones deben cumplirse.

En `main()` utilizamos:

```cpp
while (!notaValida(nota))
```

El operador `!` significa negación lógica.

Si `notaValida()` devuelve `false`, `!false` se convierte en `true` y el ciclo vuelve a solicitar la nota.

Cuando la nota es válida, termina el ciclo.

Lo que debes aprender: las funciones `bool` son muy útiles para validar información y controlar condiciones.

## Ejemplo 6 — Función con un ciclo `for`

Archivo: `06_tabla_multiplicar.cpp`

```cpp
#include <iostream>
using namespace std;

void mostrarTabla(int numero) {
    for (int i = 1; i <= 12; i++) {
        cout << numero << " x " << i
             << " = " << numero * i << endl;
    }
}

int main() {
    int numero;

    cout << "Introduzca un numero: ";
    cin >> numero;

    mostrarTabla(numero);

    return 0;
}
```

Explicación:

La función recibe un número y muestra su tabla de multiplicar del 1 al 12.

Aquí combinamos una función `void` con un ciclo `for`.

```cpp
for (int i = 1; i <= 12; i++)
```

- `i = 1`: comienza en 1.
- `i <= 12`: continúa hasta 12.
- `i++`: aumenta el contador después de cada vuelta.

En cada iteración se multiplica el número recibido por el valor actual de `i`.

Lo que debes aprender: los ciclos también se pueden utilizar dentro de las funciones. Una función puede contener condiciones, variables y otros bloques de código, igual que `main()`.

## Ejemplo 7 — Función que recibe un vector

Archivo: `07_vector_notas.cpp`

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Prototipo
double calcularPromedio(vector<double> notas);

int main() {
    vector<double> notas(5);

    double promedio;

    for (unsigned int i = 0; i < notas.size(); i++) {
        cout << "Introduzca la nota " << i + 1 << ": ";
        cin >> notas.at(i);
    }

    promedio = calcularPromedio(notas);

    cout << "El promedio es: " << promedio << endl;

    return 0;
}

// Definicion de la funcion
double calcularPromedio(vector<double> notas) {
    double suma = 0;

    for (unsigned int i = 0; i < notas.size(); i++) {
        suma += notas.at(i);
    }

    return suma / notas.size();
}
```

Explicación:

Este ejemplo combina lo aprendido en la unidad IV con las funciones de la unidad V.

Primero creamos un vector de cinco notas:

```cpp
vector<double> notas(5);
```

Después, un `for` solicita las notas y las almacena utilizando `at()`.

La función recibe el vector completo:

```cpp
double calcularPromedio(vector<double> notas)
```

Dentro utilizamos un acumulador:

```cpp
suma += notas.at(i);
```

Esto suma las cinco notas una por una.

Finalmente:

```cpp
return suma / notas.size();
```

Dividimos la suma entre la cantidad de elementos y devolvemos el promedio.

Importante: este ejemplo pasa el vector por valor, es decir, realiza una copia. Más adelante podemos aprender a pasarlo por referencia para evitar esa copia.

Lo que debes aprender: una función puede recibir colecciones de datos y recorrerlas con ciclos.

## Ejemplo 8 — Función que recibe una estructura `struct`

Archivo: `08_estructura_estudiante.cpp`

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    double nota;
};

// Prototipo
void mostrarEstudiante(Estudiante alumno);

int main() {
    Estudiante estudiante1;

    cout << "Nombre: ";
    getline(cin, estudiante1.nombre);

    cout << "Edad: ";
    cin >> estudiante1.edad;

    cout << "Nota: ";
    cin >> estudiante1.nota;

    mostrarEstudiante(estudiante1);

    return 0;
}

// Definicion
void mostrarEstudiante(Estudiante alumno) {
    cout << "\nDATOS DEL ESTUDIANTE" << endl;

    cout << "Nombre: " << alumno.nombre << endl;
    cout << "Edad: " << alumno.edad << endl;
    cout << "Nota: " << alumno.nota << endl;
}
```

Explicación:

Primero definimos una estructura:

```cpp
struct Estudiante {
    string nombre;
    int edad;
    double nota;
};
```

Después creamos una variable de ese tipo:

```cpp
Estudiante estudiante1;
```

Los datos se introducen desde `main()`.

La función:

```cpp
void mostrarEstudiante(Estudiante alumno)
```

recibe una copia de la estructura completa.

Por eso podemos acceder a:

```cpp
alumno.nombre
alumno.edad
alumno.nota
```

Mediante el operador punto `.`.

Lo que debes aprender: no solamente podemos enviar números a las funciones. También podemos enviar estructuras completas.

## Ejemplo 9 — Paso por valor y por referencia

Archivo: `09_valor_referencia.cpp`

```cpp
#include <iostream>
using namespace std;

// Prototipos
void cambiarPorValor(int numero);
void cambiarPorReferencia(int &numero);

int main() {
    int edad = 20;

    cout << "Edad inicial: " << edad << endl;

    cambiarPorValor(edad);

    cout << "Despues de pasar por valor: "
         << edad << endl;

    cambiarPorReferencia(edad);

    cout << "Despues de pasar por referencia: "
         << edad << endl;

    return 0;
}

// Paso por valor
void cambiarPorValor(int numero) {
    numero = 30;
}

// Paso por referencia
void cambiarPorReferencia(int &numero) {
    numero = 40;
}
```

Resultado:

```cpp
Edad inicial: 20
Despues de pasar por valor: 20
Despues de pasar por referencia: 40
```

### Explicación

Este ejemplo es especialmente importante.

Tenemos dos funciones:

```cpp
void cambiarPorValor(int numero)
```

Y:

```cpp
void cambiarPorReferencia(int &numero)
```

La primera recibe una copia de la variable.

Aunque dentro escribimos:

```cpp
numero = 30;
```

La variable original `edad` sigue valiendo 20.

En cambio, la segunda función utiliza:

```cpp
int &numero
```

El símbolo `&` indica que el parámetro es una referencia a la variable original.

Por eso, al ejecutar:

```cpp
numero = 40;
```

Se modifica directamente `edad`.

| Paso por valor                                          | Paso por referencia          |
| ------------------------------------------------------- | ---------------------------- |
| Recibe una copia                                        | Utiliza la variable original |
| No modifica el argumento original mediante el parámetro | Puede modificarlo            |
| No utiliza `&`                                          | Utiliza `&`                  |

Lo que debes aprender: una función puede recibir información para consultarla o recibir una referencia para modificar directamente la variable original.

## Ejemplo 10 — Programa completo con varias funciones

Archivo: `10_calculadora_funciones.cpp`

En este último ejemplo combinaremos funciones, parámetros, `return`, `switch`, `do-while` y validaciones.

```cpp
#include <iostream>
using namespace std;

// Prototipos
void mostrarMenu();

double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);

int main() {
    int opcion;

    double numero1;
    double numero2;
    double resultado;

    do {
        mostrarMenu();

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        while (opcion < 0 || opcion > 4) {
            cout << "Opcion invalida: ";
            cin >> opcion;
        }

        if (opcion != 0) {

            cout << "Introduzca el primer numero: ";
            cin >> numero1;

            cout << "Introduzca el segundo numero: ";
            cin >> numero2;

            switch (opcion) {

                case 1:
                    resultado = sumar(numero1, numero2);
                    break;

                case 2:
                    resultado = restar(numero1, numero2);
                    break;

                case 3:
                    resultado = multiplicar(numero1, numero2);
                    break;

                case 4:
                    while (numero2 == 0) {
                        cout << "No se puede dividir entre cero."
                             << endl;

                        cout << "Introduzca otro divisor: ";
                        cin >> numero2;
                    }

                    resultado = dividir(numero1, numero2);
                    break;
            }

            cout << "Resultado: " << resultado << endl;
        }

    } while (opcion != 0);

    cout << "Programa finalizado." << endl;

    return 0;
}

// Funcion que muestra el menu
void mostrarMenu() {
    cout << "\nCALCULADORA" << endl;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "4. Dividir" << endl;
    cout << "0. Salir" << endl;
}

// Funcion para sumar
double sumar(double a, double b) {
    return a + b;
}

// Funcion para restar
double restar(double a, double b) {
    return a - b;
}

// Funcion para multiplicar
double multiplicar(double a, double b) {
    return a * b;
}

// Funcion para dividir
double dividir(double a, double b) {
    return a / b;
}
```

### Explicación

Este programa utiliza cinco funciones propias:

| Función         | Tipo     | Responsabilidad      |
| --------------- | -------- | -------------------- |
| `mostrarMenu()` | `void`   | Mostrar las opciones |
| `sumar()`       | `double` | Devolver la suma     |
| `restar()`      | `double` | Devolver la resta    |
| `multiplicar()` | `double` | Devolver el producto |
| `dividir()`     | `double` | Devolver el cociente |

### ¿Cómo funciona?

Primero, `main()` ejecuta:

```cpp
mostrarMenu();
```

La función imprime las opciones de la calculadora.

Después el usuario selecciona una operación y escribe dos números.

El `switch` determina cuál función ejecutar.

Por ejemplo:

```cpp
case 1:
    resultado = sumar(numero1, numero2);
    break;
```

Si seleccionamos la opción 1, llamamos a `sumar()` y guardamos el valor que devuelve.

Para dividir, primero comprobamos que el divisor no sea cero:

```cpp
while (numero2 == 0)
```

Si es cero, solicitamos otro número.

Finalmente:

```cpp
cout << "Resultado: " << resultado << endl;
```

Muestra el resultado devuelto por la función correspondiente.

El ciclo `do-while` mantiene funcionando la calculadora hasta que el usuario introduce cero.

Lo que debes aprender: las funciones ayudan a separar las responsabilidades del programa. `main()` coordina el trabajo y cada función realiza una tarea específica.

# 5. Resumen de los 10 ejemplos

| N.º | Archivo                        | Concepto principal            |
| --- | ------------------------------ | ----------------------------- |
| 1   | `01_saludar.cpp`               | Función `void` sin parámetros |
| 2   | `02_mostrar_edad.cpp`          | Función con parámetro         |
| 3   | `03_sumar.cpp`                 | Retorno `int`                 |
| 4   | `04_calcular_promedio.cpp`     | Retorno `double`              |
| 5   | `05_validar_nota.cpp`          | Retorno `bool`                |
| 6   | `06_tabla_multiplicar.cpp`     | Función con ciclo `for`       |
| 7   | `07_vector_notas.cpp`          | Función con `vector`          |
| 8   | `08_estructura_estudiante.cpp` | Función con `struct`          |
| 9   | `09_valor_referencia.cpp`      | Paso por valor y referencia   |
| 10  | `10_calculadora_funciones.cpp` | Programa con varias funciones |

## 6. Cómo organizarlos en VS Code y GitHub

Te recomiendo esta estructura dentro de tu repositorio `Aprendiendo-Cplusplus`:

```cpp
Universidad/
└── Brito_Profesor/
    └── Practicas_Unidad5/
        ├── README.md
        ├── 01_saludar.cpp
        ├── 02_mostrar_edad.cpp
        ├── 03_sumar.cpp
        ├── 04_calcular_promedio.cpp
        ├── 05_validar_nota.cpp
        ├── 06_tabla_multiplicar.cpp
        ├── 07_vector_notas.cpp
        ├── 08_estructura_estudiante.cpp
        ├── 09_valor_referencia.cpp
        └── 10_calculadora_funciones.cpp
```

En `README.md` puedes guardar esta explicación y los ejemplos. Los programas también estarán individualmente en sus archivos `.cpp`.

### Cómo compilar

En tu Mac puedes compilar cualquier ejemplo usando:

```cpp
clang++ -std=c++17 03_sumar.cpp -o ejemplo
./ejemplo
```

Solamente cambia `03_sumar.cpp` por el archivo que quieras practicar. El ejecutable `ejemplo` lo puedes guardar en una carpeta `bin/` que esté incluida en tu `.gitignore`.

Estos programas suponen que introduces valores del tipo solicitado, por ejemplo números donde se espera un número. No incluyen todavía una recuperación completa ante errores de `cin`.

# 7. Cómo estudiar funciones correctamente

Quiero que practiques estos diez ejemplos en orden. No basta con copiarlos y ejecutarlos: debes poder modificarlos.

Te recomiendo estas pruebas:

1. En el ejemplo 1, llama a `saludar()` tres veces.
2. En el ejemplo 2, agrega un segundo parámetro para recibir el nombre del estudiante.
3. En el ejemplo 3, modifica la función para que multiplique dos números.
4. En el ejemplo 4, calcula el promedio de cuatro notas.
5. En el ejemplo 5, crea otra función que determine si una nota está aprobada, usando el criterio que indique tu profesor.
6. En el ejemplo 6, modifica la tabla para que llegue hasta 20.
7. En el ejemplo 7, cambia el programa para encontrar la nota mayor.
8. En el ejemplo 8, agrega el campo `matricula` a la estructura.
9. En el ejemplo 9, prueba qué sucede al pasar una variable diferente por referencia.
10. En el ejemplo 10, agrega una función para calcular la potencia mediante un ciclo `for`, sin utilizar `pow()`.

## 8. Conceptos que debes dominar

Al finalizar estos ejemplos deberías poder contestar lo siguiente:

- ¿Qué es una función y para qué se utiliza?
- ¿Qué diferencia existe entre `void`, `int`, `double` y `bool` como tipos de retorno?
- ¿Qué diferencia hay entre parámetros y argumentos?
- ¿Para qué utilizamos `return`?
- ¿Cuál es la diferencia entre `return` y `cout`?
- ¿Qué es un prototipo?
- ¿Qué diferencia hay entre declarar, definir y llamar una función?
- ¿Cómo se envía una variable a una función?
- ¿Qué diferencia hay entre paso por valor y paso por referencia?
- ¿Cómo enviamos un vector o una estructura a una función?
- ¿Cómo podemos combinar varias funciones dentro de un mismo programa?

Una regla que quiero que recuerdes: primero identifica qué tarea debe realizar una función, qué datos necesita recibir y qué resultado debe devolver. Cuando tengas claras esas tres cosas, escribir la función será mucho más sencillo.

Estos diez ejercicios te dan una base para comenzar a trabajar la unidad 5 y, sobre todo, para comprender cómo se comunican las funciones entre sí dentro de un programa C++.