// term_game_board.cpp

#include "term_game_board.h"

#include <iostream>
#include <iomanip>

void TermGameBoard::print ()
{
	system("clear");

	for (int row = 0; row < ROWS; ++row) {
		for (int col = 0; col < COLUMNS; ++col) {
			std::cout << " | " << std::setw(5);
			if (board[row][col].isEmpty()) {
				std::cout << " ";
			} else {
				std::cout << board[row][col].getTile().getValue();
			}
		}
		std::cout << " |" << std::endl;
	}
	std::cout << std::endl;
}
