# 09 - Punteros y Referencias

Un puntero guarda la **direccion de memoria** de una variable.
Una referencia es un "alias": un segundo nombre para la misma caja de memoria.

## Direccion (&) y desreferencia (*)

```cpp
int edad = 20;
int* ptr = &edad;    // & -> direccion de memoria de edad
                     // * -> el valor que hay en esa direccion

cout << &edad << endl;  // 0x16b... (direccion)
cout << ptr  << endl;   // la misma direccion
cout << *ptr << endl;   // 20  (desreferenciar = leer el valor apuntado)
```

## Regla mnemotecnica

- `&edad` = "direccion de edad"
- `*ptr`  = "el valor al que apunta ptr"

## Referencias (& en la declaracion)

```cpp
int a = 10;
int& ref = a;      // ref es alias de a
ref = 99;          // cambia 'a' tambien -> a == 99
```

A diferencia del puntero, la referencia no puede apuntar a otro lado y no
necesita `*` para usarse.

## Pasar por referencia a funciones

```cpp
void intercambiar(int& x, int& y) {   // recibe las MISMA variables
    int tmp = x;
    x = y;
    y = tmp;
}
```

Si usas `int x` (sin `&`), la funcion recibe una copia y el cambio no se
refleja fuera (paso por valor).

## Punteros nulos

```cpp
int* p = nullptr;   // no apunta a nada (C++ moderno)
```

Es un error usar `*p` si `p` es `nullptr` (programa se cuelga).

## Arreglos y punteros (nota)

El nombre de un arreglo se comporta como un puntero a su primer elemento:
`notas[0]` equivale a `*notas`.

## Ejemplos en esta carpeta

- `punteros_basicos.cpp` - direccion, puntero y desreferencia
- `referencia_intercambio.cpp` - swap con paso por referencia

## Retos (en `retos/`)

- `r01_*` - mostrar direcciones y valores de 3 variables
- `r02_*` - funcion que dobla un numero usando referencia
- `r03_*` - recorrer un arreglo con punteros

Siguiente tema: **10 - POO**.