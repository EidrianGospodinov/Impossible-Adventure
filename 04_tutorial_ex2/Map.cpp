#include "Map.h"

void Map::GenerateMap(int Xplayer, int Yplayer)
{
	for (int y = 0; y < HEIGHT;y++) {

		for (int x = 0; x < WIDTH; x++) {
			if (x == Xplayer && y == Yplayer) {
				cout << "@";
			}
			else if (Xplayer<0||Xplayer>=WIDTH || Yplayer<0 || Yplayer>=HEIGHT) {
				terminate();
				/*throw "Player out of Map";*/
			}
			else
			cout << ".";
		}
		cout << endl;
	}
}
