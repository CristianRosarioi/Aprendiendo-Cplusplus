#include <iostream>
using namespace std;

/*
  * Punteros como Parametros en Funciones.
  * Un puntero puede ser utilizado como parametro en una funcion.  Le da a la funcion
  * acceso al argumento original, muy similar al pase por referencia.
  * Hay que adminitir que es mucho mas facil trabajar con parametros por referencia que
  * con punteros.  Las variables de referencia ocultan toda la mecanica de dereferenciacion
  * e indireccionamiento.  Pero de todas formas debe aprender a usar punteros como
  * argumentos para llevar a cabo ciertas tareas, especialmente cuando se trata de strings.
  * Ademas la libreria de C++ tiene muchas funciones que usan punteros como parametros.
  */

// Prototipos de las funciones
void leeNumero(int *);
void duplicaValor(int *);

int main()
{
	int numero;

	//Llama a leeNumero y pasa la direccion de memoria de numero
	leeNumero(&numero);

	//Llama a duplicaValor y pasa la direccion de memoria de numero
	duplicaValor(&numero);

	//Despliega el valor en numero
	cout << "Ese valor duplicado es " << numero << endl;

	return 0;
}

void leeNumero(int *input)
{
	cout << "Entre un numero entero: ";
	cin >> *input;
}

void duplicaValor(int *val)
{
	*val *= 2;
}
