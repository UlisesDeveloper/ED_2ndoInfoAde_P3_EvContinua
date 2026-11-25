#include <iostream>
#include "dictionary.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

    
    if(argc != 3){
        cout << "no sigue formato de entrada";
        return -1;        
    } 

    int numericArg = atoi(argv[2]);
    Dictionary a;
    ifstream file(argv[1]);
    if(!file){
        cout << "archivo de 1er arg de entrada no accesible";
        return -3;
    }
    file >> a;
    vector<string> res = a.wordsOfLength(numericArg);
    for(vector<string>::const_iterator i = res.begin(); i != res.end(); ++i){
        cout << (*i) << '\n';
    }
    return 0;
}