# Tarea Unidad VII — Ejercicio 1: Leer un archivo de texto y mostrarlo por páginas

INF510 · Introducción a la Programación · UASD · Profesor Brito

Ya revisé el mandato que enviaste. Esta vez el profesor dejó un solo ejercicio, dedicado a la lectura de archivos de texto.

Vamos a resolverlo con los conceptos que hemos estudiado: `<fstream>`, `ios::in`, `getline()`, funciones, ciclos `while`, condicionales `if` y contadores.

Te daré el código completo, la explicación de su lógica paso a paso y las pruebas que debes realizar para entregarlo.

## 1. Enunciado del profesor

Crear un programa en C++ que:

1. Solicite al usuario el nombre de un archivo.
2. Abra ese archivo y muestre su contenido en pantalla.
3. Muestre cada línea precedida por su número y dos puntos (`:`), comenzando desde 1.
4. Cuando existan más de 24 líneas, muestre las primeras 24 y espere que el usuario presione Enter para continuar.
5. Repita el proceso hasta mostrar todo el archivo.

Por ejemplo, si el archivo contiene:

```
George Rolland
127 Academy Street
Brasstown, NC 28706
```

El programa debe mostrar:

```cpp
1: George Rolland
2: 127 Academy Street
3: Brasstown, NC 28706
```

Importante: el profesor no nos pide crear el archivo desde el programa. Podemos preparar un `.txt` con un editor de texto y utilizarlo para probar la lectura.

## 2. Código completo — `Ejercicio1.cpp`

Este programa utiliza una función `mostrarArchivo()` para encargarse de la lectura, numeración y pausas.

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Prototipo de la funcion
void mostrarArchivo(string nombreArchivo);

int main() {

    string nombreArchivo;

    // Solicitar el nombre del archivo
    cout << "Introduzca el nombre del archivo: ";
    getline(cin, nombreArchivo);

    // Llamar a la funcion que muestra el archivo
    mostrarArchivo(nombreArchivo);

    return 0;
}

// Funcion que lee y muestra el contenido del archivo
void mostrarArchivo(string nombreArchivo) {

    // Abrir el archivo en modo lectura
    fstream archivo(nombreArchivo.c_str(), ios::in);

    // Verificar que el archivo se haya abierto
    if (!archivo.is_open()) {

        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;

    int numeroLinea = 1;
    int lineasPantalla = 0;

    // Leer todas las lineas del archivo
    while (getline(archivo, linea)) {

        // Hacer una pausa cada 24 lineas
        if (lineasPantalla == 24) {

            cout << "\nPresione Enter para continuar...";
            cin.get();

            lineasPantalla = 0;
        }

        // Mostrar el numero y contenido de la linea
        cout << numeroLinea << ": " << linea << endl;

        // Aumentar los contadores
        numeroLinea++;
        lineasPantalla++;
    }

    // Cerrar el archivo
    archivo.close();
}
```

Comprobación: compilé el programa con C++17 y lo probé con un archivo de 50 líneas. La primera pausa ocurre antes de mostrar la línea 25 y la segunda antes de la línea 49, como corresponde.

## 3. ¿Cómo funciona la lógica general?

`main()`

Solicita el nombre del archivo

`mostrarArchivo(nombreArchivo)`

Abre el archivo mediante `ios::in`

`while (getline(...))`

Lee una línea del archivo

`if (lineasPantalla == 24)`

Espera Enter cuando ya se mostraron 24 líneas

Continúa leyendo hasta terminar el archivo

`archivo.close()`

Finaliza la lectura y cierra el archivo

La clave del ejercicio es que necesitamos controlar dos cosas diferentes: qué línea del archivo estamos leyendo y cuántas líneas hemos mostrado desde la última pausa.

Para eso utilizamos dos contadores.

## 4. Explicación de las bibliotecas y el prototipo

### Las bibliotecas

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
```

| Instrucción            | Para qué la necesitamos                    |
| ---------------------- | ------------------------------------------ |
| `<iostream>`           | Utilizar `cin`, `cout` y `endl`            |
| `<fstream>`            | Abrir y leer archivos                      |
| `<string>`             | Guardar el nombre y las líneas del archivo |
| `using namespace std;` | Evitar escribir `std::` constantemente     |

### El prototipo

```cpp
void mostrarArchivo(string nombreArchivo);
```

Analicémoslo:

- `void`: la función no devuelve un resultado.
- `mostrarArchivo`: nombre de la función.
- `string nombreArchivo`: parámetro que recibe el nombre del archivo.

¿Por qué utilizamos `void`?

Porque la función solamente necesita leer y mostrar información. No tenemos que devolver ningún número o texto a `main()`.

# 5. Explicación de `main()` línea por línea

### A. Declarar la variable

```cpp
string nombreArchivo;
```

Creamos una variable que almacenará el nombre del archivo que desea leer el usuario.

Por ejemplo:

```cpp
prueba.txt
```

### B. Solicitar el nombre

```cpp
cout << "Introduzca el nombre del archivo: ";
getline(cin, nombreArchivo);
```

Aquí utilizamos `getline()` para leer lo que escribe el usuario.

¿Por qué no usamos `cin >> nombreArchivo`?

Porque con `getline()` podemos leer nombres de archivos que contengan espacios.

Por ejemplo:

```cpp
mis datos.txt
```

### C. Llamar a la función

```cpp
mostrarArchivo(nombreArchivo);
```

Esta instrucción envía el nombre del archivo a nuestra función.

Si el usuario escribió `prueba.txt`, la llamada equivale a:

```cpp
mostrarArchivo("prueba.txt");
```

La función recibe el nombre e intenta abrir ese archivo.

### D. Finalizar

```cpp
return 0;
```

Indica que `main()` terminó normalmente.

# 6. La función `mostrarArchivo()`

Esta es la parte más importante del ejercicio.

## A. Abrir el archivo en modo lectura

```cpp
fstream archivo(nombreArchivo.c_str(), ios::in);
```

Vamos por partes.

`fstream` es la clase que permite trabajar con archivos mediante flujos.

`archivo` es el nombre que le damos al objeto.

`nombreArchivo.c_str()` proporciona el nombre almacenado en nuestro `string` en forma de cadena de caracteres de estilo C, compatible también con compiladores antiguos.

`ios::in` significa que queremos abrir el archivo para lectura.

Fíjate en la diferencia con nuestro proyecto de la perfumería:

```cpp
fstream archivo("recibo.txt", ios::out);
```

En la perfumería utilizamos `ios::out` para escribir.

Aquí utilizamos `ios::in` porque queremos recuperar información.

## B. Comprobar que el archivo se abrió

```cpp
if (!archivo.is_open()) {

    cout << "No se pudo abrir el archivo." << endl;
    return;
}
```

Esta condición comprueba si ocurrió algún problema al abrir el archivo.

El símbolo `!` significa negación.

Por tanto:

```cpp
!archivo.is_open()
```

Significa que el archivo no se encuentra abierto.

Si ocurre eso, mostramos el error y salimos de la función.

Aquí utilizamos:

```cpp
return;
```

Sin ningún valor porque nuestra función es `void`.

## 7. Los dos contadores: la parte más importante

Declaramos:

```cpp
int numeroLinea = 1;
int lineasPantalla = 0;
```

Estas variables cumplen responsabilidades diferentes.

### `numeroLinea`

Controla la numeración de todas las líneas del archivo.

Comienza en 1 porque así lo exige el mandato.

Por ejemplo:

```cpp
1: Primera linea
2: Segunda linea
3: Tercera linea
```

Esta variable nunca se reinicia durante la lectura.

### `lineasPantalla`

Controla cuántas líneas hemos mostrado desde la última pausa.

Comienza en cero.

Cuando llega a 24, el programa espera que el usuario presione Enter antes de mostrar más información.

Después se reinicia en cero.

### ¿Por qué necesitamos dos contadores?

Porque al llegar a la línea 25 necesitamos reiniciar el conteo de líneas por pantalla, pero la numeración del archivo debe continuar desde 25.

| Situación                                                 | `numeroLinea` | `lineasPantalla` |
| --------------------------------------------------------- | ------------- | ---------------- |
| Antes de imprimir la primera línea                        | 1             | 0                |
| Después de imprimir la línea 1                            | 2             | 1                |
| Después de imprimir la línea 24                           | 25            | 24               |
| Después de presionar Enter, antes de imprimir la línea 25 | 25            | 0                |
| Después de imprimir la línea 25                           | 26            | 1                |
| Después de imprimir la línea 48                           | 49            | 24               |

Este es uno de los razonamientos más importantes para el ejercicio.

## 8. El ciclo `while` que lee el archivo

```cpp
while (getline(archivo, linea)) {
```

Aquí combinamos dos conceptos que ya conocemos:

- `while`: repite instrucciones mientras se cumpla una condición.
- `getline()`: lee una línea completa.

La expresión:

```cpp
getline(archivo, linea)
```

Intenta obtener una línea del archivo y almacenarla en la variable `linea`.

Mientras la lectura funcione, el `while` continúa.

Cuando termina el archivo, el ciclo finaliza.

¿Por qué no utilizamos `for`?

Porque no sabemos de antemano cuántas líneas tiene el archivo.

Un `while` es apropiado porque podemos repetir hasta que ya no existan más líneas disponibles.

## 9. La condición que hace la pausa

```cpp
if (lineasPantalla == 24) {

    cout << "\nPresione Enter para continuar...";
    cin.get();

    lineasPantalla = 0;
}
```

Esta es la lógica que cumple el requisito especial del profesor.

### Primera instrucción

```cpp
if (lineasPantalla == 24)
```

Comprueba si ya hemos mostrado 24 líneas desde la última pausa.

### Segunda instrucción

```cpp
cout << "\nPresione Enter para continuar...";
```

Muestra un mensaje al usuario.

### Tercera instrucción

```cpp
cin.get();
```

Espera a recibir un carácter desde el teclado.

En nuestro programa, lo utilizamos para que el usuario presione Enter y continúe.

Como previamente capturamos el nombre del archivo mediante `getline(cin, nombreArchivo)`, ya se consumió el Enter de aquella entrada y esta pausa funciona correctamente.

### Cuarta instrucción

```cpp
lineasPantalla = 0;
```

Reinicia el contador de líneas de la página.

¿Por qué lo reiniciamos?

Porque necesitamos permitir otras 24 líneas antes de volver a pausar.

### ¿Qué ocurre si el archivo solo tiene 24 líneas?

No se produce una pausa innecesaria.

La condición se revisa cuando hay una nueva línea disponible. Si no existe una línea 25, el ciclo termina.

Ese pequeño detalle hace que el programa funcione correctamente tanto con archivos cortos como con archivos largos.

## 10. Mostrar la línea con su número

```cpp
cout << numeroLinea << ": " << linea << endl;
```

Veamos cada parte:

| Expresión     | Función                            |
| ------------- | ---------------------------------- |
| `numeroLinea` | Muestra el número de línea         |
| `": "`        | Agrega los dos puntos y un espacio |
| `linea`       | Muestra el contenido leído         |
| `endl`        | Termina la línea en pantalla       |

Por ejemplo, si:

```cpp
numeroLinea = 3;
linea = "Brasstown, NC 28706";
```

La instrucción imprimirá:

```cpp
3: Brasstown, NC 28706
```

Esto cumple exactamente el formato solicitado.

## 11. Incrementar los contadores

Después de imprimir una línea escribimos:

```cpp
numeroLinea++;
lineasPantalla++;
```

El operador `++` aumenta una variable en una unidad.

La primera instrucción prepara el número que se utilizará para la próxima línea.

La segunda registra que hemos mostrado una línea más dentro del grupo actual de 24.

Recuerda: ambos aumentan juntos, pero solo `lineasPantalla` vuelve a cero después de una pausa.

## 12. Cerrar el archivo

```cpp
archivo.close();
```

Esta instrucción cierra el flujo después de leer el contenido.

Es exactamente el procedimiento que vimos en clase con los ejercicios de escritura de archivos.

El proceso es:

Abrir → comprobar → leer → mostrar → cerrar.

# 13. Ejemplo de ejecución

Si el archivo contiene solamente tres líneas, verás:

```cpp
Introduzca el nombre del archivo: prueba.txt

1: George Rolland
2: 127 Academy Street
3: Brasstown, NC 28706
```

Ahora supongamos que tenemos un archivo de 50 líneas.

Simulación de lectura por páginas

Página 1 de 3

1: Contenido de la linea 1

2: Contenido de la linea 2

3: Contenido de la linea 3

4: Contenido de la linea 4

5: Contenido de la linea 5

6: Contenido de la linea 6

7: Contenido de la linea 7

8: Contenido de la linea 8

9: Contenido de la linea 9

10: Contenido de la linea 10

11: Contenido de la linea 11

12: Contenido de la linea 12

13: Contenido de la linea 13

14: Contenido de la linea 14

15: Contenido de la linea 15

16: Contenido de la linea 16

17: Contenido de la linea 17

18: Contenido de la linea 18

19: Contenido de la linea 19

20: Contenido de la linea 20

21: Contenido de la linea 21

22: Contenido de la linea 22

23: Contenido de la linea 23

24: Contenido de la linea 24

Se han mostrado 24 de 50 líneas. El programa espera Enter para continuar.

&#x20;AnteriorContinuar&#x20;

Observa que el archivo se muestra en grupos de 24, 24 y 2 líneas.

No borramos la pantalla entre grupos, porque no necesitamos utilizar `system("cls")`, que depende del sistema operativo. La pausa controla la presentación y permite ejecutarlo tanto en Windows como en Mac.

## 14. Cómo preparar el archivo para probar

En VS Code puedes crear un archivo llamado `prueba.txt` en el directorio donde ejecutarás el programa.

Para una primera prueba, escribe:

```cpp
George Rolland
127 Academy Street
Brasstown, NC 28706
```

Guárdalo y ejecuta el programa.

Después realiza otra prueba con más de 24 líneas para comprobar las pausas. Puedes crear un archivo que tenga 26 líneas de texto sencillo.

Si trabajas desde la terminal y escribes solamente `prueba.txt`, C++ lo buscará en el directorio de trabajo actual. Si está en otra carpeta, tendrás que introducir su ruta.

### Compilación en Mac

```cpp
clang++ -std=c++17 Ejercicio1.cpp -o Ejercicio1
./Ejercicio1
```

### Prueba con un archivo inexistente

Introduce:

```cpp
archivo_inexistente.txt
```

Debe aparecer:

```cpp
No se pudo abrir el archivo.
```

## 15. Conceptos que utilizamos

| Concepto    | ¿Para qué sirve en este ejercicio?        |
| ----------- | ----------------------------------------- |
| `fstream`   | Trabajar con el archivo                   |
| `ios::in`   | Abrirlo para lectura                      |
| `getline()` | Leer líneas completas                     |
| `string`    | Guardar el nombre y el contenido          |
| `void`      | Crear una función que no devuelve valores |
| Parámetros  | Enviar el nombre del archivo              |
| `while`     | Leer hasta llegar al final                |
| `if`        | Comprobar la apertura y las pausas        |
| `cin.get()` | Esperar la entrada del usuario            |
| `++`        | Incrementar los contadores                |
| `.close()`  | Cerrar el archivo                         |

## 16. Preguntas que debes saber responder

¿Por qué utilizamos `ios::in` y no `ios::out`? Porque queremos leer el contenido del archivo, no escribirlo ni reemplazarlo.

¿Por qué utilizamos `getline()`? Porque necesitamos recuperar cada línea completa, incluidos los espacios que pueda contener.

¿Por qué tenemos dos contadores? Porque uno lleva la numeración total y el otro controla cuántas líneas se han mostrado desde la última pausa.

¿Por qué utilizamos `cin.get()`? Para esperar que el usuario presione Enter antes de continuar.

¿Por qué la función es `void`? Porque su responsabilidad es mostrar información y no devolver un resultado.

¿Qué ocurre si el archivo tiene 10 líneas? Se muestran las 10 líneas y el programa termina sin pausas.

¿Qué ocurre si el archivo tiene 50 líneas? Se muestran 24, espera Enter, otras 24, espera Enter y finalmente muestra las últimas 2.

## 17. ¿Qué debes entregar?

El mandato especifica entregar los archivos fuente `.cpp` y una captura de pantalla de la ejecución, reunidos en un archivo comprimido `.zip` o `.rar`.

Para demostrar el funcionamiento, te recomiendo que la captura incluya una ejecución con más de 24 líneas y el mensaje de pausa. También puedes conservar `prueba.txt` junto al código para facilitar la revisión.

Nombres recomendados:

- `Ejercicio1.cpp` — Código fuente.
- `Ejercicio1_Lectura_Archivos.md` — Esta explicación.
- `prueba.txt` — Archivo para realizar las pruebas.

### Lo principal que debes aprender

Este ejercicio combina dos habilidades que ya conocíamos por separado:

Leer información desde un archivo mediante `<fstream>` y controlar la repetición de instrucciones mediante `while` y contadores.

La lógica más importante es:

```cpp
while (getline(archivo, linea)) {

    if (lineasPantalla == 24) {

        cout << "Presione Enter para continuar...";
        cin.get();

        lineasPantalla = 0;
    }

    cout << numeroLinea << ": " << linea << endl;

    numeroLinea++;
    lineasPantalla++;
}
```

Si puedes explicar por qué `numeroLinea` sigue aumentando mientras `lineasPantalla` se reinicia, ya habrás comprendido el corazón de esta tarea.

Con esto tenemos resuelto el único ejercicio del mandato de la Unidad VII, siguiendo los conceptos que hemos estudiado con el profesor Brito.