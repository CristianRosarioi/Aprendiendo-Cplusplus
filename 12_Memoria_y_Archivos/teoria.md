# 12 - Memoria Dinamica y Archivos

## Memoria dinamica (new / delete)

`new` reserva memoria en el monton (heap) mientras el programa corra;
`delete` la libera cuando ya no se necesita.

```cpp
int* num = new int(42);       // reserva espacio para un int con valor 42
cout << *num << endl;         // 42

int* arr = new int[10];       // arreglo dinamico
arr[0] = 5;
delete[] arr;                 // liberar el arreglo  (delete[])

delete num;                   // liberar la variable (delete)
```

> Cada `new` debe tener su `delete`. Si no, hay **fuga de memoria**.
> En C++ moderno se prefiere `std::vector` (autogestionado) antes que `new[]`.

## Archivos (fstream)

Tres clases: `ofstream` (escribir), `ifstream` (leer), `fstream` (ambas).

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // ESCRIBIR
    ofstream salida("notas.txt");       // abre (o crea) el archivo
    salida << "Cristian 8.5" << endl;   // escribe igual que con cout
    salida.close();

    // LEER
    ifstream entrada("notas.txt");
    string linea;
    while (getline(entrada, linea)) {   // lee linea por linea
        cout << linea << endl;
    }
    entrada.close();
    return 0;
}
```

## Comprobar que el archivo abrio

```cpp
ifstream entrada("datos.txt");
if (!entrada) {
    cout << "No se pudo abrir el archivo" << endl;
    return 1;
}
```

## Abrir con modo

```cpp
ofstream archivo("datos.txt", ios::app);   // app = agregar al final (no borrar)
```

## Ejemplos en esta carpeta

- `memoria_dinamica.cpp` - new/delete y arreglo dinamico
- `archivos_escribir_leer.cpp` - guardar y leer notas de un archivo

## Retos (en `retos/`)

- `r01_*` - agenda de contactos que guarda en archivo
- `r02_*` - leer un archivo de calificaciones y calcular promedio
- `r03_*` - inventario con alta/baja y guardado en archivo

Siguiente tema: **13 - STL y C++ Moderno**.