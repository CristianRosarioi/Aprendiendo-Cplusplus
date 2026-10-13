/* RETO r03 - "Cambio de moneda"
Escribe un programa que:
1. Pida una cantidad en pesos dominicanos (double).
2. Pida la tasa de cambio a dolares (double, ej: 58.5).
3. Muestre cuantos dolares obtiene:  cantidad / tasa.
Pistas: cantidad / tasa; */


#include <iostream>
using namespace std;

int main() {

double dop;
double tasa;

cout << "cantidad en peso dominicano: ";
cin >> dop;

cout << "cual es la tasa del dolar hoy: ";
cin >> tasa;

cout << "el cambio a usd es: " << dop / tasa << endl;

return 0;
} 
