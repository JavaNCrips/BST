// <Brandon Hudson>
// Prigramming Assignment 1
// CS340
// Fall 2019

 // This is a templated class
#ifndef COURSE_H
#define COURSE_H

#include "BSTree.h"
#include "Professor.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//typedef string DataType;


// This class must templated
template <class DataType>
class Course
{
public:
	// Declare a templated binary search tree that contains the professors
	// that teach the  class - done for you - do not change 
	BSTree<DataType> professors;



	Course() {
		courseName = " ";
	}




	// Changes the course name to be the name passed in
	void setCourseName(string course)
	{

		courseName = course;
	}

	// Returns the course name
	string getCourseName() const
	{
		return courseName;
	}

	// overloaded operators
	bool  operator <(DataType course)
	{

		if (course->courseName.compare(courseName) < 0) { return true; }
		else
			return false;
	}

	bool  operator <=(DataType course)
	{
		if (course->courseName.compare(courseName) <= 0) { return true; }
		else
			return false;
	}

	bool  operator ==(DataType course)
	{
		if (course->courseName.compare(courseName) == 0) { return true; }
		else
			return false;
	}

	template <typename T>
	bool  operator !=(T course)
	{
		Course<Professor> c;


		if (c.getCourseName().compare(courseName) != 0) { return true; }
		else
			return false;
	}

	// inserts an element into the tree
	template <typename T>
	void insertProf(T n, T data)
	{
		//professors.createNode(data);
		//newNode = professors.temp;
		professors.insert(n, data);
	}


	// Deletes an item (passed in) from the templated tree
	// returns a true if deleted and a false if 
	// not in tree, so not deleted
	bool deleteProf()
	{

	}

	// Writes the tree in preorder using the ostream that 
	// is passed in 
	void writeProfstoFile()
	{
	}


private:
	// Stores the class name (ex CS140)
	// Do not change the data member 
	string courseName;

	// Can add any private member functions you want
	// if you need to

};

// Overloaded operator
// prints the course namd and the tree to the screen as 
// shown on the output

/*ostream & operator <<(DataType T, Datatype U)
{
}*/
#endif