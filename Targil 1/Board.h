#pragma once

#include <iostream>
#include "Utils.h"

class Board {
	enum SIZES{X_SIZE = 13, Y_SIZE = 13, BOX_SIZE=6};
	enum SQUARE_TYPE {NOTHING,FR=1, SEA=2, FlgA=3, FlgB=4};
	enum COLOR{ BLACK, DARK_BLUE, DARK_GREEN, DARK_CYAN, DARK_RED, DARK_PURPLE, OLIVE, WHITE, GREY, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW };

	SQUARE_TYPE _board[X_SIZE][Y_SIZE] = {
		{ NOTHING,NOTHING,NOTHING,NOTHING,NOTHING ,NOTHING ,NOTHING ,NOTHING ,NOTHING ,NOTHING,FlgA ,NOTHING ,NOTHING },
		{ NOTHING,NOTHING,NOTHING,NOTHING,NOTHING ,NOTHING ,NOTHING ,NOTHING ,NOTHING ,NOTHING,NOTHING ,NOTHING ,NOTHING },
		{ NOTHING,NOTHING,NOTHING,NOTHING,NOTHING ,NOTHING ,NOTHING ,NOTHING ,NOTHING ,NOTHING,NOTHING ,NOTHING ,NOTHING },
		{ NOTHING,NOTHING,FR,NOTHING,NOTHING,NOTHING ,NOTHING,NOTHING ,NOTHING ,SEA ,NOTHING ,NOTHING ,NOTHING },
		{ NOTHING,NOTHING,FR,NOTHING,NOTHING,NOTHING ,NOTHING,NOTHING ,SEA  ,SEA ,NOTHING ,NOTHING ,NOTHING },
		{ NOTHING,NOTHING,FR,FR,NOTHING,NOTHING ,NOTHING,SEA,SEA,SEA,NOTHING ,NOTHING ,NOTHING },
		{ FR,FR,FR,FR  ,NOTHING,NOTHING ,NOTHING ,NOTHING ,NOTHING ,SEA ,SEA,NOTHING ,NOTHING },
		{ FR,NOTHING,NOTHING,FR,NOTHING,NOTHING ,NOTHING ,NOTHING ,NOTHING ,SEA,SEA,SEA,NOTHING },
		{ NOTHING,NOTHING,NOTHING,FR,NOTHING,NOTHING ,NOTHING ,NOTHING ,NOTHING,SEA,SEA,NOTHING ,NOTHING },
		{ NOTHING,NOTHING,NOTHING,NOTHING,NOTHING ,NOTHING ,NOTHING ,NOTHING ,NOTHING ,SEA ,NOTHING ,NOTHING ,NOTHING },
		{ NOTHING,NOTHING,NOTHING,NOTHING,NOTHING ,NOTHING ,NOTHING ,NOTHING ,NOTHING ,NOTHING,NOTHING ,NOTHING ,NOTHING },
		{ NOTHING,NOTHING,NOTHING,NOTHING,NOTHING ,NOTHING ,NOTHING ,NOTHING ,NOTHING ,NOTHING,NOTHING ,NOTHING ,NOTHING },
		{ NOTHING,FlgB,NOTHING,NOTHING,NOTHING ,NOTHING ,NOTHING ,NOTHING ,NOTHING ,NOTHING,NOTHING ,NOTHING ,NOTHING },
	};
public:
	Board() {}
	bool checkInitialToolLocation(const int& x, const int& y) {
		if (_board[x-1][y-1] == NOTHING)
			return true;
		else
			return false;
	}
	void printBoardToScreen();
private:
	void printSquare(const int& x,const int& y, SQUARE_TYPE type) {
		gotoxy(x , y);
		switch (type) {
		case SQUARE_TYPE::FR:
			setTextColor(COLOR::BLACK, COLOR::DARK_GREEN);
			std::cout << "FR   ";
			break;
		case SQUARE_TYPE::SEA:
			setTextColor(COLOR::BLACK, COLOR::BLUE);
			std::cout << "SEA  ";
			break;
		case SQUARE_TYPE::FlgA:
			setTextColor(COLOR::BLACK, COLOR::RED);
			std::cout << "FlagA";
			break;
		case SQUARE_TYPE::FlgB:
			setTextColor(COLOR::BLACK, COLOR::YELLOW);
			std::cout << "FlagB";
			break;
		}
		setTextColor(COLOR::WHITE, COLOR::BLACK);
		
		// make sure it gets to screen on time
		std::cout.flush();
	}
	void printPartition(const int& y) {
		for (int i = BOX_SIZE + 1; i < BOX_SIZE*(X_SIZE+1); i += BOX_SIZE) {
			gotoxy(i, y);
			std::cout << "-----";
		}
	}
};