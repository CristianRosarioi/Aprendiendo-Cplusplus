Esta tarea usa **cuatro vectores relacionados por el mismo índice**. Cada posición corresponde a un empleado:

- `empId`: identificación.
- `horas`: horas trabajadas.
- `tarifaPorHora`: pago por hora.
- `salarioBruto`: resultado de multiplicar horas por tarifa.

**No necesita una estructura:** el enunciado solicita guardar los datos en esos cuatro vectores.

```cpp
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    const int CANTIDAD = 7;

    vector<long> empId(CANTIDAD);
    vector<int> horas(CANTIDAD);
    vector<double> tarifaPorHora(CANTIDAD);
    vector<double> salarioBruto(CANTIDAD);

    int i;

    // Identificaciones iniciales.
    empId.at(0) = 5658845;
    empId.at(1) = 4520125;
    empId.at(2) = 7895122;
    empId.at(3) = 8777541;
    empId.at(4) = 8451277;
    empId.at(5) = 1302850;
    empId.at(6) = 7580489;

    cout << fixed << setprecision(2);

    // Captura y calculo de los datos.
    for (i = 0; i < CANTIDAD; i++) {
        cout << "\nEmpleado: " << empId.at(i) << endl;

        cout << "Horas trabajadas: ";
        cin >> horas.at(i);

        while (horas.at(i) < 0) {
            cout << "Las horas no pueden ser negativas." << endl;
            cout << "Ingrese las horas nuevamente: ";
            cin >> horas.at(i);
        }

        cout << "Tarifa por hora: ";
        cin >> tarifaPorHora.at(i);

        while (tarifaPorHora.at(i) < 50.00) {
            cout << "La tarifa debe ser de al menos 50.00." << endl;
            cout << "Ingrese la tarifa nuevamente: ";
            cin >> tarifaPorHora.at(i);
        }

        salarioBruto.at(i) = horas.at(i) * tarifaPorHora.at(i);
    }

    // Mostrar resultados despues de capturar todos los empleados.
    cout << "\nSALARIOS DE LOS EMPLEADOS" << endl;
    cout << "Identificacion | Salario bruto" << endl;
    cout << "-----------------------------" << endl;

    for (i = 0; i < CANTIDAD; i++) {
        cout << empId.at(i) << " | "
             << salarioBruto.at(i) << endl;
    }

    return 0;
}
```

**1. ¿Por qué cuatro vectores?**

```cpp
vector<long> empId(CANTIDAD);
vector<int> horas(CANTIDAD);
vector<double> tarifaPorHora(CANTIDAD);
vector<double> salarioBruto(CANTIDAD);
```

Cada vector tiene **siete elementos desde su creación**, con índices del **0 al 6**. Usamos los tipos que pide el enunciado:

| Vector | Tipo de cada elemento |
|---|---|
| `empId` | `long`: entero para la identificación |
| `horas` | `int`: entero para las horas |
| `tarifaPorHora` | `double`: permite decimales |
| `salarioBruto` | `double`: permite decimales |

No necesitamos `push_back()`, porque las siete posiciones ya existen.

**2. ¿Cómo se relacionan?**

**El mismo índice identifica al mismo empleado en los cuatro vectores.**

Por ejemplo, si el primer empleado trabajó 40 horas a 100 por hora:

| Expresión | Dato |
|---|---:|
| `empId.at(0)` | 5658845 |
| `horas.at(0)` | 40 |
| `tarifaPorHora.at(0)` | 100.00 |
| `salarioBruto.at(0)` | 4000.00 |

Esto se conoce como **vectores paralelos**. No debes mezclar índices: las horas del empleado 0 deben multiplicarse por la tarifa del empleado 0.

**3. El primer `for` captura y calcula**

```cpp
for (i = 0; i < CANTIDAD; i++)
```

Realiza siete vueltas:

1. `i` comienza en cero.
2. Muestra la identificación guardada en `empId.at(i)`.
3. Lee las horas y la tarifa de ese empleado.
4. Calcula su salario.
5. `i++` pasa al siguiente empleado.

**4. Validación de las horas**

```cpp
while (horas.at(i) < 0)
```

Si se introduce un valor negativo, vuelve a preguntar. **Cero es válido**, porque el enunciado solo prohíbe horas negativas.

**5. Validación de la tarifa**

```cpp
while (tarifaPorHora.at(i) < 50.00)
```

Repite la pregunta mientras la tarifa sea menor que 50. **Una tarifa de exactamente 50 sí es válida.**

**6. Cálculo del salario**

```cpp
salarioBruto.at(i) = horas.at(i) * tarifaPorHora.at(i);
```

Se lee:

> “En la posición actual de salario bruto, guarda las horas del empleado multiplicadas por su tarifa”.

No añadimos horas extra ni descuentos porque el ejercicio pide esa multiplicación directa.

**7. El segundo `for` muestra el listado**

Después de capturar los siete empleados, este ciclo vuelve a recorrerlos:

```cpp
for (i = 0; i < CANTIDAD; i++) {
    cout << empId.at(i) << " | "
         << salarioBruto.at(i) << endl;
}
```

Muestra cada identificación junto a su salario correspondiente.

**Para comprobarlo**, introduce 40 horas y una tarifa de 100 para el primer empleado. Al final debe aparecer:

```text
5658845 | 4000.00
```

Esta versión supone entradas numéricas correctas; los `while` validan los límites que exige el enunciado.