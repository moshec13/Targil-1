#include "Tool.h"

void Tool::moveTool()
{
	erase();
	_x = _x + _dir_x;
	_y = _y + _dir_y;
	draw((char)_ID);
}

void Tool::changeToolDirection(Direction newDirection) // need to check location before change direction
{
	switch (newDirection) {
	case Direction::UP:
		_dir_x = 0;
		_dir_y = -1;
		break;
	case Direction::DOWN:
		_dir_x = 0;
		_dir_y = 1;
		break;
	case Direction::LEFT:
		_dir_x = -1;
		_dir_y = 0;
		break;
	case Direction::RIGHT:
		_dir_x = 1;
		_dir_y = 0;
		break;
	}
}