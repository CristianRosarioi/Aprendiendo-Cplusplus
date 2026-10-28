#include <iostream>

using namespace std;

int suma(int, int);
int suma(int, int, int, int);
float suma(float, float);

int main(int argc, char** argv)
{
    cout << suma(3, 4) << endl;
    cout << suma(8, 7, 92, 1) << endl;
    cout << suma(3.2f, 4.5f) << endl;
    return 0;
}

int suma(int a, int b)
{
    return a + b;
}

int suma(int a, int b, int c, int d)
{
    return a + b + c + d;
}

float suma(float a, float b)
{
    return a + b;
}
