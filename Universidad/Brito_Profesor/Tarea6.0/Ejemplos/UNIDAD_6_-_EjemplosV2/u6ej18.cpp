#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int numeros[] = {10, 80, 30, 40, 50};

    for (int i = 0; i < 5; i++)
    {
        cout << "Address (" << (numeros + i) << ") - " << i << " : "
             << *(numeros + i) << endl;
    }

    cout << "Es mayor? " << ((numeros + 1) > (numeros + 3)) << endl;

    return 0;
}
