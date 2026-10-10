# Carpeta de apoyo para el examen práctico de C++

Los 15 archivos `.cpp` son programas **independientes**. Abre el que se parezca
al enunciado del examen; cada uno trae problema, algoritmo, ejemplo y comentarios.
Consulta también [GUIA_CONCEPTOS.md](GUIA_CONCEPTOS.md) y practica con
[PRACTICA_EXAMEN.md](PRACTICA_EXAMEN.md). Todo se puede leer sin internet.

## Índice y elección rápida

| Archivo | Si el problema pide… |
| --- | --- |
| [01_operaciones_basicas.cpp](01_operaciones_basicas.cpp) | operar dos enteros, división y residuo; evitar divisor cero |
| [02_condiciones.cpp](02_condiciones.cpp) | comparar valores y escoger una de varias respuestas |
| [03_validacion_intervalo.cpp](03_validacion_intervalo.cpp) | volver a pedir un intervalo hasta que sea válido |
| [04_tabla_multiplicar.cpp](04_tabla_multiplicar.cpp) | repetir una cantidad conocida de veces con `for` |
| [05_contadores_acumuladores.cpp](05_contadores_acumuladores.cpp) | contar categorías y acumular una suma |
| [06_promedio_multiplos_7.cpp](06_promedio_multiplos_7.cpp) | validar, detectar múltiplos, sumar y promediar |
| [07_numeros_primos.cpp](07_numeros_primos.cpp) | examinar divisores y encontrar primos |
| [08_potencia_sin_pow.cpp](08_potencia_sin_pow.cpp) | potencias sin `pow`, exponentes cero o negativos |
| [09_lectura_texto.cpp](09_lectura_texto.cpp) | leer nombre con espacios, usar `size`, `at`, `cin.ignore` |
| [10_clasificar_caracteres.cpp](10_clasificar_caracteres.cpp) | clasificar letras, dígitos y puntuación con `<cctype>` |
| [11_contar_vocales.cpp](11_contar_vocales.cpp) | recorrer texto, normalizar y contar vocales |
| [12_buscar_caracter.cpp](12_buscar_caracter.cpp) | contar apariciones de un carácter por posición |
| [13_modificar_cadena.cpp](13_modificar_cadena.cpp) | insertar, borrar y agregar un carácter a `string` |
| [14_subcadenas_comparaciones.cpp](14_subcadenas_comparaciones.cpp) | extraer subcadenas, comprobar vacío y comparar textos |
| [15_ejercicio_integrador.cpp](15_ejercicio_integrador.cpp) | combinar edad, sexo, condiciones anidadas y texto |

## Compilar y ejecutar

Abre la terminal **en esta carpeta**. En macOS/Linux, elige `clang++` o `g++`
según tengas instalado; por ejemplo, para el primer archivo:

```sh
clang++ -std=c++11 -Wall -Wextra 01_operaciones_basicas.cpp -o 01_operaciones_basicas
./01_operaciones_basicas
```

Para cualquier otro: sustituye en **ambos** lugares el nombre, por ejemplo:

```sh
g++ -std=c++11 -Wall -Wextra 06_promedio_multiplos_7.cpp -o 06_promedio_multiplos_7
./06_promedio_multiplos_7
```

En Windows con MinGW, compila con `g++` y usa, por ejemplo,
`-o 06_promedio_multiplos_7.exe`; ejecútalo con `06_promedio_multiplos_7.exe`.
**No compiles los 15 `.cpp` juntos:** cada uno define su propio `main`.
La carpeta de apoyo lleva código y textos, no necesita ejecutables guardados.

Se supone que introduces los tipos solicitados (números para las lecturas
numéricas). Los ejemplos numéricos suponen resultados representables por sus
tipos; los textos suelen ser cortos y las pruebas de caracteres se centran en
ASCII. Las letras con tilde, la `ñ` y otros caracteres Unicode requieren un
tratamiento distinto para longitud y clasificación. Los exponentes enormes
pueden desbordar o perder precisión en `double`.


en windows

Bcc32-c espacio nombre del archivo. Cpp

Bcc32-l espacio, nombre del archivo . Obj