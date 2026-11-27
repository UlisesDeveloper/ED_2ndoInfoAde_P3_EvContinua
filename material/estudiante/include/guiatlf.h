/**
 * @ file : guiatlf.h
 * @brief: TDA guia de telefonos
 * */

#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>
using namespace std;




/**
  *  @brief T.D.A. Guia_Tlf
  *
  * Una instancia @e c del tipo de datos abstracto @c Guia_Tlf es un objeto
  * formado por una colección de pares {(e11,e21),(e12,e22),(e13,e23),...,(e1n-1,e2n-1)}
  * ordenados por la el primer elemento del par denominado clave o key. No existen
  * elementos repetidos.
  *
  *
  * Un ejemplo de su uso:
  *
  *
  * @author Rosa Rodríguez
  * @date Marzo 2012
  */

class Guia_Tlf{
  /**
  * @page repGuia_Tlf Rep del TDA Guia_Tlf
  *
  * @section invGuia_Tlf Invariante de la representación
  *
  * El invariante es \e para todo \e i y \e j tal que i<j entonces \e e1i y e1j son distintos
  *
  * @section faGuia_Tlf Función de abstracción
  *
  * Un objeto válido @e rep del TDA Guia_Tlf representa al valor
  *
  * {(rep.begin().first,rep.begin().second),(rep.begin()+1.first,rep.begin()+1.second),....,(rep.begin()+n-1.first,rep.begin()+n-1.second)}
  *
  */
private:
	map<string,string> datos; //si admites que haya nombres repetidos tendrías que usar un
					     //multimap
               //dice que no puede haber repetidos nombres

public:

  /**
  @brief Acceso a un elemento
  @param nombre: nombre del elemento  elemento acceder
  @return devuelve el valor asociado a un nombre, es decir el teléfono
  */
  //si fuese un multimap no podriamos usar []. Ademas que deberiamos devolver p.e un vector con todos
  // los telefonos asociados a dicho nombre
string & operator[](const string &nombre);

//Otra version Con iteradores, supongo que sin modificar

/**
  @brief Acceso a un elemento sin crearlo en caso de que no exista 
  @param nombre: nombre del elemento  elemento acceder
  @return devuelve el valor asociado a un nombre, es decir el teléfono
  */
string  gettelefono(const string & nombre);

  /**
  @brief Insert un nuevo telefono
  @param nombre: nombre clave del nuevo telefono
  @param tlf: numero de telefono
  @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha ins
  insertado el nuevo tlf o false en caso contrario
  */
pair<map<string,string>::iterator,bool>  insert(string nombre, string tlf);

  /**
  @brief Insert un nuevo telefono
  @param p: pair con el nombre y el telefono asociado
  @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha
  insertado el nuevo tlf o false en caso contrario
  */
pair<map<string,string>::iterator,bool>  insert(pair<string,string> p);

  /**
  @brief Borrar un telefono
  @param nombre: nombre que se quiere borrar
  @note: en caso de que fuese un multimap borraria todos con ese nombre
  */
void borrar(const string &nombre);

  /**
  @brief Borrar un telefono
  @param nombre: nombre que se quiere borrar y telefono asociado
  @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
  */
  //con map siempre hay uno con multimap puede existir mas de uno
void borrar(const string &nombre,const string &tlf);

  /**
  @brief  Numero de telefonos
  @return el numero de telefonos asociados
  */
int size()const{return datos.size();}

  /**
  @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
  @param nombre: nombre sobre el que queremos consultar
  @return numero de telefonos asociados a un nombre
  */
//al ser un map debe de ser 0 o 1. Si fuese un multimap podríamos tener mas de uno
unsigned int contabiliza(const string &nombre){return datos.count(nombre);}

  /**
  @brief Limpia la guia
  */
void clear(){datos.clear();}

  /**
  @brief Union de guias de telefonos
  @param g: guia que se une
  @return: una nueva guia resultado de unir el objeto al que apunta this y g
  */
Guia_Tlf operator+(const Guia_Tlf & g);

  /**
  @brief Diferencia de guias de telefonos
  @param g: guia a restar
  @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
  */
Guia_Tlf operator-(const Guia_Tlf & g);

  /**
  @brief  Obtiene una guia con los nombre previos a uno dado
  @param nombre: nombre delimitador
  @param tlf: telefono asociado a nombre
  @return nueva guia sin nombres mayores que \a  nombre
  */
Guia_Tlf previos(const string &nombre,const string &tlf);

  /**
  @brief Interseccion de guias de telefonos
  @param g  guia a hacer la interseccion con la guia apuntada por this
  @return: una nueva guia resultado de la interseccion del objeto al que apunta this y g
  */
Guia_Tlf inter(const Guia_Tlf & g);

  /**
  @brief Modificamos el telefono asociado a un nombre
  @param nombre es el nombre al que le vamos a cambiar el telefono
  @param newtlf es el nuevo telefono para ese nombre
  @return Nada
  */
void modi(const string &nombre, const string &newtlf);

  /**
  @brief obtiene una guia con los nombres que comiencen por un string
  @param c string con el comienzo de los nombres
  @return: una nueva guia con los nombres que comienzan por c
  */
Guia_Tlf filtro(const string & c);

  /**
  @brief Escritura de la guia de telefonos
  @param os: flujo de salida. Es MODIFICADO
  @param g: guia de telefonos que se escribe
  @return el flujo de salida
  */
friend ostream & operator<<(ostream & os, Guia_Tlf & g);

  /**
  @brief Lectura de  la guia de telefonos
  @param is: flujo de entrada. ES MODIFICADO
  @param g: guia de telefonos. ES MODIFICADO
  @return el flujo de entrada
  */
friend istream & operator>>(istream & is, Guia_Tlf & g);

/**
 * 
 * @brief lectura de pareja de strigns
 * @param is flujo de entrada.
 * @param d par de datos al que escribir de entrada
 * 
 * @details no es de la clase directamente pero podria ser util por eso esta como friend
 * @return flujo de entrada
 */
friend istream & operator>>(istream &is,pair<string,string> &d);

  /**
  * @brief clase para iterar sobre la guia
  * */
class iterator{
   private:
    /**
    * @brief iterador de map<string,string>
    */
    map<string,string>::iterator it;
  public:
    /**
    * @brief Constructor por defecto (vacio)
    */
    iterator(){}
    /**
    * @brief Constructor por copia de iterador real que tiene el datos de guiatlf
    *
    * @param otro iterador a map<string,string>
    */
    iterator(const map<string,string>::iterator& otro):it(otro){}
    /**
    * @brief Constructor por copia de instancia de clase iterator de guiatlf
    *
    * @param otro iterator de la clase de Guia_Tlf
    */
    iterator(const iterator& otro):it(otro.it){}
    /**
    * @brief Destructor
    */
    ~iterator(){}
    /**
    * @brief Operador de asignacion mediante iterador de map<string,string>
    *
    * @param otro iterator de map<string,string>
    * @return referencia a iterator para permitir encadenar asignaciones
    */
    iterator& operator=(const map<string,string>::iterator& otro){it=otro;return *this;}
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
    * @return par de string constante de la key y del value la otra string
    */
    pair<const string, string>& operator*() const {return *it;}
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
    * @return bool true si son distintos, false si son los mismos
    */
    bool operator!=(const iterator& otro) const {return it != otro.it;}
    /**
    * @brief Operador de comparacion de igualdad
    *
    * @param otro iterador de comparacion
    * @return bool true si se refieren al mismo, false si no
    */
    bool operator==(const iterator& otro) const {return it == otro.it;}
};

  /**
  * @brief Inicializa un iterator al comienzo de la guia
  * */
iterator  begin();

  /**
  * @brief Inicializa un iterator al final de la guia
  * */
iterator  end();




}; //del class Guia_Tlf


/**
  @brief Escritura de la guia de telefonos
  @param os: flujo de salida. Es MODIFICADO
  @param g: guia de telefonos que se escribe
  @return el flujo de salida
  */
ostream & operator<<(ostream & os, Guia_Tlf & g);
/**
  @brief Lectura de  la guia de telefonos
  @param is: flujo de entrada. ES MODIFICADO
  @param g: guia de telefonos. ES MODIFICADO
  @return el flujo de entrada
  */
istream & operator>>(istream & is, Guia_Tlf & g);

/**
 * 
 * @brief lectura de pareja de strigns
 * @param is flujo de entrada.
 * @param d par de datos al que escribir de entrada
 * 
 * @details no es de la clase directamente pero podria ser util por eso esta como friend
 * @return flujo de entrada
 */
istream & operator>>(istream 
&is,pair<string,string> &d);
#endif

