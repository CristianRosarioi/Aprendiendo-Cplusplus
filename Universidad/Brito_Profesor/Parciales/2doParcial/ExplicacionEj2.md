# Simulacro de parcial 2 — Sistema de ventas en C++

Vamos con otro ejercicio parecido a los del profesor Brito, pero más sencillo que el anterior.

Esta vez no utilizaremos paso por referencia (`&`), ni búsquedas complicadas. Vamos a practicar principalmente ciclos, estructuras, arreglos, funciones, condiciones y acumuladores.

La idea es que entiendas cómo trabajan las funciones y puedas modificar el programa durante el examen.

## 1. Enunciado del ejercicio

Desarrolle un programa en C++ que permita registrar las ventas de una pequeña tienda.

El programa debe cumplir con los siguientes requisitos:

1. Crear una estructura `Producto` con nombre, precio y cantidad vendida.
2. Utilizar un arreglo para almacenar tres productos.
3. Crear una función para mostrar el menú.
4. Crear una función que reciba el precio y la cantidad, y devuelva el total de una venta.
5. Permitir registrar las ventas de los tres productos.
6. Validar que los precios sean mayores que cero y que las cantidades no sean negativas.
7. Mostrar los productos con sus respectivos totales.
8. Calcular el total general de ventas.
9. Utilizar un menú con `do-while` y `switch`.

## 2. Código completo — `simulacro_2.cpp`

```cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Estructura
struct Producto {
    string nombre;
    double precio;
    int cantidad;
};

// Prototipos
void mostrarMenu();
double calcularVenta(double precio, int cantidad);

int main() {

    Producto productos[3];

    int opcion;
    double totalGeneral;

    cout << fixed << setprecision(2);

    // Registrar los productos
    for (int i = 0; i < 3; i++) {

        cout << "\nPRODUCTO " << i + 1 << endl;

        cout << "Nombre: ";
        cin >> productos[i].nombre;

        cout << "Precio: ";
        cin >> productos[i].precio;

        while (productos[i].precio <= 0) {
            cout << "Precio invalido. Intente otra vez: ";
            cin >> productos[i].precio;
        }

        cout << "Cantidad vendida: ";
        cin >> productos[i].cantidad;

        while (productos[i].cantidad < 0) {
            cout << "Cantidad invalida. Intente otra vez: ";
            cin >> productos[i].cantidad;
        }
    }

    do {
        mostrarMenu();

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

            case 1:
                cout << "\nLISTA DE PRODUCTOS" << endl;

                for (int i = 0; i < 3; i++) {

                    cout << "\nProducto: " << productos[i].nombre
                         << endl;

                    cout << "Precio: " << productos[i].precio
                         << endl;

                    cout << "Cantidad: " << productos[i].cantidad
                         << endl;

                    cout << "Total: "
                         << calcularVenta(productos[i].precio,
                                         productos[i].cantidad)
                         << endl;
                }
                break;

            case 2:
                totalGeneral = 0;

                for (int i = 0; i < 3; i++) {

                    totalGeneral += calcularVenta(
                        productos[i].precio,
                        productos[i].cantidad
                    );
                }

                cout << "\nTotal general de ventas: "
                     << totalGeneral << endl;
                break;

            case 0:
                cout << "Programa finalizado." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 0);

    return 0;
}

// Funcion que muestra el menu
void mostrarMenu() {

    cout << "\n===== SISTEMA DE VENTAS =====" << endl;
    cout << "1. Mostrar productos" << endl;
    cout << "2. Calcular total de ventas" << endl;
    cout << "0. Salir" << endl;
}

// Funcion que calcula el total de una venta
double calcularVenta(double precio, int cantidad) {

    double total;

    total = precio * cantidad;

    return total;
}
```

## 3. Explicación de las partes importantes

### A. Estructura y arreglo

```cpp
struct Producto {
    string nombre;
    double precio;
    int cantidad;
};
```

Creamos un tipo de dato que agrupa la información de un producto.

Después declaramos:

```cpp
Producto productos[3];
```

Esto crea un arreglo de tres estructuras.

Las posiciones son:

| Índice         | Elemento         |
| -------------- | ---------------- |
| `productos[0]` | Primer producto  |
| `productos[1]` | Segundo producto |
| `productos[2]` | Tercer producto  |

Observa que aquí utilizamos un arreglo fijo, no un vector.

Para acceder a sus miembros escribimos:

```cpp
productos[i].nombre
productos[i].precio
productos[i].cantidad
```

El índice `i` selecciona el producto y el punto `.` selecciona el miembro de la estructura.

### B. Registrar los productos con un `for`

```cpp
for (int i = 0; i < 3; i++) {
```

Este ciclo se ejecuta tres veces porque tenemos tres productos.

- `i = 0`: comienza con el primer producto.
- `i < 3`: continúa mientras el índice sea menor que tres.
- `i++`: aumenta el índice en uno.

En cada vuelta solicitamos nombre, precio y cantidad.

La ventaja es que no tenemos que escribir tres veces las instrucciones de registro.

### C. Validaciones con `while`

```cpp
while (productos[i].precio <= 0) {
    cout << "Precio invalido. Intente otra vez: ";
    cin >> productos[i].precio;
}
```

Este ciclo comprueba que el precio sea mayor que cero.

El operador `<=` significa menor o igual que.

Si el usuario introduce un precio negativo o cero, vuelve a pedirlo.

Para la cantidad utilizamos:

```cpp
while (productos[i].cantidad < 0) {
    cout << "Cantidad invalida. Intente otra vez: ";
    cin >> productos[i].cantidad;
}
```

Aquí permitimos cero porque un producto puede no tener ninguna unidad vendida.

### D. Función `mostrarMenu()`

```cpp
void mostrarMenu() {

    cout << "\n===== SISTEMA DE VENTAS =====" << endl;
    cout << "1. Mostrar productos" << endl;
    cout << "2. Calcular total de ventas" << endl;
    cout << "0. Salir" << endl;
}
```

Esta función no recibe parámetros ni devuelve resultados.

Por eso utilizamos `void`.

Para ejecutarla desde `main()` simplemente escribimos:

```cpp
mostrarMenu();
```

### E. Función `calcularVenta()`

```cpp
double calcularVenta(double precio, int cantidad) {

    double total;

    total = precio * cantidad;

    return total;
}
```

Esta función recibe dos parámetros:

- `precio`: un número decimal.
- `cantidad`: un número entero.

Multiplica ambos valores y devuelve el resultado.

Por ejemplo:

```cpp
calcularVenta(25, 3)
```

Devuelve:

```cpp
75
```

Esta es una función con parámetros y valor de retorno.

Observa que no necesitamos paso por referencia, porque la función solamente recibe los valores, realiza un cálculo y devuelve un resultado. No necesita modificar las variables originales.

### F. Menú con `do-while` y `switch`

```cpp
do {
    mostrarMenu();

    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion) {
        // Opciones
    }

} while (opcion != 0);
```

El `do-while` repite el menú mientras el usuario no seleccione cero.

El `switch` determina qué operación realizar:

| Opción | Acción                     |
| ------ | -------------------------- |
| 1      | Mostrar los tres productos |
| 2      | Calcular el total general  |
| 0      | Terminar                   |
| Otra   | Mostrar opción inválida    |

### G. Acumulador de ventas

```cpp
totalGeneral = 0;

for (int i = 0; i < 3; i++) {

    totalGeneral += calcularVenta(
        productos[i].precio,
        productos[i].cantidad
    );
}
```

Aquí combinamos tres conceptos:

1. Ciclo `for`.
2. Llamada a una función.
3. Acumulador mediante `+=`.

Primero inicializamos `totalGeneral` en cero.

Después recorremos los tres productos.

En cada vuelta, `calcularVenta()` devuelve el importe de un producto y se suma al total general.

Por ejemplo:

| Producto      | Precio | Cantidad | Total |
| ------------- | ------ | -------- | ----- |
| Arroz         | 50     | 3        | 150   |
| Aceite        | 200    | 2        | 400   |
| Azúcar        | 75     | 4        | 300   |
| Total general |        |          | 850   |

El cálculo es:

\\[ 150+400+300=850 \\]

## 4. Ejemplo de ejecución

```cpp
PRODUCTO 1
Nombre: Arroz
Precio: 50
Cantidad vendida: 3

PRODUCTO 2
Nombre: Aceite
Precio: 200
Cantidad vendida: 2

PRODUCTO 3
Nombre: Azucar
Precio: 75
Cantidad vendida: 4

===== SISTEMA DE VENTAS =====
1. Mostrar productos
2. Calcular total de ventas
0. Salir

Seleccione una opcion: 2

Total general de ventas: 850.00
```

Este programa supone que introduces números válidos donde se esperan números y nombres de productos de una sola palabra.

## 5. Conceptos que practicas para el parcial

| Concepto                    | Dónde se utiliza                                                                          |
| --------------------------- | ----------------------------------------------------------------------------------------- |
| `struct`                    | Representar un producto                                                                   |
| Arreglo fijo                | `Producto productos[3]`                                                                   |
| `for`                       | Registrar y recorrer productos                                                            |
| `while`                     | Validar precio y cantidad                                                                 |
| `do-while`                  | Repetir el menú                                                                           |
| `switch`                    | Elegir opciones                                                                           |
| `if`                        | No es necesario en esta solución; las decisiones se resuelven mediante `switch` y `while` |
| `void`                      | Función que muestra el menú                                                               |
| `double` y `return`         | Función que calcula una venta                                                             |
| Parámetros                  | Enviar precio y cantidad                                                                  |
| `+=`                        | Acumular las ventas                                                                       |
| `fixed` y `setprecision(2)` | Mostrar dos decimales                                                                     |

## 6. Practica modificándolo

Antes del examen, intenta hacer tres cambios sin consultar la solución: permitir cinco productos en lugar de tres, agregar una función que calcule el ITBIS del total y añadir una opción que muestre cuál producto generó más dinero.

Lo importante de este simulacro es que `main()` coordina el programa, las funciones realizan tareas específicas y los ciclos permiten procesar todos los productos sin repetir instrucciones.

Guarda este ejemplo como `simulacro_2.cpp` en tu USB. Te servirá como referencia si el profesor utiliza un problema de ventas, inventario, facturación o registros con arreglos y funciones.