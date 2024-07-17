#include "../include/Punto.h"
#include <iostream>

using namespace std;


Punto::Punto() {
    latitud = 0;
    longitud = 0;
    descripcion = "";
}

Punto::Punto(double lat, double longi, string desc) {
    longitud = longi;
    latitud = lat;
    descripcion = desc;
}

double Punto::get_latitud() const{
    return latitud;
}

double Punto::get_longitud() const{
    return longitud;
}

string Punto::get_descripcion() const{
    return descripcion;
}

void Punto::set_latitud(double lat) {
    latitud = lat;
}

void Punto::set_longitud(double longi) {
    longitud = longi;
}

void Punto::set_coordenadas(double lat, double longi) {
    longitud = longi;
    latitud = lat;
}

void Punto::set_descripcion(string desc) {
    descripcion = desc;
}

bool Punto::operator <(const Punto &p) const {
    if(latitud > p.latitud){
        return false;
    } else if(latitud < p.get_latitud()){
        return true;
    } else {
        if(longitud > p.get_longitud()){
            return false;
        } else {
            return true;
        }
    }
}

bool Punto::operator ==(const Punto &p) const {
    return (latitud == p.get_latitud()) && (longitud == p.get_longitud());
}