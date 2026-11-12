#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/******************************************************************/
/* Programa que lee 4 numeros enteros, los almacena en un arreglo */
/* y crea 4 arreglos distintos del tamano de cada numero leido    */
/* previamente en el primer arreglo                               */
/******************************************************************/

// Prototipos
int *creaArreglo(int);
void imprimeArreglo(int *, int);
void leeArreglo(int *, int);

int main()
{
	const int SIZE = 4;
	int numeros[SIZE];

	leeArreglo(numeros, SIZE);

	int *newArr1;
	int *newArr2;
	int *newArr3;
	int *newArr4;

	newArr1 = creaArreglo(numeros[0]);
	newArr2 = creaArreglo(numeros[1]);
	newArr3 = creaArreglo(numeros[2]);
	newArr4 = creaArreglo(numeros[3]);

	imprimeArreglo(newArr1, numeros[0]);
	imprimeArreglo(newArr2, numeros[1]);
	imprimeArreglo(newArr3, numeros[2]);
	imprimeArreglo(newArr4, numeros[3]);

	delete [] newArr1;
	delete [] newArr2;
	delete [] newArr3;
	delete [] newArr4;
	newArr1 = 0;
	newArr2 = 0;
	newArr3 = 0;
	newArr4 = 0;

	return 0;
}

/******************************************************************/
/* Lee arreglo de 4 numeros para tomarlos como los tamanos de los */
/* 4 arreglos que seran creados                                   */
/******************************************************************/
void leeArreglo(int *arr, int size)
{
	cout << "Entre cuatro numeros enteros positivos.\n\n";
	for (int contador = 0; contador < size; contador++)
	{
		do
		{
			cout << "Entre el elemento " << (contador + 1) << ": ";
			cin >> arr[contador];
		} while(arr[contador] <= 0);
	}
}

/******************************************************************/
/* Funcion que imprime un arreglo, lo recibe como un puntero      */
/******************************************************************/
void imprimeArreglo(int *arr, int size)
{
	cout << "\n\nArreglo de " << "<" << size << ">" << " elementos:\n ";
	for (int contador = 0; contador < size; contador++)
	{
		cout << arr[contador] << "   ";
	}
}

/******************************************************************/
/* Funcion que crea un arreglo de un tamano definido por el       */
/* argumento y retorna un puntero que hace referencia a la        */
/* direccion en memoria donde se encuentra                        */
/******************************************************************/
int *creaArreglo(int size)
{
	int *arr;  // Arreglo para almacenar los numeros

	// Retorna NULL si size es cero o negativo
	if (size <= 0)
		return NULL;

	// Asigna dinamicamente el arreglo
	arr = new int[size];
	if (arr != NULL)
    {
        // Coloca la semilla para la generacion aleatoria
        // de los numeros
        srand(time(0));
        // Poblar el arreglo con numeros aleatorios
        for (int contador = 0; contador < size; contador++)
            arr[contador] = 1 + rand() % size;
    }

    // retorna el puntero
    return arr;
}
