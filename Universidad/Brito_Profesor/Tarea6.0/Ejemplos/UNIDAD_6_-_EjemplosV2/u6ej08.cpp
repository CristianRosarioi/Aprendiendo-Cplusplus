#include <iostream>
#include <iomanip>
using namespace std;

/******************************************************************/
/* Programa que crea un arreglo de tamano leido por teclado       */
/* para calcular las ventas totales y ventas promedio utilizando  */
/* punteros para crear un arreglo de tamano variable en tiempo de */
/* ejecucion                                                      */
/******************************************************************/

int main(int argc, char** argv)
{
	double *ventas,     // Para asignar dinamicamente un arreglo
	       total = 0.0, // Acumulador
		   promedio;    // Promedio de ventas

	int numDias,        // Para almacenar el numero de dias de ventas
	    contador;       // Variable contador

	// Lee el numero de dias de ventas
	cout << "Cuantos dias de venta desea procesar? ";
	cin >> numDias;

	// Asigna dinamicamente un arreglo lo suficientemente grande
	// para almacenar la cantidad de ventas
	ventas = new double[numDias];

	// Lee las ventas para cada dia
	for (contador = 0; contador < numDias; contador++)
	{
		cout << "Dia " << (contador + 1) << ": ";
		cin >> ventas[contador];
	}

	// Calcula la venta total
	for (contador = 0; contador < numDias; contador++)
	{
		total += ventas[contador];
		//total += *(ventas + contador);
		//total += *ventas++;
	}

	// Calcula el promedio
	promedio = total / numDias;

	// Despliega el resultado
	cout << fixed << showpoint << setprecision(2);
	cout << "\n\nVentas totales: RD$" << total << endl;
	cout << "Venta promedio: RD$" << promedio << endl;

	// Libera la memoria dinamicamente asignada
	delete [] ventas;
	ventas = 0;  // Hacemos que el puntero ventas apunte a NULL

	return 0;
}
