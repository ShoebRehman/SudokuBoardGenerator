/*
Title: Sudoku Board Generator
Name: Shoeb Rehman
Date: February 26, 2014
About: The driver application that will generate random sudoku boards
*/


#include "Sudoku.h"

int main(){

	SudokuSolve run;
	char newBoard;

	//Randomly seeds the random number function
	srand(time(NULL));


	do{
		//starts the board, with the first position being a random number
		run.startBoard();

		//recursively generates a solved board
		run.solveBoard(0, 1);

		//prints out the solved board
		run.printBoard();

		//gives the user an option to generate another board
		cout << "Would you like to generate a new board?" << endl;
		cin >> newBoard;
		cout << endl;
	} while (newBoard == 'y' || newBoard == 'Y');
	
	system("pause");
}
