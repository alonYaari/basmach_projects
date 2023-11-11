#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "Dictionary.dat"

typedef struct dictionaryWord {
	char* word;
	char* defenition;
}dictionaryWord;

//-----------------------------------------------------------------------------
// addNewWord
// ---------
//
// General : The function gets a word and add it into the dictionary.
//
// Parameters :
// char* iszNewWord  - The word that the user wants to insert.
// char* iszWordDef - The definition of the word the user wants to insert.
//
// Return Value : Void.
//
//-----------------------------------------------------------------------------
void addNewWord(char* iszNewWord, char* iszWordDef);
//-----------------------------------------------------------------------------
// getWordDefinition
// ---------
//
// General : The function gets a word and return it with it defenition.
//
// Parameters :
// char* iszNewWord - The word that the user wants to get together with it definiton.
//
// Return Value : char* - Returns a pointer to the word-definiton.
//
//-----------------------------------------------------------------------------
char* getWordDefenition(char* iszWord);
//-----------------------------------------------------------------------------
// printsWordOf
// ---------
//
// General : The function gets a letter and prints all words beggining with that letter.
//
// Parameters :
// char icStartchar - The letter.
//
// Return Value : VOID.
//
//-----------------------------------------------------------------------------
void printWordsOf(char icStartchar);
//-----------------------------------------------------------------------------
// dictionaryMenu
// ---------
//
// General : The function maneging the program.
//
// Parameters :NONE
//
// Return Value : VOID.
//
//-----------------------------------------------------------------------------
void dictionaryMenu();
