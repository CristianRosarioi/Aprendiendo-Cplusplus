# 08 - Structs y Enums

## struct - agrupar datos relacionados

Un `struct` crea un tipo propio que agrupa variables (campos).

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
};

int main() {
    Estudiante e1;
    e1.nombre = "Cristian";
    e1.edad = 20;
    e1.promedio = 8.5;

    Estudiante e2 = {"Ana", 19, 9.2};   // inicializacion directa

    cout << e1.nombre << " " << e1.promedio << endl;
    cout << e2.nombre << " " << e2.promedio << endl;
    return 0;
}
```

- Se declara el tipo fuera de `main` (al nivel del `#include`).
- Se accede a los campos con el punto: `e1.nombre`.
- Puedes tener arreglos de structs: `Estudiante lista[30];`

## enum - constantes con nombre

```cpp
enum Dia { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };

Dia hoy = LUNES;        // hoy vale 0 internamente
int valor = LUNES;      // 0
```

Los valores internos son enteros consecutivos desde 0.
Sirven para que el codigo se lea solo: `case LUNES:` en vez de `case 0:`.

## Uso combinado clasico: arreglo de structs

```cpp
Estudiante grupo[3];
for (int i = 0; i < 3; i++) {
    cout << "Nombre: ";
    cin >> grupo[i].nombre;
}
```

## Ejemplos en esta carpeta

- `struct_estudiante.cpp` - struct y acceso a campos
- `enum_dias.cpp` - enum con dias de la semana

## Retos (en `retos/`)

- `r01_*` - registro de un curso con struct
- `r02_*` - promedio de un grupo de estudiantes (arreglo de structs)
- `r03_*` - enum para menu de opciones

Siguiente tema: **09 - Punteros y Referencias**.