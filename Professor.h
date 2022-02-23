// <Brandon Hudson>
// Prigramming Assignment 1
// CS340
// Fall 2019

#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <string>
#include <iostream>
using namespace std;

//typedef string DataType;

// This class is NOT templated
class Professor
{
public:
	// Overloaded operatos
	// you may add more if youneed them
	// operators compare the professors' names
	bool operator <(Professor rhsP);
	bool operator >(Professor rhsP);
	bool operator ==(Professor rhsP);
	string operator ->();

	// Prints lname, fname
	string toString() const;

	void setLastName(string name); // Sets the last name to the string passed in
	void setFirstName(string name); // Sets the first name to the string passed in
	void setFullName(string fname, string lname);

	string getFirstName();
	string getLastName();
	string getFullName();


private:
	string fname; // for the first name
	string lname; // for the last name
	string fullName;

	// You may add any private member functions you may need

};

// Calls to string
ostream& operator <<(ostream& out, const Professor& p);

#endif