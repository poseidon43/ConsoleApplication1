// a project by Victor and William //
// SIGN ALL COMMENTS WITH RESPECTIVE INITIALS //

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "stdafx.h"
#include <string>
using namespace std;
const int ARR_NUM_ROWS = 6;
const int ARR_NUM_COLS = 7;
const char RED_CHIP = 'R';
const char YELLOW_CHIP = 'Y';
const char EMPTY_SPACE = 'O';
// hadouken - VM //


char GameBoard[ARR_NUM_ROWS][ARR_NUM_COLS] = {};

int dropColumn = 0;


// i had tried creating a statement that would not end up with a third chip being dropped in the 3rd row slot onto the next column, if you want to test this function, please use the funtion DropChipY - VM//
void DropChipR() {
	if (GameBoard[5][dropColumn - 1] == EMPTY_SPACE) {
		GameBoard[5][dropColumn - 1] = RED_CHIP;
		
	}
	else if (GameBoard[4][dropColumn - 1] == EMPTY_SPACE && (GameBoard[5][dropColumn - 1] == RED_CHIP || GameBoard[5][dropColumn - 1] == YELLOW_CHIP)) {
		GameBoard[4][dropColumn - 1] = RED_CHIP;
	}
	else if (GameBoard[3][dropColumn - 1] == EMPTY_SPACE && ((GameBoard[4][dropColumn - 1] == RED_CHIP || GameBoard[4][dropColumn - 1] == YELLOW_CHIP) && (GameBoard[5][dropColumn - 1] == RED_CHIP || GameBoard[5][dropColumn - 1] == YELLOW_CHIP))) {
		GameBoard[3][dropColumn] = RED_CHIP;
	}
	else if (GameBoard[2][dropColumn - 1] == EMPTY_SPACE) {
		GameBoard[2][dropColumn] = RED_CHIP;
	}
	else if (GameBoard[1][dropColumn - 1] == EMPTY_SPACE && ((GameBoard[3][dropColumn - 1] == RED_CHIP || GameBoard[3][dropColumn - 1] == YELLOW_CHIP) && ((GameBoard[4][dropColumn - 1] == RED_CHIP || GameBoard[4][dropColumn - 1] == YELLOW_CHIP) && (GameBoard[5][dropColumn - 1] == RED_CHIP || GameBoard[5][dropColumn - 1] == YELLOW_CHIP)))) {
		GameBoard[1][dropColumn] = RED_CHIP;
	}
	else if (GameBoard[0][dropColumn - 1] == EMPTY_SPACE && ((GameBoard[1][dropColumn - 1] == RED_CHIP || GameBoard[1][dropColumn - 1] == YELLOW_CHIP) && ((GameBoard[3][dropColumn - 1] == RED_CHIP || GameBoard[3][dropColumn - 1] == YELLOW_CHIP) && (GameBoard[4][dropColumn - 1] == RED_CHIP || GameBoard[4][dropColumn - 1] == YELLOW_CHIP) && (GameBoard[5][dropColumn - 1] == RED_CHIP || GameBoard[5][dropColumn - 1] == YELLOW_CHIP)))) {
		GameBoard[0][dropColumn - 1] = RED_CHIP;
	}
}
// this function is used to repopulate an empty space on the board with a yellow chip when the user cin's a column of their choosing; currently experiencing output errors (chips not stacking properly) - VM//
void DropChipY() {
	if (GameBoard[5][dropColumn - 1] == EMPTY_SPACE) {
		GameBoard[5][dropColumn - 1] = YELLOW_CHIP;

	}
	else if (GameBoard[4][dropColumn - 1] == EMPTY_SPACE) {
		GameBoard[4][dropColumn - 1] = YELLOW_CHIP;
	}
	else if (GameBoard[3][dropColumn - 1] == EMPTY_SPACE) {
		GameBoard[3][dropColumn - 1] = YELLOW_CHIP;
	}
	else if (GameBoard[2][dropColumn - 1] == EMPTY_SPACE) {
		GameBoard[2][dropColumn - 1] = YELLOW_CHIP;
	}
	else if (GameBoard[1][dropColumn - 1] == EMPTY_SPACE) {
		GameBoard[1][dropColumn - 1] = YELLOW_CHIP;
	}
	else if (GameBoard[0][dropColumn - 1] == EMPTY_SPACE) {
		GameBoard[0][dropColumn - 1] = YELLOW_CHIP;
	}

}

// this function outputs the gameboard array - VM //
void PrintBoard() {
	cout << "     ";
	for (int i = 0; i < ARR_NUM_ROWS; i++) {
		for (int j = 0; j < ARR_NUM_COLS; j++) {
			cout << GameBoard[i][j] << " ";
		}
		cout << "\n     ";
	}
	cout << endl;
}


int main() {

	bool RedWins = false;
	bool YellowWins = false;


	for (int i = 0; i < ARR_NUM_ROWS; i++) {
		for (int j = 0; j < ARR_NUM_COLS; j++) {
			GameBoard[i][j] = EMPTY_SPACE;
		}
	}

	PrintBoard();
	
	while (RedWins != true && YellowWins != true) {

		cin >> dropColumn;
		while (dropColumn < 1 || dropColumn > 7) {
			cin >> dropColumn;
			// add prompt later for invalid input - VM // 
		}
		// drop chip function on the gameboard, currently set to drop a red chip - VM //
		DropChipR();
		PrintBoard(); // board will print every turn

	}
	
	


	cout << endl;
	
	//Most effective method would display 2 boards, one for the player and the other for the opponent (Not sure if we want to do a real opponent or just play against the computer) - VM //
	
			
	return 0;
}
//What follows below this is the work I've done
/* #include "stdafx.h"             
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;


int main(){
	const int ROWS = 6;
	const int COLS = 7;
	char connect4[ROWS] [COLS];
	int turnPlayer, i, j, r, c;
	char proceed;
	int xPiece, oPiece;

	cout << " Connect 4: Fun and Galore\n";
	cout << " Press y to proceed: ";
	cin >> proceed;

	for (i = 0; i < ROWS; ++i) {                                  // Assigns dashes to indicate blank spaces
		for (j = 0; j < COLS; ++j) {
			connect4[i][j] = '-';
		}
	}
		while(proceed == 'y' || proceed == 'Y') { 	//Prints out the current board after each iteration
			cout << "  1 2 3 4 5 6 7\n";            //The while loop can easily be exited with the victory code
			for (i = 0; i < ROWS; ++i) {
				cout << i + 1;
				for (j = 0; j < COLS; ++j) {
					cout << " " << connect4[i] [j];
				}
				cout << endl;
		}
			cout << "enter column number to place X piece in: ";
			cin >> xPiece;
			
			while (xPiece < 1 || xPiece > 7) {			//for invalid entries
				cout << xPiece << " is not a valid column, enter a valid number: ";
				cin >> xPiece;
			}
			j = xPiece - 1;				//To make sure the input fits in the array
			for (i = ROWS; i >= 0; --i) {
				if (connect4[i][j] == '-') {
					connect4[i][j] = 'x';
					break;
				}
			}
			for (i = 0; i < ROWS; ++i) {		//the code for finding if connect 4 had been reached for the x pieces
				r = i;
				for (j = 0; j < COLS; ++j) {
					c = j;
					if (connect4[r][c] == 'x') {
						cout << r << c << "check one\n";
						r--;
						c++;
						if (connect4[r][c] == 'x') {
							cout << r << c << "check 2\n";
							r--;
							c++;
							if (connect4[r][c] == 'x') {
								cout << r << c << "check 3\n";
								r--;
								c++;
								if (connect4[r][c] == 'x') {
									cout << "BITCONNEEEEEEEEEECT!!!!!\n";
								
								}
							}
						}
					}
					/*	else {
							cout << "else working\n";
							break; 
						} */
					}
				}
			}
    return 0;
} */
