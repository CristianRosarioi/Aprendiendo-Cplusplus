Esta tarea pide una **matriz de 3 filas y 7 columnas**:

- Cada **fila** representa un mono.
- Cada **columna** representa un día de la semana.
- Cada casilla guarda las libras que comió ese mono ese día.

Usaremos un arreglo bidimensional de `double`, porque la cantidad puede tener decimales, como **2.5 libras**.

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int MONOS = 3;
    const int DIAS = 7;

    double comida[MONOS][DIAS];

    double totalComida = 0;
    double promedioDiario;
    double menor;
    double mayor;

    int mono;
    int dia;

    // Capturar los datos de los tres monos.
    for (mono = 0; mono < MONOS; mono++) {
        cout << "\nDATOS DEL MONO " << mono + 1 << endl;

        for (dia = 0; dia < DIAS; dia++) {
            cout << "Libras de comida del dia "
                 << dia + 1 << ": ";

            cin >> comida[mono][dia];

            while (comida[mono][dia] < 0) {
                cout << "La cantidad no puede ser negativa."
                     << endl;

                cout << "Ingrese nuevamente las libras: ";
                cin >> comida[mono][dia];
            }
        }
    }

    // Tomar el primer dato como referencia.
    menor = comida[0][0];
    mayor = comida[0][0];

    // Procesar las 21 cantidades almacenadas.
    for (mono = 0; mono < MONOS; mono++) {
        for (dia = 0; dia < DIAS; dia++) {
            totalComida += comida[mono][dia];

            if (comida[mono][dia] < menor) {
                menor = comida[mono][dia];
            }

            if (comida[mono][dia] > mayor) {
                mayor = comida[mono][dia];
            }
        }
    }

    // Promedio por dia de los tres monos juntos.
    promedioDiario = totalComida / DIAS;

    cout << fixed << setprecision(2);

    cout << "\nREPORTE DE ALIMENTACION" << endl;

    cout << "Promedio diario de los tres monos juntos: "
         << promedioDiario << " libras" << endl;

    cout << "Menor cantidad ingerida por un mono en un dia: "
         << menor << " libras" << endl;

    cout << "Mayor cantidad ingerida por un mono en un dia: "
         << mayor << " libras" << endl;

    return 0;
}
```

**1. ¿Qué significa la matriz?**

```cpp
double comida[MONOS][DIAS];
```

Crea **21 posiciones**, organizadas en tres filas y siete columnas:

| | Día 1 | Día 2 | Día 3 | Día 4 | Día 5 | Día 6 | Día 7 |
|---|---|---|---|---|---|---|---|
| Mono 1 | `[0][0]` | `[0][1]` | `[0][2]` | `[0][3]` | `[0][4]` | `[0][5]` | `[0][6]` |
| Mono 2 | `[1][0]` | `[1][1]` | `[1][2]` | `[1][3]` | `[1][4]` | `[1][5]` | `[1][6]` |
| Mono 3 | `[2][0]` | `[2][1]` | `[2][2]` | `[2][3]` | `[2][4]` | `[2][5]` | `[2][6]` |

Por ejemplo:

```cpp
comida[1][3]
```

Es la cantidad que comió **el segundo mono en el cuarto día**. Recuerda que los índices comienzan en cero.

**2. ¿Cómo funcionan los dos ciclos juntos?**

```cpp
for (mono = 0; mono < MONOS; mono++) {
    for (dia = 0; dia < DIAS; dia++) {
        // Leer una cantidad.
    }
}
```

El ciclo exterior selecciona el mono. El interior recorre sus siete días.

El orden es:

1. Mono 1: lee los días 1 al 7.
2. Mono 2: vuelve a comenzar por el día 1 y llega al 7.
3. Mono 3: hace lo mismo.

**El ciclo interior completa sus siete vueltas antes de que avance el exterior.**

**3. Validación**

```cpp
while (comida[mono][dia] < 0)
```

Si introduces una cantidad negativa, vuelve a pedir **esa misma casilla**. No pasa al siguiente día hasta recibir una cantidad válida.

Cero sí está permitido, porque el enunciado solo prohíbe negativos.

**4. ¿Por qué el menor y el mayor empiezan con el primer dato?**

```cpp
menor = comida[0][0];
mayor = comida[0][0];
```

Usamos una cantidad real ya capturada como referencia.

Si iniciaras `menor` en cero y todas las cantidades fueran positivas, ninguna sería menor que cero y obtendrías un resultado incorrecto.

Después examinamos cada casilla:

```cpp
if (comida[mono][dia] < menor) {
    menor = comida[mono][dia];
}
```

Si encontramos una cantidad inferior, actualizamos `menor`. Para `mayor` hacemos la comparación contraria.

**5. El promedio se divide entre 7, no entre 21**

```cpp
promedioDiario = totalComida / DIAS;
```

El enunciado pide el promedio diario de **la familia completa: los tres monos juntos**.

Por ejemplo, si cada mono comió 10 libras todos los días:

```text
Total semanal: 3 × 7 × 10 = 210 libras.
Promedio diario de la familia: 210 / 7 = 30 libras.
Menor cantidad individual: 10 libras.
Mayor cantidad individual: 10 libras.
```

Dividir entre 21 daría el promedio **por mono y por día**, que es otro resultado.

**Los valores menor y mayor se buscan entre las 21 cantidades individuales**, no entre los totales semanales de cada mono. Esta versión supone que introduces números válidos; el `while` comprueba que no sean negativos.