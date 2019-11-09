#include <iostream>
#include <vector>
#include "Archivo.hpp"
#include "BST.hpp"
#include <dirent.h>

// para listar los archivos 
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

int main()
{
	vector <Archivo> V;
	
	Tree <float>* T1 = new Tree <float> ();
	Tree <float>* T2 = new Tree <float>();
	Tree <string>* T3 = new Tree <string>();

	int f, f2;
	float f3;
	string f4;


	V.push_back(Archivo("Word", "txt", 112.85, 20190804));
	V.push_back(Archivo("Power", "ppt", 180.44, 20150804));
	V.push_back(Archivo("Word2", "txt", 90.10, 20140804));
	V.push_back(Archivo("Gaaa", "gaa", 64.44, 20110804));


	cout << "Desea ordenar por peso (1) o por fecha (2) o por extension (3)"<<endl;
	cin >> f;

	if (f == 1){
		
		for (int i = 0; i < V.size(); i++){
			T1->add(V[i].gettamano());
		}
		cout << "Que desea buscar?" << endl;
		cin >> f2;
		cout << T1->find(f2);
	}
	else if (f ==2){
		
		for (int i = 0; i < V.size(); i++){
			T2->add(V[i].getfecha());
		}
		cout << "Que desea buscar?" << endl;
		cin >> f3;
		cout <<  T2->find(f3);
	}
	else if (f == 3){
		for (int i = 0; i < V.size(); i++){
			T3->add(V[i].getextension());
		}
		cout << "Que desea buscar?" << endl;
		cin >> f4;
		cout << T3->find(f4);
	}
	else{
		return 0;
	}

	system("pause > 0");
	return 0;
}