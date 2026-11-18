#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    const int BYTES_READ_WRITE = 8;
    char fecha[9];
    long bytes, skip;
    fecha[8] = '\0';

    fstream file("fechas.txt", ios::in | ios::out | ios::binary);

    file.seekg(16L, ios::beg);
    file.read(fecha, BYTES_READ_WRITE);
    cout << "La 3ra fecha es: " << fecha << endl;

    file.seekg((long) (6 * BYTES_READ_WRITE), ios::beg);
    file.read(fecha, BYTES_READ_WRITE);
    cout << "La 7ma fecha es: " << fecha << endl;

    file.seekp(0L, ios::end);
    bytes = file.tellp();
    cout << "\nEl archivo tiene " << bytes << " bytes.\n";

    cout << "\nEntre una nueva fecha (YYYYMMDD): ";
    cin.getline(fecha, 9);
    file.write(fecha, BYTES_READ_WRITE);
    bytes += BYTES_READ_WRITE;

    file.seekg(ios::beg);
    skip = 0;
    while ((skip * BYTES_READ_WRITE) != bytes) {
        file.seekg(skip * BYTES_READ_WRITE, ios::beg);
        file.read(fecha, BYTES_READ_WRITE);
        cout << "Fecha " << ++skip << ": " << fecha << endl;
    }

    file.close();
    return 0;
}
