#pragma once
#include "Student.h"

class Roster {
public:
	const static int numberStudents = 5;
	Student* classRosterArray[numberStudents];
	int lastIndex = -1;

	//------Empty Constructor
	Roster();

	//------ Destructor
	~Roster();

	//------ Parse
	void parse(string row);

	void add(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int Day1, int Day2, int Day3, DegreeProgram degreeProgram);
	void printAll();
	void remove(string StudentID);
	void printInvalidEmails();
	void printAverageDaysInCourse(string StudentID);
	void printByDegree(DegreeProgram degreeProgram);
};
