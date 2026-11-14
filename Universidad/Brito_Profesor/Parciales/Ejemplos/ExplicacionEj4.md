# Simulacro de parcial 4 — Control de empleados y salarios en C++

Esta vez vamos a subir un poco el nivel. Te prepararé un ejercicio que combina estructuras, vectores, arreglos, ciclos anidados, funciones, validaciones, acumuladores y búsqueda del mayor.

Es parecido a los programas de empleados y matrices que hemos trabajado con el profesor Brito, pero organizado como un programa completo para el examen.

## 1. Enunciado del ejercicio

Una empresa necesita un programa que registre las horas trabajadas por tres empleados durante los siete días de la semana.

Desarrolle un programa en C++ que cumpla los siguientes requisitos:

1. Crear una estructura `Empleado` con nombre, tarifa por hora y un arreglo de siete posiciones para las horas trabajadas.
2. Utilizar un vector para almacenar tres empleados.
3. Solicitar los datos mediante ciclos anidados.
4. Validar que las horas diarias estén entre 0 y 12, y que la tarifa por hora sea mayor que cero.
5. Crear una función que calcule el total de horas semanales de un empleado.
6. Crear otra función que calcule su salario semanal.
7. Mostrar todos los empleados con sus horas y salarios.
8. Calcular el total de salarios que debe pagar la empresa.
9. Determinar cuál empleado tiene el salario más alto.
10. Utilizar un menú con `do-while` y `switch`.

Condición: el salario se calcula multiplicando todas las horas trabajadas por la tarifa correspondiente, sin pagos adicionales por horas extras.

## 2. Código completo — `simulacro_4.cpp`

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Estructura de empleados
struct Empleado {
    string nombre;
    double tarifa;
    int horas[7];
};

// Prototipos
void mostrarMenu();
int calcularHoras(Empleado empleado);
double calcularSalario(Empleado empleado);
bool horasValidas(int cantidad);

int main() {

    vector<Empleado> empleados(3);

    int opcion;
    int totalHoras;
    int contador;

    double salario;
    double totalGeneral;
    double salarioMayor;

    string nombreMayor;

    cout << fixed << setprecision(2);

    // Registrar los tres empleados
    for (unsigned int i = 0; i < empleados.size(); i++) {

        cout << "\nEMPLEADO " << i + 1 << endl;

        cout << "Nombre: ";
        cin >> empleados.at(i).nombre;

        cout << "Tarifa por hora: ";
        cin >> empleados.at(i).tarifa;

        while (empleados.at(i).tarifa <= 0) {
            cout << "Tarifa invalida. Intente otra vez: ";
            cin >> empleados.at(i).tarifa;
        }

        // Registrar las horas de los siete dias
        for (int j = 0; j < 7; j++) {

            cout << "Horas del dia " << j + 1 << ": ";
            cin >> empleados.at(i).horas[j];

            while (!horasValidas(empleados.at(i).horas[j])) {
                cout << "Horas invalidas (0 a 12): ";
                cin >> empleados.at(i).horas[j];
            }
        }
    }

    do {
        mostrarMenu();

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        while (opcion < 0 || opcion > 3) {
            cout << "Opcion invalida: ";
            cin >> opcion;
        }

        switch (opcion) {

            case 1:
                cout << "\nREPORTE DE EMPLEADOS" << endl;

                for (unsigned int i = 0; i < empleados.size(); i++) {

                    totalHoras = calcularHoras(empleados.at(i));
                    salario = calcularSalario(empleados.at(i));

                    cout << "\nEmpleado: "
                         << empleados.at(i).nombre << endl;

                    cout << "Horas por dia: ";

                    for (int j = 0; j < 7; j++) {
                        cout << empleados.at(i).horas[j] << " ";
                    }

                    cout << endl;

                    cout << "Total de horas: "
                         << totalHoras << endl;

                    cout << "Tarifa: "
                         << empleados.at(i).tarifa << endl;

                    cout << "Salario semanal: "
                         << salario << endl;
                }
                break;

            case 2:
                totalGeneral = 0;
                contador = 0;

                for (unsigned int i = 0; i < empleados.size(); i++) {

                    salario = calcularSalario(empleados.at(i));

                    totalGeneral += salario;

                    if (salario > 3000) {
                        contador++;
                    }
                }

                cout << "\nTOTAL DE NOMINA" << endl;
                cout << "Total a pagar: "
                     << totalGeneral << endl;

                cout << "Empleados con salario mayor a 3000: "
                     << contador << endl;
                break;

            case 3:
                salarioMayor = calcularSalario(empleados.at(0));
                nombreMayor = empleados.at(0).nombre;

                for (unsigned int i = 1; i < empleados.size(); i++) {

                    salario = calcularSalario(empleados.at(i));

                    if (salario > salarioMayor) {
                        salarioMayor = salario;
                        nombreMayor = empleados.at(i).nombre;
                    }
                }

                cout << "\nEMPLEADO CON MAYOR SALARIO" << endl;
                cout << "Nombre: " << nombreMayor << endl;
                cout << "Salario: " << salarioMayor << endl;
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

    cout << "\n===== CONTROL DE EMPLEADOS =====" << endl;
    cout << "1. Mostrar empleados y salarios" << endl;
    cout << "2. Calcular nomina total" << endl;
    cout << "3. Mostrar empleado con mayor salario" << endl;
    cout << "0. Salir" << endl;
}

// Funcion que calcula el total de horas
int calcularHoras(Empleado empleado) {

    int suma = 0;

    for (int i = 0; i < 7; i++) {
        suma += empleado.horas[i];
    }

    return suma;
}

// Funcion que calcula el salario
double calcularSalario(Empleado empleado) {

    int horasTotales;
    double salario;

    horasTotales = calcularHoras(empleado);

    salario = horasTotales * empleado.tarifa;

    return salario;
}

// Funcion que valida las horas
bool horasValidas(int cantidad) {

    if (cantidad >= 0 && cantidad <= 12) {
        return true;
    }

    return false;
}
```

## 3. Explicación de las partes importantes

### A. Una estructura con un arreglo dentro

```cpp
struct Empleado {
    string nombre;
    double tarifa;
    int horas[7];
};
```

Esta estructura tiene algo nuevo respecto a los ejercicios anteriores: uno de sus miembros es un arreglo.

`horas[7]` almacena las horas trabajadas durante siete días.

Podemos imaginar un empleado así:

| Dato       | Valor de ejemplo |
| ---------- | ---------------- |
| Nombre     | Juan             |
| Tarifa     | RD$100           |
| `horas[0]` | 8                |
| `horas[1]` | 7                |
| `horas[2]` | 8                |
| `horas[3]` | 6                |
| `horas[4]` | 8                |
| `horas[5]` | 4                |
| `horas[6]` | 0                |

### B. Vector de estructuras

```cpp
vector<Empleado> empleados(3);
```

Crea un vector con tres empleados.

Cada empleado contiene su propio arreglo de siete horas.

Por tanto, tenemos dos niveles de acceso:

```cpp
empleados.at(0).nombre
```

Obtiene el nombre del primer empleado.

```cpp
empleados.at(0).horas[2]
```

Obtiene las horas del tercer día del primer empleado.

Observa la diferencia: `at(0)` selecciona al empleado y `[2]` selecciona un día dentro de su arreglo.

### C. Ciclos anidados

```cpp
for (unsigned int i = 0; i < empleados.size(); i++) {

    // Datos del empleado

    for (int j = 0; j < 7; j++) {

        cout << "Horas del dia " << j + 1 << ": ";
        cin >> empleados.at(i).horas[j];
    }
}
```

Este es uno de los conceptos más importantes para el parcial.

Tenemos dos ciclos:

- El ciclo exterior, controlado por `i`, recorre los tres empleados.
- El ciclo interior, controlado por `j`, recorre los siete días de cada empleado.

Cómo recorren los datos los ciclos anidados

Empleado (`i`)

012

Día 10

Día 21

Día 32

Día 43

Día 54

Día 65

Día 76

Posición seleccionada

##

empleados.at(0).horas[0]

Empleado 1, día 1

El ciclo exterior mantiene seleccionado un empleado mientras el interior recorre sus siete días. En total se solicitan 3 × 7 = 21 valores de horas.

### D. Función `calcularHoras()`

```cpp
int calcularHoras(Empleado empleado) {

    int suma = 0;

    for (int i = 0; i < 7; i++) {
        suma += empleado.horas[i];
    }

    return suma;
}
```

Esta función recibe una estructura `Empleado` por valor, sin referencias.

Recorre su arreglo de siete posiciones y suma las horas.

Por ejemplo, si el empleado trabajó:

```cpp
8 7 8 6 8 4 0
```

El resultado es:

\\[ 8+7+8+6+8+4+0=41 \\]

La función devuelve `41` mediante `return`.

### E. Una función que llama a otra función

```cpp
double calcularSalario(Empleado empleado) {

    int horasTotales;
    double salario;

    horasTotales = calcularHoras(empleado);

    salario = horasTotales * empleado.tarifa;

    return salario;
}
```

Esta es una de las novedades más importantes de este ejercicio.

Dentro de `calcularSalario()` estamos llamando a `calcularHoras()`.

El proceso es:

1. `calcularSalario()` recibe un empleado.
2. Llama a `calcularHoras()` para saber cuántas horas trabajó.
3. Multiplica ese total por su tarifa.
4. Devuelve el salario calculado.

Si trabajó 41 horas y cobra RD$100 por hora:

\\[ 41 \times 100 = 4100 \\]

La función devuelve `4100`.

Aquí tienes dos niveles de llamadas:

```cpp
main()
   |
   v
calcularSalario()
   |
   v
calcularHoras()
   |
   v
Devuelve las horas
   |
   v
Calcula el salario
   |
   v
Devuelve el salario a main()
```

### F. Función de validación `bool`

```
bool horasValidas(int cantidad) {

    if (cantidad >= 0 && cantidad <= 12) {
        return true;
    }

    return false;
}
```

Comprueba que las horas estén entre 0 y 12.

El operador `&&` significa Y: ambas condiciones deben ser verdaderas.

La utilizamos así:

```cpp
while (!horasValidas(empleados.at(i).horas[j])) {
    cout << "Horas invalidas (0 a 12): ";
    cin >> empleados.at(i).horas[j];
}
```

El operador `!` significa negación.

Si la función devuelve `false`, el `while` continúa solicitando horas. Si devuelve `true`, deja de repetir.

### G. Acumular el total de nómina

```cpp
totalGeneral = 0;

for (unsigned int i = 0; i < empleados.size(); i++) {

    salario = calcularSalario(empleados.at(i));

    totalGeneral += salario;
}
```

Recorremos los tres empleados y calculamos sus salarios.

Después acumulamos cada resultado mediante `+=`.

Ejemplo:

| Empleado | Salario   |
| -------- | --------- |
| Juan     | RD$4,100  |
| María    | RD$3,600  |
| Pedro    | RD$2,800  |
| Total    | RD$10,500 |

El total de nómina sería RD$10,500.

También utilizamos:

```cpp
if (salario > 3000) {
    contador++;
}
```

Esto permite contar cuántos empleados cobran más de RD$3,000.

### H. Encontrar el empleado con mayor salario

```cpp
salarioMayor = calcularSalario(empleados.at(0));
nombreMayor = empleados.at(0).nombre;
```

Primero guardamos el salario y nombre del primer empleado como referencia inicial.

Después recorremos los restantes:

```cpp
for (unsigned int i = 1; i < empleados.size(); i++) {

    salario = calcularSalario(empleados.at(i));

    if (salario > salarioMayor) {
        salarioMayor = salario;
        nombreMayor = empleados.at(i).nombre;
    }
}
```

Comenzamos en `i = 1` porque el primer empleado ya fue utilizado para inicializar el mayor.

Cuando encontramos un salario superior, actualizamos las dos variables:

- `salarioMayor`, para guardar el importe.
- `nombreMayor`, para recordar a quién pertenece.

Al finalizar, tenemos el nombre y salario del empleado que más gana.

## 4. Ejemplo de ejecución

Supongamos que registramos tres empleados:

| Empleado | Horas semanales | Tarifa | Salario  |
| -------- | --------------- | ------ | -------- |
| Juan     | 41              | RD$100 | RD$4,100 |
| María    | 36              | RD$100 | RD$3,600 |
| Pedro    | 28              | RD$100 | RD$2,800 |

Cuando seleccionamos la opción 2:

```cpp
TOTAL DE NOMINA
Total a pagar: 10500.00
Empleados con salario mayor a 3000: 2
```

Al seleccionar la opción 3:

```cpp
EMPLEADO CON MAYOR SALARIO
Nombre: Juan
Salario: 4100.00
```

## 5. Lo que estás practicando para el parcial

| Concepto                       | Dónde se utiliza                    |
| ------------------------------ | ----------------------------------- |
| `struct`                       | Representar los datos del empleado  |
| `vector`                       | Almacenar tres empleados            |
| Arreglo fijo                   | Guardar siete días de horas         |
| Ciclos anidados                | Registrar las horas de todos        |
| `for`                          | Recorrer y calcular                 |
| `while`                        | Validar horas y tarifas             |
| `do-while`                     | Repetir el menú                     |
| `switch`                       | Seleccionar operaciones             |
| `if-else`                      | Tomar decisiones                    |
| `bool`                         | Validar las horas                   |
| `return`                       | Devolver horas y salarios           |
| Funciones anidadas en llamadas | Una función llama a otra            |
| Acumuladores                   | Total de horas y nómina             |
| Contadores                     | Cantidad de salarios mayores a 3000 |
| Mayor                          | Encontrar el salario más alto       |
| `at()` y `size()`              | Acceder y recorrer el vector        |

El programa supone entradas numéricas válidas y nombres de una sola palabra, como en los simulacros anteriores.

## 6. Tres cambios para practicar tú mismo

Antes de mañana, intenta realizar estas modificaciones:

1. Agrega una opción que muestre cuántos empleados trabajaron más de 40 horas.
2. Crea una función `double calcularPromedioHoras(Empleado empleado)` que devuelva el promedio de horas diarias.
3. Modifica la opción 3 para que también muestre el empleado con menor salario.

Este programa te sirve para repasar uno de los patrones más importantes del curso: recorrer una colección de estructuras, procesar sus datos con funciones y utilizar ciclos y condiciones para obtener resultados.

Guárdalo como `simulacro_4.cpp` en tu USB. Si dominas este junto con los tres anteriores, tendrás buenas referencias para resolver muchos ejercicios similares a los que ha colocado el profesor.