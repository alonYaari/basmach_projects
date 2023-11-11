#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 102

typedef int arrnMaze[SIZE][SIZE];
enum {SAFE = -1, WALL, POINT, BULLI, BEAR, EMPTY, BEARLEFT};

//Functions prototype
//-----------------------------------------------------------------------------
// game
// ---------
//
// General : The function operates the maze.
//
// Parameters :NONE.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void game();
//-----------------------------------------------------------------------------
// mazeInit
// ---------
//
// General : The function Initializes the maze.
//
// Parameters :
// arrnMaze ioArrnMaze - The maze structure.
// int* ipnscoreToWin - Pointer to the Bulli's score.
// int* ipnXbulliPlace - Pointer to X coordinate of Bulli.
// int* ipnYbulliPlace - Pointer to Y coordinate of Bulli.
// int* ipnXbearPlace - Pointer to X coordinate of the bear.
// int* ipnYbearPlace - Pointer to Y coordinate of the bear.
// 
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void mazeInit(arrnMaze ioArrnMaze, int* ipnscoreToWin, int* ipnXbulliPlace,
	int* ipnYbulliPlace, int* ipnXbearPlace, int* ipnYbearPlace);
//-----------------------------------------------------------------------------
// getWallsFromUSer
// ---------
//
// General : The function places walls on the maze according to the user cohice.
//
// Parameters :
// arrnMaze ioArrnMaze - The maze structure.
// 
// Return Value : Int - how many walls have been placed.
//
//-----------------------------------------------------------------------------
int getWallsFromUSer(arrnMaze iArrnMaze);
//-----------------------------------------------------------------------------
// getInitialBulliPlace
// ---------
//
// General : The function Initializes bulli's place..
//
// Parameters :
// arrnMaze ioArrnMaze - The maze structure.
// int* ipnXbulliPlace - Pointer to X coordinate of Bulli - the Function will initialize it according to the user cohice.
// int* ipnYbulliPlace - Pointer to Y coordinate of Bulli - the Function will initialize it according to the user cohice.
// 
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void getInitialBulliPlace(arrnMaze iArrnmaze, int* inpXbulliPlace, int* inpYbulliPlace);
//-----------------------------------------------------------------------------
// printMaze
// ---------
//
// General : The function prints the maze.
//
// Parameters :
// arrnMaze ioArrnMaze - The maze structure.
// 
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void printMaze(arrnMaze iArrnmaze);
//-----------------------------------------------------------------------------
// getInitialbearPlace
// ---------
//
// General : The function initializes the bear's place.
//
// Parameters :
// arrnMaze ioArrnMaze - The maze structure.
// int* inpXbearPlace - Pointer to X coordinate of Bulli - the Function will initialize it according to the Bulli's place.
// int* ipnYbearPlace - Pointer to Y coordinate of Bulli - the Function will initialize it according to the Bulli's place.
// 
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void getInitialBearPlace(arrnMaze iArrnmaze, int* inpXbearPlace, int* inpYbearPlace);
//-----------------------------------------------------------------------------
// bulliMoves
// ---------
//
// General : The function moves Bolli through the maze.
//
// Parameters :
// arrnMaze ioArrnMaze - The maze structure.
// int* ipnscoreToWin - Pointer to the Bulli's score.
// int* inpXbearPlace - Pointer to X coordinate of Bulli.
// int* ipnYbearPlace - Pointer to Y coordinate of Bulli.
// int* ipnXbearPlace - Pointer to X coordinate of the bear.
// int* ipnYbearPlace - Pointer to Y coordinate of the bear.
// 
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void bulliMoves(arrnMaze ioArrnMaze, int* ionpScoreToWin, int* ionpXbulliPlace,
	int* ionpYbulliPlace, int* ionpXbearPlace, int* iopnYbearPlace);
//-----------------------------------------------------------------------------
// canMoveThere
// ---------
//
// General : The function checks if Bulli can move to the new place.
//
// Parameters :
// arrnMaze ioArrnMaze - The maze structure.
// int inpXbearPlace - How many the user wants to add Bulli on his X coordinate.
// int ipnYbearPlace - How many the user wants to add Bulli on his Y coordinate.
// 
// Return Value :int - Wheter Bulli can go to the new place. (1 - can, 0 - can't).
//
//-----------------------------------------------------------------------------
int canMoveThere(arrnMaze iArrnMaze, int inXbulliPlace, int inYbulliPlace);
//-----------------------------------------------------------------------------
// bulliMoveTo
// ---------
//
// General : The function changes Bulli's location.
//
// Parameters :
// arrnMaze ioArrnMaze - The maze structure.
// int* ipnscoreToWin - Pointer to the Bulli's score.
// int* inpXbearPlace - Pointer to the current X coordinate of Bulli.
// int* ipnYbearPlace - Pointer to the current Y coordinate of Bulli.
// int nXDirection - How many to add Bulli on his X coordinate.
// int nYdirection - How many to add Bulli on his Y coordinate.
// 
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void bulliMoveTo(arrnMaze iArrnMaze, int* ipnScoreToWin, int* ipnXbulliPlace, int* ipnYbulliPlace, int nXDirection, int nYdirection);
//-----------------------------------------------------------------------------
// bulliMoveTo
// ---------
//
// General : The function changes the bear's location.
//
// Parameters :
// arrnMaze ioArrnMaze - The maze structure.
// int inpXbearPlace - The current X coordinate of Bulli.
// int ipnYbearPlace - The current Y coordinate of Bulli.
// int* ipnXbearPlace - Pointer to X coordinate of the bear.
// int* ipnYbearPlace - Pointer to Y coordinate of the bear.
// 
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void bearMove(arrnMaze iArrnMaze, int inXbulliPlace, int inYbulliPlace, int* ipnXBearPlace, int* inpYBearPlace);