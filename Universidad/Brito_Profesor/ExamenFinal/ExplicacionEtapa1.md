¡Ahora entiendo mucho mejor lo que está buscando el profesor Brito para el examen final! Y hay algo importante: tu programa funcionó y cumplió buena parte de lo solicitado, pero utilizaste una solución más compleja de lo que necesitaba el problema.

Eso explica las observaciones del profesor. No fue tanto un problema de sintaxis de C++, sino de cómo diseñar el programa y distribuir sus responsabilidades entre funciones.

Y precisamente eso es lo que debemos trabajar contigo a partir de ahora.

Vamos a analizar tu solución, corregir su diseño y construir una versión que sirva como base para las próximas funcionalidades del examen final.

## 1. Evaluación de tu programa del parcial

Según el enunciado que compartiste:

| Requisito                     | Tu solución                     | Evaluación                        |
| ----------------------------- | ------------------------------- | --------------------------------- |
| Mostrar el nombre del negocio | `NombredeNegocio()`             | &#x20;Cumplido                    |
| Mostrar detalles del negocio  | Solo nombre y descripción breve | &#x20;Podría ampliarse            |
| Mostrar cinco productos       | `vector<Perfumes>`              | &#x20;Cumplido                    |
| Mostrar nombre y precio       | `for` y `setw()`                | &#x20;Cumplido                    |
| Elegir una opción             | `cin >> opcion`                 | &#x20;Cumplido                    |
| Mostrar el pedido elegido     | `switch`                        | &#x20;Cumplido                    |
| Trabajar con funciones        | Una función para el nombre      | &#x20;Muy limitado                |
| Usar estructuras y vectores   | Los utilizaste                  | No eran necesarios ni solicitados |

Mi evaluación: resolviste el problema funcionalmente, pero todavía no organizaste el programa de la manera que el profesor esperaba.

Y algo más: el uso de un `vector` no es incorrecto técnicamente. Simplemente fue innecesario para este enunciado.

## 2. ¿Por qué el profesor te dijo que no utilizaras vectores?

Mira lo que hiciste:

```cpp
struct Perfumes {
    string nombrePerfume;
    double precioPerfume;
};

vector<Perfumes> perfume(5);
```

Después llenaste el vector con los cinco productos y los mostraste mediante un ciclo.

Esto es perfectamente válido en C++.

Pero el profesor solamente solicitó:

- Cinco opciones.
- Cinco nombres de productos.
- Sus precios.
- Una selección.
- Un mensaje mostrando el pedido.

No solicitó almacenar productos en una colección ni recorrer estructuras.

Para un menú fijo de cinco opciones, podemos mostrar directamente:

```cpp
cout << "1. One Million - RD$5000" << endl;
cout << "2. Armani Acqua di Gio - RD$7500" << endl;
cout << "3. Dolce & Gabbana Light Blue - RD$4200" << endl;
cout << "4. Nautica Voyage - RD$2500" << endl;
cout << "5. Valentino Born in Roma - RD$6500" << endl;
```

Esto es más sencillo y cumple exactamente el propósito.

Lección importante para los próximos parciales: que conozcas una herramienta no significa que tengas que utilizarla siempre.

Debemos elegir las herramientas según el problema.

## 3. Tu principal dificultad: identificar qué funciones crear

Esta es la parte que más me interesa que aprendas.

Tú creaste:

```cpp
void NombredeNegocio() {
    cout << "Accesorios Mashiaj: tu perfumeria preferida" << endl;
}
```

La función funciona, pero realiza una tarea muy pequeña.

Podríamos organizar el programa de forma más útil, separándolo en tres responsabilidades:

Organización recomendada del programa

`main()`

Coordina la ejecución

mostrarNegocio()

Nombre y detalles

mostrarMenu()

Cinco productos y precios

entregarPedido()

Procesa la opción

Observa que no necesitamos inventar funciones difíciles.

Simplemente preguntamos:

¿Qué tareas diferentes realiza este programa?

Y convertimos esas tareas en funciones.

En este caso:

1. Presentar el negocio.
2. Mostrar los productos.
3. Procesar el pedido.

`main()` solamente coordina estas operaciones.

## 4. Código corregido y organizado en funciones

Esta versión conserva tus cinco perfumes y sus precios, pero elimina las estructuras y los vectores que el profesor consideró innecesarios.

También mantiene `switch`, ya que forma parte de los conceptos que están trabajando.

```cpp
#include <iostream>
using namespace std;

// Prototipos de las funciones
void mostrarNegocio();
void mostrarMenu();
void entregarPedido(int opcion);

int main() {

    int opcion;

    mostrarNegocio();

    mostrarMenu();

    cout << "\nSeleccione una opcion (1-5): ";
    cin >> opcion;

    entregarPedido(opcion);

    return 0;
}

// Funcion que muestra los datos del negocio
void mostrarNegocio() {

    cout << "====================================" << endl;
    cout << "         ACCESORIOS MASHIAJ         " << endl;
    cout << "       Tu perfumeria preferida      " << endl;
    cout << "====================================" << endl;
}

// Funcion que muestra los productos
void mostrarMenu() {

    cout << "\nMENU DE PERFUMES" << endl;

    cout << "1. One Million 3.4 oz - RD$5000" << endl;
    cout << "2. Armani Acqua di Gio 3.4 oz - RD$7500" << endl;
    cout << "3. Dolce Gabbana Light Blue 4.2 oz - RD$4200" << endl;
    cout << "4. Nautica Voyage 3.4 oz - RD$2500" << endl;
    cout << "5. Valentino Born in Roma 3.4 oz - RD$6500" << endl;
}

// Funcion que procesa el pedido del cliente
void entregarPedido(int opcion) {

    switch (opcion) {

        case 1:
            cout << "Aqui esta su pedido: One Million 3.4 oz"
                 << endl;
            break;

        case 2:
            cout << "Aqui esta su pedido: Armani Acqua di Gio 3.4 oz"
                 << endl;
            break;

        case 3:
            cout << "Aqui esta su pedido: Dolce Gabbana Light Blue 4.2 oz"
                 << endl;
            break;

        case 4:
            cout << "Aqui esta su pedido: Nautica Voyage 3.4 oz"
                 << endl;
            break;

        case 5:
            cout << "Aqui esta su pedido: Valentino Born in Roma 3.4 oz"
                 << endl;
            break;

        default:
            cout << "Opcion invalida. Seleccione del 1 al 5."
                 << endl;
            break;
    }
}
```

### ¿Qué mejoramos?

- Eliminamos `struct` y `vector`, que no eran requisitos.
- Creamos tres funciones con responsabilidades claras.
- Utilizamos prototipos para poder definir las funciones después de `main()`.
- Enviamos la opción a una función mediante un parámetro.
- Simplificamos `main()`.
- Eliminamos el `case 0` vacío, porque el menú solicitado solo tiene opciones del 1 al 5.

No agregué todavía un ciclo para repetir el menú porque no formaba parte de este primer enunciado. Eso podemos incorporarlo cuando veamos las nuevas instrucciones del profesor.

## 5. Lo que debes entender de esta nueva organización

### A. `mostrarNegocio()`

```cpp
void mostrarNegocio() {
    cout << "ACCESORIOS MASHIAJ" << endl;
}
```

Es una función `void` sin parámetros.

No recibe información ni devuelve resultados.

Su responsabilidad es presentar el negocio.

### B. `mostrarMenu()`

```cpp
void mostrarMenu() {
    cout << "1. One Million - RD$5000" << endl;
    cout << "2. Armani Acqua di Gio - RD$7500" << endl;
}
```

También es una función `void` sin parámetros.

Se encarga exclusivamente de mostrar los productos disponibles.

Esta función será muy útil en el examen final, porque si el profesor agrega opciones al menú, sabremos exactamente dónde realizar los cambios.

### C. `entregarPedido(int opcion)`

```cpp
void entregarPedido(int opcion) {
    switch (opcion) {
        // Procesar la seleccion
    }
}
```

Aquí aparece algo importante.

La función recibe un parámetro:

```cpp
int opcion
```

Cuando desde `main()` escribimos:

```cpp
entregarPedido(opcion);
```

Le estamos enviando la opción seleccionada por el usuario.

Por ejemplo:

```cpp
entregarPedido(3);
```

La función recibe el número 3 y ejecuta el `case 3`.

Esto es paso por valor, que es lo que has estado practicando. No necesitamos paso por referencia porque la función no necesita modificar la variable original.

## 6. ¿Cómo decidir qué funciones crear durante un examen?

Quiero que utilices este pequeño método cada vez que el profesor te dé un enunciado.

Primero, subraya las acciones que te está pidiendo.

En tu enunciado aparecían:

- Mostrar el negocio.
- Mostrar los productos.
- Seleccionar un producto.
- Entregar el pedido.

Después identifica cuáles de esas acciones merecen convertirse en una función.

| Acción del enunciado            | Solución                 |
| ------------------------------- | ------------------------ |
| Mostrar nombre y detalles       | `mostrarNegocio()`       |
| Mostrar menú de productos       | `mostrarMenu()`          |
| Recibir la selección            | `cin` dentro de `main()` |
| Determinar qué pidió el usuario | `entregarPedido(opcion)` |
| Coordinar todo                  | `main()`                 |

Esto evita que te bloquees intentando inventar funciones cuando tengas poco tiempo.

### Y una regla todavía más importante

Antes de escribir una función, responde estas tres preguntas:

1\. ¿Qué hará?

Ejemplo: mostrar el menú.

2\. ¿Necesita recibir datos?

No. Entonces no necesita parámetros.

3\. ¿Necesita devolver algún resultado?

No. Entonces utilizamos `void`.

Ahora aplica las mismas preguntas a `entregarPedido()`:

- ¿Qué hará? Mostrar el producto elegido.
- ¿Necesita recibir datos? Sí, la opción seleccionada.
- ¿Necesita devolver un resultado? No, solamente muestra un mensaje.

Por eso su declaración es:

```cpp
void entregarPedido(int opcion);
```

## 7. Pensando en el examen final

Ahora que sabemos que el profesor quiere continuar desarrollando este mismo programa durante las próximas clases, debemos conservar una estructura sencilla que permita agregar funcionalidades progresivamente.

No vamos a complicarlo desde ahora con clases, bases de datos, vectores o elementos que todavía no sean necesarios.

Conservaremos una versión inicial y, cada vez que llegue un nuevo mandato, evaluaremos qué partes modificar.

Por ejemplo, si después pide calcular el ITBIS, podremos crear una función de cálculo. Si pide repetir compras, podremos incorporar un `do-while`. Si pide manejar muchos productos o inventario, ahí sí evaluaremos estructuras y vectores.

Lo importante será que cada cambio responda a un requisito real del profesor.

Quiero destacar algo de tu parcial: ya demostraste que sabes crear estructuras, llenar vectores, recorrerlos con ciclos, mostrar tablas y utilizar `switch`. Lo que más necesitas fortalecer ahora no es escribir más sintaxis, sino aprender a analizar un enunciado y diseñar funciones antes de comenzar a programar.

Esa será nuestra prioridad mientras desarrollamos el proyecto final de Accesorios Mashiaj.

Cuando me envíes la continuación del mandato, la analizaremos tomando este primer programa como base y respetando lo que el profesor vaya exigiendo.

¡Excelente! Ya vi cómo quedó en tu terminal. El programa funciona correctamente. Ahora vamos a mejorar la presentación para que parezca el menú de una perfumería, con los nombres alineados a la izquierda y los precios organizados en una columna a la derecha.

Vamos a utilizar `setw()`, `left`, `right`, `fixed` y `setprecision(2)`, que son conceptos que ya hemos trabajado en la universidad.

No vamos a agregar vectores ni estructuras. Mantendremos las tres funciones que organizamos para el examen final.

## 1. Así quedará el menú

```
===============================================================
                       ACCESORIOS MASHIAJ
                     Tu perfumeria preferida
===============================================================

                      MENU DE PERFUMES

----------------------------------------------------------------
 Opcion  Perfume                                      Precio RD$
----------------------------------------------------------------
 1       One Million 3.4 oz                            5000.00
 2       Armani Acqua di Gio 3.4 oz                     7500.00
 3       Dolce Gabbana Light Blue 4.2 oz                4200.00
 4       Nautica Voyage 3.4 oz                          2500.00
 5       Valentino Born in Roma 3.4 oz                  6500.00
----------------------------------------------------------------

Seleccione una opcion (1-5): 4

Aqui esta su pedido: Nautica Voyage 3.4 oz
```

## 2. Código completo actualizado — `AccMash.cpp`

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

// Prototipos de las funciones
void mostrarNegocio();
void mostrarMenu();
void entregarPedido(int opcion);

int main() {

    int opcion;

    mostrarNegocio();

    mostrarMenu();

    cout << "\nSeleccione una opcion (1-5): ";
    cin >> opcion;

    entregarPedido(opcion);

    return 0;
}

// Funcion que muestra el nombre y detalles del negocio
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

    cout << "----------------------------------------------------------------" << endl;

    cout << left
         << setw(9) << " Opcion"
         << setw(44) << "Perfume"
         << right << setw(11) << "Precio RD$"
         << endl;

    cout << "----------------------------------------------------------------" << endl;

    cout << left
         << setw(9) << " 1"
         << setw(44) << "One Million 3.4 oz"
         << right << setw(11) << 5000.00
         << endl;

    cout << left
         << setw(9) << " 2"
         << setw(44) << "Armani Acqua di Gio 3.4 oz"
         << right << setw(11) << 7500.00
         << endl;

    cout << left
         << setw(9) << " 3"
         << setw(44) << "Dolce Gabbana Light Blue 4.2 oz"
         << right << setw(11) << 4200.00
         << endl;

    cout << left
         << setw(9) << " 4"
         << setw(44) << "Nautica Voyage 3.4 oz"
         << right << setw(11) << 2500.00
         << endl;

    cout << left
         << setw(9) << " 5"
         << setw(44) << "Valentino Born in Roma 3.4 oz"
         << right << setw(11) << 6500.00
         << endl;

    cout << "----------------------------------------------------------------" << endl;
}

// Funcion que entrega el pedido del cliente
void entregarPedido(int opcion) {

    switch (opcion) {

        case 1:
            cout << "\nAqui esta su pedido: One Million 3.4 oz"
                 << endl;
            break;

        case 2:
            cout << "\nAqui esta su pedido: Armani Acqua di Gio 3.4 oz"
                 << endl;
            break;

        case 3:
            cout << "\nAqui esta su pedido: Dolce Gabbana Light Blue 4.2 oz"
                 << endl;
            break;

        case 4:
            cout << "\nAqui esta su pedido: Nautica Voyage 3.4 oz"
                 << endl;
            break;

        case 5:
            cout << "\nAqui esta su pedido: Valentino Born in Roma 3.4 oz"
                 << endl;
            break;

        default:
            cout << "\nOpcion invalida. Seleccione del 1 al 5."
                 << endl;
            break;
    }
}
```

## 3. ¿Qué modificamos y cómo funciona?

La mayor parte del programa permanece igual. Los cambios están concentrados en `mostrarMenu()`.

### A. La biblioteca `<iomanip>`

```cpp
#include <iomanip>
```

Nos permite utilizar herramientas para dar formato a la salida.

### B. El uso de `setw()`

Observa:

```cpp
cout << left
     << setw(9) << " 1"
     << setw(44) << "One Million 3.4 oz"
     << right << setw(11) << 5000.00
     << endl;
```

Cada instrucción tiene una responsabilidad:

| Instrucción | Función                                                   |
| ----------- | --------------------------------------------------------- |
| `left`      | Alinea los campos siguientes hacia la izquierda.          |
| `setw(9)`   | Reserva un ancho mínimo de 9 caracteres para la opción.   |
| `setw(44)`  | Reserva un ancho mínimo de 44 caracteres para el perfume. |
| `right`     | Alinea el precio a la derecha.                            |
| `setw(11)`  | Reserva un ancho mínimo de 11 caracteres para el precio.  |

Importante: `setw()` afecta únicamente al siguiente valor que imprimimos, mientras que `left` y `right` permanecen activos hasta que los cambiamos.

Por eso escribimos `left` nuevamente en cada fila: la fila anterior terminó utilizando `right`.

### C. Formato de los precios

```cpp
cout << fixed << setprecision(2);
```

Permite mostrar:

```cpp
5000.00
7500.00
4200.00
```

En vez de:

```cpp
5000
7500
4200
```

### D. ¿Por qué dejamos los productos escritos directamente?

Porque es lo que corresponde a esta primera parte del proyecto.

El profesor todavía no pidió inventario, registros ni cantidades variables de productos. Por eso mostrar cinco perfumes directamente con `cout` es suficiente.

Cuando lleguen las siguientes funcionalidades, podremos agregar lo que realmente necesitemos.

## 4. Cómo probarlo

En tu Mac, desde la carpeta del programa:

```cpp
clang++ -std=c++17 AccMash.cpp -o AccMash
./AccMash
```

Prueba las cinco opciones y también un número inválido, como `8`.

Esta será nuestra versión base de Accesorios Mashiaj para continuar el proyecto final. Con ella tenemos el código organizado en funciones, un menú bien alineado y únicamente las herramientas necesarias para cumplir el primer mandato del profesor.

Perfecto. Vamos a colocar separadores verticales `|` entre Opción, Perfume y Precio, manteniendo `setw()` para que todas las columnas queden alineadas.

Así se verá:

```cpp
+--------+------------------------------------------+------------+
| Opcion | Perfume                                  | Precio RD$ |
+--------+------------------------------------------+------------+
| 1      | One Million 3.4 oz                       |    5000.00 |
| 2      | Armani Acqua di Gio 3.4 oz               |    7500.00 |
| 3      | Dolce Gabbana Light Blue 4.2 oz          |    4200.00 |
| 4      | Nautica Voyage 3.4 oz                    |    2500.00 |
| 5      | Valentino Born in Roma 3.4 oz            |    6500.00 |
+--------+------------------------------------------+------------+
```

## Código completo actualizado — `AccMash.cpp`

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

// Prototipos de las funciones
void mostrarNegocio();
void mostrarMenu();
void entregarPedido(int opcion);

int main() {

    int opcion;

    mostrarNegocio();
    mostrarMenu();

    cout << "\nSeleccione una opcion (1-5): ";
    cin >> opcion;

    entregarPedido(opcion);

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

    cout << "| " << left << setw(6) << "1"
         << " | " << setw(40) << "One Million 3.4 oz"
         << " | " << right << setw(10) << 5000.00
         << " |" << endl;

    cout << "| " << left << setw(6) << "2"
         << " | " << setw(40) << "Armani Acqua di Gio 3.4 oz"
         << " | " << right << setw(10) << 7500.00
         << " |" << endl;

    cout << "| " << left << setw(6) << "3"
         << " | " << setw(40) << "Dolce Gabbana Light Blue 4.2 oz"
         << " | " << right << setw(10) << 4200.00
         << " |" << endl;

    cout << "| " << left << setw(6) << "4"
         << " | " << setw(40) << "Nautica Voyage 3.4 oz"
         << " | " << right << setw(10) << 2500.00
         << " |" << endl;

    cout << "| " << left << setw(6) << "5"
         << " | " << setw(40) << "Valentino Born in Roma 3.4 oz"
         << " | " << right << setw(10) << 6500.00
         << " |" << endl;

    cout << "+--------+------------------------------------------+------------+" << endl;
}

// Funcion que entrega el pedido del cliente
void entregarPedido(int opcion) {

    switch (opcion) {

        case 1:
            cout << "\nAqui esta su pedido: One Million 3.4 oz"
                 << endl;
            break;

        case 2:
            cout << "\nAqui esta su pedido: Armani Acqua di Gio 3.4 oz"
                 << endl;
            break;

        case 3:
            cout << "\nAqui esta su pedido: Dolce Gabbana Light Blue 4.2 oz"
                 << endl;
            break;

        case 4:
            cout << "\nAqui esta su pedido: Nautica Voyage 3.4 oz"
                 << endl;
            break;

        case 5:
            cout << "\nAqui esta su pedido: Valentino Born in Roma 3.4 oz"
                 << endl;
            break;

        default:
            cout << "\nOpcion invalida. Seleccione del 1 al 5."
                 << endl;
            break;
    }
}
```

## ¿Qué cambiamos?

Ahora cada fila contiene tres columnas separadas por `|`:

```cpp
cout << "| " << left << setw(6) << "1"
     << " | " << setw(40) << "One Million 3.4 oz"
     << " | " << right << setw(10) << 5000.00
     << " |" << endl;
```

- `setw(6)`: espacio para la opción.
- `setw(40)`: espacio para el nombre del perfume.
- `setw(10)`: espacio para el precio.
- `left`: alinea los nombres a la izquierda.
- `right`: alinea los precios a la derecha.
- `" | "`: crea las divisiones verticales.

Las líneas con `+` y `-` forman los bordes horizontales y conectan con las divisiones verticales.

No cambiamos ninguna funcionalidad del programa. Solo mejoramos la presentación del menú, conservando las tres funciones y el `switch` que necesita el proyecto.
