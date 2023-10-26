#include "Map.h"





void Map::GenerateMap(int Xplayer, int Yplayer, GameManager* manager)
{
	CheckpointHolder.push_back(new Checkpoint(1, 2, 4));//makes a checkpoint one at position 2-4
	CheckpointHolder.push_back(new Checkpoint(2, 6, 4));//makes _____ two at pos ____

	for (int y = 0; y < HEIGHT;y++) {

		for (int x = 0; x < WIDTH; x++) {

			/*for (Checkpoint* check : CheckpointHolder)
			{
				if (check->getXPos() == x && check->getYPos() == y) {
					cout << check->getCheckpNum();
					
				}
			}*/

			if (x == Xplayer && y == Yplayer) {
				cout << "@";
			}
			else if (CheckpointHolder[0]->getXPos() == x && CheckpointHolder[0]->getYPos() == y) {
				cout << "0";
				
			}
			else if (CheckpointHolder[0]->getTotCheckp()) {

			}
			else if (Xplayer<0||Xplayer>=WIDTH || Yplayer<0 || Yplayer>=HEIGHT) {//player goes outside the map
				//terminate();
				/*throw "Player out of Map";*/
				manager->setGameOn();
				manager->finalMessage = "Game ends by escaping the area";
				return;
			}
			else
			cout << ".";
		}
		cout << endl;
	}
}

void Map::GenerateCheckpoint(int checkNum, int xPos, int yPos)
{

}
