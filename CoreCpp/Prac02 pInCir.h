#pragma once // 保证头文件在一次编译中只包含一次
#include <iostream>
using namespace std;

class Point {
public:
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
private:
	int m_X;
	int m_Y;
};

class Cir {
public:
	void setR(int r);
	int getR();
	void setCenter(Point center);
	Point getCenter();
private:
	int m_R;
	Point m_Center;
};

void isInCircle(Cir& c, Point& p);