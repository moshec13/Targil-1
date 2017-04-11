#pragma once

#include "Board.h"
#include "Tool.h"
#include "Direction.h"
#define NUM_OF_TOOLS	3

class Board;

class Player {
	enum keyOptions { UP, DOWN, LEFT, RIGHT, _keyOptionsSize };
	char _player_type;
	string _name;
	size_t _score = 0;
	char _active_tool = NULL;
	Direction _active_Direction = Direction::STOP;
	Tool _tools[NUM_OF_TOOLS];
	char _moveKeys[_keyOptionsSize]; // need to set keys on game manager
	Board *bd;
	// to do: maybe need pointer to board to check location of tools
public:
	// check game scenerios
	Player() {}
	Player(Board *board, char player_type) {
		bd = board;
		createPlayer(player_type);
	}
	void setKeys(const char* keys);
	void createPlayer(char player_type); // create player and 3 tools
	void changeName(string name) {
		_name = name;
	}
	void updateScore() {
		_score++;
	}
	void notifyKeyhit(char kbhit);
	void move() {
		// check game scenarios before moving tool
		_tools[(_active_tool - '0') % 7].moveTool();
	}
	void printToolsOnScreen() {
		for (Tool tl : _tools) {
			tl.moveTool();
		}
	}
private:
	void changeActiveDirection(char direction);
	void setTool(const Tool& tl, const int index) {
		_tools[index] = tl;
	}
	void changeTool(char new_tool) {
		_active_tool = new_tool;
	}
	void change_direction(Direction new_direction) {
		_active_Direction = new_direction;
	}
	void randomLocation(int *x, int *y) {
		do {
			*x = (rand() % 13) + 1;
			if (_player_type == 'A') {
				*y = (rand() % 5) + 1;
			}
			else {
				*y = (rand() % 5) + 9;
			}
		} while (!(bd->checkInitialToolLocation(*x, *y))); // return true if positionon board is NULL
	}

	bool checkLocationOfTools(const int& x, const int& y) {
		for (Tool tl : _tools) {
			if (_tools);
		}
	}
};