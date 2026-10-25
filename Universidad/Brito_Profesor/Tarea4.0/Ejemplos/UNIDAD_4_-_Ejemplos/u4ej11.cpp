#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    /** Declara un vector de enteros
     *  (int) con cero elementos
     **/
    vector<int> numeros;
    int num;

    cout << "Entre un numero: ";
    cin >> num;
    numeros.push_back(num);

    cout << "El vector tiene "
         << numeros.size()
         << " elementos." << endl;

    return 0;
}
