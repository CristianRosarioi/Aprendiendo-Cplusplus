#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> creaVector(int, int);
void imprimeVector(vector<int>);

int main(int argc, char** argv)
{
    vector<int> numeros = creaVector(10, 50);
    imprimeVector(numeros);

    return 0;
}

/**
 * Funcion    : creaVector
 * Descripcion: Esta funcion recibe dos enteros, el primero define cuantos
 *              elementos tendra el vector, es decir, su tamano.  Y el segundo
 *              define el limite para generacion de numeros aleatorios, es decir,
 *              si el limite es 20, el vector sera poblado con numeros aleatorios
 *              entre 1 y 20.
 * Objetivo   : Hacemos uso de la funcion srand() y rand() para crear o generar
 *              numeros aleatorios los cuales agregaremos a nuestro vector haciendo
 *              o ejecutando la funcion "push_back"
 *              Declaramos un vector de enteros llamado temp al cual le agregaremos
 *              los numeros, este vector luego sera retornado por la funcion
 */
vector<int> creaVector(int cantidad, int limite)
{
    srand(time(0));
    vector<int> temp;
    int numero = 0;

    for (int i = 0; i < cantidad; i++)
    {
        numero = rand() % limite + 1;
        temp.push_back(numero);
    }

    return temp;
}

void imprimeVector(vector<int> v)
{
    vector<int>::iterator ite = v.begin();

    while (ite != v.end())
    {
        cout << *ite++ << endl;
    }
}
