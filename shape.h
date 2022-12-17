#pragma once
#include <iostream>
#include <string>
#include"base-types.h"

using namespace std;

class Shape {
public:
	virtual double getArea()=0;
	virtual rectangle_t getFrameRect() = 0;
	virtual void move_c(double x, double y) = 0;
	virtual void move_o(double x, double y) = 0;
	virtual void scale(double sx) = 0;
	virtual string getName() = 0;
	virtual Shape* clone() = 0;
	const bool operator<(Shape& s1);
	friend ostream& operator<< (ostream& os, Shape* sh);
	
};