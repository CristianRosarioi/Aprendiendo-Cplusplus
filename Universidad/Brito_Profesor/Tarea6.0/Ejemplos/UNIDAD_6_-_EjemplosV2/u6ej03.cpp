#include <iostream>
using namespace std;

/*
  * Aritmetica de Punteros.
  * Algunas operaciones matematicas pueden ser realizadas sobre los punteros.
  * El contenido de las variables de puntero puede ser cambiado con sentencias matematicas
  * que realicen adicion y substraccion.
  * No todas las operaciones aritmeticas pueden ser realizadas sobre punteros.  Por ejemplo,
  * usted no puede multiplicar o dividir un puntero.  Las siguientes operaciones son permitidas:
  * - Pueden ser usados los operadores de incremento (++) y decremento (--)
  * - Se puede agregar o restar un entero de una variable puntero.  Esto puede ser realizado
  *    con los operadores + / -, o tambien con los operadores += / -=.
  * - Un puntero puede ser restado de otro puntero.
  */
int main(int argc, char* argv[])
{
	const int SIZE = 8;
	int numeros[SIZE] = {5, 10, 15, 20, 25, 30, 35, 40};
	int *numPtr;
	int contador;

	numPtr = numeros;

	cout << "Contenido del arreglo -numeros-\n";
	for (contador = 0; contador < SIZE; contador++)
	{
		cout << *numPtr << "  ";
		numPtr++;
	}

	cout << "\n\nDespliega el contenido del arreglo desde"
	     << "\nel ultimo elemento hasta el primero:\n";
	for (contador = 0; contador < SIZE; contador++)
	{
		numPtr--;
		cout << *numPtr << "  ";
	}
	return 0;
}
