#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Prototipo de la funcion
void consultarUsuario(string Usuario, string Clave);

int main() {

    string Usuario;
    string Clave;

    cout << "\nIntroduzca su Usuario: ";
    getline(cin, Usuario);

    cout << "Introduzca su Clave: ";
    getline(cin, Clave);

    // Consultar los datos en el archivo
    consultarUsuario(Usuario, Clave);

    return 0;
}

// Funcion que consulta el usuario y la clave
void consultarUsuario(string Usuario, string Clave) {

    // Abrir el archivo para lectura
    fstream archivo("USUARIO.txt", ios::in);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo USUARIO.txt" << endl;
        return;
    }

    string usuarioGuardado;
    string claveGuardada;

    bool encontrado = false;

    // Leer todos los usuarios del archivo
    while (getline(archivo, usuarioGuardado)) {

        // Ignorar las lineas vacias
        if (usuarioGuardado != "") {

            // Leer la clave del usuario
            if (!getline(archivo, claveGuardada)) {
                break;
            }

            // Comparar usuario y clave
            if (Usuario == usuarioGuardado &&
                Clave == claveGuardada) {

                encontrado = true;
                break;
            }
        }
    }

    // Mostrar el resultado
    if (encontrado) {
        cout << "\nSu acceso ha sido exitoso." << endl;
    } else {
        cout << "\nUsuario o clave incorrectos. Acceso denegado."
             << endl;
    }

    // Cerrar el archivo
    archivo.close();
}