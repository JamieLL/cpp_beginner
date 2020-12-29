#include"workerManager.h"

WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在
	if (!ifs.is_open()) {
		//cout << "file does not exist" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "file is empty." << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
	int num = this->get_EmpNum();
	//cout << "The number of employees is " << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	init_Emp();
	this->m_FileIsEmpty = false;
	ifs.close();
	return;
}

void WorkerManager::showMenu() {
	cout << "***********************************************" << endl;
	cout << "*****" << "Welcome to Employee Management System" << "*****" << endl;
	cout << "*************" << "  0. Exit            " << "*************" << endl;
	cout << "*************" << "  1. Add Employee    " << "*************" << endl;
	cout << "*************" << "  2. Show Employee   " << "*************" << endl;
	cout << "*************" << "  3. Delete Employee " << "*************" << endl;
	cout << "*************" << "  4. Modify Employee " << "*************" << endl;
	cout << "*************" << "  5. Search Employee " << "*************" << endl;
	cout << "*************" << "  6. Sort Employee   " << "*************" << endl;
	cout << "*************" << "  7. Reset           " << "*************" << endl;
	cout << "***********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem() {
	cout << "Have a good day!" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp() {
	cout << "How many employees do you want to add?" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];
		//原来的数据放到新空间下
		if (this->m_EmpArray != NULL) {
			for (int i = 0;i < this->m_EmpNum;i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//新数据
		for (int i = 0;i < addNum;i++) {
			int id;
			string name;
			int dSelect;
			cout << "Please enter No." << i + 1 << " Employee's ID: " << endl;
			cin >> id;
			cout << "Please enter No." << i + 1 << " Employee's name: " << endl;
			cin >> name;
			cout << "Please select this employee's position: " << endl;
			cout << "1. Employee" << endl;
			cout << "2. Manager" << endl;
			cout << "3. Boss" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		this->save();
		this->m_FileIsEmpty = false;
		cout << "Add " << addNum << " employee(s) successfully." << endl;
	}
	else {
		cout << "Wrong number." << endl;
	}
}

void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0;i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		switch (dId)
		{
		case 1:
			worker = new Employee(id, name, dId);
			break;
		case 2:
			worker = new Manager(id, name, dId);
			break;
		case 3:
			worker = new Boss(id, name, dId);
			break;
		default:
			break;
		}
		this->m_EmpArray[index++] = worker;
	}
	ifs.close();
}

void WorkerManager::show_Emp() {
	if (this->m_EmpNum == 0) {
		cout << "No employee record." << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i]->showInfo();
		}
	}
}

//id存在返回index，不存在返回-1
int WorkerManager::isExist(int id) {
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_ID == id) {
			return i;
		}
	}
	return -1;
}

void WorkerManager::del_Emp() {
	if (this->m_EmpNum == 0) {
		cout << "Record is empty." << endl;
		return;
	}
	int id;
	cout << "Please enter the id of the employee you want to delete." << endl;
	cin >> id;
	int index = isExist(id);
	if (index != -1) {
		for (int i = index; i < this->m_EmpNum - 1; i++) {
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--;
		if (this->m_EmpNum == 0) {
			this->m_FileIsEmpty = true;
		}
		this->save();
		cout << "Delete successfully." << endl;
	}
	else {
		cout << "Delete failed. This employee does not exist." << endl;
	}
}

void WorkerManager::mod_Emp() {
	if (this->m_EmpNum == 0) {
		cout << "Record is empty." << endl;
		return;
	}
	int id;
	cout << "Please enter the id of the employee you want to modify." << endl;
	cin >> id;
	int index = isExist(id);
	if (index != -1) {
		cout << "Find employee： " << endl;
		this->m_EmpArray[index]->showInfo();
		delete this->m_EmpArray[index];

		int newId;
		string newName;
		int newDept;
		cout << "Please enter new ID: " << endl;
		cin >> newId;
		cout << "Please enter new name: " << endl;
		cin >> newName;
		cout << "Please enter new department ID: " << endl;
		cout << "1. Employee" << endl;
		cout << "2. Manager" << endl;
		cout << "3. Boss" << endl;
		cin >> newDept;

		Worker* worker = NULL;
		switch (newDept)
		{
		case 1:
			worker = new Employee(newId, newName, newDept);
			break;
		case 2:
			worker = new Manager(newId, newName, newDept);
			break;
		case 3:
			worker = new Boss(newId, newName, newDept);
			break;
		default:
			break;
		}
		this->m_EmpArray[index] = worker;
		cout << "Modify successfully." << endl;
		this->save();
	}
	else {
		cout << "Failed. This employee does not exist." << endl;
	}
}

void WorkerManager::find_Emp() {
	if (this->m_EmpNum == 0) {
		cout << "Record is empty." << endl;
		return;
	}
	cout << "Please enter the way to search: " << endl;
	cout << "1. By ID" << endl;
	cout << "2. By Name" << endl;
	int choice;
	cin >> choice;
	//按id查找
	if (choice == 1) {
		int id;
		cout << "Please enter the *id* of the employee you want to find." << endl;
		cin >> id;
		int index = isExist(id);
		if (index != -1) {
			cout << "Search successfully. Info as below: " << endl;
			this->m_EmpArray[index]->showInfo();
		}
		else {
			cout << "This employee does not exist." << endl;
		}
	}
	//按姓名查找
	else if (choice == 2) {
		string name;
		cout << "Please enter the *name* of the employee you want to find." << endl;
		cin >> name;

		bool flag = false;
		for (int i = 0; i < this->m_EmpNum;i++) {
			if (m_EmpArray[i]->m_Name == name) {
				flag = true;
				cout << "Search successfully. For employee id = " << m_EmpArray[i]->m_ID <<", info is as below: " << endl;
				this->m_EmpArray[i]->showInfo();
			}
		}
		if (flag == false) {
			cout << "Failed. This person does not exist." << endl;
		}
	}
}

void WorkerManager::sort_Emp() {
	if (this->m_EmpNum == 0) {
		cout << "Record is empty." << endl;
		return;
	}
	cout << "Please select the way to sort: " << endl;
	cout << "1. Id Assending" << endl;
	cout << "2. Id Descending" << endl;

	int choice;
	cin >> choice;
	for (int i = 0;i < this->m_EmpNum;i++) {
		int minOrMax = i;
		for (int j = i + 1;j < this->m_EmpNum;j++) {
			if (choice == 1) {
				if (m_EmpArray[minOrMax]->m_ID > m_EmpArray[j]->m_ID) {
					minOrMax = j;
				}
			}
			else if (choice == 2) {
				if (m_EmpArray[minOrMax]->m_ID < m_EmpArray[j]->m_ID) {
					minOrMax = j;
				}
			}
		}
		if (i != minOrMax) {
			Worker* temp = m_EmpArray[i];
			m_EmpArray[i] = m_EmpArray[minOrMax];
			m_EmpArray[minOrMax] = temp;
		}
	}

	this->save();
	cout << "Sort Successfully. The list after sort: " << endl;
	this->show_Emp();
}

void WorkerManager::clean_File() {
	cout << "Are you sure to delete all data?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No. Go Back" << endl;

	int choice;
	cin >> choice;
	if (choice == 1) {
		//ios::trunc如果存在则删除文件重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray != NULL) {
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "Clean successfully." << endl;
	}
}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray != NULL) {
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}