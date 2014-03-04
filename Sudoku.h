/*
Title: Sudoku Board Generator
Name: Shoeb Rehman
Date: February 26, 2014
About: A class that can be used to generate solved Sudoku Boards
*/

#define _SUDOKU_H_

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class SudokuSolve{
private:
	int board[9][9]; // creates a multidimensional array for the sudoku puzzle
public:
	void printBoard(); // prints the board neatly to show the Sudoku board
	bool solveBoard(int row, int column); // Tries random numbers to solve the board
	void startBoard(); // Randomizes the first number in the Sudoku and makes the rest 0
	bool unassignedPosition(int board[9][9]); // Runs as long as there are no unassigned positions (0's) on the board
	bool isAllowed(int row, int column, int num); // checks to see if the number can be placed in that row and column combination
};


#ifndef _SUDOKU_H_

#endif
