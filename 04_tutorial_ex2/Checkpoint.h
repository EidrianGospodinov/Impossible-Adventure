#pragma once

class Checkpoint 
{
	int counter;
	int checkpointNum;
	int xCheckpPos, yCheckPos;


public:
	Checkpoint(int numChec, int xPos, int yPos);

	int getCheckpNum();

	int getTotCheckp();

	int getXPos();

	int getYPos();

	
};

