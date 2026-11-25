#include "dictionary.h"


using namespace std;


Dictionary::Dictionary(){

    //supongo que no hace mucho ya que el private lo crea vacio por defecto
}

//usaremos para el metodo del
Dictionary::Dictionary(const Dictionary& other){
    *this = other;
}


Dictionary::~Dictionary(){
    (*this).clear();
}

void Dictionary::clear(){
    words.clear();
}

unsigned int Dictionary::size() const{
    return words.size();
}

vector<string> Dictionary::wordsOfLength(int length){
    vector<string> res;
    if(!(length < 0)){
        //uso el iterador ya implementado mismo , si veo que hay problemas uso el vanilla
        for(const_iterator i = words.begin(); i != words.end(); ++i){
            //el *it es la string asi que ya puedo acceder los elementos
            if ((*i).length() ==  length){
                res.push_back(*i);
            }
        } 
    }

    return res;
}


int Dictionary::getOccurrences(const char c){
    int count = 0;
    for(const_iterator i = words.begin(); i != words.end(); ++i){
            //el *it es la string asi que ya puedo acceder los elementos
        for(size_t j = 0; j < (*i).length() ; j++){
            if ((*i)[j] == c) {
                    count++;
            }
        }
    } 
    return count;
}


void Dictionary::anade(const Dictionary &dic){
    if(&dic != this){
        words.insert(dic.words.begin(), dic.words.end());
    }
}

bool Dictionary::insert(const string &val){
    //solo quiero el bool para saber si se ha insertado o no
    pair <iterator, bool> status = words.insert(val);
    return status.second;
}


Dictionary& Dictionary::operator=(const Dictionary &dic){
    //primero comprobamos que no son iguales pq si no es perder el tiempo
    if((&dic != this)){
        //words.clear();
        //words.insert(dic.words.begin(), dic.words.end()); //si es insert de rango no devuelve nada creia q era pair
        

        //probar a ver si funciona automaticamente el operador
        words = dic.words;
    }

    return *this;
}


istream& operator>>(istream &is, Dictionary &dic) {
    string wordInsert = "";
    while(is >> wordInsert){ //era true solo si se llega a leer palabra
        dic.insert(wordInsert);
    }
    return is;
}

ostream& operator<<(ostream &os, const Dictionary &dic){
    //para usar una clase dentro de otra se usa clase::otra
    for(Dictionary::const_iterator i = dic.words.begin(); i != dic.words.end(); ++i){
        os << (*i) << '\n';
        //pongo /n para q haya salto y no esten pegados
    }
    return os;
}