#include "GameManager.h"
bool GameManager::gameOn;
void GameManager::stopGame()
{
	gameOn = false;
}

void GameManager::startGame()
{
	gameOn = true;
}
void GameManager::splitWord(string input) {
	char sep = ' ';
	int i = 0;


	string keyword;
	string desc;


	bool iskeyword = true;

	while (input[i] != '\0')
	{
		if (input[i] == sep && iskeyword != false) {
			iskeyword = false;
		}

		else if (iskeyword != false) {
			keyword += input[i];

		}
		else
		{
			desc += input[i];
		}

		i++;
	}
	cout << keyword << endl;
	if (desc != "")
		cout << desc;

}
