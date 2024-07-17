//
// Created by alumno on 4/12/23.
//

#include "../include/AlmacenRutas.h"

AlmacenRutas::AlmacenRutas() {
    rutas = map<string, Ruta>();
    puntos = multimap<Punto, string>();
}

AlmacenRutas::AlmacenRutas(map<string, Ruta> r, multimap<Punto, string> p) {
    rutas = r;
    puntos = p;
}

void AlmacenRutas::insertar(const Ruta &ruta) {
    rutas.insert(pair<string, Ruta> (ruta.getCode(), ruta));
}

void AlmacenRutas::eliminar(const Ruta &ruta) {
    string code = ruta.getCode();
    rutas.erase(code);
}

void AlmacenRutas::eliminar_code(const string cod) {
    rutas.erase(cod);
}

Ruta AlmacenRutas::getRuta(const Ruta &ruta) {
    map<string, Ruta>::iterator it;
    for (it = rutas.begin(); it != rutas.end(); ++it) {
        if (it->second.getCode() == ruta.getCode()) {
            return it->second;
        }
    }
}

Ruta AlmacenRutas::getRuta_code(const string code) {
    return rutas[code];
}
