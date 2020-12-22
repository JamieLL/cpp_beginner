#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int& aka() {
	static int a = 10;
	return a;
}

int main() {
	// 1. 内存分区
	// 堆区：用new开辟内存
	int* p = new int(10);
	int* arr = new int[10];
	// 用delete释放
	delete p;
	delete[] arr;

	// 2. 引用
	// 引用传递，可以用形参修饰实参，即可以不用指针的地址传递
	int a = 10;
	int b = 20;
	swap(a, b);
	cout << "a = " << a << endl; // 20
	cout << "b = " << b << endl; // 10

	// 引用作为函数返回值，函数的调用可以作为左值
	int& ref = aka(); // 返回的是a的引用
	cout << "ref = " << ref << endl; // 10
	aka() = 1000;
	cout << "ref = " << ref << endl; // 1000

	// 引用的本质是一个指针常量
	int& ref1 = a; // 自动转换为: int* const ref1 = &a;
	ref1 = 20; // 内部发现ref1是引用，自动转换为: *ref1 = 20;



	system("pause");
	return 0;
}