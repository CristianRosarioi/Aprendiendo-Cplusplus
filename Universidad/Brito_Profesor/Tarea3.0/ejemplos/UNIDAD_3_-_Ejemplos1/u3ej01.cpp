#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    string una = "Lo unico que no cambia es el cambio.";
    string msj = "Vive como si fueras a morir manana, ";
    msj += "aprende como si fueras a vivir para siempre.";

    cout << "retorna | length -> msj.length(): " << msj.length() << endl;
    cout << "retorna | empty  -> msj.empty() : " << msj.empty() << endl;
    cout << "retorna | at     -> msj.at(int) : " << msj.at(7) << endl;
    cout << "retorna | substr -> msj.substr(2, 4): " << msj.substr(2, 4) << endl;
    cout << "retorna | substr -> msj.substr(70): " << msj.substr(70) << endl;
    cout << "retorna | size   -> msj.size()    : " << msj.size() << endl;
    cout << "retorna | data   -> msj.data()    : " << msj.data() << endl;
    cout << "retorna | c_str  -> msj.c_str()   : " << msj.c_str() << endl;
    cout << "retorna | find   -> msj.find(char, int): "
         << msj.find('z') << endl;

    cout << "msj.push_back('Z'); \n";
    msj.push_back('Z');
    cout << msj << endl;

    cout << "msj.insert(2, '@'); \n";
    msj.insert(2, "@**@");
    cout << msj << endl;

    cout << "msj.erase(2, 1); \n";
    msj.erase(2, 1);
    cout << msj << endl;

    msj.swap(una);
    msj.swap(una);
    cout << msj << endl;

    return 0;
}
