#include <iostream>

using namespace std;

/** prototipo de las funciones **/
void despliegaMensaje();
int suma(int a, int b);

int main(int argc, char** argv)
{
    despliegaMensaje();
    cout << suma(4, 15) << endl;
    return 0;
}

void despliegaMensaje()
{
    cout << "Bienvenido a nuestra prueba\n";
}

int suma(int a, int b)
{
    return a + b;
}
