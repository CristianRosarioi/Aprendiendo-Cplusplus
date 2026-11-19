# Unidad 5 — Funciones en C++: guía de estudio

Esta unidad es especialmente importante para tu formación como programador, porque vas a aprender a dividir un programa grande en partes pequeñas que se comunican entre sí.

Y hay algo interesante: ¿recuerdas cuando hablamos del proyecto final de la UASD, donde el profesor pondrá un programa dividido en varios archivos y tendrás que unirlos mediante un `main()`? Precisamente la unidad 5 enseña las herramientas que necesitas para hacerlo.

He podido revisar los seis materiales que enviaste. No todos tratan exclusivamente de funciones: también incluyen punteros, diferencias entre C y C++, y manejo de archivos.

## 1. ¿Qué aprenderás en esta unidad?

Estos son los temas principales de 5 — Funciones V1, y los contenidos adicionales de los otros documentos.

| Tema                              | Qué aprenderás                                 | Importancia         |
| --------------------------------- | ---------------------------------------------- | ------------------- |
| Funciones                         | Crear y llamar bloques de código reutilizables | Fundamental         |
| Parámetros y argumentos           | Enviar información a una función               | Fundamental         |
| `return` y `void`                 | Devolver resultados o ejecutar tareas          | Fundamental         |
| Prototipos                        | Declarar una función antes de definirla        | Alta                |
| Paso por valor y referencia       | Comprender cómo se envían y modifican datos    | Muy alta            |
| Sobrecarga                        | Tener varias funciones con el mismo nombre     | Alta                |
| Funciones con estructuras         | Enviar registros completos a funciones         | Alta                |
| Funciones con arreglos y vectores | Procesar colecciones desde funciones           | Muy alta            |
| Archivos `.h` y `.cpp`            | Dividir un programa en varios ficheros         | Muy alta            |
| Argumentos de línea de comandos   | Enviar datos al ejecutar un programa           | Media               |
| Punteros                          | Trabajar con direcciones de memoria            | Tema complementario |
| `<fstream>`                       | Guardar y recuperar información de archivos    | Tema complementario |

Es una evolución natural de lo que hemos estudiado: primero escribías todo dentro de `main()`. Ahora aprenderás a organizar esas mismas instrucciones en funciones.

## 2. ¿Qué es exactamente una función?

Una función es un bloque de código que realiza una tarea específica y que podemos ejecutar llamándolo por su nombre.

Por ejemplo, imagina que estás construyendo un programa de facturación. Necesitas calcular descuentos, impuestos y totales. En lugar de escribir todas las operaciones dentro de `main()`, puedes crear una función para cada tarea.

### Ejemplo básico

```
#include <iostream>
using namespace std;

int sumar(int a, int b) {
    int resultado = a + b;
    return resultado;
}

int main() {
    int total;

    total = sumar(10, 5);

    cout << "Resultado: " << total << endl;

    return 0;
}
```

El resultado es:

```
Resultado: 15
```

Veamos la estructura de la función:

| Elemento       | Significado                                         |
| -------------- | --------------------------------------------------- |
| `int`          | La función devuelve un entero                       |
| `sumar`        | Nombre de la función                                |
| `int a, int b` | Parámetros que recibe                               |
| `{ }`          | Cuerpo de la función                                |
| `return`       | Devuelve el resultado al lugar desde donde se llamó |

La parte más importante es entender el recorrido.

Cómo se ejecuta `sumar(10, 5)`

1. `main()` llama a `sumar(10, 5)`
2. `a` recibe 10 y `b` recibe 5
3. La función calcula `10 + 5`
4. `return` devuelve 15
5. `main()` guarda 15 en `total` y lo imprime

Una función no es necesariamente una biblioteca. Puedes escribir tus propias funciones y utilizarlas desde diferentes partes del programa.

## 3. Los cuatro tipos básicos de funciones

Una función puede recibir datos o no recibirlos. También puede devolver un resultado o no devolverlo.

| Tipo                         | Ejemplo                               |
| ---------------------------- | ------------------------------------- |
| Sin parámetros y sin retorno | `void saludar()`                      |
| Con parámetros y sin retorno | `void mostrarNota(int nota)`          |
| Sin parámetros y con retorno | `int obtenerNumero()`                 |
| Con parámetros y con retorno | `double calcularTotal(double precio)` |

Mira estas dos diferencias:

Función que muestra algo:

```
void saludar() {
    cout << "Hola estudiante" << endl;
}
```

Se llama con:

```
saludar();
```

No devuelve un valor al programa.

Función que calcula y devuelve:

```
double calcularDoble(double numero) {
    return numero * 2;
}
```

Se llama con:

```
double resultado = calcularDoble(15);
```

Aquí el resultado es 30.

No confundas `cout` con `return`: uno muestra información y el otro devuelve un valor a quien llamó la función.

## 4. Parámetros y argumentos

Son dos términos que debes distinguir.

```
int multiplicar(int a, int b) {
    return a * b;
}
```

`a` y `b` son los parámetros: variables que declara la función para recibir datos.

```
multiplicar(4, 6);
```

`4` y `6` son los argumentos: valores concretos enviados cuando la llamamos.

El material también incluye los argumentos por defecto, que permiten omitir algunos argumentos cuando la función ya tiene un valor predeterminado.

```
int sumar(int a, int b = 10) {
    return a + b;
}
```

Podemos llamar:

```
sumar(5);      // Devuelve 15.
sumar(5, 20);  // Devuelve 25.
```

La segunda llamada reemplaza el valor predeterminado de `b`.

## 5. Paso por valor y paso por referencia

Este será uno de los conceptos que más te recomiendo practicar.

Cuando envías una variable a una función, existen distintas formas de pasarla.

### Paso por valor

```
void cambiar(int numero) {
    numero = 100;
}

int main() {
    int edad = 20;

    cambiar(edad);

    cout << edad << endl;

    return 0;
}
```

Resultado: 20.

¿Por qué no cambió a 100? Porque la función recibió una copia del valor. Modificó esa copia, no la variable original.

### Paso por referencia

```
void cambiar(int &numero) {
    numero = 100;
}

int main() {
    int edad = 20;

    cambiar(edad);

    cout << edad << endl;

    return 0;
}
```

Resultado: 100.

La diferencia está aquí:

```
int &numero
```

El `&` indica que el parámetro es una referencia. En este caso, la función trabaja sobre la variable original.

| Paso por valor                                      | Paso por referencia                                                          |
| --------------------------------------------------- | ---------------------------------------------------------------------------- |
| Recibe una copia del dato                           | Se refiere al dato original                                                  |
| Cambiar el parámetro no cambia la variable original | Cambiar el parámetro puede modificar la variable original                    |
| Se usa cuando solo necesitamos el valor             | Se usa cuando necesitamos modificar el dato original o evitar ciertas copias |

Este tema está desarrollado en el material principal de funciones.

## 6. Prototipos de funciones

Un prototipo le indica al compilador qué función existe, qué datos recibe y qué tipo de resultado devuelve.

Esto permite escribir la definición de la función después de `main()`.

```
#include <iostream>
using namespace std;

// Prototipo
int sumar(int a, int b);

int main() {
    cout << sumar(5, 3) << endl;

    return 0;
}

// Definicion
int sumar(int a, int b) {
    return a + b;
}
```

Observa tres cosas:

- `int sumar(int a, int b);` anuncia la función.
- `sumar(5, 3)` la llama desde `main`.
- `int sumar(int a, int b) { ... }` contiene las instrucciones que ejecuta.

La diferencia fundamental: el prototipo termina con `;`, mientras que la definición tiene un cuerpo entre llaves.

Esto será importante cuando empecemos a dividir los programas en varios archivos.

## 7. Sobrecarga de funciones

La sobrecarga permite crear varias funciones con el mismo nombre, pero con diferentes listas de parámetros.

```
int sumar(int a, int b) {
    return a + b;
}

double sumar(double a, double b) {
    return a + b;
}
```

Ahora:

```
sumar(5, 3);       // Utiliza la version int.
sumar(2.5, 3.5);   // Utiliza la version double.
```

El compilador determina qué versión corresponde según los argumentos.

Importante: no basta con cambiar solamente el tipo de retorno. Para sobrecargar una función deben cambiar sus parámetros, ya sea en cantidad o en tipos.

## 8. Funciones con estructuras

Aquí conectamos la unidad 5 con tu ejercicio de las facturas y los estudiantes.

Antes hacíamos algo así:

```
cout << estudiante.nombre;
cout << estudiante.nota;
```

Ahora podemos crear una función que reciba una estructura completa.

```
#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    double nota;
};

void mostrarEstudiante(Estudiante alumno) {
    cout << "Nombre: " << alumno.nombre << endl;
    cout << "Nota: " << alumno.nota << endl;
}

int main() {
    Estudiante estudiante1;

    estudiante1.nombre = "Manuel";
    estudiante1.nota = 93;

    mostrarEstudiante(estudiante1);

    return 0;
}
```

La línea:

```
mostrarEstudiante(estudiante1);
```

envía los datos de la estructura a la función.

Y aquí:

```
void mostrarEstudiante(Estudiante alumno)
```

la función recibe una copia de esa estructura bajo el nombre `alumno`.

Esto también se puede hacer mediante referencias, y el material explica cómo enviar estructuras y devolverlas desde funciones.

## 9. Funciones con arreglos

Podemos crear una función que reciba un arreglo y procese sus elementos.

```
#include <iostream>
using namespace std;

void mostrarNotas(double notas[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << notas[i] << endl;
    }
}

int main() {
    double notas[4] = {84, 93, 78, 71};

    mostrarNotas(notas, 4);

    return 0;
}
```

Aquí hay una idea nueva:

```
void mostrarNotas(double notas[], int cantidad)
```

La función recibe el acceso al arreglo y, por separado, su cantidad de elementos.

El arreglo tradicional no comunica automáticamente su longitud a esta función.

La llamada:

```
mostrarNotas(notas, 4);
```

le permite recorrer sus cuatro elementos.

Esta parte conecta directamente con los arreglos que aprendimos en la unidad anterior.

## 10. Funciones con vectores

También podemos enviar un `vector` completo a una función.

```
#include <iostream>
#include <vector>
using namespace std;

void mostrarNumeros(vector<int> numeros) {
    for (unsigned int i = 0; i < numeros.size(); i++) {
        cout << numeros.at(i) << endl;
    }
}

int main() {
    vector<int> numeros;

    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_back(30);

    mostrarNumeros(numeros);

    return 0;
}
```

Aquí:

```
void mostrarNumeros(vector<int> numeros)
```

la función recibe un vector de enteros. En esta versión, lo recibe por valor, por lo que se copia.

Con referencias también podemos evitar esa copia:

```
void mostrarNumeros(const vector<int>& numeros)
```

Esta última sintaxis combina dos conceptos:

- `&`: pasa el vector por referencia.
- `const`: impide modificarlo mediante ese parámetro.

Es algo que practicaremos cuando entiendas bien la diferencia entre valor y referencia.

## 11. Compilación por separado: varios archivos

Este tema es fundamental para el proyecto final que me contaste.

Imagina que un programa contiene funciones para leer estudiantes, mostrar datos y calcular notas. Podemos separarlas en distintos archivos.

Organización básica de un proyecto C++

`main.cpp`

Inicia y coordina el programa

`operaciones.h`

Declara qué funciones existen

`operaciones.cpp`

Define lo que hacen las funciones

Un ejemplo pequeño:

`operaciones.h`

```
#ifndef OPERACIONES_H
#define OPERACIONES_H

int sumar(int a, int b);

#endif
```

`operaciones.cpp`

```
#include "operaciones.h"

int sumar(int a, int b) {
    return a + b;
}
```

`main.cpp`

```
#include <iostream>
#include "operaciones.h"
using namespace std;

int main() {
    cout << sumar(10, 20) << endl;
    return 0;
}
```

Aquí `main()` ejecuta una función definida en otro archivo.

Para compilar ambos archivos fuente en una sola operación, con un compilador moderno:

```
g++ main.cpp operaciones.cpp -o programa
```

En el laboratorio, donde utilizas Borland, tenemos que ajustar las instrucciones a la versión y configuración exactas de `bcc32` que tenga el profesor.

Esta sección de la unidad incluye crear librerías reutilizables, no solamente separar archivos. También aparecen las etapas de declaración, compilación y enlace.

## 12. Argumentos de línea de comandos

El material presenta otra forma de escribir `main`:

```
int main(int argc, char* argv[])
```

Sus elementos son:

| Elemento  | Qué representa                                               |
| --------- | ------------------------------------------------------------ |
| `argc`    | Cantidad de argumentos recibidos                             |
| `argv`    | Arreglo de cadenas con los argumentos                        |
| `argv[0]` | Normalmente la ruta o nombre usado para ejecutar el programa |
| `argv[1]` | Primer argumento adicional, si existe                        |

Por ejemplo, al ejecutar:

```
./programa Cristian
```

el programa puede recibir `"Cristian"` sin pedirlo mediante `cin`.

Este tema tiene conexión con los arreglos de caracteres y punteros, por eso conviene estudiarlo después de los parámetros normales.

## 13. Punteros: direcciones de memoria

Los materiales `INF510_tema_08b.ppt` y `Punteros&Variables_Punteros.doc` introducen los punteros.

Un puntero es una variable que almacena una dirección de memoria.

```
int edad = 25;
int *puntero = &edad;
```

Aquí aparecen dos operadores importantes:

| Expresión      | Significado                               |
| -------------- | ----------------------------------------- |
| `&edad`        | Obtiene la dirección de memoria de `edad` |
| `int *puntero` | Declara un puntero a un entero            |
| `*puntero`     | Accede al valor al que apunta             |

Ejemplo:

```
cout << edad;      // 25
cout << *puntero;  // 25
```

Los dos muestran el mismo valor, pero acceden a él de formas diferentes.

El material desarrolla además la desreferenciación, punteros `void`, relaciones con arreglos, paso de argumentos mediante punteros y los peligros de punteros no inicializados o colgantes.

Mi recomendación es estudiar primero las referencias de funciones y después los punteros. Están relacionados, pero no son exactamente lo mismo.

## 14. Archivos: guardar información permanentemente

Los archivos `INF510_ArchivosConceptosGenerales.doc` e `INF510_tema_10.ppt` tratan el almacenamiento persistente de información.

Hasta ahora, tus programas guardan datos en variables, arreglos o vectores. Esos datos normalmente desaparecen cuando termina el programa.

Con archivos puedes conservarlos para usarlos en otra ejecución.

El material distingue archivos de texto y binarios, explica operaciones de archivos y presenta la biblioteca `<fstream>`.

Sus tres tipos principales son:

| Tipo       | Función                          |
| ---------- | -------------------------------- |
| `ifstream` | Leer archivos                    |
| `ofstream` | Escribir archivos                |
| `fstream`  | Trabajar con lectura y escritura |

Por ejemplo:

```
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream archivo("notas.txt");

    if (archivo.is_open()) {
        archivo << "Cristian 84" << endl;
        archivo << "Manuel 93" << endl;

        archivo.close();
        cout << "Datos guardados." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}
```

Este programa intenta crear un archivo llamado `notas.txt` y escribir dos registros. Comprueba primero si pudo abrirlo.

La diferencia con `cout` es que ahora utilizamos un flujo dirigido a un archivo.

Más adelante, esto nos permitirá construir programas de estudiantes que conserven información aunque cerremos la aplicación.

## 15. Diferencias entre C y C++

El documento C frente a C++ compara características de ambos lenguajes.

Destaca, entre otras cosas, los prototipos de funciones, referencias, sobrecarga, uso de `const`, estructuras, asignación dinámica de memoria y organización de programas.

No lo estudiaría como una lista de diferencias para memorizar. Lo utilizaría para entender por qué C++ ofrece herramientas adicionales para organizar programas.

Por ejemplo, la sobrecarga de funciones y las referencias son características importantes de C++ que también aparecen en el material principal de esta unidad.

## 16. Orden en el que te recomiendo estudiar

No intentes aprender los seis documentos simultáneamente. Son muchos conceptos, y algunos necesitan conocimientos previos.

Ruta de estudio de la unidad 5

Bloque 1 de 5

1

2

3

4

5

## Fundamentos de funciones

Definir y llamar funciones

Parámetros y argumentos

void y return

Funciones con y sin resultados

Estudiar este bloque&#x20;

## 17. Ejercicios que deberías poder resolver

Al avanzar, quiero que puedas construir estas soluciones usando el material del profesor:

1. Una función que sume dos números y devuelva el resultado.
2. Una función que reciba una nota y muestre si está aprobada.
3. Una función que calcule un descuento de factura.
4. Una función que reciba un vector y determine la nota mayor.
5. Una función que reciba una estructura `Estudiante` y muestre sus datos.
6. Un programa con `main.cpp`, un archivo de cabecera y otro archivo con funciones.
7. Un programa que guarde y recupere datos de un archivo de texto.

En particular, quiero que lleguemos a transformar tu ejercicio de estudiantes en un programa donde `main()` solamente coordine las funciones de lectura, cálculo e impresión.

## Lo más importante que debes aprender

De toda esta unidad, estas son las preguntas que deberías poder responder sin mirar apuntes:

- ¿Qué diferencia existe entre declarar, definir y llamar una función?
- ¿Qué diferencia hay entre parámetros y argumentos?
- ¿Cuándo utilizo `void` y cuándo `int` o `double`?
- ¿Qué hace `return` y a dónde vuelve el programa?
- ¿Qué diferencia existe entre pasar por valor y por referencia?
- ¿Cómo recibe una función una estructura o un vector?
- ¿Cómo puedo llamar desde `main()` una función ubicada en otro archivo?

Mi recomendación: comencemos por funciones normales, parámetros, `void` y `return`. Cuando esos cuatro fundamentos estén claros, avanzamos a referencias, vectores y archivos separados.

Esta unidad es extensa, pero tiene una ventaja: muchas de sus ideas las aplicarás también en Python, TypeScript y otros lenguajes. No necesitas memorizar todo de golpe; necesitas aprender a reconocer qué problema resuelve cada herramienta.
