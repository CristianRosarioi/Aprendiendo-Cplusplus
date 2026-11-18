#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandomNumber();
void writeNumber(fstream &, int);
void openFile(fstream &, string);
void closeFile(fstream &);

const int TOTAL_NUMBER = 10;
const int LIMIT_NUMBER = 100;

int main()
{
    fstream oddFile;
    fstream evenFile;

    openFile(oddFile, "impares.txt");
    openFile(evenFile, "pares.txt");

    int number;
    srand(time(0));

    cout << "Escribiendo numeros:\n\n";
    for (int i = 0; i < TOTAL_NUMBER; i++)
    {
        number = getRandomNumber();

        cout << number << "  ";
        if (number % 2 == 0)
            writeNumber(evenFile, number);
        else
            writeNumber(oddFile, number);
    }

    closeFile(oddFile);
    closeFile(evenFile);
    cout << "\n\nTerminado!" << endl;

    return 0;
}

int getRandomNumber()
{
    return rand() % LIMIT_NUMBER + 1;
}

void writeNumber(fstream &file, int number)
{
    file << number << endl;
}

void openFile(fstream &file, string fileName)
{
    file.open(fileName.c_str(), ios::out);
}

void closeFile(fstream &file)
{
    file.close();
}
