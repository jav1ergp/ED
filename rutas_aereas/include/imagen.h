
#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <string>

enum Tipo_Pegado {OPACO, BLENDING};

using namespace std;

struct Pixel{
    unsigned char r,g,b;
    unsigned char transp; //0 no 255 si
};

class Imagen{
private:
    Pixel ** data;
    int nf,nc;
    /**
     * @brief Libera la memoria ocupada por la imagen.
     * @pre La imagen debe haber sido creada previamente.
     */
    void Borrar();

    /**
     * @brief Copia los datos de otra imagen.
     * @param I Imagen de la cual se copiar�n los datos.
     * @pre La imagen debe haber sido creada previamente.
     * @post La imagen actual contiene una copia de los datos de I.
     */
    void Copiar(const Imagen &I);

public:
    /**
     * @brief Constructor por defecto. Crea una imagen vac�a.
     * @post La imagen es vac�a (fil = col = 0).
     */
    Imagen();

    /**
     * @brief Constructor de copia. Crea una copia de otra imagen.
     * @param I Imagen a copiar.
     * @post La imagen actual es una copia de I.
     */
    Imagen(const Imagen &I);

    /**
     * @brief Constructor que crea una imagen con dimensiones especificadas y fondo blanco.
     * @param f N�mero de filas.
     * @param c N�mero de columnas.
     * @post La imagen actual es de tama�o f x c y tiene un fondo blanco.
     */
    Imagen(int f, int c);

    /**
     * @brief Operador de asignaci�n. Asigna los valores de otra imagen a esta imagen.
     * @param I Imagen a asignar.
     * @return Referencia a la imagen actual.
     * @post La imagen actual contiene una copia de los datos de I.
     */
    Imagen &operator=(const Imagen &I);

    /**
     * @brief Destructor. Libera la memoria ocupada por la imagen.
     * @post La memoria utilizada por la imagen ha sido liberada.
     */
    ~Imagen();

    /**
     * @brief Obtiene el n�mero de filas de la imagen.
     * @return N�mero de filas.
     */
    int num_filas()const{return nf;}

    /**
     * @brief Obtiene el n�mero de columnas de la imagen.
     * @return N�mero de columnas.
     */
    int num_cols()const{return nc;}

    /**
     * @brief Accede al p�xel en la posici�n especificada para lectura/escritura.
     * @param i Fila del p�xel.
     * @param j Columna del p�xel.
     * @return Referencia al p�xel en la posici�n (i, j).
     * @pre i y j deben estar dentro de los l�mites de la imagen.
     */
    Pixel &operator()(int i, int j);

    /**
     * @brief Accede al p�xel en la posici�n especificada para lectura.
     * @param i Fila del p�xel.
     * @param j Columna del p�xel.
     * @return Const referencia al p�xel en la posici�n (i, j).
     * @pre i y j deben estar dentro de los l�mites de la imagen.
     */
    const Pixel &operator()(int i, int j) const;

    /**
     * @brief Escribe la imagen en un archivo PPM junto con una m�scara de transparencia en formato PGM.
     * @param nombre Nombre del archivo de imagen.
     * @post Los datos de la imagen han sido escritos en el archivo especificado.
     */
    void EscribirImagen(const char *nombre);

    /**
     * @brief Lee una imagen desde un archivo PPM y, opcionalmente, una m�scara de transparencia desde un archivo PGM.
     * @param nombre Nombre del archivo de imagen.
     * @param nombremascara Nombre del archivo de la m�scara (puede ser una cadena vac�a).
     * @post La imagen actual contiene los datos le�dos desde el archivo especificado.
     */
    void LeerImagen(const char *nombre,const string &nombremascara="");


    /**
     * @brief Limpia la transparencia de todos los p�xeles en la imagen.
     * @post Todos los p�xeles tienen un valor de transparencia igual a cero.
     */
    void LimpiarTransp();

    /**
     * @brief Inserta una imagen en la posici�n especificada con opciones de pegado.
     * @param posi Fila de inicio para pegar la imagen.
     * @param posj Columna de inicio para pegar la imagen.
     * @param I Imagen a pegar.
     * @param tipo Tipo de pegado (OPACO o TRANSLUCIDO).
     * @pre La imagen actual y la imagen a pegar deben tener dimensiones v�lidas.
     * @post La imagen actual se ha modificado con la inserci�n de la imagen pegada.
     */
    void PutImagen(int posi, int posj, const Imagen &I, Tipo_Pegado tipo);
};

#endif
