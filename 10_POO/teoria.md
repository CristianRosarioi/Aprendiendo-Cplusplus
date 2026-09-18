# 10 - POO (Programacion Orientada a Objetos)

Programar "con clases": agrupar **datos** (atributos) y **comportamiento**
(metodos) en un mismo tipo. Esto es la evolucion del `struct`.

## Clase basica

```cpp
#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:                      // solo accesible desde dentro de la clase
    string nombre;
    int edad;

public:                       // accesible desde fuera
    // Constructor: se ejecuta al crear el objeto
    Estudiante(string n, int e) {
        nombre = n;
        edad = e;
    }

    void saludar() {
        cout << "Hola, soy " << nombre << " y tengo " << edad << " anos" << endl;
    }

    // getter / setter (controla el acceso a los privados)
    void setNombre(string n) { nombre = n; }
    string getNombre()       { return nombre; }
};

int main() {
    Estudiante e1("Cristian", 20);   // llama al constructor
    e1.saludar();
    e1.setNombre("Chris");
    cout << e1.getNombre() << endl;
    return 0;
}
```

## Modificadores de acceso

| Modificador | Acceso                            |
|-------------|-----------------------------------|
| `private`   | solo dentro de la clase (default) |
| `public`    | desde cualquier parte             |
| `protected` | clase + clases hijas (tema 11)    |

## Encapsulacion

Es la idea de que los datos importantes esten `private` y se acceda a ellos
mediante metodos publicos (getters/setters y metodos de negocio). Asi puedes
validar: p.ej. no permitir una edad negativa.

## Constructor

- Se llama `igual` que la clase (sin tipo de retorno).
- Puede tener parametros para inicializar el objeto.
- Existe un constructor por defecto automatico si no defines ninguno.

## Ejemplos en esta carpeta

- `clase_estudiante.cpp` - clase con constructor y metodos
- `clase_cuenta.cpp` - cuenta bancaria con encapsulacion

## Retos (en `retos/`)

- `r01_*` - clase rectangulo con area y perimetro
- `r02_*` - clase cuenta bancaria (depositar, retirar, mostrar)
- `r03_*` - clase estudiante con validacion de profesor

Siguiente tema: **11 - Herencia y Polimorfismo**.