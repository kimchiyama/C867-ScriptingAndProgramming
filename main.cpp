#include <iostream>
#include <string>

using namespace std;

#include "Roster.h"
#include "Student.h"

int main()
{
	//------ Personal Output Data
	cout << "C867-Scripiting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: XXXXXXXXX" << endl;
	cout << "Name: FIRSTNAME LASTNAME" << endl;
	cout << "\n";


	//------ Input Student Data
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,FIRSTNAME,LASTNAME,EMAILADDRESS@wgu.edu,29,20,45,32,SOFTWARE"
	};

	const int numberStudents = 5;
	Roster classRoster;

	for (int i = 0; i < numberStudents; i++) classRoster.parse(studentData[i]);

	cout << "Displaying all Students:" << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Displaying invalid emails:" << endl;
	cout << "\n";
	classRoster.printInvalidEmails();
	cout << endl;


	for (int i = 0; i < numberStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}

	cout << "\n";
	cout << "Showing students in degree program: " << degreeProgramStrings[2] << endl;
	classRoster.printByDegree(SOFTWARE);
	cout << endl;

	cout << "Removing A3:" << endl;
	classRoster.remove("A3");

	classRoster.printAll();
	cout << endl;

	cout << "Removing A3 again" << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << "The student with the ID: A3 was not found" << endl;

	system("pause");
	return 0;

}
