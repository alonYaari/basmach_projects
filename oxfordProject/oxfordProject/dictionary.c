#include "dictionary.h"

void addNewWord(char* iszNewWord, char* iszWordDef)
{
	//Opening the file.
	FILE* fp = fopen(FILE_NAME, "at");

	//Inserting the word and its definiton.
	fputs(iszNewWord, fp);
	fputc(' ', fp);
	fputs(iszWordDef, fp);
	fputc('\n', fp);
	fclose(fp);
}

void joinStrings(char** iopszFirstString, char* iszSecondString)
{
	//Adding the size of the defenition to the size of the word. 
	*iopszFirstString = realloc(*iopszFirstString, sizeof(char) * (strlen(*iopszFirstString) + strlen(iszSecondString)));
	//Adding to the word '-' and its defenition.
	strcat(*iopszFirstString, "-");
	strcat(*iopszFirstString, iszSecondString);
}

char* getWordDefenition(char* iszWord)
{
	//Opening the file.
	FILE* fp = fopen(FILE_NAME, "rt");
	int nIndex;
	//Allocating place for the word and the defenition.
	char cpWord = malloc(sizeof(char));
	char cpDefinition = malloc(sizeof(char));
	//printf("%d", fscanf(fp, "%s %s", cpWord, cpDefinition));

	//code segment
	while(!feof(fp))
	{
		char* cpWord = malloc(sizeof(char));
	    nIndex = 1;
		//Inserting to cpWord the word.
		cpWord[nIndex - 1] = fgetc(fp);
		while (cpWord[nIndex - 1] != ' ')
		{
			cpWord = realloc(cpWord, sizeof(char) * (++nIndex));
			cpWord[nIndex - 1] = fgetc(fp);	
		}
		//Ending cpWord.
		cpWord[nIndex - 1] = 0;
		int nSecondIndex = 1;
		char* cpDefinition = malloc(sizeof(char));
		cpDefinition[nSecondIndex - 1] = fgetc(fp);
		//Inserting to cpDefinition the defenition.
		while (!feof(fp) && (cpDefinition[nSecondIndex - 1] != '\n'))
		{
			cpDefinition = realloc(cpDefinition, sizeof(char) * (++nSecondIndex));
			cpDefinition[nSecondIndex -1] = fgetc(fp);
		}
		//Ending cpDefenition.
		cpDefinition[nSecondIndex - 1] = 0;
		//Checks if the word that the user enter appears in this row of the dictionary.
		if (!strcmp(cpWord, iszWord))
		{
			joinStrings(&cpWord, cpDefinition);
			printf("%s\n", cpWord);
			return cpWord;
		}
	}
	//Cloosing the streem and free the allocating arrays.
	fclose(fp);
	free(cpWord);
	free(cpDefinition);

	return NULL;
}

void printWordsOf(char icStartchar)
{
	//Opening the file.
	FILE* fp = fopen(FILE_NAME, "rt");
	char cpWord[20];

	//code segment
	//Gets a word from the f=dictionary
	fscanf(fp, "%s%*s", cpWord);
	//Checks if the word starts with the letter that the user picked. 
	if (cpWord[0] == icStartchar)
	{
		printf("%s\n", cpWord);
	}

	//Doing the same thing until the EOF.
	while (!feof(fp))
	{
		fscanf(fp, "%s%*s", cpWord);
		if (cpWord[0] == icStartchar)
		{
			printf("%s\n", cpWord);
		}
	}

	fclose(fp);
}

void dictionaryMenu()
{
	int nUserChoice = 0;
	printf("Pick a 1-4 number:\n");
	//Gets the user choice. 
	scanf("%d", &nUserChoice);
	while (nUserChoice != -1)
	{
		//Managing the menu according to the user choice.
		switch (nUserChoice)
		{
		case 1:
		{
			char arrcUserWord[20];
			printf("Insert a word and you will get it definition\n");
			scanf("%s", &arrcUserWord);
			getWordDefenition(arrcUserWord);
			break;
		}
		case 2:
		{
			char arrcUserWord[20];
			char arrcUserDefenition[20];
			printf("Insert a word you wanted\n");
			scanf("%s", &arrcUserWord);
			printf("Insert its defenition\n");
			scanf("%s", &arrcUserDefenition);
			addNewWord(arrcUserWord, arrcUserDefenition);
			break;
		}
		case 3:
		{
			char cUserLetter = '0';
			printf("Choose a letter\n");
			scanf(" %c", &cUserLetter);
			printWordsOf(cUserLetter);
			break;
		}
		case 4:
		{
			printf("Bye Bye!");
			exit(1);
			break;
		}
		default:
			exit(1);
			break;
		}
		printf("Pick a 1-4 number:\n");
		scanf("%d", &nUserChoice);
	}
}