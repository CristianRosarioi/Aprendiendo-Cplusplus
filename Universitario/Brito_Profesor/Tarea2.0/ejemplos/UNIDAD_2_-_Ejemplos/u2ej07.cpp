#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    unsigned int mes;

    cout << "Entre el numero del mes [1-12]: ";
    cin >> mes;

    switch (mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << "Tiene 31 dias." << endl;
            break;
        case 2:
            cout << "Tiene 28 dias." << endl;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout << "Tiene 30 dias." << endl;
            break;
        default:
            cout << "Numero de mes incorrecto." << endl;
    }

    return 0;
}
