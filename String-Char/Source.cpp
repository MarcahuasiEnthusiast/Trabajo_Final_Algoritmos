#include <iostream>
#include <vector>
#include <string>
#include "Tree.hpp"
using namespace std;

//#include "BSTArchivos.hpp"
int main(){

	string str;
	string str_2;

	cout << "Primer string: ";
	cin >> str;
	cout << "Segundo string: ";
	cin >> str_2;

	string aux = str.substr(str.length() - 1, 1);
	string aux_2 = str_2.substr(str_2.length() - 1, 1);


	if(aux_2 < aux){
		cout << "SI";
	} else{
		cout << "NO";
	}

	return 0;
}