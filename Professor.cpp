// <Brandon Hudson>
// Prigramming Assignment 1
// CS340
// Fall 2019

#include <string>
#include <fstream>
#include <iostream>
#include "Professor.h"
#include "BSTree.h"
#include "Course.h"
#include "List.h"

using namespace std;



bool Professor::operator <(Professor rhsP) {

	string p_Fullname = rhsP.fname + rhsP.lname;
	string fullName = this->fname + this->lname;

	if (p_Fullname.compare(fullName) == 1) { return true; }
	else {
		cout << p_Fullname.compare(fullName) << endl;
		return false;
	}
}

bool Professor::operator >(Professor rhsP) {
	string p_Fullname = rhsP.fname + rhsP.lname;
	string fullName = this->fname + this->lname;
	cout << p_Fullname.compare(fullName) << endl;

	if (p_Fullname.compare(fullName) == -1) { return true; }
	else
		return false;

}

bool Professor::operator ==(Professor rhsP) {
	string p_Fullname = rhsP.fname + rhsP.lname;
	string fullName = this->fname + this->lname;

	if (p_Fullname.compare(fullName) == 0) { return true; }
	else
		return false;

}


string Professor::operator ->() {
	return getFullName();
}



string  Professor::toString() const {
	string fullName = lname + fname;

	cout << fullName << endl;

	return fullName;
}

void Professor::setLastName(string name) {
	lname = name;
}

void Professor::setFirstName(string name) {
	fname = name;
}

void Professor::setFullName(string fname, string lname) {
	fullName = fname + lname;
}

string Professor::getFirstName() {
	return fname;
}

string Professor::getLastName() {
	return lname;
}

string Professor::getFullName() {
	return fullName;
}




ostream& operator <<(ostream& out, const Professor& p) {

	// p.toString();

	return cout;
}