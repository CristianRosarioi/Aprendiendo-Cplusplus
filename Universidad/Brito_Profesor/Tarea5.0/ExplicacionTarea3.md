# Unidad 5 — Tarea 3: Calculadora con argumentos de línea de comandos en C++

Llegamos a la tercera tarea de la unidad 5. Esta es diferente de las dos anteriores porque aprenderás a enviar información al programa directamente desde la terminal, sin utilizar `cin`.

Vamos a mantener el mismo estilo que utilizamos en Fibonacci y Piedra, Papel o Tijera: código sencillo, funciones, condiciones y explicaciones detalladas.

## 1. ¿Qué vamos a construir?

Una calculadora que reciba dos números y una operación matemática mediante argumentos de línea de comandos.

Por ejemplo, en lugar de abrir el programa y pedirle al usuario dos números, podremos ejecutar:

```
./calculadora 10 + 5
```

Y obtener:

```
Resultado: 15
```

Trabajaremos con las cuatro operaciones básicas: suma, resta, multiplicación y división.

La diferencia importante es que ahora `main()` tendrá esta forma:

```
int main(int argc, char* argv[])
```

Esta es precisamente la característica de la unidad 5 que queremos practicar.

## 2. Código completo — `tarea3.cpp`

```

/*
Universidad Autonoma de Santo Domingo
Introduccion a la Programacion
Unidad V - Tarea 3

Calculadora con argumentos
de linea de comandos
*/

#include <iostream>
#include <cstdlib>
using namespace std;

// Prototipos de las funciones
double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);

int main(int argc, char* argv[]) {

    double numero1, numero2;
    double resultado;
    char operacion;

    // Verificar cantidad de argumentos
    if (argc != 4) {
        cout << "Uso: calculadora numero1 operacion numero2"
             << endl;
        return 1;
    }

    // Convertir los argumentos a numeros
    numero1 = atof(argv[1]);
    operacion = argv[2][0];
    numero2 = atof(argv[3]);

    // Seleccionar la operacion
    switch (operacion) {

        case '+':
            resultado = sumar(numero1, numero2);
            break;

        case '-':
            resultado = restar(numero1, numero2);
            break;

        case '*':
            resultado = multiplicar(numero1, numero2);
            break;

        case '/':
            if (numero2 == 0) {
                cout << "Error: division entre cero." << endl;
                return 1;
            }

            resultado = dividir(numero1, numero2);
            break;

        default:
            cout << "Operacion no valida." << endl;
            return 1;
    }

    cout << "Resultado: " << resultado << endl;

    return 0;
}

// Funcion para sumar
double sumar(double a, double b) {
    return a + b;
}

// Funcion para restar
double restar(double a, double b) {
    return a - b;
}

// Funcion para multiplicar
double multiplicar(double a, double b) {
    return a * b;
}

// Funcion para dividir
double dividir(double a, double b) {
    return a / b;
}

```

Este programa es una versión didáctica que utiliza `atof()` para convertir los argumentos a números. Supone que el usuario escribe números válidos; más adelante podemos aprender a validar completamente esas entradas.

## 3. La novedad principal: `argc` y `argv`

Hasta ahora utilizábamos:

```
int main() {
```

Pero esta vez tenemos:

```
int main(int argc, char* argv[]) {
```

Aquí entran dos elementos nuevos.

| Elemento | Significado                                                                |
| -------- | -------------------------------------------------------------------------- |
| `argc`   | Cantidad de argumentos recibidos, incluyendo el nombre o ruta del programa |
| `argv`   | Arreglo de cadenas que contiene los argumentos recibidos                   |
| `char*`  | Indica que cada elemento apunta a una cadena de caracteres                 |
| `argv[]` | Permite acceder a los argumentos mediante índices                          |

Veamos una ejecución:

```
./calculadora 10 + 5
```

Cómo llegan los argumentos al programa

argv[0]

./calculadora

Programa

argv[1]

10

Primer número

argv[2]

\+

Operación

argv[3]

5

Segundo número

En esta ejecución, `argc` vale 4, porque hay cuatro elementos contando el programa.

Recuerda algo que ya aprendimos con los arreglos: los índices comienzan desde cero.

Por eso el primer número se encuentra en `argv[1]`, no en `argv[0]`.

## 4. Explicación del programa paso a paso

### A. Los prototipos

```
double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);
```

Cada prototipo anuncia una función que recibe dos números `double` y devuelve otro `double`.

Utilizamos `double` porque queremos que la calculadora también trabaje con decimales.

Por ejemplo, `dividir(5, 2)` debe devolver `2.5`.

### B. Comprobación de argumentos

```
if (argc != 4) {
    cout << "Uso: calculadora numero1 operacion numero2"
         << endl;
    return 1;
}
```

El operador `!=` significa diferente de.

Si el usuario no introduce exactamente tres argumentos adicionales, el programa muestra cómo utilizarlo y termina.

Aquí `return 1` está dentro de `main()` e indica que el programa terminó debido a un error. En cambio, `return 0` indica una finalización correcta.

### C. Conversión de datos

```
numero1 = atof(argv[1]);
operacion = argv[2][0];
numero2 = atof(argv[3]);
```

Esta parte contiene tres conceptos.

Primero, los argumentos de línea de comandos llegan como texto. Aunque escribas `10`, inicialmente es una cadena de caracteres.

Segundo, `atof()` permite convertir ese texto a un número decimal.

```
atof("10.5")
```

Produce el valor numérico `10.5`.

Tercero, `argv[2][0]` utiliza dos índices:

- `argv[2]` selecciona el argumento correspondiente a la operación.
- `[0]` obtiene su primer carácter.

Si `argv[2]` contiene `"+"`, entonces `argv[2][0]` es el carácter `'+'`.

Esto conecta con los arreglos y las cadenas de caracteres que vimos anteriormente.

### D. Selección mediante `switch`

```
switch (operacion) {
    case '+':
        resultado = sumar(numero1, numero2);
        break;

    case '-':
        resultado = restar(numero1, numero2);
        break;
}
```

Ya conoces `switch` de la unidad 2.

Se utiliza cuando tenemos varias opciones basadas en una misma variable.

Cada `case` representa una operación matemática y llama a su función correspondiente.

`break` evita que la ejecución continúe en los siguientes casos.

### E. Validación de división entre cero

```
if (numero2 == 0) {
    cout << "Error: division entre cero." << endl;
    return 1;
}
```

No debemos calcular una división cuyo divisor sea cero.

Por eso comprobamos el segundo número antes de llamar a la función `dividir()`.

### F. Funciones matemáticas

Observa lo pequeñas que son:

```
double sumar(double a, double b) {
    return a + b;
}
```

```
double dividir(double a, double b) {
    return a / b;
}
```

Cada función tiene una sola responsabilidad. Recibe los números, realiza la operación y devuelve el resultado.

Aquí está la enseñanza central: `main()` decide qué hacer y las funciones realizan los cálculos.

## 5. Cómo fluye la información

Cuando ejecutas:

```
./calculadora 8 + 4
```

Ocurre lo siguiente:

1. La terminal envía los argumentos.

   `argc = 4` y `argv` contiene el nombre del programa, `8`, `+` y `4`.
2. El programa convierte los valores.

   `numero1 = 8`, `operacion = '+'` y `numero2 = 4`.
3. `switch` identifica el operador.

   Entra al bloque `case '+'`.
4. Se ejecuta la función.

   `sumar(8, 4)` calcula 12 y lo devuelve con `return`.
5. `main()` muestra el resultado.

   `Resultado: 12`

## 6. Cómo compilarlo y ejecutarlo en tu Mac

Guarda el código como `tarea3.cpp`.

Compílalo:

```
clang++ -std=c++17 tarea3.cpp -o calculadora
```

Luego prueba estas operaciones:

| Operación         | Comando                  | Resultado |
| ----------------- | ------------------------ | --------- |
| Suma              | `./calculadora 10 + 5`   | 15        |
| Resta             | `./calculadora 10 - 5`   | 5         |
| Multiplicación    | `./calculadora 10 '*' 5` | 50        |
| División          | `./calculadora 10 / 4`   | 2.5       |
| División inválida | `./calculadora 10 / 0`   | Error     |

Atención: para multiplicar, escribe `'*'` entre comillas simples en la terminal. Sin las comillas, el intérprete de comandos puede interpretar `*` como un comodín y reemplazarlo por nombres de archivos.

Para probar la calculadora con decimales:

```
./calculadora 12.5 + 3.5
```

Resultado:

```
Resultado: 16
```

En Windows, con el compilador del laboratorio, el ejecutable normalmente tendrá extensión `.exe` y deberás adaptarte al procedimiento de compilación de Borland que utiliza el profesor.

## 7. Qué debes aprender de esta tarea

| Concepto                       | Qué significa                                      |
| ------------------------------ | -------------------------------------------------- |
| `main(int argc, char* argv[])` | Permite recibir argumentos al ejecutar el programa |
| `argc`                         | Cuenta los argumentos                              |
| `argv`                         | Almacena los argumentos como cadenas               |
| `atof()`                       | Convierte una cadena a un número decimal           |
| `argv[2][0]`                   | Obtiene el primer carácter del tercer elemento     |
| `switch`                       | Selecciona la operación                            |
| `return`                       | Devuelve un resultado o termina la función         |
| Funciones `double`             | Calculan y devuelven valores decimales             |

Hay una diferencia que no quiero que olvides:

```
resultado = sumar(numero1, numero2);
```

Aquí `sumar()` devuelve un valor que guardamos en `resultado`.

En cambio:

```
cout << resultado;
```

Solamente muestra el valor en pantalla.

Son responsabilidades distintas.

## 8. Antes de entregarla

La versión anterior es una solución de estudio para la calculadora con argumentos de línea de comandos. No pude volver a verificar el texto exacto del tercer ejercicio porque el PDF del mandato ya no está disponible para lectura en esta sesión. Por eso, no puedo garantizar que todos los operadores, prototipos y condiciones coincidan literalmente con lo que exige el profesor.

También hay un límite didáctico: `atof()` no detecta correctamente todos los textos inválidos. Por ejemplo, una cadena que no representa un número puede convertirse en `0`. Para esta etapa mantenemos la solución básica y asumimos argumentos numéricos válidos.

## 9. Resumen de las tres tareas de la unidad 5

| Tarea | Aplicación             | Aprendizaje principal                                   |
| ----- | ---------------------- | ------------------------------------------------------- |
| 1     | Fibonacci              | Funciones, parámetros, `return` y ciclos                |
| 2     | Piedra, Papel o Tijera | Funciones `void`, `char`, `string` y `bool`             |
| 3     | Calculadora            | Argumentos de línea de comandos y funciones matemáticas |

Con estas tres tareas has practicado diferentes formas de utilizar funciones.

Mi recomendación es que ahora estudies cómo se comunican `main()` y las funciones, porque es la habilidad más importante de esta unidad. Intenta modificar las operaciones de la calculadora por tu cuenta, después escribe las funciones sin mirar la solución y comprueba si puedes explicar lo que hace cada línea.

Así no dependerás de memorizar programas completos cuando el profesor te presente otro problema.
