#include<iostream>
using namespace std;

class Person05 {
	friend ostream& operator<<(ostream& cout, Person05 p);
public:
	Person05() {}
	Person05(int a, int b) {
		m_A = a;
		m_B = b;
	}
	// 通过成员函数重载
	Person05 operator+(Person05& p) {
		Person05 temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}

private:
	int m_A;
	int m_B;
};

// 通过全局函数重载
//Person05 operator+(Person05& p1, Person05& p2) {
//	Person05 temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}

// 本质简化为cout << p;
// 返回ostream&是为了链式编程
ostream& operator<<(ostream& cout, Person05 p) {
	cout << "m_A = " << p.m_A << ", m_B = " << p.m_B;
	return cout;
}

void test05_01() {
	Person05 p05_1(10, 10);
	Person05 p05_2(10, 10);
	Person05 p05_3 = p05_1 + p05_2;
	// 等同于Person05 p05_3 = p05_1.operator+(p05_2); Person05 p05_3 = operator+(p05_1, p05_2)

	cout << p05_3 << endl;
}

class MyInteger {
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger() {
		m_Num = 0;
	}
	//重载前置++
	//返回引用，是为了一直对一个数据进行++；否则++(++myint)后myint只加了一次
	MyInteger& operator++() {
		m_Num++;
		return *this;
	}
	//重载后置++
	//int代表的是占位参数，可用于区分前置和后置递增
	//返回值，因为temp是局部变量，执行完就被释放了
	MyInteger operator++(int) {
		MyInteger temp = *this;
		m_Num++;
		return temp;
	}
private:
	int m_Num;
};

ostream& operator<<(ostream& cout, MyInteger myint) {
	cout << myint.m_Num;
	return cout;
}

void test05_02() {
	MyInteger myint;
	cout << myint << endl;
	cout << ++myint << endl;
	cout << myint++ << endl;
	cout << myint << endl;
}

class Student5 {
public:
	Student5(int age) {
		m_Age = new int(age);
	}
	~Student5() {
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
	}
	//重载 赋值运算符
	Student5& operator=(Student5& s) {
		//m_Age = s.m_Age; //浅拷贝，故析构函数让堆区内存多次释放
		//先判断是否有属性在堆区，若有则先释放再深拷贝
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*s.m_Age);
		return *this;
	}

	int* m_Age;
};

void test05_03() {
	Student5 s1(18);
	Student5 s2(20);
	Student5 s3(30);
	s3 = s2 = s1;

	cout << "s1's age = " << *s1.m_Age << endl;
	cout << "s2's age = " << *s2.m_Age << endl;
	cout << "s3's age = " << *s3.m_Age << endl;
}

class Teacher5 {
public:
	Teacher5(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(Teacher5& t) {
		if (this->m_Name == t.m_Name && this->m_Age == t.m_Age) {
			return true;
		}
		return false;
	}
	bool operator!=(Teacher5& t) {
		if (this->m_Name == t.m_Name && this->m_Age == t.m_Age) {
			return false;
		}
		return true;
	}
	string m_Name;
	int m_Age;
};

void test05_04() {
	Teacher5 t1("tch1", 18);
	Teacher5 t2("tch1", 18);
	Teacher5 t3("tch1", 20);
	if (t1 == t2) {
		cout << "p1 == p2" << endl;
	}
	else {
		cout << "p1 != p2" << endl;
	}
	if (t1 != t3) {
		cout << "p1 != p3" << endl;
	}
	else {
		cout << "p1 == p3" << endl;
	}
}

class MyPrint {
public:
	//重载 函数调用运算符
	void operator()(string txt) {
		cout << txt << endl;
	}
};

class MyPlus {
public:
	int operator()(int num1, int num2) {
		return num1 + num2;
	}
};

void test05_05() {
	MyPrint myPrint;
	myPrint("hello world");//仿函数
	MyPlus myPlus;
	myPlus(10, 10);
	//匿名函数对象
	cout << MyPlus()(100, 100) << endl;
}

int main5() {
	test05_01();
	test05_02();
	test05_03();
	test05_04();
	test05_05();

	system("pause");
	return 0;
}