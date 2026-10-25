# Asistente de plantillas C++ sin internet

`asistente.cpp` es un **generador por reglas**, no una IA: propone una o varias
plantillas por palabras clave y **solo guarda código después de dos
confirmaciones** (plantilla y resumen). Si no reconoce el enunciado, presenta
un menú. El asistente y los programas que genera no necesitan red.

## Comenzar en este Mac

Este equipo es **macOS (Darwin), arm64 / Apple Silicon**. Abre Terminal y entra
en la carpeta `Examen/asistente_offline` (puedes arrastrar la carpeta desde
Finder después de escribir `cd `). **Ejecuta desde esta carpeta**: la ruta
relativa `generados/` se crea aquí, no al lado del ejecutable si lo abres
desde otra ubicación.

```sh
clang++ -std=c++11 -Wall -Wextra asistente.cpp -o asistente_mac
./asistente_mac
```

Se incluye el ejecutable **`asistente_mac` para este Mac arm64**. Un binario
macOS arm64 **no funciona directamente en Windows ni Linux**; copia el fuente
y recompila allí. En Windows, si tienes MinGW/g++ instalado:

```text
g++ -std=c++11 -Wall -Wextra asistente.cpp -o asistente.exe
asistente.exe
```

No se incluye ningún `.exe` de Windows. El generador no requiere
`<filesystem>`: usa C++11 y operaciones locales de archivos compatibles
con macOS y MinGW.

Para compilar una solución desde `asistente_offline`, sustituye su nombre
según el archivo creado:

```sh
clang++ -std=c++11 -Wall -Wextra generados/plantilla_05_multiplos_0001.cpp -o programa_generado
./programa_generado
```

En Windows, la salida puede ser `-o programa_generado.exe` y se ejecuta como
`programa_generado.exe`. **No compiles dos archivos con `main` juntos**.
El generador no compila ni ejecuta automáticamente la solución.

## Archivos

- `asistente.cpp`: fuente del generador; usa C++11.
- `asistente_mac`: ejecutable compilado en macOS arm64.
- `GUIA_DE_USO.md`: significado de preguntas, reglas, ajustes manuales.
- `ejemplos_enunciados.txt`: frases para probar modo A.
- `generados/`: contiene una salida de ejemplo por plantilla (15 archivos).
  Los nuevos archivos se nombran `plantilla_XX_tema_0001.cpp`, luego
  `0002.cpp`, etc. Se buscan nombres libres para no reemplazar trabajos
  previos. Su fuente usa C++11 básico.

Las 15 plantillas son: operaciones, comparar, validar intervalo, tabla,
múltiplos, pares/impares, signos numéricos, notas, primos, potencia,
clasificación de caracteres, vocales, aparición de un carácter, operaciones
de `string` y edad/sexo/vocal. Lee [GUIA_DE_USO.md](GUIA_DE_USO.md) antes de
usar un resultado como respuesta de examen.

## Materiales de referencia

Se revisaron los PDF de unidades 1 y 2 y el PPTX de unidad 3 en
`../contenido/`, más los 15 ejemplos y `../apoyo_examen/GUIA_CONCEPTOS.md`.
El código generado mantiene `main` único y comentarios educativos; en
clasificación ASCII utiliza `<cctype>` con conversión segura a `unsigned char`
antes de llamar a esas funciones.
