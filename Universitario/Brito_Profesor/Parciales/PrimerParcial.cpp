#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


struct Estudiantes {
    string matricula;
    string primernombre;
    string primerapellido;
    int edad;
    char sexo;
    double notafinal;
};

   double notamayor;

Estudiantes estudiante1, estudiante2, estudiante3, estudiante4;

int main () {

	Estudiantes estudiante1 = {"121128", "Cristian", "Rosario", 29, 'M', 84};
	Estudiantes estudiante2 = {"212321", "Manuel", "martinez", 36, 'M', 93};
	Estudiantes estudiante3 = {"323651", "Madelin", "Baez", 19, 'F', 78};
	Estudiantes estudiante4 = {"214659", "Esther", "Beltre", 18, 'F', 71};


	cout << "\nLista de los estudiantes:" << endl;
cout << "Matricula | Nombre | Apellido | Edad | Sexo | Nota" << endl;
cout << "------------------------------------------------" << endl;

cout << estudiante1.matricula << " | "
     << estudiante1.primernombre << " | "
     << estudiante1.primerapellido << " | "
     << estudiante1.edad << " | "
     << estudiante1.sexo << " | "
     << estudiante1.notafinal << endl;

cout << estudiante2.matricula << " | "
     << estudiante2.primernombre << " | "
     << estudiante2.primerapellido << " | "
     << estudiante2.edad << " | "
     << estudiante2.sexo << " | "
     << estudiante2.notafinal << endl;

cout << estudiante3.matricula << " | "
     << estudiante3.primernombre << " | "
     << estudiante3.primerapellido << " | "
     << estudiante3.edad << " | "
     << estudiante3.sexo << " | "
     << estudiante3.notafinal << endl;

cout << estudiante4.matricula << " | "
     << estudiante4.primernombre << " | "
     << estudiante4.primerapellido << " | "
     << estudiante4.edad << " | "
     << estudiante4.sexo << " | "
     << estudiante4.notafinal << endl;

	
if (estudiante1.notafinal >= estudiante2.notafinal &&
    estudiante1.notafinal >= estudiante3.notafinal &&
    estudiante1.notafinal >= estudiante4.notafinal) {

    notamayor = estudiante1.notafinal;

} else if (estudiante2.notafinal >= estudiante1.notafinal &&
           estudiante2.notafinal >= estudiante3.notafinal &&
           estudiante2.notafinal >= estudiante4.notafinal) {

    notamayor = estudiante2.notafinal;

} else if (estudiante3.notafinal >= estudiante1.notafinal &&
           estudiante3.notafinal >= estudiante2.notafinal &&
           estudiante3.notafinal >= estudiante4.notafinal) {

    notamayor = estudiante3.notafinal;

} else {
    notamayor = estudiante4.notafinal;
}

cout << "\nLA NOTA MAYOR ES: " << notamayor << endl;

return 0;
}
