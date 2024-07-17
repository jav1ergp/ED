#include "../include/Punto.h"

using namespace std;

int main() {
    Punto punto1(10,20,"Punto A");
    Punto punto2(15, 25, "Punto B");
    Punto punto3(10, 20, "Punto C");

    cout << "Coordenadas del punto 1: " << punto1.get_latitud() << ", " << punto1.get_longitud() << endl;
    cout << "Coordenadas del punto 2: " << punto2.get_latitud() << ", " << punto2.get_longitud() << endl;
    cout << "Descripción del punto 2: " << punto2.get_descripcion() << endl;

    punto3.set_descripcion("Punto C modificado");
    cout << "Nueva descripción del punto 3: " << punto3.get_descripcion() << endl;

    if (punto1 < punto2) {
        cout << "Punto 1 está antes que Punto 2." << endl;
    } else {
        cout << "Punto 1 no está antes que Punto 2." << endl;
    }

    if (punto1 == punto3) {
        cout << "Punto 1 es igual a Punto 3." << endl;
    } else {
        cout << "Punto 1 no es igual a Punto 3." << endl;
    }

    cout << "Coordenadas de un nuevo punto formato:(latitud,longitud)";
    Punto punto4;
    cin >> punto4;
    cout << "El nuevo punto es: " << punto4 << endl;

    return 0;
}