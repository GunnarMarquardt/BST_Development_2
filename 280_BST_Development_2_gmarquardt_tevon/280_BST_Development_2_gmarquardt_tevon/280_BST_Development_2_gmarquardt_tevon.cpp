/*
280
BST_Development_2
Gunnar Marquardt && Thomas Evon
*/

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
	int howMany(Node*); //helper
	void treeClear(Node*); //helper
	void display(Node*, int);
public:
	BST();
	void insert(int);
	void displayInOrder();
	int howMany();
	int treeSize();
	void treeClear();
	int sumInRange(int, int);
	void display();
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

int BST::howMany(Node* r) {
	if (r == nullptr)
		return 0;
	else
		return 1 + howMany(r->left) + howMany(r->right);
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
int BST::howMany() {
	return howMany(root);
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
	root = nullptr;
	size = 0;
}

void BST::display(Node* ptr, int level)
{
	if (ptr != nullptr)
	{
		display(ptr->right, level + 1);
		cout << endl;
		if (ptr == root)
			cout << "Root->:  ";
		else
		{
			for (int i = 0; i < level; i++)
				cout << "       ";
		}
		cout << ptr->data;
		display(ptr->left, level + 1);
	}
} // display helper

void BST::display() {
	display(root, 1);
} // display (pretty tree)

int BST::sumInRange(int min, int max) {
	Node* runner = root;
	int sum = 0;
	if (runner == nullptr) return 0;
	while (runner != nullptr && runner->data >= min) {
		sum += runner->data;
		runner = runner->left;
	}
	runner = root->right;
	while (runner != nullptr && runner->data <= max) {
		sum += runner->data;
		runner = runner->right;
	}
	return sum;
}

int main() {
	int input, num;
	BST bst = BST();
	while (1) {
		cout << endl << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "Choose Your Function:" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "1.Insert Recursive" << endl;
		cout << "2.SuminRange" << endl;
		cout << "3.Pretty Tree Display" << endl;
		cout << "4.Display in Order" << endl;
		cout << "5.Get Number of Nodes (howMany)" << endl;
		cout << "6.Get Tree Size" << endl;
		cout << "7.Clear Tree" << endl;
		cout << "8.Quit" << endl;
		cout << endl << "Enter your choice : ";
		cin >> input;
		switch (input) {
		case 1:
			cout << "Insert (enter int): ";
			cin >> num;
			bst.insert(num);
			break;
		case 2:
			int min, max;
			cout << "Enter your min and max values: ";
			cin >> min >> max;
			if (min > max) cout << "ERROR, your min is greater than your max!" << endl;
			cout << "Sum is = " << bst.sumInRange(min, max) << endl;
			break;
		case 3:
			cout << endl << "Display pretty tree:" << endl
				<< "--------------------" << endl;
			bst.display();
			break;
		case 4:
			cout << endl << "Display In Order:" << endl
				<< "--------------------" << endl;
			bst.displayInOrder();
			break;
		case 5:
			cout << "The number of nodes are: " << bst.howMany();
			break;
		case 6:
			cout << "The number of nodes is: " << bst.treeSize();
			break;
		case 7:
			bst.treeClear();
			break;
		case 8:
			cout << "Program TERMINATED" << endl;
			exit(0);
			break;
		}
	}
	return 0;
}