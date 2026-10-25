/*  vect6.cpp
    Compilador: bcc32 5.5

  C++ / FERREIRAS/ <vector>

  Uso de:  erase()
   
  Para ello, dinamicamente se capturar� en una variable vector valores reales
  (La captura terminara con <Ctrl>+Z+<ENTER>) y se manipular� dicho vector 
  usando  los recursos indicados.  

    assign(),  clear(),   empty,  pop_back(), size(), swap(),

 */

/*#include <vector>
#include <iostream>
#include <conio>

using namespace std;

int main(void){

  clrscr();
  cout << endl << endl;
  vector<float> v1; //crea el objeto vector v1 de flotantes, vacio  
  vector<float>::iterator iter1, iter2, iter3; // Crea objetos iterator
  float real;
 
  cout << endl << "ENTRE VALORES REALES. PARA TERMINAR CTRL+Z DOS VECES:"
       << endl << endl;
  while( cin >> real) {
     v1.push_back(real); //
  }
  
 // Accesando el vector usando el iterator

 cout << endl << endl << "El contenido actual del vector es: " << endl;
 iter1 = v1.begin(); // begin() retorna un puntero al primer elemento
 while( iter1 != v1.end() ){// end() retorna puntero a la posici�n (ultimo_elemento + 1) 
   cout << *iter1 << "  "; // el iterator puede ser "desreferenciado"
   iter1++; // el iterator puede ser incrementado
 }

  iter2 =v1.begin();
  iter2 = iter2 + 2; // Apunta al tercer elemento de v1
  v1.erase(iter2, iter2 + 3); // Borra 3 elementos a partir del 3er., inclusive 

  cout << endl << endl << "El contenido actual del vector es: " << endl;
  iter1 = v1.begin(); // begin() retorna un puntero al primer elemento
  while( iter1 != v1.end() ){// end() retorna puntero a la posici�n (ultimo_elemento + 1) 
    cout << *iter1 << "  "; // el iterator puede ser "desreferenciado"
    iter1++; // el iterator puede ser incrementado
  }

 return 0;
}
 */

 /*ste quinto ejemplo del profesor Ferreiras introduce el método .erase(), pero contiene un riesgo crítico de corrupción de memoria y crash instantáneo en entornos modernos.
Al ejecutar la línea v1.erase(iter2, iter2 + 3);, el programa asume ciegamente que el usuario ingresó por lo menos 5 elementos. Si introduces menos, iter2 + 3 apuntará a una dirección de memoria fuera de los límites del vector (v1.end()), provocando un comportamiento indefinido (undefined behavior). Además, arrastra los mismos problemas de compatibilidad debido a <conio> y clrscr().

🟢 Código Corregido, Seguro y Modernizado

Esta versión utiliza secuencias de escape ANSI estándar para limpiar la pantalla y añade controles de flujo estrictos (if/else) que verifican el tamaño dinámico del vector antes de realizar cualquier operación de borrado por rango:*/

#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    // Reemplazo estándar multiplataforma para limpiar la pantalla
    cout << "\033[2J\033[1;1H";
    cout << endl << endl;

    vector<float> v1; // Crea el objeto vector v1 de flotantes, vacío  
    vector<float>::iterator iter1, iter2; // Crea objetos iterator
    float real;
 
    cout << "ENTRE VALORES REALES. PARA TERMINAR (Ctrl+Z en Windows o Ctrl+D en Linux/Mac + Enter):" 
         << endl << endl;
    while (cin >> real) {
        v1.push_back(real); 
    }
  
    // Accediendo al vector usando el iterador
    cout << endl << endl << "El contenido actual del vector es: " << endl;
    iter1 = v1.begin(); 
    while (iter1 != v1.end()) { 
        cout << *iter1 << "  "; 
        iter1++; 
    }

    // --- BORRADO SEGURO POR RANGO ---
    // Verificamos que el vector tenga al menos 3 elementos para poder iniciar el borrado en el 3er elemento (índice 2)
    if (v1.size() >= 3) {
        iter2 = v1.begin() + 2; // Apunta al tercer elemento con seguridad
        
        // Calculamos de forma dinámica el límite superior para no sobrepasar v1.end()
        vector<float>::iterator iter_limite;
        if (v1.size() >= 5) {
            iter_limite = iter2 + 3; // Si hay suficientes elementos, borra exactamente 3 elementos
        } else {
            iter_limite = v1.end();  // Si hay menos de 5, borra de forma segura desde el 3ro hasta el final
        }

        // Borra los elementos en el rango [iter2, iter_limite) - El límite superior es exclusivo
        v1.erase(iter2, iter_limite); 
        cout << endl << endl << "--- Elementos borrados con exito ---";
    } else {
        cout << endl << endl << "[Aviso]: El vector es demasiado corto (menos de 3 elementos). No se realizo el borrado.";
    }

    // Imprimir el contenido final del vector
    cout << endl << endl << "El contenido actual del vector es: " << endl;
    iter1 = v1.begin(); // Se reinicializa obligatoriamente porque .erase() invalida los iteradores previos
    while (iter1 != v1.end()) { 
        cout << *iter1 << "  "; 
        iter1++; 
    }

    cout << endl;
    return 0;
}


/*
💡 Análisis del comportamiento de .erase():

• Uso por Rango (v1.erase(inicio, fin)): Borra todos los elementos comprendidos en el intervalo. Es fundamental recordar que el iterador de fin es excluyente (abierto por la derecha). Por lo tanto, v1.erase(v1.begin() + 2, v1.begin() + 5) eliminará exactamente los índices 2, 3 y 4.
• Invalidación Crítica de Iteradores: Al igual que ocurre con .insert(), al remover elementos con .erase(), la memoria del contenedor se reestructura y todos los iteradores que apuntaban a posiciones posteriores al borrado quedan completamente destruidos. Intentar reutilizar iter1 o iter2 sin antes volver a igualarlos a v1.begin() rompería el programa en ejecución.
Con este archivo cerramos la revisión de las operaciones básicas con iteradores (insert, assign, erase). */

