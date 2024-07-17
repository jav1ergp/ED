
#include "Pais.h"
#include <set>

using namespace std;

/**
 * @brief La clase Paises representa un conjunto de pa�ses.
 */
class Paises{
  private:
    set<Pais> datos;
  public:
      Paises(){} //Constructor por defecto
      
      /**
     * @brief Inserta un pa�s en el conjunto.
     * @param P Pa�s a insertar.
     * @post El pa�s se ha insertado en el conjunto.
     */
      void Insertar(const Pais &P){
          datos.insert(P);
      }
      
	  /**
     * @brief Borra un pa�s del conjunto.
     * @param P Pa�s a borrar.
     * @post El pa�s se ha borrado del conjunto.
     */
      void Borrar(const Pais &P){
          datos.erase(P);
      }
      
/**
* @brief Clase iterator para iterar sobre los pa�ses en el conjunto.
*/
class iterator{
	private:
	    set<Pais>::iterator it;
	public:
	    friend class Paises;
	    friend class const_iterator;

        iterator(){}; //Constructor por defecto
        
        /**
         * @brief Operador de incremento.
         * @return Referencia al iterador actual despu�s de incrementar.
         */
        iterator & operator ++(){
            ++it;
            return *this; //referencia al it actual para poder usarlo muchas veces
        }
        
	    /**
         * @brief Operador de decremento.
         * @return Referencia al iterador actual despu�s de decrementar.
         */
        iterator & operator --(){
            --it;
            return *this;
        }
		
		/**
         * @brief Operador de igualdad.
         * @param iter Otro iterator para comparaci�n.
         * @return True si los iteradores son iguales.
         */
        bool operator ==(const iterator  & iter){ //.it para que se use en los iterators de list<Punto>
            return it == iter.it;
        }
		
		/**
         * @brief Operador de desigualdad.
         * @param iter Otro iterator para comparaci�n.
         * @return True si los iteradores son diferentes.
         */
        bool operator !=(const iterator & iter){
            return it != iter.it;
        }
         
		/**
         * @brief Operador de acceso a la informaci�n.
         * @return Referencia al pa�s actual.
         */
        const Pais & operator*(){
            return *it;
        }
	};
	   
	   /**
       * @brief Clase const_iterator para iterar sobre los pa�ses en el conjunto (versi�n constante).
       */
	class const_iterator{
	private:
	    set<Pais>::const_iterator it;
	public:
		
		/**
         * @brief Operador de incremento.
         * @return Referencia al iterador actual despu�s de incrementar.
         */
	    friend class Paises;
        const_iterator(){};
        const_iterator & operator ++(){
            ++it;
            return *this; //referencia al it actual para poder usarlo muchas veces
        }
        
        /**
         * @brief Operador de decremento.
         * @return Referencia al iterador actual despu�s de decrementar.
         */
        const_iterator & operator --(){
            --it;
            return *this;
        }
        
        /**
         * @brief Operador de igualdad.
         * @param iter Otro const_iterator para comparaci�n.
         * @return True si los iteradores son iguales.
         */
        bool operator ==(const const_iterator  & iter){
            return it == iter.it;
        }
        
		/**
         * @brief Operador de desigualdad.
         * @param iter Otro const_iterator para comparaci�n.
         * @return True si los iteradores son diferentes.
         */
        bool operator !=(const const_iterator & iter){
            return it != iter.it;
        }
        
		/**
         * @brief Operador de acceso a la informaci�n.
         * @return Referencia constante al pa�s actual.
         */
        const Pais & operator*(){
            return *it;
        }
	};
   
    /**
     * @brief Obtiene un iterator apuntando al primer elemento del conjunto.
     * @return Iterator apuntando al primer elemento del conjunto.
     */
     
    iterator begin(){
        iterator iter;
        iter.it = datos.begin();
        return iter;
    }
    
	/**
     * @brief Obtiene un iterator apuntando al final del conjunto.
     * @return Iterator apuntando al final del conjunto.
     */
    iterator end(){
        iterator iter;
        iter.it = datos.end();
        return iter;
    }
    
	/**
     * @brief Obtiene un const_iterator apuntando al primer elemento del conjunto.
     * @return Const_iterator apuntando al primer elemento del conjunto.
     */
    const_iterator begin()const{
        const_iterator iter;
        iter.it = datos.begin();
        return iter;
    }
    
	/**
     * @brief Obtiene un const_iterator apuntando al final del conjunto.
     * @return Const_iterator apuntando al final del conjunto.
     */
    const_iterator end()const{
        const_iterator iter;
        iter.it = datos.end();
        return iter;
    }
	
	 /**
     * @brief Busca un pa�s en el conjunto por igualdad.
     * @param p Pa�s a buscar.
     * @return Iterator apuntando al pa�s si se encuentra, o a end() si no se encuentra.
     */
     
    iterator find(const Pais &p){
         iterator iter;
         set<Pais>::iterator i;
         for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i);
         iter.it=i;
         return iter;
    }
     /**
     * @brief Busca un pa�s en el conjunto por igualdad de coordenadas.
     * @param p Punto a buscar.
     * @return Iterator apuntando al pa�s si se encuentra, o a end() si no se encuentra.
     */

    iterator find(const Punto &p){
         iterator iter;
         set<Pais>::iterator i;
         for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i);
         iter.it=i;
         return iter;
    }
    
     /**
     * @brief Sobrecarga del operador de inserci�n para leer un conjunto de pa�ses desde un flujo de entrada.
     * @param is Flujo de entrada.
     * @param R Conjunto de pa�ses.
     * @return Referencia al flujo de entrada despu�s de la operaci�n.
     */

	friend istream & operator>>(istream & is, Paises &R){
         Paises rlocal;
         //leemos el comentario
         if (is.peek()=='#'){
             string a;
             getline(is,a);
         }

         Pais P;
         while (is>>P){
             rlocal.Insertar(P);

         }
         R=rlocal;
         return is;
	}
	
	/**
     * @brief Sobrecarga del operador de extracci�n para escribir un conjunto de pa�ses en un flujo de salida.
     * @param os Flujo de salida.
     * @param R Conjunto de pa�ses.
     * @return Referencia al flujo de salida despu�s de la operaci�n.
     */

	friend ostream & operator<<(ostream & os, const Paises &R){
        Paises::const_iterator it;
        for (it=R.begin(); it!=R.end(); ++it){
            os<<*it<<"\t";
        }
        return os;
	}
};
