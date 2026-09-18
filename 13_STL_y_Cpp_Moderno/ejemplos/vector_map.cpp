// Ejemplo: std::map (diccionario clave/valor) y vector
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, float> calificaciones;

    calificaciones["Matematicas"] = 8.5;
    calificaciones["Programacion"] = 9.0;
    calificaciones["Fisica"] = 7.5;

    cout << "Calificacion de Programacion: " << calificaciones["Programacion"] << endl;

    cout << "\nTodas las calificaciones:" << endl;
    for (auto& par : calificaciones) {
        cout << par.first << " -> " << par.second << endl;
    }
    return 0;
}