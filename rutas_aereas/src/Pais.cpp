#include "../include/Pais.h"

Pais::Pais(){
    pais = "";
    bandera = "";
}

Pais::Pais(Punto p2, string pa, string b){
    p = p2;
    pais = pa;
    bandera = b;
}

Punto Pais::GetPunto()const{
    return p;
}

string Pais::GetPais()const{
    return pais;
}
string Pais::GetBandera()const{
    return bandera;
}
bool Pais::operator<(const Pais &P) const{
    return pais < P.pais;
}

bool Pais::operator==(const Pais &P) const{
    return pais == P.pais;
}

bool Pais::operator==(const Punto &P) const{
    return p == P;
}

