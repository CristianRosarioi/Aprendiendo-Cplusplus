# 11 - Herencia y Polimorfismo

## Herencia

Una clase "hija" hereda atributos y metodos de una clase "padre" y puede
agregar o modificar comportamiento.

```cpp
class Persona {
protected:
    string nombre;
public:
    Persona(string n) : nombre(n) {}
    void saludar() {
        cout << "Hola, soy " << nombre << endl;
    }
};

class Estudiante : public Persona {     // hereda de Persona
private:
    int matricula;
public:
    Estudiante(string n, int m) : Persona(n), matricula(m) {}

    void mostrarMatricula() {
        cout << "Matricula: " << matricula << endl;
    }
};
```

- `protected`: accesible en la clase hija, no desde fuera.
- `: public Persona`: empieza la herencia.
- El constructor de la hija llama al del padre con `: Persona(n)`.

## Polimorfismo

Un mismo metodo hace cosas diferentes segun el objeto. Clasico: animales.

```cpp
class Animal {
public:
    // virtual => permite que la clase hija la "redefina" (override)
    virtual void sonar() {
        cout << "... silencio" << endl;
    }
    virtual ~Animal() {}        // destructor virtual (buena practica)
};

class Perro : public Animal {
public:
    void sonar() override {     // override = redefino la version del padre
        cout << "Guau guau" << endl;
    }
};

class Gato : public Animal {
public:
    void sonar() override {
        cout << "Miau" << endl;
    }
};

// Uso polimorfico
Animal* mascota1 = new Perro();
Animal* mascota2 = new Gato();
mascota1->sonar();    // Guau guau
mascota2->sonar();    // Miau
```

## Palabras clave

- `virtual` en el metodo del padre: permite sobreescribirlo.
- `override` en la hija: aclara que estoy redefiniendo (y el compilador verifica).
- `->` acceso a metodo/atributo cuando tienes un PUNTERO a un objeto.

## Ejemplos en esta carpeta

- `herencia_estudiante.cpp` - Persona -> Estudiante
- `polimorfismo_animal.cpp` - Animal -> Perro/Gato con virtual

## Retos (en `retos/`)

- `r01_*` - clase Vehiculo: Auto y Moto que sobreescriben mover()
- `r02_*` - clase Figura y Circulo/Rectangulo con area()
- `r03_*` - Empleado y sus tipos (asado a salario, por hora)

Siguiente tema: **12 - Memoria y Archivos**.