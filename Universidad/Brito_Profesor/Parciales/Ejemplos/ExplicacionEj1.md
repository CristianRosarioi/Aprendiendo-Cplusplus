# Simulacro de parcial de C++ — UASD

Para el parcial de mañana, 8 de noviembre de 2026, vamos a preparar un programa parecido a los ejercicios que suele colocar el profesor Brito: un enunciado práctico que te obligue a combinar varias unidades, en lugar de resolver conceptos por separado.

Voy a utilizar como referencia las tareas que hemos trabajado: estudiantes, facturas, máquina de bebidas, vectores, ciclos y funciones.

## 1. Enunciado de práctica: Sistema de control de estudiantes

Desarrolle un programa en C++ que permita registrar y consultar las calificaciones de un grupo de estudiantes mediante un menú.

Requisitos:

1. Crear una estructura `Estudiante` que contenga matrícula, nombre, apellido, edad y nota final.
2. Utilizar un `vector` para almacenar hasta cinco estudiantes.
3. Crear funciones para mostrar el menú, registrar estudiantes, mostrar registros, calcular estadísticas y buscar estudiantes.
4. Validar que la edad sea mayor que cero y que la nota esté entre 0 y 100.
5. Mostrar todos los estudiantes utilizando un ciclo `for`.
6. Determinar la nota mayor, la menor, el promedio y la cantidad de aprobados y reprobados.
7. Buscar un estudiante por matrícula.
8. Utilizar un `do-while` para repetir el menú hasta que el usuario seleccione salir.
9. Presentar las notas con dos decimales.

Conceptos del curso que practicarás

Variables y operadores

if / else

switch / case

for y while

do-while

struct

vector y at()

size() y push_back()

Funciones y parámetros

Paso por referencia

Acumuladores

iomanip

Este programa también utiliza un vector de estructuras, que es una combinación muy importante de las unidades IV y V.

## 2. Código completo — `simulacro_parcial.cpp`

Lo mantendremos dentro de los conceptos estudiados, sin clases, punteros manuales, algoritmos avanzados ni bibliotecas adicionales innecesarias.

```cpp

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Estructura para los datos del estudiante
struct Estudiante {
    long matricula;
    string nombre;
    string apellido;
    int edad;
    double notaFinal;
};

// Prototipos de las funciones
void mostrarMenu();
void registrar(vector<Estudiante> &estudiantes);
void mostrarEstudiantes(vector<Estudiante> &estudiantes);
void calcularEstadisticas(vector<Estudiante> &estudiantes);
void buscarEstudiante(vector<Estudiante> &estudiantes);

int main() {

    vector<Estudiante> estudiantes;

    int opcion;

    cout << fixed << setprecision(2);

    do {
        mostrarMenu();

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        while (opcion < 0 || opcion > 4) {
            cout << "Opcion invalida. Intente otra vez: ";
            cin >> opcion;
        }

        switch (opcion) {

            case 1:
                registrar(estudiantes);
                break;

            case 2:
                mostrarEstudiantes(estudiantes);
                break;

            case 3:
                calcularEstadisticas(estudiantes);
                break;

            case 4:
                buscarEstudiante(estudiantes);
                break;

            case 0:
                cout << "Programa finalizado." << endl;
                break;
        }

    } while (opcion != 0);

    return 0;
}

// Funcion para mostrar el menu
void mostrarMenu() {

    cout << "\n===== CONTROL DE ESTUDIANTES =====" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Mostrar estudiantes" << endl;
    cout << "3. Calcular estadisticas" << endl;
    cout << "4. Buscar por matricula" << endl;
    cout << "0. Salir" << endl;
}

// Funcion para registrar estudiantes
void registrar(vector<Estudiante> &estudiantes) {

    Estudiante nuevo;
    bool repetida = false;

    // Limitar la cantidad de estudiantes
    if (estudiantes.size() >= 5) {
        cout << "No puede registrar mas estudiantes." << endl;
        return;
    }

    cout << "\nREGISTRO DE ESTUDIANTE" << endl;

    cout << "Matricula: ";
    cin >> nuevo.matricula;

    // Comprobar si la matricula ya existe
    for (unsigned int i = 0; i < estudiantes.size(); i++) {

        if (estudiantes.at(i).matricula == nuevo.matricula) {
            repetida = true;
        }
    }

    if (repetida == true) {
        cout << "Esta matricula ya esta registrada." << endl;
        return;
    }

    cout << "Nombre: ";
    cin >> nuevo.nombre;

    cout << "Apellido: ";
    cin >> nuevo.apellido;

    cout << "Edad: ";
    cin >> nuevo.edad;

    while (nuevo.edad <= 0) {
        cout << "Edad invalida. Introduzca otra edad: ";
        cin >> nuevo.edad;
    }

    cout << "Nota final: ";
    cin >> nuevo.notaFinal;

    while (nuevo.notaFinal < 0 || nuevo.notaFinal > 100) {
        cout << "Nota invalida. Introduzca otra nota: ";
        cin >> nuevo.notaFinal;
    }

    // Agregar el estudiante al vector
    estudiantes.push_back(nuevo);

    cout << "Estudiante registrado correctamente." << endl;
}

// Funcion para mostrar los registros
void mostrarEstudiantes(vector<Estudiante> &estudiantes) {

    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    cout << "\nLISTA DE ESTUDIANTES" << endl;

    cout << left
         << setw(12) << "Matricula"
         << setw(15) << "Nombre"
         << setw(15) << "Apellido"
         << setw(8) << "Edad"
         << setw(10) << "Nota" << endl;

    for (unsigned int i = 0; i < estudiantes.size(); i++) {

        cout << left
             << setw(12) << estudiantes.at(i).matricula
             << setw(15) << estudiantes.at(i).nombre
             << setw(15) << estudiantes.at(i).apellido
             << setw(8) << estudiantes.at(i).edad
             << setw(10) << estudiantes.at(i).notaFinal
             << endl;
    }
}

// Funcion para calcular estadisticas
void calcularEstadisticas(vector<Estudiante> &estudiantes) {

    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    double suma = 0;
    double promedio;
    double mayor = estudiantes.at(0).notaFinal;
    double menor = estudiantes.at(0).notaFinal;

    int aprobados = 0;
    int reprobados = 0;

    for (unsigned int i = 0; i < estudiantes.size(); i++) {

        // Acumular todas las notas
        suma += estudiantes.at(i).notaFinal;

        // Determinar la nota mayor
        if (estudiantes.at(i).notaFinal > mayor) {
            mayor = estudiantes.at(i).notaFinal;
        }

        // Determinar la nota menor
        if (estudiantes.at(i).notaFinal < menor) {
            menor = estudiantes.at(i).notaFinal;
        }

        // Contar aprobados y reprobados
        if (estudiantes.at(i).notaFinal >= 70) {
            aprobados++;
        } else {
            reprobados++;
        }
    }

    promedio = suma / estudiantes.size();

    cout << "\nESTADISTICAS DEL GRUPO" << endl;
    cout << "Cantidad: " << estudiantes.size() << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Nota mayor: " << mayor << endl;
    cout << "Nota menor: " << menor << endl;
    cout << "Aprobados: " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;
}

// Funcion para buscar un estudiante
void buscarEstudiante(vector<Estudiante> &estudiantes) {

    long matriculaBuscada;
    bool encontrado = false;

    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    cout << "Introduzca la matricula a buscar: ";
    cin >> matriculaBuscada;

    for (unsigned int i = 0; i < estudiantes.size(); i++) {

        if (estudiantes.at(i).matricula == matriculaBuscada) {

            cout << "\nESTUDIANTE ENCONTRADO" << endl;

            cout << "Matricula: "
                 << estudiantes.at(i).matricula << endl;

            cout << "Nombre: "
                 << estudiantes.at(i).nombre << endl;

            cout << "Apellido: "
                 << estudiantes.at(i).apellido << endl;

            cout << "Edad: "
                 << estudiantes.at(i).edad << endl;

            cout << "Nota: "
                 << estudiantes.at(i).notaFinal << endl;

            encontrado = true;
            break;
        }
    }

    if (encontrado == false) {
        cout << "No se encontro esa matricula." << endl;
    }
}

```

Dos aclaraciones: para este simulacro utilizaremos una nota de aprobación de 70 como criterio de práctica; si el profesor indica otro valor, cambia esa condición. Además, suponemos que introduces números cuando el programa los solicita y nombres y apellidos de una sola palabra. La recuperación de `cin` ante entradas de texto inválidas no está implementada.

## 3. Explicación de las partes más importantes

### A. La estructura

```cpp
struct Estudiante {
    long matricula;
    string nombre;
    string apellido;
    int edad;
    double notaFinal;
};
```

Agrupa los datos de un estudiante. Es el mismo concepto que utilizaste con `struct Bebida` en la máquina expendedora.

En vez de guardar cada dato por separado, trabajamos con una estructura que contiene toda la información.

### B. El vector

```cpp
vector<Estudiante> estudiantes;
```

Aquí creamos un vector vacío.

A diferencia de la máquina de bebidas, donde utilizábamos:

```cpp
vector<Bebida> bebidas(5);
```

ahora no creamos cinco elementos desde el principio. Vamos agregándolos a medida que el usuario registre estudiantes.

Para eso utilizamos:

```cpp
estudiantes.push_back(nuevo);
```

`push_back()` agrega un elemento al final del vector.

Por ejemplo:

| Operación                 | Tamaño del vector |
| ------------------------- | ----------------- |
| Se crea el vector         | 0                 |
| Se registra un estudiante | 1                 |
| Se registra otro          | 2                 |
| Se registra un tercero    | 3                 |

Para conocer su tamaño utilizamos `estudiantes.size()`.

### C. Los prototipos

```cpp
void mostrarMenu();
void registrar(vector<Estudiante> &estudiantes);
void mostrarEstudiantes(vector<Estudiante> &estudiantes);
void calcularEstadisticas(vector<Estudiante> &estudiantes);
void buscarEstudiante(vector<Estudiante> &estudiantes);
```

Estos prototipos indican qué funciones existen.

Observa especialmente:

```cpp
void registrar(vector<Estudiante> &estudiantes);
```

El símbolo `&` significa que enviamos el vector por referencia.

Esto permite que la función `registrar()` agregue estudiantes al mismo vector que está declarado en `main()`.

Si no utilizáramos la referencia, se recibiría una copia y los cambios no quedarían almacenados en el vector original.

### D. El menú y el `switch`

```cpp
do {
    mostrarMenu();

    cin >> opcion;

    switch (opcion) {
        case 1:
            registrar(estudiantes);
            break;

        case 2:
            mostrarEstudiantes(estudiantes);
            break;
    }

} while (opcion != 0);
```

Este fragmento está simplificado para estudiar la idea principal.

El `do-while` mantiene el programa funcionando, mientras que el `switch` determina qué función ejecutar.

Esto es muy importante: ahora no colocamos toda la lógica dentro de `main()`. La función principal coordina las demás.

### E. El registro

```cpp
Estudiante nuevo;
```

Declara una variable de tipo `Estudiante`.

Después recibimos sus datos:

```cpp
cin >> nuevo.matricula;
cin >> nuevo.nombre;
cin >> nuevo.apellido;
cin >> nuevo.edad;
cin >> nuevo.notaFinal;
```

El operador punto (`.`) permite acceder a los miembros de la estructura.

Para validar la nota:

```cpp
while (nuevo.notaFinal < 0 || nuevo.notaFinal > 100) {
    cout << "Nota invalida: ";
    cin >> nuevo.notaFinal;
}
```

Este `while` se repite mientras la nota esté fuera del rango permitido.

Finalmente:

```cpp
estudiantes.push_back(nuevo);
```

Agrega la estructura completa al vector.

### F. Buscar la nota mayor y menor

```
double mayor = estudiantes.at(0).notaFinal;
double menor = estudiantes.at(0).notaFinal;
```

Aquí inicializamos ambas variables con la nota del primer estudiante.

¿Por qué?

Porque necesitamos un valor real del grupo con el cual comparar.

Después recorremos las notas:

```cpp
for (unsigned int i = 0; i < estudiantes.size(); i++) {

    if (estudiantes.at(i).notaFinal > mayor) {
        mayor = estudiantes.at(i).notaFinal;
    }

    if (estudiantes.at(i).notaFinal < menor) {
        menor = estudiantes.at(i).notaFinal;
    }
}
```

En cada vuelta comprobamos si la nota actual es mayor o menor que las que tenemos guardadas.

Esta lógica aparece mucho en los ejercicios de programación, no solamente con notas.

### G. Acumuladores y contadores

```cpp
suma += estudiantes.at(i).notaFinal;
```

Acumula las notas.

```cpp
aprobados++;
```

Aumenta en uno la cantidad de aprobados.

```cpp
reprobados++;
```

Aumenta en uno la cantidad de reprobados.

Después calculamos:

```cpp
promedio = suma / estudiantes.size();
```

Dividimos la suma entre la cantidad de estudiantes registrados.

### H. Buscar por matrícula

```cpp
bool encontrado = false;
```

Esta variable se llama bandera booleana.

Comienza en `false` porque todavía no hemos encontrado al estudiante.

Después:

```cpp
for (unsigned int i = 0; i < estudiantes.size(); i++) {

    if (estudiantes.at(i).matricula == matriculaBuscada) {
        encontrado = true;
        break;
    }
}
```

El ciclo revisa las matrículas una por una.

Cuando encuentra una coincidencia:

- Cambia `encontrado` a `true`.
- Utiliza `break` para terminar la búsqueda.

Si el ciclo termina y la bandera sigue en `false`, significa que no se encontró la matrícula.

## 4. Ejemplo de ejecución

Imagina que registras estos tres estudiantes:

| Matrícula | Nombre | Edad | Nota |
| --------- | ------ | ---- | ---- |
| 1001      | Juan   | 20   | 85   |
| 1002      | Maria  | 22   | 95   |
| 1003      | Pedro  | 19   | 60   |

Al seleccionar la opción 3, el programa mostrará:

```
ESTADISTICAS DEL GRUPO
Cantidad: 3
Promedio: 80.00
Nota mayor: 95.00
Nota menor: 60.00
Aprobados: 2
Reprobados: 1
```

Si seleccionas la opción 4 y buscas la matrícula `1002`, mostrará los datos de Maria.

## 5. Cómo compilar para el parcial

En tu Mac:

```cpp
clang++ -std=c++17 simulacro_parcial.cpp -o simulacro
./simulacro
```

En el laboratorio, puedes utilizar el procedimiento de Borland que has practicado:

```cpp
bcc32 -c simulacro_parcial.cpp
```

Después debes enlazar el archivo objeto para generar el ejecutable, utilizando el comando y las bibliotecas configuradas en tu laboratorio. Conviene comprobar antes del examen que tu versión de `bcc32` acepta el programa, porque las versiones antiguas pueden presentar diferencias de compatibilidad.

## 6. Una prueba que quiero que hagas esta noche

Este simulacro tiene cinco funciones y varios conceptos combinados. Para comprobar que puedes resolver otro enunciado durante el examen, intenta hacer estos cambios sin mirar la solución:

- Cambia el límite de cinco estudiantes a siete.
- Añade una opción al menú para mostrar solamente los aprobados.
- Agrega una función que cuente los estudiantes mayores de 18 años.
- Haz que el programa muestre también el nombre del estudiante con la nota mayor.

Para el parcial, lo más importante es que sepas identificar estos patrones:

| Si el profesor pide…                  | Piensa en…              |
| ------------------------------------- | ----------------------- |
| Registrar varios datos relacionados   | `struct`                |
| Guardar muchos registros              | `vector` o arreglo      |
| Recorrer todos los registros          | `for`                   |
| Repetir un menú                       | `do-while`              |
| Validar información                   | `while` con condiciones |
| Encontrar el mayor o menor            | `for` + `if`            |
| Calcular un promedio                  | Acumulador + cantidad   |
| Buscar un registro                    | `for` + `if`            |
| Ejecutar tareas distintas             | Funciones               |
| Modificar un vector desde una función | Paso por referencia `&` |

Mi recomendación para mañana: guarda `simulacro_parcial.cpp` en la USB, pero no te limites a llevarlo. Practica especialmente identificar qué función necesita cada requisito de un enunciado.

El profesor puede cambiar estudiantes por empleados, productos, facturas o animales; sin embargo, la lógica de recorrer, buscar, validar, acumular y calcular será prácticamente la misma.

Este programa te sirve como plantilla para enfrentar varios de esos problemas.