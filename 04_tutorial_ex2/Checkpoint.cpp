#include "Checkpoint.h"

Checkpoint::Checkpoint(int checkNum, int xPos, int yPos)
{
	checkpointNum = checkNum;
	counter++;
	xCheckpPos = xPos;
	yCheckPos = yPos;
}



int Checkpoint::getCheckpNum()
{
	return checkpointNum;
}

int Checkpoint::getTotCheckp()
{
	return counter;
}

int Checkpoint::getXPos()
{
	return xCheckpPos;
}

int Checkpoint::getYPos()
{
	return yCheckPos;
}
