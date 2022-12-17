#include <iostream>
#include <string>
#include "rectangle.h"
#include "base-types.h"

using namespace std;

Rectangle::Rectangle(point_t a, point_t b){

	if (a.y > b.y) {

		B = a;
		D = b;
		A.x = D.x;
		A.y = B.y;
		C.x = B.x;
		C.y = D.y;

	}
	else if (a.y < b.y) {

		B = b;
		D = a;
		A.x = D.x;
		A.y = B.y;
		C.x = B.x;
		C.y = D.y;

	}
	

	pos.x = (B.x - A.x) / 2;
	pos.y = (A.y - D.y) / 2;

}

double Rectangle::getArea() {
	
	double width = sqrt((B.x - A.x) * (B.x - A.x));
	double height = sqrt((A.y - D.y) * (A.y - D.y));

	return width * height;

}
rectangle_t Rectangle::getFrameRect() {

	rectangle_t framerect;
	
	double width = sqrt((B.x - A.x) * (B.x - A.x));
	double height = sqrt((A.y - D.y) * (A.y - D.y));

	framerect.width = width;
	framerect.height = height;
	framerect.pos = pos;

	return framerect;

}
void Rectangle::move_c(double x, double y) {

	pos.x = x;
	pos.y = y;

	double width = sqrt((B.x - A.x) * (B.x - A.x));
	double height = sqrt((A.y - D.y) * (A.y - D.y));

	A.x = pos.x - (width / 2);
	A.y = pos.y + (height / 2);

	B.x = pos.x + (width / 2);
	B.y = pos.y + (height / 2);

	C.x = pos.x + (width / 2);
	C.y = pos.y - (height / 2);

	D.x = pos.x - (width / 2);
	D.y = pos.y - (height / 2);

}
void Rectangle::move_o(double x, double y) {

	pos.x += x;
	pos.y += y;

	double width = sqrt((B.x - A.x) * (B.x - A.x));
	double height = sqrt((A.y - D.y) * (A.y - D.y));

	A.x = pos.x - (width / 2);
	A.y = pos.y + (height / 2);

	B.x = pos.x + (width / 2);
	B.y = pos.y + (height / 2);

	C.x = pos.x + (width / 2);
	C.y = pos.y - (height / 2);

	D.x = pos.x - (width / 2);
	D.y = pos.y - (height / 2);

}
void Rectangle::scale(double sx) {

	double width = (sqrt((B.x - A.x) * (B.x - A.x)))*sx;
	double height = (sqrt((A.y - D.y) * (A.y - D.y)))*sx;

	A.x = pos.x - (width / 2);
	A.y = pos.y + (height / 2);

	B.x = pos.x + (width / 2);
	B.y = pos.y + (height / 2);

	C.x = pos.x + (width / 2);
	C.y = pos.y - (height / 2);

	D.x = pos.x - (width / 2);
	D.y = pos.y - (height / 2);

}
string Rectangle::getName() {
	return "RECTANGLE";
}
Shape* Rectangle::clone() {

	return this;

}