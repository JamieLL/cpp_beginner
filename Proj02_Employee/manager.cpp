#include"manager.h"

Manager::Manager(int id, string name, int dID) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}

void Manager::showInfo() {
	cout << "Employee ID: " << this->m_ID <<
		"\tEmployee Name: " << this->m_Name <<
		"\tEmployee Department: " << this->getDeptName() <<
		"\tMission: Manage Employees and follow Boss" << endl;
}

string Manager::getDeptName() {
	return string("Manager");
}