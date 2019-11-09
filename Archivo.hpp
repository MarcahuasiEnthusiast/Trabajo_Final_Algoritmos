#pragma once

#include <string>

using namespace std;
//using namespace System;

class Archivo
{
private:
	string	nombre		;
	string	extension	;
	float	tama�o		;
	int		fecha		; // 20190402
public:

	Archivo(string nom, string ext, float tam, int fec)
	{
		nombre = nom;
		extension = ext;
		tama�o = tam;
		fecha = fec;
	}


	string	getnombre	 	() {return nombre		;}
	string	getextension  	() {return extension	;}
	float	gettama�o		() {return tama�o		;}
	int		getfecha		() {return fecha		;}

	void setnombre		(string	nombre		) { this->nombre		= nombre	;}	
	void setextension	(string	extension	) { this->extension	= extension	;}
	void settama�o		(float	tama�o		) { this->tama�o		= tama�o	;}	
	void setfecha		(int	fecha		) { this->fecha		= fecha		;}

};