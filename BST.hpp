#pragma once

#ifndef __BST_HPP__
#define __BST_HPP__

#include <functional>

template<typename T, typename Comparable = T>
class Tree {
	struct Node {
		T     elem;
		Node* left;
		Node* right;

		Node(T elem) : elem(elem), left(nullptr), right(nullptr) {}
	};

	Node* root;
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
		cout << "Encontrado" << endl;
		return find(root, val);
	}

	/*list<T>* findAll(Comparable val) {
	return nullptr; // TODO!!
	}*/

	void inorder(std::function<void(T)> proc) {
		inorder(root, proc);
	}
};

#endif


