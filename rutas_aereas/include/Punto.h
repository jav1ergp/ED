#ifndef Punto_H
#define Punto_H
#include <iostream>
#include <string>

using namespace std;

class Punto{
private:
    double latitud, longitud;
    string descripcion;

public:
	
    /**
     * @brief Constructor por defecto. Crea un punto en el origen sin descripci�n.
     * @post Se crea un punto en el origen sin descripci�n.
     */
    Punto();

    /**
     * @brief Constructor que inicializa un punto con coordenadas y descripci�n.
     * @param lat Latitud del punto.
     * @param longi Longitud del punto.
     * @param desc Descripci�n del punto.
     * @post Se crea un punto con las coordenadas y descripci�n proporcionadas.
     */
    Punto(double lat, double longi, std::string desc);

    /**
     * @brief Obtiene la latitud del punto.
     * @return Latitud del punto.
     */
    double get_latitud() const;

    /**
     * @brief Obtiene la longitud del punto.
     * @return Longitud del punto.
     */
    double get_longitud() const;

    /**
     * @brief Obtiene la descripci�n del punto.
     * @return Descripci�n del punto.
     */
    std::string get_descripcion() const;

    /**
     * @brief Establece la latitud del punto.
     * @param lat Latitud a establecer.
     */
    void set_latitud(double lat);

    /**
     * @brief Establece la longitud del punto.
     * @param longi Longitud a establecer.
     * @post La longitud del punto se actualiza con el valor proporcionado.
     */
    void set_longitud(double longi);

    /**
     * @brief Establece las coordenadas del punto.
     * @param lat Latitud a establecer.
     * @param longi Longitud a establecer.
     * @post Las coordenadas del punto se actualizan con los valores proporcionados.
     */
    void set_coordenadas(double lat, double longi);

    /**
     * @brief Establece la descripci�n del punto.
     * @param desc Descripci�n a establecer.
     * @post La descripci�n del punto se actualiza con el valor proporcionado.
     */
    void set_descripcion(std::string desc);

    /**
     * @brief Sobrecarga del operador de comparaci�n "menor que".
     * @param p Punto para comparaci�n.
     * @return True si el punto actual es menor que el punto proporcionado.
     */
    bool operator <(const Punto &p) const;

    /**
     * @brief Sobrecarga del operador de igualdad.
     * @param p Punto para comparaci�n.
     * @return True si el punto actual es igual al punto proporcionado.
     */
    bool operator ==(const Punto &p) const;


 /**
 * @brief Sobrecarga del operador de inserci�n para imprimir un punto en un flujo de salida.
 * @param os Flujo de salida.
 * @param p Punto a imprimir.
 * @return Referencia al flujo de salida despu�s de la operaci�n.
 * @post Se imprime la representaci�n del punto en el flujo de salida.
 */
friend std::ostream& operator<<(std::ostream &os, const Punto &p) {
    if (p.get_descripcion() != "") {
        os << p.get_descripcion() << " ";
    }
    os << "(" << p.get_latitud() << "," << p.get_longitud() << ")";
    return os;
}

/**
 * @brief Sobrecarga del operador de extracci�n para leer un punto desde un flujo de entrada.
 * @param is Flujo de entrada.
 * @param p Punto a leer.
 * @return Referencia al flujo de entrada despu�s de la operaci�n.
 * @post Se lee un punto desde el flujo de entrada y se almacena en el objeto proporcionado.
 */
friend std::istream& operator>>(std::istream &is, Punto &p) {
    double lat, longi;
    char c;

    is >> c >> lat >> c >> longi >> c;

    p.set_coordenadas(lat, longi);
    p.set_descripcion("");

    return is;
}

};

#endif
