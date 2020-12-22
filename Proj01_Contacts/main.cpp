#include<iostream>
#include"head.h"
using namespace std;

void showMenu() {
	cout << "*****************************" << endl;
	cout << "***** 1. add person     *****" << endl;
	cout << "***** 2. show contacts  *****" << endl;
	cout << "***** 3. delete person  *****" << endl;
	cout << "***** 4. find person    *****" << endl;
	cout << "***** 5. modify person  *****" << endl;
	cout << "***** 6. reset contacts *****" << endl;
	cout << "***** 0. exit           *****" << endl;
	cout << "*****************************" << endl;
}

int main() {
	Contacts contactBook;
	contactBook.p_size = 0;

	int choice = 0;

	while (true) {
		showMenu();
		cin >> choice;
		switch (choice) {
		case 1:
			addperson(&contactBook);
			break;
		case 2:
			showcontacts(&contactBook);
			break;
		case 3:
			deleteperson(&contactBook);
			break;
		case 4:
			findperson(&contactBook);
			break;
		case 5:
			modifyperson(&contactBook);
			break;
		case 6:
			resetcontacts(&contactBook);
			break;
		case 0:
			cout << "bye" << endl;
			system("pause");
 			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}