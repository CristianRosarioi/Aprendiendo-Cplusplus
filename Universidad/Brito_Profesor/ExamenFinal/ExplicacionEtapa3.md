Vamos a hacer esta modificación sobre tu código original de Accesorios Mashiaj, conservando el encabezado de la UASD, todos tus comentarios, los textos del menú, los precios y la lógica de compras.

Los cambios serán muy específicos:

1. Agregar el manejo de archivos con `<fstream>`.
2. Crear una función llamada `guardarRecibo()`.
3. Guardar la factura en un archivo llamado `recibo.txt`.
4. Utilizar `ios::out`, como explicó el profesor, para que cada nueva factura reemplace la anterior.
5. Mantener la factura en pantalla y añadir su almacenamiento al terminar la compra.

Hay una precisión importante sobre las bibliotecas: aunque `<fstream>` incluye internamente otras dependencias, no garantiza sustituir `<iostream>` para `cin` y `cout`, ni `<iomanip>` para `setw` y `setprecision`. Por eso conservaré esas dos, necesarias para que tu código compile correctamente. Podemos quitar el `#include <string>` explícito porque `<fstream>` ya proporciona soporte para `std::string`.

La diferencia fundamental que aprenderemos es esta:

```cpp
fstream archivo("recibo.txt", ios::out);
```

`ios::out` abre el archivo para escribir desde el principio, descartando su contenido anterior. Así tendremos un solo recibo: el correspondiente a la última compra, no un historial de todas las facturas.

## 1. Código completo actualizado — `AccMash.cpp`

Los únicos cambios en tu programa son la biblioteca de archivos, el nuevo prototipo, la llamada desde `main()` y la función `guardarRecibo()` al final.

```cpp

/*
Universidad Autónoma de Santo Domingo UASD
Centro UASD San Pedro, Escuela de informatica 5100-29
Introduccion a la Programacion
Cristian Rosario
Matricula: 100806653
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Prototipos de las funciones
void mostrarNegocio();
void mostrarMenu();
string obtenerPerfume(int opcion);
double obtenerPrecio(int opcion);
double calcularITBIS(double subtotal);
void mostrarFactura(int cantidades[]);
void guardarRecibo(int cantidades[]);

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

    // Guardar la factura en el archivo recibo.txt
    guardarRecibo(cantidades);

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

// Funcion que guarda la factura en el archivo recibo.txt
void guardarRecibo(int cantidades[]) {

    // Abrir el archivo en modo salida
    fstream archivo("recibo.txt", ios::out);

    // Validar que el archivo se haya abierto
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo recibo.txt" << endl;
        return;
    }

    double subtotal = 0;
    double itbis;
    double totalGeneral;
    double importe;

    int totalUnidades = 0;

    // Escribir el encabezado del recibo
    archivo << "\n\n===============================================================" << endl;
    archivo << "                       ACCESORIOS MASHIAJ" << endl;
    archivo << "                         FACTURA DE COMPRA" << endl;
    archivo << "===============================================================" << endl;

    archivo << fixed << setprecision(2);

    archivo << left
            << setw(36) << "Perfume"
            << right << setw(10) << "Cantidad"
            << setw(12) << "Precio"
            << setw(14) << "Importe" << endl;

    archivo << "------------------------------------------------------------------------" << endl;

    // Recorrer los cinco perfumes
    for (int i = 0; i < 5; i++) {

        // Mostrar solamente los perfumes comprados
        if (cantidades[i] > 0) {

            importe = cantidades[i] * obtenerPrecio(i + 1);

            archivo << left << setw(36) << obtenerPerfume(i + 1)
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

    archivo << "------------------------------------------------------------------------" << endl;

    archivo << "Total de unidades: " << totalUnidades << endl;
    archivo << "Subtotal: RD$ " << subtotal << endl;
    archivo << "ITBIS (18%): RD$ " << itbis << endl;

    archivo << "------------------------------------------------------------------------" << endl;

    archivo << "TOTAL GENERAL: RD$ " << totalGeneral << endl;

    archivo << "===============================================================" << endl;

    archivo << "Gracias por comprar en Accesorios Mashiaj." << endl;

    // Cerrar el archivo
    archivo.close();

    cout << "\nFactura guardada en recibo.txt" << endl;
}

```

# 2. Explicación de toda la lógica del programa

Primero repasaremos las funciones que ya tenías y después estudiaremos detalladamente lo nuevo.

## A. `main()` — Controla las compras

```cpp
int cantidades[5] = {0, 0, 0, 0, 0};
```

Este arreglo almacena cuántos perfumes ha comprado el cliente.

Cada posición corresponde a uno de los cinco productos.

Cuando el usuario compra un perfume, utilizamos:

```cpp
cantidades[opcion - 1] += cantidad;
```

Esto permite acumular las unidades.

Por ejemplo, si compra dos One Million y después compra tres más, el arreglo guardará cinco unidades de ese perfume.

El ciclo:

```cpp
do {
    // Mostrar menu y registrar compras
} while (opcion != 0);
```

Permite repetir la compra hasta que el cliente seleccione `0`.

Al finalizar, ahora ejecutamos dos funciones:

```cpp
mostrarFactura(cantidades);
guardarRecibo(cantidades);
```

La primera presenta la factura en pantalla.

La segunda guarda esa misma información en `recibo.txt`.

## B. `mostrarNegocio()` — Presentación

```cpp
void mostrarNegocio();
```

Es una función `void` porque solamente muestra información.

No recibe parámetros porque el nombre y los detalles del negocio son fijos.

## C. `mostrarMenu()` — Presentación de los productos

```cpp
void mostrarMenu();
```

Muestra los cinco perfumes con sus precios.

Utiliza un ciclo `for`:

```cpp
for (int i = 1; i <= 5; i++)
```

Y llama a:

```cpp
obtenerPerfume(i);
obtenerPrecio(i);
```

Esto evita escribir los nombres y los precios en diferentes partes del código.

La presentación utiliza `setw()`, `left` y `right` para alinear las columnas.

## D. `obtenerPerfume()` — Obtener nombres

```cpp
string obtenerPerfume(int opcion);
```

Recibe la opción seleccionada y utiliza `switch` para devolver el nombre del perfume correspondiente.

Por ejemplo:

```cpp
obtenerPerfume(4);
```

Devuelve `"Nautica Voyage 3.4 oz"`.

Utilizamos `string` porque la función devuelve texto.

## E. `obtenerPrecio()` — Obtener precios

```cpp
double obtenerPrecio(int opcion);
```

Funciona de manera similar a la anterior, pero devuelve un precio numérico.

Por ejemplo:

```cpp
obtenerPrecio(4);
```

Devuelve `2500.00`.

Utilizamos `double` porque los precios pueden contener decimales.

## F. `calcularITBIS()` — Calcular el impuesto

```cpp
double calcularITBIS(double subtotal) {

    double itbis;

    itbis = subtotal * 0.18;

    return itbis;
}
```

Recibe el subtotal y calcula el 18 %.

Si el subtotal vale RD$10,000:

\\[ 10000 \times 0.18 = 1800 \\]

La función devuelve RD$1,800.

Esta función se utiliza tanto para la factura en pantalla como para el recibo guardado.

## G. `mostrarFactura()` — Generar la factura en pantalla

Esta función recibe:

```cpp
int cantidades[]
```

Y recorre las cinco posiciones del arreglo.

Utiliza:

```cpp
if (cantidades[i] > 0)
```

Para mostrar solamente los productos que el cliente compró.

Calcula el importe de cada producto:

```cpp
importe = cantidades[i] * obtenerPrecio(i + 1);
```

Acumula el subtotal:

```cpp
subtotal += importe;
```

Cuenta las unidades:

```cpp
totalUnidades += cantidades[i];
```

Y finalmente calcula el impuesto y total general:

```cpp
itbis = calcularITBIS(subtotal);

totalGeneral = subtotal + itbis;
```

Toda esa lógica permanece exactamente igual que en tu programa original.

# 3. Lo nuevo: `guardarRecibo()`

Esta es la parte que debes estudiar especialmente porque corresponde al procesamiento de archivos que explicó el profesor.

## A. ¿Por qué creamos una función?

```cpp
void guardarRecibo(int cantidades[]);
```

Porque guardar la factura es una responsabilidad diferente de mostrarla.

Ahora tenemos:

- `mostrarFactura()`: presenta información en la terminal.
- `guardarRecibo()`: escribe información en un archivo.

Las dos reciben el mismo arreglo de cantidades y calculan la factura correspondiente.

## B. ¿Qué hace `<fstream>`?

```cpp
#include <fstream>
```

Nos permite trabajar con archivos mediante flujos.

En los ejemplos de clase, el profesor utilizó:

```cpp
fstream escribir("feo.txt", ios::out);
```

Nosotros hacemos algo equivalente:

```cpp
fstream archivo("recibo.txt", ios::out);
```

La variable `archivo` representa el flujo que utilizaremos para escribir la factura.

## C. ¿Qué significa `ios::out`?

Este concepto es el más importante del cambio.

`ios::out` es un modo de apertura para escritura.

En nuestro caso, cuando el archivo ya existe, su contenido anterior se descarta al abrirlo correctamente en este modo.

Por ejemplo:

Simulación del archivo `recibo.txt`

Primera compraSegunda compra

recibo.txt

ACCESORIOS MASHIAJ

FACTURA DE COMPRA

One Million 3.4 oz — 2 unidades

Subtotal: RD$10,000.00

ITBIS: RD$1,800.00

TOTAL: RD$11,800.00

El archivo contiene el recibo de la primera compra.

### Diferencia entre `ios::out` y `ios::app`

| Modo       | Comportamiento                                               |
| ---------- | ------------------------------------------------------------ |
| `ios::out` | Escribe una factura nueva reemplazando el contenido anterior |
| `ios::app` | Agrega una nueva factura al final del archivo existente      |
| `ios::in`  | Abre el archivo para leer información                        |

En nuestro programa utilizamos solamente `ios::out`, tal como solicitaste.

No necesitamos utilizar `ios::app`.

## D. ¿Por qué comprobamos `is_open()`?

```cpp
if (!archivo.is_open()) {
    cout << "Error al abrir el archivo recibo.txt" << endl;
    return;
}
```

Esta condición comprueba si el archivo se abrió.

El símbolo `!` significa negación.

Por tanto:

```cpp
!archivo.is_open()
```

Significa que el archivo no está abierto.

Si ocurre eso, mostramos un mensaje de error y terminamos la función con:

```cpp
return;
```

Como `guardarRecibo()` es `void`, utilizamos `return` sin devolver ningún valor.

## E. ¿Por qué cambiamos `cout` por `archivo`?

En `mostrarFactura()` tenemos:

```cpp
cout << "TOTAL GENERAL: RD$ " << totalGeneral << endl;
```

Esto envía información a la pantalla.

En `guardarRecibo()` utilizamos:

```cpp
archivo << "TOTAL GENERAL: RD$ " << totalGeneral << endl;
```

Esto envía información al archivo.

La diferencia es el destino del flujo de salida.

| Instrucción  | Destino          |
| ------------ | ---------------- |
| `cout <<`    | Pantalla         |
| `archivo <<` | Archivo de texto |

Por eso podemos utilizar las mismas instrucciones de formato:

```cpp
archivo << fixed << setprecision(2);
```

```cpp
archivo << setw(12) << importe;
```

El archivo conserva la presentación de columnas de la factura.

## F. ¿Qué hace `archivo.close()`?

```cpp
archivo.close();
```

Cierra el flujo del archivo después de escribir.

Este es el mismo procedimiento que viste en las prácticas del profesor.

El proceso completo es:

Abrir `recibo.txt` con `ios::out`

Comprobar `archivo.is_open()`

Escribir encabezado, productos y totales

Cerrar con `archivo.close()`

La factura queda guardada en el disco

# 4. ¿Dónde se creará `recibo.txt`?

Cuando ejecutes el programa, el archivo se creará en el directorio de trabajo actual, siempre que el programa tenga permiso para escribir.

Por ejemplo, si ejecutas `./AccMash` desde la carpeta del proyecto, verás:

```cpp
AccesoriosMashiaj/
├── AccMash.cpp
├── AccMash
└── recibo.txt
```

No necesitas crear el `.txt` manualmente.

Puedes compilar y ejecutar desde tu Mac:

```cpp
clang++ -std=c++17 AccMash.cpp -o AccMash
./AccMash
```

Y consultar el recibo:

```cpp
cat recibo.txt
```

## 5. ¿Cómo comprobar que funciona correctamente?

Haz estas tres pruebas:

1. Ejecuta el programa, compra dos One Million y finaliza con 0. Abre `recibo.txt` y comprueba que aparezca esa factura.
2. Ejecuta nuevamente, compra un Nautica Voyage y finaliza con 0. Comprueba que la factura anterior ya no esté y que solamente aparezca la nueva.
3. Comprueba que los nombres, cantidades, subtotal, ITBIS y total general coincidan entre la terminal y el archivo.

En este ejercicio, si seleccionas 0 sin comprar nada, también se generará un recibo con importes en cero, porque hemos conservado tu lógica original.

## 6. Resumen de las modificaciones

| Elemento               | Antes                      | Ahora                               |
| ---------------------- | -------------------------- | ----------------------------------- |
| Menú y productos       | Cinco perfumes             | Sin cambios                         |
| Registro de cantidades | Arreglo de cinco elementos | Sin cambios                         |
| Cálculo del ITBIS      | Función `calcularITBIS()`  | Sin cambios                         |
| Factura en pantalla    | `mostrarFactura()`         | Sin cambios                         |
| Biblioteca de archivos | No estaba                  | `<fstream>`                         |
| Guardar factura        | No existía                 | `guardarRecibo()`                   |
| Archivo                | No existía                 | `recibo.txt`                        |
| Modo de apertura       | No existía                 | `ios::out`                          |
| Facturas anteriores    | No se guardaban            | Se reemplazan con cada nueva compra |

Lo más importante que debes aprender: `cout` y `fstream` son dos formas de trabajar con flujos de salida. Con `cout` enviamos información a la terminal; con `fstream` abierto mediante `ios::out` enviamos información a un archivo.

Esta versión conserva tu programa original y agrega únicamente el almacenamiento del último recibo, utilizando los conceptos que el profesor está enseñando en clase.