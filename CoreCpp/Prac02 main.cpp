#include<iostream>
#include"Prac02 pInCir.h"
using namespace std;

int main2_1() {
	// Practice-Proj02 pInCir: the relationship between point and circle
	// class Point, class Cir
	Cir c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	Point p;
	p.setX(10);
	p.setY(9);

	isInCircle(c, p);

	system("pause");
	return 0;
}