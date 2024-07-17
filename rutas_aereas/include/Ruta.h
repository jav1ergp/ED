#ifndef Ruta_H
#define Ruta_H
#include <iostream>
#include <list>
#include "Punto.h"

using namespace std;

class Ruta {
    private:    
        list<Punto> puntos;
        string code;

    public:
    /**
     * @brief Constructor por defecto. Crea una ruta sin puntos y con código vacío.
     * @post Se crea una ruta sin puntos y con código vacío.
     */
    Ruta();

    /**
     * @brief Constructor que inicializa una ruta con una lista de puntos y un código.
     * @param p Lista de puntos que conforman la ruta.
     * @param code Código único de la ruta.
     * @post Se crea una ruta con la lista de puntos y el código proporcionados.
     */
    Ruta(const list<Punto> p, string code);

    /**
     * @brief Inserta un punto al final de la lista de puntos.
     * @param p Punto a insertar.
     * @post El punto se inserta al final de la lista de puntos de la ruta.
     */
    void insertar(const Punto &p);

    /**
     * @brief Elimina un punto de la lista de puntos.
     * @param p Punto a eliminar.
     * @post Se elimina el punto de la lista de puntos de la ruta.
     */
    void eliminar(const Punto &p);

    /**
     * @brief Obtiene la lista de puntos de la ruta.
     * @return Lista de puntos de la ruta.
     * @post Se devuelve la lista de puntos de la ruta.
     */
    std::list<Punto> getPuntos();

    /**
     * @brief Establece la lista de puntos de la ruta.
     * @param p Lista de puntos a establecer.
     * @post La lista de puntos de la ruta se actualiza con la lista proporcionada.
     */
    void setPuntos(const list<Punto> p);

    /**
     * @brief Obtiene el código único de la ruta.
     * @return Código único de la ruta.
     * @post Se devuelve el código único de la ruta.
     */
    string getCode() const;

    /**
     * @brief Establece el código único de la ruta.
     * @param code Código único a establecer.
     * @post El código único de la ruta se actualiza con el código proporcionado.
     */
    void setCode(string code);

/**
 * @brief Clase iterator para iterar sobre los puntos de una ruta.
 */
class iterator{
    private:
        list<Punto>::iterator it;

    public:
        friend class Ruta;
        friend class const_iterator;

        iterator(): it(0){} //Constructor por defecto
        iterator(const iterator &otro): it(otro.it){} //Constructor de copia 
        
     /**
     * @brief Operador de incremento.
     * @return Referencia al iterador actual después de incrementar.
     */
        iterator & operator ++(){
            ++it;
            return *this; //referencia al it actual para poder usarlo muchas veces
        }
	 
	 /**
     * @brief Operador de decremento.
     * @return Referencia al iterador actual después de decrementar.
     */
        iterator & operator --(){
            --it;
            return *this;
        }
	 
	 /**
     * @brief Operador de asignación.
     * @param otro Otro iterator para copiar.
     * @return Referencia al iterator actual después de la asignación.
     */
        iterator& operator=(const iterator &otro)
        {
            it = otro.it;
            return *this;
        }
        
	 /**
     * @brief Operador de igualdad.
     * @param iter Otro iterator para comparación.
     * @return True si los iteradores son iguales.
     */
        bool operator ==(const iterator  & iter){ //.it para que se use en los iterators de list<Punto>
            return it == iter.it;
        }

	 /**
     * @brief Operador de desigualdad.
     * @param iter Otro iterator para comparación.
     * @return True si los iteradores son diferentes.
     */
        bool operator !=(const iterator & iter){
            return it != iter.it;
        }
        
	 /**
     * @brief Operador de acceso a la información.
     * @return Referencia al punto actual.
     */
         Punto & operator*(){
            return *it;
        }
};

/**
 * @brief Clase const_iterator para iterar sobre los puntos de una ruta (versión constante).
 */
 
class const_iterator{
    private:
        list<Punto>::const_iterator it;

    public:
        friend class Ruta;

        const_iterator(): it(0){} //Constructor por defecto
        const_iterator(const const_iterator &otro): it(otro.it){} //Constructor copia
        
     /**
     * @brief Operador de incremento.
     * @return Referencia al iterador actual después de incrementar.
     */
        const_iterator & operator ++(){
            ++it;
            return *this; //referencia al it actual para poder usarlo muchas veces
        }

	 /**
     * @brief Operador de decremento.
     * @return Referencia al iterador actual después de decrementar.
     */
        const_iterator & operator --(){
            --it;
            return *this;
        }

	 /**
     * @brief Operador de igualdad.
     * @param iter Otro const_iterator para comparación.
     * @return True si los iteradores son iguales.
     */
        bool operator ==(const const_iterator  & iter){
            return it == iter.it;
        }
	 
	 /**
     * @brief Operador de desigualdad.
     * @param iter Otro const_iterator para comparación.
     * @return True si los iteradores son diferentes.
     */
        bool operator !=(const const_iterator & iter){
            return it != iter.it;
        }

	 /**
     * @brief Operador de acceso a la información.
     * @return Referencia constante al punto actual.
     */
        const Punto & operator*() const{
            return *it;
        }
};

/**
 * @brief Obtiene un iterator apuntando al primer punto de la ruta.
 * @return Iterator apuntando al primer punto de la ruta.
 */
    iterator begin(){
        iterator iter;
        iter.it = puntos.begin(); 
        return iter;
    }

/**
 * @brief Obtiene un iterator apuntando al final de la lista de puntos de la ruta.
 * @return Iterator apuntando al final de la lista de puntos de la ruta.
 */
    iterator end(){
        iterator iter;
        iter.it = puntos.end();
        return iter;
    }

/**
 * @brief Obtiene un const_iterator apuntando al primer punto de la ruta.
 * @return Const_iterator apuntando al primer punto de la ruta.
 */
    const_iterator begin()const{
        const_iterator iter;
        iter.it = puntos.begin(); 
        return iter;
    }
    
/**
 * @brief Obtiene un const_iterator apuntando al final de la lista de puntos de la ruta.
 * @return Const_iterator apuntando al final de la lista de puntos de la ruta.
 */
    const_iterator end()const{
        const_iterator iter;
        iter.it = puntos.end();
        return iter;
    }

/**
 * @brief Sobrecarga del operador de inserción para leer una ruta desde un flujo de entrada.
 * @param is Flujo de entrada.
 * @param r Ruta a leer.
 * @return Referencia al flujo de entrada después de la operación.
 * @post Se lee una ruta desde el flujo de entrada y se almacena en el objeto proporcionado.
 */

    friend istream &operator>>(istream &is, Ruta &r){
        int nruta;
        Punto p;
        Ruta aux;

        is >> aux.code;
        is >> nruta;
        for (int i = 0; i < nruta; ++i)
        {
            is >> p;
            aux.insertar(p);
        }
        r = aux;
        return is;
    }

/**
 * @brief Sobrecarga del operador de extracción para escribir una ruta en un flujo de salida.
 * @param os Flujo de salida.
 * @param r Ruta a escribir.
 * @return Referencia al flujo de salida después de la operación.
 */
    friend ostream &operator<<(ostream &os, const Ruta &r){
        Ruta::const_iterator it;
        if(r.getCode() != ""){
            os << "Code " << r.getCode();
        }

        for(it = r.begin(); it != r.end(); ++it){
            os << *it;
        }
        os << endl;
	    return os;
    }
};

#endif
