#include<iostream>
#include"workerManager.h"
using namespace std;



int main() {
	WorkerManager wm;
	int choice = 0;
	
	while (true)
	{
		wm.showMenu();
		cout << "Please enter your choice" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出
			wm.exitSystem();
			break;
		case 1://添加
			wm.Add_Emp();
			break;
		case 2://展示
			wm.show_Emp();
			break;
		case 3://删除
			wm.del_Emp();
			break;
		case 4://修改
			wm.mod_Emp();
			break;
		case 5://搜索
			wm.find_Emp();
			break;
		case 6://排序
			wm.sort_Emp();
			break;
		case 7://清空
			wm.clean_File();
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	

	system("pause");
	return 0;
}