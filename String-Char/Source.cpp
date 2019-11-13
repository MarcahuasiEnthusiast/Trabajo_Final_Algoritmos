#include <iostream>
#include <vector>
#include "Tree.hpp"
using namespace std;
//#include "BSTArchivos.hpp"
int main(){
	
	Tree <string> T;
	vector <string> V;

	string aux("wewggn");
	string aux2("nmvnk");
	string aux3("tuqe");
	string aux4("wa");
	string aux5("dnuyu");
	string aux6("wrwz");

	string a = aux.substr(aux.length()   - 1, 1);
	string b = aux2.substr(aux2.length() - 1, 1);
	string c = aux3.substr(aux3.length() - 1, 1);
	string d = aux4.substr(aux4.length() - 1, 1);
	string e = aux5.substr(aux5.length() - 1, 1);
	string f = aux6.substr(aux6.length() - 1, 1);

	T.add(a);
	T.add(f);
	T.add(b);
	T.add(c);
	T.add(d);
	T.add(e);
	
	V = T.FiltrarMenor(f);

	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << endl;
	}

	return 0;
}