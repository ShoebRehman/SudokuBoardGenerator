/*
Title: Sudoku Board Generator
Name: Shoeb Rehman
Date: February 26, 2014
About: The functions from the SudokuSolve class are defined in this function
*/

#include "Sudoku.h"

// Prints the board to follow a standard Sudoku format
void SudokuSolve::printBoard(){
	//A nested for loop to print out every value from the 9x9 array
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cout << " " << board[i][j];

			//Spaces the printing of the board by every 3rd column
			if ((j + 1) % 3 == 0){
				cout << "  ";
			}
		}
		cout << endl;

		//Spaces the printing of the board by every 3rd row
		if ((i + 1) % 3 == 0){
			cout << endl;
		}
	}
}

// Randomizes the first position in the array and then makes everything else empty (0)
void SudokuSolve::startBoard(){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (j == 0 && i == 0){
				//puts a random number in the first position
				board[0][0] = 1 + (rand() % 9);
			}
			//Makes everything else 0
			else{
				board[i][j] = 0;
			}
		}
	}
}

// Checks position in the array and if it's not filled, it'll return false. If it is, it'll return true
bool SudokuSolve::unassignedPosition(int board[9][9]){
	for (int row = 0; row < 9; row++){
		for (int column = 0; column < 9; column++){
			if (board[row][column] == 0){
				return false;
			}
		}
	}
	return true;
}

// Checks to see if the number is allowed at that row/column position
bool SudokuSolve::isAllowed(int row, int column, int num){

	//Checks Column for a duplicate number
	for (int i = 0; i < 9; i++){
		if (board[i][column] == num){
			return false; // if there's a duplicate number in the column, returns false and backtracks
		}
	}

	//Checks row for duplicate number
	for (int j = 0; j < 9; j++){
		if (board[row][j] == num){
			return false; // if there's a duplicate number in the row, returns false and backtracks
		}
	}

	//Checks block
	int startRow = row - (row % 3);
	int startCol = column - (column % 3);

	for (int x = startRow; x < startRow + 3; x++){
		for (int y = startCol; y < startCol + 3; y++){
			if (board[x][y] == num){
				return false; // if there's a duplicate number in the block, returns false and backtracks
			}
		}
	}

	return true; // if everything is good, returns true 
}

// Takes a number and puts it into the row/column
bool SudokuSolve::solveBoard(int row, int column){

	//if it reaches the end of the column, it'll move a row down and revert to the first column
	if (column == 9){
		column = 0;
		row++;
	}

	//as soon as the board is filled, it'll return true and end
	if (unassignedPosition(board)){
		return true;
	}

	//puts a random number in the randNum variable
	int randNum = (rand() % 9) + 1;

	//a for loop that puts the randum generated number into a variable and checks that number for the position in the board
	for (int num = randNum; num < 10; num++){
		if (isAllowed(row, column, num)) { //if the number is allowed, it'll set that position to that number

			board[row][column] = num;

			//increments the column to the next one 
			if (solveBoard(row, column + 1)){
				return true;
			}

			//if the number can't go, it'll set the position back to 0
			else {
				board[row][column] = 0;
			}
		}
	}

	//a for loop that puts the randum generated number into a variable and checks that number for the position in the board, counting backwards
	for (int num1 = randNum; num1 > 0; num1--){
		if (isAllowed(row, column, num1)) { //if the number is allowed, it'll set that position to that number

			board[row][column] = num1;

			//increments the column to the next one 
			if (solveBoard(row, column + 1)){
				return true;
			}

			//if the number can't go, it'll set the position back to 0
			else {
				board[row][column] = 0;
			}
		}
	}

	return false;
}
