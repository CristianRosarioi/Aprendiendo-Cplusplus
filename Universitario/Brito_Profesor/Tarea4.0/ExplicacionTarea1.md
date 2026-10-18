La tarea pide una **máquina de bebidas con un vector de cinco estructuras**. Cada compra debe reducir la existencia, calcular el cambio y acumular el dinero de las ventas.

Usaremos lo que ya has visto: **`struct`, `vector`, `.at()`, `.size()`, condiciones y ciclos**. Para mostrar el dinero con dos decimales, usamos `fixed` y `setprecision(2)`.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Bebida {
    string nombreBebida;
    double precioBebida;
    int cantidadEnMaquina;
};

int main() {
    vector<Bebida> bebidas(5);

    int opcion;
    int posicion;
    unsigned int i;

    double dinero;
    double cambio;
    double totalVentas = 0;

    // Datos iniciales de las cinco bebidas.
    bebidas.at(0).nombreBebida = "Botella de Agua";
    bebidas.at(0).precioBebida = 20.00;
    bebidas.at(0).cantidadEnMaquina = 20;

    bebidas.at(1).nombreBebida = "Coca Cola";
    bebidas.at(1).precioBebida = 25.00;
    bebidas.at(1).cantidadEnMaquina = 20;

    bebidas.at(2).nombreBebida = "Seven Up";
    bebidas.at(2).precioBebida = 25.00;
    bebidas.at(2).cantidadEnMaquina = 20;

    bebidas.at(3).nombreBebida = "Montain Dew";
    bebidas.at(3).precioBebida = 30.00;
    bebidas.at(3).cantidadEnMaquina = 20;

    bebidas.at(4).nombreBebida = "Jugo V8";
    bebidas.at(4).precioBebida = 50.00;
    bebidas.at(4).cantidadEnMaquina = 20;

    cout << fixed << setprecision(2);

    do {
        cout << "\nMAQUINA DE BEBIDAS" << endl;
        cout << "Opcion | Bebida | Precio | Existencia" << endl;
        cout << "------------------------------------" << endl;

        for (i = 0; i < bebidas.size(); i++) {
            cout << i + 1 << " | "
                 << bebidas.at(i).nombreBebida << " | "
                 << bebidas.at(i).precioBebida << " | "
                 << bebidas.at(i).cantidadEnMaquina
                 << endl;
        }

        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        while (opcion < 0 || opcion > 5) {
            cout << "Opcion invalida. Escriba de 0 a 5: ";
            cin >> opcion;
        }

        if (opcion != 0) {
            posicion = opcion - 1;

            if (bebidas.at(posicion).cantidadEnMaquina == 0) {
                cout << "Esta bebida esta agotada." << endl;
            } else {
                cout << "Bebida seleccionada: "
                     << bebidas.at(posicion).nombreBebida
                     << endl;

                cout << "Introduzca el monto de dinero: ";
                cin >> dinero;

                while (dinero < 20.00 ||
                       dinero < bebidas.at(posicion).precioBebida) {

                    if (dinero < 20.00) {
                        cout << "El monto debe ser de al menos 20.00."
                             << endl;
                    } else {
                        cout << "El monto no alcanza para esta bebida."
                             << endl;
                    }

                    cout << "Introduzca nuevamente el monto: ";
                    cin >> dinero;
                }

                cambio = dinero - bebidas.at(posicion).precioBebida;

                bebidas.at(posicion).cantidadEnMaquina--;

                totalVentas += bebidas.at(posicion).precioBebida;

                cout << "Retire su bebida: "
                     << bebidas.at(posicion).nombreBebida
                     << endl;

                cout << "Su cambio es: " << cambio << endl;
            }
        }

    } while (opcion != 0);

    cout << "\nTotal de dinero recaudado: "
         << totalVentas << endl;

    return 0;
}
```

**1. La estructura representa una bebida**

```cpp
struct Bebida {
    string nombreBebida;
    double precioBebida;
    int cantidadEnMaquina;
};
```

Agrupa los tres datos que exige el enunciado:

| Campo | Qué guarda |
|---|---|
| `nombreBebida` | Nombre del producto |
| `precioBebida` | Precio de una unidad |
| `cantidadEnMaquina` | Unidades disponibles |

**2. El vector contiene cinco bebidas**

```cpp
vector<Bebida> bebidas(5);
```

Se lee: **«Un vector llamado `bebidas`, con cinco elementos del tipo `Bebida`»**.

Las cinco posiciones existen desde esta declaración. Por eso podemos asignar directamente:

```cpp
bebidas.at(0).nombreBebida = "Botella de Agua";
```

La expresión tiene dos partes:

- `bebidas.at(0)`: obtiene la primera estructura.
- `.nombreBebida`: selecciona su campo del nombre.

No necesitamos `push_back()` porque **ya creamos las cinco posiciones**.

**3. Las variables de trabajo**

| Variable | Función |
|---|---|
| `opcion` | Número elegido en el menú |
| `posicion` | Índice de la bebida seleccionada |
| `i` | Recorre el vector para mostrar el menú |
| `dinero` | Monto entregado para una compra |
| `cambio` | Dinero que se devuelve |
| `totalVentas` | Acumula el valor de las bebidas vendidas |

```cpp
double totalVentas = 0;
```

Comienza en cero porque todavía no se ha vendido nada.

**4. El ciclo principal mantiene funcionando la máquina**

```cpp
do {
    // Mostrar opciones y procesar una compra.
} while (opcion != 0);
```

El `do-while` ejecuta primero su contenido y comprueba la condición después.

Por eso el menú aparece **al menos una vez**. Después de una compra, vuelve a aparecer. Si el usuario selecciona cero, termina.

**5. El `for` muestra las cinco bebidas**

```cpp
for (i = 0; i < bebidas.size(); i++)
```

Recorre los índices del 0 al 4.

```cpp
cout << i + 1;
```

Muestra las opciones del **1 al 5**, que son más naturales para el usuario.

**6. Validamos la opción**

```cpp
while (opcion < 0 || opcion > 5)
```

`||` significa **OR: «o»**.

Se repite la pregunta si la opción es menor que cero **o** mayor que cinco. Cero sirve para salir; del 1 al 5 se selecciona una bebida.

**7. Convertimos la opción en índice**

```cpp
posicion = opcion - 1;
```

El usuario cuenta desde 1, pero el vector desde 0:

| Opción | Índice | Bebida |
|---:|---:|---|
| 1 | 0 | Agua |
| 2 | 1 | Coca Cola |
| 3 | 2 | Seven Up |
| 4 | 3 | Montain Dew |
| 5 | 4 | Jugo V8 |

Esta conversión ocurre solamente cuando `opcion != 0`, para no intentar acceder al índice `-1`.

**8. Comprobamos si quedan unidades**

```cpp
if (bebidas.at(posicion).cantidadEnMaquina == 0)
```

Si está agotada, se muestra el aviso. No se solicita dinero y el ciclo vuelve al menú.

**9. Validamos el dinero**

```cpp
while (dinero < 20.00 ||
       dinero < bebidas.at(posicion).precioBebida)
```

Rechaza el monto cuando:

- Es menor que 20. Esto también rechaza cualquier cantidad negativa.
- No alcanza para pagar la bebida elegida.

Por ejemplo, **20 pesos cumplen el mínimo general**, pero no alcanzan para comprar un Jugo V8 de 50.

Aquí, cada nuevo intento **sustituye el monto anterior**; no suma abonos.

**10. Procesamos la venta**

```cpp
cambio = dinero - bebidas.at(posicion).precioBebida;
```

Calcula la devolución.

```cpp
bebidas.at(posicion).cantidadEnMaquina--;
```

`--` resta uno a la existencia de la bebida seleccionada.

```cpp
totalVentas += bebidas.at(posicion).precioBebida;
```

Suma el precio al dinero recaudado. **No suma todo lo introducido**, porque una parte puede devolverse como cambio.

Por ejemplo, si compras una Coca Cola con 100:

```text
Precio:                  25.00
Dinero entregado:        100.00
Cambio:                  75.00
Existencia restante:        19
Aumento en totalVentas:  25.00
```

**Pruebas que debes hacer**

| Prueba | Resultado esperado |
|---|---|
| Elegir agua y entregar 20 | Cambio 0; quedan 19 |
| Elegir Coca Cola y entregar 100 | Cambio 75 |
| Introducir un monto negativo o 10 | Pedir otro monto |
| Elegir V8 y entregar 20 | Avisar que no alcanza |
| Elegir una opción como 8 | Pedir una opción válida |
| Comprar las 20 aguas y volver a elegir agua | Avisar que está agotada |
| Elegir 0 | Mostrar la recaudación y terminar |

Esta versión supone que introduces **números en las preguntas numéricas**, como en los ejemplos básicos que hemos trabajado.

Para entregar, el enunciado pide **el archivo `.cpp` y una captura de la ejecución dentro de un ZIP o RAR**.