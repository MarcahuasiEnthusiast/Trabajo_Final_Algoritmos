#pragma once
#include "Tree.hpp"
#include <iostream>
#include <string>

enum Tipo{Nombre, Extension, Tamano, fecha_creacion};

class Explorador{
    std::string direccion_arch;
    Tipo tipo;
public:
    Explorador(std::string direccion_arch, Tipo tipo) 
    : direccion_arch(direccion_arch), tipo(tipo){ }

    std::string getDirec(){ return direccion_arch;}
    Tipo getTipo(){ return tipo;}

    void setDirec(std::string direccion_arch){
        this->direccion_arch = direccion_arch;
    }
    void setTipo(Tipo tipo){
        this->tipo = tipo;
    }

};
