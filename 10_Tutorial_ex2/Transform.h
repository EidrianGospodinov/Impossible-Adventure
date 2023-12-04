#pragma once
#include "block.h"

struct Transform
{
	virtual void apply(block& b) = 0;
};

