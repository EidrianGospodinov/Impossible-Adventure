#pragma once
#include "Transform.h"
class Rescale:public Transform
{
private: 
	double factor;
public:
	Rescale(double f);
	void apply(block& b);
};

