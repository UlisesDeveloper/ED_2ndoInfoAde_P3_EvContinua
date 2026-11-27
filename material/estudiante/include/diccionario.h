#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>


using namespace std;



/*Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que
no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave
de tipo T. El diccionario está ordenado de menor a mayor clave.
 */

  /**
   * @brief Estructura de dato del que esta hecho la lista del diccionario
   *
   * Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave de tipo T. El diccionario está ordenado de menor a mayor clave.
   *
   * @param clave guarda la clave de una entrada
   * @param info_asoci lista de la informacion asociada a una entrada
   */
template <class T, class U>
struct data {
    T clave;
    list<U> info_asoci;
};



/*Comparador de datos. Ordena 2 registros de acuerdo a la clave de tipo T. Puede usarse como
un funtor.
 */
/**
   * @brief Operador de comparacion entre datos de la entradas del diccionario
   *
   * Comparador de datos. Ordena 2 registros de acuerdo a la clave de tipo T. Puede usarse como un funtor
   *
   * @param d1 primer parametro de comparacion
   * @param d2 segundo parametro de comparacion
   */
template <class T, class U>
bool operator<(const data<T, U> &d1, const data <T, U>&d2) {
    if (d1.clave < d2.clave)
        return true;
    return false;

}



/**
 * @brief Diccionario de lista
 * @details lo almacena con una lista las entradas del struct data<T,U>
 */

template <class T, class U>
class Diccionario {
private:
    /**
     * @brief Lista de datos (clave, lista de información asociada) ordenados por clave de menor a mayor.
     */
    list<data<T, U> > datos;

    /* Copia el diccionario de entrada en el objeto implicito*/
    /**
   * @brief Copia de diccionario
   *
   * Copia el diccionario de entrada en el objeto implicito
   *
   * @param D diccionario a copiarse
   */
    void Copiar(const Diccionario<T, U>& D);

    /* Borra todos los datos que contiene el diccionario*/
    /**
   * @brief Borrado de diccionario
   *
   * Borra todos los datos que contiene el diccionario
   *
   */
    void Borrar();

public:

    /**
     *Constructor por defecto
     */
    /**
   * @brief Constructor por defecto
   *
   * Constructor por defecto del Diccionario, sin funcion se queda vacio
   *
   */
    Diccionario();

    /**
     *Constructor de copias
     */
    /**
   * @brief Constructor de copias
   *
   * Constructor de copia, copia los datos de un diccionario a otro 
   *
   * @param D diccionario a copiarse en la nueva instancia del diccionario
   */
    Diccionario(const Diccionario &D);

    /**
     * Destructor
     */
    /**
   * @brief Destructor 
   *
   * Se limpia automaticamente antes de destruirse la instancia 
   *
   */
    ~Diccionario();

    /**
     *Operador de asignación
     */
    /**
   * @brief Operador de Asignacion
   *
   * Copia los datos del diccionario de parametro al nuestro
   *
   * @param D diccionario a copiarse en esta instancia del diccionario
   * @return referencia a la instancia para permitir encadenar asignaciones
   */
    Diccionario<T, U>& operator=(const Diccionario<T, U> &D);


    //Explicacion de chat de funcionalidad de typename 
    /*
    Because :: is used to access static variables, functions, and inner types alike, 
    the compiler needs to know which one you are grabbing. Whenever <T> or <T, U> appears to the left of ::, 
    the compiler can't look inside that template yet to check for itself, 
    so typename explicitly tells it: "What comes after :: is a datatype, not a variable or a function."
    
    
    typename is not a one-time declaration at the top of a class (that's what template <class T, class U> does)—it is a tag you have to stick directly onto every single line where you write SomethingWithT<T, U>::InnerType
    */

    /**
    * @brief clase del iterador para recorrer el diccionario 
    */
    class iterator{
        //Completar el iterador
        private:
        /**
        * @brief iterador de list<data<T,U>> 
        */
        typename list<data<T, U>>::iterator iterador;
        public:
        /**
        * @brief Constructor por defecto (vacio) 
        */
        iterator(){};
        /**
        * @brief Constructor por copia de iterador real que tiene el diccionario
        * 
        * @param a iterador a lista de data<T,U>
        */
        iterator(const typename list<data<T,U>>::iterator &a){
            iterador = a;
        }
        /**
        * @brief Constructor por copia de instancia de clase iterator de Diccionario
        *
        * @param a iterator de la clase de Diccionario 
        */
        iterator(const iterator &a){
            iterador = a.iterador;
        }
        /**
        * @brief Destructor
        */
        ~iterator(){}
        /**
        * @brief Operador de asignacion mediante instancia de clase iterator de Diccionario
        * 
        * 
        * @param otro iterator de la clase de Diccionario 
        * @return referenecia a iterator para permitir encadenar asignaciones
        */
        iterator& operator=(const iterator& otro){
            if(this != &otro){
                iterador=otro.iterador;
            }
            return *this;
        }
        /**
        * @brief Operador de asignacion mediante iterador de list<data<T,U>>
        * 
        * 
        * @param otro iterator de la clase de Diccionario 
        * @return referenecia a iterator para permitir encadenar asignaciones
        */
        iterator& operator=(const typename list<data<T,U>>::iterator& otro){
            
                iterador=otro;
            
            return *this;
        } 
        /**
        * @brief Operador de referencia 
        * 
        * es const porque dentro de la funcion no se modifica nada
        * 
        * 
        * @return referencia al elemento del iterador
        */
        data<T, U>& operator*() const{
            return *iterador;
        }
        /**
        * @brief Operador de preaumento en 1
        * 
        * Aumenta en 1 el iterador para que apunte/se refiera al siguiente elemento
        * 
        * @return referencia al iterador
        */
        iterator& operator++(){
            ++iterador;
            return *this;
        }
        /**
        * @brief Operador de predecremento en 1
        * 
        * Decrementa en 1 el iterador para que apunte/se refiera al elemento anterior
        * 
        * @return referencia al iterador
        */
        iterator& operator--(){
            --iterador;
            return *this;
        }
        /**
        * @brief Operador de postaumento en 1
        * 
        * Aumenta en 1 el iterador para que apunte/se refiera al siguiente elemento
        * 
        * @param int para que se entienda que es para postaumento
        * @return referencia al iterador
        */
        iterator& operator++(int){
            iterador++;
            return *this;
        }
        /**
        * @brief Operador de postdecremento en 1
        * 
        * Decrementa en 1 el iterador para que apunte/se refiera al elemento anterior
        * 
        * @param int para que se entienda que es para postaumento
        * @return referencia al iterador
        */
        iterator& operator--(int){
            iterador--;
            return *this;
        }

        /**
        * @brief Operador de comparacion de desigualdad 
        * 
        * 
        * @param otro iterador de comparacion
        * @return bool true si son distintos, false si son los mismos
        */
        bool operator!=(const iterator& otro) const{
            return otro.iterador != iterador;
        }

        /**
        * @brief Operador de comparacion de igualdad 
        * 
        * 
        * @param otro iterador de comparacion
        * @return bool true si se refieren al mismo, false si no 
        */
        bool operator==(const iterator& otro) const{
            return otro.iterador == iterador;
        }
        friend class Diccionario<T,U>;

    };
    /**
    * @brief clase del const_iterador para recorrer el diccionario 
    */
    class const_iterator{
        //Completar el const_iterator
        private:
        /**
        * @brief const_iterator de list<data<T,U>> 
        */
        typename list<data<T, U>>::const_iterator iterador;
        public:
        /**
        * @brief Constructor por defecto (vacio) 
        */
        const_iterator(){};
        /**
        * @brief Constructor por copia de const_iterador real que tiene el diccionario
        * 
        * @param a const_iterator a lista de data<T,U>
        */
        const_iterator(const typename list<data<T,U>>::const_iterator &a){
            iterador = a;
        } 
        /**
        * @brief Constructor por copia de instancia de clase const_iterator de Diccionario
        *
        * @param a const_iterator de la clase de Diccionario 
        */
        const_iterator(const const_iterator &a){
            iterador = a.iterador;
        }
        /**
        * @brief Destructor
        */
        ~const_iterator(){}
        /**
        * @brief Operador de asignacion mediante instancia de clase const_iterator de Diccionario
        * 
        * 
        * @param otro const_iterator de la clase de Diccionario 
        * @return referenecia a const_iterator para permitir encadenar asignaciones
        */
        const_iterator& operator=(const const_iterator& otro){
            if(this != &otro){
                iterador=otro.iterador;
            }
            return *this;
        }
        /**
        * @brief Operador de asignacion mediante const_iterador de list<data<T,U>>
        * 
        * 
        * @param otro const_iterator de la clase de Diccionario 
        * @return referenecia a const_iterator para permitir encadenar asignaciones
        */
        const_iterator& operator=(const typename list<data<T,U>>::const_iterator& otro){
            
            iterador=otro;
            
            return *this;
        } 

        /**
        * @brief Operador de referencia 
        * 
        * es const porque dentro de la funcion no se modifica nada
        * y const el dato de retorno para que no se permita la modificacion
        * 
        * @return referencia constante al elemento del iterador
        */
        const data<T, U>& operator*() const{
            return *iterador;
        }

        /**
        * @brief Operador de preaumento en 1
        * 
        * Aumenta en 1 el const_iterator para que apunte/se refiera al siguiente elemento
        * 
        * @return referencia al const_iterator
        */
        const_iterator& operator++(){
            ++iterador;
            return *this;
        }

        /**
        * @brief Operador de predecremento en 1
        * 
        * Decrementa en 1 el const_iterador para que apunte/se refiera al elemento anterior
        * 
        * @return referencia al const_iterador
        */
        const_iterator& operator--(){
            --iterador;
            return *this;
        }

        /**
        * @brief Operador de postaumento en 1
        * 
        * Aumenta en 1 el const_iterador para que apunte/se refiera al siguiente elemento
        * 
        * @param int para que se entienda que es para postaumento
        * @return referencia al const_iterador
        */
        const_iterator& operator++(int){
            iterador++;
            return *this;
        }
        /**
        * @brief Operador de postdecremento en 1
        * 
        * Decrementa en 1 el const_iterador para que apunte/se refiera al elemento anterior
        * 
        * @param int para que se entienda que es para postaumento
        * @return referencia al const_iterador
        */
        const_iterator& operator--(int){
            iterador--;
            return *this;
        }

        /**
        * @brief Operador de comparacion de desigualdad 
        * 
        * 
        * @param otro const_iterador de comparacion
        * @return bool true si son distintos, false si son los mismos
        */
        bool operator!=(const const_iterator& otro) const{
            return otro.iterador != iterador;
        }

        /**
        * @brief Operador de comparacion de igualdad 
        * 
        * 
        * @param otro const_iterador de comparacion
        * @return bool true si se refieren al mismo, false si no 
        */
        bool operator==(const const_iterator& otro) const{
            return otro.iterador == iterador;
        }
        friend class Diccionario<T,U>;
    };

    /**
     Busca la clave p en el diccionario.
      p es la clave a buscar. it_out apuntara al elemento con esa clave y en caso
      contrario de que no este la clave it_out apuntara a donde debería estar.
    */
   /**
   * @brief Esta_clave busca clave de diccionario
   *
   * Busca la clave p en el diccionario.
   * p es la clave a buscar. it_out apuntara al elemento con esa clave y en caso
   * contrario de que no este la clave it_out apuntara a donde debería estar.
   *
   * @param p clave a buscar
   * @param it_out apunta al elemento con esa clave
   * @return bool de si se encuentra o no
   */
    bool Esta_Clave(const T &p, typename Diccionario<T,U>::iterator &it_out);


    /**
     Inserta un nuevo registro en el diccionario.
     clave clave usada para insertar en el diccionario
     info informacion asociada a la clave que se inserta junto con clave
     el diccionario se supone ordenado, ya que insertar inserta en orden
     */
    /**
   * @brief Inserta clave en el diccionario
   *
   * Inserta un nuevo registro en el diccionario.
   * clave clave usada para insertar en el diccionario
   * info informacion asociada a la clave que se inserta junto con clave
   * el diccionario se supone ordenado, ya que insertar inserta en orden
   *
   * @param clave clave a insertar
   * @param info info asociada de la clave a insertar
   */
    void Insertar(const T& clave, const list<U> &info);


    /**
     Añade una nueva informacion asocida a una clave que está en el diccionario.
     La nueva información se inserta al final de la lista de información.
     Si no esta la clave la inserta y añade la informacion asociada.
     */
    /**
   * @brief Añade significado a una clave
   *
   * Añade una nueva informacion asocida a una clave que está en el diccionario.
   * La nueva información se inserta al final de la lista de información.
   * Si no esta la clave la inserta y añade la informacion asociada.
   *
   * @param s info a insertar
   * @param p clave a la que insertar la info
   */
    void AddSignificado_Palabra(const U & s, const T &p);


    /**
     Devuelve la información (una lista) asociada a una clave p.
     devuelve una lista con la informacion asociada a la clave.
     */
    /**
   * @brief Nos devuelve la info asociada de una clave
   *
   * Devuelve la información (una lista) asociada a una clave p.
   * devuelve una lista con la informacion asociada a la clave.
   *
   * @param p clave de la que sacar la informacion asociada
   * @return list<U> con la informacion asociada de la clave
   */
    list<U> getInfo_Asoc(const T & p);

    /**
     Devuelve el tamaño del diccionario
     tamaño del diccionario
     */
    /**
   * @brief Tamaño del diccionario
   *
   * Devuelve el tamaño del diccionario tamaño del diccionario
   *
   * @return int con num de entradas en el diccionario
   */
    int size()const;


    /**
     borra un data del diccionario por su clave
     c es la clave cuyo elemento queremos borrar. Devuelve
     true si se ha borrado el elemento, false si no
     */
    /**
   * @brief Borrado de una entrada por la clave
   *
   * borra un data del diccionario por su clave
   * c es la clave cuyo elemento queremos borrar. Devuelve
   * true si se ha borrado el elemento, false si no
   *
   * @param c clave de la entrada a borrar
   * @return bool si se ha borrado o si no el elemento de la clave del parametro
   */
    bool Borrar(const T & c);

    /**
     Union de 2 diccionarios
     Si una clave aparece en ambos diccionarios en el resultante aparece una sola vez con la union
     de las informaciones asociadas.
     */
    /**
   * @brief union logica de diccionarios
   *
   * Union de 2 diccionarios
   * Si una clave aparece en ambos diccionarios en el resultante aparece una sola vez con la union
   * de las informaciones asociadas.
   *
   * @param D Diccionario al que unir con la instancia actual
   * @return Diccionario resultante de la union del parametro y de la instancia actual
   */
    Diccionario union_d(const Diccionario & D);

    /**
     elimina las claves del diccionario que aprecen en D
     D diccionario cuyas claves queremos eliminar
     */
    /**
   * @brief diferencia logica de diccionarios
   *
   * elimina las claves del diccionario que aprecen en D
   * D diccionario cuyas claves queremos eliminar
   *
   * @param D Diccionario al que hacer la diferencia con la instancia actual
   * @return Diccionario resultante de la diferencia del parametro y de la instancia actual
   */
    Diccionario diferencia(const Diccionario &D);

    /**
     Interssecion d 2 diccionarios;
     diccionario con el que se interseca
     */
    /**
   * @brief interseccion logica de diccionarios
   *
   * Interssecion d 2 diccionarios;
   * diccionario con el que se interseca
   *
   * @param D Diccionario al que hacer la interseccion con la instancia actual
   * @return Diccionario resultante de la interseccion del parametro y de la instancia actual
   */
    Diccionario interseccion(const Diccionario & D);


    /**
     Devuelve un diccionario con las claves en el
     * 	intervalo [i,f)

     */
    /**
   * @brief obtener diccionario de un rango de entradas en la instancia actual
   *
   * Devuelve un diccionario con las claves en el
   * intervalo [i,f)
   *
   * @param i Clave del elemento del rango inferior [
   * @param f Clave del elemento del rango inferior )
   * @return Diccionario resultante del rango establecido por los parametros sobre la instancia actual
   */
    Diccionario Devolver_rango(const T &i, const T & f);


    /** Funciones begin y end para los iteradores**/
    /**
   * @brief funcion begin del iterador no const
   *
   * @return iterator apuntando al principio 
   */
    iterator begin();

    /**
   * @brief funcion end del iterador no const
   *
   * @return iterator apuntando a elemento por encima del final
   */
    iterator end();
    /**
   * @brief funcion begin del iterador const
   *
   * @return const_iterator apuntando al principio
   */
    const_iterator begin() const;

     /**
   * @brief funcion end del iterador const
   *
   * @return const_iterator apuntando a elemento por encima del final
   */
    const_iterator end() const;

};


//cosa de gpt
#include "../src/diccionario.cpp"
#endif
