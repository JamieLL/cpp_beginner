#include<iostream>
using namespace std;

class Building;
class GoodFriend
{
public:
	GoodFriend();
	void visitbuilding();

private:
	Building* building;
};


class GoodFriend2 {
public:
	GoodFriend2();
	void visitbuilding();
	Building* b;
};

class Building {
	friend void myfriend(Building* building);
	friend class GoodFriend;
	friend void GoodFriend2::visitbuilding(); //这个就是只让另一类的某方法可以调用
public:
	Building(); 
public:
	string m_livingroom;
private:
	string m_bedroom;
};

Building::Building() {
	this->m_livingroom = "living room";
	this->m_bedroom = "bedroom";
}

GoodFriend::GoodFriend() {
	building = new Building;
}
void GoodFriend::visitbuilding() {
	cout << "GoodFriend class: " << building->m_bedroom << endl;
}

GoodFriend2::GoodFriend2() {
	b = new Building;//new返回的是指针类型
}
void GoodFriend2::visitbuilding() {
	cout << "GoodFriend2 class: " << b->m_livingroom << endl;
	cout << "GoodFriend2 class: " << b->m_bedroom << endl;
}


void myfriend(Building* building) {
	cout << "myfriend func: " << building->m_livingroom << endl;
	cout << "myfriend func: " << building->m_bedroom << endl;
}


int main4() {
	Building b;
	GoodFriend gf;
	GoodFriend2 gf2;
	//b.m_bedroom;//无法访问private
	myfriend(&b);
	gf.visitbuilding();
	gf2.visitbuilding();

	system("pause");
	return 0;
}