#include "Rotate90.h"

void Rotate90::apply(block& b)
{
	double temp;
	temp = b.height;
	b.height = b.width;
	b.width = temp;
}
