// <Brandon Hudson>
// Prigramming Assignment 1
// CS340
// Fall 2019

#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <iomanip>
#include<fstream>
#include<cstdlib>
#include <string>
#include <fstream>

using namespace std;



// class must be templated
//template <class DataType>
//void destructorHelper(DataType leaf);

template <class DataType>
class BSTree
{
private:
	// You may NOT add any data members
	struct node;
	typedef node* nodePtr;
	//typedef string DataType; /*THIS TYPEDEF*/

	struct node
	{
		DataType element;
		nodePtr right;
		nodePtr left;
	};
	int count;
	nodePtr root;

	nodePtr itr;

	// You may add any private member functions here


	// This method is to print the tree as shown on handout 
	// it is called from printTree (given below)
	void printTreeHelper(int depth, nodePtr cur) const
	{
		const int spacing = 4;
		if (cur != NULL)
		{
			if (depth == 0)
				cout << cur->element;
			else
				cout << setw(spacing * depth) << " " << cur->element;
			cout << endl;
			printTreeHelper(depth + 1, cur->right);
			printTreeHelper(depth + 1, cur->left);


		}
		else
			cout << setw(spacing * depth) << " " << "****" << endl;

	}


public:




	// Default constructor
	BSTree()
	{
		root = new node;
		root = nullptr;
		//	insert(this, this->element);
	//		root->left = nullptr;
		//	root->right = nullptr;

	}

	// Copy constructor
	template <typename T>
	BSTree(T next, DataType data)
	{
		//root = new node();		
		nodePtr n = new node();
		n = createNode(data);

		if (root == nullptr) {
			root = createNode(data);
		}
		else {
			n->element = root->element;
			n->right = root->right;
			n->left = root->left;

			itr = n;
		}

	}

	template <typename T>
	nodePtr createNode(T data) {
		nodePtr n = new node;
		n->element = data;
		n->left = nullptr;
		n->right = nullptr;

		return n;

	}

	nodePtr createNode() {
		nodePtr n = new node;

		n->left = nullptr;
		n->right = nullptr;

		return n;

	}

	template <typename T>
	void setElement(nodePtr n, T data) {
		n->element = data;
	}

	// Equal overload

	const BSTree& operator =(nodePtr nextNode)
	{
		BSTree t = new BSTree();

		if (root->element == nextNode->element && root->right == nextNode->right && root->left == nextNode->left) {

			return true;
		}
		else { return false; }

	}

	// Destructor
	~BSTree()
	{
		//deleteTree(root);
	}

	/*nodePtr operator ->()const {
		return root;
	}*/

	/*void operator =(const nodePtr n) {

		root->left = n->left;
	}
	*/


	// Inserts element (that is passed in) into the tree
	// If value is already in the tree do NOt add it
	// a second time
	template <typename T>
	void insert(T n, T data)
	{
		BSTree* tree = new BSTree(n, data);
		nodePtr temp = new node;
		nodePtr nxt = new node;

		tree = this;

		bool locked = true;
		//printTree();


	//	cout << "INSERT!!!" << endl;

		temp = createNode(data);

		if (root == nullptr) {
			root = createNode(data);
		}
		else {
			nodePtr cur;
			nxt = root;

			cur = temp;

			if (cur->element < nxt->element) {
				while (locked) {
					if (nxt->left == nullptr) {
						if (cur->element < nxt->element) {
							nxt->left = temp;
							locked = false;
						}
						else {
							if (nxt->right == nullptr) {
								nxt->right = temp;
								locked = false;
							}
							else {
								nxt = nxt->right;
							}
						}
					}
					else {
						nxt = nxt->left;
					}
				}
			}
			else if (cur->element > nxt->element) {
				locked = true;
				while (locked) {
					if (nxt->right == nullptr) {
						if (cur->element > nxt->element) {
							nxt->right = temp;
							locked = false;
						}
						else {
							if (nxt->left == nullptr) {
								nxt->left = temp;
								locked = false;
							}
							else {
								nxt = nxt->left;
							}
						}
					}
					else {
						nxt = nxt->right;
					}
				}
			}
			else {
				cout << "Already in tree!" << endl;
			}

			/*

			if (temp->element < cur->element) {
				if (cur->left == nullptr) {
					cur = cur->left;
					cur = createNode(data);

					if (nxt->left != nullptr) {

						nxt = root->left;
					}
					else {

					}

					return;
				}
				else {
					cur = cur->left;
				}
			}
			else if (temp->element < cur->element) {
				if (cur->right == nullptr) {
					cur = cur->right;
					cur = createNode(data);
					return;
				}
				else {
					cur = cur->right;
				}
			}
			else {
				cout << "Equal" << endl;
				return;
			}

			*/



		}


		printTree();

	}





	//Print the tree as a tree
	// This (and its helper function) is given to you
	bool printTree() const
	{
		if (root == NULL) {

			cout << "Tree is Empty!" << endl;
			return false;

		}
		else
		{



			printTreeHelper(0, root);
			if (root->right != nullptr) {

				printTreeHelper(0, root->right);
			}

			if (root->left != nullptr) {

				printTreeHelper(0, root->left);

			}

			return true;
		}
	}

	// Prints tree in order to the screen
	// call printInOrder with  cout passed in
	// Done for you
	template <typename T>
	void printInOrder()
	{

		printInOrder(root->left);
		printf("%s\n", root->element);
		printInOrder(root->right);
		// printInOrder(cout);

	}

	// Prints the tree in order to
	// the ostream passed into it

	void printInOrder(ostream& T)
	{
		printInOrder(root->left);
		printf("%s\n", root->element);
		printInOrder(root->right);

	}

	// Prints tree in preorder to the screen
	// call printPreOrder with  cout passed in
	// Done for you
	void printPreOrder()
	{
		printPreOrder(cout);

	}
	// Prints the tree in preorder to
	// the ostream passed into it

	void printPreOrder(DataType& T)
	{
	}

	// Deletes the item passed in from the tree
	// Returns true id deleted and false if not in list
	bool  deleteNode(nodePtr cur)
	{

	}

	// Deletes the whole tree
	void deleteTree(nodePtr cur)
	{

		if (cur)
		{
			deleteTree(cur->left);
			deleteTree(cur->right);
			delete(cur);

		}
	}
};

#endif
