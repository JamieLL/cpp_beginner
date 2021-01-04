#include<iostream>
using namespace std;

template<class NameType = string, class AgeType = int>
class Person {
public:
	Person(NameType name, AgeType age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson() {
		cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

//指定传入函数
void printPerson1(Person<string, int>& p) {
	p.showPerson();
}

//参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2>& p) {
	p.showPerson();
	cout << "T1's type is " << typeid(T1).name() << endl;
	cout << "T2's type is " << typeid(T2).name() << endl;
}

//整个类模板化
template<class T>
void printPerson3(T& p) {
	p.showPerson();
	cout << "T's type is " << typeid(T).name() << endl;
}

void test02_01() {
	Person<string, int> p1("jm", 18);
	p1.showPerson();
	printPerson1(p1);
	printPerson2(p1);
	printPerson3(p1);
}


//类外实现
template<class T1, class T2>
class Person2 {
public:
	Person2(T1 name, T2 age);
	void showPerson();

	T1 m_Name;
	T2 m_Age;
};

template<class T1, class T2>
Person2<T1, T2>::Person2(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1, class T2>
void Person2<T1, T2>::showPerson() {
	cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
}

void test02_02() {
	Person2<string, int> p("ll", 30);
	p.showPerson();
}

//-------------------------------------------
//全局函数配合友元，类外函数。先声明
template<class T1, class T2> class Person3;

//先声明，定义可以写在后面
template<class T1, class T2>
void printPerson3_2(Person3<T1, T2>& p) {
	cout << "name: " << p.m_Name << " age: " << p.m_Age << endl;
}

template<class T1, class T2>
class Person3 {
	//全局函数配合友元，类内实现
	friend void printPerson3_1(Person3<T1, T2>& p) {
		cout << "name: " << p.m_Name << " age: " << p.m_Age << endl;
	}
	friend void printPerson3_2<>(Person3<T1, T2>& p);

public:
	Person3(T1 name, T2 age) {
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};

void test02_03() {
	Person3<string, int> p("dd", 32);
	printPerson3_1(p);
	printPerson3_2(p);
}

//-------
//练习例子查看Prac02

int main2() {
	test02_01();
	test02_02();
	test02_03();

	system("pause");
	return 0;
}