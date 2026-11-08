# Accesorios Mashiaj — Segunda etapa del proyecto final de C++

Ahora sí comenzamos a convertir Accesorios Mashiaj en un pequeño sistema de ventas y facturación.

Lo que pidió el profesor es una continuación del programa que construiste en el parcial. Por eso no vamos a comenzar otro proyecto ni agregar cosas que todavía no nos han pedido. Vamos a conservar tus cinco perfumes, el menú con `setw()`, las funciones y el `switch`.

La diferencia es que ahora el cliente podrá comprar varios perfumes y diferentes cantidades, y al terminar recibirá una factura.

## 1. ¿Qué pide el profesor en esta etapa?

El programa debe:

1. Mostrar el nombre y los detalles del negocio.
2. Presentar los cinco perfumes con sus precios.
3. Permitir seleccionar un perfume y escribir cuántas unidades desea.
4. Permitir seguir comprando otros perfumes, incluso repetir uno que ya seleccionó.
5. Acumular las cantidades y los importes.
6. Al seleccionar 0. Finalizar compra, mostrar una factura con los productos, cantidades, precios y subtotales.
7. Calcular el ITBIS y el total general.

Para este ejercicio utilizaremos un ITBIS del 18 %, aplicado a todos los productos como supuesto de práctica. Es una tasa de cálculo del programa, no una verificación del tratamiento tributario particular de cada perfume.

## 2. Así funcionará el programa

Por ejemplo, el cliente realiza estos pedidos:

- 2 One Million.
- 1 Nautica Voyage.
- 3 Valentino Born in Roma.

Cuando termine la compra, aparecerá una factura como esta:

## ACCESORIOS MASHIAJ

Tu perfumería preferida

FACTURA DE COMPRA

| Producto               | Cant. | Precio | Importe |
| ---------------------- | ----- | ------ | ------- |
| One Million            | 2     | 5,000  | 10,000  |
| Nautica Voyage         | 1     | 2,500  | 2,500   |
| Valentino Born in Roma | 3     | 6,500  | 19,500  |

Total de unidades

6

Subtotal

RD$32,000.00

ITBIS (18 %)

RD$5,760.00

TOTAL GENERAL

## RD$37,760.00

Gracias por su compra

# 3. Código completo actualizado — `AccMash.cpp`

Para esta etapa utilizaremos dos arreglos sencillos, uno para las cantidades y otro para los precios. No necesitamos `vector`, ni `struct`, ni paso por referencia explícito.

Es razonable usar arreglos ahora porque tenemos cinco productos y necesitamos recordar cuánto se compró de cada uno. El programa sigue siendo sencillo y utiliza únicamente conceptos de las unidades que hemos estudiado.

```cpp

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Prototipos de las funciones
void mostrarNegocio();
void mostrarMenu();
string obtenerPerfume(int opcion);
double obtenerPrecio(int opcion);
void mostrarFactura(int cantidades[]);

int main() {

    int opcion;
    int cantidad;

    // Arreglo que guarda las cantidades compradas
    int cantidades[5] = {0, 0, 0, 0, 0};

    mostrarNegocio();

    do {
        mostrarMenu();

        cout << "\nSeleccione una opcion (0-5): ";
        cin >> opcion;

        // Validar la opcion seleccionada
        while (opcion < 0 || opcion > 5) {
            cout << "Opcion invalida. Seleccione del 0 al 5: ";
            cin >> opcion;
        }

        if (opcion != 0) {

            cout << "\nPerfume seleccionado: "
                 << obtenerPerfume(opcion) << endl;

            cout << "Precio: RD$ "
                 << obtenerPrecio(opcion) << endl;

            cout << "Cantidad que desea comprar: ";
            cin >> cantidad;

            // Validar la cantidad
            while (cantidad <= 0) {
                cout << "Cantidad invalida. Introduzca una cantidad mayor que 0: ";
                cin >> cantidad;
            }

            // Acumular la cantidad del producto seleccionado
            cantidades[opcion - 1] += cantidad;

            cout << "\nProducto agregado a su pedido." << endl;
            cout << "Puede seguir comprando o elegir 0 para finalizar."
                 << endl;
        }

    } while (opcion != 0);

    // Mostrar la factura final
    mostrarFactura(cantidades);

    return 0;
}

// Funcion que muestra los datos del negocio
void mostrarNegocio() {

    cout << "===============================================================" << endl;
    cout << "                       ACCESORIOS MASHIAJ" << endl;
    cout << "                     Tu perfumeria preferida" << endl;
    cout << "===============================================================" << endl;
}

// Funcion que muestra el menu de perfumes
void mostrarMenu() {

    cout << fixed << setprecision(2);

    cout << "\n                      MENU DE PERFUMES\n" << endl;

    cout << "+--------+------------------------------------------+------------+" << endl;

    cout << "| " << left << setw(6) << "Opcion"
         << " | " << setw(40) << "Perfume"
         << " | " << right << setw(10) << "Precio RD$"
         << " |" << endl;

    cout << "+--------+------------------------------------------+------------+" << endl;

    for (int i = 1; i <= 5; i++) {

        cout << "| " << left << setw(6) << i
             << " | " << setw(40) << obtenerPerfume(i)
             << " | " << right << setw(10) << obtenerPrecio(i)
             << " |" << endl;
    }

    cout << "+--------+------------------------------------------+------------+" << endl;
    cout << "0. Finalizar compra" << endl;
}

// Funcion que devuelve el nombre del perfume
string obtenerPerfume(int opcion) {

    switch (opcion) {

        case 1:
            return "One Million 3.4 oz";

        case 2:
            return "Armani Acqua di Gio 3.4 oz";

        case 3:
            return "Dolce Gabbana Light Blue 4.2 oz";

        case 4:
            return "Nautica Voyage 3.4 oz";

        case 5:
            return "Valentino Born in Roma 3.4 oz";

        default:
            return "Perfume no encontrado";
    }
}

// Funcion que devuelve el precio del perfume
double obtenerPrecio(int opcion) {

    switch (opcion) {

        case 1:
            return 5000.00;

        case 2:
            return 7500.00;

        case 3:
            return 4200.00;

        case 4:
            return 2500.00;

        case 5:
            return 6500.00;

        default:
            return 0;
    }
}

// Funcion que genera la factura
void mostrarFactura(int cantidades[]) {

    double subtotal = 0;
    double itbis;
    double totalGeneral;
    double importe;

    int totalUnidades = 0;

    cout << "\n\n===============================================================" << endl;
    cout << "                       ACCESORIOS MASHIAJ" << endl;
    cout << "                         FACTURA DE COMPRA" << endl;
    cout << "===============================================================" << endl;

    cout << fixed << setprecision(2);

    cout << left
         << setw(36) << "Perfume"
         << right << setw(10) << "Cantidad"
         << setw(12) << "Precio"
         << setw(14) << "Importe" << endl;

    cout << "------------------------------------------------------------------------" << endl;

    // Recorrer los cinco perfumes
    for (int i = 0; i < 5; i++) {

        // Mostrar solamente los perfumes comprados
        if (cantidades[i] > 0) {

            importe = cantidades[i] * obtenerPrecio(i + 1);

            cout << left << setw(36) << obtenerPerfume(i + 1)
                 << right << setw(10) << cantidades[i]
                 << setw(12) << obtenerPrecio(i + 1)
                 << setw(14) << importe << endl;

            subtotal += importe;

            totalUnidades += cantidades[i];
        }
    }

    // Calcular el ITBIS y el total general
    itbis = subtotal * 0.18;

    totalGeneral = subtotal + itbis;

    cout << "------------------------------------------------------------------------" << endl;

    cout << "Total de unidades: " << totalUnidades << endl;
    cout << "Subtotal: RD$ " << subtotal << endl;
    cout << "ITBIS (18%): RD$ " << itbis << endl;

    cout << "------------------------------------------------------------------------" << endl;

    cout << "TOTAL GENERAL: RD$ " << totalGeneral << endl;

    cout << "===============================================================" << endl;

    cout << "Gracias por comprar en Accesorios Mashiaj." << endl;
}

```

# 4. Explicación de las nuevas funcionalidades

Voy a concentrarme en las partes nuevas, porque el menú, `switch`, los prototipos y `setw()` ya los estudiamos. Lo importante ahora es que entiendas cómo almacenar varias compras, acumularlas y generar la factura.

## A. El arreglo `cantidades[5]`

```cpp
int cantidades[5] = {0, 0, 0, 0, 0};
```

Este arreglo tiene cinco posiciones, una para cada perfume.

| Índice | Perfume                  | Cantidad inicial |
| ------ | ------------------------ | ---------------- |
| 0      | One Million              | 0                |
| 1      | Armani Acqua di Gio      | 0                |
| 2      | Dolce Gabbana Light Blue | 0                |
| 3      | Nautica Voyage           | 0                |
| 4      | Valentino Born in Roma   | 0                |

Todas las cantidades comienzan en cero porque todavía no se ha comprado nada.

¿Por qué es necesario?

Porque el cliente puede seleccionar varios productos y necesitamos recordar qué cantidades lleva acumuladas.

Por ejemplo, si compra dos One Million:

```cpp
cantidades[0] = 2;
```

Luego compra tres Valentino:

```cpp
cantidades[4] = 3;
```

Al finalizar, el arreglo contendrá:

```cpp
{2, 0, 0, 0, 3}
```

Esto nos permite saber que compró dos unidades del primer producto y tres del quinto.

## B. Repetir las compras mediante `do-while`

```cpp
do {
    mostrarMenu();

    cout << "Seleccione una opcion (0-5): ";
    cin >> opcion;

    // Procesar compra

} while (opcion != 0);
```

Antes el programa solamente permitía seleccionar un perfume y terminaba.

Ahora utilizamos `do-while` para repetir el menú hasta que el usuario escriba `0`.

El procedimiento es:

1. Muestra el menú.
2. El usuario selecciona un perfume.
3. Solicita la cantidad.
4. Guarda la cantidad.
5. Vuelve al menú.
6. Continúa hasta seleccionar 0.

Cuando selecciona 0, sale del ciclo y se genera la factura.

## C. Las funciones `obtenerPerfume()` y `obtenerPrecio()`

Estas dos funciones evitan que escribamos repetidamente los nombres y precios en diferentes partes del programa.

Por ejemplo:

```cpp
string obtenerPerfume(int opcion) {
    switch (opcion) {
        case 1:
            return "One Million 3.4 oz";

        case 2:
            return "Armani Acqua di Gio 3.4 oz";

        default:
            return "Perfume no encontrado";
    }
}
```

Este fragmento muestra solamente algunos casos; la función completa está en el código principal.

Si llamamos:

```cpp
cout << obtenerPerfume(2);
```

Muestra:

```cpp
Armani Acqua di Gio 3.4 oz
```

La función `obtenerPrecio()` hace lo mismo, pero devuelve un número `double`.

```cpp
double obtenerPrecio(int opcion) {
    switch (opcion) {
        case 1:
            return 5000.00;

        case 2:
            return 7500.00;

        default:
            return 0;
    }
}
```

Por ejemplo:

```cpp
double precio = obtenerPrecio(1);
```

La variable `precio` recibe `5000.00`.

Fíjate en la diferencia:

- `obtenerPerfume()` devuelve `string`.
- `obtenerPrecio()` devuelve `double`.

Ambas reciben `int opcion` como parámetro, pero devuelven tipos diferentes según lo que necesitan proporcionar.

## D. Acumular las cantidades compradas

Esta es posiblemente la instrucción más importante de toda la modificación:

```cpp
cantidades[opcion - 1] += cantidad;
```

Vamos a entenderla.

Primero:

```cpp
opcion - 1
```

Convierte la opción del menú en el índice del arreglo.

El menú comienza en 1, pero el arreglo comienza en 0.

Después:

```cpp
+= cantidad
```

Agrega la cantidad introducida a la que ya había.

Supongamos que el cliente selecciona la opción 1 y pide dos perfumes.

```cpp
opcion = 1;
cantidad = 2;
```

La instrucción equivale a:

```cpp
cantidades[0] += 2;
```

Como inicialmente había 0:

```cpp
0 + 2 = 2
```

Si vuelve a seleccionar la opción 1 y compra tres más:

```cpp
cantidades[0] += 3;
```

Entonces:

```cpp
2 + 3 = 5
```

Ahora la factura tendrá 5 unidades de One Million, aunque el cliente lo haya seleccionado en dos momentos diferentes.

Esta es la diferencia fundamental entre utilizar:

```cpp
cantidades[opcion - 1] = cantidad;
```

y:

```cpp
cantidades[opcion - 1] += cantidad;
```

La primera reemplaza el valor anterior. La segunda lo acumula.

## E. La función `mostrarFactura()`

```cpp
void mostrarFactura(int cantidades[])
```

Esta función recibe el arreglo con las cantidades compradas.

La llamamos desde `main()`:

```cpp
mostrarFactura(cantidades);
```

Aquí no estamos utilizando el símbolo `&` de paso por referencia.

Sin embargo, hay un detalle de C++ que debes conocer: cuando pasamos un arreglo tradicional como parámetro de esta manera, la función puede acceder a los elementos del arreglo original. No se crea automáticamente una copia completa del arreglo.

En nuestro caso no modificamos las cantidades dentro de esta función; solamente las consultamos para imprimir la factura.

### Recorrer los productos comprados

```cpp
for (int i = 0; i < 5; i++) {

    if (cantidades[i] > 0) {
        // Calcular y mostrar el producto
    }
}
```

El ciclo recorre las cinco posiciones.

El `if` comprueba que la cantidad sea mayor que cero.

Esto significa que solo aparecerán en la factura los perfumes que el cliente realmente compró.

Si no compró Nautica Voyage, por ejemplo, no aparecerá una fila para ese producto.

### ¿Por qué utilizamos `i + 1`?

Dentro de la factura aparece:

```cpp
obtenerPerfume(i + 1);
obtenerPrecio(i + 1);
```

Porque `i` comienza en cero, mientras que nuestras funciones esperan opciones del 1 al 5.

Si `i` vale 0, enviamos 1, que corresponde a One Million.

## F. Calcular el importe de cada producto

```cpp
importe = cantidades[i] * obtenerPrecio(i + 1);
```

El importe es el resultado de multiplicar la cantidad comprada por el precio unitario.

Por ejemplo, si compramos tres Valentino:

\\[ 3\times6500=19500 \\]

La variable `importe` recibe `19500`.

Después mostramos el nombre, la cantidad, el precio y el importe mediante `cout` y `setw()`.

## G. Calcular el subtotal

```cpp
subtotal += importe;
```

Esta es otra operación de acumulación.

El subtotal representa la suma de todos los productos antes de aplicar el ITBIS.

Por ejemplo:

| Producto         | Importe   |
| ---------------- | --------- |
| 2 One Million    | RD$10,000 |
| 1 Nautica Voyage | RD$2,500  |
| 3 Valentino      | RD$19,500 |
| Subtotal         | RD$32,000 |

El programa acumula cada importe en `subtotal`.

## H. Calcular el total de unidades

```cpp
totalUnidades += cantidades[i];
```

Aquí no estamos sumando dinero, sino cantidades.

En nuestro ejemplo:

\\[ 2+1+3=6 \\]

Por tanto, el cliente compró seis unidades en total.

Es importante no confundir:

- Cantidad total: número de unidades compradas.
- Subtotal: suma monetaria antes de impuestos.
- Total general: suma monetaria después de agregar el impuesto.

## I. Calcular el ITBIS

```cpp
itbis = subtotal * 0.18;
```

El programa calcula el 18 % del subtotal.

Por ejemplo:

\\[ 32000\times0.18=5760 \\]

El ITBIS será RD$5,760.

## J. Calcular el total general

```cpp
totalGeneral = subtotal + itbis;
```

Sumamos el subtotal y el impuesto:

\\[ 32000+5760=37760 \\]

La factura mostrará:

```cpp
Subtotal: RD$ 32000.00
ITBIS (18%): RD$ 5760.00
TOTAL GENERAL: RD$ 37760.00
```

# 5. ¿Cómo queda organizado el programa?

| Función                 | Responsabilidad                                |
| ----------------------- | ---------------------------------------------- |
| `main()`                | Controlar las compras y guardar las cantidades |
| `mostrarNegocio()`      | Mostrar el nombre y detalles del negocio       |
| `mostrarMenu()`         | Mostrar los cinco perfumes y sus precios       |
| `obtenerPerfume(int)`   | Devolver el nombre del perfume                 |
| `obtenerPrecio(int)`    | Devolver el precio del perfume                 |
| `mostrarFactura(int[])` | Calcular y mostrar la factura final            |

Observa cómo estamos aplicando lo que te dijo el profesor: el programa ya no depende de una sola función que haga prácticamente todo.

Cada función tiene una responsabilidad concreta y podemos seguir ampliándolo en las próximas clases.

## 6. Lo que debes probar al compilarlo

Prueba estas situaciones:

| Prueba                            | Resultado esperado                 |
| --------------------------------- | ---------------------------------- |
| Comprar 2 unidades del producto 1 | Factura con 2 One Million          |
| Comprar productos 1, 3 y 5        | Aparecen tres productos diferentes |
| Comprar dos veces el producto 2   | Las cantidades se acumulan         |
| Introducir cantidad 0 o negativa  | Vuelve a pedir una cantidad válida |
| Introducir opción 8               | Vuelve a solicitar una opción      |
| Seleccionar 0 sin comprar         | Factura con total 0                |
| Comprar varias unidades           | Calcula subtotal, ITBIS y total    |

Al igual que en los ejercicios anteriores, esta versión supone que el usuario introduce valores numéricos cuando se le solicitan. No incluye todavía recuperación ante errores de entrada como escribir letras en lugar de números.

## 7. Lo que más quiero que entiendas de esta etapa

Hay cuatro conceptos que debes dominar porque seguramente los seguiremos utilizando hasta el examen final:

Primero: `do-while` mantiene abierto el proceso de compras.

Segundo: el arreglo `cantidades[5]` conserva cuántos perfumes se han comprado de cada tipo.

Tercero: `+=` permite acumular tanto cantidades como dinero sin perder lo registrado anteriormente.

Cuarto: las funciones separan el menú, la información de los perfumes y la factura.

También quiero que notes que esta vez no necesitamos un `switch` directamente en `main()`. Lo utilizamos en `obtenerPerfume()` y `obtenerPrecio()`, porque esas funciones determinan qué nombre y qué precio corresponde a cada opción.

En la próxima ampliación podemos mantener esta misma estructura y agregar únicamente las funcionalidades que indique el profesor.

Esta sería nuestra versión 2 de Accesorios Mashiaj: un sistema que ya permite registrar una compra con diferentes productos, acumular cantidades y generar una factura con subtotal, ITBIS y total general.


# Y por qué ITBIS no es una función ? Osea es solo una pregunta no es que lo cambiemos. 


¡Buena pregunta! Y tiene mucho que ver con lo que te señaló el profesor sobre aprender a identificar qué partes del programa deben convertirse en funciones.

El ITBIS perfectamente podría ser una función. No lo hice así porque el cálculo era sencillo y estaba dentro de `mostrarFactura()`, pero separarlo sería una buena decisión de organización.

### 1. Como lo tenemos actualmente

```cpp
itbis = subtotal * 0.18;
totalGeneral = subtotal + itbis;
```

Funciona correctamente, pero el cálculo está directamente dentro de `mostrarFactura()`.

### 2. ¿Cómo sería utilizando una función?

Podríamos declarar:

```cpp
double calcularITBIS(double subtotal);
```

Y definirla:

```cpp
double calcularITBIS(double subtotal) {
    return subtotal * 0.18;
}
```

Después, dentro de `mostrarFactura()`, simplemente escribiríamos:

```cpp
itbis = calcularITBIS(subtotal);

totalGeneral = subtotal + itbis;
```

### 3. ¿Qué ventaja tendría?

Imagina que mañana el profesor te pide calcular el ITBIS en otra parte del programa.

En lugar de repetir:

```cpp
subtotal * 0.18
```

Podrías llamar:

```cpp
calcularITBIS(subtotal)
```

Además, si el porcentaje cambia, solo tendrías que modificar la función.

### 4. Entonces, ¿cuándo debo crear una función?

Esa es la pregunta importante.

No necesitas crear una función para cada línea de código. Pero normalmente conviene considerar una función cuando:

- Una operación tiene una responsabilidad claramente identificable.
- Necesitas utilizar el mismo cálculo en diferentes partes.
- Quieres separar la lógica de cálculo de las instrucciones que muestran información.
- Una parte del programa comienza a crecer demasiado.

En nuestro proyecto, esta organización tendría sentido:

| Función            | Responsabilidad      |
| ------------------ | -------------------- |
| `mostrarNegocio()` | Presentar el negocio |
| `mostrarMenu()`    | Mostrar los perfumes |
| `obtenerPerfume()` | Obtener el nombre    |
| `obtenerPrecio()`  | Obtener el precio    |
| `calcularITBIS()`  | Calcular el impuesto |
| `mostrarFactura()` | Presentar la factura |

Mi recomendación para tu aprendizaje: sí, `calcularITBIS()` es un buen candidato para una función, especialmente porque el profesor quiere que organices el proyecto utilizando funciones.

Pero no necesitamos cambiar el código ahora, como dijiste.

Lo importante es que estás comenzando a pensar como programador: ya no solamente te preguntas cómo hacer que el código funcione, sino cómo organizarlo correctamente.


# Ok dame el código completo nuevo. Poniendo esa función de itbis. Me gusta que la tenga por las ventajas que dices. Dale edita eso y me lo pasas completo 

Perfecto. Vamos a mantener Accesorios Mashiaj como lo tenemos, pero ahora agregaremos la función `calcularITBIS()`, que se encargará exclusivamente de calcular el impuesto.

No cambiaremos la lógica de las compras ni la presentación del menú. Seguiremos utilizando funciones, `switch`, arreglos, `for`, `do-while` y `setw()`, como hemos aprendido con el profesor Brito.

## Código completo actualizado — `AccMash.cpp`

```cpp

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Prototipos de las funciones
void mostrarNegocio();
void mostrarMenu();
string obtenerPerfume(int opcion);
double obtenerPrecio(int opcion);
double calcularITBIS(double subtotal);
void mostrarFactura(int cantidades[]);

int main() {

    int opcion;
    int cantidad;

    // Arreglo para guardar las cantidades compradas
    int cantidades[5] = {0, 0, 0, 0, 0};

    mostrarNegocio();

    do {
        mostrarMenu();

        cout << "\nSeleccione una opcion (0-5): ";
        cin >> opcion;

        // Validar la opcion
        while (opcion < 0 || opcion > 5) {
            cout << "Opcion invalida. Seleccione del 0 al 5: ";
            cin >> opcion;
        }

        if (opcion != 0) {

            cout << "\nPerfume seleccionado: "
                 << obtenerPerfume(opcion) << endl;

            cout << "Precio: RD$ "
                 << obtenerPrecio(opcion) << endl;

            cout << "Cantidad que desea comprar: ";
            cin >> cantidad;

            // Validar la cantidad
            while (cantidad <= 0) {
                cout << "Cantidad invalida. Introduzca una cantidad mayor que 0: ";
                cin >> cantidad;
            }

            // Acumular las cantidades de cada perfume
            cantidades[opcion - 1] += cantidad;

            cout << "\nProducto agregado a su pedido." << endl;
            cout << "Puede seguir comprando o elegir 0 para finalizar."
                 << endl;
        }

    } while (opcion != 0);

    // Mostrar factura al finalizar
    mostrarFactura(cantidades);

    return 0;
}

// Funcion que muestra los datos del negocio
void mostrarNegocio() {

    cout << "===============================================================" << endl;
    cout << "                       ACCESORIOS MASHIAJ" << endl;
    cout << "                     Tu perfumeria preferida" << endl;
    cout << "===============================================================" << endl;
}

// Funcion que muestra el menu
void mostrarMenu() {

    cout << fixed << setprecision(2);

    cout << "\n                      MENU DE PERFUMES\n" << endl;

    cout << "+--------+------------------------------------------+------------+" << endl;

    cout << "| " << left << setw(6) << "Opcion"
         << " | " << setw(40) << "Perfume"
         << " | " << right << setw(10) << "Precio RD$"
         << " |" << endl;

    cout << "+--------+------------------------------------------+------------+" << endl;

    for (int i = 1; i <= 5; i++) {

        cout << "| " << left << setw(6) << i
             << " | " << setw(40) << obtenerPerfume(i)
             << " | " << right << setw(10) << obtenerPrecio(i)
             << " |" << endl;
    }

    cout << "+--------+------------------------------------------+------------+" << endl;
    cout << "0. Finalizar compra" << endl;
}

// Funcion que devuelve el nombre del perfume
string obtenerPerfume(int opcion) {

    switch (opcion) {

        case 1:
            return "One Million 3.4 oz";

        case 2:
            return "Armani Acqua di Gio 3.4 oz";

        case 3:
            return "Dolce Gabbana Light Blue 4.2 oz";

        case 4:
            return "Nautica Voyage 3.4 oz";

        case 5:
            return "Valentino Born in Roma 3.4 oz";

        default:
            return "Perfume no encontrado";
    }
}

// Funcion que devuelve el precio del perfume
double obtenerPrecio(int opcion) {

    switch (opcion) {

        case 1:
            return 5000.00;

        case 2:
            return 7500.00;

        case 3:
            return 4200.00;

        case 4:
            return 2500.00;

        case 5:
            return 6500.00;

        default:
            return 0;
    }
}

// Funcion que calcula el ITBIS
double calcularITBIS(double subtotal) {

    double itbis;

    itbis = subtotal * 0.18;

    return itbis;
}

// Funcion que genera la factura
void mostrarFactura(int cantidades[]) {

    double subtotal = 0;
    double itbis;
    double totalGeneral;
    double importe;

    int totalUnidades = 0;

    cout << "\n\n===============================================================" << endl;
    cout << "                       ACCESORIOS MASHIAJ" << endl;
    cout << "                         FACTURA DE COMPRA" << endl;
    cout << "===============================================================" << endl;

    cout << fixed << setprecision(2);

    cout << left
         << setw(36) << "Perfume"
         << right << setw(10) << "Cantidad"
         << setw(12) << "Precio"
         << setw(14) << "Importe" << endl;

    cout << "------------------------------------------------------------------------" << endl;

    // Recorrer los cinco perfumes
    for (int i = 0; i < 5; i++) {

        // Mostrar solamente los perfumes comprados
        if (cantidades[i] > 0) {

            importe = cantidades[i] * obtenerPrecio(i + 1);

            cout << left << setw(36) << obtenerPerfume(i + 1)
                 << right << setw(10) << cantidades[i]
                 << setw(12) << obtenerPrecio(i + 1)
                 << setw(14) << importe << endl;

            subtotal += importe;

            totalUnidades += cantidades[i];
        }
    }

    // Llamar la funcion que calcula el ITBIS
    itbis = calcularITBIS(subtotal);

    // Calcular el total general
    totalGeneral = subtotal + itbis;

    cout << "------------------------------------------------------------------------" << endl;

    cout << "Total de unidades: " << totalUnidades << endl;
    cout << "Subtotal: RD$ " << subtotal << endl;
    cout << "ITBIS (18%): RD$ " << itbis << endl;

    cout << "------------------------------------------------------------------------" << endl;

    cout << "TOTAL GENERAL: RD$ " << totalGeneral << endl;

    cout << "===============================================================" << endl;

    cout << "Gracias por comprar en Accesorios Mashiaj." << endl;
}

```

## ¿Qué cambiamos exactamente?

Solo realizamos tres cambios respecto a la versión anterior.

### 1. Agregamos el prototipo

```cpp
double calcularITBIS(double subtotal);
```

Le indica al compilador que existe una función llamada `calcularITBIS`, que recibe un `double` y devuelve otro `double`.

### 2. Creamos la función

```cpp
double calcularITBIS(double subtotal) {

    double itbis;

    itbis = subtotal * 0.18;

    return itbis;
}
```

La función recibe el subtotal de la compra, calcula el 18 % y devuelve ese resultado.

Por ejemplo, si recibe `10000`:

```cpp
10000 * 0.18 = 1800
```

La función devuelve `1800`.

### 3. Modificamos `mostrarFactura()`

Antes teníamos:

```cpp
itbis = subtotal * 0.18;
```

Ahora tenemos:

```cpp
itbis = calcularITBIS(subtotal);
```

Observa el recorrido:

`mostrarFactura()`

Subtotal = 10,000

`calcularITBIS(10000)`

Calcula 10,000 × 0.18

`return 1800`

Devuelve el impuesto a mostrarFactura()

Total general = 11,800

## Organización actual de nuestro programa

| Función            | Responsabilidad                  |
| ------------------ | -------------------------------- |
| `main()`           | Controlar el proceso de compras  |
| `mostrarNegocio()` | Mostrar los detalles del negocio |
| `mostrarMenu()`    | Mostrar los cinco perfumes       |
| `obtenerPerfume()` | Devolver el nombre de un perfume |
| `obtenerPrecio()`  | Devolver su precio               |
| `calcularITBIS()`  | Calcular y devolver el impuesto  |
| `mostrarFactura()` | Preparar y presentar la factura  |

Ahora tenemos seis funciones propias más `main()`.

Esto es precisamente lo que queremos practicar para el examen final: dividir las responsabilidades del programa sin complicarlo innecesariamente.

Una aclaración para tus estudios: aunque `mostrarFactura(int cantidades[])` no utiliza el símbolo `&`, los arreglos tradicionales se pasan a las funciones mediante acceso a sus elementos originales, no como una copia completa del arreglo.

Esta será nuestra versión actualizada de Accesorios Mashiaj. Mantendremos esta base para incorporar las siguientes instrucciones que nos dé el profesor.