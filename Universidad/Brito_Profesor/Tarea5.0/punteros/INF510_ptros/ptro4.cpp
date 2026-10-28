
/*
  ptro4.cpp
  Comilador: bcc32 5.5

  C++ /Ferreiras /  Punteros en C++

  Puntero a void

*/

#include <iostream> 

using namespace std;

 void f1(void* data, int x){
      
      if ( x == sizeof(char) ) {
         char* pcaracter;
         pcaracter=(char*)data;// Es obligatorio hacer la
                                  //  coversion
         ++(*pcaracter);
      }
else if (x == sizeof(int) ) {
         int* pentero;
         pentero=(int*)data;// Es obligatorio hacer la conversion 
         ++(*pentero); 
      }
 
      else if (x == sizeof(float) ) {
         float* pflotante;
         pflotante=(float*)data; // Es obligatorio hacer la 
                                 // conversion 
         ++(*pflotante);
      }
      else{
         cout << endl << endl
              << "NO HAY CODIGO PARA ESE TIPO !!" << endl;       
         exit(0);
      }
}


void f(void) {
    
    char w;
    int  z; 
    float y; 
    
    cout << endl << "Entre un char : ";
    cin >> w;
    
    cout << endl << "Entre un int : ";
    cin >> z;

    cout << endl << "Entre un real : ";
    cin >> y;

    f1 (&w, sizeof(w));
    f1 (&z, sizeof(z));
    f1 (&y, sizeof(y));

    cout << endl << w << ", " 
         << z <<  ", " << y << endl;
    
 } 


int main(void){

    f();
    return 0;
}

/*
    C:\Borland\BCC55\Bin>ptro4

C:\Borland\BCC55\Bin>ptro4

Entre un char : A

Entre un int : 45

Entre un real : 3.456

B, 46, 3.456

*/
