#include<iostream>
using namespace std;
#include "Prac02 myarray.hpp"

void printIntArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize();i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void testPrac02_01() {
	MyArray<int> arr1(5);

	for (int i = 0;i < 5;i++) {
		arr1.Push_Back(i);
	}
	cout << "arr1: " << endl;
	printIntArray(arr1);
	cout << "arr1's capacity: " << arr1.getCapacity() << endl;
	cout << "arr1's size: " << arr1.getSize() << endl;

	cout << "arr2: " << endl;
	MyArray<int> arr2(arr1);
	printIntArray(arr2);
	arr2.Pop_Back();
	cout << "arr2 after pop: " << endl;
	printIntArray(arr2);
	cout << "arr2's capacity: " << arr2.getCapacity() << endl;
	cout << "arr2's size: " << arr2.getSize() << endl;

	MyArray<int> arr3(100);
	arr3 = arr1;

}

class PersonP {
public:
	PersonP() { };
	PersonP(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void printPersonPArray(MyArray<PersonP>& arr) {
	for (int i = 0; i < arr.getSize();i++) {
		cout << "name:" << arr[i].m_Name << " age: " << arr[i].m_Age << endl;
	}
}

void testPrac02_02() {
	MyArray<PersonP> arr(10);
	PersonP p1("jm", 18);
	PersonP p2("ll", 30);
	PersonP p3("dd", 32);
	PersonP p4("yz", 17);
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	printPersonPArray(arr);
	cout << "capacity: " << arr.getCapacity() << endl;
	cout << "size: " << arr.getSize() << endl;

}

int main() {
	testPrac02_01();
	testPrac02_02();

	system("pause");
	return 0;
}

