#include "../include/Ruta.h"
#include <fstream>

using namespace std;

int main(int argc, char * argv[]) {
    ifstream f(argv[1]);
    Ruta ruta;
    f >> ruta;

    cout << "La ruta es" << endl << ruta << endl;

    ruta.eliminar(Punto(52.50786264022465, 13.426141949999987, ""));
    ruta.insertar(Punto(60.5079, 11.4261, " NUEVO"));
    ruta.insertar(Punto(63.5079, 10.4261, " NUEVO"));

    cout << "La ruta es" << endl << ruta << endl;

    cout << "Los puntos son: " << endl;
    for (Ruta::iterator it = ruta.begin(); it != ruta.end(); ++it) {
        cout << *it;
    }
    cout << endl;
}
