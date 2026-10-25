/*   vect3.cpp
      Compilador: bcc32 5.5

  C++ / FERREIRAS/ <vector>

  Uso de:   insert()
   
  Para ello, dinamicamente se capturar� en una variable vector valores reales
  (La captura terminara con <Ctrl>+Z+<ENTER>) y se manipular� dicho vector 
  usando  los recursos indicados.  
  
*/

/*
#include <vector>
#include <iostream>
#include <conio>

using namespace std;

int main(void){

  clrscr();
  vector<float> v1;   
  vector<float>::iterator iter1, iter2, iter3; 
  float real;
 
  cout << endl << "ENTRE VALORES REALES. PARA TERMINAR CTRL+Z DOS VECES:" 
       << endl << endl;
  while( cin >> real) {
     v1.push_back(real); //
  }
  
 // Accesando el vector usando el iterator

 cout << endl << endl << "El contenido actual del vector es: ";
 iter1 = v1.begin(); // begin() retorna un puntero al primer elemento
 while( iter1 != v1.end() ){// end() retorna puntero a la posici�n (ultimo_elemento + 1) 
   cout << *iter1 << "  "; // el iterator puede ser "desreferenciado"
   iter1++; // el iterator puede ser incrementado
 }

  // insert()   
 
  iter2 =v1.begin();
  iter2 = iter2 + 2; // Apunta al tercer elemento de v1
  v1.insert(iter2, 123.456); // inserta 123.456 en la tercera posicion desplazando 

  cout << endl << endl << "El contenido actual del vector es: ";
  iter1 = v1.begin(); // begin() retorna un puntero al primer elemento
  while( iter1 != v1.end() ){// end() retorna puntero a la posici�n (ultimo_elemento + 1) 
    cout << *iter1 << "  "; // el iterator puede ser "desreferenciado"
    iter1++; // el iterator puede ser incrementado
  }

  return 0;
}
*/ 

/*El código de C++ que presentas tiene tres errores principales que impedirán que compile en entornos modernos: el uso de la biblioteca obsoleta e incorrecta <conio>, la falta de la extensión .h en caso de que se use (aunque no se debe usar), y un error crítico de invalidación de iteradores tras la inserción (v1.insert).
Aquí tienes la explicación detallada de los problemas y la versión corregida.

🔴 Los Errores en tu Código

1. <conio> y clrscr(): La librería <conio.h> no es estándar y clrscr() pertenece a los antiguos compiladores de Borland (Turbo C++). En compiladores modernos (GCC, Clang, MSVC) esto causará un error de compilación.
2. Falta de verificación del tamaño antes de iter2 + 2: Si el usuario introduce menos de dos elementos, la línea iter2 = iter2 + 2; intentará apuntar más allá de v1.end(), provocando un comportamiento indefinido (undefined behavior) o una caída del programa.
3. Invalidación de Iteradores (Error Lógico Grave): Al hacer v1.insert(iter2, 123.456);, el vector se reasigna en memoria si supera su capacidad. Esto hace que todos los iteradores existentes (iter1, iter2, iter3) queden completamente invalidados. Aunque luego reasignas iter1 = v1.begin();, es una excelente práctica capturar el nuevo iterador válido que retorna .insert().*/

// El codigo de arriba es el que dio el profesor pero no compila en C++14, por lo que se ha modificado para que compile y funcione correctamente.

#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    // Reemplazo estándar y multiplataforma para "limpiar" la pantalla mediante secuencias de escape ANSI
    cout << "\033[2J\033[1;1H"; 
    
    vector<float> v1;
    vector<float>::iterator iter1, iter2;
    float real;

    cout << endl << "ENTRE VALORES REALES. PARA TERMINAR (Presione Ctrl+Z en Windows o Ctrl+D en Linux/Mac + Enter):" 
         << endl << endl;
         
    while (cin >> real) {
        v1.push_back(real);
    }

    // Mostrando el contenido inicial del vector
    cout << endl << endl << "El contenido actual del vector es: ";
    iter1 = v1.begin();
    while (iter1 != v1.end()) {
        cout << *iter1 << "  ";
        iter1++;
    }

    // INSERCIÓN SEGURA: Verificamos que el vector tenga al menos 2 elementos para avanzar el iterador
    iter2 = v1.begin();
    if (v1.size() >= 2) {
        iter2 = iter2 + 2; // Apunta a la tercera posición de v1
    } else {
        iter2 = v1.end();  // Si hay menos de 2, inserta al final
    }

    // Al insertar, el método retorna un NUEVO iterador válido apuntando al elemento insertado
    iter2 = v1.insert(iter2, 123.456f);

    // Mostrando el contenido después de la inserción
    cout << endl << endl << "El contenido actual del vector es (despues de insertar 123.456): ";
    iter1 = v1.begin(); // Se vuelve a inicializar de forma segura
    while (iter1 != v1.end()) {
        cout << *iter1 << "  ";
        iter1++;
    }

    cout << endl;
    return 0;
}


/*
Cambios Clave:

• Limpieza de pantalla: Se eliminó <conio> y se usó "\033[2J\033[1;1H", que limpia la terminal de forma nativa en sistemas modernos.
• Control de flujo: Se añadió un if (v1.size() >= 2) para evitar que el programa falle si introduces solo 0 o 1 número.
• Fin de datos: En sistemas modernos, terminar la consola (cin) suele requerir un solo Ctrl+Z (Windows) o Ctrl+D (Unix) seguido de la tecla Enter.*/

