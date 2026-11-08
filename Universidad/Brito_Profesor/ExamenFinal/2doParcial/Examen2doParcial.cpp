/*
Universidad Autónoma de Santo Domingo UASD
Centro UASD San Pedro, Escuela de informatica 5100-29
Introduccion a la Programacion
Cristian Rosario
Matricula: 100806653
*/

// Este fue el que yo hice en el aula, pero tuve que corregir varias cosas y abajo esta el otro. 

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


struct Perfumes {
    string nombrePerfume;
    double precioPerfume;    
};

// Definicion de la funcion

void NombredeNegocio() {
    cout << "Accesorios Mashiaj: tu perfumeria preferida" << endl;
}

int main() {
	vector<Perfumes> perfume(5);
	
	int opcion;
	int i;

	// Datos iniciales de los 5 perfumes

	perfume.at(0).nombrePerfume = "One Million 3.4 oz";
    	perfume.at(0).precioPerfume = 5000;

    	perfume.at(1).nombrePerfume = "Armari Aqua di Gio 3.4 oz";
    	perfume.at(1).precioPerfume = 7500;

    	perfume.at(2).nombrePerfume = "Dolce Gabanna Light blue 4.2 oz";
    	perfume.at(2).precioPerfume = 4200;

    	perfume.at(3).nombrePerfume = "Nautica Voyage 3.4 oz";
    	perfume.at(3).precioPerfume = 2500;

    	perfume.at(4).nombrePerfume = "Valentino Born in roma 3.4 oz";
    	perfume.at(4).precioPerfume = 6500;

	cout << fixed << setprecision(2);


	cout << "\nBienvenidos a" << endl;
	NombredeNegocio();
	cout << fixed << setprecision(2) << left;

	cout << "+-------------------------------------------------------------+" << endl;

	cout << "|  " << setw(6) << "Opcion  "
		     << "| " << setw(40) << "        Perfume"
		     << "| " << setw(8) << " Precio"
		     << endl;

	cout << "+-------------------------------------------------------------+" << endl;

        for (i = 0; i < perfume.size(); i++) {
            cout << "| " << setw(8) << i + 1
                 << " | " << setw(40) << perfume.at(i).nombrePerfume
                 << " | " << setw(8) << perfume.at(i).precioPerfume
                 << " |" << endl;
	}

	 cout << "+----------+-----------------------------------------------------+" << endl;
        

   	cout << "\n\nSeleccione Una Opcion (1, 2, 3, 4, 5,): ";
        cin >> opcion;

	switch(opcion) {
	
       
        case 1: cout << endl << "Aqui esta su perfume: One Million 3.4 oz" << endl;
	    break;
        
        case 2: cout << endl << "Aqui esta su perfume: Armari Aqua di Gio 3.4 oz" << endl;
                      break;
        
        case 3: cout << endl << "Aqui esta su perfume: Dolce Gabanna Light blue 4.2 oz" << endl;
	      break;
        
        case 4: cout << endl << "Aqui esta su perfume: Nautica Voyage 3.4 oz" << endl;
                      break;
	
	case 5: cout << endl << "Aqui esta su perfume: Valentino Born in roma 3.4 oz" << endl;
                      break;

	case 0: 

        
        default:  cout << endl << "por favor Presta Atencion a lo que haces: " << opcion 
                              << " NO ESTA ENTRE ESTOS NUMEROS (1,2,3,4,5,)" << endl;
	    break;
	}


return 0;
}
