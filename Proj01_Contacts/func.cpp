#include<iostream>
#include"head.h"
using namespace std;

void addperson(Contacts* ctBook) {
	if (ctBook->p_size == MAX) {
		cout << "Failed. Contacts is full." << endl;
		return;
	}
	else {
		string name;
		cout << "Name: " << endl;
		cin >> name;
		ctBook->people[ctBook->p_size].m_name = name;

		int sex; // 1-male, 2-female
		cout << "Sex: 1. Male 2. Female" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				ctBook->people[ctBook->p_size].m_sex = sex;
				break;
			}
			cout << "Please enter 1 or 2." << endl;
		}

		int age;
		cout << "Age: " << endl;
		cin >> age;
		ctBook->people[ctBook->p_size].m_age = age;

		string phone;
		cout << "Phone: " << endl;
		cin >> phone;
		ctBook->people[ctBook->p_size].m_phone = phone;

		string address;
		cout << "Address: " << endl;
		cin >> address;
		ctBook->people[ctBook->p_size].m_address = address;

		ctBook->p_size++;
		cout << "Add person successfully!" << endl;
	}
}

void showcontacts(const Contacts* ctBook) {
	if (ctBook->p_size == 0) {
		cout << "The Contacts is empty." << endl;
		return;
	}
	for (int i = 0;i < ctBook->p_size;i++) {
		cout << "Name: " << ctBook->people[i].m_name <<
			"\tSex: " << (ctBook->people[i].m_sex == 1 ? "male" : "female") <<
			"\tAge: " << ctBook->people[i].m_age <<
			"\tPhone: " << ctBook->people[i].m_phone <<
			"\tAddress: " << ctBook->people[i].m_address << endl;
	}
}

// if exits: retutn position, otherwise return -1
int isExist(const Contacts* ctBook, string name) {
	for (int i = 0;i < ctBook->p_size;i++) {
		if (ctBook->people[i].m_name == name) {
			return i;
		}
	}
	return -1;
}

void deleteperson(Contacts* ctBook) {
	cout << "Please enter the person's name you want to delete: " << endl;
	string name;
	cin >> name;
	int pos = isExist(ctBook, name);
	if (pos == -1) {
		cout << "This person does not exist." << endl;
		return;
	}
	for (int i = pos; i < ctBook->p_size-1;i++) {
		ctBook->people[i] = ctBook->people[i + 1];
	}
	ctBook->p_size--;
	cout << "Delete person from Contacts successfully." << endl;
}

void findperson(const Contacts* ctBook) {
	cout << "Please enter the person's name you want to find: " << endl;
	string name;
	cin >> name;
	int pos = isExist(ctBook, name);
	if (pos == -1) {
		cout << "This person does not exist." << endl;
		return;
	}
	cout << "Name: " << ctBook->people[pos].m_name <<
		"\tSex: " << (ctBook->people[pos].m_sex == 1 ? "male" : "female") <<
		"\tAge: " << ctBook->people[pos].m_age <<
		"\tPhone: " << ctBook->people[pos].m_phone <<
		"\tAddress: " << ctBook->people[pos].m_address << endl;
}

void modifyperson(Contacts* ctBook) {
	cout << "Please enter the person's name you want to find: " << endl;
	string name;
	cin >> name;
	int pos = isExist(ctBook, name);
	if (pos == -1) {
		cout << "This person does not exist." << endl;
		return;
	}

	cout << "Name: " << endl;
	cin >> name;
	ctBook->people[pos].m_name = name;

	int sex; // 1-male, 2-female
	cout << "Sex: 1. Male 2. Female" << endl;
	while (true) {
		cin >> sex;
		if (sex == 1 || sex == 2) {
			ctBook->people[pos].m_sex = sex;
			break;
		}
		cout << "Please enter 1 or 2." << endl;
	}

	int age;
	cout << "Age: " << endl;
	cin >> age;
	ctBook->people[pos].m_age = age;

	string phone;
	cout << "Phone: " << endl;
	cin >> phone;
	ctBook->people[pos].m_phone = phone;

	string address;
	cout << "Address: " << endl;
	cin >> address;
	ctBook->people[pos].m_address = address;

	cout << "Modify person successfully!" << endl;
}

void resetcontacts(Contacts* ctBook) {
	ctBook->p_size = 0;
	cout << "Reset Contacts successfully." << endl;
}