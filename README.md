# Pruebas C++

Repositorio para aprender y practicar **C++ desde cero hasta nivel universitario**. Organizado por temas: cada carpeta `NN_Tema` contiene su `teoria.md`, sus `ejemplos/` (codigos resueltos) y sus `retos/` (ejercicios para practicar).

## Mapa de estudio (de inicio a fin)

| # | Tema | Contenido | Estado |
|---|------|-----------|--------|
| 01 | Sintaxis Basica | Hola mundo, tipos, variables, cin/cout | Hecho |
| 02 | Operadores | Aritmeticos, comparacion, logicos, asignacion | Hecho |
| 03 | Condicionales | if / else if / else, switch, ternario | Hecho |
| 04 | Bucles | for, while, do-while, break/continue | Hecho |
| 05 | Funciones | Params, retorno, void, prototipos | Pendiente |
| 06 | Arrays y Vectores | Arreglos fijos, std::vector | En progreso |
| 07 | Strings | string, getline, metodos, char arrays | Hecho |
| 08 | Structs y Enums | struct, enum | Pendiente |
| 09 | Punteros y Referencias | &, *, null, referencias | Pendiente |
| 10 | POO | clases, encapsulacion, metodos | Pendiente |
| 11 | Herencia y Polimorfismo | herencia, override, virtual | Pendiente |
| 12 | Memoria y Archivos | new/delete, fstream | Pendiente |
| 13 | STL y C++ Moderno | vector, map, auto, lambda | Pendiente |

## Estructura del repositorio

```
Pruebas C++
├── README.md                   <- este indice (empieza aqui)
├── Aprende_C++.md              <- guia maestra de repaso
├── 01_Sintaxis_Basica/ ... 13  <- cada tema con teoria/ejemplos/retos
├── Fundamentos/                <- notas teoricas sueltas
├── Universitario/              <- tareas entregadas de la universidad
├── scripts/build.sh            <- compilador automatico
└── build/                      <- ejecutables (ignorados por git)
```

## Como compilar y ejecutar

```bash
# Compilacion automatica (recomendado): guarda el .exe en build/
./scripts/build.sh 06_Arrays_y_Vectores/retos/r01_calculadora_semestre.cpp

# Compilacion manual
g++ -std=c++17 programa.cpp -o build/programa

# Ejecutar
./build/programa
```

## Guia de estudio

El **orden recomendado** es el numerado de la tabla (01 -> 13). Para cada tema:

1. Lee `teoria.md`.
2. Revisa los `ejemplos/` y compilalos.
3. Resuelve los `retos/` (empieza por r01).

Complementa con `Aprende_C++.md` (guia general) y `Fundamentos/` (notas).

## Referencias utiles

- W3Schools C++: https://www.w3schools.com/cpp/
- Referencia del lenguaje: https://cplusplus.com/reference/
- Compilador en linea (probar sin instalar): https://www.onlinegdb.com/