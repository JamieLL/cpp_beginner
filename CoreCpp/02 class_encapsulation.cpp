#include<iostream>
using namespace std;

const double PI = 3.14;

class Circle {
public:
	int m_r;

	double calPerimeter() {
		return 2 * PI * m_r;
	}
};

class Student {
public:
	int m_id;
	string m_name;

	void show() {
		cout << "id: " << m_id <<
			"\tname: " << m_name << endl;
	}
};

class Person {
public:
	void setName(string name) {
		m_Name = name;
	}
	string getName() {
		return m_Name;
	}
	int getAge() {
		m_Age = 0;
		return m_Age;
	}
private:
	string m_Name;
	int m_Age;
	int m_Phone;
};

class Cube {
public:
	void set(int l, int w, int h) {
		m_L = l;
		m_W = w;
		m_H = h;
	}
	void get() {
		cout << "L: " << m_L <<
			"\tW: " << m_W <<
			"\tH: " << m_H << endl;
	}
	double area() {
		return 2 * m_L * m_W + 2 * m_H * m_W + 2 * m_L * m_H;
	}
	double vol() {
		return m_L * m_W * m_H;
	}
	bool isCubeSame(Cube& c) {
		if (area() == c.area() && vol() == c.vol()) {
			return true;
		}
		else {
			return false;
		}
	}

private:
	int m_L;
	int m_W;
	int m_H;
};

bool isCubeSame(Cube& c1, Cube& c2) {
	if (c1.area() == c2.area() && c1.vol() == c2.vol()) {
		return true;
	}
	else {
		return false;
	}
}

int main2() {
	Circle c1;
	c1.m_r = 10;
	cout << "Circle Perimeter: " << c1.calPerimeter() << endl;

	Student s1;
	s1.m_id = 1287364;
	s1.m_name = "jm";
	s1.show();

	Person p1;
	p1.setName("jm");
	cout << "Person name: " << p1.getName() << endl;
	// p1.m_Age = 18; // 因为成员变量是private所以不能访问
	cout << "Person age: " << p1.getAge() << endl;

	Cube c2;
	c2.set(1, 2, 3);
	c2.get();
	cout << "area: " << c2.area() << endl;
	cout << "volume: " << c2.vol() << endl;
	Cube c3;
	c3.set(1, 2, 3);
	c3.get();
	cout << "Global func: C2 == C3? " << (isCubeSame(c2, c3)? "Yes":"No") << endl;
	cout << "Member func: C2 == C3? " << (c2.isCubeSame(c3) ? "Yes" : "No") << endl;

	system("pause");
	return 0;
}