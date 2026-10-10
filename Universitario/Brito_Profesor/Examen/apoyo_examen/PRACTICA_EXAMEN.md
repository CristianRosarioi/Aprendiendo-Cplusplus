# Cinco ejercicios nuevos para practicar

Intenta escribir cada solución en un archivo independiente con `int main()`.
Antes de programar, apunta **entrada → proceso → salida** y prueba algún
caso a mano. No hay soluciones completas aquí; consulta el índice del README
solo si te atascas.

1. **Suma de pares en un intervalo.** Lee dos enteros hasta que el primero
   sea menor que el segundo. Calcula la suma y la cantidad de pares del
   intervalo inclusivo. Si no hay pares, muestra un aviso. **Pistas:**
   `while` para validar, `% 2`, contador y acumulador; prueba `3..5`.

2. **Promedio de calificaciones aprobadas.** Lee una cantidad positiva de
   notas enteras y cuenta las de 70 o más; calcula el promedio solo de las
   aprobadas. Si ninguna aprobó, no dividas. **Pistas:** `for`, `if`, suma,
   contador y `static_cast<double>`; prueba todas las notas menores que 70.

3. **Contar una letra dentro de un nombre.** Lee nombre y apellido en una
   línea y después una letra inglesa (sin tilde). Cuenta sus apariciones
   ignorando la diferencia entre mayúsculas y minúsculas. **Pistas:**
   `getline`, recorrido con índice, `at`, `tolower` y conversión segura
   antes de `<cctype>`; prueba texto vacío.

4. **Seleccionar una operación.** Lee dos enteros y una letra: `S` para
   suma, `R` para resta o `D` para división entera. Informa si la opción
   es inválida y nunca dividas entre cero. **Pistas:** `if / else if /
   else`, `==`; puedes consultar el `switch` de unidad 2 si te interesa.

5. **Analizar una palabra.** Lee una línea y muestra si está vacía, sus
   primeros dos caracteres si tiene al menos dos, y cuántos dígitos ASCII
   contiene. **Pistas:** `empty`, `size`, `substr(0, 2)`, `isdigit` con
   argumento convertido de forma segura; prueba línea vacía y una letra.

En todos, escribe al inicio del archivo tu propio ejemplo de entrada y
salida y explica por qué se inicializan los contadores en cero.
