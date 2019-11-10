#pragma once

#include "Archivo.hpp"
#include <iostream>

#ifndef __BSTARCHIVOS_HPP__
#define __BSTARCHIVOS_HPP__

#include <functional>

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
	int   len;
	int flag = 1; // Si es igual a 1 es por nombre, 2 extension, 3 tamaño y 4 fecha

	//std::function<Comparable(T)>  key;

	void destroy(Node* node) {
		if (node != nullptr) {
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}

	Node* addTam(Node* node, Archivo A/*,T elem*/) {

		if (node == nullptr) {
			node = new Node(A);
			++len;
		}
		else if (A.gettamaño() > node->A.gettamaño()) {
			node->right = addTam(node->right, A);
		}
		else {
			node->left = addTam(node->left, A);
		}
		return node;
	}

	Node* addFec(Node* node, Archivo A/*,T elem*/) {

		if (node == nullptr) {
			node = new Node(A);
			++len;
		}
		else if (A.getfecha() > node->A.getfecha()) {
			node->right = addFec(node->right, A);
		}
		else {
			node->left = addFec(node->left, A);
		}
		return node;
	}

	Node* addExt(Node* node, Archivo A/*,T elem*/) {

		if (node == nullptr) {
			node = new Node(A);
			++len;
		}
		else if (A.getextension() > node->A.getextension()) {
			node->right = addExt(node->right, A);
		}
		else {
			node->left = addExt(node->left, A);
		}
		return node;
	}


	Node* addNom(Node* node, Archivo A/*,T elem*/) {

		if (node == nullptr) {
			node = new Node(A);
			++len;
		}
		else if (A.getnombre() > node->A.getnombre()) {
			node->right = addNom(node->right, A);
		}
		else {
			node->left = addNom(node->left, A);
		}
		return node;
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
			return Archivo("","",0,0);
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
		if (T == node->A.gettamaño()) {
			cout << "Encontrado" << endl;

			cout << node->A.gettamaño() << endl;

			return node->A;
		}
		else if (T < node->A.gettamaño()) {
			return findTam(node->left, T);
		}
		else {
			return findTam(node->right, T);
		}
	}


public:
	Tree(/*std::function<Comparable(T)>  key = [](T a) {return a; }*/)
		: /*key(key),*/ root(nullptr), len(0) {}

	~Tree() {
		destroy(root);
	}

	void addExt(Archivo A) {
		root = addExt(root, A);
	}
	void addNom(Archivo A) {
		root = addNom(root, A);
	}
	void addFec(Archivo A) {
		root = addFec(root, A);
	}
	void addTam(Archivo A) {
		root = addTam(root, A);
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

	Archivo findFec(int F) {
		return findFec(root, F);
	}
	Archivo findNom(string N) {
		return findNom(root, N);
	}
	Archivo findExt(string E) {
		return findExt(root, E);
	}
	Archivo findTam(float T) {
		return findTam(root, T);
	}

	/*list<T>* findAll(Comparable val) {
	return nullptr; // TODO!!
	}*/

	/*void inorder(std::function<void(T)> proc) {
		inorder(root, proc);
	}*/
};

#endif