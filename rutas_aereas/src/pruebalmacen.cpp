#include "../include/AlmacenRutas.h"

#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
    ifstream f (argv[1]);
    AlmacenRutas alm;
    f >> alm;
    cout << alm << endl;

    alm.eliminar_code("R3");

    Ruta ruta;
    ruta.setCode("D1");
    ruta.insertar(Punto(12.2334,10.2222, ""));
    ruta.insertar(Punto(33.2334,33.2222,""));
    ruta.insertar(Punto(22.2334,22.2222,""));

    alm.insertar(ruta);
    cout << alm << endl;
    cout << alm.getRuta_code("R4");
    string a = "R5";
    Ruta d = alm.getRuta_code(a);
    cout << d;
    cout << d;

}