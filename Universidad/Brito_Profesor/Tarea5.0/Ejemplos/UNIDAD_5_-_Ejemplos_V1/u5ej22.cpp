#include <iostream>
#include <vector>

using namespace std;

int mayor(vector<int>);

int main(int argc, char** argv)
{
    vector<int> numeros;
    numeros.push_back(34);
    numeros.push_back(55);
    numeros.push_back(47);

    cout << "El mayor es: "
         << mayor(numeros) << endl;
    return 0;
}

int mayor(vector<int> arreglo)
{
    int mayor = arreglo.at(0);
    for (int i = 0; i < arreglo.size(); i++)
    {
        if (arreglo.at(i) > mayor)
            mayor = arreglo.at(i);
    }

    return mayor;
}
