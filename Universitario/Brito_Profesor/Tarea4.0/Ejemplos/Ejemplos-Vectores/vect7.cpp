/*  vect7.cpp
    Compilador: bcc32 5.5

  C++/ FERREIRAS/ <vector>

  Uso de:   assign(),  capacity(), clear(),   empty,  pop_back(), size(), swap(),
   
  Para ello, dinamicamente se capturar� data en un vector (La captura terminara
  con <Ctrl>+Z+<ENTER>) y se manipular� dicho vector usando  los recursos 
  indicados.  
   
 */

/*#include <vector>
#include <iostream>
#include <conio>

using namespace std;

int main(void){

     vector<float> v1, v2;   
     vector<float>::iterator iter1, iter2, iter3; 
     float real;
 
     clrscr();

    // v1
     cout << endl << "ENTRE VALORES REALES. PARA TERMINAR CTRL+Z DOS VECES:" 
          << endl << endl;
     while( cin >> real) {
         v1.push_back(real); //
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
    cout << endl << "ENTRE VALORES REALES. PARA TERMINAR ENTRE CTRL+Z:" << endl << endl;
     while( cin >> real) {
         v2.push_back(real); //
     }
  
    cout << endl << endl << "Data en el vector v2 es: " << endl;
    iter1 = v2.begin(); 
    while( iter1 != v2.end() ){ 
       cout << *iter1 << "  "; 
       iter1++; 
    }
  
   // assign()
   
     v1.assign(v1.begin()+1, v1.begin() + 4);
     cout << endl << "Data en el vector v1: " << endl;
     for(iter2 = v1.begin(); iter2 != v1.end(); iter2++)
         cout << *iter2 << " ";
    cout<<"\n\n";
   
    v2.assign(5, 7);
    cout << endl << "Data en el vector v2: "  << endl;
    for(iter3 = v2.begin(); iter3 != v2.end(); iter3++)
        cout << *iter3 << " ";

  return 0;
}*/

/*Este tercer ejemplo del profesor Ferreiras para Borland C++ 5.5 introduce métodos muy importantes como .assign(), pero añade un riesgo crítico de caída del programa (segmentation fault) debido a que asume que el usuario siempre ingresará una cantidad fija de datos.
Si el usuario introduce menos de 4 elementos en v1, la línea v1.assign(v1.begin()+1, v1.begin() + 4); intentará acceder a memoria no reservada, rompiendo el programa de inmediato de forma indefinida.

🔴 Los Problemas de este Tercer Código

1. Desbordamiento de Rango con .assign(): Intentar hacer v1.begin() + 4 sin validar que v1.size() >= 4 es sumamente peligroso.
2. Los mismos fallos heredados de Borland: Uso de <conio>, clrscr(), y el método ineficiente de limpiar el búfer (cin.ignore(4)), que impedirá capturar correctamente el segundo vector en plataformas modernas.

🟢 Código Corregido, Seguro y Modernizado

Este diseño corrige la entrada de datos consecutiva mediante la biblioteca <limits>, implementa la secuencia de escape ANSI para limpiar la pantalla y protege el programa con una estructura condicional (if) que verifica el tamaño del vector antes de realizar la segmentación con .assign().*/

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
    // Reemplazo estándar multiplataforma para limpiar la pantalla
    cout << "\033[2J\033[1;1H";

    vector<float> v1, v2;   
    vector<float>::iterator iter1, iter2, iter3; 
    float real;
 
    // --- Llenado de v1 ---
    cout << "ENTRE VALORES REALES PARA V1. PARA TERMINAR (Ctrl+Z en Windows o Ctrl+D en Linux + Enter):" 
         << endl << endl;
    while (cin >> real) {
        v1.push_back(real); 
    }
  
    cout << endl << "Data en el vector v1 es: " << endl;
    iter1 = v1.begin(); 
    while (iter1 != v1.end()) { 
       cout << *iter1 << "  "; 
       iter1++; 
    }
    cout << endl;

    // --- Llenado de v2 ---
    limpiarEntrada(); // Limpieza del flujo heredado del primer ciclo
    cout << endl << "ENTRE VALORES REALES PARA V2. PARA TERMINAR (Ctrl+Z o Ctrl+D + Enter):" << endl << endl;
    while (cin >> real) {
         v2.push_back(real); 
    }
  
    cout << endl << "Data en el vector v2 es: " << endl;
    iter1 = v2.begin(); 
    while (iter1 != v2.end()) { 
       cout << *iter1 << "  "; 
       iter1++; 
    }
    cout << endl;
  
    // --- USO DE assign() ---
   
    // CONTROL DE SEGURIDAD: Evita un volcado de memoria si v1 tiene menos de 4 elementos
    cout << endl << "--- Aplicando v1.assign() ---" << endl;
    if (v1.size() >= 4) {
        // Reemplaza el contenido de v1 por el rango desde el índice 1 hasta el 3 (el límite superior es exclusivo)
        v1.assign(v1.begin() + 1, v1.begin() + 4);
        cout << "Data en el vector v1 (sub-rango copiado): " << endl;
        for (iter2 = v1.begin(); iter2 != v1.end(); iter2++) {
            cout << *iter2 << " ";
        }
    } else {
        cout << "[Aviso]: v1 tiene menos de 4 elementos. No se pudo extraer el rango de forma segura." << endl;
    }
    cout << "\n\n";
   
    // Asigna al vector v2 exactamente 5 elementos, todos inicializados con el valor 7
    v2.assign(5, 7);
    cout << "Data en el vector v2 (asignacion explicita de 5 sietes): " << endl;
    for (iter3 = v2.begin(); iter3 != v2.end(); iter3++) {
        cout << *iter3 << " ";
    }
    cout << endl;

    return 0;
}

/*
💡 Análisis del método .assign():

• Por rango (v1.assign(inicio, fin)): Borra por completo el contenido previo del vector y le asigna los elementos que se encuentren en el intervalo especificado. Recuerda que el iterador final (v1.begin() + 4) es excluyente, por lo que toma las posiciones 1, 2 y 3.
• Por repetición (v2.assign(cantidad, valor)): Es una forma rápida de formatear un vector. En este caso, destruye todo lo que el usuario digitó en v2 y lo rellena con 7 7 7 7 7.
El encabezado del programa menciona que también se van a utilizar métodos como capacity(), clear(), empty(), pop_back(), size() y swap(), pero no se implementaron en el código original.*/

