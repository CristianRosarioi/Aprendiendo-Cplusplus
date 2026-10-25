#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<string>);

int main(int argc, char** argv)
{
    vector<string> comidas;
    vector<string> bebidas;
    vector<string>::iterator ite;

    bebidas.push_back("Pina Colada");
    bebidas.push_back("Vino Carbernet Sauvignon");
    bebidas.push_back("Vino Pinot Noir");
    bebidas.push_back("Vino Tempranillo");
    bebidas.push_back("Vino Merlot");
    bebidas.push_back("Cerveza Beck's");

    comidas.push_back("Ravioli relleno de espinacas");
    comidas.push_back("Canelones rellenos de carne");
    comidas.push_back("Lasagna de pollo");
    comidas.push_back("Crema de auyama");
    comidas.push_back("Ravioli relleno de hongos");
    comidas.push_back("Alitas en salsa BBQ");
    comidas.push_back("Costillas Babyback");
    comidas.push_back("Ribeye 16oz");
    comidas.push_back("Chivo guisado picante");

    cout << "comidas.size()  : " << comidas.size() << endl;
    cout << "comidas.empty() : " << ((comidas.empty()) ? "Vacio" : "Tiene elementos") << endl;
    cout << "comidas.at(5)   : " << comidas.at(5) << endl;
    ite = find(comidas.begin(), comidas.end(), "Ribeye 16oz");
    cout << "comidas.find(\"Ribeye 16oz\"): " << *ite << endl;

    // ite = 8

    print(comidas);

    cout << "comidas.erase(ite)" << endl;
    comidas.erase(ite);
    print(comidas);

    cout << "comidas.insert(ite - 4, \"Spaguetti a la bolognesa\")" << endl;
    comidas.insert(ite - 4, "Spaguetti a la bolognesa");
    print(comidas);

    cout << "comidas.pop_back()" << endl;
    comidas.pop_back();
    print(comidas);

    cout << "comidas.swap(bebidas)" << endl;
    comidas.swap(bebidas);
    print(comidas);

    return 0;
}

void print(vector<string> x)
{
    cout << endl;
    for (int i = 0; i < x.size(); i++)
        cout << x.at(i) << endl;

    cout << endl << endl;
}
