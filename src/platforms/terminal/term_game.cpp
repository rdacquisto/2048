// term_game_board.cpp

#include "term_game.h"

#include <iostream>
#include <string>

Direction TermGame::getInput()
{
	Direction result;
	char pressed_key;
    int ascii_code = 0;
    bool useEscapeSequence = false;

    while(ascii_code != 3) {
        system("/bin/stty raw");
        pressed_key = getchar();
        system("/bin/stty cooked");
        ascii_code = pressed_key;

        if (ascii_code == 27) {
        	useEscapeSequence = true;
        } else if (useEscapeSequence) {
        	// Arrow Keys
        	switch (ascii_code) {
        		case 65:
        			return UP;
        		case 66:
        			return DOWN;
        		case 67:
        			return RIGHT;
        		case 68:
        			return LEFT;
        		case 27:
        		case 91:
        			continue;
        		default:
        			useEscapeSequence = false;
        	}
        } else {
        	switch (ascii_code) {
        		// A
        		case 97:
        		case 65:
        			return LEFT;
        		// S
        		case 115:
        		case 83:
        			return DOWN;
        		// W
        		case 119:
        		case 87:
        			return UP;
        		// D
        		case 100:
        		case 86:
        			return RIGHT;
        	}
        }
    }

    // Returning an undefined Direction object to make the compiler happy.
    // Note: I assume there is a chance that this will possibly at some point return a valid Direction.
    return result;
}

void TermGame::start()
{
	bool in_progress = true;

	while (in_progress) {

		// Print the 2048 Board
		game_board.print();

		// Get user input for next move.
		Direction input = getInput();

		if (input > 3) {
			// Handle the case where no valid input is was present. (ctrl + c)
			in_progress = false;
		} else {
			// Perform a move based on the given user input.
			game_board.perform_move(input);

			// Check to see if there are any valid moves left.
			in_progress = !(game_board.is_game_over());
		}
	}
	// Print the final 2048 Board
	game_board.print();

}
