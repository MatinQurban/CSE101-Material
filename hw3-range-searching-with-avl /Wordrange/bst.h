#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <string>
using namespace std;

struct Node {
	string key;
	int height;
	int size;
	Node *left, *right, *parent;

	Node(string k): key(k), height(1), size(1), left(nullptr), right(nullptr), parent(nullptr) {}
};

class AVLTree
{
	public:
		AVLTree(): root(nullptr) {}

		void insert(string key);
		int rangeQuery(string low, string high);

	private:
		Node* root;

		int getHeight(Node* n);
		int getSize(Node* n);
		void updateNode(Node* n);
		int getBalance(Node* n);

		//Anything related to rotating
		Node* rotateLeft(Node* x);
		Node* rotateRight(Node* y);
		Node* balance(Node* node);
		Node* insertRecursive(Node* node, string key, Node* parent);
		int countLE(Node* node, string key);
	int countLT(Node* node, string key);  // count strictly less than key
};

#endif