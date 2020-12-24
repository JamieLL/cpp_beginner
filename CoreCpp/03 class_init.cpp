#include<iostream>
using namespace std;

<<<<<<< HEAD
//构造函数和析构函数
=======
>>>>>>> 2ef7c2322b997a5debd960d68cd97cd91ede3c7c
class Person03 {
public:
	//无参构造函数
	Person03() {
		cout << "Person无参构造函数的调用" << endl;
	}
	//有参构造函数
	Person03(string name, int a) {
		m_name = name;
		m_age = new int(a);
		cout << "Person有参构造函数的调用" << endl;
	}
	//深拷贝的拷贝构造函数
	Person03(const Person03& p) {
		m_name = p.m_name;
		//m_age = p.m_age; // 默认的浅拷贝
		m_age = new int(*p.m_age);
		cout << "Person拷贝构造函数的调用" << endl;
	}

	//析构函数
	~Person03() {
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL; // 防止出现野指针：即若原地址被重新分配给别的，该野指针就会指向新的，可能产生不好的后果
		}
		cout << "Person析构函数的调用" << endl;
	}

	string m_name;
	int* m_age;
};

<<<<<<< HEAD
//初始化列表，浅拷贝
=======

>>>>>>> 2ef7c2322b997a5debd960d68cd97cd91ede3c7c
class Student {
public:
	//初始化列表初始化属性
	Student(int a, int b) :m_a(a), m_b(b) {}

	int m_a;
	int m_b;
};

void test01() {
	Person03 p1; // 调用默认构造函数时，不要加()
	Person03 p2("jm", 18); // Person03 p2 = Person03(18); // Person03 p2 = 18;
	// 这是浅拷贝
	Person03 p3(p2); // Person03 p3 = Person03(p2); // Person03 p3 = p2;

	Person03("aaa", 10); // 匿名对象，在当前行结束后，系统会立即回收

	cout << "p2's name: " << p2.m_name << "\tp2's age: " << *p2.m_age << endl;
	cout << "p3's name: "<< p3.m_name << "\tp3's age: " << *p3.m_age << endl;
	//因为局部变量在栈区，所以后创建的先被回收


	Student s1(10, 20);
}

<<<<<<< HEAD
//静态成员
class Member {
public:
	static void func() {
		m_A = 100;
		//m_B = 200; //静态成员函数不能访问非静态成员变量，因为无法区分是哪个对象的
		cout << "static func的调用" << endl;
	}

	static int m_A;
	int m_B;
};
//静态成员变量在类外要先初始化
int Member::m_A = 0;

void test02() {
	Member m;
	m.func();
	// 通过类名访问
	Member::func();
}

//this指针
class Pthis {
public:
	Pthis(int age) {
		this->age = age;
	}
	void addage(Pthis& p) {
		this->age += p.age;
	}
	Pthis& addages(Pthis& p) {
		this->age += p.age;
		return *this;
	}

	int age;
};

void test03() {
	Pthis p1(10);
	Pthis p2(10);
	p2.addage(p1);
	cout << "p2's age: " << p2.age << endl;
	p2.addages(p1).addages(p1).addages(p1);
	cout << "p2's age: " << p2.age << endl;
}

int main3() {
	test01();
	test02();
	test03();
=======
int main() {
	test01();
>>>>>>> 2ef7c2322b997a5debd960d68cd97cd91ede3c7c

	system("pause");
	return 0;
}