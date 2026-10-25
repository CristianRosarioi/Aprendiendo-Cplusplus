# Tarea 3.0 — explicación de los ejercicios

Cada archivo `.cpp` es un programa independiente. Para compilar desde esta carpeta, por ejemplo: `g++ tarea1.cpp -o tarea1`. Después se ejecuta con `./tarea1` (para los otros ejercicios se cambia el número). Las variables se declaran antes de `main`, fuera de la función, como pide el profesor. Las líneas vacías solo separan partes del código; las llaves `{` y `}` abren y cierran los bloques.

## 1. Contar tipos de caracteres (`tarea1.cpp`)

Se lee una línea completa y se revisa carácter por carácter. Un mismo carácter puede contarse en más de una categoría: una `A` cuenta como mayúscula y como alfanumérica; un `7` cuenta como dígito y como alfanumérico. **Alfanumérico** significa letra o dígito, como en `isalnum` del ejemplo `u3ej09.cpp` del profesor. Los espacios no se cuentan en ninguna de estas cinco categorías.

| Línea | Qué hace |
| --- | --- |
| 1 | Abre el comentario de presentación. |
| 2 | Indica la universidad. |
| 3 | Indica el centro y la escuela. |
| 4 | Indica la asignatura. |
| 5 | Indica el nombre del estudiante. |
| 6 | Indica la matrícula. |
| 7 | Cierra el comentario de presentación. |
| 9 | Incluye `iostream` para `cin` y `cout`. |
| 10 | Incluye `string` para guardar el texto. |
| 11 | Incluye `cctype` para las funciones que clasifican caracteres. |
| 12 | Permite escribir `cout` y `string` sin anteponer `std::`. |
| 14 | Declara fuera de `main` la variable que guardará el texto. |
| 15 | Inicia en cero el contador de mayúsculas. |
| 16 | Inicia en cero el contador de minúsculas. |
| 17 | Inicia en cero el contador de dígitos. |
| 18 | Inicia en cero el contador de signos de puntuación. |
| 19 | Inicia en cero el contador de letras y dígitos juntos. |
| 20 | Declara el índice `i` para recorrer el texto. |
| 21 | Declara el carácter actual como `unsigned char` para usarlo correctamente con `cctype`. |
| 23 | Comienza la función `main`, donde inicia el programa. |
| 24 | Pide al usuario que escriba un texto. |
| 25 | Lee la línea completa, incluidos los espacios. |
| 27 | Comienza el ciclo en la posición cero y recorre el texto hasta la última posición. |
| 28 | Guarda en `caracter` el carácter de la posición actual. |
| 30 | Comprueba si el carácter es una letra mayúscula. |
| 31 | Si lo es, suma uno al contador de mayúsculas. |
| 32 | Cierra la condición de mayúsculas. |
| 33 | Comprueba si el carácter es una letra minúscula. |
| 34 | Si lo es, suma uno al contador de minúsculas. |
| 35 | Cierra la condición de minúsculas. |
| 36 | Comprueba si el carácter es un dígito. |
| 37 | Si lo es, suma uno al contador de dígitos. |
| 38 | Cierra la condición de dígitos. |
| 39 | Comprueba si el carácter es un signo de puntuación, como `!` o `.`. |
| 40 | Si lo es, suma uno al contador de puntuación. |
| 41 | Cierra la condición de puntuación. |
| 42 | Comprueba si el carácter es una letra o un dígito. |
| 43 | Si lo es, suma uno al contador de alfanuméricos. |
| 44 | Cierra la condición de alfanuméricos. |
| 45 | Cierra el ciclo después de revisar todos los caracteres. |
| 47 | Muestra la cantidad de mayúsculas. |
| 48 | Muestra la cantidad de minúsculas. |
| 49 | Muestra la cantidad de dígitos. |
| 50 | Muestra la cantidad de signos de puntuación. |
| 51 | Muestra la cantidad de alfanuméricos. |
| 53 | Indica que el programa terminó correctamente. |
| 54 | Cierra `main`. |

Por ejemplo, con `Hola 2!`, el resultado es 1 mayúscula, 3 minúsculas, 1 dígito, 1 signo de puntuación y 5 alfanuméricos. Como las funciones revisan caracteres individuales, el ejemplo más sencillo para probarlas es texto sin tildes.

## 2. Nombre y apellido en vertical (`tarea2.cpp`)

El programa sigue el ejemplo de iteradores `u3ej08.cpp`. Un iterador señala una posición del `string`: `begin()` señala el primer carácter y `end()` señala la posición después del último. El espacio entre el nombre y el apellido también ocupa una línea (se ve como una línea vacía).

| Línea | Qué hace |
| --- | --- |
| 1 | Abre el comentario de presentación. |
| 2 | Indica la universidad. |
| 3 | Indica el centro y la escuela. |
| 4 | Indica la asignatura. |
| 5 | Indica el nombre del estudiante. |
| 6 | Indica la matrícula. |
| 7 | Cierra el comentario de presentación. |
| 9 | Incluye las herramientas de entrada y salida. |
| 10 | Incluye el tipo `string`. |
| 11 | Permite usar nombres de la biblioteca sin `std::`. |
| 13 | Declara fuera de `main` una sola variable para nombre y apellido. |
| 14 | Declara fuera de `main` el iterador que recorrerá esa cadena. |
| 16 | Inicia `main`. |
| 17 | Pide el nombre completo. |
| 18 | Lo lee con espacios mediante `getline`. |
| 20 | Coloca el iterador `letra` al comienzo del nombre leído. |
| 21 | Repite el ciclo mientras no llegue al final de la cadena. |
| 22 | `*letra` obtiene el carácter actual y `endl` salta a la próxima línea. |
| 23 | Avanza el iterador al siguiente carácter. |
| 24 | Cierra el ciclo. |
| 26 | Indica que el programa terminó correctamente. |
| 27 | Cierra `main`. |

## 3. Factura y descuento (`tarea3.cpp`)

Como en los ejemplos de estructuras `u3ej06.cpp` y `u3ej10.cpp`, se guardan varios datos en una sola variable de tipo `Factura`. Solo se leen los cuatro primeros miembros; los dos últimos se calculan. Las condiciones se revisan desde el monto mayor hasta el menor para aplicar un solo porcentaje.

| Monto bruto | Descuento |
| --- | --- |
| Menor que 20 000 | 0 % |
| Desde 20 000 hasta menos de 30 000 | 7 % |
| Desde 30 000 hasta menos de 50 000 | 10 % |
| Desde 50 000 en adelante | 14 % |

| Línea | Qué hace |
| --- | --- |
| 1 | Abre el comentario de presentación. |
| 2 | Indica la universidad. |
| 3 | Indica el centro y la escuela. |
| 4 | Indica la asignatura. |
| 5 | Indica el nombre del estudiante. |
| 6 | Indica la matrícula. |
| 7 | Cierra el comentario de presentación. |
| 9 | Incluye `iostream` para leer y mostrar información. |
| 10 | Incluye `string` para los datos de texto. |
| 11 | Incluye `iomanip` para mostrar los montos con dos decimales. |
| 12 | Permite usar `cin`, `cout` y `string` sin escribir `std::`. |
| 14 | Define la estructura `Factura`. |
| 15 | Declara el número de factura, de tipo `long`. |
| 16 | Declara el nombre del cliente, de tipo `string`. |
| 17 | Declara la fecha, de tipo `string`. |
| 18 | Declara el monto bruto, de tipo `double`. |
| 19 | Declara el valor del descuento, de tipo `double`. |
| 20 | Declara el monto neto, de tipo `double`. |
| 21 | Cierra la definición de la estructura con `};`. |
| 23 | Declara fuera de `main` la variable `factura` con todos los miembros de la estructura. |
| 25 | Inicia `main`. |
| 26 | Pide el número de factura. |
| 27 | Lee el número y lo guarda en `factNumero`. |
| 28 | Descarta el salto de línea que dejó `cin` antes de usar `getline`. |
| 29 | Pide el nombre del cliente. |
| 30 | Lee el nombre completo, incluidos los espacios. |
| 31 | Pide la fecha. |
| 32 | Lee la fecha como texto. |
| 33 | Pide el monto bruto. |
| 34 | Lee el monto en `factMonto`. |
| 36 | Comprueba primero si el monto es de 50 000 o más. |
| 37 | Calcula el 14 % del monto si se cumple esa condición. |
| 38 | Si no, comprueba si el monto es de 30 000 o más. |
| 39 | Calcula el 10 % del monto si se cumple. |
| 40 | Si no, comprueba si el monto es de 20 000 o más. |
| 41 | Calcula el 7 % del monto si se cumple. |
| 42 | Si no se cumplió ninguna condición, entra en este último caso. |
| 43 | Asigna descuento cero a los montos menores de 20 000. |
| 44 | Cierra las condiciones del descuento. |
| 46 | Resta el descuento al monto bruto y guarda el resultado en `factNeto`. |
| 48 | Establece que los números decimales se muestren con dos cifras después del punto. |
| 49 | Muestra un título para los datos; `\n` deja una línea en blanco antes. |
| 50 | Muestra el número de factura. |
| 51 | Muestra el cliente. |
| 52 | Muestra la fecha. |
| 53 | Muestra el monto bruto. |
| 54 | Muestra el valor del descuento. |
| 55 | Muestra el monto neto. |
| 57 | Indica que el programa terminó correctamente. |
| 58 | Cierra `main`. |

Por ejemplo, con monto bruto de `30000`, el descuento es `3000` y el monto neto es `27000`.

## Entrega

El mandato pide incluir los tres archivos `.cpp` en un ZIP o RAR junto con capturas de la **compilación** y la **corrida** de cada programa. Tras ejecutar los programas en tu equipo, toma esas capturas y agrégalas al comprimido.
