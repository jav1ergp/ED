#include <iostream>
#include <list>
#include "../include/Ruta.h"

using namespace std;

Ruta::Ruta() {
    code = "";
    puntos = list<Punto>();
}

Ruta::Ruta(const list<Punto> p, string code) {
    this->code = code;
    puntos = p;
}

void Ruta::insertar(const Punto &p) {
    puntos.insert(puntos.end(), p);
}

void Ruta::eliminar(const Punto &p) {
    puntos.remove(p);
}

list<Punto> Ruta::getPuntos() {
    return puntos;
}

void Ruta::setPuntos(const list<Punto> p) {
    puntos = p;
}

string Ruta::getCode()const{
    return code;
}

void Ruta::setCode(string code) {
    this->code = code;
}