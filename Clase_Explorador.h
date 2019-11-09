#include "Tree.h"
#include <iostream>
#include <string>

enum Tipo{Nombre, Extension, Tamano, fecha_creacion};

class Explorador{
    string direccion_arch;
    Tipo tipo;
public:
    Explorador(string direccion_arch, Tipo tipo) 
    : direccion_arch(direccion_arch), tipo(tipo){ }

    string getDirec(){ return direccion_arch;}
    Tipo getTipo(){ return tipo;}

    void setDirec(string direccion_arch){
        this->direccion_arch = direccion_arch;
    }
    void setTipo(Tipo tipo){
        this->tipo = tipo;
    }

};