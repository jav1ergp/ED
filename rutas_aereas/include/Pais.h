#ifndef PAIS_H
#define PAIS_H

#include "Punto.h"
using namespace std;

class Pais{
private:
    Punto p;
    string pais;
    string bandera;

public:
   /**
     * @brief Constructor por defecto. Crea un pa�s sin informaci�n.
     * @post Se crea un pa�s sin informaci�n (punto, nombre, bandera).
     */
    Pais();

    /**
     * @brief Constructor que inicializa un pa�s con un punto, nombre y ruta de la bandera.
     * @param p Punto que representa la ubicaci�n del pa�s.
     * @param pais Nombre del pa�s.
     * @param bandera Ruta de la bandera del pa�s.
     * @post Se crea un pa�s con la informaci�n proporcionada.
     */
    Pais(Punto p, string pais, string bandera);

    /**
     * @brief Obtiene el punto que representa la ubicaci�n del pa�s.
     * @return Punto que representa la ubicaci�n del pa�s.
     * @post Se devuelve el punto del pa�s.
     */
    Punto GetPunto() const;

    /**
     * @brief Obtiene el nombre del pa�s.
     * @return Nombre del pa�s.
     * @post Se devuelve el nombre del pa�s.
     */
    std::string GetPais() const;

    /**
     * @brief Obtiene la ruta de la bandera del pa�s.
     * @return Ruta de la bandera del pa�s.
     * @post Se devuelve la ruta de la bandera del pa�s.
     */
    std::string GetBandera() const;

    /**
     * @brief Sobrecarga del operador de comparaci�n "menor que" para ordenar pa�ses por nombre.
     * @param P Otro pa�s para comparaci�n.
     * @return True si el nombre del pa�s actual es menor que el del pa�s proporcionado.
     * @post Se devuelve true si el nombre del pa�s actual es menor que el del pa�s proporcionado.
     */
    bool operator<(const Pais &P) const;

    /**
     * @brief Sobrecarga del operador de igualdad para comparar pa�ses por nombre.
     * @param P Otro pa�s para comparaci�n.
     * @return True si el nombre del pa�s actual es igual al del pa�s proporcionado.
     * @post Se devuelve true si el nombre del pa�s actual es igual al del pa�s proporcionado.
     */
    bool operator==(const Pais &P) const;

    /**
     * @brief Sobrecarga del operador de igualdad para comparar con un punto.
     * @param P Punto para comparaci�n.
     * @return True si el punto actual es igual al punto proporcionado.
     * @post Se devuelve true si el punto actual es igual al punto proporcionado.
     */
    bool operator==(const Punto &P) const;

    friend istream & operator>>(istream & is, Pais & P){
        double lat,lng;

        is >> lat >> lng >> P.pais >> P.bandera;

        P.p=Punto(lat,lng,"");
        return is;
    }

    friend ostream & operator<<(ostream & os, const Pais &P){
        os << P.p << " " << P.pais << " " << P.bandera << endl;
        return os;
    }
};
#endif
