#include <iostream>
using namespace std;

/*
  * Los punteros son necesarios para operaciones de asignacion de memoria.
  * Cuando se trabaja con una cantidad de data desconocida, la asignacion de memoria
  * nos permite crear variables, arreglos y estructuras de data mas complejas en memoria
  * mientras el programa se encuentre en ejecucion.  Los punteros son tambien muy utiles
  * para manipular arreglos y C-strings.  En programacion orientaba a objetos, los punteros
  * son muy usados para crear y trabajar con objetos y compartir acceso a estos.
  */
int main(int argc, char** argv)
{
	int x = 25;
	int *ptr;

	ptr = &x;

	cout << "El valor de x es: " << x << endl // 25
	     << "La direccion de memoria de x es: " << &x << endl // 0x
		 << "El valor al que apunta ptr es: " << *ptr << endl; // 25

	*ptr = 1974;
	cout << "\nAhora el valor de x es: " << x << endl // 1974
		 << "El valor al que apunta ptr es: " << *ptr << endl // 1974
		 << "Y la direccion es: " << ptr << endl; // 0x

	return 0;
}
