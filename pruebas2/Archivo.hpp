#pragma once

#include <string>

using namespace std;
using namespace System;

class Archivo
{
private:
	string	nombre		;
	string	extension	;
	float	tamaño		;
	int		fecha		; // 20190402
public:

	Archivo(string nom, string ext, float tam, int fec)
	{
		nombre = nom;
		extension = ext;
		tamaño = tam;
		fecha = fec;
	}


	string	getnombre	 	() {return nombre		;}
	string	getextension  	() {return extension	;}
	float	gettamaño		() {return tamaño		;}
	int		getfecha		() {return fecha		;}

	void setnombre		(string	nombre		) { this->nombre		= nombre	;}	
	void setextension	(string	extension	) { this->extension	= extension	;}
	void settamaño		(float	tamaño		) { this->tamaño		= tamaño	;}	
	void setfecha		(int	fecha		) { this->fecha		= fecha		;}

};