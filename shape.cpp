#include<iostream>
#include<string>
#include"shape.h"
#include"base-types.h"

using namespace std;


const bool Shape::operator< (Shape& s1) {

	double farea = this->getArea();
	double sarea = s1.getArea();

	return farea < sarea;
}

ostream& operator<< (ostream& os, Shape* sh) {

	os << "Name: " << sh->getName() << " area: " << sh->getArea() << " left bottom: " << sh->getFrameRect().pos.x - (sh->getFrameRect().width / 2)+1 << ", " << sh->getFrameRect().pos.y - (sh->getFrameRect().height / 2)+1 << " right top: " << sh->getFrameRect().pos.x + (sh->getFrameRect().width / 2) +1<< ", " << sh->getFrameRect().pos.y + (sh->getFrameRect().height / 2)+1;
	return os;
}