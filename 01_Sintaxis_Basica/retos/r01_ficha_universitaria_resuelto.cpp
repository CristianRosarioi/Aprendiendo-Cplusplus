
// Variables y entrada/salida básica

/*Tu Primer Reto: 
"Ficha Universitaria Interactiva"
Escribe un programa en C++ que:
Pida al usuario que ingrese su nombre (una sola palabra por ahora).
Pida su edad (entero).
Pida su promedio acumulado o calificación deseada (número con decimales).
Luego, imprima una ficha formateada con los datos que ingresó y calcule cuántos años tendrá dentro de 5 años.*/


 #include <iostream>
 using namespace std;

 int main() {
        string nombre;
        int edad;
        float promedio;
        cout << "Ingrese su nombre: ";
        cin >> nombre;
        cout << "Ingrese su edad: ";
        cin >> edad;
        cout << "Ingrese su promedio acumulado: ";
        cin >> promedio;
        cout << "\n Ficha Universitaria Interactiva" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Promedio acumulado: " << promedio << endl; 
        cout << "Edad en 5 años: " << edad + 5 << endl;
        return 0;
 }

