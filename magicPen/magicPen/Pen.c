#include "Pen.h"

void addText(char** icppStringFromUer)
{
	// Variables definition
	int nStringLen;
	int nCurrLen = 0;
	char cBuffer;

	// Code section

	printf("Enter your string's len: ");
	scanf("%d", &nStringLen);
	// Allocating a place for the string and checks if the allocation succeeded.
	if (!(*icppStringFromUer = malloc(sizeof(char) * nStringLen))) { printf("\nError 1 - Allocation failed"); exit(1); }
	printf("\nInsert a string: ");
	// Recives characters from the user. 
	// The amount of depends on what the user decided earlier.
	while (nCurrLen < nStringLen)
	{
		scanf(" %c", &cBuffer);
		// Inserting every character to the string.
		(*icppStringFromUer)[nCurrLen++] = cBuffer;
	}

	// Null terminating - ends the string.
	(*icppStringFromUer)[nCurrLen] = 0;
	printf("\n%s", *icppStringFromUer);
}

void updateString(char** icppOriginalString)
{
	// Variables definition
	int nStartLocation;
	int nNumberOfChars;
	int nNewLength;
	int nIndex;
	int nCurrLen = 0;
	int nOriginalLen = strlen(icppOriginalString);
	char cBuffer;
	char* pcString;

	// Code section
	printf("Input place to start updating: ");
	scanf("%d", &nStartLocation);
	// Checks if the user picked a valid start location.
	if (nStartLocation < 0 || nStartLocation > nOriginalLen)
	{
		printf("Invalid location");
		return;
	}
	
	printf("Input number of chars to be updated: ");
	scanf("%d", &nNumberOfChars);
	nNewLength = nStartLocation + nNumberOfChars;
	// Allocating a place (according to the size that the user enter) for the string and checks if the allocation succeeded.
	if(!(pcString = malloc(sizeof(char) * nNumberOfChars)))
	{
		printf("\nError 1 - Allocation failed");
		exit(1);
	}

	printf("Insert a string: ");
	// Recives characters from the user. 
	// The amount of depends on what the user decided earlier.
	while (nCurrLen < nNumberOfChars)
	{
		scanf(" %c", &cBuffer);
		pcString[nCurrLen++] = cBuffer;
	}
	
	// Null terminating - ends the string.
	pcString[nCurrLen] = 0;
	nCurrLen = 0;

	// Realloctaing the original string and chaeks if the allocation succeeded.
	if(!(*icppOriginalString = realloc(*icppOriginalString, sizeof(char) * nNewLength)))
	{
		printf("\nError 1 - Allocation failed!");
		exit(1); 
	}
	
	// Copying the values that the user inserted to the original string. 
	// Starts from the place the user choose.
	for ( nIndex = nStartLocation; nIndex < nNewLength; nIndex++)
	{
		(*icppOriginalString)[nIndex] = pcString[nCurrLen++];
	}

	// Null terminating - ends the string.
	(*icppOriginalString)[nIndex] = 0;

	//free(pcString);
	printf("%s", *icppOriginalString);
}

void deleteText(char** icppOriginalString)
{
	// Variables definition
	int nNumberOfCharsToDelete;
	int nStringLen = strlen(*icppOriginalString);
	int nIndex;
	int nNewSize;
	char* pcNewString = malloc(sizeof(char));

	// Code section
	printf("How many characters do you want to delete from the end of the string? ");
	scanf("%d", &nNumberOfCharsToDelete);
	
	// Checks if the number that the user picked is valid.
	if (nNumberOfCharsToDelete >= 0 && nNumberOfCharsToDelete <= strlen(*icppOriginalString))
	{
		// Needs to delete the whole string.
		if (nNumberOfCharsToDelete == strlen(*icppOriginalString))
		{
			// Realloctaing the original string and chaeks if the allocation succeeded.
			if(!(*icppOriginalString = realloc(*icppOriginalString, sizeof(char)))){ printf("\nError 1 - Allocation failed"); exit(1); };
			*icppOriginalString = NULL;
			printf("Terminated the string.");
		}
		else
		{
			// Allocates new place for a string.
			if (!(pcNewString = malloc(sizeof(nStringLen - nNumberOfCharsToDelete + 1) * sizeof(char))))
			{
				printf("\nError 1 - Allocation failed");
				exit(1);
			}

			// Copying from the original string to the temp string. 
			for (nIndex = 0; nIndex < nStringLen - nNumberOfCharsToDelete; nIndex++)
			{
				pcNewString[nIndex] = (*icppOriginalString)[nIndex];
			}
			// Null terminating - ends the string.
			pcNewString[nIndex] = 0;

			// Realloctaing the original string and chaeks if the allocation succeeded.
			if (!(*icppOriginalString = realloc(*icppOriginalString, sizeof(char) * nIndex)))
			{
				printf("\nError 1 - Allocation failed!");
				exit(1);
			}
			// Returning the deleted string to the original string.
			strcpy(*icppOriginalString, pcNewString);
		}
	}
	else
	{
		printf("Amount of chars to delete need to be between 1 to the size of the string");
	}

	printf("\n%s", *icppOriginalString);
	//free(*pcNewString);
}

void writeToFile(char* icpOriginalString)
{
	// Variables definition
	char carrFileName[20] = { 0 };

	// Code section
	printf("Enter the file name you want to write to: ");
	scanf("%s", carrFileName);
	// Opens the file that the user asked.
	FILE* fp = fopen(carrFileName, "wt");
	// Checks if the file is exist - if not, Exits with 2.
	if (fp == NULL)
	{
		printf("Error 2 - file opening failed.");
		exit(2);
	}

	//Writes the string to the file.
	fputs(icpOriginalString, fp);
	fclose(fp);
}

char* getStringFromFile()
{
	// Variables definition
	char carrFileName[20] = { 0 };
	char* cpStringFromFile = malloc(sizeof(char));

	// Code section
	printf("Enter the file name you want to read from: ");
	scanf("%s", carrFileName);
	// Opens the file that the user asked.
	FILE* fp = fopen(carrFileName, "rt");
	// Checks if the file is exist - if not, Exits with 2.
	if (fp == NULL)
	{
		printf("Error 2 - file opening failed.");
		exit(2);
	}
	
	//Counts the length of the string in the file.
	fseek(fp, 0, SEEK_END);
	int nSizeOfLine = ftell(fp);
	rewind(fp);
	// alloctaing the a temporarly string and chaeks if the allocation succeeded.
	if (!(cpStringFromFile = malloc(nSizeOfLine * sizeof(char)))) { printf("\nAllocation error!"); exit(1); };
	
	// Reads from the file to the temporarly string
	fscanf(fp, "%s", cpStringFromFile);
	printf("%s", cpStringFromFile);
	fclose(fp);

	return cpStringFromFile;
}

void menu(char** iocppString)
{
	// Variables definition
	int nChoice;

	// Code section
	printf("To add a string - 1; \nTo update string - 2; \nTo delete string - 3;");
	printf("\nWriting to file - 4; \nreading from file - 5; \nexit - 6;\n\n");
	scanf("%d", &nChoice);
	// Calls the right function according to what the user asked.
	while (1)
	{
		switch (nChoice)
		{
		case 1:
			addText(iocppString);

			break;
		case 2:
			updateString(iocppString);

			break;
		case 3:
			deleteText(iocppString);

			break;
		case 4:
			writeToFile(*iocppString);

			break;
		case 5:
			*iocppString = getStringFromFile();
			
			break;
		case 6:
			printf("exiting...");
			exit(0);
		default:
			break;
		}
		printf("\n\nTo add a string - 1; \nTo update string - 2; \nTo delete string - 3;");
		printf("\nWriting to file - 4; \nreading from file - 5; \nexit - 6;\n\n");
		scanf("%d", &nChoice);
	}
}