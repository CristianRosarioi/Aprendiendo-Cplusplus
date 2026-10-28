#include <iostream>

using namespace std;

int suma(int, int);
double suma(double, double);

int main(int argc, char** argv)
{
    cout << suma(4, 5) << endl;
    cout << suma(3.5, 4.0) << endl;
    return 0;
}

int suma(int a, int b)
{
    return a + b;
}

double suma(double a, double b)
{
    return a + b;
}
