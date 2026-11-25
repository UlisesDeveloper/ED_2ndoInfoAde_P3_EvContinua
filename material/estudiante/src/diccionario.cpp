#include "diccionario.h"

template <class T, class U>
void Diccionario<T,U>::Copiar(const Diccionario<T, U>& D){
    //supongo que por copiarlo habra que eliminar la lista que ya teniamos
   if(this == &D){
        datos = D;

    }
}

template <class T, class U>
void Diccionario<T,U>::Borrar() {
    datos.clear();
}

template <class T, class U>
Diccionario<T,U>::Diccionario() {
    //supongo que lo dejo vacio ya que no hay elementos 
}

template <class T, class U>
Diccionario<T,U>::Diccionario(const Diccionario &D){
    (*this).Copiar(D);
}

template <class T, class U>
Diccionario<T,U>::~Diccionario(){
    //supongo que quiere el destructor que borre los datos aunque se hace automaticamente
    (*this).Borrar();
}


template <class T, class U>
Diccionario<T, U>& Diccionario<T,U>::operator=(const Diccionario<T, U> &D){
    (*this).Copiar(D);
}

template <class T, class U>
bool Diccionario<T,U>::Esta_Clave(const T &p, typename Diccionario<T,U>::iterator &it_out){
    bool found = false;
    bool exitLoop = false;
    it_out = datos.end(); //por si acaso
    for( typename list<data<T, U>>::iterator it = datos.begin(); it != datos.end() && !exitLoop; ++it){
        if((*it).clave == p){
            found = true; exitLoop = true;
            it_out = it;
        } else if ((*it).clave >= p){
            //se ha pasado por lo que ya no lo vamos a encontrar
            exitLoop = true;
            it_out = it;
        }
    }
   
    return found;
}

template <class T, class U>
void Diccionario<T,U>::Insertar(const T& clave, const list<U> &info){
    //no estamos en set es un list permite duplicados usamos la funcion esta_clave
    //para asegurarnos de que no este
    iterator posInsertar;
    if(!Esta_Clave(clave, posInsertar)){ //Colocarlo en la posicion que nos diga 
        data<T, U> nuevo;
        nuevo.clave = clave;
        nuevo.info_asoci = info;
        datos.insert(posInsertar.iterador, nuevo); //exterior no puede acceder datos privados del interior sin friend, al reves si 
    } //supongo que si ya esta la clave no quiero cambiar su info_asociada
}

template <class T, class U>
void Diccionario<T,U>::AddSignificado_Palabra(const U & s, const T &p){
    bool encontrado = false;
    bool salir =false;
    typename list<data<T, U>>::iterator itInsNoEncontrado = datos.end();
     
    for(typename list<data<T, U>>::iterator it = datos.begin(); it != datos.end() && !salir; ++it ){
        if((*it).clave == p){
            encontrado = true; salir = true;
            (*it).info_asoci.push_back(s);
        }

        if((*it).clave > p){ //no se va a encontrar porque ya no hemos pasado de letra
            itInsNoEncontrado = it;
            salir = true;
        }
    }

    if(!encontrado){ //no estaba por lo que simplemente insertamos en el sitio correcto
        data<T,U> nuevo;
        nuevo.clave = p;
        nuevo.info_asoci.push_back(s);
        itInsNoEncontrado = datos.insert(itInsNoEncontrado, nuevo);
    }
}

template <class T, class U>
list<U> Diccionario<T,U>::getInfo_Asoc(const T & p){
    list<U> res; //si no hay ninguna clave se devolvera simplemente una vacia
    iterator pos;
    if(Esta_Clave(p, pos)){
        res = (*pos).info_asoci;
    }

    return res;
}

template <class T, class U>
int Diccionario<T,U>::size()const{
    return datos.size();
}

template <class T, class U>
bool Diccionario<T,U>::Borrar(const T & c){
    iterator pos;
    bool esta = false;
    if(Esta_Clave(c, pos)){
        esta = true;
        datos.erase(pos.iterador);
    }
    return esta;
}

template <class T, class U>
Diccionario<T,U> Diccionario<T,U>::union_d(const Diccionario<T,U> & D){
Diccionario<T,U> res = (*this);
iterator actual;
for(const_iterator it = D.begin(); it != D.end(); ++it){
    bool estaClave = res.Esta_Clave((*it).clave, actual);
    if(estaClave){
        (*actual).info_asoci.insert((*actual).info_asoci.end(),(*it).info_asoci.begin(), (*it).info_asoci.end());
    } else {
        res.datos.insert(actual.iterador,(*it))
    }
}


return res;
}
