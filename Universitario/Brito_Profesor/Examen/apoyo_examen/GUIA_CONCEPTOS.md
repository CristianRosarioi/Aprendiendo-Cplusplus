# Guía de conceptos y límites del material

## De dónde sale cada técnica

Se revisaron los documentos originales de `Examen/contenido/`: PDF **unidad 1,
Iniciando con C++** y PDF **unidad 2, Estructuras de Control**; el material de
**unidad 3, Cadenas y estructuras** está en **PPTX**, no en PDF, y se revisó
su texto y los `.cpp` de `Tarea3.0/ejemplos/UNIDAD_3_-_Ejemplos1/`. Se leyeron
los enunciados `Tarea2.0/mandato.txt` y `Tarea3.0/mandato.txt` y se compararon
las soluciones del alumno, que no son por sí solas prueba de enseñanza.

**Confirmado en los materiales distribuidos:** unidad 1: `#include <iostream>`,
`using namespace std`, `cin`, `cout`, `endl`, `int main()`, `return 0`,
variables e inicialización, `int`, `double`, `char`, operadores aritméticos
(`%`, `++`, `+=`, `*=` incluidos), relacionales y lógicos, conversión
`static_cast`, `getline` con `string` y `cin.ignore`. Unidad 2: `if`, `else if`,
`else`, condiciones anidadas, `while`, `for`, `do-while`, `switch`, `break`,
`continue` y ejemplos de tablas y factorial. Unidad 3: `#include <string>`,
`string`, `getline`, índices desde cero, `size`, `at`, `substr`, `insert`,
`erase`, `empty`, comparación lexicográfica y `<cctype>` con `isupper`,
`islower`, `isdigit`, `ispunct`, `isalnum`, `tolower`. `push_back` aparece
en el archivo de ejemplo del profesor `u3ej01.cpp` que acompaña esa unidad,
aunque no figura en el listado de recursos de las diapositivas. Los
**contadores y acumuladores** están ilustrados por la inicialización de la
unidad 1 y ejercicios de las unidades 2 y 3.

**Enunciados de tareas, no explicación de técnicas nuevas:** el mandato de
Tarea 2 pide explícitamente intervalo, promedio de múltiplos de 7 con `while`,
primos de 30 a 300 y potencias sin `pow` con exponentes negativos. El de
Tarea 3 pide clasificación con `<cctype>`; un ejercicio en aula del alumno
combina edad, sexo y vocal. Las decisiones usadas en `tarea1.cpp`,
`tarea3.cpp` y `tareaenaula.cpp` pueden haber sido asistidas por IA: no son
evidencia adicional del temario. En particular, que la solución del alumno
use `unsigned char` o `long long` no obliga a repetirlos.

**Adaptaciones:** los ejemplos usan `int` para contadores y `double` para
promedios y potencias. La unidad 1 menciona `unsigned int` en una tabla y la
unidad 2 muestra un factorial con `unsigned long long`, pero ninguno es
necesario aquí. No se declaran variables `unsigned` ni `long long`. En los
ejemplos 10, 11 y 15, la conversión `static_cast<unsigned char>(...)` es
**solo un paso obligatorio para pasar un byte válido a `<cctype>`**: no es
un contador ni una variable sin signo. El profesor explica `static_cast`,
pero ese detalle de seguridad de `<cctype>` no está desarrollado en las
diapositivas; está documentado en el propio código. Se evitan iteradores,
estructuras y funciones propias aunque aparezcan en el material, para dejar
los algoritmos centrados en `main` y en índices sencillos. Se usa `break`
solo en 06 para terminar el recorrido inclusivo sin incrementar `int` tras
el límite final. En 08, contar exponentes negativos hacia cero evita negar
el mínimo `int` y no introduce `long long`.

## Base de un programa

```cpp
#include <iostream>
using namespace std;
int main() {
    int edad = 18; // inicializada: contiene un valor conocido
    cout << edad << endl;
    return 0;
}
```

`cin >> edad` lee un número; `cout << edad << endl` lo muestra y acaba la
línea. `int` almacena enteros; `double`, valores con decimales; `char`, un
carácter (`'A'`); `string`, una secuencia (`"Ana Maria"`) que requiere
`#include <string>`. Las comillas simples son para `char` y las dobles para
textos. No se deben usar valores de variables sin inicializar.

## Cálculos y decisiones

`+`, `-`, `*`, `/` hacen operaciones habituales; `%` es el residuo **entre
enteros**: `14 % 7 == 0`. `=` asigna (`suma = 0`); `==` pregunta igualdad
(`if (suma == 0)`). `!=` es distinto; `<`, `>`, `<=`, `>=` comparan.
`&&` exige ambas condiciones; `||`, al menos una. El divisor de `/` y `%`
no puede ser cero.

`5 / 2` da `2` (división entera); `5.0 / 2` da `2.5`.
Para una suma entera: `double media = static_cast<double>(suma) / cantidad;`
Solo se divide si `cantidad > 0`. Convertir **después** de la división
no recupera decimales ya truncados.

```cpp
if (edad >= 18) {
    cout << "Mayor" << endl;
} else {
    cout << "Menor" << endl;
}
```

`else if` sirve para una tercera opción; un `if` dentro de otro sirve para
edad **según** sexo. Con llaves queda claro qué instrucciones pertenecen
a cada rama.

## Ciclos, contadores y acumuladores

```cpp
int contador = 0; // cuenta sucesos, normalmente suma 1
int suma = 0;     // acumula valores que pueden ser distintos
for (int i = 1; i <= 3; i++) {
    contador++; // contador = contador + 1
    suma += i;  // suma = suma + i
}
```

`for (inicio; condicion; avance)` es útil para repeticiones conocidas.
`while (inicio >= final) { /* volver a leer */ }` repite mientras el
intervalo sea inválido. Un `while` puede ejecutarse cero veces. Hay que
modificar el dato del que depende la condición para evitar un ciclo infinito.
`potencia *= base` significa `potencia = potencia * base`; una potencia
comienza en **1**, porque 1 es el factor neutro y el exponente cero no
realiza multiplicaciones. Para exponentes negativos se multiplica `1/base`
tantas veces como corresponda; `base == 0` en este caso no está permitido.

## Cadenas, posiciones y entrada con espacios

```cpp
#include <string>
string nombre;
getline(cin, nombre); // acepta espacios, también una línea vacía
int longitud = static_cast<int>(nombre.size()); // textos pequeños
for (int i = 0; i < longitud; i++) {
    cout << nombre.at(i) << endl;
}
```

Si la cadena tiene longitud N, sus índices van de **0 a N-1**; `at(N)`
queda fuera de rango. Antes de `at(0)` en una cadena posiblemente vacía,
comprueba `!nombre.empty()`. `substr(1, 2)` toma **dos** caracteres desde
el índice 1. `insert(3, " de")` añade texto en el índice 3;
`erase(3, 3)` borra tres caracteres desde ahí; `push_back('!')` añade
un `char` al final. En los tres últimos casos el cambio persiste para
la operación siguiente. Las comparaciones de `string` (`<`, `==`) miran
caracteres lexicográficamente; `"casa" < "caso"` es verdadero aunque
ambas palabras tienen igual longitud.

Después de `cin >> edad`, si la edad se escribe sola en la línea, el ENTER
queda pendiente: `cin.ignore(); getline(cin, nombre);` consume ese ENTER.
Si el usuario escribe más datos en **esa misma línea**, un solo `ignore()`
solo descarta un carácter: introduce cada dato en la línea indicada.

## Clasificación de caracteres (`<cctype>`)

`isupper(c)` prueba mayúscula; `islower(c)`, minúscula; `isdigit(c)`,
dígito; `ispunct(c)`, puntuación; `isalnum(c)`, letra o dígito;
`tolower(c)` devuelve la versión minúscula cuando exista. Ejemplo:

```cpp
#include <cctype>
int c = static_cast<unsigned char>(nombre.at(i));
if (isalnum(c)) { contador++; }
```

Esas funciones exigen `EOF` o un valor representable como `unsigned char`.
Un `char` puede contener un byte negativo: convertirlo **antes** de llamar
a la función evita comportamiento indefinido. La conversión explícita a
`unsigned char` está justificada exclusivamente aquí. Las condiciones de
las categorías se prueban independientemente porque una `A` puede ser
mayúscula **y** alfanumérica. `tolower` no traduce texto Unicode completo.

## Errores comunes y límites

| Síntoma | Revisa |
| --- | --- |
| Error de compilación cerca de `return` | Falta `;`, comillas o una llave anterior. |
| `getline` devuelve texto vacío tras `cin >>` | Quedó un ENTER: revisa `cin.ignore()`. |
| `at` da error de rango | Índice fuera de 0..N-1 o cadena vacía. |
| Promedio incorrecto o división por cero | ¿Había elementos? ¿Convertiste antes de dividir? |
| Ciclo no termina o omite el último | ¿Se incrementa el control? ¿Se usa `<` o `<=`? |
| `if` elige la rama equivocada | Diferencia `=` de `==` y revisa `&&`/`||`. |
| Varias definiciones de `main` | Compila solo un `.cpp` por vez. |

Los ejemplos no son analizadores de entradas no numéricas. Con `int`, la
suma, multiplicación y contadores tienen un límite; con `double`, la
precisión y magnitud también. Un texto UTF-8 con `á`, `ñ` o emojis ocupa
varios bytes: `size()` y `at(i)` trabajan por byte y `<cctype>` no clasifica
correctamente todos esos caracteres como letras. Se emplean textos de
tamaño habitual cuyo número de bytes cabe en `int`; no se prometen
resultados para cantidades extraordinariamente grandes.
