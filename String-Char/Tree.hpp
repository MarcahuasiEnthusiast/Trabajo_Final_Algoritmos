#pragma once

#include <functional>
#include <vector>

using namespace std;

#ifndef _BST_2_HPP_
#define _BST_2_HPP_


template<typename T, typename Comparable = T>
class Tree {
	struct Node {
		T     elem;
		Node* left;
		Node* right;

		Node(T elem) : elem(elem), left(nullptr), right(nullptr) {}
	};

	Node* root;
	Node* root2;
	vector <T> V;
	int   len;


	std::function<Comparable(T)>  key;

	void destroy(Node* node) {
		if (node != nullptr) {
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}
	Node* add(Node* node, T elem) {
		if (node == nullptr) {
			node = new Node(elem);
			++len;
		}
		else if (key(elem) > key(node->elem)) {
			node->right = add(node->right, elem);
		}
		else {
			node->left = add(node->left, elem);
		}
		return node;
	}

	void inorder(Node* node, std::function<void(T)> proc) {
		if (node != nullptr) {
			inorder(node->left, proc);
			proc(node->elem);
			inorder(node->right, proc);
		}
	}

	T find(Node* node, Comparable val) {
		if (node == nullptr) {
			return 0;
		}
		if (val == key(node->elem)) {
			return node->elem;
		}
		else if (val < key(node->elem)) {
			return find(node->left, val);
		}
		else {
			return find(node->right, val);
		}
	}

	Node* findDad(Node* node, Comparable val) {
		if (node == nullptr) {
			return nullptr;
		}
		if (node == root && val == root->elem) {
			return nullptr;
		}
		if (val == key(node->left->elem) || val == key(node->right->elem)) {
			return node;
		}
		else if (val < key(node->elem)) {
			return findDad(node->left, val);
		}
		else {
			return findDad(node->right, val);
		}
	}

	Node* findNode(Node* node, Comparable val) {
		if (node == nullptr) {
			return nullptr;
		}
		if (val == key(node->elem)) {
			return node;
		}
		else if (val < key(node->elem)) {
			return findNode(node->left, val);
		}
		else {
			return findNode(node->right, val);
		}
	}


public:
	Tree(std::function<Comparable(T)>  key = [](T a) {return a; })
		: key(key), root(nullptr), len(0) {}
	~Tree() {
		destroy(root);
	}
	void add(T elem) {
		root = add(root, elem);
	}
	bool remove(Comparable val) {
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
	}

	T find(Comparable val) {
		return find(root, val);
	}

	Node* findNode(Comparable val) {
		return findNode(root, val);
	}

	Node* findDad(Comparable val) {
		return findDad(root, val);
	}

		void inorder(std::function<void(T)> proc) {
		inorder(root, proc);
	}

		vector <T> FiltrarMayor(T n) {
			V.clear();
			return FiltradoMayor(n);
	}

	vector <T> FiltradoMayor(T n)
	{
		root2 = findNode(n);
		Node* root3 = root2;
		Node* papi = findDad(root2->elem);//right
		Node* hijo = root2;


		//V.push_back(root2->elem); Descomentar para mayor e igual

		while (root2->right != nullptr)
		{
			root2 = root2->right;
			root3 = root2;
			V.push_back(root2->elem);
			while (root3->left != nullptr)
			{
				root3 = root3->left;
				V.push_back(root3->elem);
			}
		}

		if (papi != nullptr)
		{
			if (papi->elem > hijo->elem)
			{
				V.push_back(papi->elem);
				FiltradoMayor(papi->elem);
			}
			else if (hijo->elem < root->elem)
			{
				V.push_back(root->elem);
				FiltradoMayor(root->elem);
			}
		}

		return V;
	}

	vector <T> FiltrarMenor(T n) {
		V.clear();
		return FiltradoMenor(n);
	}

	vector <T> FiltradoMenor(T n)
	{

		root2 = findNode(n);
		Node* root3 = root2;
		Node* papi = findDad(root2->elem);//left
		Node* hijo = root2;


		//V.push_back(root2->elem); Descomentar para mayor e igual

		while (root2->left != nullptr)
		{
			root2 = root2->left;
			root3 = root2;
			V.push_back(root2->elem);
			while (root3->right != nullptr)
			{
				root3 = root3->right;
				V.push_back(root3->elem);
			}
		}

		if (papi != nullptr)
		{
			if (papi->elem < hijo->elem)
			{
				V.push_back(papi->elem);
				FiltradoMenor(papi->elem);
			}
			else if (hijo->elem > root->elem)
			{
				V.push_back(root->elem);
				FiltradoMenor(root->elem);
			}

		}

		return V;
	}
};

#endif