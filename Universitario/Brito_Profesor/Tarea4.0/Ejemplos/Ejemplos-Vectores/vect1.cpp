/*
   vect1.cpp
   Compilador: bcc32 5.5

  C++ / FERREIRAS/  <vector>

  Uso de:  at(),  back(),  front(), max_size(), push_back(), size()

  Para ello, dinamicamente se capturar� en una variable vector valores reales
  (La captura terminara con <Ctrl>+Z+<ENTER>) y se manipular� dicho vector 
  los recursos indicados. 
 

*/

/*#include <vector>
#include <iostream>
#include <conio>

using namespace std;

int main(void){

  clrscr();
  cout << endl << endl;

  vector<float> v1;  
  float real;
 
 // max_size()

  cout << "La cantidad maxima de elementos que este vector puede almacenar es:\n "
          <<  v1.max_size() << " Elementos de tipo float, !! Ei diablo !!"
          << endl  << "\nCARGA DE ELEMENTOS EN EL ARREGLO\n"
          << "ENTRE VALORES REALES. PARA TERMINAR CTRL+Z DOS VECES:\n" << endl;
  while( cin >> real) {
     v1.push_back(real);
  }

// size()
 
  cout << endl << "La cantidad actual de elementos en el vector es: "
          << v1.size()  << "\nLos cuales son: " << endl << endl;

  // at(),  back(),  front()

  //  at(i)  Retorna el elemento indice i
  // back()  Retorna el ultimo elemento en el vector 
  // front() Retorna el primer elemento en el vector

  unsigned int j(0);
  while( j < v1.size() ){ 
    cout << v1.at(j) << ",  ";
    j++;
  }
  
  if( !v1.empty() )
      cout << endl << endl << "El elemento (i= 0, n = 1) es at(0) = " << v1.at(0) 
           << endl << endl << "El primer elemento en el vector es: " << v1.front()
           << endl << endl << "El ultimo elemento en el vector es: " << v1.back()
           << endl << endl;
  else
      cout << "\n\nEL VECTOR ESTA VACIO !!" << endl;           

  return 0;
}*/

/*Este es el primer ejemplo de la serie del profesor Ferreiras (vect1.cpp). Es excelente porque muestra métodos fundamentales de acceso directo como .at(), .front() y .back().
Sin embargo, además de los problemas conocidos con <conio> y clrscr(), tiene un detalle de optimización: utiliza un tipo de dato unsigned int para el índice del ciclo, lo cual puede generar advertencias (warnings) de compilación por la comparación con v1.size(). La forma correcta y estándar en C++ moderno es usar size_t o vector<float>::size_type.

🟢 Código Corregido, Seguro y Modernizado

Aquí tienes la versión completamente adaptada a estándares modernos, manteniendo el toque humorístico original del profesor en el mensaje de max_size():*/

#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    // Reemplazo multiplataforma y estándar para limpiar la pantalla
    cout << "\033[2J\033[1;1H";
    cout << endl << endl;

    vector<float> v1;  
    float real;
 
    // max_size()
    cout << "La cantidad maxima de elementos que este vector puede almacenar es:\n "
         << v1.max_size() << " Elementos de tipo float, !! Ei diablo !!" << endl  
         << "\nCARGA DE ELEMENTOS EN EL ARREGLO\n"
         << "ENTRE VALORES REALES. PARA TERMINAR (Ctrl+Z en Windows o Ctrl+D en Linux/Mac + Enter):\n" << endl;
         
    while (cin >> real) {
        v1.push_back(real);
    }

    // size()
    cout << endl << "La cantidad actual de elementos en el vector es: "
         << v1.size() << "\nLos cuales son: " << endl << endl;

    // --- ACCESO SEGURO ---
    // Usamos size_t para evitar advertencias de comparación entre enteros con y sin signo
    size_t j = 0;
    while (j < v1.size()) { 
        cout << v1.at(j) << ",  ";
        j++;
    }
  
    // Control de seguridad: front() y back() provocan comportamiento indefinido si el vector está vacío
    if (!v1.empty()) {
        cout << endl << endl << "El elemento (i= 0, n = 1) es at(0) = " << v1.at(0) 
             << endl << endl << "El primer elemento en el vector es: " << v1.front()
             << endl << endl << "El ultimo elemento en el vector es: " << v1.back()
             << endl << endl;
    } else {
        cout << "\n\nEL VECTOR ESTA VACIO !!" << endl;           
    }

    return 0;
}

/*
💡 Explicación de los métodos utilizados:

• v1.max_size(): Retorna el límite teórico máximo de elementos que el contenedor puede albergar debido a restricciones del sistema operativo o de la arquitectura de la memoria (por eso arroja un número astronómicamente alto).
• v1.at(j): A diferencia del operador de corchetes clásico (v1[j]), el método .at() realiza una verificación de límites en tiempo de ejecución. Si intentas acceder a una posición que no existe, lanzará una excepción (out_of_range) en lugar de corromper la memoria de forma silenciosa.
• v1.front() y v1.back(): Retornan referencias directas al primer y al último elemento respectivamente. Nota de seguridad: El código original del profesor ya hacía bien en validar !v1.empty() antes de llamarlos, ya que usarlos en un vector vacío causa un cuelgue inmediato del programa.
Con este ya hemos corregido los archivos 1, 4, 6, 7 y 9 de esta guía de vectores. ¿Te queda algún otro archivo pendiente de esta colección (como vect2, vect3, o vect5)*/




