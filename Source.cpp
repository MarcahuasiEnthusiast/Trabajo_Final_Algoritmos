#include <iostream>
#include <vector>
#include <string>
#include "Archivo.hpp"
#include "avl.hpp"

int main(){
	
	typedef AVLTree <Archivo*, string, nullptr> AVLNom;
	typedef AVLTree <Archivo*, string, nullptr> AVLExt;
	typedef AVLTree <Archivo*, int,    nullptr> AVLTam;
	typedef AVLTree <Archivo*, int,    nullptr> AVLFec;

	auto knom = [](Archivo * A) { return A->getnombre(); };
	auto kext = [](Archivo * A) { return A->getextension(); };
	auto ktam = [](Archivo * A) { return A->gettamano(); };
	auto kfec = [](Archivo * A) { return A->getfecha(); };

	AVLNom * avlnom = new AVLNom(knom);
	AVLExt * avlext = new AVLExt(kext);
	AVLTam * avltam = new AVLTam(ktam);
	AVLFec * avlfec = new AVLFec(kfec);


	auto Mostrar = [](Archivo * A)
	{
		cout << " ( " << A->getnombre() << " , " << A->getextension() << " , " << A->gettamano() << " , " << A->getfecha() << " )" << endl;
	};

	avlfec->add(new Archivo("Gaaa", "gaa", 64.44, 9));
	avlfec->add(new Archivo("Word", "txt", 112.85, 4)	);
	avlfec->add(new Archivo("Power", "ppt", 180.44, 5)	);
	avlfec->add(new Archivo("Word2", "txt", 90.10, 1)	);
	avlfec->add(new Archivo("Gaaa", "gaa", 64.44, 3)  );
	avlfec->add(new Archivo("Gaaa", "gaa", 64.44, 7));

	//string aux ("Word ");
	//string aux2("Power");
	//string aux3("Word2");
	//string aux4("Gaaa ");
//
	//string a = aux.substr ( aux.length() - 1, 1);
	//string b = aux2.substr(aux2.length() - 1, 1);
	//string c = aux3.substr(aux3.length() - 1, 1);
	//string d = aux4.substr(aux4.length() - 1, 1);



	vector <Archivo*> V = avlfec->antiinorderV();

	//avlfec->inorder(Mostrar);

	for (int i = 0; i < V.size(); i++)
	{
		Mostrar(V[i]);
	}

	//Mostrar(avlnom->find("Gaaa"));

	system("pause");
	return 0;
}