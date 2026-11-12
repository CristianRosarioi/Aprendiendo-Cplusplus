#include <iostream>
using namespace std;

/*
  * Relacion entre Arreglos y Punteros.
  * Los nombres de arreglos pueden ser usados como constantes tipo punteros, y los punteros pueden
  * ser usados como nombres de arreglos.
  * Es importante saber que los punteros no trabajan de la misma forma que las variables regulares
  * cuando se usan en una expresion matematica.  En C++, cuando se agrega un valor n a un puntero,
  * se esta agregando n veces el tamano del tipo de dato referenciado por el puntero.  En otras
  * palabras, si se agrega uno al arreglo numeros estamos haciendo 1 * sizeof(int).  Si se agrega 2 a
  * al arreglo numeros lo que hacemos es 2 * sizeof(int), y asi sucesivamente.
  *
  *    *(numeros + 1) es realmente *(numeros + 1 * 4)
  *    *(numeros + 2) es realmente *(numeros + 2 * 4)
  *    *(numeros + 3) es realmente *(numeros + 3 * 4)
  *
  * Esta conversion automatica significa que un un elemento en el arreglo puede ser obtenido mediante
  * el uso del sub-indice o mediante la suma del sub-indice al puntero del arreglo.
  */
int main(int argc, char* argv[])
{
	int numeros[] = {10, 20, 30, 40, 50};

	for (int i = 0; i < 5; i++)
    {
        //cout << "numeros[" << i << "] " << numeros[i] << endl;

		cout << "numeros[" << i << "]  " << *(numeros + i)
		     << "  ==> [" << (numeros + i) << "]" << endl;
    }

	return 0;
}
