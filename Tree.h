#include <iostream>
#include <functional>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;
using std::string;

template<typename T, typename Comparable = T, T NONE = 0>
class Tree{
	struct Node{
		T elem;
		Node* left;
		Node* right;
		Node(T elem) : elem(elem), left(nullptr), right(nullptr){ }
	};
	Node* root;
	int len;
	function<Comparable(T)> key;
	void destroy(Node* node){
		if(node != nullptr){
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}
	Node* add(Node* node, T elem){
		if(node == nullptr){
			node = new Node(elem);
		} else if(key(elem) > key(node->elem)){
			node->right = add(node->right, elem);
		} else{
			node->left = add(node->left, elem);
		}
		return node;
	}
	void preOrder(Node* node, function<void(T)> proc){
		if(node != nullptr){
			proc(node->elem);
			preOrder(node->left, proc);
			preOrder(node->right, proc);
		}
	}
	void postOrder(Node* node, function<void(T)> proc){
		if(node != nullptr){
			postOrder(node->left, proc);
			postOrder(node->right, proc);
			proc(node->elem);
		}
	}
	void inOrder(Node* node, function<void(T)> proc){
		if(node != nullptr){
			inOrder(node->left, proc);
			proc(node->elem);
			inOrder(node->right, proc);
		}
	}
	T find(Node* node, Comparable val){
		if(node == nullptr){
			return NONE;
		}
		if(val == key(node->elem)){
			return node->elem;
		}
		else if(val < key(node->elem)){
			return find(node->left, val);
		}
		else{
			return find(node->right, val);
		}
	}
public:
	Tree(function<Comparable(T)> key = [](T a){return a; }) : key(key), root(nullptr), len(0){ }
	~Tree(){
		destroy(root);
	}
	T find(Comparable val){
		return find(root, val);
	}
	void add(T elem){
		root = add(root, elem);
	}
	void preOrder(function<void(T)> proc){
		preOrder(root, proc);
	}
	void inOrder(function<void(T)> proc){
		inOrder(root, proc);
	}
	void postOrder(function<void(T)> proc){
		postOrder(root, proc);
	}

	bool remove(Comparable val){
		Node* aux = root;
		Node* parent;
		bool left;
		while(aux != nullptr){
			if(val == key(aux->elem)){
				break;
			}else{
				parent = aux;
				if(val < key(aux->elem)){
					left = true;
					aux = aux->left;
				} else{
					left = false;
					aux = aux->right;
				}
			}
		}
		if (aux == nullptr) return false;
		if(aux->left == nullptr){
			if(aux == root) root = aux->right;
			else if(left) parent->left = aux->right;
			else parent->right = aux->right;
			delete aux;
		} else{
			Node* aux2 = aux->left;
			while(aux2->right != nullptr){
				parent = aux2;
				aux2 = aux2->right;
			}
			if(aux2 == aux->left){
				aux->left = aux2->left;
			} else{
				parent->right = aux2->left;
			}
			aux->elem = aux2->elem;
			delete aux2;
		}
		return true;
	}
};