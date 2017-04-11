#pragma once

#include <iostream>
#include "Utils.h"
#include "Direction.h"

#define X_AXIS_SHIFT 6
#define Y_AXIS_SHIFT 2

using namespace std;

class Tool {
	int _x, _y;
	TOOL_NUM _ID;
	int _dir_x, _dir_y;
	bool _TOOL_ALIVE = true;
public:
	Tool() {}
	Tool(const int& x,const int& y,const TOOL_NUM& id){
		_x = x;
		_y = y;
		_ID = id;
		_dir_x = _dir_y = 0;
	} 
	void moveTool();
	void erase() {
		draw(' ');
	}
	void changeToolDirection(Direction newDirection);
	void stop() {
		_dir_x = _dir_y = 0;
	}
	void killTool() { // need to erase tool from 2D array
		_TOOL_ALIVE = false;
		erase();
	}
	bool checkToolStatus() {
		return _TOOL_ALIVE;
	}
private:
	void draw(const char id) {
		gotoxy((X_AXIS_SHIFT * (_x)) + 1, (Y_AXIS_SHIFT) + ((_y)*Y_AXIS_SHIFT));
		std::cout << id;
		// make sure it gets to screen on time
		std::cout.flush();
	}
};