#include "Tree.h"
#include "Clase_Explorador.h"
#include <iostream>
#include <dirent.h>
#include <string>

using namespace std;

void list_dir(string dir){
    DIR* directorio;
    struct dirent* elemento;
    string elem;
    if(directorio = opendir(dir.c_str())){
        while(elemento = readdir(directorio)){
            elem = elemento->d_name;
            cout<< elem << endl;
        }
    }
    closedir(directorio);
}

int main(){

    /*cout << "Ruta del directorio a listar: ";
    std::string dir;
    getline(cin, dir);
    list_dir(dir);

    typedef Tree<Explorador*, Tipo, nullptr> explorador;
    explorador* ex = new explorador([]  (Explorador* s){
        return s->getTipo();
    });

    ex->add(new Explorador(dir, Nombre));*/


    return 0;
}