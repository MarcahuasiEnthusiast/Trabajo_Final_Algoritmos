#include <iostream>
#include <vector>
#include <string>
#include "Archivo.hpp"
#include "avl.hpp"


void bla(){
	cout << "Hola";
}

int main(){
	
	typedef AVLTree <Archivo*, string, nullptr> AVLNom;
	typedef AVLTree <Archivo*, string, nullptr> AVLExt;
	typedef AVLTree <Archivo*, int, nullptr> AVLTam;
	typedef AVLTree <Archivo*, int, nullptr> AVLFec;

	auto knom = [](Archivo * A) { return A->getnombre();    };
	auto kext = [](Archivo * A) { return A->getextension(); };
	auto ktam = [](Archivo * A) { return A->gettamano();    };
	auto kfec = [](Archivo * A) { return A->getfecha();     };

	AVLNom * avlnom = new AVLNom(knom);
	AVLExt * avlext = new AVLExt(kext);
	AVLTam * avltam = new AVLTam(ktam);
	AVLFec * avlfec = new AVLFec(kfec);


	auto Mostrar = [](Archivo * A){
		cout << " ( " << A->getnombre() << " , " << A->getextension() << " , " << A->gettamano() << " , " << A->getfecha() << " )" << endl;
	};

	//auto add = [&](Archivo * A)
	//{
	//	avlnom->add(A);
	//	avlext->add(A);
	//	avltam->add(A);
	//	avlfec->add(A);
	//};


	avlfec->add(new Archivo("Word", "txt", 112.85, 4)	);
	avlfec->add(new Archivo("Power", "ppt", 180.44, 5)	);
	avlfec->add(new Archivo("Word2", "txt", 90.10, 1)	);
	avlfec->add(new Archivo("Gaaa", "gaa", 64.44, 3)    );


	vector <Archivo*> V = avlfec->FiltradoMayor(5);

	cout << V.size();

	for (int i = 0; i < V.size(); i++){
		Mostrar(V[i]);
	}

	//Mostrar(avlnom->find("Gaaa"));

	system("pause");
	return 0;
}