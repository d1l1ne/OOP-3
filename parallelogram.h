#pragma once
#include <iostream>
#include <string>
#include "shape.h"
#include "base-types.h"

using namespace std;

class Parallelogram : public Shape {

private:
	point_t A;
	point_t B;
	point_t C;
	point_t D;
	point_t pos;

public:
	Parallelogram(point_t a, point_t b, point_t c);
	double getArea() override;
	rectangle_t getFrameRect() override;
	void move_c(double x, double y) override;
	void move_o(double x, double y) override;
	void scale(double sx) override;
	string getName() override;
	Shape* clone() override;

};