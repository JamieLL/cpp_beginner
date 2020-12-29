#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

void test() {
	Worker* worker = NULL;
	worker = new Employee(1, "zs", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "jm", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(2, "mm", 3);
	worker->showInfo();
	delete worker;
}