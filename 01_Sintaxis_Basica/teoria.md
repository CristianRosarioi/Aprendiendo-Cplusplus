# 01 - Sintaxis Basica

Fundamentos de todo programa en C++: estructura, tipos de datos, variables, entrada y salida.

## Estructura minima

```cpp
#include <iostream>   // biblioteca de entrada/salida (cin, cout)
using namespace std;  // permite usar cout/cin sin escribir std::

int main() {          // punto de entrada del programa
    // tu codigo aqui
    return 0;         // 0 = finalizo con exito
}
```

## Comentarios

- `// comentario de una linea`
- `/* comentario de varias lineas */`

## Tipos de datos basicos

| Tipo   | Tamaño (tipico) | Que guarda                                 | Ejemplo                       |
|--------|-----------------|--------------------------------------------|-------------------------------|
| bool   | 1 byte          | true / false                               | `bool activo = true;`         |
| char   | 1 byte          | un caracter o codigo ASCII                 | `char letra = 'A';`           |
| int    | 4 bytes         | numeros enteros                            | `int edad = 20;`              |
| float  | 4 bytes         | decimales (6-7 digitos)                    | `float nota = 8.5f;`          |
| double | 8 bytes         | decimales (15 digitos, mas exacto)         | `double pi = 3.14159;`        |
| string | variable       | texto (requiere `#include <string>`)       | `string nombre = "Ana";`      |

## Variables y constantes

```cpp
string nombre;              // declarar
nombre = "Luis";            // asignar

int edad = 20;              // declarar + asignar

const float IVA = 0.18;     // const = valor que NO puede cambiar
```

## Entrada y salida

- `cout <<` imprime en consola.
- `cin >>` lee lo que el usuario escribe.
- `endl` salto de linea (o `"\n"`).

```cpp
string nombre;
int edad;

cout << "Escribe tu nombre: ";
cin >> nombre;

cout << "Escribe tu edad: ";
cin >> edad;

cout << "Hola " << nombre << ", tendras " << edad + 5 << " anos en 5 anos" << endl;
```

## Problema del "Enter" pendiente

`cin` deja el Enter en el buffer. Si luego usas `getline`, limpia el buffer con `cin.ignore();` (ver tema 07).

## Ejemplos en esta carpeta

- `Hola_mundo.cpp` - primer programa y estructura minima
- `hola.cpp` - variante corta
- `cin_nombre_apellido.cpp` - leer nombre y apellido
- `getline_string.cpp` - leer la linea completa (con espacios)
- `char_ascii.cpp` - char con valores ASCII

## Retos (en `retos/`)

- `r01_ficha_universitaria_resuelto.cpp` - ficha con nombre, edad y promedio
- `r02_años_curso.cpp` - calcula tu edad en un año futuro
- `r03_cambio_dinero.cpp` - operaciones basicas entre dos numeros

Siguiente tema: **02 - Operadores**.