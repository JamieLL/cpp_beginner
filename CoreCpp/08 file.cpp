#include<iostream>
#include<fstream>
#include <string>
using namespace std;

//写文件
void test08_01() {
	ofstream ofs;
	ofs.open("./filetest.txt", ios::out);
	ofs << "hello world1" << endl;
	ofs << "hello world2" << endl;
	ofs << "hello world3" << endl;
	ofs.close();
}

//读文件
void test08_02() {
	ifstream ifs;
	ifs.open("./filetest.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "file fails to open" << endl;
		return;
	}
	//1.第一种读取方式
	//char buf[1024] = { 0 };
	//while (ifs >> buf) {
	//	cout << buf << endl;
	//}

	//2.第二种读取方式
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf))) {
	//	cout << buf << endl;
	//}

	//3.第三种读取方式
	string buf;
	while (getline(ifs, buf)) {
		cout << buf << endl;
	}

	//4.第四种读取方式
	//char c;
	//while ((c = ifs.get()) != EOF) {
	//	cout << c;
	//}


	ifs.close();
}

//二进制方式写
class Person_08 {
public:
	char m_Name[64]; //string容易出现问题
	int m_Age;
};
void test08_03() {
	ofstream ofs;
	ofs.open("file_person.txt", ios::out | ios::binary);
	Person_08 p = { "jm", 18 };
	ofs.write((const char*)&p, sizeof(Person_08));
	ofs.close();
}

//二进制方式读
void test08_04() {
	ifstream ifs;
	ifs.open("file_person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "file fails to open" << endl;
	}
	Person_08 p;
	ifs.read((char*)&p, sizeof(Person_08));
	cout << "name: " << p.m_Name << " age: " << p.m_Age << endl;
	ifs.close();
}

int main8() {
	test08_01();
	test08_02();
	test08_03();
	test08_04();

	system("pause");
	return 0;
}