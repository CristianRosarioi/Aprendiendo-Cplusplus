# Unidad VII — Operaciones con archivos en C++

INF510 · Introducción a la Programación · UASD · Profesor Brito

¡Llegamos a la Unidad VII! Y esta unidad conecta directamente con lo que estamos haciendo en el proyecto final de Accesorios Mashiaj.

Revisé los tres materiales que compartiste:

- 7 — Operaciones con Archivos: 53 páginas, de Félix Ferreiras y Zobiesky Ovalle.
- INF510 tema XIII — Procesamiento de Archivos en C++: 107 diapositivas.
- Material Complementario — Archivos y DBMS: 22 páginas.

Los tres materiales se complementan: el primero explica las operaciones de archivos, la presentación ofrece ejemplos prácticos y el tercero compara los sistemas basados en archivos con los gestores de bases de datos.

Vamos a preparar un resumen completo para guardar en Markdown (`UNIDAD_7_OPERACIONES_ARCHIVOS.md`), como hemos hecho con las unidades anteriores.

## 1. ¿Qué aprenderemos en la Unidad VII?

Según los objetivos del material principal, aprenderemos a escribir y leer archivos de texto, trabajar con archivos binarios, crear registros mediante estructuras, realizar accesos aleatorios y utilizar archivos como argumentos de funciones.

| Tema                              | Qué aprenderemos                                             | Prioridad de estudio |
| --------------------------------- | ------------------------------------------------------------ | -------------------- |
| Archivos y persistencia           | Guardar información que no desaparezca al cerrar el programa | Fundamental          |
| `<fstream>`                       | Abrir, escribir, leer y cerrar archivos                      | Fundamental          |
| `ios::out`, `ios::in`, `ios::app` | Elegir cómo trabajar con el archivo                          | Fundamental          |
| `<<`, `>>`, `getline()`           | Escribir y recuperar información                             | Fundamental          |
| `get()`, `put()`                  | Procesar caracteres individuales                             | Alta                 |
| Archivos binarios                 | Guardar y recuperar bloques de bytes                         | Alta                 |
| Estructuras y registros           | Guardar datos organizados                                    | Alta                 |
| `seekg()`, `seekp()`              | Moverse dentro de un archivo                                 | Alta                 |
| `tellg()`, `tellp()`              | Consultar posiciones de lectura y escritura                  | Media                |
| Archivos en funciones             | Enviar un flujo mediante referencia                          | Alta                 |
| DBMS                              | Entender la diferencia entre archivos y bases de datos       | Conceptual           |

La prioridad es mi propuesta para estudiar, no una distribución oficial de calificaciones.

## 2. ¿Qué es un archivo y por qué lo necesitamos?

Un archivo es un conjunto de información almacenada en un dispositivo, identificado normalmente por un nombre y una extensión.

Por ejemplo:

```cpp
cliente.txt
recibo.txt
productos.dat
empleados.bin
```

Hasta ahora utilizábamos variables, arreglos, vectores y estructuras para almacenar los datos mientras el programa estaba ejecutándose.

El problema es que, al terminar el programa, esos datos almacenados solamente en memoria dejan de estar disponibles.

### Antes: información temporal

```cpp
string cliente = "Juan Perez";
double total = 5000;
```

Esos datos existen durante la ejecución del programa, pero no se conservan automáticamente cuando termina.

### Ahora: información persistente

```cpp
fstream archivo("cliente.txt", ios::out);

archivo << "Juan Perez" << endl;

archivo.close();
```

Ahora podemos conservar el nombre en un archivo y recuperarlo posteriormente.

Diferencia entre memoria y almacenamiento

Memoria RAM

Variables, arreglos y estructuras durante la ejecución

Los datos temporales se pierden al finalizar

Almacenamiento

Archivos guardados en disco o SSD

Los datos permanecen guardados

Concepto que debes memorizar: persistencia de datos.

Es la capacidad de conservar información para volver a utilizarla después, incluso en otra ejecución del programa.

## 3. ¿Qué es `<fstream>`?

`<fstream>` es la biblioteca estándar de C++ que permite trabajar con archivos mediante flujos de entrada y salida.

```cpp
#include <fstream>
```

En esta unidad encontramos tres clases principales:

| Clase      | Para qué se utiliza                                 |
| ---------- | --------------------------------------------------- |
| `ifstream` | Leer archivos                                       |
| `ofstream` | Escribir archivos                                   |
| `fstream`  | Leer y escribir archivos, según el modo de apertura |

El profesor trabaja principalmente con `fstream`, por eso nosotros también lo utilizaremos en los ejemplos.

### ¿Qué es un flujo?

Un flujo (stream) es un mecanismo que permite transferir información entre un programa y un destino u origen.

Por ejemplo:

```cpp
cout << "Hola";
```

Escribe en la salida estándar, normalmente la terminal.

Mientras que:

```cpp
archivo << "Hola";
```

Escribe en un archivo abierto para salida.

De manera parecida:

```cpp
cin >> numero;
```

Recibe datos desde la entrada estándar.

Y:

```cpp
archivo >> numero;
```

Extrae datos de un archivo abierto para lectura.

La idea fundamental es que la sintaxis resulta familiar porque trabajamos con flujos en ambos casos.

## 4. Los cinco pasos para trabajar con un archivo

El PDF principal explica cinco pasos: declarar una variable de archivo, asociarla con un archivo físico, abrirlo, utilizarlo y cerrarlo.

En C++ podemos asociar y abrir el archivo en una sola instrucción.

### Ejemplo básico

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    fstream archivo("datos.txt", ios::out);

    archivo << "Hola desde C++" << endl;

    archivo.close();

    return 0;
}
```

### Explicación

```cpp
fstream archivo("datos.txt", ios::out);
```

Crea un flujo llamado `archivo`, asociado a `datos.txt`, en modo escritura.

```cpp
archivo << "Hola desde C++" << endl;
```

Escribe una línea en el archivo.

```cpp
archivo.close();
```

Cierra el archivo.

El contenido resultante será:

```cpp
Hola desde C++
```

También podemos abrir el archivo por separado:

```cpp
fstream archivo;

archivo.open("datos.txt", ios::out);

// Escribir informacion

archivo.close();
```

Las dos formas son válidas.

## 5. Modos de apertura de archivos

Este es uno de los temas más importantes para el parcial y el examen final.

| Modo          | Significado | Comportamiento                                             |
| ------------- | ----------- | ---------------------------------------------------------- |
| `ios::in`     | Input       | Abre para lectura                                          |
| `ios::out`    | Output      | Abre para escritura, normalmente reemplazando el contenido |
| `ios::app`    | Append      | Agrega información al final                                |
| `ios::trunc`  | Truncate    | Descarta el contenido anterior                             |
| `ios::ate`    | At end      | Posiciona inicialmente el flujo al final                   |
| `ios::binary` | Binary      | Utiliza modo binario                                       |

El material también menciona `ios::nocreate` y `ios::noreplace`. Esos indicadores aparecen en ejemplos de compiladores antiguos, pero no pertenecen al conjunto de modos portables que utilizamos con C++17. Conviene reconocerlos cuando leas las diapositivas, sin copiarlos directamente a nuestros programas.

### Diferencia entre `ios::out` e `ios::app`

¿Qué pasa con un archivo que ya contiene información?

ios::outios::app

ventas.txt — antes

Venta 1: RD$5,000

Escribimos: Venta 2: RD$7,500

ventas.txt — después

Venta 2: RD$7,500

La compra anterior se reemplaza por la nueva.

Esto ya lo aplicamos en tu perfumería:

```cpp
fstream archivo("recibo.txt", ios::out);
```

Porque el profesor quiere que `recibo.txt` conserve solamente la factura de la compra más reciente.

Una advertencia: `ios::ate` no significa exactamente lo mismo que `ios::app`. El primero posiciona inicialmente el flujo al final; el segundo obliga a que las escrituras se agreguen al final. Esa distinción será importante cuando estudiemos acceso aleatorio.

## 6. Escribir archivos de texto

En la presentación del profesor aparecen ejemplos utilizando `<<` y `put()`.

Son dos formas diferentes de escribir información.

### Ejemplo 1 — Escribir información con `<<`

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    fstream archivo("estudiante.txt", ios::out);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    archivo << "Nombre: Juan Perez" << endl;
    archivo << "Edad: 20" << endl;
    archivo << "Nota: 90" << endl;

    archivo.close();

    cout << "Datos guardados correctamente" << endl;

    return 0;
}
```

El resultado dentro de `estudiante.txt` será:

```cpp
Nombre: Juan Perez
Edad: 20
Nota: 90
```

¿Por qué utilizamos `<<`?

Porque queremos escribir textos y números con formato, de manera similar a `cout`.

### Ejemplo 2 — Escribir caracteres con `put()`

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    char letra;

    fstream archivo("letras.txt", ios::out);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    cout << "Introduzca una letra: ";
    cin >> letra;

    archivo.put(letra);

    archivo.close();

    return 0;
}
```

La instrucción fundamental es:

```cpp
archivo.put(letra);
```

Inserta un carácter en el archivo.

Si el usuario introduce `A`, el archivo contendrá:

```cpp
A
```

### Diferencia

- `archivo << "Hola";` escribe texto utilizando salida formateada.
- `archivo.put('H');` escribe un carácter.

## 7. Leer archivos de texto

Ahora vamos a recuperar información que ya existe en un archivo.

Para eso utilizamos:

```cpp
ios::in
```

El material presenta diferentes maneras de leer: `>>`, `get()` y `getline()`.

### Ejemplo 3 — Leer un archivo completo línea por línea

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    fstream archivo("estudiante.txt", ios::in);

    string linea;

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }

    while (getline(archivo, linea)) {

        cout << linea << endl;
    }

    archivo.close();

    return 0;
}
```

### ¿Qué hace `getline()`?

```cpp
getline(archivo, linea)
```

Intenta leer una línea completa del archivo y guardarla en la variable `linea`.

Por ejemplo, si el archivo contiene:

```cpp
Nombre: Juan Perez
Edad: 20
Nota: 90
```

El ciclo se ejecutará tres veces:

| Vuelta | Contenido de `linea` |
| ------ | -------------------- |
| 1      | `Nombre: Juan Perez` |
| 2      | `Edad: 20`           |
| 3      | `Nota: 90`           |

### ¿Por qué utilizamos `while`?

```cpp
while (getline(archivo, linea))
```

Porque no sabemos necesariamente cuántas líneas tiene el archivo.

El ciclo continuará mientras pueda leer una línea correctamente.

Cuando se acaben los datos, finalizará.

Algo importante del material: el profesor también enseña `eof()`, que permite consultar el estado de fin de archivo. Sin embargo, para recorrer líneas es preferible escribir `while (getline(archivo, linea))` en lugar de `while (!archivo.eof())`, porque comprobamos directamente que cada lectura haya funcionado.

### Diferencias entre los métodos de lectura

| Instrucción               | ¿Qué lee?                                                |
| ------------------------- | -------------------------------------------------------- |
| `archivo >> dato`         | Un dato formateado; normalmente se detiene ante espacios |
| `archivo.get(c)`          | Un carácter, incluyendo espacios y saltos de línea       |
| `getline(archivo, linea)` | Una línea completa                                       |

Por ejemplo, para recuperar un nombre completo como `Juan Carlos Perez`, es más práctico utilizar `getline()` que `>>`.

## 8. Verificar errores y cerrar archivos

El material también explica que abrir un archivo puede fallar.

Por ejemplo, porque:

- El archivo de lectura no existe.
- No tenemos permisos suficientes.
- La ruta indicada es incorrecta.
- Existe un problema con el dispositivo.

Por eso verificamos la apertura:

```cpp
fstream archivo("datos.txt", ios::in);

if (!archivo.is_open()) {
    cout << "Error al abrir el archivo" << endl;
    return 1;
}
```

Otro método que aparece en el material es:

```cpp
if (archivo.fail()) {
    cout << "Error" << endl;
}
```

`fail()` permite consultar si el flujo se encuentra en estado de fallo.

Y cuando terminamos:

```cpp
archivo.close();
```

Cerramos el archivo.

### ¿Dónde se guarda un archivo?

Si escribimos:

```cpp
fstream archivo("datos.txt", ios::out);
```

El archivo se crea en el directorio de trabajo actual.

Pero también podemos indicar una ruta, como explican las diapositivas:

```cpp
fstream archivo("/home/usuario/datos.txt", ios::out);
```

Si el directorio de destino no existe o no tenemos permisos para escribir, la apertura fallará.

# Parte II — Archivos binarios

## 9. ¿Qué diferencia existe entre un archivo de texto y uno binario?

El material distingue los archivos de texto de los archivos binarios.

Archivo de texto: contiene información representada mediante caracteres de una codificación. Podemos abrirlo con un editor y leerlo.

Archivo binario: guarda bytes según un formato determinado, que no necesariamente está pensado para mostrarse como texto.

| Característica              | Texto `.txt`               | Binario `.bin` o `.dat`                   |
| --------------------------- | -------------------------- | ----------------------------------------- |
| Lectura con Bloc de notas   | Normalmente comprensible   | Puede mostrar caracteres extraños         |
| Forma habitual de escritura | `<<`, `put()`              | `write()`                                 |
| Forma habitual de lectura   | `>>`, `getline()`, `get()` | `read()`                                  |
| Almacenamiento de números   | Como caracteres            | Puede almacenar su representación binaria |
| Registros de tamaño fijo    | Posibles                   | Muy utilizados para acceso aleatorio      |

Una precisión: la extensión no determina por sí sola el formato interno. Y aunque el material enfatiza los registros binarios de longitud fija, no todos los formatos binarios tienen necesariamente registros fijos.

## 10. Escribir y leer un número en formato binario

El PDF y la presentación explican las funciones:

```cpp
archivo.write(direccion, tamano);
archivo.read(direccion, tamano);
```

Estas funciones trabajan con bloques de bytes.

### Ejemplo 4 — Guardar y recuperar un `double`

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    double precio = 2500.50;
    double recuperado = 0;

    // Escribir el numero
    fstream archivo("precio.bin", ios::out | ios::binary);

    if (!archivo.is_open()) {
        cout << "Error al crear el archivo" << endl;
        return 1;
    }

    archivo.write(
        reinterpret_cast<char*>(&precio),
        sizeof(precio)
    );

    archivo.close();

    // Leer el numero
    archivo.open("precio.bin", ios::in | ios::binary);

    if (!archivo.is_open()) {
        cout << "Error al leer el archivo" << endl;
        return 1;
    }

    archivo.read(
        reinterpret_cast<char*>(&recuperado),
        sizeof(recuperado)
    );

    if (archivo) {
        cout << "Precio recuperado: " << recuperado << endl;
    }

    archivo.close();

    return 0;
}
```

### ¿Qué hace `write()`?

```cpp
archivo.write(
    reinterpret_cast<char*>(&precio),
    sizeof(precio)
);
```

La función necesita saber dos cosas:

- Dirección: dónde se encuentra el dato que queremos guardar.
- Tamaño: cuántos bytes debemos escribir.

`&precio` obtiene la dirección de la variable.

`reinterpret_cast<char*>` permite presentar esa dirección como un puntero a bytes para la operación.

`sizeof(precio)` obtiene el tamaño del dato en bytes.

La función `read()` realiza el proceso contrario: recupera los bytes y los coloca en la variable destino.

### ¿Por qué se relaciona esto con la Unidad VI?

Porque necesitamos comprender punteros y direcciones de memoria para entender de dónde salen los bytes que se escriben y dónde se almacenan los bytes que se leen.

También es importante saber que este formato binario directo puede depender del equipo y del compilador. Por tanto, es apropiado para estudiar la técnica, pero no necesariamente para intercambiar archivos entre sistemas diferentes.

## 11. Guardar registros utilizando estructuras

Aquí aparece una relación con la Unidad IV, donde estudiamos `struct`.

El PDF explica que podemos utilizar estructuras para representar registros y guardarlos en archivos binarios.

Por ejemplo:

```cpp
struct Empleado {
    char nombre[30];
    int edad;
    double salario;
};
```

### Ejemplo 5 — Guardar una estructura

```cpp
#include <iostream>
#include <fstream>
using namespace std;

struct Empleado {
    char nombre[30];
    int edad;
    double salario;
};

int main() {

    Empleado empleado = {"Juan", 25, 35000.00};

    fstream archivo("empleado.bin", ios::out | ios::binary);

    if (!archivo.is_open()) {
        cout << "Error al abrir archivo" << endl;
        return 1;
    }

    archivo.write(
        reinterpret_cast<char*>(&empleado),
        sizeof(empleado)
    );

    archivo.close();

    cout << "Empleado guardado correctamente" << endl;

    return 0;
}
```

¿Qué sucede aquí?

En lugar de escribir el nombre, la edad y el salario uno por uno como texto, guardamos los bytes de la estructura completa.

Una advertencia importante: para esta técnica hemos utilizado `char nombre[30]` en vez de `string nombre`. No debemos guardar directamente los bytes de una estructura que contenga `std::string` y esperar poder recuperarla correctamente de esa manera, porque `string` administra recursos internos.

Este ejemplo sigue el enfoque de registros con campos de tamaño fijo que presenta el material.

# Parte III — Acceso aleatorio a archivos

## 12. ¿Qué significa acceso secuencial y acceso aleatorio?

El PDF dedica una sección completa a este tema.

### Acceso secuencial

Significa leer información siguiendo el orden del archivo.

Por ejemplo:

```cpp
Registro 1 → Registro 2 → Registro 3 → Registro 4
```

Si queremos llegar al registro 4 mediante lectura secuencial, normalmente tenemos que pasar por los anteriores.

### Acceso aleatorio

Significa movernos directamente a una posición específica del archivo.

Por ejemplo, podemos ir a los bytes correspondientes al tercer registro sin tener que procesar los dos anteriores.

Diferencia entre los dos tipos de acceso

Acceso secuencial

R1

R2

R3

R4

R5

Acceso aleatorio

## 13. Funciones de acceso aleatorio

El profesor presenta cuatro funciones fundamentales:

| Función   | Qué hace                                 |
| --------- | ---------------------------------------- |
| `seekg()` | Mueve la posición de lectura             |
| `seekp()` | Mueve la posición de escritura           |
| `tellg()` | Devuelve la posición actual de lectura   |
| `tellp()` | Devuelve la posición actual de escritura |

Una manera sencilla de recordar los nombres:

- g viene de get, leer.
- p viene de put, escribir.
- seek significa buscar o posicionarse.
- tell significa informar una posición.

### Posiciones de referencia

| Indicador  | Significado              |
| ---------- | ------------------------ |
| `ios::beg` | Desde el comienzo        |
| `ios::cur` | Desde la posición actual |
| `ios::end` | Desde el final           |

Por ejemplo:

```cpp
archivo.seekg(0, ios::beg);
```

Mueve la posición de lectura al principio.

```cpp
archivo.seekp(0, ios::end);
```

Mueve la posición de escritura al final.

### Ejemplo 6 — Leer directamente el tercer número

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    int numeros[3] = {10, 20, 30};

    fstream archivo("numeros.bin", ios::out | ios::binary);

    archivo.write(
        reinterpret_cast<char*>(numeros),
        sizeof(numeros)
    );

    archivo.close();

    archivo.open("numeros.bin", ios::in | ios::binary);

    // Ir directamente al tercer entero
    archivo.seekg(2 * sizeof(int), ios::beg);

    int numero = 0;

    archivo.read(
        reinterpret_cast<char*>(&numero),
        sizeof(numero)
    );

    cout << "Tercer numero: " << numero << endl;

    archivo.close();

    return 0;
}
```

Resultado:

```cpp
Tercer numero: 30
```

### ¿Por qué `2 * sizeof(int)`?

Porque queremos el tercer elemento, que tiene índice 2.

Si un `int` ocupa cuatro bytes en ese equipo, los datos estarían organizados de esta manera:

| Elemento | Desplazamiento |
| -------- | -------------- |
| 10       | Byte 0         |
| 20       | Byte 4         |
| 30       | Byte 8         |

Entonces:

```
archivo.seekg(2 * sizeof(int), ios::beg);
```

Nos lleva directamente al comienzo del tercer entero.

Importante: este puntero de posición del archivo no es exactamente el mismo concepto que un `int*` de la Unidad VI. Aquí hablamos de una posición dentro de un flujo de archivo, no de una dirección de memoria RAM.

# Parte IV — Archivos y funciones

## 14. Enviar un archivo como argumento de una función

Este tema es importante porque conecta la Unidad VII con la Unidad V, cuando aprendimos a crear funciones.

Hasta ahora hemos utilizado funciones como:

```cpp
double calcularITBIS(double subtotal);
```

Ahora podemos crear funciones que reciban un archivo.

El material presenta esta forma:

```cpp
void escribirDatos(fstream &archivo);
```

Observa el símbolo `&`.

### ¿Por qué necesitamos paso por referencia?

Los objetos `fstream` no se pueden copiar como variables numéricas normales.

Por eso, si queremos que varias funciones trabajen con el mismo flujo, podemos enviarlo por referencia.

### Ejemplo 7 — Una función que recibe un archivo

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Prototipo
void escribirNombre(fstream &archivo, string nombre);

int main() {

    string nombre;

    cout << "Introduzca su nombre: ";
    getline(cin, nombre);

    fstream archivo("nombres.txt", ios::out);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    escribirNombre(archivo, nombre);

    archivo.close();

    return 0;
}

// Funcion que escribe en el archivo
void escribirNombre(fstream &archivo, string nombre) {

    archivo << "Nombre: " << nombre << endl;
}
```

### ¿Cuál es la lógica?

`main()` abre el archivo.

Después llama a:

```cpp
escribirNombre(archivo, nombre);
```

La función recibe el mismo flujo y escribe la información.

Finalmente, `main()` cierra el archivo.

Esto resulta útil cuando necesitamos organizar un programa grande en varias funciones que comparten un archivo abierto.

## 15. Utilizar varios archivos en un mismo programa

El material principal también explica que podemos abrir distintos archivos simultáneamente.

Esto ya lo estamos haciendo conceptualmente en nuestro proyecto de perfumería.

Tenemos:

```cpp
cliente.txt
recibo.txt
```

Podemos trabajar con ambos desde un mismo programa:

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    fstream cliente("cliente.txt", ios::out);
    fstream recibo("recibo.txt", ios::out);

    if (!cliente.is_open() || !recibo.is_open()) {
        cout << "Error al abrir uno de los archivos" << endl;
        return 1;
    }

    cliente << "Juan Perez" << endl;

    recibo << "Cliente: Juan Perez" << endl;
    recibo << "Total: RD$5000" << endl;

    cliente.close();
    recibo.close();

    return 0;
}
```

Cada objeto `fstream` está asociado a un archivo diferente.

Por eso podemos guardar información distinta en cada uno.

# Parte V — Sistemas basados en archivos y DBMS

## 16. ¿Qué es un sistema basado en archivos?

El material complementario explica que un sistema basado en archivos es un conjunto de archivos creados por las aplicaciones para resolver sus necesidades de almacenamiento.

Por ejemplo, imaginemos una perfumería que utiliza:

```cpp
clientes.txt
productos.txt
ventas.txt
facturas.txt
```

Cada archivo almacena un tipo de información.

Este enfoque puede funcionar para programas pequeños, especialmente como los ejercicios que desarrollamos en Introducción a la Programación.

Pero también tiene limitaciones.

## 17. Problemas de los sistemas basados en archivos

El material complementario menciona varios inconvenientes.

| Problema                    | Ejemplo en un negocio                                                           |
| --------------------------- | ------------------------------------------------------------------------------- |
| Redundancia                 | El nombre del cliente aparece repetido en varios archivos                       |
| Inconsistencia              | El mismo cliente tiene dos teléfonos distintos en diferentes archivos           |
| Dependencia física y lógica | Cambiar el formato del archivo obliga a modificar el programa                   |
| Dificultad de consulta      | Buscar todas las compras de un cliente puede requerir recorrer muchos registros |
| Aislamiento de datos        | La información está distribuida en archivos distintos                           |
| Acceso concurrente          | Dos usuarios podrían modificar un archivo simultáneamente                       |
| Seguridad e integridad      | El programa debe implementar sus propias validaciones y controles               |

### ¿Qué es la redundancia?

Imagina que guardamos:

```cpp
cliente.txt
Juan Perez | 809-555-1234
```

Y también:

```cpp
ventas.txt
Juan Perez | 809-555-1234 | 5000
```

Estamos repitiendo la misma información.

Si el cliente cambia su número de teléfono y solamente actualizamos un archivo, los datos dejarán de coincidir.

Ese es un ejemplo de inconsistencia.

## 18. ¿Qué es un DBMS o SGBD?

DBMS significa Database Management System.

En español: Sistema Gestor de Bases de Datos (SGBD).

Es un software que permite crear, organizar, consultar, actualizar y administrar bases de datos.

El material menciona varios ejemplos:

- MySQL.
- PostgreSQL.
- Oracle.
- Microsoft SQL Server.
- DB2.

En lugar de crear manualmente un archivo de texto para cada tipo de información, podemos utilizar un sistema de bases de datos que administre las relaciones, consultas, accesos y controles.

### Comparación

| Característica                | Archivos `.txt`                      | DBMS                                                 |
| ----------------------------- | ------------------------------------ | ---------------------------------------------------- |
| Crear información persistente | Sí                                   | Sí                                                   |
| Buscar registros              | Mediante código que lea los archivos | Mediante consultas                                   |
| Relacionar información        | Debemos programarlo                  | Ofrece mecanismos especializados                     |
| Acceso simultáneo             | Requiere control manual              | Ofrece control de concurrencia                       |
| Integridad de los datos       | Depende de la aplicación             | Puede implementar restricciones                      |
| Adecuado para                 | Ejercicios y aplicaciones sencillas  | Sistemas que requieren gestión de datos más completa |

Esto es particularmente interesante para tu formación porque el proyecto Accesorios Mashiaj está utilizando archivos planos, mientras que aplicaciones más grandes suelen utilizar gestores de bases de datos.

Lo que está enseñando el profesor es una base para comprender por qué existen los DBMS.

## 19. Sistema de archivos del sistema operativo

El último tema del material complementario distingue el almacenamiento de datos dentro de nuestras aplicaciones del sistema de archivos que administra el sistema operativo.

Un sistema de archivos permite organizar información en carpetas, administrar ubicaciones y controlar el acceso a los archivos almacenados.

El PDF menciona ejemplos como FAT32, NTFS, ext2, ext3, UFS, ZFS y HFS.

Estos sistemas no son lo mismo que un DBMS.

Un sistema de archivos organiza archivos y directorios en un dispositivo. Un DBMS gestiona datos estructurados dentro de una base de datos.

# Parte VI — Aplicación en nuestro proyecto final

## 20. ¿Cómo estamos utilizando la Unidad VII en Accesorios Mashiaj?

Actualmente nuestro programa ya incluye:

| Función             | Concepto de la Unidad VII                    |
| ------------------- | -------------------------------------------- |
| `guardarCliente()`  | Escritura de datos con `fstream`             |
| `guardarRecibo()`   | Escritura de una factura en archivo de texto |
| `ios::out`          | Reemplazo del contenido anterior             |
| `archivo <<`        | Salida formateada hacia un archivo           |
| `archivo.is_open()` | Comprobación de apertura                     |
| `archivo.close()`   | Cierre del archivo                           |

Por ejemplo:

```cpp
void guardarCliente(string nombreCliente, string telefonoCliente) {

    fstream archivo("cliente.txt", ios::out);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    archivo << "Nombre: " << nombreCliente << endl;
    archivo << "Telefono: " << telefonoCliente << endl;

    archivo.close();
}
```

Este código combina tres unidades:

- Unidad V: funciones, parámetros y `void`.
- Unidad VI: conceptos de memoria y almacenamiento, como antecedentes.
- Unidad VII: flujos de archivos y escritura persistente.

Si el profesor solicita recuperar clientes, consultar recibos anteriores o trabajar con registros binarios, ya sabemos qué partes de esta unidad necesitamos aplicar.

Por ahora, no cambiaremos nada del proyecto sin un mandato nuevo.

## 21. Errores comunes que debes evitar

Estos son errores que podrían aparecer durante una práctica.

| Error                                                                      | Por qué es importante                                   |
| -------------------------------------------------------------------------- | ------------------------------------------------------- |
| Utilizar `ios::out` cuando querías conservar el historial                  | Puede reemplazar el contenido anterior                  |
| Utilizar `ios::app` cuando querías un único recibo                         | Acumulará recibos                                       |
| Olvidar comprobar la apertura                                              | El programa podría continuar sin guardar los datos      |
| Utilizar `>>` para leer nombres completos                                  | Los espacios separan la extracción                      |
| Utilizar `while (!archivo.eof())` incorrectamente                          | Puede procesar una lectura fallida                      |
| Leer un archivo con un formato diferente al utilizado para guardarlo       | Los datos pueden interpretarse mal                      |
| Confundir `seekg()` con `seekp()`                                          | Uno modifica lectura y el otro escritura                |
| Escribir directamente una estructura con `std::string` como bytes binarios | No produce un registro binario recuperable de esa forma |
| Confundir un archivo plano con un DBMS                                     | No ofrecen automáticamente las mismas capacidades       |

## 22. Hoja rápida de referencia para estudiar

Esta tabla es ideal para guardar al final de tu Markdown.

| Quiero hacer esto                      | Instrucción                               |
| -------------------------------------- | ----------------------------------------- |
| Incluir la biblioteca de archivos      | `#include <fstream>`                      |
| Crear o reemplazar un archivo de texto | `fstream archivo("datos.txt", ios::out);` |
| Abrir para leer                        | `fstream archivo("datos.txt", ios::in);`  |
| Agregar al final                       | `fstream archivo("datos.txt", ios::app);` |
| Escribir información                   | `archivo << dato;`                        |
| Leer un dato                           | `archivo >> dato;`                        |
| Leer una línea                         | `getline(archivo, linea);`                |
| Escribir un carácter                   | `archivo.put(c);`                         |
| Leer un carácter                       | `archivo.get(c);`                         |
| Comprobar apertura                     | `archivo.is_open()`                       |
| Comprobar fallo                        | `archivo.fail()`                          |
| Cerrar el archivo                      | `archivo.close();`                        |
| Abrir en binario para escribir         | `ios::out \\| ios::binary`                |
| Escribir bytes                         | `archivo.write(direccion, tamano);`       |
| Leer bytes                             | `archivo.read(direccion, tamano);`        |
| Mover posición de lectura              | `archivo.seekg(...);`                     |
| Mover posición de escritura            | `archivo.seekp(...);`                     |
| Consultar posición de lectura          | `archivo.tellg();`                        |
| Consultar posición de escritura        | `archivo.tellp();`                        |
| Pasar un archivo a una función         | `void funcion(fstream &archivo);`         |

## 23. Ejercicios que te recomiendo para practicar

Prácticas de la Unidad VII

0 de 10 completados

01_escribir_archivo.cpp

Crear un archivo y escribir tres líneas

02_agregar_archivo.cpp

Agregar información sin borrar lo anterior

03_leer_archivo.cpp

Leer todo un archivo mediante getline()

04_leer_caracteres.cpp

Leer caracteres individuales con get()

05_guardar_estudiante.cpp

Guardar el nombre, edad y nota de un estudiante

06_registro_clientes.cpp

Registrar clientes en un archivo de texto

07_leer_clientes.cpp

Recuperar los clientes guardados

08_archivo_binario.cpp

Guardar y recuperar un número con read() y write()

09_acceso_aleatorio.cpp

Recuperar un registro mediante seekg()

10_archivos_funciones.cpp

Enviar un archivo como argumento por referencia

## 24. ¿Qué debes dominar para el examen?

Te recomiendo estudiar la unidad en este orden:

Primera etapa: aprender a crear, escribir, leer y cerrar archivos de texto con `<fstream>`, `ios::out`, `ios::in` e `ios::app`.

Segunda etapa: practicar lectura de líneas, validación de apertura y almacenamiento de varios registros.

Tercera etapa: comprender archivos binarios, `read()`, `write()` y registros con estructuras.

Cuarta etapa: estudiar `seekg()`, `seekp()`, `tellg()`, `tellp()` y archivos como parámetros de funciones.

Quinta etapa: entender las limitaciones de los archivos planos y por qué utilizamos DBMS.

No necesitas memorizar los 107 ejemplos y diapositivas. Necesitas comprender qué hace cada recurso y saber elegirlo cuando el enunciado te presente un problema.

## 25. Repaso rápido de conceptos

1\. ¿Qué modo utilizarías para que recibo.txt conserve solamente la última factura?

ios::app

ios::out

ios::in

2\. ¿Qué función permite recuperar líneas completas de un archivo?

getline()

put()

seekp()

3\. ¿Qué función mueve la posición de lectura dentro de un archivo?

tellp()

seekg()

close()

4\. ¿Por qué se utiliza fstream &archivo como parámetro?

Para copiar el archivo

Para recibir el flujo por referencia

Para convertir el archivo en un entero

5\. ¿Cuál es una ventaja de un DBMS frente a archivos planos?

No necesita almacenamiento

Ofrece mecanismos de consultas, integridad y concurrencia

No utiliza archivos internamente

Aciertos: 0 de 5

Reiniciar

## Conclusión de la Unidad VII

Esta unidad representa un paso importante en nuestro aprendizaje.

Antes sabíamos crear programas que recibían datos, los procesaban y mostraban resultados. Ahora sabemos cómo almacenar y recuperar información para que nuestros programas puedan conservarla entre distintas ejecuciones.

Además, empezamos a entender los fundamentos de los sistemas que manejan datos de clientes, ventas, productos y facturas.

Y lo mejor es que ya estamos aplicando estos conceptos en Accesorios Mashiaj con `cliente.txt` y `recibo.txt`.

Mi recomendación es que primero practiquemos bien los archivos de texto antes de pasar a los binarios y al acceso aleatorio. Son los conceptos que ya has utilizado en tu proyecto y sobre los que podemos construir los siguientes ejercicios.

Nombre recomendado para guardar estos apuntes: `UNIDAD_7_OPERACIONES_ARCHIVOS.md`.

Con esto tenemos un resumen de los tres materiales. La Unidad VII parece una unidad de cierre por su contenido, aunque los documentos compartidos no confirman por sí solos que sea oficialmente la última del curso.