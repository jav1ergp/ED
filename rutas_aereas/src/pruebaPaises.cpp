#include <iostream>
#include <fstream>
#include "../include/Paises.h"

using namespace std;

int main(int argc, char *argv[]) {
    ifstream f(argv[1]);
    Paises pais;
    f >> pais;
    cout << pais << endl;

    Pais p;
    ifstream g(argv[2]);
    g >> p;

    Paises::iterator pais_encontrado = pais.find(p);

    if (pais_encontrado != pais.end()) {
        cout << "Encontrado " << p << endl;

    } else {
        cout << "No Encontrado" << p << endl;
    }


}