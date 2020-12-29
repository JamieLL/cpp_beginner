#pragma once
#include"worker.h"
#include<iostream>
using namespace std;

class Manager :public Worker {
public:
	Manager(int id, string name, int dID);
	virtual void showInfo();
	virtual string getDeptName();
};