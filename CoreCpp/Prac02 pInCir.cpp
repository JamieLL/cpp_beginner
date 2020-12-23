#include"Prac02 pInCir.h"

void Point::setX(int x) {
	m_X = x;
}
void Point::setY(int y) {
	m_Y = y;
}
int Point::getX() {
	return m_X;
}
int Point::getY() {
	return m_Y;
}

void Cir::setR(int r) {
	m_R = r;
}
int Cir::getR() {
	return m_R;
}
void Cir::setCenter(Point center) {
	m_Center = center;
}
Point Cir::getCenter() {
	return m_Center;
}


void isInCircle(Cir& c, Point& p) {
	int distance =
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rDistance = c.getR() * c.getR();
	if (distance == rDistance) {
		cout << "The point is on the circle." << endl;
	}
	else if (distance < rDistance) {
		cout << "The point is in the circle." << endl;
	}
	else {
		cout << "The point is outside of the circle." << endl;
	}
}