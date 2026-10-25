#include <iostream>
#include <vector>

using namespace std;

void print(vector<string>);

int main(int argc, char** argv)
{
    vector<string> comidas;
    vector<string>::iterator v;

    comidas.push_back("Pincho de Camarones");
    comidas.push_back("Chuleta Fresca a la Parrilla");
    comidas.push_back("Fabada");
    comidas.push_back("Paella Marinera");
    comidas.push_back("Vino Pinot Noir");
    comidas.push_back("Vino Late Harvest");

    v = comidas.begin();
    while(v != comidas.end())
    {
        cout << *v++ << endl;
    }


    v = comidas.begin();

    //cout << endl << *(v + 2) << endl << endl;

    comidas.erase(v + 2);
    print(comidas);

    cout << endl << endl << comidas.size() << endl;
    comidas.clear();
    cout << endl << endl << comidas.size() << endl;

    return 0;
}

void print(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr.at(i) << endl;
}
