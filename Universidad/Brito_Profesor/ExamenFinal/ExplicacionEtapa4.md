# Accesorios Mashiaj — Etapa 4: Registro de clientes y recibos

Vamos a agregar la cuarta etapa de tu proyecto final, manteniendo todo lo que ya funciona exactamente igual: los cinco perfumes, precios, menú, comentarios, cálculos, ITBIS, factura en pantalla y almacenamiento del último recibo con `ios::out`.

Solo agregaremos las funcionalidades nuevas que pidió el profesor Brito.

### ¿Qué cambia en esta etapa?

1. Cuando el cliente termine de seleccionar sus perfumes y cantidades, el programa solicitará su nombre y número de teléfono.
2. Guardaremos esos datos en un archivo llamado `cliente.txt`, utilizando `<fstream>` e `ios::out`.
3. Agregaremos el nombre y teléfono del cliente al comienzo de la factura guardada en `recibo.txt`.
4. Los dos archivos reemplazarán sus contenidos anteriores cada vez que se realice una nueva compra.

La factura que ya aparece en pantalla conservará su presentación actual. Los datos del cliente se agregarán al recibo guardado, tal como solicitaste.

Usaremos dos funciones relacionadas con archivos:

- `guardarCliente()` — Nueva función para guardar los datos en `cliente.txt`.
- `guardarRecibo()` — La función existente, que ahora recibirá también el nombre y el teléfono.

## 1. Código completo actualizado — `AccMash.cpp`

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
void guardarRecibo(int cantidades[], string nombreCliente, string telefonoCliente);
void guardarCliente(string nombreCliente, string telefonoCliente);

int main() {

    int opcion;
    int cantidad;

    // Variables para los datos del cliente
    string nombreCliente;
    string telefonoCliente;

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

    // Solicitar los datos del cliente
    cin.ignore(1000, '\n');

    cout << "\nIntroduzca el nombre del cliente: ";
    getline(cin, nombreCliente);

    cout << "Introduzca el numero de telefono: ";
    getline(cin, telefonoCliente);

    // Mostrar factura al finalizar
    mostrarFactura(cantidades);

    // Guardar los datos del cliente
    guardarCliente(nombreCliente, telefonoCliente);

    // Guardar la factura en el archivo recibo.txt
    guardarRecibo(cantidades, nombreCliente, telefonoCliente);

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

// Funcion que devuelve el precio
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

    cout << "\n\n========================================================================" << endl;
    cout << "                       ACCESORIOS MASHIAJ" << endl;
    cout << "                         FACTURA DE COMPRA" << endl;
    cout << "========================================================================" << endl;

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

    cout << "========================================================================" << endl;

    cout << "Gracias por comprar en Accesorios Mashiaj." << endl;
}

// Funcion que guarda la factura en el archivo recibo.txt
void guardarRecibo(int cantidades[], string nombreCliente, string telefonoCliente) {

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

    // Escribir los datos del cliente en el recibo
    archivo << "Nombre del cliente: " << nombreCliente << endl;
    archivo << "Numero de telefono: " << telefonoCliente << endl;
    archivo << endl;

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

// Funcion que guarda los datos del cliente
void guardarCliente(string nombreCliente, string telefonoCliente) {

    // Abrir el archivo cliente.txt en modo salida
    fstream archivo("cliente.txt", ios::out);

    // Validar que el archivo se haya abierto
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo cliente.txt" << endl;
        return;
    }

    // Escribir los datos del cliente
    archivo << "DATOS DEL CLIENTE" << endl;
    archivo << "Nombre: " << nombreCliente << endl;
    archivo << "Telefono: " << telefonoCliente << endl;

    // Cerrar el archivo
    archivo.close();

    cout << "\nDatos del cliente guardados en cliente.txt" << endl;
}

```

# 2. Explicación de las modificaciones

## A. Nuevas variables en `main()`

Agregamos:

```cpp
string nombreCliente;
string telefonoCliente;
```

Ambas son de tipo `string`, pero por razones diferentes.

`nombreCliente`: almacena el nombre completo de la persona que realiza la compra.

`telefonoCliente`: almacena su número telefónico.

### ¿Por qué el teléfono es `string` y no `int`?

Porque un teléfono no se utiliza para realizar operaciones matemáticas.

Además, puede incluir:

- Ceros iniciales.
- Guiones.
- Espacios.
- El símbolo `+` de un código internacional.

Por ejemplo:

```cpp
809-555-1234
```

Por eso `string` es un tipo apropiado.

## B. Solicitar los datos después de las compras

Agregamos este fragmento justo después del `do-while`:

```cpp
cin.ignore(1000, '\n');

cout << "\nIntroduzca el nombre del cliente: ";
getline(cin, nombreCliente);

cout << "Introduzca el numero de telefono: ";
getline(cin, telefonoCliente);
```

¿Por qué colocamos esto después del ciclo?

Porque el profesor quiere que primero el cliente termine de seleccionar todos sus productos y cantidades.

Cuando selecciona `0`, el ciclo finaliza y entonces solicitamos los datos personales.

### ¿Para qué sirve `getline()`?

Anteriormente hemos utilizado:

```cpp
cin >> nombreCliente;
```

Pero si el usuario introduce:

```cpp
Juan Carlos Perez
```

`cin >> nombreCliente` solamente leería `Juan`.

Con:

```cpp
getline(cin, nombreCliente);
```

Podemos capturar el nombre completo, incluidos los espacios.

### ¿Para qué sirve `cin.ignore(1000, '\n')`?

Esta instrucción descarta los caracteres pendientes de la línea de entrada hasta encontrar el salto de línea, con un límite de 1000 caracteres.

Es necesaria aquí porque venimos de utilizar:

```cpp
cin >> opcion;
```

Después de introducir `0` y presionar Enter, queda el salto de línea pendiente.

Si llamamos inmediatamente a `getline()`, podría leer ese salto de línea y devolver un nombre vacío.

Con `cin.ignore()` evitamos ese problema.

## C. Nueva función `guardarCliente()`

Este es el nuevo prototipo:

```cpp
void guardarCliente(string nombreCliente, string telefonoCliente);
```

Vamos a analizarlo:

| Parte                    | Significado              |
| ------------------------ | ------------------------ |
| `void`                   | No devuelve un resultado |
| `guardarCliente`         | Nombre de la función     |
| `string nombreCliente`   | Recibe el nombre         |
| `string telefonoCliente` | Recibe el teléfono       |

¿Por qué utilizamos `void`?

Porque la responsabilidad de la función es guardar datos en un archivo, no calcular y devolver un resultado.

Dentro de ella utilizamos:

```cpp
fstream archivo("cliente.txt", ios::out);
```

Esta instrucción abre `cliente.txt` para escritura.

Si el archivo no existe, se crea. Si ya existe, se reemplaza su contenido anterior al abrirlo correctamente.

Después:

```cpp
archivo << "DATOS DEL CLIENTE" << endl;
archivo << "Nombre: " << nombreCliente << endl;
archivo << "Telefono: " << telefonoCliente << endl;
```

Escribimos los datos en el archivo.

Finalmente:

```cpp
archivo.close();
```

Cerramos el flujo.

### Así quedará `cliente.txt`

```cpp
DATOS DEL CLIENTE
Nombre: Juan Carlos Perez
Telefono: 809-555-1234
```

El archivo guardará solamente los datos del último cliente, porque estamos utilizando `ios::out`.

## D. Modificación de `guardarRecibo()`

Antes recibía solamente el arreglo:

```cpp
void guardarRecibo(int cantidades[]);
```

Ahora recibe tres parámetros:

```cpp
void guardarRecibo(int cantidades[], string nombreCliente, string telefonoCliente);
```

¿Por qué?

Porque necesita tres tipos de información:

1. `cantidades[]`: saber qué productos compró el cliente.
2. `nombreCliente`: saber cómo se llama.
3. `telefonoCliente`: conocer su teléfono.

En `main()` ahora la llamamos así:

```cpp
guardarRecibo(cantidades, nombreCliente, telefonoCliente);
```

Fíjate en la relación:

| Argumento enviado desde `main()` | Parámetro recibido       |
| -------------------------------- | ------------------------ |
| `cantidades`                     | `int cantidades[]`       |
| `nombreCliente`                  | `string nombreCliente`   |
| `telefonoCliente`                | `string telefonoCliente` |

Los dos textos se pasan por valor a la función, mientras que el parámetro del arreglo permite acceder a sus elementos originales.

### ¿Qué agregamos dentro de `guardarRecibo()`?

Solamente estas instrucciones para mostrar los datos en el archivo:

```cpp
archivo << "Nombre del cliente: " << nombreCliente << endl;
archivo << "Numero de telefono: " << telefonoCliente << endl;
archivo << endl;
```

Las colocamos después del encabezado de la factura y antes de la tabla de productos.

Todos los cálculos, el ciclo `for`, los nombres, precios e ITBIS continúan iguales.

# 3. ¿Cómo quedarán los archivos?

Después de realizar una compra se generarán dos archivos.

AccesoriosMashiaj/

AccMash.cpp

cliente.txt

Nuevo

recibo.txt

### Contenido de `recibo.txt`

Por ejemplo, si Juan Carlos Perez compra dos One Million, tendremos:

```cpp
========================================================================
                       ACCESORIOS MASHIAJ
                         FACTURA DE COMPRA
========================================================================
Nombre del cliente: Juan Carlos Perez
Numero de telefono: 809-555-1234

Perfume                               Cantidad      Precio       Importe
------------------------------------------------------------------------
One Million 3.4 oz                           2     5000.00      10000.00
------------------------------------------------------------------------
Total de unidades: 2
Subtotal: RD$ 10000.00
ITBIS (18%): RD$ 1800.00
------------------------------------------------------------------------
TOTAL GENERAL: RD$ 11800.00
========================================================================
Gracias por comprar en Accesorios Mashiaj.
```

La factura sigue siendo la misma. Únicamente agregamos los dos datos del cliente.

# 4. El flujo completo de la etapa 4

1\. Mostrar menú

El cliente selecciona sus perfumes

2\. Registrar cantidades

El do-while permite seguir comprando

3\. Seleccionar 0

Finaliza el proceso de compras

4\. Solicitar datos

Se pide nombre y teléfono

5\. Mostrar factura

Se ejecuta mostrarFactura()

6\. Guardar cliente

Se escribe cliente.txt con ios::out

7\. Guardar recibo

Se escribe recibo.txt con ios::out

## 5. Repaso de todas las funciones actuales

| Función            | ¿Qué hace?                                | Retorno  |
| ------------------ | ----------------------------------------- | -------- |
| `mostrarNegocio()` | Presenta Accesorios Mashiaj               | `void`   |
| `mostrarMenu()`    | Muestra productos y precios               | `void`   |
| `obtenerPerfume()` | Devuelve el nombre del perfume            | `string` |
| `obtenerPrecio()`  | Devuelve su precio                        | `double` |
| `calcularITBIS()`  | Calcula el 18 %                           | `double` |
| `mostrarFactura()` | Presenta la factura en pantalla           | `void`   |
| `guardarRecibo()`  | Guarda la factura y los datos del cliente | `void`   |
| `guardarCliente()` | Guarda el nombre y teléfono del cliente   | `void`   |

Ahora tenemos ocho funciones propias más `main()`.

## 6. Cómo probar la nueva etapa

En tu Mac, desde la carpeta del proyecto:

```cpp
clang++ -std=c++17 AccMash.cpp -o AccMash
./AccMash
```

Realiza una compra, introduce el nombre completo y el teléfono, y después revisa los archivos:

```cpp
cat cliente.txt
cat recibo.txt
```

Haz también una segunda compra con otro nombre y teléfono. Comprueba que ambos archivos contienen exclusivamente la información de la nueva compra, porque seguimos utilizando `ios::out`.

Nota: en esta versión no modificamos la validación numérica que ya tenías ni agregamos validaciones nuevas para nombres y teléfonos. Eso mantiene el comportamiento original; las entradas vacías de texto todavía serían aceptadas.

### Lo principal que debes aprender de esta etapa

Antes, nuestro programa solamente necesitaba los productos y sus cantidades para generar una factura.

Ahora tenemos información adicional, por lo que debemos enviar más argumentos a las funciones que la necesitan.

Este es uno de los principios más importantes de la programación con funciones: cada función debe recibir la información necesaria para cumplir su responsabilidad.

Y con `<fstream>` hemos añadido una segunda capacidad: los datos ya no se quedan solamente en las variables, sino que podemos conservarlos en archivos `.txt`.

Esta es nuestra etapa 4 de Accesorios Mashiaj, sin alterar ninguna de las funcionalidades anteriores.