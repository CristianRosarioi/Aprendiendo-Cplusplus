/*
  vect9.cpp
  Compilador: bcc32 5.5

  C++ \ FERREIRAS \ <vector>

   Operadores de comparacion !=, <,  <=, ==,  >,  >=


*/


/*#include <vector>
#include <iostream>
#include <conio>

using namespace std;

int main(void){


     vector<float> vec1, vec2, vec3;   
     vector<float>::iterator iter1, iter2, iter3; 
     float real;
 
     system("cls");

    // vec1

     cout << endl << "ENTRE VALORES REALES. PARA TERMINAR CTRL+Z DOS VECES:" << endl << endl;
     while( cin >> real) {
         vec1.push_back(real); 
     }
  
    
    // vec2
  
    cin.ignore(4);  
    cin.clear();
    cout << endl << "ENTRE VALORES REALES. PARA TERMINAR CTRL+Z DOS VECES:" << endl << endl;
     while( cin >> real) {
         vec2.push_back(real); 
     }
  
  
   // vec3
    
     cin.ignore(4);  
     cin.clear();
     cout << endl << "ENTRE VALORES REALES. PARA TERMINAR CTRL+Z DOS VECES:" << endl << endl;
     while( cin >> real) {
         vec3.push_back(real); //
     }
     
   
    system("cls"); 
    cout << endl << endl << "Data en el vector vec1 es: " << endl;
    iter1 = vec1.begin(); 
    while( iter1 != vec1.end() ){ 
       cout << *iter1 << "  "; 
       iter1++; 
    }

    cout << endl << endl << "Data en el vector vec2 es: " << endl;
    iter1 = vec2.begin(); 
    while( iter1 != vec2.end() ){ 
       cout << *iter1 << "  "; 
       iter1++; 
    }

     cout << endl << endl<< "Data en el vector vec3: " << endl;
     for(iter2 = vec3.begin(); iter2 != vec3.end(); iter2++)
         cout << *iter2 << " ";
     cout<<"\n\n";

     cout << "OPERACIONES DE COMPARAION ENTRE VECTORES" << endl << endl;

     if( vec1 != vec2 )
        cout << "vec1 no es igual a vec2 " << endl;
     else
        cout << "vec1 es igual a vec2 " << endl;

     if( vec1 == vec3 )
        cout << "vec1 es igual a vec3" << endl;
     else
        cout << "vec1 no es igual a vec3 "<< endl;

     if( vec1 < vec2 )
        cout << "vec1 es menor que vec2 " << endl;
     else
        cout << "vec1 no es menor que vec2" << endl;

     if( vec2 > vec1 )
        cout << "vec2 es mayor que vec1" << endl;
     else
        cout << "vec2 no es mayor que vec1 "<< endl;

     if( vec2 >= vec1 )
        cout << "vec2 es mayor o igual que vec1" << endl;
     else
        cout << "vec2 no es mayor o igual que vec1 " << endl;
      
     if( vec1 <= vec2 )
        cout << "vec1 es menor o igual que vec2 " << endl;
     else
        cout << "vec1 no es menor o igual que vec2" << endl;

     if( vec1 > vec2 )
        cout << "vec1 es mayor que vec2 " << endl;
     else
        cout << "vec1  es menor o igual que vec2" << endl;



     return 0;
}
*/

/*Al igual que el código anterior, este script fue escrito originalmente para el compilador Borland C++ 5.5 (bcc32), un entorno antiguo de finales de los años 90.
Para que funcione correctamente en cualquier compilador moderno sin fallar al leer los datos de forma consecutiva, presenta dos problemas críticos: el uso de la cabecera obsoleta <conio> y el método incorrecto de limpiar el flujo de entrada de datos (cin.clear() y cin.ignore()), el cual dejará basura en el búfer si el usuario presiona Ctrl+Z o Ctrl+D.

🔴 Los Errores en tu Segundo Código

1. La cabecera <conio>: No se está utilizando ninguna función de esta librería (como getch()), por lo que incluirla genera un error innecesario en compiladores modernos.
2. system("cls"): Aunque funciona en Windows, no es multiplataforma (falla en Linux/macOS) y consume muchos recursos.
3. cin.ignore(4) incorrecto: Al finalizar una secuencia con Ctrl+Z/Ctrl+D, el estado de error de cin se activa. Usar un valor fijo como 4 en el ignore no garantiza limpiar el búfer si el usuario presionó la tecla Enter o caracteres adicionales. La forma estándar es ignorar hasta encontrar el salto de línea \n.

🟢 Código Corregido, Seguro y Modernizado

Este código reemplaza la limpieza de pantalla por una secuencia ANSI estándar, corrige la lógica de entrada para que puedas llenar los tres vectores consecutivamente sin errores, y mantiene intactas todas tus operaciones de comparación de vectores:*/


#include <vector>
#include <iostream>
#include <limits> // Necesario para limpiar cin de forma robusta

using namespace std;

// Función auxiliar estándar para limpiar el flujo "cin" después de un fin de archivo (Ctrl+Z o Ctrl+D)
void limpiarEntrada() {
    cin.clear(); // Restablece el estado de cin (quita el estado de error/EOF)
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta todo el búfer restante hasta el salto de línea
}

int main(void) {
    // Reemplazo multiplataforma para limpiar la pantalla (Secuencia ANSI)
    cout << "\033[2J\033[1;1H";

    vector<float> vec1, vec2, vec3;   
    vector<float>::iterator iter1, iter2; 
    float real;

    // --- Llenado de vec1 ---
    cout << "ENTRE VALORES REALES PARA VEC1. PARA TERMINAR (Ctrl+Z en Win o Ctrl+D en Linux + Enter):" << endl << endl;
    while (cin >> real) {
        vec1.push_back(real); 
    }
    limpiarEntrada(); // Limpieza indispensable para poder volver a usar cin
  
    // --- Llenado de vec2 ---
    cout << endl << "ENTRE VALORES REALES PARA VEC2. PARA TERMINAR (Ctrl+Z o Ctrl+D + Enter):" << endl << endl;
    while (cin >> real) {
        vec2.push_back(real); 
    }
    limpiarEntrada();
  
    // --- Llenado de vec3 ---
    cout << endl << "ENTRE VALORES REALES PARA VEC3. PARA TERMINAR (Ctrl+Z o Ctrl+D + Enter):" << endl << endl;
    while (cin >> real) {
        vec3.push_back(real); 
    }
     
    // Limpiar pantalla antes de mostrar resultados
    cout << "\033[2J\033[1;1H"; 

    // Imprimir vec1 (Usando iterador manual con while)
    cout << "Data en el vector vec1 es: " << endl;
    iter1 = vec1.begin(); 
    while (iter1 != vec1.end()) { 
       cout << *iter1 << "  "; 
       iter1++; 
    }

    // Imprimir vec2 (Usando iterador manual con while)
    cout << endl << endl << "Data en el vector vec2 es: " << endl;
    iter1 = vec2.begin(); 
    while (iter1 != vec2.end()) { 
       cout << *iter1 << "  "; 
       iter1++; 
    }

    // Imprimir vec3 (Usando iterador en ciclo for)
    cout << endl << endl << "Data en el vector vec3: " << endl;
    for (iter2 = vec3.begin(); iter2 != vec3.end(); iter2++) {
         cout << *iter2 << " ";
    }
    cout << "\n\n";

    // --- OPERACIONES DE COMPARACIÓN ---
    cout << "OPERACIONES DE COMPARACION ENTRE VECTORES" << endl << endl;

    if (vec1 != vec2)
        cout << "vec1 no es igual a vec2 " << endl;
    else
        cout << "vec1 es igual a vec2 " << endl;

    if (vec1 == vec3)
        cout << "vec1 es igual a vec3" << endl;
    else
        cout << "vec1 no es igual a vec3 " << endl;

    if (vec1 < vec2)
        cout << "vec1 es menor que vec2 " << endl;
    else
        cout << "vec1 no es menor que vec2" << endl;

    if (vec2 > vec1)
        cout << "vec2 es mayor que vec1" << endl;
    else
        cout << "vec2 no es mayor que vec1 " << endl;

    if (vec2 >= vec1)
        cout << "vec2 es mayor o igual que vec1" << endl;
    else
        cout << "vec2 no es mayor o igual que vec1 " << endl;
      
    if (vec1 <= vec2)
        cout << "vec1 es menor o igual que vec2 " << endl;
    else
        cout << "vec1 no es menor o igual que vec2" << endl;

    if (vec1 > vec2)
        cout << "vec1 es mayor que vec2 " << endl;
    else
        cout << "vec1 es menor o igual que vec2" << endl;

    return 0;
}

/*
 ¿Por qué es importante el cambio en limpiarEntrada()?

Cuando ingresas datos en una lista mediante while(cin >> real), el ciclo solo se rompe cuando ocurre un error (por ejemplo, si envías el comando de fin de archivo Ctrl+Z / Ctrl+D o escribes una letra).
Si no se limpia el flujo con cin.clear() e ignoras todo el resto de la línea con numeric_limits, los siguientes bloques while leerán el error remanente de inmediato y saltarán directamente al final del programa sin dejarte escribir datos en vec2 o vec3.*/

