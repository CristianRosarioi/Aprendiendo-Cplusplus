# Guía Básica de C++ para Principiantes

Guía de estudio con todo lo fundamental que debes saber para aprender **C++ desde cero**.
Pensada para complementar las notas, ejemplos y ejercicios de este repositorio.

---

## 1. ¿Qué es C++?

- **C++** es un lenguaje de programación de **alto rendimiento** y uso generalizado, creado por Bjarne Stroustrup en 1985.
- Es una extensión de **C** y te permite programar tanto a **bajo nivel** (cercano al hardware) como a **alto nivel** (con clases y objetos).
- Se usa en videojuegos, sistemas operativos, motores gráficos, aplicaciones de escritorio, etc.
- Es de **tipado estático** y **compilado**: el código se traduce a un ejecutable antes de ejecutarse.

---

## 2. Estructura mínima de un programa

Todo programa en C++ necesita:

```cpp
#include <iostream>   // Biblioteca para entrada/salida (cin / cout)
using namespace std;  // Para usar cout, cin, endl sin escribir std::

int main() {          // Punto de entrada del programa
    // Tu código aquí
    return 0;         // 0 = programa finalizó con éxito
}
```

> Nota: `using namespace std;` es cómodo para aprender, pero en proyectos grandes se recomienda usar `std::cout`, `std::cin`, etc.

### Comentarios

```cpp
// Comentario de una línea

/*
  Comentario
  de varias
  líneas
*/
```

Los comentarios no se ejecutan: sirven para explicar tu código.

---

## 3. Cómo compilar y ejecutar

C++ necesita un **compilador**. En macOS puedes instalar y usar `g++` (Xcode Command Line Tools).

```bash
# Compilar (crea el ejecutable)
g++ programa.cpp -o programa

# Compilar con un estándar reciente (recomendado)
g++ -std=c++17 programa.cpp -o programa

# Ejecutar
./programa
```

Para probar sin instalar nada: https://www.onlinegdb.com/ o https://wandbox.org/

---

## 4. Tipos de datos básicos

| Tipo     | Tamaño (típico) | Qué guarda                                   | Ejemplo                          |
|----------|-----------------|----------------------------------------------|----------------------------------|
| `bool`   | 1 byte          | `true` / `false`                             | `bool esEstudiante = true;`      |
| `char`   | 1 byte          | Un solo carácter o código ASCII              | `char letra = 'A';`              |
| `int`    | 4 bytes         | Números enteros                              | `int edad = 20;`                 |
| `float`  | 4 bytes         | Decimales (6-7 dígitos de precisión)         | `float promedio = 8.5f;`         |
| `double` | 8 bytes         | Decimales (15 dígitos de precisión, más exacto) | `double pi = 3.1415926535;`  |
| `string` | variable       | Cadenas de texto (necesita `#include <string>`) | `string nombre = "Ana";`    |

### Declarar y asignar variables

```cpp
string nombre;               // Declarar
nombre = "Luis";             // Asignar

int edad = 20;               // Declarar + asignar en la misma línea

const float IVA = 0.18;      // const = valor que NO puede cambiar
```

---

## 5. Entrada y salida de datos

- `cout` → mostrar (imprimir) en la consola.
- `cin` → leer lo que el usuario escribe.
- `endl` → salto de línea (como presionar Enter).

```cpp
#include <iostream>
using namespace std;

int main() {
    string nombre;
    int edad;

    cout << "Escribe tu nombre: ";
    cin >> nombre;

    cout << "Escribe tu edad: ";
    cin >> edad;

    cout << "Hola " << nombre << ", tendrás " << edad + 5 << " años en 5 años." << endl;

    return 0;
}
```

> Usa `\n` como alternativa ligera a `endl`: `cout << "Hola\n";`

### Problema común: el "Enter" que se queda pendiente

`cin` deja el salto de línea (Enter) en el buffer. Si después usas `getline`, lo mejor es limpiar el buffer:

```cpp
#include <iostream>
using namespace std;

int main() {
    string nombre, linea;
    int edad;

    cout << "Edad: ";
    cin >> edad;
    cin.ignore();            // Limpia el Enter que quedó pendiente

    cout << "Nombre completo: ";
    getline(cin, nombre);    // getline permite espacios ("Ana García")

    cout << "Hola " << nombre << " (" << edad << ")" << endl;
    return 0;
}
```

---

## 6. Operadores

### Aritméticos

| Operador | Operación | Ejemplo          |
|----------|-----------|------------------|
| `+`      | Suma      | `a + b`          |
| `-`      | Resta     | `a - b`          |
| `*`      | Producto  | `a * b`          |
| `/`      | División  | `a / b`          |
| `%`      | Módulo (residuo) | `a % b`     |

> Cuidado: si divides dos `int`, obtienes un `int` (se trunca). Ej: `7 / 2 == 3`. Para obtener decimales usa `double`.

### Comparación

| Operador | Significado          |
|----------|----------------------|
| `==`     | Igual a             |
| `!=`     | Diferente de        |
| `>`      | Mayor que           |
| `<`      | Menor que           |
| `>=`     | Mayor o igual       |
| `<=`     | Menor o igual       |

### Lógicos

| Operador | Significado |
|----------|-------------|
| `&&`     | AND (y)     |
| `\|\|`   | OR (o)      |
| `!`      | NOT (no)    |

### Asignación abreviada

```cpp
edad  += 1;    // edad = edad + 1
total -= 5;    // total = total - 5
total *= 2;    // total = total * 2
edad  += 1;    // igual que: edad++
edad  -= 1;    // igual que: edad--
```

---

## 7. Condicionales

### if / else if / else

```cpp
int nota;
cout << "Ingresa tu nota (0-100): ";
cin >> nota;

if (nota >= 60) {
    cout << "Aprobado" << endl;
} else if (nota >= 50) {
    cout << "Cerca, casi apruebas" << endl;
} else {
    cout << "Reprobado" << endl;
}
```

### switch

Útil cuando comparas una variable contra varios **valores exactos**:

```cpp
int opcion;
cout << "1. Ver notas  2. Ver horario  3. Salir" << endl;
cin >> opcion;

switch (opcion) {
    case 1:
        cout << "Mostrando notas..." << endl;
        break;                    // "break" corta el switch
    case 2:
        cout << "Mostrando horario..." << endl;
        break;
    case 3:
        cout << "Saliendo..." << endl;
        break;
    default:
        cout << "Opción inválida" << endl;
}
```

### Operador ternario (if corto)

```cpp
string resultado = (nota >= 60) ? "Aprobado" : "Reprobado";
```

---

## 8. Bucles (repeticiones)

### while — repite mientras la condición sea verdadera

```cpp
int contador = 1;
while (contador <= 5) {
    cout << "Contador: " << contador << endl;
    contador++;        // ¡NO olvidar! evita un bucle infinito
}
```

### do-while — ejecuta al menos una vez

```cpp
int num;
do {
    cout << "Adivina el número (1-10): ";
    cin >> num;
} while (num != 7);
```

### for — repite un número fijo de veces

```cpp
for (int i = 0; i < 5; i++) {
    cout << "Vuelta " << i << endl;
}
```

### break y continue

```cpp
// break: sale del bucle por completo
for (int i = 0; i < 10; i++) {
    if (i == 5) break;        // se detiene en 5
}

// continue: salta a la siguiente vuelta
for (int i = 0; i < 10; i++) {
    if (i == 5) continue;     // se salta el 5, pero sigue
    cout << i << endl;
}
```

---

## 9. Funciones

Permiten organizar y reutilizar código.

```cpp
#include <iostream>
using namespace std;

// Definición de la función (retorna un double, recibe dos doubles)
double promedio(double a, double b) {
    return (a + b) / 2;
}

// Función que no retorna nada
void saludar(string nombre) {
    cout << "Hola " << nombre << endl;
}

int main() {
    saludar("Cristian");                    // void: no retorna valor
    double prom = promedio(8.5, 9.0);       // guardamos el retorno
    cout << "Promedio: " << prom << endl;
    return 0;
}
```

Conceptos clave:
- **Parámetros**: los valores que recibe la función.
- **Retorno**: valor que devuelve con `return`. Si no devuelve nada, usa `void`.
- **Llamada**: usar la función desde `main` u otra función.

---

## 10. Arreglos (arrays)

Colección de valores del **mismo tipo** en una sola variable.

```cpp
// Declarar con tamaño fijo
int notas[3];

// Asignar por índice (empieza en 0)
notas[0] = 8;
notas[1] = 9;
notas[2] = 7;

// O declarar e inicializar directamente
int otros[3] = {8, 9, 7};

// Recorrer con un bucle
for (int i = 0; i < 3; i++) {
    cout << "Nota " << i << ": " << notas[i] << endl;
}
```

> Los índices van de **0 a tamaño-1**. `notas[3]` daría error (fuera de rango).

---

## 11. Cadenas de texto (string)

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre = "Cristian";
    string apellido = "Rosario";

    cout << "Largo del nombre: " << nombre.length() << endl;   // cantidad de caracteres
    cout << "Primera letra: " << nombre[0] << endl;           // índice 0
    cout << "Concatenación: " << nombre + " " + apellido << endl;

    // Comparar
    if (nombre == "Cristian") {
        cout << "Es Cristian" << endl;
    }
    return 0;
}
```

Métodos útiles: `.length()`, `.append(...)`, `.find(...)`, `.substr(...)`, `.empty()`.

---

## 12. Punteros básicos (introducción)

Un puntero guarda la **dirección de memoria** de otra variable.

```cpp
int edad = 20;
int* ptr = &edad;        // & = dirección de memoria de edad
                         // * = valor que está en esa dirección

cout << &edad << endl;   // dirección de memoria (ej: 0x16...)
cout << ptr  << endl;    // misma dirección
cout << *ptr << endl;    // 20 (el valor apuntado, se llama "desreferenciar")
```

No te desesperes con los punteros ahora: **domina el resto primero** y regresa aquí. Solo ten claro que `&` obtiene dirección y `*` obtiene/apunta al valor.

---

## 13. Buenas prácticas desde el inicio

1. **Compila seguido**: no escribas 200 líneas sin probar. Compila tras cada cambio pequeño.
2. **Nombres claros**: `promedio`, `edad`, `nombre` en vez de `p`, `e`, `n`.
3. **Declara una variable con su propósito**: `const float IVA = 0.18;` si no cambiará.
4. **Usa `return 0;`** al final de `main`.
5. **Inicializa tus variables**: `int total = 0;` en vez de dejar solo `int total;`.
6. **Lee los errores del compilador**: te dicen la línea y el problema la mayoría de las veces.
7. **Sé consistente con la indentación** (espacios o tabulación, pero siempre igual).
8. **Orden lógico**: luego entra a funciones, luego a **Programación Orientada a Objetos** (clases).

---

## 14. Orden recomendado de estudio

1. Sintaxis y estructura mínima (✅ ya visto)
2. Variables y tipos de datos (✅ ya visto en `Fundamentos/`)
3. Entrada/salida con `cin`/`cout` (✅ ya practicado en `UNIDAD_1`)
4. Operadores y expresiones
5. Condicionales (`if`, `else`, `switch`)
6. Bucles (`for`, `while`, `do-while`)
7. Funciones
8. Arreglos
9. `string`
10. Estructuras (`struct`)
11. Punteros y referencias
12. Programación Orientada a Objetos (clases, herencia, polimorfismo)
13. Manejo de archivos y memoria dinámica (posterior)

---

## 15. Recursos útiles

- **Documentación y tutoriales**: https://www.w3schools.com/cpp/
- **Referencia del lenguaje**: https://cplusplus.com/reference/
- **Compilador en línea**: https://www.onlinegdb.com/
- **Libro clásico (en español)**: *C++ Paso a Paso* o *El Lenguaje de Programación C++* de Bjarne Stroustrup (avanzado).

---

*Este archivo es material de apoyo: complementa los ejemplos de `UNIDAD_1_-_Ejemplos/` y los retos de `Ejercicios1.0/`.*