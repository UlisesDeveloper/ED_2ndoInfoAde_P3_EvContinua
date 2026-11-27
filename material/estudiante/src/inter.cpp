#include <iostream>
#include <fstream>
#include "guiatlf.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

    //supongo que se refiere a que el archivo de guia solo tiene los nombres
    //y el otro fichero es de solo tlfns
    //NO SON 2 guias distinta
    if (argc != 3){
        cout << "num de args incorrectos";
        return -1;
    }

    //ifstream guia(string(argv[1])), tlf(string(argv[2])); //ifstream necesita que sean strings normales no las de c

    ifstream guia(argv[1]), guia2(argv[2]);
    

    if(!guia || !guia2){
        cout << "archivo no se ha podido abrir";
        return -2;
    }

    Guia_Tlf guiaTel,guiaTel2,res;
    guia >> guiaTel;
    guia2 >> guiaTel2;
    res = guiaTel.inter(guiaTel2);

    cout << res;
    return 0;
}