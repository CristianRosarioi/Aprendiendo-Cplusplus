#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string pais = "Republica Dominicana";
    string::iterator ite = pais.begin();

    while (ite != pais.end())
    {
        cout << *ite << endl;
        ite++;
    }

    return 0;
}
