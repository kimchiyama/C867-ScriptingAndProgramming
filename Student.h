#pragma once
#include <iostream>
#include "Degree.h"

using namespace std;

class Student {

public:
	//------ For the array
	const static int DaysInCourse = 3;


private:
	string StudentID;
	string FirstName;
	string LastName;
	string EmailAddress;
	int Age;
	int Days[DaysInCourse];
	DegreeProgram degreeProgram;

public:
	//------ Empty Constructor
	Student();

	//------ Full Constructor
	Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int Days[], DegreeProgram degreeProgram);

	//------ Destructor
	~Student();


	//------ Getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram();

	//------ Setters
	void setStudentID(string StudentID);
	void setFirstName(string FirstName);
	void setLastName(string LastName);
	void setEmailAddress(string EmailAddress);
	void setAge(int Age);
	void setDays(int Days[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//------Print
	static void printHeader();

	void print();

};

