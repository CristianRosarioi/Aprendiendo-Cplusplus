#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> creaVector(int);
void imprimeVector(vector<int>);

int main(int argc, char** argv)
{
    vector<int> numeros;
    numeros = creaVector(5);
    imprimeVector(numeros);
    return 0;
}

vector<int> creaVector(int cantidad)
{
    srand(time(0));
    int numero;
    vector<int> arreglo;
    for (int i = 0; i < cantidad; i++)
    {
        numero = rand() % 100 + 1;
        arreglo.push_back(numero);
    }

    return arreglo;
}

void imprimeVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr.at(i) << endl;
}
