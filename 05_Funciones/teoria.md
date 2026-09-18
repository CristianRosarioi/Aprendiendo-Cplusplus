# 05 - Funciones

Las funciones permiten organizar y reutilizar codigo. Un programa se divide en
bloques que reciben datos (parametros), hacen un trabajo y devuelven un resultado.

## Partes de una funcion

```cpp
tipo_retorno nombre(parametros) {
    // cuerpo
    return valor_del_tipo_retorno;
}
```

## Ejemplo completo

```cpp
#include <iostream>
using namespace std;

double promedio(double a, double b) {   // retorna double, recibe dos doubles
    return (a + b) / 2;
}

void saludar(string nombre) {           // void = NO retorna nada
    cout << "Hola " << nombre << endl;
}

int main() {
    saludar("Cristian");                       // llamada a void
    double prom = promedio(8.5, 9.0);          // guardamos el retorno
    cout << "Promedio: " << prom << endl;
    return 0;
}
```

## Conceptos clave

- **Parametros**: valores que recibe la funcion (van entre parentesis).
- **Retorno**: valor que devuelve con `return`. Si no devuelve nada, usa `void`.
- **Llamada**: usar la funcion desde `main` u otra funcion.
- **Prototipo**: declarar la funcion antes de `main` y definir el cuerpo despues:

```cpp
double promedio(double a, double b);   // prototipo

int main() { /* ... */ }

double promedio(double a, double b) {  // definicion completa despues
    return (a + b) / 2;
}
```

- **Paso por valor**: la funcion recibe una COPIA. Modificar el parametro dentro
  de la funcion NO afecta a la variable original (ver tema 09 para referencias).

## Buenas practicas

1. Nombres claros: `calcularPromedio()`, no `func1()`.
2. Una funcion = una responsabilidad.
3. Inicializa los acumuladores fuera de la funcion si son locales.

## Ejemplos en esta carpeta

- `funcion_suma.cpp` - suma de dos numeros
- `funcion_promedio.cpp` - promedio de notas
- `funcion_void_saludar.cpp` - funcion sin retorno

## Retos (en `retos/`)

- `r01_*` - area y perimetro de un rectangulo con funciones
- `r02_*` - menu con funciones (suma, resta, multiplica, divide)
- `r03_*` - es par o impar con una funcion bool

Siguiente tema: **06 - Arrays y Vectores**.