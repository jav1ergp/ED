#include <iostream>
#include <fstream>
#include "../include/Pais.h"

using namespace std;

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    Pais pais;
    f >> pais;

    cout << "País :" << endl;
    cout << pais << endl;

    cout << "País: " << pais.GetPais() << endl;
    cout << "Bandera: " << pais.GetBandera() << endl;
    cout << "Coordenadas: " << pais.GetPunto() << endl;

}