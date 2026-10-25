# Tarea 2.0 — explicación de los ejercicios

## 1. Promedio de los múltiplos de 7 (`tarea1.cpp`)

Primero se leen `numDesde` y `numHasta`. Si `numDesde` no es menor que `numHasta`, el programa vuelve a pedir ambos valores. Luego recorre el intervalo con un `while`. Cada vez que `numero % 7 == 0`, ese número se suma a un acumulador y se aumenta un contador. Al terminar, el promedio es `suma / cantidad`.

La idea importante es que el promedio necesita **dos datos**: la suma y cuántos números se sumaron. `suma` es `double` para no perder los decimales por división entera. Antes de dividir se comprueba que `cantidad` sea mayor que cero: puede ocurrir que en el intervalo no haya ningún múltiplo de 7. Por ejemplo, entre 1 y 21 se tomarían 7, 14 y 21, y el promedio sería 14.

## 2. Números primos entre 30 y 300 (`tarea2.cpp`)

El programa recorre todos los enteros desde 30 hasta 300. Para cada uno empieza suponiendo que es primo y busca un divisor desde 2. El operador `%` devuelve el residuo de una división: si `numero % divisor == 0`, la división es exacta y ese número ya no puede ser primo. En ese caso, `break` detiene la búsqueda de divisores.

Solo se comprueban divisores hasta la raíz cuadrada del número. En el código se expresa como `divisor <= numero / divisor`, sin usar otra librería. Si un número tuviera un divisor mayor que su raíz cuadrada, el divisor con el que forma pareja sería menor, así que ya lo habríamos encontrado. Al final se imprime el número únicamente si no apareció ningún divisor.

## 3. Potencia con exponente negativo (`tarea3.cpp`)

Se leen una `base` de tipo `double` y un `exponente` de tipo `int`. La potencia empieza en 1 porque ese es el resultado de cualquier base no nula elevada a 0. Después se multiplica por la base tantas veces como indique el valor absoluto del exponente. Por ejemplo, para `2` y `3`: `1 × 2 × 2 × 2 = 8`.

Cuando el exponente es negativo se toma el recíproco del producto: `2` elevado a `-3` da `1 / 8 = 0.125`. Si la base es 0 y el exponente es negativo, el programa avisa que no se puede dividir entre cero. `repeticiones` es `long long` para poder cambiar el signo incluso si se introduce el menor valor posible de un `int`. Todo el cálculo se hace con un ciclo, sin `pow`.

## Para el resumen que pide el enunciado

Al escribir tus experiencias para el foro, puedes comentar qué te costó al validar el intervalo, cómo entendiste la búsqueda de divisores y por qué el exponente negativo termina en una división. Como conclusión, los tres ejercicios practican recorridos con ciclos y decisiones con condiciones, que sirven también para filtrar datos, contar casos y hacer cálculos sin funciones ya hechas.
