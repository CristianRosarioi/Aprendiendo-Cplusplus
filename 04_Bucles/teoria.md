# 04 - Bucles

Los bucles repiten codigo. C++ tiene tres: `for`, `while` y `do-while`.

## for - repeticion con contador (num. fijo de veces)

```cpp
for (int i = 0; i < 5; i++) {
    cout << "Vuelta " << i << endl;
}
```

Partes: inicializacion `int i = 0`; condicion `i < 5`; incremento `i++`.

## while - repite mientras la condicion sea verdadera

```cpp
int contador = 1;
while (contador <= 5) {
    cout << "Contador: " << contador << endl;
    contador++;          // NO olvidarlo, si no es un bucle infinito
}
```

Pre-test: si la condicion es falsa desde el inicio, nunca ejecuta el bloque.

## do-while - ejecuta al menos una vez

```cpp
int num;
do {
    cout << "Ingresa el promedio (0-100): ";
    cin >> num;
} while (num < 0 || num > 100);   // <- OJO: lleva punto y coma al final
```

Post-test: el bloque se ejecuta siempre una vez y luego valida. Ideal para
pedir datos hasta que sean validos.

## break y continue

```cpp
break;     // sale del bucle por completo
continue;  // salta a la siguiente vuelta (se salta el codigo restante)
```

## Errores comunes

- **Bucle infinito**: olvidar actualizar la variable de control (`contador++`).
- **Condicion al reves** que nunca se cumple: el bucle no se ejecuta.
- **Faltar el `;`** al final del `do { ... } while (cond);`

## Ejemplos en esta carpeta

- `bucle_for.cpp` - tabla de multiplicar (contador)
- `bucle_while_contador.cpp` - suma de numeros ingresados
- `bucle_do_while_menu.cpp` - repetir menu hasta salir / validar dato

## Retos (en `retos/`)

- `r01_validar_promedio_resuelto.cpp` - pedir nota hasta que sea valida
- `r02_*` - tabla de multiplicar elegida por el usuario
- `r03_*` - sumar numeros hasta que ingrese 0

Siguiente tema: **05 - Funciones**.