
// SIGN ALL COMMENTS WITH RESPECTIVE INITIALS //

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
#include <vector>
using namespace std;
const int ARR_NUM_ROWS = 6;
const int ARR_NUM_COLS = 7;
const char RED_CHIP = 'R';
const char YELLOW_CHIP = 'Y';
const char EMPTY_SPACE = '-';
bool redTurn;

string player1, player2;

// hadouken - VM //

//Mac was here =^.^= Time to clean this up :) 4/17/18 - MC


char GameBoard[ARR_NUM_ROWS][ARR_NUM_COLS] = {};

int dropColumn = 0;

// this function outputs the gameboard array - VM //
void PrintBoard() {
	cout << "    1 2 3 4 5 6 7\n";
	for (int i = 0; i < ARR_NUM_ROWS; i++) {
		cout << "    ";
		for (int j = 0; j < ARR_NUM_COLS; j++) {
			cout << GameBoard[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
}

//Starts a new game 
void CreateGame() {
	srand(time(0));
	int startCoinFlip = rand() % 2;
	int nameAssignNum = rand() % 2;

	if (startCoinFlip == 1) {
		redTurn = true;
	}
	else {
		redTurn = false;
	}

	for (int i = 0; i < ARR_NUM_ROWS; i++) {
		for (int j = 0; j < ARR_NUM_COLS; j++) {
			GameBoard[i][j] = EMPTY_SPACE;
		}
	}

	cout << "Welcome To Connect FOUR! The vertical checkers game. Get four in a row to win!" << endl;
	cout << "RULES OF THE GAME" << endl;
	cout << "--Each player will randomly be assigned a color" << endl;
	cout << "--The goal is to drop chips onto the gameboard and try to get four of the same colored chips in a row" << endl;
	cout << "--If you get four in a row first, you win!" << endl;

	cout << "Player one, enter your name: ";
	cin >> player1;
	cout << "Player two, enter your name: ";
	cin >> player2;

	cout << "In this match, " << player1 << " is going up against " << player2 << "!" << endl;
	
	if (nameAssignNum == 0) {
		cout << player1 << " is assigned the red color (R)" << endl;
		cout << player2 << " is assigned the yellow color (Y)" << endl;
	}
	else {
		cout << player1 << " is assigned the yellow color (Y)" << endl;
		cout << player2 << " is assigned the red color (R)" << endl;
	}

	PrintBoard();
}

//Drops chip and handels logic 
void DropChip(char color) {
	if (dropColumn < 1 || dropColumn > 7) {
		cout << "INVALID INPUT! Enter a number (1-7): ";
		cin >> dropColumn;
		DropChip(color);
	}
	else if (GameBoard[0][dropColumn - 1] != EMPTY_SPACE) {
		cout << "Column filled!" << endl;
		cin >> dropColumn;
		DropChip(color);
	}
	else {
		for (int i = 5; i >= 0; i = i - 1) {
			if (GameBoard[i][dropColumn - 1] == EMPTY_SPACE) {
				GameBoard[i][dropColumn - 1] = color;
				break;
			}
		}
		if (redTurn) {
			redTurn = false;
		}
		else {
			redTurn = true;
		}
		PrintBoard();
	}
}

/*
SitRep for 4/16/18 -- Have finished creating a turn logic for player vs player,
however we will need to complete an algorithm for a computer player, one that
can persist on winning the game. also, we must create a nested loop
in order to parse the board for any winning combinations. Afterwards, it is
necessary to go back and create
prompts for input values and a UI that explains the roles
when the game initially prints the heading. - VM
*/

//Victory checker code should go here

void VictoryCheck() {}

// end victory checker code


int main() {

	bool RedWins = false;
	bool YellowWins = false;

	CreateGame();
	// this loop will determine who's turn it is and 
	while (!RedWins && !YellowWins) {
		if (redTurn == true) {
			cout << "Red turn, enter colnumber: ";
			cin >> dropColumn;
			DropChip(RED_CHIP);
		}
		else {
			cout << "Yellow turn, enter colnumber: ";
			cin >> dropColumn;
			DropChip(YELLOW_CHIP);
		}
	}

	cout << endl;

	/*
	Most effective method would display 2 boards, one for the player and the other
	for the opponent
	(Not sure if we want to do a real opponent or just play against the computer)
	*/

	//How would two boards work?

	//I think the two boards were a mistake in theory, you only need one for each turn

	// we don't need to code in a CPU player, we can do it as 

	return 0;
}