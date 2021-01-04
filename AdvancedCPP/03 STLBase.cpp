#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void myPrint(int val) {
	cout << val << endl;
}

void test03_01() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	//第一种遍历方式
	vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中第一个元素
	vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器中最后一个元素的下一个位置
	while (itBegin != itEnd) {
		cout << *itBegin << endl;
		itBegin++;
	}

	//第二种遍历方式
	for (vector<int>::iterator it = v.begin(); it != v.end();it++) {
		cout << *it << endl;
	}

	//第三种遍历方式：STL种提供的遍历算法
	for_each(v.begin(), v.end(), myPrint);
}

class Person03 {
public:
	Person03(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test03_02() {
	vector<Person03> v;
	Person03 p1("jm", 18);
	Person03 p2("jmm", 3);
	Person03 p3("mm", 20);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	for (vector<Person03>::iterator it = v.begin(); it != v.end();it++) {
		cout << "name: " << (*it).m_Name << " age: " << (*it).m_Age << endl;
		cout << "name: " << it->m_Name << " age: " << it->m_Age << endl;
	}
}

//存放自定义数据类型 指针
void test03_03() {
	vector<Person03*> v;
	Person03 p1("jm", 18);
	Person03 p2("jmm", 3);
	Person03 p3("mm", 20);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);

	//Person03*，所以(*it)是指针
	for (vector<Person03*>::iterator it = v.begin(); it != v.end();it++) {
		// Person03* p = (*it);
		// p->m_Name
		cout << "name: " << (*it)->m_Name << " age: " << (*it)->m_Age << endl;
		cout << "name: " << (*(*it)).m_Name << " age: " << (*(*it)).m_Age << endl;
	}
}

//容器嵌套容器
void test03_04() {
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	for (int i = 0; i < 3;i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 4);
		v3.push_back(i + 7);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		for (vector<int>::iterator vit = (*it).begin();vit != (*it).end();vit++) {
			cout << *vit << " ";
		}
		cout << endl;
	}
}

int main() {
	test03_01();
	test03_02();
	test03_03();
	test03_04();

	system("pause");
	return 0;
}