# Guía de uso y comprobación

## Elegir plantilla

1. Desde `asistente_offline` ejecuta `./asistente_mac` (macOS) o recompila
   `asistente.cpp` y ejecuta el resultado en tu sistema.
2. Selecciona `1` para escribir un enunciado o `2` para ver las 15 plantillas.
3. En modo 1, elige expresamente una propuesta. Cada opción explica qué
   palabras la activaron. Si ninguna coincide, escribe `0` para abrir el menú.
4. Confirma la plantilla (`s`) o vuelve al inicio (`n`). Contesta sus preguntas,
   revisa el **resumen**, y responde `s` solo si describe tu problema. `n`
   cancela sin crear un archivo.
5. Mira el `.cpp` en `generados/`, especialmente el enunciado y el algoritmo
   explicados en su cabecera. Compílalo **por separado**, dale datos cuando
   se ejecute y compara con una prueba hecha a mano.

## Qué reconoce y qué no

Las reglas reconocen familias de palabras: `promedio`, `suma`, `cantidad`,
`múltiplos`, `pares/impares`, `notas`, `primos`, `potencia`, `vocales`,
`mayúsculas`, `minúsculas`, `dígitos`, `puntuación`, `alfanuméricos`,
`carácter`, `tabla`, `comparar`, `validar`, `string`, `edad` y `sexo`.
Tratan formas frecuentes con y sin tilde (por ejemplo `múltiplos/multiplos`).
No eliminan de manera general caracteres UTF-8; las secuencias que no forman
parte de ese pequeño mapa no se interpretan. Una coincidencia **no** demuestra
que toda la frase se haya entendido. El texto libre original **no se copia al
código**, ni siquiera a sus comentarios: las plantillas redactan su propio
enunciado a partir de opciones controladas. Esto también impide que una
secuencia `*/` introducida en una frase cierre accidentalmente un comentario.

Palabras fuera de alcance (como `archivos`, `ordenar`, `mediana`, `factorial`)
o filtros simultáneos incompatibles dan aviso y requieren aceptar
explícitamente el ajuste. Una petición de `while` para una plantilla que solo
ofrece `for` también da aviso. No detecta todas las reglas, negaciones o
restricciones de lenguaje natural: **si el resumen no cubre una condición
del examen, cancela y modifica tú el programa**. La ruta del asistente
siempre es relativa al directorio desde el que se lanza.

## Parámetros frente a datos de entrada

Un *parámetro del algoritmo* se decide **en el asistente**, antes de escribir
el archivo: por ejemplo divisor, elegir suma/cantidad/promedio, ambos extremos
incluidos o excluidos, `while` o `for`, umbral de aprobado, categorías de
caracteres, comparación sensible a mayúsculas. Los límites fijos, el número
fijo de una tabla y un carácter fijo se incluyen como valores en el fuente
tras validarlos. No introduzcas código C++ en estas respuestas.

Los *datos de entrada* se preguntan **al ejecutar el programa generado**:
los dos números de una operación, notas, edad y nombre; también límites de
un intervalo si escogiste lectura por teclado. Si escoges `getline`, se
pueden introducir espacios; si escoges `cin >>`, se lee solo una palabra.
En el ejemplo edad/sexo, pon cada dato en su propia línea. Las preguntas
del asistente usan validación para opciones y parámetros; las soluciones
generadas suponen números escritos correctamente (nivel inicial del curso).

En intervalo, marcar `validar inicio < final` fuerza esa relación aun cuando
decidas excluir extremos: por ejemplo `[3,4]` excluyendo ambos queda vacío.
Si hay promedio, se comprueba que haya elementos seleccionados antes de
dividir. Se prohíbe el divisor cero para múltiplos, y el programa de potencia
impide base cero con exponente negativo. Los límites se recorren con `break`
al alcanzar el último valor para evitar incrementar un `int` máximo.

## Adaptar un resultado manualmente

- Identifica *entrada, proceso y salida* del enunciado y comprueba que los
  `cin`/`getline` del archivo piden los datos correctos. Si necesitas otro
  filtro, cambia la condición `if` dentro del ciclo. `==` compara; `=` asigna.
- Para incluir un extremo usa `<=`; para excluirlo usa `<` o la condición de
  borde dentro del ciclo. Verifica rangos negativos: `numero % 2 != 0`
  identifica impares positivos y negativos.
- En `for (inicio; condicion; avance)`, comprueba que el control avance y que
  la condición se vuelva falsa; en `while`, modifica el contador dentro del
  cuerpo. Haz una prueba de escritorio con un intervalo de 2 o 3 valores.
- Si agregas otro `if`, decide si puede coincidir con los anteriores: las
  categorías de `<cctype>` usan `if` independientes porque `isalnum` también
  cuenta las letras y los dígitos. Para opciones excluyentes usa `else if`.
- Antes de `/`, revisa divisor cero y el contador de elementos cuando pides
  promedios. `static_cast<double>(suma)` **antes** de dividir conserva decimales.

Prueba una entrada normal, una vacía si hay `getline`, un intervalo sin
elementos y un límite incorrecto. Consulta los 15 `.cpp` de
`../apoyo_examen/` cuando necesites comparar soluciones comentadas.

## Límites

Cada programa generado tiene **un solo `main`**. Los acumuladores `int`
pueden desbordarse; `double` tiene precisión y rango finitos; las potencias
con exponentes enormes pueden tardar o exceder ese rango. `size()` y `at()`
recorren bytes: la `ñ`, vocales acentuadas y otros caracteres Unicode no se
procesan como letras Unicode completas. `<cctype>` recibe cada byte mediante
`static_cast<unsigned char>` para evitar argumentos negativos, pero eso no
resuelve Unicode. La comparación sin distinguir mayúsculas es básica (ASCII).
