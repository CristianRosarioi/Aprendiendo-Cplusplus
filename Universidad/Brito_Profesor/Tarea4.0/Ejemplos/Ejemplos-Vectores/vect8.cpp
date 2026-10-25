/*  
    vect8.cpp
    Compilador: bcc32 5.5

  C++ / FERREIRAS/  <vector>

  Uso de: capacity(), clear(),   empty,  pop_back(), size(), swap(),
   
  Para ello, dinamicamente se capturar� data en un vector (La captura terminara
  con <Ctrl>+Z+<ENTER>) y se manipular� dicho vector usando  los recursos 
  indicados.  
   
 */

/*#include <vector>
#include <iostream>
#include <conio>

using namespace std;

int main(void){

     vector<float> v1, v2, v3;   
     vector<float>::iterator iter1, iter2, iter3; 
     float real;
 
     system("cls");

    // v1
     cout << endl << "ENTRE VALORES REALES. PARA TERMINAR CTRL+Z DOS VECES:" 
          << endl << endl;
     while( cin >> real) {
         v1.push_back(real); 
     }
  
    cout << endl << endl << "Data en el vector v1 es: " << endl;
    iter1 = v1.begin(); 
    while( iter1 != v1.end() ){ 
       cout << *iter1 << "  "; 
       iter1++; 
    }

    // v2
  
    cin.ignore(4);  
    cin.clear();
    cout << endl << "ENTRE VALORES REALES. PARA TERMINAR CTRL+Z DOS VECES:" 
         << endl << endl;
     while( cin >> real) {
         v2.push_back(real); 
     }
  
    cout << endl << endl << "Data en el vector v2 es: " << endl;
    iter1 = v2.begin(); 
    while( iter1 != v2.end() ){ 
       cout << *iter1 << "  "; 
       iter1++; 
    }
  
   // capacity(), clear(),   empty,  pop_back(), size(), swap()
     
     cout << "\nLa capacity del vector v1 es: " << v1.capacity() << endl;
     cout << "    El size del vector v1 es: " << v1.size() << endl;
     v1.clear();
     cout << "vector v1 despue de clear() : " << endl;
     cout << "La capacity del vector v1 es: " << v1.capacity() << endl;
     cout << "    El size del vector v1 es: " << v1.size() << endl;
     if( v1.empty() == true ) // true if the vector size is 0, false otherwise
        cout << "Es que esta vacio de verdad, zoqueta !!" << endl; 
     cout << "El ultimo elemento en v2 es : " << v2.back() << endl;
     v2.pop_back();
     cout << "Despues de  pop_back(), El ultimo elemento en v2 es : "<< v2.back() << endl;
     
     cin.ignore(4);  
     cin.clear();
     cout << endl << "ENTRE VALORES REALES. PARA TERMINAR CTRL+Z DOS VECES: "
          << endl << endl;
     while( cin >> real) {
         v3.push_back(real); //
     }
         
     cout << endl << "Data en el vector v3: " << endl;
     for(iter2 = v3.begin(); iter2 != v3.end(); iter2++)
         cout << *iter2 << " ";
     cout<<"\n\n";
   
     // swap()

     v2.swap(v3);

     cout << "\n\nDATOS EN LOS VECTORES DESPUES DEL swap:\n\n";    
     cout << endl << "Data en el vector v2: "  << endl;
     for(iter3 = v2.begin(); iter3 != v2.end(); iter3++)
        cout << *iter3 << " ";
   
     cout << endl << "Data en el vector v3: " << endl;
     for(iter2 = v3.begin(); iter2 != v3.end(); iter2++)
         cout << *iter2 << " ";
     cout<<"\n\n";

  return 0;
}
*/

/*Este es el archivo vect8.cpp del profesor Ferreiras, el cual contiene exactamente las funciones que hacían falta por revisar: .capacity(), .clear(), .empty(), .pop_back() y .swap().
Además de los problemas con <conio>, system("cls") y la limpieza ineficiente del flujo cin, este código presenta un riesgo crítico de fallo de segmentación (crash) en la línea cout << "El ultimo elemento en v2 es : " << v2.back() << endl;. Si el usuario decide terminar la entrada de datos de v2 de inmediato sin ingresar ningún número, intentar leer .back() o aplicar .pop_back() sobre un vector vacío romperá el programa instantáneamente.

🟢 Código Corregido, Seguro y Modernizado

Aquí tienes la versión completamente corregida. Se añadieron estructuras condicionales de seguridad (if) para validar que v2 tenga elementos antes de inspeccionar o eliminar su último valor, y se unificó la lectura consecutiva de datos de forma estándar:*/

#include <vector>
#include <iostream>
#include <limits> // Necesario para limpiar cin con seguridad

using namespace std;

// Función estándar para limpiar el flujo de entrada tras usar Ctrl+Z o Ctrl+D
void limpiarEntrada() {
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

int main(void) {
    // Reemplazo multiplataforma y estándar para limpiar la pantalla
    cout << "\033[2J\033[1;1H";

    vector<float> v1, v2, v3;   
    vector<float>::iterator iter1, iter2, iter3; 
    float real;
 
    // --- Llenado de v1 ---
    cout << "ENTRE VALORES REALES PARA V1. PARA TERMINAR (Ctrl+Z en Windows o Ctrl+D en Linux + Enter):" 
         << endl << endl;
    while (cin >> real) {
        v1.push_back(real); 
    }
    limpiarEntrada();
  
    cout << endl << "Data en el vector v1 es: " << endl;
    iter1 = v1.begin(); 
    while (iter1 != v1.end()) { 
       cout << *iter1 << "  "; 
       iter1++; 
    }
    cout << endl;

    // --- Llenado de v2 ---
    cout << endl << "ENTRE VALORES REALES PARA VEC2. PARA TERMINAR (Ctrl+Z o Ctrl+D + Enter):" 
         << endl << endl;
    while (cin >> real) {
         v2.push_back(real); 
    }
    limpiarEntrada();
  
    cout << endl << "Data en el vector v2 es: " << endl;
    iter1 = v2.begin(); 
    while (iter1 != v2.end()) { 
       cout << *iter1 << "  "; 
       iter1++; 
    }
    cout << endl;
  
    // --- DEMOSTRACIÓN DE: capacity(), clear(), empty, pop_back(), size() ---
     
    cout << "\nLa capacity del vector v1 es: " << v1.capacity() << endl;
    cout << "    El size del vector v1 es: " << v1.size() << endl;
     
    v1.clear(); // Elimina todos los elementos de v1
    cout << "\n--- vector v1 despues de clear() ---" << endl;
    cout << "La capacity del vector v1 es: " << v1.capacity() << endl;
    cout << "    El size del vector v1 es: " << v1.size() << endl;
     
    if (v1.empty()) { // Equivalente a v1.empty() == true
        cout << "Es que esta vacio de verdad, zoqueta !!" << endl; 
    }
     
    // CONTROL DE SEGURIDAD: Evita un crash si v2 se encuentra vacío
    cout << endl << "--- Manipulando el final de v2 ---" << endl;
    if (!v2.empty()) {
        cout << "El ultimo elemento en v2 es : " << v2.back() << endl;
        v2.pop_back(); // Elimina el último elemento
        
        if (!v2.empty()) {
            cout << "Despues de pop_back(), El nuevo ultimo elemento en v2 es : " << v2.back() << endl;
        } else {
            cout << "Despues de pop_back(), el vector v2 ha quedado completamente vacio." << endl;
        }
    } else {
        cout << "[Aviso]: v2 esta vacio. No se puede usar back() ni pop_back()." << endl;
    }
     
    // --- Llenado de v3 ---
    cout << endl << "ENTRE VALORES REALES PARA V3. PARA TERMINAR (Ctrl+Z o Ctrl+D + Enter): "
         << endl << endl;
    while (cin >> real) {
         v3.push_back(real); 
    }
    limpiarEntrada();
         
    cout << endl << "Data en el vector v3: " << endl;
    for (iter2 = v3.begin(); iter2 != v3.end(); iter2++) {
         cout << *iter2 << " ";
    }
    cout << "\n\n";
   
    // --- DEMOSTRACIÓN DE: swap() ---
    v2.swap(v3); // Intercambia de forma eficiente los contenidos de v2 y v3

    cout << "DATOS EN LOS VECTORES DESPUES DEL swap:\n";    
    cout << "Data en el vector v2: "  << endl;
    for (iter3 = v2.begin(); iter3 != v2.end(); iter3++) {
        cout << *iter3 << " ";
    }
   
    cout << endl << "Data en el vector v3: " << endl;
    for (iter2 = v3.begin(); iter2 != v3.end(); iter2++) {
         cout << *iter2 << " ";
    }
    cout << "\n\n";

    return 0;
}

/*
💡 Comportamiento de la Memoria en C++:

• v1.clear(): Borra los elementos reduciendo el size() a 0, pero conserva la capacity() original intacta. Esto ocurre porque C++ mantiene la memoria interna reservada por si necesitas volver a rellenar el vector más adelante, evitando el costo de hacer nuevas asignaciones de sistema.
• v2.swap(v3): Es una operación sumamente rápida de complejidad constante O(1). En lugar de copiar físicamente elemento por elemento de un arreglo a otro en memoria, lo único que hace internamente C++ es intercambiar los punteros internos de inicio, fin y capacidad de ambos vectores.
Con esta entrega completamos prácticamente toda la caja de herramientas de la estructura <vector> de tus guías de estudio. ¿Tienes algún otro archivo como vect2.cpp, vect3.cpp o vect5.cpp*/

