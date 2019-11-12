#pragma once

#include "Archivo.hpp"
#include <iostream>
#include <functional>
#include <vector>

#ifndef __BSTARCHIVOS_HPP__
#define __BSTARCHIVOS_HPP__

using namespace std;

//template<typename T, typename Comparable = T>
class Tree {
	struct Node {
		//T     elem;
		Archivo  A;
		Node* left;
		Node* right;

		Node(Archivo A/*T elem*/) : A(A), left(nullptr), right(nullptr) {}
	};
	
	Node* root;
	Node* root2;
	int   len;
	int flag = 0; // Si es igual a 1 es por nombre, 2 extension, 3 tamano y 4 fecha

	//std::function<Comparable(T)>  key;

	void destroy(Node* node) {
		if (node != nullptr) {
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}

	Node* add(Node* node, Archivo A/*,T elem*/) {

		if (flag == 3)
		{
			if (node == nullptr) {
				node = new Node(A);
				++len;
			}
			else if (A.gettamano() > node->A.gettamano()) {
				node->right = add(node->right, A);
			}
			else {
				node->left = add(node->left, A);
			}
			return node;
		}

		else if (flag == 4)
		{
			if (node == nullptr) {
				node = new Node(A);
				++len;
			}
			else if (A.getfecha() > node->A.getfecha()) {
				node->right = add(node->right, A);
			}
			else {
				node->left = add(node->left, A);
			}
			return node;
		}

		else if (flag == 2)
		{
			if (node == nullptr) {
				node = new Node(A);
				++len;
			}
			else if (A.getextension() > node->A.getextension()) {
				node->right = add(node->right, A);
			}
			else {
				node->left = add(node->left, A);
			}
			return node;
		}

		else if (flag == 1)
		{

			if (node == nullptr) {
				node = new Node(A);
				++len;
			}
			else if (A.getnombre() > node->A.getnombre()) {
				node->right = add(node->right, A);
			}
			else {
				node->left = add(node->left, A);
			}
			return node;
		}
		
	}

	//void inorder(Node* node, std::function<void(T)> proc) {
	//	if (node != nullptr) {
	//		inorder(node->left, proc);
	//		proc(node->elem);
	//		inorder(node->right, proc);
	//	}
	//}

	Archivo findFec(Node* node, int I) {
		if (node == nullptr) {
			cout << "No Encontrado" << endl;
			return Archivo("", "", 0, 0);
		}
		if (I == node->A.getfecha()) {
			cout << "Encontrado" << endl;

			cout << node->A.getfecha() << endl;

			return node->A;
		}
		else if (I < node->A.getfecha()) {
			return findFec(node->left, I);
		}
		else {
			return findFec(node->right, I);
		}
	}

	Archivo  findNom(Node* node, string N) {
		if (node == nullptr) {
			cout << "No Encontrado" << endl;
			return Archivo("", "", 0, 0);
		}
		if (N == node->A.getnombre()) {
			cout << "Encontrado" << endl;

			cout << node->A.getnombre() << endl;

			return node->A;
		}
		else if (N < node->A.getnombre()) {
			return findNom(node->left, N);
		}
		else {
			return findNom(node->right, N);
		}
	}

	Archivo findExt(Node* node, string E) {
		if (node == nullptr) {
			cout << "No Encontrado" << endl;
			return Archivo("", "", 0, 0);
		}
		if (E == node->A.getextension()) {
			cout << "Encontrado" << endl;

			cout << node->A.getextension() << endl;

			return node->A;
		}
		else if (E < node->A.getextension()) {
			return findExt(node->left, E);
		}
		else {
			return findExt(node->right, E);
		}
	}


	Archivo findTam(Node* node, float T) {
		if (node == nullptr) {
			cout << "No Encontrado" << endl;
			return Archivo("", "", 0, 0);
		}
		if (T == node->A.gettamano()) {
			cout << "Encontrado" << endl;

			cout << node->A.gettamano() << endl;

			return node->A;
		}
		else if (T < node->A.gettamano()) {
			return findTam(node->left, T);
		}
		else {
			return findTam(node->right, T);
		}
		
	}

	/*template <typename T>
	Archivo find(Node* node, T F) {
		if (flag == 1)
		{
			if (node == nullptr) {
				cout << "No Encontrado" << endl;
				return Archivo("", "", 0, 0);
			}
			if (N == key(node->A.getnombre())) {
				cout << "Encontrado" << endl;

				cout << node->A.getnombre() << endl;

				return node->A;
			}
			else if (N < key(node->A.getnombre())) {
				return findNom(node->left, N);
			}
			else {
				return findNom(node->right, N);
			}
		}
		else if (flag == 2)
		{
			if (node == nullptr) {
				cout << "No Encontrado" << endl;
				return Archivo("", "", 0, 0);
			}
			if (E == node->A.getextension()) {
				cout << "Encontrado" << endl;

				cout << node->A.getextension() << endl;

				return node->A;
			}
			else if (E < node->A.getextension()) {
				return findExt(node->left, E);
			}
			else {
				return findExt(node->right, E);
			}
		}
		else if (flag == 3)
		{
			if (node == nullptr) {
				cout << "No Encontrado" << endl;
				return Archivo("", "", 0, 0);
			}
			if (T == node->A.gettama�o()) {
				cout << "Encontrado" << endl;

				cout << node->A.gettama�o() << endl;

				return node->A;
			}
			else if (T < node->A.gettama�o()) {
				return findTam(node->left, T);
			}
			else {
				return findTam(node->right, T);
			}
		}
		else if (flag == 4)
		{
			if (node == nullptr) {
				cout << "No Encontrado" << endl;
				return Archivo("", "", 0, 0);
			}
			if (I == node->A.getfecha()) {
				cout << "Encontrado" << endl;

				cout << node->A.getfecha() << endl;

				return node->A;
			}
			else if (I < node->A.getfecha()) {
				return findFec(node->left, I);
			}
			else {
				return findFec(node->right, I);
			}
		}

	}*/

	
	Node* findNode_nombre(Node* node, string val) {
		if (node == nullptr) {
			return 0;
		}
		if (val == node->A.getnombre()) {
			return node;
		}
		else if (val < node->A.getnombre()) {
			return findNode_nombre(node->left, val);
		}
		else {
			return findNode_nombre(node->right, val);
		}
	}

	
	Node* findNode_fec(Node* node, int val) {
		if (node == nullptr) {
			return 0;
		}
		if (val == node->A.getfecha()) {
			return node;
		}
		else if (val < node->A.getfecha()) {
			return findNode_fec(node->left, val);
		}
		else {
			return findNode_fec(node->right, val);
		}
	}

	
	Node* findNode_exte(Node* node, string val) {
		if (node == nullptr) {
			return 0;
		}
		if (val == node->A.getextension()) {
			return node;
		}
		else if (val < node->A.getextension()) {
			return findNode_exte(node->left, val);
		}
		else {
			return findNode_exte(node->right, val);
		}
	}

	
	Node* findNode_tam(Node* node, float val) {
		if (node == nullptr) {
			return 0;
		}
		if (val == node->A.gettamano()) {
			return node;
		}
		else if (val < node->A.gettamano()) {
			return findNode_tam(node->left, val);
		}
		else {
			return findNode_tam(node->right, val);
		}
	}


public:
	Tree(/*std::function<Comparable(T)>  key = [](T a) {return a; }*/)
		: /*key(key),*/ root(nullptr), len(0) {}

	~Tree() {
		destroy(root);
	}

	void add(Archivo A) {
		root = add(root, A);

	}

	/*bool remove(Comparable val) {
		Node* aux = root;
		Node* parent;
		bool left;
		while (aux != nullptr) {
			if (val == key(aux->elem)) {
				break;
			}
			else {
				parent = aux;
				if (val < key(aux->elem)) {
					left = true;
					aux = aux->left;
				}
				else {
					left = false;
					aux = aux->right;
				}
			}
		}
		if (aux == nullptr) return false;
		if (aux->left == nullptr) {
			if (aux == root)  root = aux->right;
			else if (left)    parent->left = aux->right;
			else              parent->right = aux->right;
			delete aux;
		}
		else {
			Node* aux2 = aux->left;
			while (aux2->right != nullptr) {
				parent = aux2;
				aux2 = aux2->right;
			}
			if (aux2 == aux->left) {
				aux->left = aux2->left;
			}
			else {
				parent->right = aux2->left;
			}
			aux->elem = aux2->elem;
			delete aux2;
		}
		return true;
	}*/

	/*vector <Archivo> FiltradoIgual(float n){
		vector <Archivo> V;
		V.push_back(n);
		root2 = findNode_tam(n);
		Node* aux = root2;

		while (aux->right != nullptr){
			if(aux->right == root2){
				V.push_back();
			}
			aux = aux->right;
		}

		return V;
	}*/

	bool remove_by_tamano(float val) {
		Node* aux = root;
		Node* parent;
		bool left;
		while (aux != nullptr) {
			if (val == aux->A.gettamano()) {
				break;
			}
			else {
				parent = aux;
				if (val < aux->A.gettamano()) {
					left = true;
					aux = aux->left;
				}
				else {
					left = false;
					aux = aux->right;
				}
			}
		}
		if (aux == nullptr) return false;
		if (aux->left == nullptr) {
			if (aux == root)  root = aux->right;
			else if (left)    parent->left = aux->right;
			else              parent->right = aux->right;
			delete aux;
		}
		else {
			Node* aux2 = aux->left;
			while (aux2->right != nullptr) {
				parent = aux2;
				aux2 = aux2->right;
			}
			if (aux2 == aux->left) {
				aux->left = aux2->left;
			}
			else {
				parent->right = aux2->left;
			}
			aux->A = aux2->A;
			delete aux2;
		}
		return true;
	}

	bool remove_by_fecha(float val) {
		Node* aux = root;
		Node* parent;
		bool left;
		while (aux != nullptr) {
			if (val == aux->A.getfecha()) {
				break;
			}
			else {
				parent = aux;
				if (val < aux->A.getfecha()) {
					left = true;
					aux = aux->left;
				}
				else {
					left = false;
					aux = aux->right;
				}
			}
		}
		if (aux == nullptr) return false;
		if (aux->left == nullptr) {
			if (aux == root)  root = aux->right;
			else if (left)    parent->left = aux->right;
			else              parent->right = aux->right;
			delete aux;
		}
		else {
			Node* aux2 = aux->left;
			while (aux2->right != nullptr) {
				parent = aux2;
				aux2 = aux2->right;
			}
			if (aux2 == aux->left) {
				aux->left = aux2->left;
			}
			else {
				parent->right = aux2->left;
			}
			aux->A = aux2->A;
			delete aux2;
		}
		return true;
	}

	bool remove_by_extension(string val) {
		Node* aux = root;
		Node* parent;
		bool left;
		while (aux != nullptr) {
			if (val == aux->A.getextension()) {
				break;
			}
			else {
				parent = aux;
				if (val < aux->A.getextension()) {
					left = true;
					aux = aux->left;
				}
				else {
					left = false;
					aux = aux->right;
				}
			}
		}
		if (aux == nullptr) return false;
		if (aux->left == nullptr) {
			if (aux == root)  root = aux->right;
			else if (left)    parent->left = aux->right;
			else              parent->right = aux->right;
			delete aux;
		}
		else {
			Node* aux2 = aux->left;
			while (aux2->right != nullptr) {
				parent = aux2;
				aux2 = aux2->right;
			}
			if (aux2 == aux->left) {
				aux->left = aux2->left;
			}
			else {
				parent->right = aux2->left;
			}
			aux->A = aux2->A;
			delete aux2;
		}
		
			return true;
	}

	bool remove_by_nombre(string val) {
		Node* aux = root;
		Node* parent;
		bool left;
		while (aux != nullptr) {
			if (val == aux->A.getnombre()) {
				break;
			}
			else {
				parent = aux;
				if (val < aux->A.getnombre()) {
					left = true;
					aux = aux->left;
				}
				else {
					left = false;
					aux = aux->right;
				}
			}
		}
		if (aux == nullptr) return false;
		if (aux->left == nullptr) {
			if (aux == root)  root = aux->right;
			else if (left)    parent->left = aux->right;
			else              parent->right = aux->right;
			delete aux;
		}
		else {
			Node* aux2 = aux->left;
			while (aux2->right != nullptr) {
				parent = aux2;
				aux2 = aux2->right;
			}
			if (aux2 == aux->left) {
				aux->left = aux2->left;
			}
			else {
				parent->right = aux2->left;
			}
			aux->A = aux2->A;
			delete aux2;

		}

		return true;
	}


	//template <typename T>
	//Archivo find(T F) {
	//	if (flag  == 1)
	//	{
	//		return findNom(root, F);
	//	}
	//	else if (flag == 2)
	//	{
	//		//return findExt(root, F);
	//	}
	//	else if (flag == 3)
	//	{
	//		return findTam(root, F);
	//	}
	//	else if (flag == 4)
	//	{
	//		return findFec(root, F);
	//	}
	//	
	//}

	/*list<T>* findAll(Comparable val) {
	return nullptr; // TODO!!
	}*/

	/*void inorder(std::function<void(T)> proc) {
		inorder(root, proc);
	}*/

	void change()
	{
		cout << "Por que criterio desea trabajar? (1 es por nombre, 2 extension, 3 tama�o y 4 fecha)" << endl;
		cin >> flag;
	}
};

#endif