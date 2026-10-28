/*
Universidad Autónoma de Santo Domingo UASD
Centro UASD San Pedro, Escuela de informatica 5100-29
Introduccion a la Programacion
Cristian Rosario
Matricula: 100806653
*/

// Juego: Piedra, Papel o Tijera

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Constantes para las opciones
const char PIEDRA = 'P';
const char PAPEL = 'A';
const char TIJERA = 'T';
const char SALIR = 'S';

// Prototipos de las funciones
void displayMenu();
char getComputerOption();
string checkOptions(char, char);
bool inputOK(char);

int main() {
    char opcionUsuario;
    char opcionComputadora;
    string resultado;

    // Inicializar los numeros aleatorios
    srand(time(0));

    do {
        displayMenu();

        cin >> opcionUsuario;

        // Convertir a mayuscula
        opcionUsuario = toupper(opcionUsuario);

        // Validar la opcion
        while (!inputOK(opcionUsuario)) {
            cout << "Opcion no valida. Intente de nuevo: ";
            cin >> opcionUsuario;
            opcionUsuario = toupper(opcionUsuario);
        }

        if (opcionUsuario != SALIR) {

            // Generar la opcion de la computadora
            opcionComputadora = getComputerOption();

            // Mostrar las selecciones
            cout << "Usted eligio: ";

            if (opcionUsuario == PIEDRA) {
                cout << "Piedra" << endl;
            } else if (opcionUsuario == PAPEL) {
                cout << "Papel" << endl;
            } else {
                cout << "Tijera" << endl;
            }

            cout << "La computadora eligio: ";

            if (opcionComputadora == PIEDRA) {
                cout << "Piedra" << endl;
            } else if (opcionComputadora == PAPEL) {
                cout << "Papel" << endl;
            } else {
                cout << "Tijera" << endl;
            }

            // Comparar las opciones
            resultado = checkOptions(opcionUsuario,
                                     opcionComputadora);

            cout << "Resultado: " << resultado << endl;
            cout << endl;
        }

    } while (opcionUsuario != SALIR);

    cout << "Gracias por jugar." << endl;

    return 0;
}

// Funcion que muestra el menu
void displayMenu() {
    cout << "===== PIEDRA, PAPEL O TIJERA =====" << endl;
    cout << "P - Piedra" << endl;
    cout << "A - Papel" << endl;
    cout << "T - Tijera" << endl;
    cout << "S - Salir" << endl;
    cout << "Opcion: ";
}

// Funcion que genera la opcion de la computadora
char getComputerOption() {
    int numero = rand() % 3;

    if (numero == 0) {
        return PIEDRA;
    } else if (numero == 1) {
        return PAPEL;
    } else {
        return TIJERA;
    }
}

// Funcion que compara las opciones
string checkOptions(char usuario, char computadora) {

    if (usuario == computadora) {
        return "Empate :|";
    }

    if ((usuario == PIEDRA && computadora == TIJERA) ||
        (usuario == TIJERA && computadora == PAPEL) ||
        (usuario == PAPEL && computadora == PIEDRA)) {

        return "Gano! :)";
    }

    return "Perdio :(";
}

// Funcion que valida las opciones
bool inputOK(char opcion) {

    if (opcion == PIEDRA || opcion == PAPEL ||
        opcion == TIJERA || opcion == SALIR) {
        return true;
    }

    return false;
}
