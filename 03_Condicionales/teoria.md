# 03 - Condicionales

Toma de decisiones: el programa ejecuta un bloque u otro segun una condicion.

## if / else if / else

```cpp
int nota;
cout << "Ingresa tu nota (0-100): ";
cin >> nota;

if (nota >= 90 && nota <= 100) {
    cout << "Excelente - A" << endl;
} else if (nota >= 70) {
    cout << "Aprobado - C" << endl;
} else {
    cout << "Reprobado - F" << endl;
}
```

Reglas de sintaxis:
1. **Case-sensitive**: `if`, `else`, `cout` van en minusculas.
2. Condicion **siempre entre parentesis**: `if (nota >= 60)`.
3. `&&`, `||`, `==` se usan exactamente como estan (no `=>` ni `&` sueltos).

## switch

Compara una variable contra valores exactos:

```cpp
int opcion;
cin >> opcion;

switch (opcion) {
    case 1:
        cout << "Ver notas" << endl;
        break;
    case 2:
        cout << "Ver horario" << endl;
        break;
    default:
        cout << "Opcion invalida" << endl;
}
```

- `break` corta el switch (sin el, ejecuta el siguiente case).
- `default` es opcional: se ejecuta si ningun case coincide.

## Operador ternario (if corto)

```cpp
string resultado = (nota >= 60) ? "Aprobado" : "Reprobado";
```

Lee: "si la condicion es verdadera usa el primer valor, si no el segundo".

## Rangos con && y ||

En matematicas se escribe `90 <= nota <= 100`, pero en C++ eso NO funciona:
debes separarlo con `&&`: `(nota >= 90 && nota <= 100)`.

## Ejemplos en esta carpeta

- `ejemplo_if_else.cpp` - aprobado/reprobado
- `ejemplo_switch_menu.cpp` - menu con opciones
- `ejemplo_ternario.cpp` - if en una linea

## Retos (en `retos/`)

- `r01_mayor_edad_nota_resuelto.cpp` - mayor/menor de edad y aprobado
- `r02_rangos_notas_resuelto.cpp` - notas con calificacion A-B-C-F
- `r03_*` - dia de la semana con switch

Siguiente tema: **04 - Bucles**.