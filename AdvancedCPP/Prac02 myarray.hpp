//设计自己的封装数组类
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray {
public:
	//有参构造
	MyArray(int capacity) {
		cout << "MyArray 有参构造" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造，防止浅拷贝
	MyArray(const MyArray& arr) {
		cout << "MyArray 拷贝构造" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0;i < this->m_Size;i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator= 防止浅拷贝 a=b=c所以需要返回自身
	MyArray& operator=(const MyArray& arr) {
		cout << "MyArray operator=" << endl;
		//先判断原来堆区是否有数据，有需先释放
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0;i < this->m_Size;i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//尾插法
	void Push_Back(const T& val) {
		if (this->m_Capacity == this->m_Size) {
			cout << "Failed, already full." << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void Pop_Back() {
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}

	//通过下标访问 arr[index] = 100
	T& operator[](int index) {
		return this->pAddress[index];
	}

	//返回容量、大小
	int getCapacity() {
		return this->m_Capacity;
	}

	int getSize() {
		return this->m_Size;
	}

	//析构
	~MyArray() {
		if (this->pAddress != NULL) {
			cout << "MyArray 析构" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;
	int m_Capacity;
	int m_Size;
};