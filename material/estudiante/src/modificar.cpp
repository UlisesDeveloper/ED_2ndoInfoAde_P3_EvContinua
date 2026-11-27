#include <iostream>
#include <fstream>
#include "guiatlf.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

    
    if (argc != 4){
        cout << "num de args incorrectos";
        return -1;
    }

    //ifstream guia(string(argv[1])), tlf(string(argv[2])); //ifstream necesita que sean strings normales no las de c

    ifstream guia(argv[1]);
    

    if(!guia){
        cout << "archivo no se ha podido abrir";
        return -2;
    }

    Guia_Tlf guiaTel;
    guia >> guiaTel;
    /*if(guiaTel.gettelefono(string(argv[2])) != ""){ //seguridad para no crear entrada por si no existe
        guiaTel[string(argv[2])] = string(argv[3]);
        
    }*/ //Se me ha olvidado modi

    guiaTel.modi(string(argv[2]), string(argv[3]));



    cout << guiaTel;
    return 0;
}