# 13 - STL y C++ Moderno

La STL (Standard Template Library) trae contenedores listos: `vector`, `map`,
`string`, algoritmos, etc. El C++ moderno (11/14/17/20) añade herramientas que
hacen el codigo mas limpio y seguro.

## auto - el compilador deduce el tipo

```cpp
auto x = 42;          // int
auto nota = 8.5;      // double
auto nombre = "Ana";  // string (cadena)
```

## range-based for - recorrer sin indices

```cpp
vector<int> notas = {8, 9, 7};

for (int n : notas) {        // "para cada n en notas"
    cout << n << endl;
}
```

## std::vector (conveniente)

```cpp
vector<string> materias;
materias.push_back("Matematicas");
materias.push_back("Programacion");
cout << materias.size();   // 2
```

## std::map - diccionario clave/valor

```cpp
#include <map>

map<string, float> calificaciones;
calificaciones["Matematicas"] = 8.5;
calificaciones["Programacion"]  = 9.0;
calificaciones["Fisica"]       = 7.5;

cout << calificaciones["Fisica"];   // 7.5

for (auto& par : calificaciones) {
    cout << par.first << " -> " << par.second << endl;
}
```

## std::string es "codigo moderno"

Preferir `std::string` sobre `char[]`, y `std::vector` sobre `new[]`.

## Lambdas - funciones anonimas

```cpp
auto alCuadrado = [](int x) { return x * x; };
cout << alCuadrado(5);   // 25
```

`[](tipos){ cuerpo }` es una funcion sin nombre que puedes guardar en `auto`.

## Algoritmos utiles (sort)

```cpp
#include <algorithm>

vector<int> notas = {7, 9, 8};
sort(notas.begin(), notas.end());   // ordena de menor a mayor
```

## Compila siempre con un estandar moderno

```bash
g++ -std=c++17 programa.cpp -o build/programa
```

## Ejemplos en esta carpeta

- `auto_y_rangefor.cpp` - auto y range-based for
- `vector_map.cpp` - vector y mapa de calificaciones
- `lambda.cpp` - funciones anonimas

## Retos (en `retos/`)

- `r01_*` - promedio con vector + range-for
- `r02_*` - diccionario de materias con map y notas
- `r03_*` - ordenar calificaciones con sort

¡Felicidades si llegaste aqui! Ya tienes el recorrido completo desde hola mundo
hasta el C++ moderno.