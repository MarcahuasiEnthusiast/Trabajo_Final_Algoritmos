#pragma once
#include <iostream>
#include <string>


class Archivo{
	string nombre;
    string exten;
    int fech;
	float capacidad;
public:
	Archivo(string nombre, string exten, float capacidad, int fech)
	: nombre(nombre), capacidad(capacidad), fech(fech),exten(exten) { }

	string getNombre(){ return nombre; }
    string getExten(){ return exten; }
	float  getCapacidad(){return capacidad; }
    int    getFecha(){ return fech; }

	void setnombre(string nombre){
		this->nombre = nombre;
	}
    void setexten(string exten){
        this->exten = exten;
    }
	void setcapacidad(float capacidad){
		this->capacidad = capacidad;
	}
    void setfecha(int fech){
        this->fech = fech;
    }
};
