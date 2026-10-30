1. ¿Qué hace el programa?

Simula una máquina expendedora con cinco bebidas. Muestra sus nombres,
precios y existencias; permite seleccionar una bebida, introducir
dinero, calcular el cambio, descontar una unidad y acumular el importe
de las ventas. El menú se repite hasta que el usuario elige 0.

2. Código completo

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
        cout << fixed << setprecision(2) << left;

        cout << "+--------+----------------------+----------+------------+" << endl;

        cout << "| " << setw(6) << "Opcion"
             << " | " << setw(20) << "Bebida"
             << " | " << setw(8) << "Precio"
             << " | " << setw(10) << "Existencia"
             << " |" << endl;

        cout << "+--------+----------------------+----------+------------+" << endl;

        for (i = 0; i < bebidas.size(); i++) {
            cout << "| " << setw(6) << i + 1
                 << " | " << setw(20) << bebidas.at(i).nombreBebida
                 << " | " << setw(8) << bebidas.at(i).precioBebida
                 << " | " << setw(10) << bebidas.at(i).cantidadEnMaquina
                 << " |" << endl;
        }

        cout << "+--------+----------------------+----------+------------+" << endl;
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

────────

3. Bibliotecas

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

• <iostream>: permite usar cout para mostrar información,
cin para recibir datos y endl para terminar una línea.
• <string>: permite utilizar el tipo string para almacenar
textos, como los nombres de las bebidas.
• <vector>: permite utilizar vectores, que almacenan varios
elementos del mismo tipo y permiten acceder a ellos mediante
índices.
• <iomanip>: proporciona herramientas para dar formato a la
salida. Aquí utilizamos fixed, setprecision(), left y
setw().
• using namespace std;: permite escribir cout, cin, string
y vector sin anteponer std::.

4. La estructura Bebida

struct Bebida {
    string nombreBebida;
    double precioBebida;
    int cantidadEnMaquina;
};

struct crea un tipo de dato propio agrupando variables relacionadas.
En este caso, cada bebida tiene:

Campo                 Tipo       Información

────────

nombreBebida        string   Nombre de la bebida
precioBebida        double   Precio
cantidadEnMaquina   int      Unidades disponibles

La estructura es como una plantilla. Define qué información tendrá cada
bebida. Más adelante creamos cinco elementos de ese tipo dentro del
vector.

5. La función main()

int main() {

main() es la función principal y el punto de entrada del programa.
Cuando ejecutamos el programa, comienza por esta función. El tipo int
indica que devuelve un número entero al sistema operativo; normalmente
return 0 significa que terminó correctamente.

6. Crear el vector

vector<Bebida> bebidas(5);

Desglose:

• vector: indica que declaramos un vector.
• <Bebida>: especifica que almacenará elementos del tipo Bebida.
• bebidas: nombre de la variable vector.
• (5): crea cinco elementos inicialmente.

Sus índices son 0, 1, 2, 3 y 4. Aunque hay cinco elementos, el
primero está en la posición cero. Cada posición contiene una estructura
Bebida completa, con sus tres campos.

7. Declarar las variables

int opcion;
int posicion;
unsigned int i;

double dinero;
double cambio;
double totalVentas = 0;

• opcion: guarda el número que el usuario elige en el menú: de 1
a 5 para comprar y 0 para salir.
• posicion: guarda el índice del vector correspondiente a la
opción. Se calcula restando uno a la opción del menú.
• unsigned int i: variable de control del for. unsigned
indica que es un entero sin signo, por lo que no representa valores
negativos.
• dinero: almacena el monto que introduce el cliente. Es
double porque puede tener decimales.
• cambio: almacena lo que debe devolverse al cliente.
• totalVentas = 0: es un acumulador. Comienza en cero y va
sumando el precio de cada bebida vendida.

8. Asignar los datos iniciales

Ejemplo:

bebidas.at(0).nombreBebida = "Botella de Agua";
bebidas.at(0).precioBebida = 20.00;
bebidas.at(0).cantidadEnMaquina = 20;

Desglosemos la primera instrucción:

1. bebidas identifica el vector.
2. .at(0) selecciona el elemento de la posición cero.
3. .nombreBebida accede al campo nombreBebida de esa estructura.
4. = asigna el texto "Botella de Agua" a ese campo.

El punto (.) permite acceder a un miembro de una estructura. at() es
una función miembro de vector que accede a una posición mediante su
índice.

Las siguientes instrucciones asignan el precio y la existencia de esa
bebida. El mismo procedimiento se repite para las cinco:

Posición Bebida              Precio   Existencia inicial

────────

       0 Botella de Agua      20.00                   20
       1 Coca Cola            25.00                   20
       2 Seven Up             25.00                   20
       3 Montain Dew          30.00                   20
       4 Jugo V8              50.00                   20

9. Formato de los números decimales

cout << fixed << setprecision(2);

• fixed: hace que los números se muestren en formato decimal
fijo.
• setprecision(2): combinado con fixed, indica que se muestren
dos cifras después del punto decimal.

Ejemplos:

 Valor   Presentación

────────

    20          20.00
  25.5          25.50
30.123          30.12
    50          50.00

Esta configuración permanece activa en cout. Por eso, repetirla más
adelante no es necesario, aunque tampoco causa un error.

10. El ciclo principal do-while

do {
    // Instrucciones de la máquina
} while (opcion != 0);

El ciclo permite que la máquina siga funcionando hasta que el usuario
elija cero.

1. Ejecuta las instrucciones dentro de do.
2. Muestra el menú y recibe una opción.
3. Procesa la compra si corresponde.
4. Al llegar al while, comprueba opcion != 0.
5. Si la condición es verdadera, vuelve al principio.
6. Si es falsa, termina el ciclo.

Utilizamos do-while porque queremos mostrar el menú al menos una vez
antes de comprobar si el usuario desea salir.

11. Mostrar el menú y formar la tabla

cout << "\nMAQUINA DE BEBIDAS" << endl;
cout << fixed << setprecision(2) << left;

• \n inserta un salto de línea antes del título.
• endl termina la línea.
• left indica que el contenido se alinee a la izquierda dentro del
espacio asignado.

La línea:

cout << "+--------+----------------------+----------+------------+" << endl;

imprime caracteres normales (+ y -) para dibujar el borde de la
tabla. No es una función especial de C++.

Los encabezados se imprimen así:

cout << "| " << setw(6) << "Opcion"
     << " | " << setw(20) << "Bebida"
     << " | " << setw(8) << "Precio"
     << " | " << setw(10) << "Existencia"
     << " |" << endl;

setw() establece el ancho mínimo del siguiente campo que se imprime:

• setw(6): ancho mínimo de seis caracteres.
• setw(20): ancho mínimo de veinte caracteres.
• setw(8): ancho mínimo de ocho caracteres.
• setw(10): ancho mínimo de diez caracteres.

Importante: setw() solo afecta al siguiente elemento enviado a
cout. Por eso se coloca antes de cada encabezado o dato que queremos
alinear. left hace que el contenido quede alineado a la izquierda.

12. El ciclo for: recorrer las bebidas

for (i = 0; i < bebidas.size(); i++) {

Este ciclo recorre todos los elementos del vector para mostrar sus
datos.

• i = 0: comienza en el primer índice.
• i < bebidas.size(): continúa mientras i sea menor que la
cantidad de elementos.
• bebidas.size(): función miembro de vector que devuelve
cuántos elementos contiene. Aquí devuelve 5.
• i++: incrementa i en uno después de cada vuelta.

Las vueltas son:

Vuelta   `i` Elemento

────────

     1     0 Primera bebida
     2     1 Segunda bebida
     3     2 Tercera bebida
     4     3 Cuarta bebida
     5     4 Quinta bebida

Después de la quinta vuelta, i pasa a 5. La condición 5 < 5 es falsa
y el ciclo termina.

Dentro del ciclo:

cout << "| " << setw(6) << i + 1
     << " | " << setw(20) << bebidas.at(i).nombreBebida
     << " | " << setw(8) << bebidas.at(i).precioBebida
     << " | " << setw(10) << bebidas.at(i).cantidadEnMaquina
     << " |" << endl;

• i + 1: muestra opciones de 1 a 5 aunque los índices sean de 0 a 4.
• bebidas.at(i).nombreBebida: obtiene el nombre del elemento actual.
• bebidas.at(i).precioBebida: obtiene su precio.
• bebidas.at(i).cantidadEnMaquina: obtiene su existencia.
• setw() organiza el ancho de cada columna.

La ventaja del ciclo es que no necesitamos escribir cinco bloques de
impresión: un solo bloque se repite cambiando el índice.

13. Recibir y validar la opción

cout << "Seleccione una opcion: ";
cin >> opcion;

cout muestra el mensaje y cin guarda la respuesta en opcion.

Después:

while (opcion < 0 || opcion > 5) {
    cout << "Opcion invalida. Escriba de 0 a 5: ";
    cin >> opcion;
}

|| significa OR (O). La condición es verdadera si la opción es menor
que cero o mayor que cinco. Mientras sea inválida, el ciclo vuelve a
pedirla.

Entrada ¿Válida?   Motivo

────────

     -1 No         Menor que cero
      0 Sí         Salir
      1 Sí         Primera bebida
      3 Sí         Tercera bebida
      5 Sí         Quinta bebida
      6 No         Mayor que cinco

Esta validación comprueba el rango numérico, no que el usuario haya
escrito un número. El manejo de letras o texto en cin no está
implementado en esta versión.

14. Comprobar si el usuario quiere salir

if (opcion != 0) {

!= significa “diferente de”. Si la opción es distinta de cero, se
ejecuta el proceso de compra. Si es cero, se omite ese bloque y el ciclo
termina al comprobar su condición.

15. Convertir la opción en índice

posicion = opcion - 1;

El menú comienza en 1, pero el vector comienza en 0. Restamos uno para
que la opción corresponda con el índice correcto.

Opción   Operación   Índice

────────

     1       1 - 1        0
     2       2 - 1        1
     3       3 - 1        2
     4       4 - 1        3
     5       5 - 1        4

16. Comprobar si hay existencia

if (bebidas.at(posicion).cantidadEnMaquina == 0) {
    cout << "Esta bebida esta agotada." << endl;
}

Accedemos a la bebida seleccionada y revisamos su campo
cantidadEnMaquina.

== es el operador de comparación de igualdad. Si la existencia es
exactamente cero, mostramos el mensaje y no procesamos la compra.

Si hay unidades disponibles, se ejecuta el else y continúa el proceso.

17. Mostrar la bebida seleccionada

cout << "Bebida seleccionada: "
     << bebidas.at(posicion).nombreBebida
     << endl;

Muestra el nombre de la bebida que eligió el usuario. Si eligió la
opción 2, posicion vale 1 y se muestra Coca Cola.

18. Recibir el dinero

cout << "Introduzca el monto de dinero: ";
cin >> dinero;

El usuario introduce el monto y cin lo guarda en dinero. Usamos
double para permitir valores decimales.

19. Validar el dinero con while

while (dinero < 20.00 ||
       dinero < bebidas.at(posicion).precioBebida) {

Hay dos comparaciones unidas por ||:

1. dinero < 20.00: comprueba que el monto no sea inferior a 20.
2. dinero < bebidas.at(posicion).precioBebida: comprueba que el monto
alcance para pagar la bebida elegida.

La condición es verdadera si cualquiera de las dos comparaciones es
verdadera. Por eso el programa rechaza el monto y vuelve a pedirlo.

Ejemplo: si Coca Cola cuesta 25 pesos:

Dinero ¿Menor que 20?   ¿Menor que 25?   Resultado

────────

    10 Sí               Sí               Rechazado
    19 Sí               Sí               Rechazado
    20 No               Sí               Rechazado
    24 No               Sí               Rechazado
    25 No               No               Aceptado
    30 No               No               Aceptado

Los mensajes se seleccionan con:

if (dinero < 20.00) {
    cout << "El monto debe ser de al menos 20.00." << endl;
} else {
    cout << "El monto no alcanza para esta bebida." << endl;
}

Si el monto es inferior a 20, aparece el primer mensaje. Si es de 20 o
más, pero todavía menor que el precio de la bebida, aparece el segundo.

Después se vuelve a solicitar:

cout << "Introduzca nuevamente el monto: ";
cin >> dinero;

El while evalúa otra vez la condición. Solo termina cuando el dinero
alcanza para pagar.

En este programa todos los precios son de 20 pesos o más. Por eso, la
condición combinada equivale en la práctica a comprobar que el dinero
sea menor que el precio, pero mantenemos ambas comparaciones porque
expresan las dos validaciones del ejercicio.

20. Calcular el cambio

cambio = dinero - bebidas.at(posicion).precioBebida;

Resta el precio de la bebida al dinero recibido y guarda la diferencia
en cambio.

Ejemplo:

• Dinero recibido: 50.00.
• Precio: 25.00.
• Cambio: 50.00 - 25.00 = 25.00.

21. Descontar una unidad

bebidas.at(posicion).cantidadEnMaquina--;

-- es el operador de decremento: resta uno al valor.

Es equivalente a:

bebidas.at(posicion).cantidadEnMaquina =
    bebidas.at(posicion).cantidadEnMaquina - 1;

Si había 20 unidades, ahora hay 19. El vector conserva ese nuevo valor
durante el resto de la ejecución.

22. Acumular las ventas

totalVentas += bebidas.at(posicion).precioBebida;

+= suma el precio a lo que ya estaba guardado en totalVentas.

Es equivalente a:

totalVentas = totalVentas + bebidas.at(posicion).precioBebida;

Ejemplo:

Venta   Precio   Total acumulado

────────

    1    20.00             20.00
    2    25.00             45.00
    3    50.00             95.00

El acumulador comienza en cero y aumenta con cada venta.

No sumamos todo el dinero entregado por el cliente, porque el cambio
se devuelve. El total representa el importe de las bebidas vendidas.

23. Mostrar la bebida y el cambio

cout << "Retire su bebida: "
     << bebidas.at(posicion).nombreBebida
     << endl;

Muestra el nombre de la bebida que debe retirar el cliente.

cout << "Su cambio es: " << cambio << endl;

Muestra el cambio calculado. Como fixed y setprecision(2) están
activos, los importes se presentan con dos decimales.

24. Repetir o terminar

} while (opcion != 0);

Después de procesar la compra, se comprueba la condición:

• Si opcion es distinta de cero, vuelve a mostrarse el menú.
• Si opcion es cero, el ciclo termina.

25. Mostrar el total y finalizar

cout << "\nTotal de dinero recaudado: "
     << totalVentas << endl;

return 0;
}

El total se muestra después del ciclo, por eso aparece una sola vez
cuando el usuario sale.

return 0 indica que main() terminó correctamente. La última llave
cierra la función principal.

────────

26. Ejemplo de ejecución

Supongamos que se realizan dos compras:

1. Una Coca Cola de 25 pesos, pagando con 50.
2. Un Jugo V8 de 50 pesos, pagando con 100.
3. Luego se selecciona 0 para salir.

Salida simplificada:

Seleccione una opcion: 2
Bebida seleccionada: Coca Cola
Introduzca el monto de dinero: 50
Retire su bebida: Coca Cola
Su cambio es: 25.00

Seleccione una opcion: 5
Bebida seleccionada: Jugo V8
Introduzca el monto de dinero: 100
Retire su bebida: Jugo V8
Su cambio es: 50.00

Seleccione una opcion: 0
Total de dinero recaudado: 75.00

El total es 25.00 + 50.00 = 75.00.

────────

27. Resumen de conceptos

Concepto            Ejemplo                       Función

────────

struct            struct Bebida               Agrupa datos relacionados
vector            vector<Bebida> bebidas(5)   Almacena cinco bebidas
at()              bebidas.at(i)               Accede a una posición
size()            bebidas.size()              Devuelve la cantidad de elementos
Punto (.)         .precioBebida               Accede a un campo de la estructura
for               Recorrido de bebidas          Recorre el vector
do-while          Menú principal                Repite el programa
while             Validaciones                  Repite hasta recibir un valor permitido
if / else         Comprobar existencia          Toma decisiones
||                Validación del dinero         Operador lógico OR
--                Descontar existencia          Resta una unidad
+=                Acumular ventas               Suma al total
setw()            Formato de tabla              Establece ancho mínimo
left              Alineación                    Alinea a la izquierda
fixed             Formato decimal               Muestra decimales en formato fijo
setprecision(2)   Precios y cambio              Muestra dos decimales

28. Limitaciones de esta versión

1. La validación de la opción comprueba el rango numérico, pero no
recupera cin si el usuario escribe letras donde se espera un
número.
2. La validación del dinero también supone que se introduce un número;
no controla entradas como hola.
3. Las bebidas y sus precios están definidos al principio y no se
modifican mediante el menú.
4. Todas las existencias comienzan en 20.
5. Los datos no se guardan permanentemente. Al cerrar y volver a
ejecutar, las existencias regresan a 20 y totalVentas vuelve a
cero. Para conservarlos necesitaríamos utilizar archivos.
6. Toda la lógica está dentro de main(). Con las funciones de la
unidad 5 podremos separar el menú, la validación, la compra y los
cálculos en funciones propias.

29. Preguntas para comprobar que entendiste

Intenta responder sin mirar el código:

1. ¿Por qué utilizamos vector<Bebida> en lugar de declarar cinco
variables Bebida independientes?
2. ¿Por qué el vector tiene cinco elementos, pero sus índices van de 0
a 4?
3. ¿Qué diferencia existe entre size() y at()?
4. ¿Qué hace bebidas.at(posicion).cantidadEnMaquina--?
5. ¿Por qué utilizamos do-while para el menú?
6. ¿Qué diferencia existe entre totalVentas += precio y
totalVentas = precio?
7. ¿Por qué convertimos opcion en posicion restándole uno?
8. ¿Qué hace setw() y por qué lo colocamos antes de cada dato?
9. ¿Por qué el total suma el precio y no todo el dinero entregado por
el cliente?
10. ¿Qué pasaría si el usuario introduce una letra donde el programa
espera un número?

30. Idea principal para recordar

El recorrido completo de los datos es:

1. Creamos la estructura que describe una bebida.
2. Creamos un vector para guardar cinco bebidas.
3. Asignamos nombre, precio y existencia a cada posición.
4. Mostramos el vector recorriéndolo con for.
5. Recibimos y validamos la selección.
6. Comprobamos la existencia.
7. Recibimos y validamos el dinero.
8. Calculamos el cambio.
9. Descontamos una unidad.
10. Acumulamos el precio de la venta.
11. Repetimos hasta que el usuario seleccione salir.

La clave es comprender cómo trabajan juntos struct, vector, índices,
ciclos, condiciones y acumuladores. No se trata de memorizar el programa
completo, sino de reconocer qué responsabilidad tiene cada parte.