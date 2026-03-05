#include "bst.h"
#include <algorithm>

int AVLTree::getHeight(Node* n) {return n ? n->height : 0;}
int AVLTree::getSize(Node* n) {return n ? n->size : 0;}
int AVLTree::getBalance(Node* n) {return n ? getHeight(n->left) - getHeight(n->right) : 0;}

void AVLTree::updateNode(Node* n) 
{
	if(n)
	{
		n->height = 1 + max(getHeight(n->left), getHeight(n->right));
		n->size = 1 + getSize(n->left) + getSize(n->right);
	}
}

Node* AVLTree::rotateRight(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left = T2;

	if(T2) T2->parent = y;
	x->parent = y->parent;
	y->parent = x;

	updateNode(y);
	updateNode(x);
	return x;
}

Node* AVLTree::rotateLeft(Node* x)
{
	Node* y = x->right;
	Node* T2 = y->left;

	y->left = x;
	x->right = T2;

	if(T2) T2->parent = x;
	y->parent = x->parent;
	x->parent = y;

	updateNode(x);
	updateNode(y);
	return y;
}

Node* AVLTree::balance(Node* node)
{
	updateNode(node);
	int balanceFactor = getBalance(node);

	if(balanceFactor > 1) // left heavy
	{
		if(getBalance(node->left) < 0)
		{
			node->left = rotateLeft(node->left);
		}
		return rotateRight(node);
	}

	if(balanceFactor < -1) //right heavy
	{
		if(getBalance(node->right) > 0)
		{
			Node* rightChild = node->right;
			node->right = rotateRight(rightChild);
		}
		return rotateLeft(node);
	}

	return node;
}

void AVLTree::insert(string key) {root = insertRecursive(root, key, nullptr);}
Node* AVLTree::insertRecursive(Node* node, string key, Node* parent)
{
	if(node == nullptr)
	{
		Node* newNode = new Node(key);
		newNode->parent = parent;
		return newNode;
	}

	if(key < node->key) {
		node->left = insertRecursive(node->left, key, node);
	} else if(key > node->key) {
		node->right = insertRecursive(node->right, key, node);
	} else {
		// key already present; do not insert duplicate
		return node;
	}
	return balance(node);
}

int AVLTree::countLE(Node* node, string key)
{
	if(node == nullptr) return 0;

	if(node->key <= key)
	{
		return 1 + getSize(node->left) + countLE(node->right, key);
	}
	else
	{
		return countLE(node->left, key);
	}
}

// count keys strictly less than the given key
int AVLTree::countLT(Node* node, string key)
{
	if(node == nullptr) return 0;

	if(node->key < key)
	{
		return 1 + getSize(node->left) + countLT(node->right, key);
	}
	else
	{
		return countLT(node->left, key);
	}
}

int AVLTree::rangeQuery(string low, string high)
{
	// since we want inclusive range first i have to find the bounds, see if low is 
	// in the list, and see how many are to the left of high.
	// maybe instead of this i can count less than or equal of high bound minus countLE(one less than low)
	// note: intermediate results aren't used elsewhere so avoid unused variable warnings
	int highCount = countLE(root, high);
	int lowCount  = countLT(root, low);
	return highCount - lowCount;
}