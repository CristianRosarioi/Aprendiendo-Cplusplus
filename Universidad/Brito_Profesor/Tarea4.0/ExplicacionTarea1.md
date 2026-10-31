# ¿Qué hace el programa?

Simula una máquina expendedora con cinco bebidas. Muestra sus nombres,
precios y existencias; permite seleccionar una bebida, introducir
dinero, calcular el cambio, descontar una unidad y acumular el importe
de las ventas. El menú se repite hasta que el usuario elige 0.

# Máquina de bebidas en C++ — Explicación del código

Asignatura: Introducción a la Programación — UASD Unidad IV: Arreglos y vectores Temas: `struct`, `vector`, ciclos, condicionales, validaciones y acumuladores.

## 1. Objetivo del programa

Este programa simula una máquina expendedora que contiene cinco tipos de bebidas. Permite al usuario seleccionar un producto, introducir el dinero, recibir su cambio y actualizar el inventario.

También registra el total de dinero recaudado y mantiene el menú funcionando hasta que el usuario elija salir.

## 2. Código completo

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Bebida {
    string nombreBebida;
    double precioBebida;
    int cantidadEnMaquina;
};

int main() {
    vector<Bebida> bebidas(5);

    int opcion;
    int posicion;
    unsigned int i;

    double dinero;
    double cambio;
    double totalVentas = 0;

    // Datos iniciales de las cinco bebidas.
    bebidas.at(0).nombreBebida = "Botella de Agua";
    bebidas.at(0).precioBebida = 20.00;
    bebidas.at(0).cantidadEnMaquina = 20;

    bebidas.at(1).nombreBebida = "Coca Cola";
    bebidas.at(1).precioBebida = 25.00;
    bebidas.at(1).cantidadEnMaquina = 20;

    bebidas.at(2).nombreBebida = "Seven Up";
    bebidas.at(2).precioBebida = 25.00;
    bebidas.at(2).cantidadEnMaquina = 20;

    bebidas.at(3).nombreBebida = "Montain Dew";
    bebidas.at(3).precioBebida = 30.00;
    bebidas.at(3).cantidadEnMaquina = 20;

    bebidas.at(4).nombreBebida = "Jugo V8";
    bebidas.at(4).precioBebida = 50.00;
    bebidas.at(4).cantidadEnMaquina = 20;

    cout << fixed << setprecision(2);

    do {
        cout << "\nMAQUINA DE BEBIDAS" << endl;
        cout << fixed << setprecision(2) << left;

        cout << "+--------+----------------------+----------+------------+" << endl;

        cout << "| " << setw(6) << "Opcion"
             << " | " << setw(20) << "Bebida"
             << " | " << setw(8) << "Precio"
             << " | " << setw(10) << "Existencia"
             << " |" << endl;

        cout << "+--------+----------------------+----------+------------+" << endl;

        for (i = 0; i < bebidas.size(); i++) {
            cout << "| " << setw(6) << i + 1
                 << " | " << setw(20) << bebidas.at(i).nombreBebida
                 << " | " << setw(8) << bebidas.at(i).precioBebida
                 << " | " << setw(10) << bebidas.at(i).cantidadEnMaquina
                 << " |" << endl;
        }

        cout << "+--------+----------------------+----------+------------+" << endl;
        cout << "0. Salir" << endl;

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        while (opcion < 0 || opcion > 5) {
            cout << "Opcion invalida. Escriba de 0 a 5: ";
            cin >> opcion;
        }

        if (opcion != 0) {
            posicion = opcion - 1;

            if (bebidas.at(posicion).cantidadEnMaquina == 0) {
                cout << "Esta bebida esta agotada." << endl;
            } else {
                cout << "Bebida seleccionada: "
                     << bebidas.at(posicion).nombreBebida
                     << endl;

                cout << "Introduzca el monto de dinero: ";
                cin >> dinero;

                while (dinero < 20.00 ||
                       dinero < bebidas.at(posicion).precioBebida) {

                    if (dinero < 20.00) {
                        cout << "El monto debe ser de al menos 20.00."
                             << endl;
                    } else {
                        cout << "El monto no alcanza para esta bebida."
                             << endl;
                    }

                    cout << "Introduzca nuevamente el monto: ";
                    cin >> dinero;
                }

                cambio = dinero - bebidas.at(posicion).precioBebida;

                bebidas.at(posicion).cantidadEnMaquina--;

                totalVentas += bebidas.at(posicion).precioBebida;

                cout << "Retire su bebida: "
                     << bebidas.at(posicion).nombreBebida
                     << endl;

                cout << "Su cambio es: " << cambio << endl;
            }
        }

    } while (opcion != 0);

    cout << "\nTotal de dinero recaudado: "
         << totalVentas << endl;

    return 0;
}
```

## 3. Bibliotecas y estructura

### Bibliotecas utilizadas

| Biblioteca   | Función                                                                    |
| ------------ | -------------------------------------------------------------------------- |
| `<iostream>` | Permite utilizar `cin`, `cout` y `endl`.                                   |
| `<string>`   | Permite utilizar cadenas de texto.                                         |
| `<vector>`   | Permite almacenar varios elementos en un vector.                           |
| `<iomanip>`  | Permite dar formato a la salida mediante `setw`, `fixed` y `setprecision`. |

`using namespace std;` permite utilizar los elementos de la biblioteca estándar sin escribir `std::` delante de ellos.

### Estructura `Bebida`

```cpp
struct Bebida {
    string nombreBebida;
    double precioBebida;
    int cantidadEnMaquina;
};
```

Una estructura (`struct`) permite agrupar diferentes datos relacionados bajo un mismo tipo.

En este caso, cada bebida tiene tres miembros:

- `nombreBebida`: guarda el nombre mediante `string`.
- `precioBebida`: almacena el precio mediante `double`.
- `cantidadEnMaquina`: almacena las unidades disponibles mediante `int`.

La estructura define cómo estará organizada cada bebida, pero todavía no crea las cinco bebidas.

## 4. Vector, variables e inicialización

### Creación del vector

```cpp
vector<Bebida> bebidas(5);
```

Esta instrucción crea un vector llamado `bebidas`, compuesto por cinco elementos del tipo `Bebida`.

Cada posición contiene una estructura completa con su nombre, precio y existencia.

| Índice del vector | Bebida          |
| ----------------- | --------------- |
| 0                 | Botella de Agua |
| 1                 | Coca Cola       |
| 2                 | Seven Up        |
| 3                 | Montain Dew     |
| 4                 | Jugo V8         |

Importante: aunque el vector contiene cinco elementos, sus índices comienzan en cero y terminan en cuatro.

### Variables del programa

```cpp
int opcion;
int posicion;
unsigned int i;

double dinero;
double cambio;
double totalVentas = 0;
```

| Variable      | Función                                                               |
| ------------- | --------------------------------------------------------------------- |
| `opcion`      | Guarda la selección del usuario.                                      |
| `posicion`    | Guarda el índice del vector correspondiente a la bebida seleccionada. |
| `i`           | Controla el ciclo que recorre las bebidas.                            |
| `dinero`      | Guarda el monto introducido.                                          |
| `cambio`      | Guarda el dinero que debemos devolver.                                |
| `totalVentas` | Acumula el precio de las bebidas vendidas.                            |

`unsigned int` es un entero sin signo, mientras que `double` permite almacenar valores decimales.

### Asignación de datos

```cpp
bebidas.at(0).nombreBebida = "Botella de Agua";
bebidas.at(0).precioBebida = 20.00;
bebidas.at(0).cantidadEnMaquina = 20;
```

Aquí utilizamos dos elementos importantes:

- `.at(0)`: accede a la primera posición del vector.
- El punto (`.`): permite acceder a los miembros de la estructura.

Por ejemplo:

```cpp
bebidas.at(0).precioBebida
```

Significa: acceder al vector `bebidas`, seleccionar su primera posición y obtener el campo `precioBebida`.

El mismo procedimiento se repite para las cinco bebidas.

## 5. Presentación de la tabla y ciclo `for`

### Formato de los números

```cpp
cout << fixed << setprecision(2);
```

Esta instrucción permite mostrar los precios con dos decimales.

Por ejemplo:

```cpp
20.00
25.00
50.00
```

Para organizar la tabla también utilizamos:

```cpp
cout << left;
```

Que alinea los datos a la izquierda.

Y:

```cpp
setw(20)
```

Que establece un ancho mínimo de veinte caracteres para el siguiente dato mostrado.

Los caracteres `+`, `-` y `|` simplemente forman los bordes de la tabla.

### Recorrer el vector con `for`

```cpp
for (i = 0; i < bebidas.size(); i++) {
    cout << "| " << setw(6) << i + 1
         << " | " << setw(20) << bebidas.at(i).nombreBebida
         << " | " << setw(8) << bebidas.at(i).precioBebida
         << " | " << setw(10) << bebidas.at(i).cantidadEnMaquina
         << " |" << endl;
}
```

Este ciclo recorre las cinco posiciones del vector.

Analicemos su estructura:

```cpp
for (i = 0; i < bebidas.size(); i++)
```

- `i = 0`: comenzamos en la primera posición.
- `i < bebidas.size()`: repetimos mientras `i` sea menor que la cantidad de elementos.
- `i++`: aumentamos `i` en uno después de cada vuelta.

`bebidas.size()` devuelve `5`, porque ese es el número de elementos del vector.

| Vuelta | Valor de `i` | Bebida mostrada |
| ------ | ------------ | --------------- |
| 1      | 0            | Botella de Agua |
| 2      | 1            | Coca Cola       |
| 3      | 2            | Seven Up        |
| 4      | 3            | Montain Dew     |
| 5      | 4            | Jugo V8         |

Cuando `i` llega a 5, la condición es falsa y termina el ciclo.

### ¿Por qué utilizamos `i + 1`?

```cpp
setw(6) << i + 1
```

Porque queremos mostrar las opciones del menú del 1 al 5, aunque los índices del vector sean del 0 al 4.

Esto solamente modifica el número mostrado; no cambia el valor almacenado en `i`.

## 6. Menú principal y validación de opciones

### Ciclo `do-while`

```cpp
do {
    // Mostrar menu y procesar compras
} while (opcion != 0);
```

Este ciclo mantiene funcionando la máquina hasta que el usuario selecciona cero.

Utilizamos `do-while` porque necesitamos mostrar el menú al menos una vez antes de comprobar la condición.

El operador `!=` significa diferente de.

Por tanto:

```cpp
opcion != 0
```

Significa que el usuario todavía no ha seleccionado salir.

### Validación mediante `while`

```cpp
cout << "Seleccione una opcion: ";
cin >> opcion;

while (opcion < 0 || opcion > 5) {
    cout << "Opcion invalida. Escriba de 0 a 5: ";
    cin >> opcion;
}
```

Este ciclo comprueba que la opción esté entre 0 y 5.

El operador `||` significa OR (O). Basta con que una de las dos condiciones sea verdadera para que el ciclo se repita.

Por ejemplo:

- Si introduce `-1`, vuelve a pedir la opción.
- Si introduce `7`, vuelve a pedirla.
- Si introduce `3`, continúa.
- Si introduce `0`, podrá salir del programa.

Utilizamos `while` porque debemos seguir pidiendo la opción hasta recibir un número permitido.

## 7. Selección de bebida y proceso de compra

### Convertir la opción en un índice

```cpp
if (opcion != 0) {
    posicion = opcion - 1;
```

Primero comprobamos que el usuario no haya seleccionado salir.

Después restamos uno a la opción, porque el menú comienza en 1 y el vector comienza en 0.

Ejemplo:

```cpp
opcion = 3;
posicion = opcion - 1;
```

Resultado:

```cpp
posicion = 2;
```

Por tanto, accederemos a Seven Up.

### Comprobar la existencia

```cpp
if (bebidas.at(posicion).cantidadEnMaquina == 0) {
    cout << "Esta bebida esta agotada." << endl;
}
```

Esta condición comprueba si la cantidad disponible es igual a cero.

El operador `==` compara dos valores, mientras que `=` se utiliza para asignar.

Si no quedan unidades, el programa muestra un mensaje y no realiza la compra.

Si hay existencia, entra al `else` y continúa.

### Solicitar y validar el dinero

```cpp
cout << "Introduzca el monto de dinero: ";
cin >> dinero;

while (dinero < 20.00 ||
       dinero < bebidas.at(posicion).precioBebida) {
```

El ciclo comprueba dos condiciones:

1. Que el dinero no sea inferior a RD$20.
2. Que el dinero alcance para comprar la bebida seleccionada.

Por ejemplo, si el usuario selecciona una bebida de RD$30:

| Dinero | Resultado |
| ------ | --------- |
| 10     | Rechazado |
| 20     | Rechazado |
| 25     | Rechazado |
| 30     | Aceptado  |
| 50     | Aceptado  |

Dentro del `while` tenemos:

```cpp
if (dinero < 20.00) {
    cout << "El monto debe ser de al menos 20.00." << endl;
} else {
    cout << "El monto no alcanza para esta bebida." << endl;
}
```

Este `if-else` permite mostrar un mensaje diferente según el motivo del rechazo.

Después se solicita nuevamente el dinero hasta obtener un monto suficiente.

Importante: cada nuevo monto reemplaza el anterior; el programa no suma depósitos parciales.

## 8. Cambio, inventario y total de ventas

Cuando el usuario introduce suficiente dinero, ejecutamos tres operaciones importantes.

### Calcular el cambio

```cpp
cambio = dinero - bebidas.at(posicion).precioBebida;
```

Ejemplo: si compra Coca Cola por RD$25 y paga RD$50:

```cpp
Cambio = 50 - 25
Cambio = 25
```

### Descontar una unidad

```cpp
bebidas.at(posicion).cantidadEnMaquina--;
```

El operador `--` disminuye el valor en uno.

Si inicialmente había 20 bebidas, después de la compra quedan 19.

Es equivalente a:

```cpp
bebidas.at(posicion).cantidadEnMaquina =
    bebidas.at(posicion).cantidadEnMaquina - 1;
```

### Acumular las ventas

```cpp
totalVentas += bebidas.at(posicion).precioBebida;
```

El operador `+=` suma un valor a lo que la variable ya tenía almacenado.

Es equivalente a:

```cpp
totalVentas = totalVentas +
              bebidas.at(posicion).precioBebida;
```

Ejemplo:

| Venta     | Precio | Total acumulado |
| --------- | ------ | --------------- |
| Agua      | 20.00  | 20.00           |
| Coca Cola | 25.00  | 45.00           |
| Jugo V8   | 50.00  | 95.00           |

El acumulador comienza en cero y aumenta después de cada compra.

No sumamos todo el dinero entregado, sino el precio de la bebida, porque el cambio se devuelve al cliente.

Finalmente mostramos:

```cpp
cout << "Retire su bebida: "
     << bebidas.at(posicion).nombreBebida << endl;

cout << "Su cambio es: " << cambio << endl;
```

## 9. Finalización del programa

Cuando el usuario selecciona cero, termina el `do-while`.

Después se ejecuta:

```cpp
cout << "\nTotal de dinero recaudado: "
     << totalVentas << endl;

return 0;
```

El programa muestra el dinero total recaudado durante todas las compras.

`return 0` indica que la función `main()` terminó correctamente.

## 10. Simulación completa de una compra

Supongamos que un usuario compra una Coca Cola.

Estado inicial:

```cpp
Precio: 25.00
Existencia: 20
Total de ventas: 0.00
```

El usuario selecciona la opción 2.

```cpp
opcion = 2;
posicion = opcion - 1;
```

La posición será `1`.

El programa comprueba que todavía hay unidades y solicita dinero.

El usuario introduce RD$50.

```cpp
dinero = 50;
```

Como el dinero es suficiente, calculamos:

```cpp
cambio = 50 - 25;
```

Resultado:

```cpp
Cambio: 25.00
```

Después descontamos la existencia:

```cpp
bebidas.at(1).cantidadEnMaquina--;
```

Ahora quedan 19 Coca Colas.

Finalmente acumulamos la venta:

```cpp
totalVentas += 25;
```

El total pasa de 0 a 25.

El menú aparece nuevamente porque la opción es distinta de cero.

## 11. Resumen de los conceptos utilizados

\| Concepto | Utilidad dentro del programa | |---|---| | `struct` | Agrupar los datos de cada bebida. | | `vector` | Almacenar las cinco bebidas. | | `.at()` | Acceder a una posición del vector. | | `.size()` | Obtener la cantidad de elementos. | | `for` | Recorrer el vector y mostrar las bebidas. | | `while` | Validar opciones y montos. | | `do-while` | Repetir el menú principal. | | `if-else` | Tomar decisiones. | | `||` | Combinar condiciones mediante OR. | | `++` | Aumentar el contador del `for`. | | `--` | Disminuir el inventario. | | `+=` | Acumular las ventas. | | `setw()` | Organizar las columnas. | | `fixed` y `setprecision(2)` | Mostrar los precios con dos decimales. |

### Limitaciones de esta versión

El programa supone que el usuario introduce números válidos. Si escribe letras donde se espera un número, `cin` puede fallar porque no hemos implementado una recuperación de errores de entrada.

Además, los datos se mantienen solamente durante la ejecución. Al cerrar el programa y abrirlo nuevamente, las existencias vuelven a 20 y las ventas comienzan desde cero.

## 12. Conclusión

Este ejercicio nos permitió combinar varias herramientas importantes de C++ en un mismo programa.

Utilizamos una estructura para representar los datos de cada bebida, un vector para almacenarlas, ciclos para mostrar y validar información, condiciones para controlar las compras y acumuladores para registrar las ventas.

La lógica general del programa es:

Inicializar bebidas → Mostrar menú → Seleccionar → Validar → Cobrar → Calcular cambio → Actualizar inventario → Acumular venta → Repetir o salir.

Lo más importante es comprender cómo trabajan juntos los ciclos, las estructuras y los vectores. Dominar esa combinación nos permitirá desarrollar programas más completos, como sistemas de estudiantes, inventarios y facturación.