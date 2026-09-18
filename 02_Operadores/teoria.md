# 02 - Operadores

Los operadores permiten calcular y comparar valores.

## Aritmeticos

| Operador | Operacion   | Ejemplo   |
|----------|-------------|-----------|
| `+`      | Suma        | `a + b`   |
| `-`      | Resta       | `a - b`   |
| `*`      | Producto    | `a * b`   |
| `/`      | Division    | `a / b`   |
| `%`      | Modulo/residuo | `a % b`|

> CUIDADO: si divides dos `int`, el resultado es `int` (se trunca la parte decimal).
> `7 / 2 == 3`, no 3.5. Para decimales usa `double` o `float`.

## Relacionales (comparacion)

| Operador | Significado      |
|----------|------------------|
| `==`     | Igual a          |
| `!=`     | Diferente de     |
| `>`      | Mayor que        |
| `<`      | Menor que        |
| `>=`     | Mayor o igual    |
| `<=`     | Menor o igual    |

## Logicos

| Operador | Significado |
|----------|-------------|
| `&&`     | AND (y)     |
| `\|\|`   | OR (o)      |
| `!`      | NOT (no)    |

## Asignacion abreviada

```cpp
edad  += 1;   // edad = edad + 1
total -= 5;   // total = total - 5
total *= 2;   // total = total * 2
edad  ++;     // edad = edad + 1
edad  --;     // edad = edad - 1
```

## == vs = (error clasico universitario)

- `=` asigna: `int x = 10;`
- `==` compara: `if (x == 10)`

## Precedencia y parentesis

Usa parentesis para que no haya ambiguedad: `promedio = (a + b) / 2;`
(sin parentesis, `a + b / 2` divide primero).

## Ejemplos en esta carpeta

- `area_triangulo.cpp` - base * altura / 2
- `area_triangulo_cin_multiple.cpp` - leer varios datos en un solo `cin >> a >> b`
- `division_int_vs_double.cpp` - la diferencia entre dividir int y double

## Retos (en `retos/`)

- `r01_*` - convertir grados Celsius a Fahrenheit
- `r02_*` - calcular promedio y mostrar el residuo de una division
- `r03_*` - operaciones con IVA

Siguiente tema: **03 - Condicionales**.