#include<iostream>
using namespace std;

class GoodFriend {
public:
	GoodFriend() {
		b = new Building;//new返回的是指针类型
	}
	void visitbuilding() {
		cout << "GoodFriend class: " << b->m_bedroom << endl;
	}
private:
	Building* b;
};

//class GoodFriend2 {
//public:
//	GoodFriend2() {
//		b = new Building;//new返回的是指针类型
//	}
//	void visitbuilding() {
//		cout << "GoodFriend class: " << b->m_livingroom << endl;
//		//cout << "GoodFriend class: " << b->m_bedroom << endl;
//	}
//	Building* b;
//};

class Building {
	friend void myfriend(Building* building);
	friend class GoodFriend;
	//friend void GoodFriend2::visitbuilding(); //这个就是只让另一类的某方法可以调用
public:
	Building() {
		m_livingroom = "living room";
		m_bedroom = "bedroom";
	}
	string m_livingroom;
private:
	string m_bedroom;
};

void myfriend(Building* building) {
	cout << "myfriend func: " << building->m_livingroom << endl;
	cout << "myfriend func: " << building->m_bedroom << endl;
}


int main() {
	Building b;
	//b.m_bedroom;//无法访问private
	myfriend(&b);

	GoodFriend gf;
	gf.visitbuilding();

	system("pause");
	return 0;
}