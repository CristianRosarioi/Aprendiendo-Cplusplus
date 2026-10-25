/* vect4.cpp
    Compilador: bcc32 5.5

  C++ / FERREIRAS/ <vector>

  Uso de:   insert()
   
  Para ello, dinamicamente se capturar� en una variable o vector valores reales
  (La captura terminara con <Ctrl>+Z+<ENTER>) y se manipular� dicho vector 
  usando  los recursos indicados.  



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
  v1.insert(iter2, 5, 123.456); // inserta 5 copias de 123.456 a partir de la tercera 
                                // posicion desplazando 

  cout << endl << endl << "El contenido actual del vector es: " << endl;
  iter1 = v1.begin(); // begin() retorna un puntero al primer elemento
  while( iter1 != v1.end() ){// end() retorna puntero a la posici�n (ultimo_elemento + 1) 
    cout << *iter1 << "  "; // el iterator puede ser "desreferenciado"
    iter1++; // el iterator puede ser incrementado
  }

  cout << endl << endl;
  system("PAUSE");
  return 0;
}
*/

/*Este cuarto ejemplo del profesor Ferreiras muestra una variante avanzada de .insert() que permite inyectar múltiples copias de un mismo valor en una posición específica de un vector.
Al igual que en los casos anteriores, el código asume que el usuario introducirá suficientes datos. Si el usuario escribe menos de dos números, la instrucción iter2 = iter2 + 2; apuntará a una zona de memoria inválida, provocando un error de segmentación (crash) en compiladores modernos. Además, incluye dependencias obsoletas como <conio> y clrscr().

🟢 Código Corregido, Seguro y Modernizado

Esta versión elimina las librerías obsoletas, implementa la limpieza de pantalla mediante secuencias ANSI estándar y añade un bloque condicional de seguridad (if/else) para asegurar que la inserción múltiple ocurra únicamente en posiciones válidas del vector:*/

#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    // Reemplazo multiplataforma y estándar para limpiar la pantalla
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
    iter1 = v1.begin(); // begin() retorna un iterador al primer elemento
    while (iter1 != v1.end()) { // end() retorna un iterador a la posición (último_elemento + 1) 
        cout << *iter1 << "  "; // El iterador es desreferenciado con '*'
        iter1++; // El iterador es incrementado
    }

    // --- INSERCIÓN MÚLTIPLE SEGURA ---
    iter2 = v1.begin();
    if (v1.size() >= 2) {
        iter2 = iter2 + 2; // Apunta con seguridad al tercer elemento (índice 2)
    } else {
        iter2 = v1.end();  // Si hay menos de 2 elementos, se insertarán al final
    }

    // Inserta 5 copias del valor 123.456 a partir de la posición apuntada por iter2
    v1.insert(iter2, 5, 123.456f); 

    // Imprimir el contenido final del vector
    cout << endl << endl << "El contenido actual del vector es (luego de insertar 5 copias de 123.456): " << endl;
    iter1 = v1.begin(); // Se vuelve a inicializar debido a la invalidación de iteradores tras modificar el tamaño
    while (iter1 != v1.end()) {
        cout << *iter1 << "  "; 
        iter1++; 
    }

    cout << endl << endl;
    
    // Reemplazo de system("PAUSE") para que sea multiplataforma y estándar
    cout << "Presione ENTER para terminar . . .";
    cin.clear(); // Limpia cualquier bandera de error del ciclo while anterior
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta caracteres residuales
    cin.get(); // Espera una pulsación de tecla Enter

    return 0;
}

/*
💡 Análisis de los cambios implementados:

• v1.insert(posición, cantidad, valor): Esta sobrecarga toma tres argumentos. Desplaza todos los elementos existentes hacia la derecha para hacer espacio exacto a las copias solicitadas (en este caso, 5 bloques seguidos con 123.456).
• Invalidación de iteradores: Cada vez que usas .insert(), el vector puede cambiar de tamaño y reubicarse en otra dirección de memoria. Por ello, el valor que tenía iter1 antes de la inserción queda obsoleto y es estrictamente necesario volver a escribir iter1 = v1.begin(); antes del segundo ciclo while.
• Reemplazo de system("PAUSE"): El uso de llamadas al sistema operativo consume recursos innecesarios y ata tu código exclusivamente a consolas Windows de Microsoft. El uso combinado de cin.clear() junto a cin.get() logra exactamente el mismo efecto de pausa de forma portátil y nativa en C++.*/

