#include "guiatlf.h"


using namespace std;


string& Guia_Tlf::operator[](const string &nombre){
    return datos[nombre];
}


string Guia_Tlf::gettelefono(const string & nombre){
    string res= "";
    map<string,string>::iterator resBusqueda = datos.find(nombre);
    if(resBusqueda != datos.end()){
        res= (*resBusqueda).second;
    }
    return res;
}


pair<map<string,string>::iterator,bool>  Guia_Tlf::insert(string nombre, string tlf){
    return datos.insert({nombre,tlf });
}


pair<map<string,string>::iterator,bool>  Guia_Tlf::insert(pair<string,string> p){
    return datos.insert(p);
}

void Guia_Tlf::borrar(const string &nombre){
    datos.erase(nombre);
}

//tienen q coincidir nom y tlf
void Guia_Tlf::borrar(const string &nombre,const string &tlf){
    map<string, string>::iterator iter = datos.find(nombre);
    if(iter != datos.end() && (*iter).second == tlf){
        datos.erase(nombre);
    }
}


Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf & g){
    Guia_Tlf res = (*this);
    
    map<string,string>::const_iterator iter;
    for(iter = g.datos.begin(); iter !=g.datos.end(); ++iter){
        res.datos.emplace((*iter).first, (*iter).second);
    }
    return res;
}

Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf & g){
    Guia_Tlf res;
    map<string,string>::const_iterator iterThis, iterG;
    /*for(iterThis = datos.begin(); iterThis != datos.end(); ++iterThis){
        found = false;
        for(iterG = g.datos.begin(); iterG !=g.datos.end(); ++iterG){
            if((*iterThis).first == (*iterG).first){
                found = true;
            }
        }
        if(!found){
            res.insert({(*iterThis).first,(*iterThis).second});
        }
    }
    */
    //mejor usar find que se me ha olvidao
    for(iterThis = datos.begin(); iterThis != datos.end(); ++iterThis){
        iterG = g.datos.find((*iterThis).first);
        if(iterG == g.datos.end()){
            res.datos.insert({(*iterThis).first, (*iterThis).second});
        }
    }
    return res;
}


Guia_Tlf Guia_Tlf::previos(const string &nombre,const string &tlf){
    //ret guia con todos los elementos hasta nombre
    Guia_Tlf res;
    //auto mas rapido que escribir lo de map ite
    auto iter = datos.find(nombre);
    if(iter != datos.end() && (*iter).second == tlf){
        auto iterRecorrer = datos.begin();
        while(iterRecorrer != iter){
            res.insert({(*iterRecorrer).first, (*iterRecorrer).second});
            ++iterRecorrer;
        }
    }
    return res;
}


Guia_Tlf Guia_Tlf::inter(const Guia_Tlf & g){
    //lo comun 
    //Supongo que interseccion es cuando coincide el nombre y el telefono
    //si veo que falla solo hacer que coincida el nombre
    Guia_Tlf res;
    map<string,string>::const_iterator iterThis, iterG;
    for(iterThis = datos.begin(); iterThis != datos.end(); ++iterThis){
        iterG = g.datos.find((*iterThis).first);
        if(iterG != g.datos.end() && (*iterG).second == (*iterThis).second){
            res.datos.insert({(*iterThis).first, (*iterThis).second});
        }
    }
    return res;
}


void Guia_Tlf::modi(const string &nombre, const string &newtlf){
    auto iter = datos.find(nombre);
    if(iter != datos.end()){
        (*iter).second = newtlf;
    }
}


Guia_Tlf Guia_Tlf::filtro(const string & c){
    Guia_Tlf res;
    //const char* cenc= c.c_str(); //string de c 
    //no hace falta se puede [] con strings normales y hay starts_with() para strings

    for(auto it = datos.begin(); it!= datos.end(); ++it){
        if((*it).first.starts_with(c)){
            res.insert({(*it).first, (*it).second});
        }
    }
    return res;

}

//poner guia_tlf:: si no piensa que se refiere a iterator normal de la stl

Guia_Tlf::iterator Guia_Tlf::begin(){
    iterator a(datos.begin());
    return a;
}

Guia_Tlf::iterator Guia_Tlf::end(){
    iterator a(datos.end());
    return a;
}




ostream & operator<<(ostream & os, Guia_Tlf & g){
    for(auto it= g.datos.begin(); it != g.datos.end(); ++it){
        os << (*it).first << '\t'<< (*it).second << '\n';
    }
    return os;
}

istream & operator>>(istream & is, Guia_Tlf & g){
    string lecturaNom, lecturaTlf;
    //para no hacer cosas raras tener contador interno de si es 1er o 2nd elemento
    /*int count = 0;
    pair<map<string,string>::iterator, bool> resUltInsertado;
    while(is >> lectura){
        if(count % 2 == 0){
            resUltInsertado = g.datos.emplace(lectura, "");
        } else {
            (*(resUltInsertado.first)).second = lectura;
        }
        count++;
    }*/ //NO SIRVE Pq estan separados por tab las entradas y aparte si es nom con apellidos como en los .txt falla

    while(getline(is, lecturaNom, '\t') && getline(is, lecturaTlf)){ //no tiene tab que buscar el tlf por lo que esta bien si obtiene el resto q queda de la linea
        if(!lecturaTlf.empty() && lecturaTlf.back() == '\r'){ //he puesto lo de \r porque se quedaba y era feo
            //popback quita el ultimo char de la string
            lecturaTlf.pop_back();
        }
        g.datos[lecturaNom] = lecturaTlf;
        
    }

    return is;
}


istream & operator>>(istream 
&is,pair<string,string> &d){
  getline(is,d.first,'\t');
  getline(is,d.second);
  return is;
}