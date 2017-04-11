#include "GameManager.h"

void GameManager::runGame()
{
	char ch = 0;
	while (ch != EXIT) {
		printMenu();
		cin >> (char)ch;
		if (ch == options::SELECT_NAMES) {
			changeName();
		}
		if (ch == options::START_GAME) {
			startGame();
		}
		if (ch == options::REVEARSE_GAME) {

		}
		if (ch == options::RESTART_MATCH) {

		}
		if (ch == options::EXIT) {
			clearScreen(); 
			cout << "Hope you have enjoyed the Game made by Xenia && Moshe :)" << endl;
		}
	}
}
