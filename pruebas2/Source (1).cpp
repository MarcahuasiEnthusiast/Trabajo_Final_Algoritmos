#include <iostream>
#include <vector>
#include "Archivo.hpp"
//#include "BST.hpp"
#include "BSTArchivos.hpp"

int main()
{
	Tree T;

	int f, f2;
	float f3;
	string f4;

	auto px = [](Archivo s) {
		cout << "{"
			<< s.getnombre() << " "
			<< s.getextension() << " "
			<< s.gettamano() << " "
			<< s.getfecha() << "}\n";
	};

	T.addFec(Archivo("Word", "txt", 112.85, 20190804));
	T.addFec(Archivo("Power", "ppt", 180.44, 20150804));
	T.addFec(Archivo("Word2", "txt", 90.10, 20140804));
	T.addFec(Archivo("Gaaa", "chch", 1, 20110804));
	T.addFec(Archivo("Carajo!!!", "diceth", 64.44, 20131711));
	T.addFec(Archivo("auxilio!!!", "weed", 64.44, 20250606));
	T.addFec(Archivo("videoconferencia", "ovnis", 64.44, 20111004));

	/*T.findExt("txt");
	T.findTam(112.85);
	T.findFec(20110804);
	T.findNom("Word");*/

	T.inorder(px);

	/*cout << "Desea ordenar por peso (1) o por fecha (2) o por extension (3)"<<endl;
	cin >> f;

	if (f == 1)
	{
		
		for (int i = 0; i < V.size(); i++)
		{
			T1->add(V[i].gettama�o());
		}


		cout << "Qu� desea buscar?" << endl;
		cin >> f2;

		cout << T1->find(f2);
	}
	else if (f ==2)
	{
		
		for (int i = 0; i < V.size(); i++)
		{
			T2->add(V[i].getfecha());
		}

		cout << "Qu� desea buscar?" << endl;
		cin >> f3;

		cout <<  T2->find(f3);
	}
	else if (f == 3)
	{
		
		for (int i = 0; i < V.size(); i++)
		{
			T3->add(V[i].getextension());
		}

		cout << "Qu� desea buscar?" << endl;
		cin >> f4;

		cout << T3->find(f4);
	}
	else
	{
		return 0;
	}
*/


	system("pause");
	return 0;
}