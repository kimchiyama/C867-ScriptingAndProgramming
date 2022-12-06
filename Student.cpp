#include <iostream>
#include <string>

using namespace std;

#include "Student.h"

//------ Empty Constructor
Student::Student() {
	this->StudentID = "";
	this->FirstName = "";
	this->LastName = "";
	this->EmailAddress = "";
	this->Age = 0;
	for (int i = 0; i < DaysInCourse; i++) this->Days[i] = 0;
	this->degreeProgram = DegreeProgram::NETWORK;
}


//------ Full Constructor
Student::Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int Days[], DegreeProgram degreeProgram) {
	this->StudentID = StudentID;
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->EmailAddress = EmailAddress;
	this->Age = Age;
	for (int i = 0; i < DaysInCourse; i++) this->Days[i] = Days[i];
	this->degreeProgram = degreeProgram;
}


//------ Destructor
Student::~Student() {}


//------ Setters
void Student::setStudentID(string StudentID) { this->StudentID = StudentID; }
void Student::setFirstName(string FirstName) { this->FirstName = FirstName; }
void Student::setLastName(string LastName) { this->LastName = LastName; }
void Student::setEmailAddress(string EmailAddress) { this->EmailAddress = EmailAddress; }
void Student::setAge(int Age) { this->Age = Age; }
void Student::setDays(int Days[]) {
	for (int i = 0; i < DaysInCourse; i++) this->Days[i] = Days[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }


//------ Getters
string Student::getStudentID() { return this->StudentID; }
string Student::getFirstName() { return this->FirstName; }
string Student::getLastName() { return this->LastName; }
string Student::getEmailAddress() { return this->EmailAddress; }
int Student::getAge() { return this->Age; }
int* Student::getDays() { return this->Days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//------ Print
void Student::printHeader() {
	cout << "\n";
}
void Student::print() {
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout <<  '{' << this->getDays()[0] << ',' << this->getDays()[1] << ',' << this->getDays()[2] << '}' << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}
