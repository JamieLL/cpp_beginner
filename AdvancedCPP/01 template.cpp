#include<iostream>
using namespace std;

void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

// 模板，T代表一种数据类型
template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void test01_01() {
	int a = 10;
	int b = 20;
	swapInt(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double c = 1.1;
	double d = 2.2;
	swapDouble(c, d);
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	//调用模板
	//1. 自动推导类型
	mySwap(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	//2. 显示指定类型
	mySwap<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}


// typename可以用class替代
template<class T>
void mySort(T arr[], int len) {
	for (int i = 0;i < len;i++) {
		int max = i;
		for (int j = i + 1;j < len;j++) {
			if (arr[max] > arr[j]) {
				max = j;
			}
		}
		if (max != i) {
			mySwap(arr[max], arr[i]);
		}
	}
}

template<class T>
void printArray(T arr[], int len) {
	for (int i = 0;i < len;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01_02() {
	char charArr[] = "bacfde";
	int num = sizeof(charArr) / sizeof(char) - 1; // 字符数组最后多一个“\0”，占一个字节
	mySort(charArr, num);
	printArray(charArr, num);
}

void test01_03() {
	int intArr[] = { 2, 3, 1, 5, 6, 4 };
	int num = sizeof(intArr) / sizeof(int); // -1前=6
	mySort(intArr, num);
	printArray(intArr, num);
}

template<class T>
T myAdd(T a, T b) {
	return a + b;
}

void test01_04() {
	int a = 10;
	int b = 20;
	char c = 'a';
	cout << myAdd(a, b) << endl;
	//cout << myAdd(a, c) << endl; // 不会隐式类型转换

	// 这里函数模板不能用引用传递，会报错；引用的本质是指针，不能隐式转换
	cout << myAdd<int>(a, c) << endl;
}

int main1() {
	test01_01();
	test01_02();
	test01_03();
	test01_04();

	system("pause");
	return 0;
}