#include<iostream>
#define MAX 1000
using namespace std;

struct Person {
	string m_name;
	int m_sex; // 1-male, 2-female
	int m_age;
	string m_phone;
	string m_address;
};

struct Contacts {
	struct Person people[MAX];
	int p_size;
};

void addperson(Contacts* ctBook);
void showcontacts(const Contacts* ctBook);
int isExist(const Contacts* ctBook, string name);
void deleteperson(Contacts* ctBook);
void findperson(const Contacts* ctBook);
void modifyperson(Contacts* ctBook);
void resetcontacts(Contacts* ctBook);