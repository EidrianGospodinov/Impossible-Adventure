#include "Shift.h"

Shift::Shift(double x, double y):dx(x),dy(y)
{
}

void Shift::apply(block& b)
{
	
	b.middleX += dx;
	b.middleY += dy;
	
}
