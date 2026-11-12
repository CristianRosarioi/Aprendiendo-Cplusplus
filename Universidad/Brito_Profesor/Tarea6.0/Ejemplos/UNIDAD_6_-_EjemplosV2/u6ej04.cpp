#include <iostream>
using namespace std;

/*
  * Comparando Punteros.
  * Si una direccion se encuentra antes de otra direccion en memoria, la primera direccion
  * es considerada "menor" que la segunda.  Los operadores de relacion de C++ pueden ser
  * usados para comparar los valores de los punteros.
  * Los punteros pueden ser comparados mediante el uso de los operadores:
  * >   <   ==   !=   >=   <=
  */
int main()
{
	int numeros[8] = {-10, 38, 95, 1, -17, 22, 33, 85};
	int *ptrNum1 = numeros + 4; // es -17
	int *ptrNum2 = numeros + 2; // es 95

	cout << "\nDireccion de memoria en ptrNum1: " << ptrNum1 << endl
		 << "Direccion de memoria en ptrNum2: " << ptrNum2 << endl
		 << endl;

	if (ptrNum1 > ptrNum2)
		cout << "ptrNum1 es mayor que ptrNum2" << endl;
	else if (ptrNum1 < ptrNum2)
		cout << "ptrNum1 es menor que ptrNum2" << endl;
	else
		cout << "ptrNum1 es igual que ptrNum2" << endl;

	cout << "\nEl valor al que apunta ptrNum1 es: " << *ptrNum1 << endl
		 << "El valor al que apunta ptrNum2 es: " << *ptrNum2 << endl;

	return 0;
}
