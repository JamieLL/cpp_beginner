#pragma once
#include"worker.h"
#include<iostream>
using namespace std;

class Employee :public Worker {
public:
	Employee(int id, string name, int dID);
	virtual void showInfo(); // virtual关键字可删可不删
	virtual string getDeptName();
};