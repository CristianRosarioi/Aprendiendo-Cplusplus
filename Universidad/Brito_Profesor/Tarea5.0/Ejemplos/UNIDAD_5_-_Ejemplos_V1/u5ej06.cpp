#include <iostream>

using namespace std;

int suma(int, int, int = 0);

int main(int argc, char** argv)
{
    int num1 = 3, num2 = 6;

    cout << "Invocando funcion con 2 parametros: " << suma(num1, num2) << endl;
    cout << "Invocando funcion con 3 parametros: " << suma(num1, num2, 1) << endl;

    return 0;
}

int suma(int a, int b, int c)
{
    return a + b + c;
}
