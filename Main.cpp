#include <iostream>
#include <vector>
#include "Tree.hpp"
#include "Clase_Explorador.hpp"
#include <dirent.h>

// para listar los archivos 
void list_dir(string dir){
    DIR* directorio;
    struct dirent* elemento;
    string elem;
    if(directorio = opendir(dir.c_str())){
        while(elemento = readdir(directorio)){
            elem = elemento->d_name;
        }
    }
    closedir(directorio);
}

int main(){
	typedef Tree<Archivo*, > Arbolito;
	Arbolito* t = new Arbolito([](Archivo* s){
		return s->getNombre();
	});

	t->add(new Archivo("Word" , "txt", 112.85, 20190804));
	t->add(new Archivo("Power", "ppt", 180.44, 20150804));
	t->add(new Archivo("Word2", "txt", 90.10 , 20140804));
	t->add(new Archivo("Gaaa" , "gaa", 64.44 , 20110804));

	auto px = [](Archivo* s){
		cout << "{" 
		<< s->getNombre() << " "
		<< s->getExten() << " "
		<< s->getCapacidad() << " "
		<< s->getFecha() << " }" << endl;
	};
	t->inOrder(px);

	delete t;


	/*V.push_back(Archivo("Word", "txt", 112.85, 20190804));
	V.push_back(Archivo("Power", "ppt", 180.44, 20150804));
	V.push_back(Archivo("Word2", "txt", 90.10, 20140804));
	V.push_back(Archivo("Gaaa", "gaa", 64.44, 20110804));*/

	system("pause > 0");
	return 0;
}