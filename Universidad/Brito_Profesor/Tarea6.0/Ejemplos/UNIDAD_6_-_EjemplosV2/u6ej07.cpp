#include <iostream>
using namespace std;

int main()
{
	int valor = 22;
	int valor2 = 33;
	int valor3 = 44;

	int * const ptr = &valor2;
	// ptr = &valor2; error: assignment of read-only variable 'ptr'
	// No es posible hacer que el puntero apunte a otra direccion de memoria
	// Es un puntero constante (la variable puntero es una constante)
    // error: ptr = &valor3;
    // OK   : *ptr = 500;
	*ptr = valor;

	const int *ptr2 = &valor2;
	// *ptr2 = 34; error: assignment of read-only location '* ptr2'
	// No es posible cambiar el contenido del valor al que apunta el puntero
	// Es un puntero de constante (apunta a una constante)
	// error: *ptr2 = 500;
	// OK   : ptr2 = &valor3;
	ptr2 = &valor;

	const int * const ptr3 = &valor3;
	// No es posible cambiar ni el valor al que apunta el puntero
	// ni tampoco hacer que el puntero apunte a otro valor
	// Es un puntero constante que apunta a una constante
	// error: ptr3 = &valor2;
	// error: *ptr3 = 500;

	cout << "ptr = " << ptr << endl;
	cout << "*ptr = " << *ptr << endl;
	cout << "ptr2 = " << ptr2 << endl;
	cout << "*ptr2 = " << *ptr2 << endl;
	cout << "ptr3 = " << ptr3 << endl;
	cout << "*ptr3 = " << *ptr3 << endl;


    int arreglo[] = {2, 4, 5};
    cout << arreglo << endl;
    cout << *arreglo << endl;
    cout << arreglo[0] << endl;
    cout << *(arreglo + 1) <<endl; // 4
    cout << *arreglo + 1<< endl; // 3
	return 0;
}
