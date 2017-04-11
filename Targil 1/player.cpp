#include "player.h"
#include "Direction.h"

void Player::setKeys(const char * keys)
{
	int i = 0;
	for (char& key : _moveKeys) {
		key = keys[i++];
	}
}

void Player::createPlayer(char player_type)
{
	_player_type = player_type; 
	int x, y;
	int index = 0;

	if (_player_type == 'A')
		_name = "a";
	else
		_name = "b";

	while (index < NUM_OF_TOOLS) {
		randomLocation(&x, &y);
		if (_player_type == 'A') {
			switch (index) {
			case 0:
				setTool(Tool(x, y, TOOL_NUM::ONE), index);
				break;
			case 1:
				setTool(Tool(x, y, TOOL_NUM::TWO), index);
				break;
			case 2:
				setTool(Tool(x, y, TOOL_NUM::THREE), index);
				break;
			}
		}
		if (_player_type == 'B') {
			switch (index) {
			case 0:
				setTool(Tool(x, y, TOOL_NUM::SEVEN), index);
				break;
			case 1:
				setTool(Tool(x, y, TOOL_NUM::EIGHT), index);
				break;
			case 2:
				setTool(Tool(x, y, TOOL_NUM::NINE), index);
				break;
			}
		}
		index++;
	}
}

void Player::notifyKeyhit(char kbhit)
{
	if (((kbhit == '1' || kbhit == '2' || kbhit == '3') && _player_type == 'A') || ((kbhit == '7' || kbhit == '8' || kbhit == '9')  && _player_type == 'B')) {
		if (kbhit != _active_tool) {
			_tools[(_active_tool - '0') % 7].stop();
			_active_tool = kbhit; // notice to screen in case the tool is dead
		}
		else
			return;
	}
	else if (tolower(kbhit) == _moveKeys[UP] || tolower(kbhit) == _moveKeys[DOWN] || 
		tolower(kbhit) == _moveKeys[LEFT] || tolower(kbhit) == _moveKeys[RIGHT]) {
		changeActiveDirection(kbhit);
		_tools[(_active_tool - '0') % 7].changeToolDirection(_active_Direction);
	}
	if (_active_tool != NULL)
		move();
}

void Player::changeActiveDirection(char direction)
{
	if (tolower(direction) == _moveKeys[UP]) {
		_active_Direction = Direction::UP;
	}
	else if (tolower(direction) == _moveKeys[DOWN]) {
		_active_Direction = Direction::DOWN;
	}
	else if (tolower(direction) == _moveKeys[LEFT]) {
		_active_Direction = Direction::LEFT;
	}
	else if (tolower(direction) == _moveKeys[RIGHT]) {
		_active_Direction = Direction::RIGHT;
	}
}
