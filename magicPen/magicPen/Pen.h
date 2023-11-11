#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "Dictionary.dat"

//Functions prototype

//-----------------------------------------------------------------------------
// addText
// ---------
//
// General : The function gets a pointer to a text. Then, it adds the text to the "main string".
//
// Parameters :
// char** cppStringFromUer - Pointer to a text that it to be added to the "main string".
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void addText(char** cppStringFromUer);
//-----------------------------------------------------------------------------
// updateString
// ---------
//
// General : The function gets a pointer to a text.
//			 Then, it inserting the text to the "main string" from the place that the user asked.
//
// Parameters :
// char** icppOriginalString - Pointer to a text that that will be replaced parts of the main string.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void updateString(char** icppOriginalString);
//-----------------------------------------------------------------------------
// deleteString
// ---------
//
// General : The function gets a pointer to the main string.
//			 Then, based on the user, it deleted characters from the and of the string.
//
// Parameters :
// char** icppOriginalString - Pointer to the main string.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void deleteText(char** icppOriginalString);
//-----------------------------------------------------------------------------
// writeToFile
// ---------
//
// General : The function gets a string and writes in it a file that named by the user.
//
// Parameters :
// char* icpOriginalString - The string.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void writeToFile(char* icpOriginalString);
//-----------------------------------------------------------------------------
// getStringFromFile
// ---------
//
// General : The function gets a string from a file into the main string.
//
// Parameters : NONE.
//
// Return Value : Char* - The function returns the string she received.
//
//-----------------------------------------------------------------------------
char* getStringFromFile();
//-----------------------------------------------------------------------------
// menu
// ---------
//
// General : The function is the menu of the whole program.
//
// Parameters :
// char* icpOriginalString - The main string.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void menu(char** iocppString);