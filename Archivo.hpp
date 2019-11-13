#pragma once

#include <string>

using namespace std;
//using namespace System;

class Archivo{
private:
	string	nombre		;
	string	extension	;
	int	tamano		    ;
	int		fecha		; // 20190402
public:

	Archivo(string nom, string ext, int tam, int fec)
	{
		nombre = nom;
		extension = ext;
		tamano = tam;
		fecha = fec;
	}


	string	getnombre	 	() {return nombre		;}
	string	getextension  	() {return extension	;}
	int	    gettamano		() {return tamano		;}
	int		getfecha		() {return fecha		;}

	void setnombre		(string	nombre		) { this->nombre		= nombre	;}	
	void setextension	(string	extension	) { this->extension	= extension	    ;}
	void settamano		(int	tamano		) { this->tamano		= tamano	;}	
	void setfecha		(int	fecha		) { this->fecha		= fecha		    ;}

};