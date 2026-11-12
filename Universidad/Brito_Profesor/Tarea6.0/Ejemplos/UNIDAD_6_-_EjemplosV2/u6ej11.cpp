#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// *****************************************************************************
// * Las funciones pueden retornar punteros, pero debe asegurarse que el dato
// * al que apunta el puntero todavia existe.
// * Se debe retornar punteros de una funcion si:
// *    - El puntero apunta un dato que fue pasado como argumento en una funcion
// *    - El puntero apunta a una porcion de memoria asignada dinamicamente
// *****************************************************************************

// Prototipos
int *getRandomNums(int, int);

int main(int argc, char** argv)
{
	int *numeros;

	// Obtiene un arreglo de 5 numeros aleatorios
	numeros = getRandomNums(5, 10);

	// Despliega los numeros
	for (int contador = 0; contador < 5; contador++)
		cout << numeros[contador] << endl;

	// Libera la memoria
	delete [] numeros;
	numeros = 0;

	return 0;
}

int *getRandomNums(int num, int divisor)
{
	int *arr;  // Arreglo para almacenar los numeros

	// Retorna NULL si num es cero o negativo
	if (num <= 0)
		return NULL;

	// Asigna dinamicamente el arreglo
	arr = new int[num];

	// Coloca la semilla para la generacion aleatoria de los numeros
	srand(time(0));

	// Poblar el arreglo con numeros aleatorios
	for (int contador = 0; contador < num; contador++)
		arr[contador] = rand() % divisor + 1;

	// Retorna el puntero
	return arr;
}
