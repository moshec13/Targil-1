#include "Board.h"

void Board::printBoardToScreen()
{
	int row_Y_pos = 2;
	// print X index Row
	char start = 'A';
	for (int i = BOX_SIZE + 1; i < BOX_SIZE*(X_SIZE + 1); i += BOX_SIZE) {
		gotoxy(i + BOX_SIZE/2 -1, row_Y_pos);
		std::cout << start++;
		std::cout.flush();
	}
	row_Y_pos += 2;
	// print rest of rows
	for (int i = 0; i < SIZES::X_SIZE ; i++) {
		// print Y index 
		int j = 0;
		gotoxy((j*BOX_SIZE), row_Y_pos);
		std::cout << (i + 1);
		std::cout.flush(); 
		// print boxes
		for (j=1; j <= SIZES::Y_SIZE; j++) {
			printSquare((j*BOX_SIZE) + 1, row_Y_pos,_board[i][j-1]);
			gotoxy(BOX_SIZE*j, row_Y_pos);
			std::cout << "|";
			std::cout.flush();
		}
		//print last "|" in row
		gotoxy(BOX_SIZE*j, row_Y_pos);
		std::cout << "|";
		std::cout.flush();
		//print partition beetwin rows
		printPartition(row_Y_pos - 1);
		row_Y_pos += 2;
	}
	// print last partition
	printPartition(row_Y_pos - 1);
}
