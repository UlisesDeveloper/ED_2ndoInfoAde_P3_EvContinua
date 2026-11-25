#include <iostream>
#include "dictionary.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

   if(argc != 3){
        cout << "no sigue formato de entrada";
        return -1;        
    } 

    
    Dictionary a;
    ifstream file(argv[1]);
    ifstream fileUnion(argv[2]);
    if(!file || !fileUnion){
        cout << "archivo de 1er/2ndo arg de entrada no accesible";
        return -3;
    }
    file >> a;
    fileUnion >> a;
    
    //no pone nada de salida pero supongo q si no no se puede comprobar
    cout << a;
    
    return 0;
}