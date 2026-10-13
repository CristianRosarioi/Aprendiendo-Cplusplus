#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    vector<int> edades;
    // vector<int> edades(4);
    // vector<int> edades(4, -9);

    int edad;
    int cont = 1;

    do
    {
        cout << "Entre edad " << cont++ << ": ";
        cin >> edad;

        if (edad == 0) break;

        edades.push_back(edad);
    } while(true);

    for (int i = 0; i < edades.size(); i++)
    {
        cout << edades.at(i) << endl;
    }

    return 0;
}
