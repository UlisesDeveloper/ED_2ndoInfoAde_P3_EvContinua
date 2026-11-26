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


    class iterator{
        //Completar el iterador
        private:
        typename list<data<T, U>>::iterator iterador;
        public:
        iterator(){};
        iterator(const typename list<data<T,U>>::iterator &a){
            iterador = a;
        }
        iterator(const iterator &a){
            iterador = a.iterador;
        }
        ~iterator(){}
        iterator& operator=(const iterator& otro){
            if(this != &otro){
                iterador=otro.iterador;
            }
            return *this;
        }
        iterator& operator=(const typename list<data<T,U>>::iterator& otro){
            
                iterador=otro;
            
            return *this;
        } 

        data<T, U>& operator*() const{
            return *iterador;
        }

        iterator& operator++(){
            ++iterador;
            return *this;
        }

        iterator& operator--(){
            --iterador;
            return *this;
        }

        iterator& operator++(int){
            iterador++;
            return *this;
        }
        iterator& operator--(int){
            iterador--;
            return *this;
        }

        bool operator!=(const iterator& otro) const{
            return otro.iterador != iterador;
        }

        bool operator==(const iterator& otro) const{
            return otro.iterador == iterador;
        }
        friend class Diccionario<T,U>;

    };
    class const_iterator{
        //Completar el const_iterator
        private:
        typename list<data<T, U>>::const_iterator iterador;
        public:
        const_iterator(){};
        const_iterator(const typename list<data<T,U>>::const_iterator &a){
            iterador = a;
        } 
        const_iterator(const const_iterator &a){
            iterador = a.iterador;
        }
        ~const_iterator(){}
        const_iterator& operator=(const const_iterator& otro){
            if(this != &otro){
                iterador=otro.iterador;
            }
            return *this;
        }
        const_iterator& operator=(const typename list<data<T,U>>::const_iterator& otro){
            
            iterador=otro;
            
            return *this;
        } 

        const data<T, U>& operator*() const{
            return *iterador;
        }

        const_iterator& operator++(){
            ++iterador;
            return *this;
        }

        const_iterator& operator--(){
            --iterador;
            return *this;
        }

        const_iterator& operator++(int){
            iterador++;
            return *this;
        }
        const_iterator& operator--(int){
            iterador--;
            return *this;
        }

        bool operator!=(const const_iterator& otro) const{
            return otro.iterador != iterador;
        }

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

    list<U> getInfo_Asoc(const T & p);

    /**
     Devuelve el tamaño del diccionario
     tamaño del diccionario
     */
    int size()const;


    /**
     borra un data del diccionario por su clave
     c es la clave cuyo elemento queremos borrar. Devuelve
     true si se ha borrado el elemento, false si no
     */
    bool Borrar(const T & c);

    /**
     Union de 2 diccionarios
     Si una clave aparece en ambos diccionarios en el resultante aparece una sola vez con la union
     de las informaciones asociadas.
     */
    Diccionario union_d(const Diccionario & D);

    /**
     elimina las claves del diccionario que aprecen en D
     D diccionario cuyas claves queremos eliminar
     */
    Diccionario diferencia(const Diccionario &D);

    /**
     Interssecion d 2 diccionarios;
     diccionario con el que se interseca
     */
    Diccionario interseccion(const Diccionario & D);


    /**
     Devuelve un diccionario con las claves en el
     * 	intervalo [i,f)

     */

    Diccionario Devolver_rango(const T &i, const T & f);


    /** Funciones begin y end para los iteradores**/

    iterator begin();

    iterator end();

    const_iterator begin() const;

    const_iterator end() const;

};


//cosa de gpt
#include "../src/diccionario.cpp"
#endif
