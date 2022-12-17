#include <iostream>
#include <string>
#include "parallelogram.h"
#include "base-types.h"

using namespace std;

Parallelogram::Parallelogram(point_t a, point_t b, point_t c) { 

	if (a.x < b.x && a.x < c.x && (a.y == b.y || a.y == c.y)) {
		A = a;
	}
	else if (b.x < a.x && b.x < c.x && (b.y == a.y || b.y == c.y)) {
		A = b;
	}
	else if (c.x < b.x && c.x < a.x && (a.y == b.y || a.y == c.y)) {
		A = c;
	}

	if (b.y == A.y && b.x != A.x) {
		B = b;
	}
	else if (c.y == A.y && c.x != A.x) {
		B = c;
	}
	else if (a.y == A.y && a.x != A.x) {
		B = a;
	}

	if ((a.x != A.x || a.y != A.y) && (a.x != B.x || a.y != B.y)) {
		C = a;
	}
	else if((b.x != A.x || b.y != A.y) && (b.x != B.x || b.y != B.y)){
		C = b;
	}
	else if ((c.x != A.x || c.y != A.y) && (c.x != B.x || c.y != B.y)) {
		C = c;
	}

	D.x = A.x - (B.x - C.x);
	D.y = C.y;
	
	pos.x = ((A.x*C.y-C.x*A.y)*(D.x-B.x)-(B.x*D.y-D.x*B.y)*(C.x-A.x))/((A.y-C.y)*(D.x-B.x)-(B.y-D.y)*(C.x-A.x));
	pos.y = ((B.y-D.y)*pos.x-(B.x*D.y-D.x*B.y))/(D.x-B.x);

}
double Parallelogram::getArea() {

	point_t temp;

	temp.x = A.x;
	temp.y = D.y;
	
	return (sqrt((D.x - C.x) * (D.x - C.x) + (D.y - C.y) * (D.y - C.y))) * (sqrt((temp.x - A.x) * (temp.x - A.x) + (temp.y - A.y) * (temp.y - A.y)));
}
rectangle_t Parallelogram::getFrameRect() {

	rectangle_t framerect;
	framerect.pos = pos;

	framerect.width = sqrt((B.x - A.x) * (B.x - A.x)) + sqrt((A.x - D.x) * (A.x - D.x));
	framerect.height = sqrt((A.y - D.y) * (A.y - D.y));

	return framerect;

}

void Parallelogram::move_c(double x, double y) {
	
	double prevx = pos.x;
	double prevy = pos.y;

	pos.x = x;
	pos.y = y;
	
	double diffx = pos.x - prevx;
	double diffy = pos.y - prevy;

	A.x += diffx;
	A.y += diffy;

	B.x += diffx;
	B.y += diffy;

	C.x += diffx;
	C.y += diffy;

	D.x += diffx;
	D.y += diffy;

}
void Parallelogram::move_o(double x, double y) {

	pos.x += x;
	pos.y += y;

	A.x += x;
	A.y += y;

	B.x += x;
	B.y += y;

	C.x += x;
	C.y += y;

	D.x += x;
	D.y += y;

}
void Parallelogram::scale(double sx) {

	double width = (sqrt((B.x - A.x) * (B.x - A.x))) * sx;
	double height = (sqrt((A.y - D.y) * (A.y - D.y))) * sx;

	A.x = pos.x - (width / 2);
	A.y = pos.y + (height / 2);

	B.x = pos.x + (width / 2);
	B.y = pos.y + (height / 2);

	C.x = pos.x + (width / 2);
	C.y = pos.y - (height / 2);

	D.x = pos.x - (width / 2);
	D.y = pos.y - (height / 2);

}
string Parallelogram::getName() {
	return "PARALLELOGRAM";
}
Shape* Parallelogram::clone() {

	return this;

}