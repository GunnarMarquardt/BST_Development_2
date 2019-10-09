//Binary Search Tree
#include <iostream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
};

class BST {
private:
	int size = 0;
	Node* root;
	Node* insert(int, Node*); //helper
	void displayInOrder(Node*); //helper
	int getSize(Node*); //helper
	void treeClear(Node*); //helper
public:
	BST();
	void insert(int);
	void displayInOrder();
	int getSize();
	int treeSize();
	void treeClear();
}; //BST class

//helper functions
Node* BST::insert(int v, Node* r) {
	if (r == nullptr) {
		r = new Node;
		r->left = r->right = nullptr;
		r->data = v;
		return r;
	}
	else if (v < r->data) {
		r->left = insert(v, r->left);
		return r;
	}
	else {
		r->right = insert(v, r->right);
		return r;
	}
} //helper

int BST::getSize(Node* r) {
	if (r == nullptr)
		return 0;
	else
		return 1 + getSize(r->left) + getSize(r->right);
} //helper


void BST::displayInOrder(Node* r) {
	if (r != nullptr)
	{
		displayInOrder(r->left);
		cout << r->data << endl;
		displayInOrder(r->right);
	}
} //helper

void BST::treeClear(Node* n) {
	if (n != nullptr) {
		treeClear(n->left);
		treeClear(n->right);
		delete n;
	}
	return;
} //helper

//constructors
BST::BST() {
	root = nullptr;
}


//setters
void BST::insert(int v) {
	root = insert(v, root);
	size++;
}

//getters
int BST::getSize() {
	return getSize(root);
}

int BST::treeSize() {
	return size;
}

//utility
void BST::displayInOrder() {
	displayInOrder(root);
}

void BST::treeClear() {
	treeClear(root);
	size = 0;
}

int main() {
	
}