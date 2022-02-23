// <Brandon Hudson>
// Prigramming Assignment 1
// CS340
// Fall 2019

#include<iostream>
#include<fstream>
#include<cstdlib>
#include <string>
#include <fstream>
#include "Professor.h"
#include "BSTree.h"
#include "Course.h"
#include "List.h"
using namespace std;




string arr[100];

Professor profArr[50];
Professor root;

// Asks the user to type in a file name - and then loads all of the classes
// and the teachers into the class list, classList. The classList and the
// filename are passed into this function - both will be changed inside the
// function
void readFile(string& fileName, List< Course<Professor> >& classList);

// Asks the user to type in the class name, and the first and last name
// of the professor. The classList is passed into this function. The
// professor will be added to the class when the function is executed.
// If the class name entered doesn't exist in the list, the list is not 
// changed and an error message is shown on the screen (see output)
// Hint - you may want to pull the list node out of the list (delete it), and then 
// add the proessor to the tree, and then put the node back into the list
void addProfessor(List <Course<Professor> >& classList);

// Asks the the user to type in the class name, and the first and last name
// of the professor. The classList is passed into this function. The
// professor will be deleted from the class when the function is executed.
// If the class name entered doesn't exist in the list, the list is not 
// changed and an error message is shown on the screen (see output)
// Hint - you may want to pull the list node out of the list (delete it), and then 
// remove the professor from the tree, and then put the node back into the list
//void deleteProfessor(List <Course<Professor> > &classList);

// Asks the user to type in the class name. The class will be deleted from 
// the classList. If that class entered doesn't exist in the list, the list is  
// not changed and an error message is shown on the screen (see output)
// The classList is passed into this function
//void deleteClass(List <Course<Professor> > &classList);

// Asks the user to type in the class name. The class will be added to 
// the classList - it will have no professors
void addClass(List <Course<Professor> >& classList);

// Prints the menu to the screen and returns the users selection
int printMenu();

// Opens the file that was entered in ReadFile, and writes the information
// from the list back to the file in the same format so the file can be used 
// again with this program. The class list and filename are passed into this 
// function. The files should be written to in PREORDER, so when it is read
// in again the employees are not in order.
//void writeFile(string fileName, List< Course<Professor> > classList);

void printList();

//template <typename DataType>
int main()
{
	cout << "Programmed by <Brandon Hudson> \n\n";



	List<Course<Professor>> classList;// Define a cList called ClassList
						   // The list should be of type
						   // cClasses


	int selection;
	string fileName = "DataFile.txt";


	//	cout << "Enter the file you want to read in: " << endl;
	//cin >> fileName;




	//readFile(fileName, classList);


	//BSTree tree = new BSTree();


	do
	{
		selection = printMenu();
		switch (selection)
		{

		case 1:
			readFile(fileName, classList);
			//classList.printList();
			break;
		case 2:
			addProfessor(classList);

			break;
		case 3:
			//deleteProfessor(classList);
			break;
		case 4:
			//deleteClass(classList);
			break;
		case 5:
			addClass(classList);
			break;
		case 6:
			cout << "Writing to file ....\n";
			//writeFile(fileName, classList);
			cout << "Done\n";
			break;
		case 7:
			cout << endl << arr[1] << endl;
			break;
		default:
			cout << "Invalid selection! Please Re-enter!\n";
		}
	} while (selection != 6);

	return 0;
}

void readFile(string& fileName, List<Course<Professor>>& classList) {
	string output;
	string className;
	ifstream fin;

	Professor prof;
	Professor tempP;

	Course<Professor> p;




	string strClass = "Class:";
	string strTeacher = "Teachers:";


	fin.open("DataFile.txt");

	if (fin.is_open()) {

		while (!fin.eof()) {

			fin >> output;

			if (output.compare(strClass) == 0) {
				fin >> output;
				className = output;
				p.setCourseName(output);
			}
			else if (output.compare(strTeacher) == 0) {
				do {
					if (output.compare(strClass) == 0) { break; }
					fin >> output;
					prof.setLastName(output);


					if (output.compare(strClass) == 0) { break; }
					fin >> output;
					prof.setFirstName(output);
					prof.setFullName(prof.getFirstName(), prof.getLastName());

					cout << prof.getFullName() << endl;

					p.insertProf(tempP, prof);
				} while (output.compare(strClass) != 0);
			}
			else {
				className = output;
				fin >> output;
			}

			classList.insert(p);

			//fin >> output;



		}
		fin.close();
	}


	//p.insertProf(prof);
	//p.insertProf(tempP);
	cout << "Done!" << endl;
}

int printMenu() {
	cout << "1. Print Course and professors" << endl;
	cout << "2. Add Instructor to course" << endl;
	cout << "3. Delete Instructor to course" << endl;
	cout << "4. Delete Class" << endl;
	cout << "5. Add Class" << endl;
	cout << "6. Exit" << endl;
	cout << "Enter your selection: " << endl;

	int input = 0;

	cin >> input;
	return input;
}

//template <typename DataType>
void addProfessor(List <Course<Professor> >& classList) {
	Professor prof;


	Course<Professor> p;





	//classList.insert(p);



	string cName = p.getCourseName();

	//p.insertProf(prof, tempP);

	cout << "Enter the class to add a professor in: " << endl;
	string newClass;
	cin >> newClass;
	p.setCourseName(newClass);


	cout << "Enter last name of Professor!" << endl;
	string profLName;
	cin >> profLName;


	cout << "Enter last name of Professor!" << endl;
	string profFName;
	cin >> profFName;
	prof.setFullName(profFName, profLName);

	cout << p.getCourseName() << endl << prof.getFullName() << endl;

	string tName = prof.getFullName();
	root = prof;

	p.insertProf(root, prof);

	//classList.insert(p);




}

void printList() {

	cout << "PrintList function called!" << endl;
}

void addClass(List <Course<Professor> >& classList) {

	Course<Professor> p;

	classList.insert(p);
	cout << "addclass function" << endl;
}