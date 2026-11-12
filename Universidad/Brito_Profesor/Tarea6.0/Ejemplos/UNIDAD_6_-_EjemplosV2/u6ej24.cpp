#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    short numeros[] = {31, 19, 14, 74, 9};

    /** No se debe utilizar &numeros para
      * asignar la direccion de memoria del
      * arreglo a numerosPtr ya que el nombre
      * del arreglo en si mismo contiene la
      * direccion de memoria en RAM de la primera
      * posicion en el arreglo, el elemento cero
      */
    short *numerosPtr = numeros;

    int indice = 0;
    while (indice < 5)
    {
        *(numerosPtr + indice) *= 2;
        cout << indice << ": "
             << *(numerosPtr + indice)
             << endl;
        indice++;
    }

    return 0;
}
