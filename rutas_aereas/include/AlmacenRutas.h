//
// Created by alumno on 4/12/23.
//

#ifndef PRACTICAFINAL_ALMACENRUTAS_H
#define PRACTICAFINAL_ALMACENRUTAS_H
#include "Ruta.h"
#include <map>
#include <iostream>
#include <list>

class AlmacenRutas {
    private:
        map<string, Ruta> rutas;
        multimap<Punto, string> puntos; //identificar los puntos por los que pasa la ruta

    public:
     /**
     * @brief Constructor por defecto. Crea un AlmacenRutas vacío.
     */
    AlmacenRutas();

    /**
     * @brief Constructor que inicializa el almacenamiento con mapas dados.
     * @param rutas Mapa de rutas con el código como clave.
     * @param puntos Multimapa de rutas con las coordenadas como clave.
     */
    AlmacenRutas(map<string, Ruta> rutas, multimap<Punto, string> puntos);

    /**
     * @brief Inserta una ruta en el almacenamiento.
     * @param ruta Ruta a insertar.
     * @post La ruta se ha insertado en el almacenamiento.
     */
    void insertar(const Ruta &ruta);

    /**
     * @brief Elimina una ruta del almacenamiento.
     * @param ruta Ruta a eliminar.
     * @post La ruta se ha eliminado del almacenamiento.
     */
    void eliminar(const Ruta &ruta);

    /**
     * @brief Elimina una ruta del almacenamiento por código.
     * @param code Código de la ruta a eliminar.
     * @post La ruta con el código especificado se ha eliminado del almacenamiento.
     */
    void eliminar_code(const string code);

    /**
     * @brief Obtiene una copia de una ruta en el almacenamiento.
     * @param ruta Ruta con el código especificado.
     * @return Copia de la ruta encontrada.
     */
    Ruta getRuta(const Ruta &ruta);

    /**
     * @brief Obtiene una ruta del almacenamiento por código.
     * @param code Código de la ruta a obtener.
     * @return Ruta con el código especificado.
     */
    Ruta getRuta_code(const string code);

    class iterator{
    private:
        map<string,Ruta>::iterator it;

    public:
        friend class AlmacenRutas;
        friend class const_iterator;

        iterator(){};
        iterator & operator ++(){
            ++it;
            return *this; //referencia al it actual para poder usarlo muchas veces
        }

        iterator & operator --(){
            --it;
            return *this;
        }

        bool operator ==(const iterator  & iter){ //.it para que se use en los iterators de list<Punto>
            return it == iter.it;
        }

        bool operator !=(const iterator & iter){
            return it != iter.it;
        }

        const pair<string,Ruta> operator*(){
            return *it;
        }
    };

    class const_iterator{
    private:
        map<string,Ruta>::const_iterator it;

    public:
        friend class AlmacenRutas;

        const_iterator(){};
        const_iterator & operator ++(){
            ++it;
            return *this; //referencia al it actual para poder usarlo muchas veces
        }

        const_iterator & operator --(){
            --it;
            return *this;
        }

        bool operator ==(const const_iterator  & iter){
            return it == iter.it;
        }

        bool operator !=(const const_iterator & iter){
            return it != iter.it;
        }

        const pair<string,Ruta> operator*(){
            return *it;
        }
    };

    iterator begin(){
        iterator iter;
        iter.it = rutas.begin();
        return iter;
    }

    iterator end(){
        iterator iter;
        iter.it = rutas.end();
        return iter;
    }

    const_iterator begin()const{
        const_iterator iter;
        iter.it = rutas.begin();
        return iter;
    }

    const_iterator end()const{
        const_iterator iter;
        iter.it = rutas.end();
        return iter;
    }

    friend istream &operator>>(istream &is, AlmacenRutas &r){
        AlmacenRutas aux;
        Ruta ruta;

        if(is.peek()=='#'){
            string a;
            getline(is,a);
        }

        for(int i = 0; i < 20; i++) { // no funciona con while asi que le pongo un num alto
            is >> ruta;
            aux.insertar(ruta);
        }

        r = aux;
        return is;
    }


    friend ostream &operator<<(ostream &os, const AlmacenRutas &r){
        AlmacenRutas::const_iterator it;

        for(it = r.begin(); it != r.end(); ++it){
            os << (*it).second << endl;
        }
        os << endl;
        return os;
    }
};


#endif //PRACTICAFINAL_ALMACENRUTAS_H
