#define _CRT_SECURE_NO_WARNINGS
#include "time.h"
#include "tanks.h"

//-----------------------------------------------------------------------------
// doStep
// ---------
//
// General : The function moves the tank to this new spot.
//
// Parameters :
// Board gameBoard - the game board.
// Tank *tank - pointer to the playing tank.
// int onAddX - Inicates the direction the tank should go to at X axis.
// int onAddY - Inicates the direction the tank should go to at Y axis.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void doStep(Board gameBoard, Tank *tank, int onAddX, int onAddY)
{
	// Code section
	// Changes the current tile of the tank to empty.
	gameBoard[tank->x][tank->y] = BLANK;
	// Changes the tank location
	tank->x = tank->x + onAddX;
	tank->y = tank->y + onAddY;
	// Moves the tank to its new place on board.
	gameBoard[tank->x][tank->y] = TANK;
}

//-----------------------------------------------------------------------------
// checkMove
// ---------
//
// General : The function checks if a tank can move at a specific direction (the direction sets according the parameters).
//
// Parameters :
// Board gameBoard - The game board.
// Tank *tank - Pointer to the playing tank.
// int onAddX - Inicates the direction the tank should go to at X axis.
// int onAddY - Inicates the direction the tank should go to at Y axis.
//
// Return Value : int - If the tank can go this direction, 0 if its can't.
//
//-----------------------------------------------------------------------------
int checkMove(Board gameBoard, Tank* tank, int onAddX, int onAddY)
{
	// Code section
	// Checks if the tank can move to the place the user wants. 
	if (gameBoard[tank->x + onAddX][tank->y + onAddY] == BLANK){return 1;}
	// In case its can't.
	return 0;
}

//-----------------------------------------------------------------------------
// moveTank
// ---------
//
// General : The function calls the right functions in order to move the tank like the user asked (if it possible).
//
// Parameters :
// Board gameBoard - The game board.
// Tank *tank - Pointer to the playing tank.
// int onDirection - The direction that the tank should go.
// int onSteps - The number of steps the tank should make.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void moveTank(Board gameBoard, Tank* tank, int onDirection, int onSteps)
{
	// Variables definition
	int nStop = 0;

	// Code section
	// Runs acoording to the number of steps it's need, or until faces a wall or another tank.
	while (onSteps && !nStop)
	{
		// Each dircation has different care.
		switch (onDirection)
		{
		case 1:
			if (checkMove(gameBoard, tank, -1, 0))
			{
				// In case the tank can move, call the doStep function with the right parameters  and decrease the number of steps he can do.
				doStep(gameBoard, tank, -1, 0);
				onSteps--;
			}
			// Changes the nStop to 1, so it wont enter the while again.
			else{ nStop = 1;}

			break;
		case 2:
			// In case the tank can move, call the doStep function with the right parameters and decrease the number of steps he can do.
			if (checkMove(gameBoard, tank, 0, 1)) { doStep(gameBoard, tank, 0, 1); onSteps--;}
			// Changes the nStop to 1, so it wont enter the while again.
			else { nStop = 1; }

			break;
		case 3:
			// In case the tank can move, call the doStep function with the right parameters and decrease the number of steps he can do.
			if (checkMove(gameBoard, tank, 1, 0)) { doStep(gameBoard, tank, 1, 0); onSteps--;}
			// Changes the nStop to 1, so it wont enter the while again.
			else { nStop = 1; }

			break;
		case 4:
			// In case the tank can move, call the doStep function with the right parameters  and decrease the number of steps he can do.
			if (checkMove(gameBoard, tank, 0, -1)) { doStep(gameBoard, tank, 0, -1); onSteps--; }
			// Changes the nStop to 1, so it wont enter the while again.
			else { nStop = 1; }

			break;
		default:
			break;
		}
	}
}

//-----------------------------------------------------------------------------
// setAdittion
// ---------
//
// General : The function gets the direction and sets the X and Y adittions.
//
// Parameters :
// int* opnXAddition - Pointer to the change on the X axis.
// int* opnYAddition - Pointer to the change on the Y axis.
// int onDirection - The direction that the tank should go.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void setAddition(int* opnXAddition, int* opnYAddition, int onDirection)
{
	// Cose section
	// According to the direction, cahnge the X an Y additions. 
	switch (onDirection)
	{
	case(1): // up
		*opnXAddition = *opnXAddition - 1;
		
		break;
	case(2): // right
		*opnYAddition = *opnYAddition + 1;
		
		break;
	case(3): // down
		*opnXAddition = *opnXAddition + 1;

		break;
	case(4): // left
		*opnYAddition = *opnYAddition - 1;
		
		break;
	default:
		break;
	}
}

//-----------------------------------------------------------------------------
// shootGeneral
// ---------
//
// General : The function gets the direction and the type of the rocket and then "shoot" its to the right direction.
//
// Parameters :
// Board gameBoard - The game board.
// Tank *tank - Pointer to the playing tank.
// int onDirection - The direction that the rocket should go.
// int shootType - Determine if a regular shoot or special one will shoot.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void shootGeneral(Board gameBoard, Tank* tank, int onDirection, int onShootType)
{
	
	// Variables definition
	int nXAddition = 0, nYAddition = 0, nTimes = 0;
	int nXCurrentLocation = tank->x, nYCurrentLocation = tank->y;
	int nHit = 0;

	// Code section
	// Calls to setAdittion to insert values to the X and Y adittions.
	setAddition(&nXAddition, &nYAddition, onDirection);
	// Changes the current location according to the additions its needs.
	nXCurrentLocation += nXAddition;
	nYCurrentLocation += nYAddition;

	// Checks which type of shoot it is - special or regular.
	if (onShootType == 3) // Special shot
	{
		// So it can nTurn maximum five times or until its hit a broken wall.
		while (nTimes < 5 &&  !nHit)
		{
			if (gameBoard[nXCurrentLocation][nYCurrentLocation] != WALL)
			{
				if (gameBoard[nXCurrentLocation][nYCurrentLocation] != BLANK)
				{
					if (gameBoard[nXCurrentLocation][nYCurrentLocation] == BROKEN_WALL)
					{ 
						// Hit broken wall, so destoys the wall and chages the place on the board to blank.
						gameBoard[nXCurrentLocation][nYCurrentLocation] = BLANK;
						// Indicates that broken wall been hit.
						nHit = 1;
					}
					else 
					{
						// Hits tank.
						// Checks if the shoot hit the shooter tank
						if (tank->x == nXCurrentLocation && tank->y == nYCurrentLocation)
						{
							// Hit current tank so second tank won
							printf("Tank %d has won", !(tank->player));
						}
						else
						{
							// The shooter tank hit his rival, so he won.
							printf("Tank %d has won", (tank->player));
						}

						// Tank been hit. The game ends.
						exit(1);
					}
				}
				else
				{
					// Changes the current location at the same direction.
					nXCurrentLocation += nXAddition;
					nYCurrentLocation += nYAddition;
				}
			}
			else
			{
				// Hit wall
				// reset to position before the addition
				nXCurrentLocation -= nXAddition;
				nYCurrentLocation -= nYAddition;
				// Adds to the counter that count the shoot's turns.
				nTimes++; 
				// changes the shoot's direction.
				onDirection++;
				if (onDirection > 4) { onDirection = 1; }
				//Reset and change the additions.
				nXAddition = 0; nYAddition = 0;
				setAddition(&nXAddition, &nYAddition, onDirection);
			}
		}
	}
	else if (onShootType == 2)
	{   // normal shot
		// Until faaces wall.
		while (gameBoard[nXCurrentLocation][nYCurrentLocation] != WALL && !nHit)
		{
			if (gameBoard[nXCurrentLocation][nYCurrentLocation] != BLANK)
			{
				if (gameBoard[nXCurrentLocation][nYCurrentLocation] == BROKEN_WALL)
				{
					// Hit broken wall, so destoys the wall and chages the place on the board to blank.
					gameBoard[nXCurrentLocation][nYCurrentLocation] = BLANK;
					// Indicates that broken wall been hit.
					nHit = 1;
				}
				else 
				{
					// Hit a TANK - for sure not his tank, so he won.
					printf("Tank %d has won", (tank->player));
					exit(1);
				}
			}
			// Changes the current location at the same direction.
			nXCurrentLocation += nXAddition;
			nYCurrentLocation += nYAddition;
		}
	}
}

//-----------------------------------------------------------------------------
// shootGeneral
// ---------
//
// General : The function taking care on the 4 option, plants bomb.
//			 The function asks from the user to pick where the bomb will plant, and then plants it there.
//
// Parameters :
// Board gameBoard - The game board.
// Tank *tank - Pointer to the playing tank.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void dropaBomb(Board gameBoard, Tank tank)
{
	// Variables definition
	int nXIndex;
	int nYIndex;
	int nMaxVal = 2;
	int narrBombs[3][3];
	int nIsPlantingTankLost = 0;
	int nOtherTankLost = 0;

	// Code section
	// Inser 1 or 0 randomly to the bomb array.
	srand((unsigned)time(NULL));
	for (int  nIndex = 0; nIndex < 3; nIndex++)
	{
		for (int nJindex = 0; nJindex < 3; nJindex++)
		{
			narrBombs[nIndex][nJindex] =rand() % nMaxVal;
		}
	}

	printf("Enter the indexes to plant a bomb:\n");
	scanf("%d %d", &nXIndex, &nYIndex);

	// Going thruogh the bomb's impact area.
	for (int nIndex = nXIndex - 1; nIndex < nXIndex + 2; nIndex++)
	{
		for (int nJinex = nYIndex - 1; nJinex < nYIndex + 2; nJinex++)
		{
			// If in this current location bomb has been plant.
			if (narrBombs[nIndex - nXIndex + 1][nJinex - nYIndex + 1])
			{
				// Checks if tank has been hit.
				if (gameBoard[nIndex][nJinex] == TANK)
				{
					if (tank.x == nIndex && tank.y == nJinex)
					{
						// In this case the planting tank is the one that got hurt by the bomb.
						nIsPlantingTankLost = 1;
					}
					else
					{
						// In this case the not playing tank is the one that got hurt by the bomb.
						nOtherTankLost = 1;
					}
				}
				if (gameBoard[nIndex][nJinex] == BROKEN_WALL)
				{
					// Hit broken wall, so destoys the wall and chages the place on the board to blank.
					gameBoard[nIndex][nJinex] = BLANK;
				}
			}
		}
	}

	// Chekcs if any of the tank got hurt.
	if (nIsPlantingTankLost)
	{
		if (nOtherTankLost)
		{
			// Means that both tanks got destroy, so its a tie.
			printf("No one wons, both tanks have been eliminated");
			exit(2);
		}
		else
		{
			// Means that the not playing tank won.
			printf("Tank %d has won", !(tank.player));
		}
		exit(1);
	}
	if (nOtherTankLost)
	{
		// Means that only the playing tank won.
		printf("Tank %d has won", (tank.player));
		exit(1);
	}
}

//-----------------------------------------------------------------------------
// initiateBoard
// ---------
//
// General : The function initiate the board. Placing The walls, the broken walls, the tanks and determine where the empty spots.
//
// Parameters :
// Board gameBoard - The game board.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void initiateBoard(Board gameBoard)
{
	// Code section
	// Initiats the board.
	for (int nIndex = 0; nIndex < SIZE ; nIndex++)
	{
		for (int nJindex = 0; nJindex < SIZE; nJindex++)
		{
			if (!nIndex || !nJindex || nIndex == SIZE - 1 || nJindex == SIZE-1)
			{
				// Places walls at the board's edges.
				gameBoard[nIndex][nJindex] = WALL;
			}
			else
			{
				if (nJindex == 1 || nJindex == SIZE - 2)
				{
					if (nIndex == 6)
					{
						// Places tanks where they should be.
						gameBoard[nIndex][nJindex] = TANK;
					}
					else
					{
						// This place need to be an empty one.
						gameBoard[nIndex][nJindex] = BLANK;
					}
				}
				else
				{
					if (nJindex % 2 == 0 && nIndex%2==0)
					{
						// At the odd's places, place broken wall.
						gameBoard[nIndex][nJindex] = BROKEN_WALL;
					}
					else
					{
						// This place need to be an empty one.
						gameBoard[nIndex][nJindex] = BLANK;
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------------------------
// checkForWIn
// ---------
//
// General : The function checks if there are still broken walls in order to know if the game should continue.
//
// Parameters :
// Board gameBoard - The game board.
//
// Return Value : Int - 1 if there are still broken walls, and 0 the other case.
//
//-----------------------------------------------------------------------------
int checkForWIn(Board gameBoard)
{
	// Code section
	// Cecks if there are still broken walls.
	for (int nIndex = 2; nIndex < SIZE - 2; nIndex += 2)
	{
		for (int nJindex = 2; nJindex < SIZE - 2; nJindex += 2)
		{
			if (gameBoard[nIndex][nJindex] == BROKEN_WALL)
			{
				// Returns 1 in case that broken wall has been found.
				return 1;
			}
		}
	}

	//There are no more broken walls on the board.
	return 0;
}

//-----------------------------------------------------------------------------
// printBoard
// ---------
//
// General : The function prints the board.
//
// Parameters :
// Board gameBoard - The game board.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void printBoard(Board gameBoard)
{
	for (int nIndex = 1; nIndex < SIZE - 1; nIndex ++)
	{
		for (int nJindex = 1; nJindex < SIZE - 1; nJindex ++)
		{
			printf("%d", gameBoard[nIndex][nJindex]);
		}
		printf("\n");
	}
}

//-----------------------------------------------------------------------------
// menu
// ---------
//
// General : The function gets the playing tank, the board and the tank choice.
//			 After that, its calls to the right function according to the user choice its got.
//
// Parameters :
// Board gameBoard - The game board.
// Tank *tank - Pointer to the playing tank.
// int onChoice - The user choice.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void menu(Board gameBoard, Tank* tank, int onChoice)
{
	// Variables definition
	int nDirection;
	int nSteps;

	// Code section
	switch (onChoice)
	{
	case MOVE:
		printf("Please enter the direction you want to make your move, and the number of steps you want to make;\n");
		printf("1 for go up, 2 for go right, 3 for go down and 4 to go left\n");
		// Collects the direction and the number of steps the user wants to make.
		scanf("%d %d", &nDirection, &nSteps);
		// Calls the moveTank function.
		moveTank(gameBoard, tank, nDirection, nSteps);

		break;
	case REGULAR_SHOOT:
	case SPECIAL_SHOOT:
		printf("Please enter the direction you want to shoot;\n");
		printf("1 for go up, 2 for go right, 3 for go down and 4 to go left\n");
		// Collects the direction the user wants to shoot is rocket to.
		scanf("%d", &nDirection);
		// Calls the shootGenenral function.
		shootGeneral(gameBoard, tank, nDirection, onChoice);

		break;
	case AIR_BOMB:
		// Calls the dropaBomb function.
		dropaBomb(gameBoard, *tank);

		break;
	default:
		break;
	}
}

void game()
{
	// Variables definition
	Board narrGameBoard;
	Tank tank0;
	Tank tank1;
	int nTurn = 1;
	int inChoice;
	int nDirection;
	int nSteps;

	// Code section
	// Inintiats board and tanks.
	initiateBoard(narrGameBoard);
	tank1.x = 6; tank1.y = 1; tank1.player = 1;
	tank0.x = 6; tank0.y = SIZE - 2; tank0.player = 0;

	printBoard(narrGameBoard);

	// Runs until no broken walls left (or a tank got hit).
	while (checkForWIn(narrGameBoard))
	{
		printf("Tank %d is currently playing\n", nTurn);
		printf("Please enter your move; 1 for move, 2 for regular shoot, 3 for special shoot, 4 for plant a bomb, 999 for quit.\n");
		scanf("%d", &inChoice);
		// If the user wants to exit the program.
		if (inChoice == 999)
		{
			printf("Quit");
			exit(3);
		}
		if (nTurn)
		{
			// Checks if the user's cohice is valid.
			if (inChoice > 0 || inChoice< 5)
			{
				menu(narrGameBoard, &tank1, inChoice);
				// Moves the turn to the other player.
				nTurn = !nTurn;
			}
		}
		else
		{
			// Checks if the user's cohice is valid.
			if (inChoice > 0 || inChoice < 5)
			{
				menu(narrGameBoard, &tank0, inChoice);
				// Moves the turn to the other player.
				nTurn = !nTurn;
			}
		}
		printBoard(narrGameBoard);
		printf("\n\n\n\n\n\n");
	}
	printf("The game ends with tie.");
	exit(2);
}