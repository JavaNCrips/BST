// <Brandon Hudson>
// Prigramming Assignment 1
// CS340
// Fall 2019

#ifndef LIST_H
#define LIST_H
#include <iostream>
#include<fstream>
#include<cstdlib>
#include <string>
#include <fstream>
using namespace std;
//typedef string DataType;

// class must be templated
template <class DataType>
class List
{
private:
	// You may NOT add any data members
	struct node;
	typedef node* nodePtr;
	struct node
	{
		DataType info;
		nodePtr next;
	};

	nodePtr head;

	nodePtr itr;

	// You can add any private member functions you want

public:
	// Default onstructor
	List()
	{
		head = new node;
		head->next = nullptr;
	}

	// Copy Constructor
	template <typename T>
	List(DataType data)
	{
		nodePtr n = new node();

		Course<Professor>* c = new Course<Professor>();

		if (head == nullptr) {
			head = createNode(data);
		}
		else {
			n = head;
			while (n->next != nullptr) {
				n = n->next;
			}
			if (n == nullptr) {
				n = createNode(data);
			}
			else {
				while (n->next != nullptr) {
					n = n->next;
				}
				if (n == nullptr) {
					n = createNode(data);
				}
			}

		}
	}



	// Destructor
	~List()
	{
		//head->info = NULL;
		//head->next = NULL;
	}

	template <typename T>
	nodePtr createNode(DataType data) {
		nodePtr n = new node;
		n->info = data;
		n->next = nullptr;


		return n;

	}
	// Overloaded equal operator
	template <typename T>
	T operator =(T& nextNode)
	{
		List* list = new List;
		nodePtr itr = nextNode->head;

		while (itr != nullptr) {

			itr = itr->next;

		}

		return itr;

	}

	// insert into the list
	// if it is already in the list, it does NOT addd it
	void insert(DataType newNode)
	{



		nodePtr cur;
		nodePtr prev;
		prev = head;
		cur = head->next;

		while (cur != nullptr && cur->info != prev->info) {

			prev = cur;
			cur = cur->next;
		}

		if (cur == nullptr || cur->info != prev->info) {


			nodePtr temp = new node;
			temp->next = cur;
			temp->info = newNode;
			prev->next = temp;

			List* newList = new List;
			newList->head = head;



		}

		//cout << "Course Inserted" << endl;


	}

	// checks to see if element is in list
	// returns true if it is in list, false if not in list
	bool isInList(DataType& newNode)
	{
		while (head->next != nullptr) {
			if (head = newNode) { return true; }
			else {
				head = head->next;
				return false;
			}
		}
	}

	// Prints the list to the screen by calling the
	// overloaded printList and passing cout into it
	// Done for you
	void printList()
	{
		printList(cout);




	}

	// Prints the list to the ostream passed into it
	void printList(ostream& out)
	{
		if (head != nullptr) {
			//printInOrder(head->next);
			//printf("%s\n", head->info);
			//printInOrder(head->right);

		}
	}

	// Deletes the item passed in from the list
	// returns a true if an item is deleted and a false
	// if the item wasn't in the list    
	bool deleteListItem()
	{
	}

	// Deletes the item from the list that is passed in, it
	// also passes the item that is deleted back (2 formal parameters)
	// returns a true if an item is deleted and a false
	// if the item wasn't in the list
	bool deleteAndPassBackListItem()
	{
	}

	// Deletes the first item from the list, it
	// also passes the item that is deleted back 
	// returns a true if an item is deleted and a false
	// if the item wasn't in the list  
	bool deleteFirstAndPassBackListItem()
	{
	}

	// Returns true if the list is empty and false if it isn't
	bool isEmpty()
	{
	}
};
#endif