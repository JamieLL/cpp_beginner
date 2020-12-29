#pragma once
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<iostream>
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;


class WorkerManager {
public:
	WorkerManager();
	
	void showMenu();
	void exitSystem();
	void Add_Emp();
	void save();
	int get_EmpNum();
	void init_Emp();
	void show_Emp();
	void del_Emp();
	int isExist(int id);
	void mod_Emp();
	void find_Emp();
	void sort_Emp();
	void clean_File();

	~WorkerManager();

	int m_EmpNum;
	Worker** m_EmpArray;
	bool m_FileIsEmpty;
};