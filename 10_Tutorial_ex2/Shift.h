#pragma once
#include "Transform.h"
class Shift:public Transform
{
private:
	double dx, dy;

public:
	Shift(double x, double y);
	void apply(block& b);

};

