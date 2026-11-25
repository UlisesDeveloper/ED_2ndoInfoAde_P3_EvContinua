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
    if(!file){
        cout << "archivo de 1er arg de entrada no accesible";
        return -3;
    }
    file >> a;
    //hay que poner [0] aunque solo sea un arg
    cout << a.getOccurrences(argv[2][0]) << '\n';

    return 0;
}