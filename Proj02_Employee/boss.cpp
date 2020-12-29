#include"boss.h"

Boss::Boss(int id, string name, int dID) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}

void Boss::showInfo() {
	cout << "Employee ID: " << this->m_ID <<
		"\tEmployee Name: " << this->m_Name <<
		"\tEmployee Department: " << this->getDeptName() <<
		"\tMission: Manage the whole company. Lying on the bed and get money." << endl;
}

string Boss::getDeptName() {
	return string("Boss");
}