#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

//NOT SURE IF I SHOULD FIX PUTTING THE CONST IN WORDS OF LENGTH
//getoccurrences


#include <set>
#include <string>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */
class Dictionary{
private:
  set<string> words;
public:

  /**
   * @brief Constructor por defecto
   *
   * Crea un Dictionary vacío
   */
  Dictionary();

  /**
   * @brief Constructor de copia
   *
   * Crea un Dictionary con el mismo contenido que el que se pasa como argumento
   *
   * @param other Dictionary que se quiere copiar
   */
  Dictionary(const Dictionary& other);

  /**
   * @brief Destructor
   *
   * Limpia todos los elementos del Dictionary antes de borrarlo
   */
  ~Dictionary();

  /**
   *  \brief Limpia el Dictionary
   *
   *  Elimina todas las palabras contenidas en el conjunto
   */
  void clear();

  /**
   * @brief Tamaño del diccionario
   *
   * @return Número de palabras guardadas en el diccionario
   */
  unsigned int size()const;

  /**
   * @brief Devuelve las palabras en el diccionario con una longitud dada
   * @param length Longitud de las palabras buscadas
   * @return Vector de palabras con la longitud desdeada
   */
  vector<string> wordsOfLength(int length); 

  /**
   * @brief Indica si una palabra esta en el diccionario o no.
   *
   * Este método comprueba si una determinada palabra se encuentra o no en el dicccionario
   *
   * @param palabra: la palabra que se quiere buscar.
   * @return Booleano indicando si la palabra existe o no en el diccionario
   */
  bool exists(const string& val)const{return words.count(val) > 0;}

  /**
   * @brief Indica el numero de apariciones de una letra.
   * @param c letra a buscar.
   * @return Un entero indicando el numero de apariciones.
   */
  int getOccurrences(const char c);

  /**
   * @brief Añade al diccionario actual el que se pasa como argumento
   * @param dic diccionario pasado como argumento.
   */
  void anade(const Dictionary &dic);

  /**
   * @brief Comprueba si el diccionario está vacio.
   * @return true si el diccionario está vacío, false en caso contrario
   */
  bool empty()const{return words.empty();}

  /**
   * @brief Elimina una palabra del diccionario
   *
   * @param val Palabra a borrar del diccionario
   *
   * @return Booleano que indica si la palabra se ha borrado del diccionario
   */
  bool erase(const string &val){return words.erase(val) > 0;}

  /**
   * @brief Inserta una palabra en el diccionario
   *
   * @param val palaba a insertar en el diccionario
   * @return Booleano que indica si la inserción ha tenido éxito. Una palabra se inserta
   * con éxito si no existía previamente en el diccionario
   */
  bool insert(const string &val);


  /**
   * @brief Sobrecarga del operador de asignación
   */
  Dictionary& operator=(const Dictionary &dic);

  /**
   * @brief Sobrecarga del operador de entrada
   *
   * Permite leer las palabras de un fichero de texto e introducirlas en el
   * diccionario
   *
   * @param is Flujo de entrada
   * @param dic Diccionario a rellenar
   * @return Flujo de entrada para poder encadenar el operador
   */
  friend istream& operator>>(istream &is, Dictionary &dic);

  /**
   * @brief Sobrecarga del operador de salida
   *
   * Permite imprimir el diccionario completo a un flujo de salida
   *
   * @param os Flujo de salida, donde imprimir el diccionario
   * @param dic Diccionario a imprimir
   * @return Flujo de salida, para poder encadenar el operador
   */
  friend ostream& operator<<(ostream &os, const Dictionary &dic);

  /**
    * @brief clase del iterador para recorrer el diccionario 
  */
  class iterator{
  private:
    /**
    * @brief iterador de set<string>
    */
    set<string>::iterator it;
  public:
    /**
    * @brief Constructor por defecto (vacio)
    */
    iterator(){}
    /**
    * @brief Constructor por copia de iterador real que tiene el diccionario
    *
    * @param otro iterador a set<string>
    */
    iterator(const set<string>::iterator& otro):it(otro){}
    /**
    * @brief Constructor por copia de instancia de clase iterator de Dictionary
    *
    * @param otro iterator de la clase de Dictionary
    */
    iterator(const iterator& otro):it(otro.it){}
    /**
    * @brief Destructor
    */
    ~iterator(){}
    /**
    * @brief Operador de asignacion mediante iterador de set<string>
    *
    * @param otro iterator de set<string>
    * @return referencia a iterator para permitir encadenar asignaciones
    */
    iterator& operator=(const set<string>::iterator& otro){it=otro;return *this;}
    /**
    * @brief Operador de asignacion mediante instancia de clase iterator de Dictionary
    *
    * @param otro iterator de la clase de Dictionary
    * @return referencia a iterator para permitir encadenar asignaciones
    */
    iterator& operator=(const iterator& otro){it=otro.it;return *this;}
    /**
    * @brief Operador de referencia
    *
    * es const porque dentro de la funcion no se modifica nada
    *
    * @return elemento al que apunta el iterador
    */
    string operator*()const{return *it;}
    /**
    * @brief Operador de preaumento en 1
    *
    * Aumenta en 1 el iterador para que apunte/se refiera al siguiente elemento
    *
    * @return referencia al iterador
    */
    iterator& operator++(){++it;return *this;}
    /**
    * @brief Operador de predecremento en 1
    *
    * Decrementa en 1 el iterador para que apunte/se refiera al elemento anterior
    *
    * @return referencia al iterador
    */
    iterator& operator--(){--it;return *this;}
    /**
    * @brief Operador de postaumento en 1
    *
    * Aumenta en 1 el iterador para que apunte/se refiera al siguiente elemento
    *
    * @param int para que se entienda que es para postaumento
    * @return referencia al iterador
    */
    iterator& operator++(int){it++;return *this;}
    /**
    * @brief Operador de postdecremento en 1
    *
    * Decrementa en 1 el iterador para que apunte/se refiera al elemento anterior
    *
    * @param int para que se entienda que es para postaumento
    * @return referencia al iterador
    */
    iterator& operator--(int){it--;return *this;}
    /**
    * @brief Operador de comparacion de desigualdad
    *
    * @param otro iterador de comparacion
    * @return @return bool true si son distintos, false si son los mismos
    */
    bool operator!=(const iterator& otro){return it != otro.it;}
    /**
    * @brief Operador de comparacion de igualdad
    *
    * @param otro iterador de comparacion
    * @return bool true si se refieren al mismo, false si no
    */
    bool operator==(const iterator& otro){return it == otro.it;}
  };

  /**
   * @brief clase del const_iterador para recorrer el dictionary
   */
  class const_iterator{
  private:
    /**
    * @brief const_iterator de set<string>
    */
    set<string>::const_iterator const_it;
  public:
    /**
    * @brief Constructor por defecto (vacio)
    */
    const_iterator(){}
    /**
    * @brief Constructor por copia de const_iterador real que tiene el diccionario
    *
    * @param otro const_iterator a set<string>
    */
    const_iterator(const set<string>::const_iterator& otro):const_it(otro){}
    /**
    * @brief Constructor por copia de instancia de clase const_iterator de Dictionary
    *
    * @param otro const_iterator de la clase de Dictionary
    */
    const_iterator(const const_iterator& otro):const_it(otro.const_it){}
    /**
    * @brief Destructor
    */
    ~const_iterator(){}
    /**
    * @brief Operador de asignacion mediante const_iterator de set<string>
    *
    * @param otro const_iterator de set<string>
    * @return referencia a const_iterator para permitir encadenar asignaciones
    */
    const_iterator& operator=(const set<string>::const_iterator& otro){const_it = otro;return *this;}
    /**
    * @brief Operador de asignacion mediante instancia de clase const_iterator de Dictionary
    *
    * @param otro const_iterator de la clase de Dictionary
    * @return referencia a const_iterator para permitir encadenar asignaciones
    */
    const_iterator& operator=(const const_iterator& otro){const_it = otro.const_it;return *this;}
    /**
    * @brief Operador de referencia
    *
    * es const porque dentro de la funcion no se modifica nada
    * y const el dato de retorno para que no se permita la modificacion
    *
    * @return elemento al que apunta el const_iterator
    */
    const string operator*()const{return *const_it;}
    /**
    * @brief Operador de preaumento en 1
    *
    * Aumenta en 1 el const_iterator para que apunte/se refiera al siguiente elemento
    *
    * @return referencia al const_iterator
    */
    const_iterator& operator++(){++const_it;return *this;}
    /**
    * @brief Operador de predecremento en 1
    *
    * Decrementa en 1 el const_iterador para que apunte/se refiera al elemento anterior
    *
    * @return referencia al const_iterador
    */
    const_iterator& operator--(){--const_it;return *this;}
    /**
    * @brief Operador de postaumento en 1
    *
    * Aumenta en 1 el const_iterador para que apunte/se refiera al siguiente elemento
    *
    * @param int para que se entienda que es para postaumento
    * @return referencia al const_iterador
    */
    const_iterator& operator++(int){const_it++;return *this;}
    /**
    * @brief Operador de postdecremento en 1
    *
    * Decrementa en 1 el const_iterador para que apunte/se refiera al elemento anterior
    *
    * @param int para que se entienda que es para postaumento
    * @return referencia al const_iterador
    */
    const_iterator& operator--(int){const_it--;return *this;}
    /**
    * @brief Operador de comparacion de desigualdad
    *
    * @param otro const_iterador de comparacion
    * @return bool true si son distintos, false si son los mismos
    */
    bool operator!=(const const_iterator& otro){return const_it != otro.const_it;}
    /**
    * @brief Operador de comparacion de igualdad
    *
    * @param otro const_iterador de comparacion
    * @return bool true si se refieren al mismo, false si no
    */
    bool operator==(const const_iterator& otro){return const_it == otro.const_it;}
  };

  iterator begin(){iterator i = words.begin();return i;}
  iterator end(){iterator i = words.end();return i;}
  const_iterator begin()const{const_iterator i = words.begin();return i;}
  const_iterator end()const{const_iterator i = words.end();return i;}

};

/**
   * @brief Sobrecarga del operador de entrada
   *
   * Permite leer las palabras de un fichero de texto e introducirlas en el
   * diccionario
   *
   * @param is Flujo de entrada
   * @param dic Diccionario a rellenar
   * @return Flujo de entrada para poder encadenar el operador
   */
istream& operator>>(istream &is, Dictionary &dic);

/**
   * @brief Sobrecarga del operador de salida
   *
   * Permite imprimir el diccionario completo a un flujo de salida
   *
   * @param os Flujo de salida, donde imprimir el diccionario
   * @param dic Diccionario a imprimir
   * @return Flujo de salida, para poder encadenar el operador
   */
ostream& operator<<(ostream &os, const Dictionary &dic);

#endif
