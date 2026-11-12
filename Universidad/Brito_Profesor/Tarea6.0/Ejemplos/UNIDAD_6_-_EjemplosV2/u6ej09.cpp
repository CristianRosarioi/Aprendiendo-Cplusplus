#include <iostream>
using namespace std;
// Este programa usa una funcion que duplica un arreglo
// tipo int de cualquier tamano

// Prototipos
int *duplicaArreglo(const int *, int);
void imprimeArreglo(int[], int);

int main()
{
   // Define constantes para el tamano de cada arreglo a duplicar
   const int SIZE1 = 5, SIZE2 = 7, SIZE3 = 10;

   // Define tres arreglos de tamanos diferentes
   int array1[SIZE1] = {100, 200, 300, 400, 500};
   int array2[SIZE2] = {10, 20, 30, 40, 50, 60, 70};
   int array3[SIZE3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

   // Define tres punteros para poder recibir los arreglos duplicados
   int *dup1, *dup2, *dup3;

   // Duplica los arreglos
   dup1 = duplicaArreglo(array1, SIZE1);
   dup2 = duplicaArreglo(array2, SIZE2);
   dup3 = duplicaArreglo(array3, SIZE3);

   // Despliega los arreglos originales
   cout << "Aqui esta el contenido de los arreglos originales:\n";
   imprimeArreglo(array1, SIZE1);
   imprimeArreglo(array2, SIZE2);
   imprimeArreglo(array3, SIZE3);

   // Despliega los nuevos arreglos
   cout << "\nAqui esta el contenido de los nuevos arreglos:\n";
   imprimeArreglo(dup1, SIZE1);
   imprimeArreglo(dup2, SIZE2);
   imprimeArreglo(dup3, SIZE3);

   // Libera la memoria dinamicamente asignada
   delete [] dup1;
   delete [] dup2;
   delete [] dup3;
   dup1 = 0;
   dup2 = 0;
   dup3 = 0;
   return 0;
}

// *****************************************************************************
// La funcion duplicaArreglo acepta un arreglo tipo int y otro argumento int que indica el
// tamano del arreglo.  La funcion crea un nuevo arreglo el cual es un duplicado del arreglo
// pasado como argumento y retorna un puntero que apunta al nuevo arreglo.  Si se pasa un
// tamano de arreglo invalido la funcion retorna null.
// *****************************************************************************
int *duplicaArreglo(const int *arr, int size)
{
   int *newArray;

   // Valida el tamano del arreglo.  Si es cero o negativo retorna null
   if (size <= 0)
      return NULL;

   // Asigna de forma dinamica el nuevo arreglo
   newArray = new int[size];

   // Copia el contenido del arreglo argumento al nuevo arreglo
   for (int index = 0; index < size; index++)
      newArray[index] = arr[index];
      //*newArray++ = *arr++;

   // Retorna el puntero que apunta al nuevo arreglo
   return newArray;
}

// *****************************************************************************
// La funcion imprimeArreglo acepta un arreglo de enteros y otro entero que indica el
// tamano del arreglo e imprime su contenido
// *****************************************************************************
void imprimeArreglo(int arr[], int size)
{
   for (int index = 0; index < size; index++)
      cout << arr[index] << " ";
   cout << endl;
}
