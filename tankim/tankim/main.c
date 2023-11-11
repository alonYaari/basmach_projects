#include "tanks.h"

//-----------------------------------------------------------------------------
// tankim!
// -----------
//
// General : A program that operates a game between 2 tanks.
//			 Every tank, on his turn, can choose between 4 option in order to destroy the second tank, and be the last tank that survive.
//			 The options are to move, shoot 2 kinds of shoots and plants a bomb.
//
// Input : The program waits that the every user make his choice on his turn, and then acts according to the cohice..
//
// Process : According to the user choice. The program acts according to the user choice.
//			 After that, its pass the turn to the second user.
//
// Output : Before every turn the program prints the board. 
//          If the game ends, the program will stop, and print which tank has won or weather its a tie.
//
//-----------------------------------------------------------------------------
// Programmer : Alon Yaari
// Date : 15.12.22
//-----------------------------------------------------------------------------
int main()
{
	game();
}