#include <iostream>
#include <vector>
#include <string>
#include "Tree.hpp"
using namespace std;
//#include "BSTArchivos.hpp"
int main()
{
	//vector <Archivo> V;
	//
	//Tree <int>* T1 = new Tree <int> ();
	//Tree <float>* T2 = new Tree <float>();
	//Tree <string>* T3 = new Tree <string>();

	//Tree T;
	
	Tree <string> T;
	vector <char> V;

	string hola("holaa");
	char hola2 = hola.back();

	T.add(hola);
	T.add(hola);
	T.add(hola);
	T.add(hola);
	T.add(hola);
	T.add(hola);
	T.add(hola);

	//T.findDad(5);

	
	V = T.FiltrarMenor(hola2);
	//V = T.FiltrarMenor(5);

	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << endl;
	}



	int f, f2;
	float f3;
	string f4;





	//T.change();

	/*V.push_back(Archivo("Word", "txt", 112.85, 20190804));
	V.push_back(Archivo("Power", "ppt", 180.44, 20150804));
	V.push_back(Archivo("Word2", "txt", 90.10, 20140804));
	V.push_back(Archivo("Gaaa", "gaa", 64.44, 20110804));*/

	/*T.add(Archivo("Word", "txt", 112.85, 20190804));
	T.add(Archivo("Power", "ppt", 180.44, 20150804));
	T.add(Archivo("Word2", "txt", 90.10, 20140804));
	T.add(Archivo("Gaaa", "gaa", 64.44, 20110804));*/

	//T.find("txt");
	//T.find(112.85);
	//T.find(20140804);

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