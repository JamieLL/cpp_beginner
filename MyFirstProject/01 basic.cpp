#include <iostream>
#include<ctime>
#include "func.h"
#define PI 3.14
using namespace std;

struct student {
	string name;
	int age;
	int score;
}s3; // s3为定义时创建一个变量，一般不用

struct teacher {
	int id;
	string name;
	struct student stu;
};

int main()
{
	int a = 10;
	const int day = 7;
	// print
	cout << "a = " << a << endl;
	cout << "PI = " << PI << endl;
	cout << "day = " << day << endl;

	//float f = -0.1234567f;
	//cout << f << endl;

	string str = "hello";
	cout << str << endl;

	bool flag = true;
	cout << flag << endl;

	int b = 0;
	//cout << "enter b" << endl;
	//cin >> b;
	//cout << "b = " << b << endl;

	cout << (a == b) << endl;

	if (a != b)
	{
		cout << "a != b" << endl;
	}
	else if (a == b)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a == b" << endl;
	}

	// 三目运算符 1?2:3，返回的是变量，可以继续赋值
	int c = a > b ? a : b;
	cout << "c = " << c << endl;

	// 随机数种子：根据系统当前时间
	srand((unsigned int)time(NULL));
	int rnum = rand() % 100 + 1;// rand()%100 生成0~99
	cout << "rnum = " << rnum << endl;

	//while
	int num = 0;
	while (num < 2) {
		cout << "num = " << num << endl;
		num++;
	}

	//for
	for (int i = 0; i < 2; i++) {
		cout << "i = " << i << endl;
	}

	// 99乘法表
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << "*" << i << "=" << i * j << "\t";
		}
		cout << endl;
	}

	// 数组，定义时必须有初始长度
	// 长度：sizeof(arr) / sizeof(arr[0]
	int arr[6] = { 10,20,30,40,50 };
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << endl;
	}
	cout << arr << endl;
	cout << (int)arr << endl;
	cout << &arr[0] << endl;

	int start = 0;
	int end = sizeof(arr) / sizeof(arr[0]) - 1;

	// 往后冒泡排序
	//int num[] = { 4,2,8,0,5,7,1,3,9 };
	//int len = sizeof(num) / sizeof(num[0]);
	//int temp = 0;
	//for (int i = 0;i < len - 1;i++) {
	//	for (int j = 0;j < len - i - 1;j++) {
	//		if (num[j] > num[j + 1]) {
	//			temp = num[j];
	//			num[j] = num[j + 1];
	//			num[j + 1] = temp;
	//		}
	//	}
	//}

	//for (int i = 0; i < len; i++) {
	//	cout << num[i] << " ";
	//}
	//cout << endl;


	// 二维数组
	//int biarr[][2] = { {1,2},{3,4} };
	//int biarr[2][2] = { 1,2,3,4 };
	//int biarr[2][2] = { {1,2},{3,4} }; //建议用法【直观
	// 行数： sizeof(arr) / sizeof(arr[0])
	// 列数： sizeof(arr[0])/ sizeof(arr[0][0])


	// 指针（some* 也是一种数据结构）
	//int a = 10;
	int* p;
	// &为取址符
	p = &a;
	// 解引用：指针前加*代表解引用，找到指针指向的内存中的数据
	cout << "*p: " << *p << endl;
	cout << "sizeof(int*) = " << sizeof(p) << endl; //32位指针占4个字节，64位操作系统占8个字节
	
	// const修饰指针-常量指针：指针的指向可以修改，但指针指向的值不可以改
	const int* p1 = &a;
	// *p1 = 20; 错误
	// const修饰常量-指针常量：指针的指向不可以修改，但指针指向的值可以改
	int* const p2 = &a;
	// p2 = &b; 错误
	// const既修饰指针又修饰常量：指针的指向和指向的值都不可以修改
	const int* const p3 = &a;

	p = arr;//数组名即为数组的首地址
	// p++;就是往后移一个数（4个字节

	//void swapp(int* p1, int* p2) {
	//	int temp = *p1;
	//	*p1 = *p2;
	//	*p2 = temp;
	//}
	//swapp(&a, &b);

	// 将数组作为函数形参： func(int* arr), func(int arr[]), func(int arr[10])都可以

	// 结构体 struct
	struct student s1; // struct 关键字可以省略
	s1.name = "jm";
	struct student s2 = { "jm2" , 18, 601};
	student ss[3];

	struct student* ps = &s2;
	cout << ps->name << endl;
	// struct值传递和地址传递入函数：func1(struct student s), func2(struct student* p)。函数调用func1(s), func2(&s)
	// 另：指针传递可以节省内存
	// func(const struct student* s)：防止误操作修改值

	// srand((unsigned int)time(NULL)); 随机数种子
	// int random = rand() % 60; //0~59


	system("pause");

	return 0;
}