#include "Rescale.h"

Rescale::Rescale(double f):factor(f)
{

}

void Rescale::apply(block& b)
{
	b.height *= factor;
	b.width *= factor;
}
