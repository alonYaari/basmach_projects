#include "board.h"

void game()
{
	int arrBoard[SIZE][SIZE];
	int nScoreToWin;
	int nXBulliPlace;
	int nYBulliPlace;
	int nXBearPlace;
	int nYBearPlace;

	//code segment
	mazeInit(arrBoard, &nScoreToWin, &nXBulliPlace, 
		&nYBulliPlace, &nXBearPlace, &nYBearPlace);
	bulliMoves(arrBoard, &nScoreToWin, &nXBulliPlace, 
		&nYBulliPlace, &nXBearPlace, &nYBearPlace);
}

void mazeInit(arrnMaze ioArrnMaze, int* iopnscoreToWin, int* iopnXbulliPlace,
	int* iopnYbulliPlace, int* iopnXbearPlace, int* iopnYbearPlace)
{
	//code segment
	for (int nIndex = 0; nIndex < SIZE; nIndex++)
	{
		for (int jIndex = 0; jIndex < SIZE; jIndex++)
		{
			if (nIndex == 0 || jIndex == 0 || nIndex == SIZE - 1 || jIndex == SIZE -1)
			{
				//Crating safety wall.
				ioArrnMaze[nIndex][jIndex] = SAFE;
			}
			else
			{
				//Adding points to maze.
				ioArrnMaze[nIndex][jIndex] = POINT;
			}
		}
	}

	//Counting the number of points on the maze.
	*iopnscoreToWin = (SIZE - 2) - getWallsFromUSer(ioArrnMaze);
	//Calling a function to place Bulli.
	getInitialBulliPlace(ioArrnMaze, iopnXbulliPlace, iopnYbulliPlace);
	//Calling a function to place the bear.
	getInitialBearPlace(ioArrnMaze, iopnXbearPlace, iopnYbearPlace);
}
int getWallsFromUSer(arrnMaze iArrnMaze)
{
	//Variables definiton
	int nXplace;
	int nYplace;
	int nWallsNumber = 0;

	//code segment
	printf("Enter the coordinates (first row then column) to place a wall - Stops when gets a 0!\n");
	scanf("%d %d", &nXplace, &nYplace);
	while (nXplace > 0 && nYplace > 0)
	{
		nWallsNumber++;
		//Placing walls accorsding to the user.
		iArrnMaze[nXplace][nYplace] = WALL;
		scanf("%d %d", &nXplace, &nYplace);
	}
	printf("\n\n");
	
	//Returns how many walls have been placed.
	return nWallsNumber;
}
void printMaze(arrnMaze iArrnmaze)
{
	//code segmant
	//Runs all over the maze.
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			printf("%d", iArrnmaze[i][j]);
		}
		printf("\n");
	}
}
void getInitialBulliPlace(arrnMaze iArrnmaze, int* ipnXbulliPlace, int* ipnYbulliPlace)
{
	//code segment
	printf("Enter the first coordinates (first row then column) of Bulli\n");
	scanf("%d %d", ipnXbulliPlace, ipnYbulliPlace);
	//Checks Bulli can be placed wehre the user picked.
	if (iArrnmaze[*ipnXbulliPlace][*ipnYbulliPlace] != 0){iArrnmaze[*ipnXbulliPlace][*ipnYbulliPlace] = BULLI;}
	else{printf("Bulli can't be placed there\n");}
}
void getInitialBearPlace(arrnMaze iArrnmaze, int* ipnXbearPlace, int* ipnYbearPlace)
{
	//code segment
	printf("Enter the first coordinates (first row then column) of the bear\n");
	scanf("%d %d", ipnXbearPlace, ipnYbearPlace);
	
	//Checks if the user pick's is legal.
	if (iArrnmaze[*ipnXbearPlace][*ipnYbearPlace] != WALL && iArrnmaze[*ipnXbearPlace][*ipnYbearPlace] != BULLI)
	{
		iArrnmaze[*ipnXbearPlace][*ipnYbearPlace] = BEAR;
	}
	else
	{
		printf("the bear can't be placed there\n");
	}
}

void bulliMoves(arrnMaze ioArrnMaze, int* iopnScoreToWin,int* iopnXbulliPlace,
	int* iopnYbulliPlace, int* iopnXbearPlace, int* iopnYbearPlace)
{
	//Varieble defeiition
	int nDirection;
	int nLastDirection;

	//code segment
	//Receives instructions from the user.
	printf("1 - go right, 2 - go left, 3 - go up, 4 - go down, 0 - last location\n");
	scanf("%d", &nDirection);
	if (nDirection == 0)
	{
		printf("You have to press 1-4 in order to startPlaying\n");
		scanf("%d", &nDirection);
	}
	//Until Bulli collects all points from the maze.
	while (*iopnScoreToWin)
	{
		//In case the user picked 0 - Bulli will keep moving at the same direction.
		nDirection = !nDirection ? nLastDirection : nDirection;
		
		//According to the user instruction...
		switch (nDirection)
		{
		//Moving right.
		case 1:
			nLastDirection = 1;
			//Checks if bulli can go right.
			if (canMoveThere(ioArrnMaze, *iopnXbulliPlace, *iopnYbulliPlace + 1))
			{
				//Calls to bulliMoveTo in order to move bulli.
				bulliMoveTo(ioArrnMaze, iopnScoreToWin,
					iopnXbulliPlace, iopnYbulliPlace, 0, 1);

				if (!(*iopnScoreToWin))
				{
					//The game ends! Bulli collected all points on maze.
					printf("\n----------------------------------\nBulli wins!!!!!!!!!!!!!!!!!!\n----------------------------------");
					exit(1);
				}
			}
			
			break;
		//Moving left.
		case 2:
			nLastDirection = 2;
			//Checks if bulli can go left.
			if (canMoveThere(ioArrnMaze, *iopnXbulliPlace, *iopnYbulliPlace - 1))
			{
				//Calls to bulliMoveTo in order to move bulli.
				bulliMoveTo(ioArrnMaze, iopnScoreToWin,
					iopnXbulliPlace, iopnYbulliPlace, 0, -1);

				if (!(*iopnScoreToWin))
				{
					//The game ends! Bulli collected all points on maze.
					printf("\n----------------------------------\nBulli wins!!!!!!!!!!!!!!!!!!\n----------------------------------");
					exit(1);
				}
			}
			
			break;
		//Moving up
		case 3:
			nLastDirection = 3;
			//Checks if bulli can go up.
			if (canMoveThere(ioArrnMaze, *iopnXbulliPlace - 1, *iopnYbulliPlace))
			{
				//Calls to bulliMoveTo in order to move bulli.
				bulliMoveTo(ioArrnMaze, iopnScoreToWin,
					iopnXbulliPlace, iopnYbulliPlace, -1, 0);

				if (!(*iopnScoreToWin))
				{
					//The game ends! Bulli collected all points on maze.
					printf("\n----------------------------------\nBulli wins!!!!!!!!!!!!!!!!!!\n----------------------------------");
					exit(1);
				}
			}

			break;
		//Moving down
		case 4:
			nLastDirection = 4;
			//Checks if bulli can go down.
			if (canMoveThere(ioArrnMaze, *iopnXbulliPlace + 1, *iopnYbulliPlace))
			{
				//Calls to bulliMoveTo in order to move bulli.
				bulliMoveTo(ioArrnMaze, iopnScoreToWin,
					iopnXbulliPlace, iopnYbulliPlace, 1, 0);

				if (!(*iopnScoreToWin)) 
				{
					//The game ends! Bulli collected all points on maze.
					printf("\n----------------------------------\nBulli wins!!!!!!!!!!!!!!!!!!\n----------------------------------"); 
					exit(1);
				}
			}

			break;
		default:
			printf("Wrong input, pleae enter number from 1-4");
			break;
		}

		//After the user move, calls to bearMove in order to move the bear.
		bearMove(ioArrnMaze, *iopnXbulliPlace, *iopnYbulliPlace, iopnXbearPlace, iopnYbearPlace);
		printMaze(ioArrnMaze);
		//Keeps reciving instructions from the user.
		scanf("%d", &nDirection);
	}
}
int canMoveThere(arrnMaze iArrnMaze, int inXbulliPlace, int inYbulliPlace)
{
	//Checks if Bulli doesnt run into a wall or to the end of the maze.
	if (iArrnMaze[inXbulliPlace][inYbulliPlace] == WALL || iArrnMaze[inXbulliPlace][inYbulliPlace] == SAFE)
	{
		return 0;
	}
	return 1;
}
void bulliMoveTo(arrnMaze iArrnMaze, int* ipnScoreToWin, int* ipnXbulliPlace, int* ipnYbulliPlace, int nXDirection, int nYdirection)
{
	//Code segment.
	//Changes Bulli's coordinates.
	*ipnXbulliPlace = *ipnXbulliPlace + nXDirection;
	*ipnYbulliPlace = *ipnYbulliPlace + nYdirection;

	//Cheks if Bulli move to a place where he collect a point.
	if (iArrnMaze[*ipnXbulliPlace][*ipnYbulliPlace] == POINT || iArrnMaze[*ipnXbulliPlace][*ipnYbulliPlace] == BEARLEFT)
	{
		*ipnScoreToWin = *ipnScoreToWin - 1;
		//Placing Bulli in his new place.
		iArrnMaze[*ipnXbulliPlace][*ipnYbulliPlace] = BULLI;
	}
	else
	{
		//Checks if Bulli encountered the bear.
		if (iArrnMaze[*ipnXbulliPlace][*ipnYbulliPlace] == BEAR)
		{
			//The game ends! The bear catched bulli.
			printf("The bear catched bulli");
			exit(1);
		}
		//Placing Bulli in his new place.
		iArrnMaze[*ipnXbulliPlace][*ipnYbulliPlace] = BULLI;
	}
	
	//Clears the previous place of Bulli.
	iArrnMaze[*ipnXbulliPlace - nXDirection][*ipnYbulliPlace - nYdirection] = EMPTY;
}

void bearMove(arrnMaze iArrnMaze, int inXbulliPlace, int inYbulliPlace, int* ipnXBearPlace, int* ipnYBearPlace)
{
	//Variables definitons.
	//Saves bear's last position.
	int nXBeforeChange = *ipnXBearPlace;
	int nYBeforeChange = *ipnYBearPlace;
	//Calculates where the the bear should move.
	int nmoveinX = inXbulliPlace - *ipnXBearPlace;
	int nmoveinY = inYbulliPlace - *ipnYBearPlace;

	//Code segment.
	//Checks if the bear doesnt run into a wall.
	if (nmoveinY > 0 && iArrnMaze[*ipnXBearPlace][*ipnYBearPlace + 1] != WALL &&
		iArrnMaze[*ipnXBearPlace][*ipnYBearPlace + 1] != SAFE)
	{
		//Moves the bear.
		*ipnYBearPlace = *ipnYBearPlace + 1;
	}
	else
	{
		//Checks if the bear doesnt run into a wall.
		if (nmoveinY < 0 && iArrnMaze[*ipnXBearPlace][*ipnYBearPlace - 1] != WALL &&
			iArrnMaze[*ipnXBearPlace][*ipnYBearPlace - 1] != SAFE)
		{
			//Moves the bear.
			*ipnYBearPlace = *ipnYBearPlace - 1;
		}
	}
	//Checks if the bear doesnt run into a wall.
	if (nmoveinX > 0 && iArrnMaze[*ipnXBearPlace + 1][*ipnYBearPlace] != WALL &&
		iArrnMaze[*ipnXBearPlace + 1][*ipnYBearPlace] != SAFE)
	{
		//Moves the bear.
		*ipnXBearPlace = *ipnXBearPlace + 1;
	}
	else 
	{ 
		//Checks if the bear doesnt run into a wall.
		if (nmoveinX < 0 && iArrnMaze[*ipnXBearPlace - 1][*ipnYBearPlace] != WALL &&
			iArrnMaze[*ipnXBearPlace - 1][*ipnYBearPlace] != SAFE)
			{
				//Moves the bear.
				*ipnXBearPlace = *ipnXBearPlace - 1;
			}
	}

	//Checks if the bear wncountered Bulli.
	if (iArrnMaze[*ipnXBearPlace][*ipnYBearPlace] == BULLI)
	{
		//The game ends!
		printf("The bear catched bulli");
		exit(1);
	}

	//Clears the previous place of the bear.
	iArrnMaze[nXBeforeChange][nYBeforeChange] = BEARLEFT;
	//Moves the bear to his new position.
	iArrnMaze[*ipnXBearPlace][*ipnYBearPlace] = BEAR;
}