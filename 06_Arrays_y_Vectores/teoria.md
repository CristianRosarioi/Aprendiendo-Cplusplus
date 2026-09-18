# 06 - Arrays y Vectores

Colecciones de valores del mismo tipo en una sola variable.

## Arreglo de tamaño fijo (C-style array)

```cpp
float notas[4];          // reserva espacio para 4 notas

notas[0] = 8.5;          // indices van de 0 a tamaño-1
notas[1] = 9.0;
notas[2] = 7.5;
notas[3] = 6.0;

float otros[3] = {8, 9, 7};   // declarar e inicializar directo

cout << notas[0] << endl;     // 8.5
```

> Los indices van de **0 a tamaño-1**. `notas[4]` es un error fuera de rango.

## Recorrer con for

```cpp
const int TOTAL = 4;
float notas[TOTAL];
float suma = 0;

for (int i = 0; i < TOTAL; i++) {
    cin >> notas[i];
    suma += notas[i];
}

float promedio = suma / TOTAL;
```

## std::vector (crece solo - recomendado)

`vector` pertenece a la STL: puedes agregar elementos sin fijar tamaño.

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<float> notas;
    notas.push_back(8.5);      // agrega al final
    notas.push_back(9.0);

    cout << "Cantidad: " << notas.size() << endl;   // 2
    cout << notas[0] << endl;                       // 8.5

    for (int i = 0; i < notas.size(); i++) {
        cout << notas[i] << endl;
    }
    return 0;
}
```

Metodos utiles: `push_back(x)`, `size()`, `[i]` acceso, `empty()`.
Para vaciarlo: `notas.clear()`.

## Ejemplos en esta carpeta

- `arreglo_notas.cpp` - arreglo fijo y acceso por indice
- `arreglo_y_for.cpp` - llenar, mostrar y promediar con for
- `vector_intro.cpp` - std::vector con push_back

## Retos (en `retos/`)

- `r01_calculadora_semestre.cpp` - 4 materias, promedio y letra (resuelto)
- `r02_*` - mayor y menor de un arreglo
- `r03_*` - conteo de cursos aprobados con vector

Siguiente tema: **07 - Strings**.