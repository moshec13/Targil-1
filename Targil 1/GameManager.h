#pragma once

#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include "Board.h"
#include "player.h"
#include "Utils.h"

class GameManager {
	enum {NUM_OF_PLAYERS=2};
	enum options { SELECT_NAMES = 49, START_GAME = 50, REVEARSE_GAME = 51, RESTART_MATCH = 52, EXIT = 57, PAUSE = 27 };

	string player_a = "A";
	string player_b = "B";
	Player players[NUM_OF_PLAYERS];
	Board _board;

	bool reverseGame = false;
	bool GameOver = false;

public:
	GameManager() {
		players[0] = Player(&_board, 'A');
		players[0].setKeys("wxda");
		players[1] = Player(&_board, 'B');
		players[1].setKeys("imlj");
	}
	
	void runGame();

private:
	void printMenu() {
		cout << "please select options for game:" << endl;
		cout << "1. change names" << endl;
		cout << "2. start game" << endl;
		cout << "3. start reverse game" << endl;
		cout << "4. restart match" << endl;
		cout << "9. exit game" << endl;
	}
	void changeName() {
		clearScreen();
		std::cout << "Select name for player A: ";
		std::cin >> player_a;
		players[0].changeName(player_a);
		std::cout << "Select name for player B: ";
		std::cin >> player_b;
		players[1].changeName(player_b);
	}
	void startGame() {
		clearScreen();
		_board.printBoardToScreen();
		players[0].printToolsOnScreen();
		players[1].printToolsOnScreen();
		char ch = NULL;
		int index = 0;
		while (!(GameOver)) {
			if (_kbhit()) {
				ch = _getch();
			}
			if ((index % 2) == 0) {
				players[1].notifyKeyhit(ch);
				// check game scenarios befre move tool
			}
			else {
				players[0].notifyKeyhit(ch);
				// check game scenarios befre move tool
			}
			index++;
		}
	}
};