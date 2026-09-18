# 07 - Strings

Cadenas de texto. En C++ moderno usa `std::string` (muy superior al `char[]` clasico).

## Declarar y usar

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string nombre = "Cristian";
    string apellido = "Rosario";

    cout << "Largo: " << nombre.length() << endl;        // cantidad de caracteres
    cout << "Primera letra: " << nombre[0] << endl;      // indice 0
    cout << "Concatenar: " << nombre + " " + apellido << endl;

    if (nombre == "Cristian") {
        cout << "Es Cristian" << endl;
    }
    return 0;
}
```

## Leer texto con espacios: getline

```cpp
string nombre;
cout << "Nombre completo: ";
getline(cin, nombre);   // lee toda la linea, incluye espacios
```

## El problema del Enter pendiente

`cin >>` deja el Enter en el buffer. Si despues usas `getline`, aparece como
una linea vacia. Solucion: limpiar el buffer con `cin.ignore()`:

```cpp
int edad;
string nombre;

cout << "Edad: ";
cin >> edad;
cin.ignore();          // tira el Enter que quedo pendiente

cout << "Nombre: ";
getline(cin, nombre);
```

## Metodos utiles

| Metodo          | Que hace                       |
|-----------------|--------------------------------|
| `.length()`     | tamano (cantidad de caracteres)|
| `.append(x)`    | agrega texto al final          |
| `.find(x)`      | posicion de x (si no, npos)    |
| `.substr(pos,n)`| porcion del string             |
| `.empty()`      | true si esta vacio             |

## char[] estilo C (lo que pide la universidad a veces)

```cpp
char nombre[20];              // arreglo de caracteres con tamaño fijo
cin.getline(nombre, 20);      // leer con espacios (como getline)
```

Se usan en C, pero en C++ es mejor `std::string`. Si el profesor lo pide,
revisa los ejemplos `caracteres_*.cpp`.

## char vs string

- `char letra = 'A';` un solo caracter, comillas simples.
- `string nombre = "Ana";` cadena, comillas dobles.
- Un `char` tambien guarda codigos ASCII: `char c = 72;` imprime 'H'.

## Ejemplos en esta carpeta

- `caracteres_nombre.cpp` / `caracteres_nombre_apellido.cpp` - char[] con cin
- `caracteres_getline.cpp` / `caracteres_pausa.cpp` - getline y cin.get
- `edad_getline_sin_ignore.cpp` - el BUG del Enter (falla a proposito)
- `edad_getline_ignore.cpp` - la solucion con cin.ignore()

## Retos (en `retos/`)

- `r01_*` - verificar que el nombre no este vacio
- `r02_*` - contar vocales en un nombre
- `r03_*` - separar nombre y apellido con substr

Siguiente tema: **08 - Structs y Enums**.