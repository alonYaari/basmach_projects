#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 13

typedef enum instruction{MOVE = 1, REGULAR_SHOOT, SPECIAL_SHOOT, AIR_BOMB};
typedef enum Tile{TANK = 1, BLANK, BROKEN_WALL, WALL};
typedef int Board[SIZE][SIZE];
typedef struct Tank
{
	int x;
	int y;
	int player;
}Tank;

// Functions prototype

//-----------------------------------------------------------------------------
// menu
// ---------
//
// General : The function operates the game. Its calls to initiate the board, and then take care on the turns in the game.
//			 In every turn the function calls the menu function with the players and his choice.
//
// Parameters :NONE.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void game();