#include <iostream>
#include <string>

using namespace std;

#include "Roster.h"

Roster::Roster() {}

//------ Parsing
void Roster::parse(string studentData) {
	//------ Identifying Degree Program for Students
	DegreeProgram degreeProgram = NETWORK;
	if (studentData.back() == 'Y') degreeProgram = SECURITY;
	else if (studentData.back() == 'E') degreeProgram = SOFTWARE;

	//------ Parsing Student Data
	int rhs = studentData.find(",");
	string StudentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string FirstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string LastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string EmailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Days1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Days2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Days3 = stoi(studentData.substr(lhs, rhs - lhs));

	add(StudentID, FirstName, LastName, EmailAddress, Age, Days1, Days2, Days3, degreeProgram);
}

//------ Print

void Roster::add(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int Days1, int Days2, int Days3, DegreeProgram degreeProgram) {
	int Days[3] = { Days1, Days2, Days3 };
	classRosterArray[++lastIndex] = new Student(StudentID, FirstName, LastName, EmailAddress, Age, Days, degreeProgram);
}


void Roster::remove(string StudentID) {
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == StudentID)
		{
			success = true;
			if (i < numberStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numberStudents - 1];
				classRosterArray[numberStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
}



void Roster::printAll() {
	Student::printHeader();
		for (int i = 0; i <= Roster::lastIndex; i++) {
			Roster::classRosterArray[i]->print();
	}
}


void Roster::printAverageDaysInCourse(string StudentID) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == StudentID) {
			cout << "Student ID: " << StudentID << "," << " average days in course is: " << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3 << endl;
		}
	}
}


void Roster::printInvalidEmails() {
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string EmailAddress = (classRosterArray[i]->getEmailAddress());
		if (EmailAddress.find('.') == string::npos || (EmailAddress.find("@") == string::npos || (EmailAddress.find(' ') != string::npos))) {
			any = true;
			cout << classRosterArray[i]->getEmailAddress() << endl;
		}
	}
	if (!any) cout << "NO INVALID EMAILS" << endl;
}


void Roster::printByDegree(DegreeProgram degreeProgram) {
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
			classRosterArray[i]->print();
	}
	cout << endl;
}


Roster::~Roster() {
	cout << "Destructor Called" << endl;
	for (int i = 0; i < numberStudents; i++) {
		cout << "The Student with the ID: " << i + 1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
};
