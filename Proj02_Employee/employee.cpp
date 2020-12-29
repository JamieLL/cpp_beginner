#include"employee.h"

Employee::Employee(int id, string name, int dID) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}

void Employee::showInfo() {
	cout << "Employee ID: " << this->m_ID <<
		"\tEmployee Name: " << this->m_Name <<
		"\tEmployee Department: " << this->getDeptName() <<
		"\tMission: Follow Manager" << endl;
}

string Employee::getDeptName() {
	return string("Employee");
}